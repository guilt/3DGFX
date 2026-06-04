// BITMAP.H - Universal BMP loader.
//
// Design:
//   All BMP formats (1/4/8/16/24/32-bit, RLE4, RLE8, BI_BITFIELDS) are
//   loaded and converted at LOAD TIME to 8-bit indices into the 256-entry
//   5x8x6 RGB cube palette.  Storage is 1 byte/pixel -- low RAM, fast draw.
//
//   At draw time drawBitmap() is a straight VGA-framebuffer blit; there is
//   zero per-pixel RGB work at runtime.  The VGA DAC must already hold the
//   RGB cube palette (call initializeRGBPalette() once after entering
//   mode 13h).
//
// Palette:
//   Indexed-source BMPs  -- source palette is read, then each palette entry
//                           is mapped through RGBToIndexed() to produce a
//                           lookup table.  Every pixel is remapped at load.
//   Direct-source BMPs   -- each pixel's RGB is fed directly to
//                           RGBToIndexed() at load time.
//   The source palette can be retained (KeepSourcePalette flag) for callers
//   that need the original colour table.

#ifndef INC_BMP_H
#define INC_BMP_H

#include <CANVAS.H>
#include <PIXEL.H>
#include <string.h>

#define MAX_BMP_WIDTH  320
#define MAX_BMP_HEIGHT 200

struct BitmapFlags {
    enum {
        None              = 0,
        ToIndexed8        = 1,  // Convert all pixels to 8-bit indices into the RGB cube
        KeepSourcePalette = 2,  // Retain the original source palette after conversion
    };
};

// BMP file header (packed, little-endian on disk)
#if !defined(__BORLANDC__) && !defined(__WATCOMC__) && !defined(__DJGPP__)
#pragma pack(1)
#endif
struct BitmapHeader
{
    char  header[2];
    int32 fileSize;
    int32 reserved;
    int32 dataOffset;
    int32 headerSize;
    int32 width;
    int32 height;
    int16 planes;
    int16 bitsPerPixel;
    int32 compression;
    int32 imageSize;
    int32 xPixelsPerMeter;
    int32 yPixelsPerMeter;
    int32 colorsUsed;
    int32 importantColors;
};
#if !defined(__BORLANDC__) && !defined(__WATCOMC__) && !defined(__DJGPP__)
#pragma pack()
#endif

struct Bitmap
{
    BitmapHeader h;          // raw file header (width/height normalised to positive)
    byte* data;              // w x h bytes -- 8-bit indices into our true-colour palette
    RGBQuad pal[256];        // source palette (for indexed-source BMPs)
    word palSize;            // source palette entries (0 = no palette)
    byte bpp;                // original bits-per-pixel from file
};

static void freeBitmap(Bitmap& b)
{
    if (b.data) { delete[] b.data; b.data = NULL; }
    b.palSize = 0;
    b.bpp = 0;
}

// ------------------------------------------------------------------
//  loadBitmapInto -- universal BMP loader
// ------------------------------------------------------------------
//  Parses any common BMP variant, converts every pixel to an 8-bit
//  index into the 5x8x6 RGB cube, and stores the result in b.data
//  (1 byte/pixel).  The source palette is optionally retained.
//
//  flags  combination of BitmapFlags values (default ToIndexed8 | KeepSourcePalette)
//
static void loadBitmapInto(const char* fileName, Bitmap& b,
                           int flags = BitmapFlags::ToIndexed8 | BitmapFlags::KeepSourcePalette)
{
    fstream file;
    file.open(fileName, ios::in | ios::binary);
    if (!file) return;

    freeBitmap(b);
    memset(&b.h, 0, sizeof(BitmapHeader));
    memset(b.pal, 0, sizeof(b.pal));

    // --- Read & validate header ---------------------------------------
    file.read((char*)&b.h, sizeof(BitmapHeader));
    if (b.h.header[0] != 'B' || b.h.header[1] != 'M') { file.close(); return; }
    if (b.h.headerSize != 40) { file.close(); return; }

    word w       = (word)(b.h.width  < 0 ? -b.h.width  : b.h.width);
    word h       = (word)(b.h.height < 0 ? -b.h.height : b.h.height);
    bool topDown = b.h.height < 0;
    word srcBpp  = (word)b.h.bitsPerPixel;
    dword comp   = b.h.compression;

    if (w > MAX_BMP_WIDTH || h > MAX_BMP_HEIGHT) { file.close(); return; }

    b.bpp = (byte)srcBpp;
    bool keepPal = (flags & BitmapFlags::KeepSourcePalette) != 0;

    // --- Palette ------------------------------------------------------
    dword colors = b.h.colorsUsed;
    if (colors == 0 && srcBpp <= 8) colors = (dword)1 << srcBpp;

    b.palSize = 0;
    if (srcBpp <= 8) {
        dword n = colors > 256 ? 256 : colors;
        b.palSize = (word)n;
        for (dword i = 0; i < n; i++)
            file.read((char*)&b.pal[i], sizeof(RGBQuad));
    }

    // Precompute source->our-palette mapping
    byte palMap[256];
    buildPaletteMap(palMap, b.pal, b.palSize);

    // --- Allocate output ----------------------------------------------
    dword pixelCount = (dword)w * h;
    b.data = new byte[pixelCount];

    file.seekg(b.h.dataOffset, ios::beg);

    // ==================================================================
    //  BI_RGB / BI_BITFIELDS  (uncompressed)
    // ==================================================================
    if (comp == 0 || comp == 3)
    {
        dword srcStride = ((srcBpp * w + 31u) / 32u) * 4u;
        byte* rowBuf = new byte[srcStride];

        // Bitfield masks for BI_BITFIELDS
        dword rMask = 0, gMask = 0, bMask = 0;
        int rShift = 0, gShift = 0, bShift = 0;
        int rBits = 8, gBits = 8, bBits = 8;
        if (comp == 3) {
            file.seekg(54, ios::beg);
            file.read((char*)&rMask, 4);
            file.read((char*)&gMask, 4);
            file.read((char*)&bMask, 4);
            file.seekg(b.h.dataOffset, ios::beg);
            while (!((rMask >> rShift) & 1)) rShift++;
            while (!((gMask >> gShift) & 1)) gShift++;
            while (!((bMask >> bShift) & 1)) bShift++;
            { dword m = rMask >> rShift; rBits = 0; while (m) { rBits++; m >>= 1; } }
            { dword m = gMask >> gShift; gBits = 0; while (m) { gBits++; m >>= 1; } }
            { dword m = bMask >> bShift; bBits = 0; while (m) { bBits++; m >>= 1; } }
        }

        // Hoist srcBpp branching outside the per-pixel loop (speed)
        for (word y = 0; y < h; y++) {
            file.read((char*)rowBuf, srcStride);
            word dstY = topDown ? (h - 1 - y) : y;
            byte* dst = b.data + (dword)dstY * w;
            word x;

            switch (srcBpp) {

            case 1:
                for (x = 0; x < w; x++)
                    dst[x] = palMap[(rowBuf[x >> 3] >> (7 - (x & 7))) & 1];
                break;

            case 4:
                for (x = 0; x < w; x++)
                    dst[x] = palMap[(x & 1) ? (rowBuf[x >> 1] & 0x0F)
                                            : ((rowBuf[x >> 1] >> 4) & 0x0F)];
                break;

            case 8:
                for (x = 0; x < w; x++)
                    dst[x] = palMap[rowBuf[x]];
                break;

            case 16:
                if (comp == 3 && rMask) {
                    int rMax = (1 << rBits) - 1, gMax = (1 << gBits) - 1, bMax = (1 << bBits) - 1;
                    for (x = 0; x < w; x++) {
                        word val = *(word*)(rowBuf + x * 2);
                        int r = (int)((val & rMask) >> rShift) * 255 / rMax;
                        int g = (int)((val & gMask) >> gShift) * 255 / gMax;
                        int bv = (int)((val & bMask) >> bShift) * 255 / bMax;
                        dst[x] = RGBToIndexed((byte)r, (byte)g, (byte)bv);
                    }
                } else {
                    for (x = 0; x < w; x++) {
                        word val = *(word*)(rowBuf + x * 2);
                        dst[x] = RGBToIndexed(
                            (byte)(((val >> 10) & 0x1F) * 255 / 31),
                            (byte)(((val >> 5)  & 0x1F) * 255 / 31),
                            (byte)((val        & 0x1F) * 255 / 31));
                    }
                }
                break;

            case 24:
                for (x = 0; x < w; x++)
                    dst[x] = RGBToIndexed(rowBuf[x*3+2], rowBuf[x*3+1], rowBuf[x*3]);
                break;

            case 32:
                for (x = 0; x < w; x++)
                    dst[x] = RGBToIndexed(rowBuf[x*4+2], rowBuf[x*4+1], rowBuf[x*4]);
                break;
            }
        }
        delete[] rowBuf;
    }

    // ==================================================================
    //  BI_RLE8
    // ==================================================================
    else if (comp == 1)
    {
        byte* idxBuf = new byte[pixelCount];
        memset(idxBuf, 0, pixelCount);
        dword xx = 0, yy = 0;
        bool done = false;
        while (!done && yy < h) {
            byte c, v;
            if (!file.read((char*)&c, 1)) break;
            if (!file.read((char*)&v, 1)) break;
            if (c > 0) {
                dword left = w - xx;
                dword runLen = c < left ? c : left;
                memset(idxBuf + yy * w + xx, v, runLen);
                xx += runLen;
            } else if (v == 0) { yy++; xx = 0; }
            else if (v == 1) { done = true; }
            else if (v == 2) {
                byte dx, dy;
                file.read((char*)&dx, 1); file.read((char*)&dy, 1);
                xx += dx; yy += dy;
            } else {
                for (byte i = 0; i < v; i++) {
                    byte val;
                    file.read((char*)&val, 1);
                    if (xx < w) idxBuf[yy * w + xx] = val;
                    xx++;
                }
                if (v & 1) file.read((char*)&c, 1);
            }
        }
        for (dword i = 0; i < pixelCount; i++)
            b.data[i] = palMap[idxBuf[i]];
        delete[] idxBuf;
    }

    // ==================================================================
    //  BI_RLE4
    // ==================================================================
    else if (comp == 2)
    {
        byte* idxBuf = new byte[pixelCount];
        memset(idxBuf, 0, pixelCount);
        dword xx = 0, yy = 0;
        bool done = false;
        while (!done && yy < h) {
            byte c, v;
            if (!file.read((char*)&c, 1)) break;
            if (!file.read((char*)&v, 1)) break;
            if (c > 0) {
                byte hi = (v >> 4) & 0x0F, lo = v & 0x0F;
                for (byte i = 0; i < c && xx + i < w; i++)
                    idxBuf[yy * w + xx + i] = (i & 1) ? lo : hi;
                xx += c;
            } else if (v == 0) { yy++; xx = 0; }
            else if (v == 1) { done = true; }
            else if (v == 2) {
                byte dx, dy;
                file.read((char*)&dx, 1); file.read((char*)&dy, 1);
                xx += dx; yy += dy;
            } else {
                for (byte i = 0; i < v; i++) {
                    if ((i & 1) == 0) file.read((char*)&c, 1);
                    byte nib = (i & 1) ? (c & 0x0F) : ((c >> 4) & 0x0F);
                    if (xx < w) idxBuf[yy * w + xx] = nib;
                    xx++;
                }
                if ((v & 3) == 1 || (v & 3) == 2) file.read((char*)&c, 1);
            }
        }
        for (dword i = 0; i < pixelCount; i++)
            b.data[i] = palMap[idxBuf[i]];
        delete[] idxBuf;
    }

    file.close();

    if (!keepPal) b.palSize = 0;

    // Normalise dimensions so callers always see positive values
    b.h.width  = (int32)w;
    b.h.height = (int32)h;
}

// ------------------------------------------------------------------
//  initBitmap -- kept for source compatibility
// ------------------------------------------------------------------
//  No longer needs to touch the VGA DAC -- every pixel in b.data is
//  already an index into the RGB cube palette that was set up by
//  initializeRGBPalette() during program init.
static void initBitmap(Bitmap& b)
{
    (void)b;
}

// ------------------------------------------------------------------
//  drawBitmap -- blit a converted Bitmap to the VGA framebuffer
// ------------------------------------------------------------------
//  Pixels are 8-bit indices already matched to the RGB cube palette
//  loaded in the VGA DAC.  This is a straight copy (Y-flipped for
//  BMP's bottom-up convention).
static void drawBitmap(Bitmap& b, int xo, int yo)
{
    if (!b.data) return;
    word w = (word)b.h.width;
    word h = (word)b.h.height;

    for (int i = 0; i < w; i++)
        for (int j = 0; j < h; j++)
            putPixel(i + xo, h + yo - j - 1, b.data[j * w + i]);
}

// ------------------------------------------------------------------
//  bitmapPixel -- read back the 8-bit palette index at (x, y)
// ------------------------------------------------------------------
inline byte bitmapPixel(const Bitmap& b, int x, int y)
{
    if (!b.data || x < 0 || x >= b.h.width || y < 0 || y >= b.h.height)
        return 0;
    return b.data[(dword)y * b.h.width + x];
}

#endif
