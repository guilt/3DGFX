// Easy Image Routines.

#ifndef INC_IMAGE_H
#define INC_IMAGE_H

#include <PLATFORM.H>
#include <CANVAS.H>
#include <PIXEL.H>

#define I_ORD_DRAW 0
#define I_OR_DRAW  1
#define I_XOR_DRAW 2
#define I_AND_DRAW 3

// ------------------------------------------------------------------
//  Palette I/O - reads .PAL format files
// ------------------------------------------------------------------

#define DEFAULT_PAL "DEFAULT.PAL"

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
    unsigned char* buffer;
    uint16 i, j, k, l;

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

    void load(const char[], unsigned char xorKey = 0);
    void draw(uint16 x = 0, uint16 y = 0);
    void drawWithMode(uint16 x = 0, uint16 y = 0, uint16 mode = I_ORD_DRAW);
    void drawStretched(uint16 x1, uint16 y1, uint16 x2, uint16 y2);

    image() : imgHeight(0), imgWidth(0), buffer(NULL), i(0), j(0), k(0), l(0) {}
    image(const char filename[]) : imgHeight(0), imgWidth(0), buffer(NULL), i(0), j(0), k(0), l(0)
    {
        load(filename);
    }

    ~image()
    {
        if (buffer != NULL) { delete[] buffer; imgHeight = imgWidth = 0; }
    }
};

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
    if ((x1 >= x2) || (y1 >= y2))
        return;
    xr = (float)nx / (float)imgWidth;
    yr = (float)ny / (float)imgHeight;
    for (i = 0; i < imgHeight; i++)
    {
        for (j = 0; j < imgWidth; j++)
        {
            igl = getPixel(j, i);
            if (xr <= 1)
            {
                if (yr <= 1)
                {
                    putPixel(x1 + (uint16)(j * xr), y1 + (uint16)(i * yr), igl);
                }
                else
                {
                    for (k = 0; k < (uint16)(yr + 0.5); k++)
                        putPixel(x1 + (uint16)(j * xr), y1 + (uint16)(i * yr) + k, igl);
                }
            }
            else
            {
                if (yr <= 1)
                {
                    for (l = 0; l < (uint16)(xr + 0.5); l++)
                        putPixel(x1 + (uint16)(j * xr) + l, y1 + (uint16)(i * yr), igl);
                }
                else
                {
                    for (k = 0; k < (uint16)(yr + 0.5); k++)
                        for (l = 0; l < (uint16)(xr + 0.5); l++)
                            putPixel(x1 + (uint16)(j * xr) + l, y1 + (uint16)(i * yr) + k, igl);
                }
            }
        }
    }
}

void image ::load(const char filename[], unsigned char xorKey)
{
    uint16 val, textMode = 0;
    fstream ifile;
    unsigned char c;

    if (buffer != NULL)
    {
        delete[] buffer;
    }
    imgHeight = imgWidth = 0;
    ifile.open(filename, ios::in | ios::binary);
    if (!ifile)
    {
        return;
    }
    if (ifile.get() != 'I' || ifile.get() != 'M')
    {
        ifile.close();
        return;
    }
    if (ifile.get() == 'T')
    {
        textMode = 1;
    }
    if (!textMode)
    {
        ifile.read((char*)&imgHeight, sizeof(uint16));
        ifile.read((char*)&imgWidth, sizeof(uint16));
    }
    else
    {
        ifile.get();
        ifile >> imgHeight;
        ifile.get();
        ifile >> imgWidth;
        ifile.get();
    }
    allocBuffer();
    if (buffer == NULL)
    {
        imgHeight = imgWidth = 0;
        return;
    }
    for (i = 0; i < imgHeight; i++)
    {
        for (j = 0; j < imgWidth; j++)
        {
            if (!textMode)
            {
                ifile.read((char*)&c, sizeof(unsigned char));
            }
            else
            {
                ifile >> val;
                c = (unsigned char)val;
                ifile.get();
            }
            c ^= xorKey;
            setPixel(j, i, c);
        }
        if (textMode)
        {
            ifile.get();
        }
    }
    ifile.close();
}

#endif