#ifndef INC_BMP_H
#define INC_BMP_H

#include <CANVAS.H>

#define MAX_BMP_WIDTH  320
#define MAX_BMP_HEIGHT 200
#define BMP_DATA_SIZE  64000

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
    BitmapHeader h;
    RGBQuad pal[NUM_COLORS];
    char data[BMP_DATA_SIZE];
};

static void loadBitmapInto(const char* fn, Bitmap& b)
{
    fstream file;
    file.open(fn, ios::in | ios::binary);
    if (!file) return;
    file.read((char*)&b.h, sizeof(BitmapHeader));
    if (b.h.header[0] != 'B' || b.h.header[1] != 'M') { file.close(); return; }
    if (b.h.headerSize != 40) { file.close(); return; }
    if (b.h.compression != 0) { file.close(); return; }
    if (b.h.width > MAX_BMP_WIDTH || b.h.height > MAX_BMP_HEIGHT) { file.close(); return; }
    if (b.h.colorsUsed == 0) b.h.colorsUsed = 256;
    for (int32 i = 0; i < b.h.colorsUsed; i++)
        file.read((char*)&b.pal[i], sizeof(RGBQuad));
    for (int32 j = 0; j < b.h.height; j++)
        for (int32 i = 0; i < b.h.width; i++)
            file.read((char*)&b.data[j * b.h.width + i], sizeof(char));
    file.close();
}

static void initBitmap(Bitmap& b)
{
    // Set only the BMP's actual palette entries (indices 0 .. colorsUsed-1).
    // Entries 16-255 (the 5x8x6 RGB cube) are left untouched so that
    // RGBToIndexed() / putPixelRGB() keep working correctly.
    for (int i = 0; i < b.h.colorsUsed; i++)
    {
        byte r = (byte)(unsigned char)b.pal[i].r;
        byte g = (byte)(unsigned char)b.pal[i].g;
        byte bl = (byte)(unsigned char)b.pal[i].b;
        setPalette(i, r, g, bl);
    }
    updateSystemPalette();
}

static void drawBitmap(Bitmap& b, int xo, int yo)
{
    initBitmap(b);
    for (int i = 0; i < b.h.width; i++)
        for (int j = 0; j < b.h.height; j++)
            putPixel(i + xo, b.h.height + yo - j - 1, b.data[j * b.h.width + i]);
}

#endif
