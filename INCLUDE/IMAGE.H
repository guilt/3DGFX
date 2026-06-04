// IMAGE.H - Easy Image loader (.IM format) with true-colour palette
//           conversion support.
//
// Design:
//   The image class loads .IM files (a simple custom format: "IM" + 2-byte
//   height + 2-byte width + raw pixel bytes).  Pixel data is stored as
//   8-bit palette indices.
//
//   By default (ImageFlags::None) draw() writes the original indices to the
//   VGA framebuffer and assumes the VGA DAC already holds the matching
//   palette (set via setPaletteFromFile() or setBwPalette()).
//
//   With ImageFlags::ToIndexed8 the caller must also supply a .PAL palette
//   (via loadPalette() or the external readPaletteFile()).  Calling
//   convertToTruePalette() remaps every pixel through the palette to an
//   8-bit index into the 5x8x6 RGB cube.  After conversion draw() blits
//   directly to the framebuffer without needing a custom VGA palette.
//
// Palette I/O (readPaletteFile / setPaletteFromFile) remain independent
// utilities for callers that manage their own palette buffers.

#ifndef INC_IMAGE_H
#define INC_IMAGE_H

#include <PLATFORM.H>
#include <CANVAS.H>
#include <PIXEL.H>

#define I_ORD_DRAW 0
#define I_OR_DRAW  1
#define I_XOR_DRAW 2
#define I_AND_DRAW 3

#define DEFAULT_PAL "DEFAULT.PAL"

struct ImageFlags {
    enum {
        None       = 0,
        ToIndexed8 = 1,   // Pixels will be converted to RGB cube indices
    };
};

// ------------------------------------------------------------------
//  Palette I/O -- read .PAL format files
// ------------------------------------------------------------------
//  Binary .PAL: "PL" signature + 768 bytes (R,G,B each stored as 6-bit,
//  shifted left by 2 to become 8-bit).
//  Text .PAL:   "PLT" signature + 256 lines of "R,G,B" ASCII.
// ------------------------------------------------------------------

static bool readPaletteFile(const char* fileName, byte palette[PALETTE_BYTES])
{
    int i, r, g, b, textMode = 0;
    fstream file;
    file.open(fileName, ios::in | ios::binary);
    if (!file) return false;
    if (file.get() != 'P' || file.get() != 'L') { file.close(); return false; }
    if (file.get() == 'T') { textMode = 1; file.get(); }
    for (i = 0; i < 256; i++)
    {
        if (!textMode) {
            file.read((char*)&r, sizeof(char));
            file.read((char*)&g, sizeof(char));
            file.read((char*)&b, sizeof(char));
        } else {
            file >> r; file.get(); file >> g; file.get(); file >> b; file.get();
        }
        palette[i * 3]     = (byte)(r << 2);
        palette[i * 3 + 1] = (byte)(g << 2);
        palette[i * 3 + 2] = (byte)(b << 2);
    }
    file.close();
    return true;
}

static bool setPaletteFromFile(const char* fileName)
{
    byte pal[PALETTE_BYTES];
    if (!readPaletteFile(fileName, pal)) return false;
    setPaletteArray(pal, NUM_COLORS);
    updateSystemPalette();
    return true;
}

class image
{
    uint16 imgHeight, imgWidth;
    unsigned char* buffer;          // pixel data (original indices, or true-palette indices)
    uint16 i, j, k, l;             // scratch loop vars (used in draw methods)

    byte srcPal[PALETTE_BYTES];     // source palette (loaded from .PAL)
    bool palLoaded;                 // srcPal has been loaded
    bool converted;                 // buffer holds RGB-cube indices (not original)

    void allocBuffer()
    {
        if (!imgHeight || !imgWidth) return;
        buffer = new unsigned char[(imgHeight * imgWidth)];
    }

  public:
    uint16 height() { return imgHeight; }
    uint16 width()  { return imgWidth; }

    void setPixel(uint16 col, uint16 row, unsigned char val)
    {
        if (buffer == NULL || row >= imgHeight || col >= imgWidth) return;
        buffer[(row * imgWidth) + col] = val;
    }

    unsigned char getPixel(uint16 col, uint16 row)
    {
        if (buffer == NULL || row >= imgHeight || col >= imgWidth) return 0;
        return buffer[(row * imgWidth) + col];
    }

    // Load an .IM file.  Flags control post-processing (conversion requires
    // a palette to have been loaded first via loadPalette()).
    void load(const char filename[], unsigned char xorKey = 0,
              int flags = ImageFlags::None);

    // Load a .PAL palette file into the image object.
    bool loadPalette(const char* fileName);

    // Convert the pixel buffer in-place from original indices to 8-bit
    // indices into the 5x8x6 RGB cube.  Requires a loaded palette.
    void convertToTruePalette();

    void draw(uint16 x = 0, uint16 y = 0);
    void drawWithMode(uint16 x = 0, uint16 y = 0, uint16 mode = I_ORD_DRAW);
    void drawStretched(uint16 x1, uint16 y1, uint16 x2, uint16 y2);

    image() : imgHeight(0), imgWidth(0), buffer(NULL),
              i(0), j(0), k(0), l(0), palLoaded(false), converted(false) {}
    image(const char filename[], unsigned char xorKey = 0,
          int flags = ImageFlags::None) : imgHeight(0), imgWidth(0), buffer(NULL),
              i(0), j(0), k(0), l(0), palLoaded(false), converted(false)
    {
        load(filename, xorKey, flags);
    }

    ~image()
    {
        if (buffer != NULL) { delete[] buffer; imgHeight = imgWidth = 0; }
    }
};

// ------------------------------------------------------------------
//  load -- read an .IM file
// ------------------------------------------------------------------
//  filename    path to .IM file
//  xorKey      optional XOR obfuscation key (196 in cheetah.im)
//  flags       ImageFlags -- if ToIndexed8 and a palette has been loaded
//              via loadPalette(), pixels are automatically converted to
//              true-colour palette indices during loading.
void image ::load(const char filename[], unsigned char xorKey, int flags)
{
    uint16 val, textMode = 0;
    fstream ifile;
    unsigned char c;

    if (buffer != NULL) {
        delete[] buffer;
        buffer = NULL;
    }
    imgHeight = imgWidth = 0;
    converted = false;

    ifile.open(filename, ios::in | ios::binary);
    if (!ifile) return;

    if (ifile.get() != 'I' || ifile.get() != 'M') { ifile.close(); return; }
    if (ifile.get() == 'T') textMode = 1;

    if (!textMode) {
        ifile.read((char*)&imgHeight, sizeof(uint16));
        ifile.read((char*)&imgWidth,  sizeof(uint16));
    } else {
        ifile.get();
        ifile >> imgHeight; ifile.get();
        ifile >> imgWidth;  ifile.get();
    }

    allocBuffer();
    if (buffer == NULL) { imgHeight = imgWidth = 0; return; }

    for (i = 0; i < imgHeight; i++) {
        for (j = 0; j < imgWidth; j++) {
            if (!textMode)
                ifile.read((char*)&c, sizeof(unsigned char));
            else {
                ifile >> val; c = (unsigned char)val; ifile.get();
            }
            c ^= xorKey;
            setPixel(j, i, c);
        }
        if (textMode) ifile.get();
    }
    ifile.close();

    // Auto-convert if the caller requested true-colour and a palette is ready
    if ((flags & ImageFlags::ToIndexed8) && palLoaded)
        convertToTruePalette();
}

// ------------------------------------------------------------------
//  loadPalette -- read a .PAL file into the image's source palette
// ------------------------------------------------------------------
bool image ::loadPalette(const char* fileName)
{
    palLoaded = readPaletteFile(fileName, srcPal);
    return palLoaded;
}

// ------------------------------------------------------------------
//  convertToTruePalette -- remap buffer indices to the RGB cube
// ------------------------------------------------------------------
//  Each pixel's original index is used to look up the source palette,
//  then RGBToIndexed() maps that colour to an 8-bit index into the
//  5x8x6 VGA palette.  After this call draw() writes indices that
//  match the cube palette set up by initializeRGBPalette().
void image ::convertToTruePalette()
{
    if (!buffer || !palLoaded) return;
    for (i = 0; i < imgHeight; i++)
        for (j = 0; j < imgWidth; j++) {
            unsigned char idx = getPixel(j, i);
            byte r = srcPal[idx * 3];
            byte g = srcPal[idx * 3 + 1];
            byte b = srcPal[idx * 3 + 2];
            setPixel(j, i, (unsigned char)RGBToIndexed(r, g, b));
        }
    converted = true;
}

// ------------------------------------------------------------------
//  draw methods -- write buffer pixels to the VGA framebuffer
// ------------------------------------------------------------------
//  If converted is true the buffer holds RGB-cube indices that match
//  the VGA DAC (set via initializeRGBPalette()).  If not converted
//  the VGA DAC must have been set to the appropriate custom palette
//  (via setPaletteFromFile() etc.).

void image ::draw(uint16 x, uint16 y)
{
    unsigned char igl;
    for (i = 0; i < imgHeight; i++)
    {
        for (j = 0; j < imgWidth; j++)
        {
            igl = getPixel(j, i);
            putPixel(x + j, y + i, igl);
        }
    }
}

void image ::drawWithMode(uint16 x, uint16 y, uint16 mode)
{
    unsigned char igl;
    for (i = 0; i < imgHeight; i++)
    {
        for (j = 0; j < imgWidth; j++)
        {
            igl = getPixel(j, i);
            if (mode == I_OR_DRAW)
                igl = (getPixel(x + j, y + i) | igl);
            else if (mode == I_AND_DRAW)
                igl = (getPixel(x + j, y + i) & igl);
            else if (mode == I_XOR_DRAW)
                igl = (getPixel(x + j, y + i) ^ igl);
            putPixel(x + j, y + i, igl);
        }
    }
}

void image ::drawStretched(uint16 x1, uint16 y1, uint16 x2, uint16 y2)
{
    unsigned char igl = 0;
    uint16 nx = (x2 + 1) - x1, ny = (y2 + 1) - y1;
    float xr, yr;
    if ((x1 >= x2) || (y1 >= y2)) return;
    xr = (float)nx / (float)imgWidth;
    yr = (float)ny / (float)imgHeight;
    for (i = 0; i < imgHeight; i++)
    {
        for (j = 0; j < imgWidth; j++)
        {
            igl = getPixel(j, i);
            if (xr <= 1) {
                if (yr <= 1)
                    putPixel(x1 + (uint16)(j * xr), y1 + (uint16)(i * yr), igl);
                else
                    for (k = 0; k < (uint16)(yr + 0.5); k++)
                        putPixel(x1 + (uint16)(j * xr), y1 + (uint16)(i * yr) + k, igl);
            } else {
                if (yr <= 1)
                    for (l = 0; l < (uint16)(xr + 0.5); l++)
                        putPixel(x1 + (uint16)(j * xr) + l, y1 + (uint16)(i * yr), igl);
                else
                    for (k = 0; k < (uint16)(yr + 0.5); k++)
                        for (l = 0; l < (uint16)(xr + 0.5); l++)
                            putPixel(x1 + (uint16)(j * xr) + l, y1 + (uint16)(i * yr) + k, igl);
            }
        }
    }
}

#endif
