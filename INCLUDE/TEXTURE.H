// BMP Texture Renderer.
#ifndef INC_TEX_H
#define INC_TEX_H

#include <CANVAS.H>


#define TEXTURE_SIZE 40
#define MAX_TEXTURES 35
#define MAX_FILENAME_LEN 64

#if !defined(__BORLANDC__) && !defined(__WATCOMC__) && !defined(__DJGPP__)
#pragma pack(1)
#endif
struct TextureHeader
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

RGBQuad pal[256];

struct Texture
{
    TextureHeader h;
    char data[TEXTURE_SIZE][TEXTURE_SIZE];
};

static Texture* loadTexture(const char* fileName)
{
    long i, j;
    int widthClipped = 0;
    fstream file;
    char ct;
    file.open(fileName, ios::in | ios::binary);
    if (!file) return NULL;

    Texture* t = new Texture;
    file.read((char*)&t->h, sizeof(TextureHeader));

    if (t->h.header[0] != 'B' || t->h.header[1] != 'M')
    {
        file.close();
        delete t;
        return NULL;
    }
    if (t->h.imageSize != (t->h.height * t->h.width))
    {
        file.close();
        delete t;
        return NULL;
    }
    if (t->h.height > TEXTURE_SIZE) t->h.height = TEXTURE_SIZE;
    if (t->h.width > TEXTURE_SIZE) widthClipped = 1;
    if (t->h.colorsUsed == 0) t->h.colorsUsed = 256;
    for (i = 0; i < t->h.colorsUsed; i++)
        file.read((char*)&pal[i], sizeof(RGBQuad));

    for (j = 0; j < t->h.height; j++)
    {
        if (!widthClipped)
        {
            for (i = 0; i < t->h.width; i++)
                file.read((char*)&t->data[i][j], sizeof(char));
        }
        else
        {
            for (i = 0; i < TEXTURE_SIZE; i++)
                file.read((char*)&t->data[i][j], sizeof(char));
            for (i = TEXTURE_SIZE; i < t->h.width; i++)
                file.read((char*)&ct, sizeof(char));
        }
    }
    if (widthClipped) t->h.width = TEXTURE_SIZE;
    file.close();

    int ci;
    for (ci = 0; ci < NUM_COLORS; ci++)
    {
        setPalette(ci, pal[ci].r, pal[ci].g, pal[ci].b);
    }
    updateSystemPalette();

    return t;
}

static void freeTexture(Texture* t)
{
    if (t) delete t;
}

static bool loadTextureInto(const char* fn, Texture& t)
{
    Texture* tmp = loadTexture(fn);
    if (!tmp) return false;
    t = *tmp;
    delete tmp;
    return true;
}

static void initTexturePalette()
{
    int ci;
    for (ci = 0; ci < NUM_COLORS; ci++)
    {
        setPalette(ci, pal[ci].r, pal[ci].g, pal[ci].b);
    }
    updateSystemPalette();
}

#define initTextures() initTexturePalette()

#endif
