// BMP Texture Renderer -- loads via BITMAP.H, clips to TEXTURE_SIZE.
#ifndef INC_TEX_H
#define INC_TEX_H

#include <CANVAS.H>
#include <BITMAP.H>

#ifdef ITEX

#define TEXTURE_SIZE 40
#define MAX_TEXTURES 35
#define MAX_FILENAME_LEN 64

struct Texture
{
    int width, height;
    byte data[TEXTURE_SIZE][TEXTURE_SIZE];
};

static Texture* loadTexture(const char* fileName)
{
    Bitmap bmp;
    loadBitmapInto(fileName, bmp, BitmapFlags::ToIndexed8);
    if (!bmp.data) return NULL;

    Texture* t = new Texture;
    t->width  = bmp.h.width  > TEXTURE_SIZE ? TEXTURE_SIZE : (int)bmp.h.width;
    t->height = bmp.h.height > TEXTURE_SIZE ? TEXTURE_SIZE : (int)bmp.h.height;

    for (int j = 0; j < t->height; j++)
        for (int i = 0; i < t->width; i++)
            t->data[i][j] = bmp.data[j * bmp.h.width + i];

    freeBitmap(bmp);
    return t;
}

static void freeTexture(Texture* t)
{
    if (t) delete t;
}

static bool loadTextureInto(const char* fileName, Texture& t)
{
    Texture* tmp = loadTexture(fileName);
    if (!tmp) return false;
    t = *tmp;
    delete tmp;
    return true;
}

#endif // ITEX
#endif // INC_TEX_H
