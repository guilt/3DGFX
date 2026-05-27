#ifndef INC_PIXEL_H
#define INC_PIXEL_H

// PIXEL.H - Palette conversion, Pixel24 class, YUV colour space.
// Colour constants and RGBToIndexed live in TYPES.H (lower layer).

#include <PLATFORM.H>
#include <CANVAS.H>

// ------------------------------------------------------------------
//  VGA standard palette (0-15) used by several functions below
// ------------------------------------------------------------------

static const byte vgaPal[16][3] = {
    {  0,  0,  0 }, {  0,  0,170 }, {  0,170,  0 }, {  0,170,170 },
    {170,  0,  0 }, {170,  0,170 }, {170, 85,  0 }, {170,170,170 },
    { 85, 85, 85 }, { 85, 85,255 }, { 85,255, 85 }, { 85,255,255 },
    {255, 85, 85 }, {255, 85,255 }, {255,255, 85 }, {255,255,255 },
};

// ------------------------------------------------------------------
//  putPixelRGB / putPixelRGBA - 24/32-bit ? indexed and write.
//  Uses RGBToIndexed macro from TYPES.H.
// ------------------------------------------------------------------

#define putPixelRGB(x, y, r, g, b) \
    putPixel((x), (y), RGBToIndexed((r), (g), (b)))



// ------------------------------------------------------------------
//  Palette index ? RGB conversion
// ------------------------------------------------------------------

static void vgaIndexToRGB(int index, byte& r, byte& g, byte& b)
{
    if (index < 16) {
        r = vgaPal[index][0]; g = vgaPal[index][1]; b = vgaPal[index][2];
    } else {
        int i = index - 16;
        r = (byte)(((i / 48) * 255 + 2) / 4);
        g = (byte)((((i / 6) % 8) * 255 + 3) / 7);
        b = (byte)(((i % 6) * 255 + 2) / 5);
    }
}

static int rgbToVgaIndex(byte r, byte g, byte b)
{
    byte rr, gg, bb;
    int best = 0, bestDist = 3 * 256 * 256;
    for (int i = 0; i < 256; i++) {
        vgaIndexToRGB(i, rr, gg, bb);
        int dr = (int)r - (int)rr;
        int dg = (int)g - (int)gg;
        int db = (int)b - (int)bb;
        int d = dr * dr + dg * dg + db * db;
        if (d < bestDist) { bestDist = d; best = i; }
    }
    return best;
}

// RGB cube palette buffer + initialiser
static byte rgbPalette[PALETTE_BYTES];

static void initializeRGBPalette(byte palette[PALETTE_BYTES])
{
    int i;
    for (i = 0; i < 16; i++)
    {
        palette[i * 3]     = vgaPal[i][0];
        palette[i * 3 + 1] = vgaPal[i][1];
        palette[i * 3 + 2] = vgaPal[i][2];
    }
    for (i = 16; i < 256; i++)
    {
        int ii = i - 16;
        int ri = ii / 48, gi = (ii / 6) % 8, bi = ii % 6;
        palette[i * 3]     = (byte)((ri * 255 + 2) / 4);
        palette[i * 3 + 1] = (byte)(((gi * 255 + 3) / 7));
        palette[i * 3 + 2] = (byte)(((bi * 255 + 2) / 5));
    }
    setPaletteArray(palette, 256);
}

// ------------------------------------------------------------------
//  RGB ? YUV conversion (BT.601)
// ------------------------------------------------------------------

#define rgbToY(r, g, b)  ((byte)(((77*(r) + 150*(g) + 29*(b)) >> 8) & 0xFF))
#define rgbToU(r, g, b)  ((byte)(((129*(b) - 38*(r) - 74*(g) + 32768) >> 8) & 0xFF))
#define rgbToV(r, g, b)  ((byte)(((129*(r) - 64*(g) - 32*(b) + 32768) >> 8) & 0xFF))

#define yuvToR(y, u, v)  ((byte)clamp255(((y) + ((359 * ((v)-128)) >> 8))))
#define yuvToG(y, u, v)  ((byte)clamp255(((y) - ((88 * ((u)-128) + 183 * ((v)-128)) >> 8))))
#define yuvToB(y, u, v)  ((byte)clamp255(((y) + ((455 * ((u)-128)) >> 8))))

#ifndef clamp255
#define clamp255(x)  ((x) < 0 ? 0 : ((x) > 255 ? 255 : (x)))
#endif

// ------------------------------------------------------------------
//  Canvas palette helper - sets up a 6?6?6 RGB cube palette.
//  Free function, no class overhead.
// ------------------------------------------------------------------

static void setCanvasRGBPalette(Canvas& canvas)
{
    byte palette[PALETTE_BYTES];
    for (int i = 16; i < 256; i++)
    {
        int ii = i - 16;
        int ri = ii / 48, gi = (ii / 6) % 8, bi = ii % 6;
        palette[i * 3]     = (byte)((ri * 255 + 2) / 4);
        palette[i * 3 + 1] = (byte)((gi * 255 + 3) / 7);
        palette[i * 3 + 2] = (byte)((bi * 255 + 2) / 5);
    }
    canvas.setPaletteArray(palette, NUM_COLORS);
}

#endif
