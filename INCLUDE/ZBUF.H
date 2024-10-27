// The Important Z-Buffering File .
#include <defs.h>

#ifndef IZBUF
#define zbufr(x, y, z, color)
#define mkzbuf()
#define rmzbuf()
#define clrzbuf()
#endif

#ifdef IZBUF

#define ZMEM   screen_height*screen_width
#define ZPARAM 500

int *zbuffer;

void mkzbuf()
{
    zbuffer = (int *)malloc(ZMEM);
}

void clrzbuf()
{
    long i;
    for (i = 0; i < ZMEM; i++)
    {
        zbuffer[i] = -32768;
    }
}

void zbufr(int& x, int& y, char z, int color)
{
    int offset = (screen_width * y) + x;
    int zc = z*ZPARAM;
    if (zc > zbuffer[offset])
    {
        zbuffer[offset] = zc;
        putpixel(x, y, color);
    }
}

void rmzbuf()
{
    free(zbuffer);
}
#endif

