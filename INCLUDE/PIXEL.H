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
//  COLOR_* aliases for the 16 VGA hardware indices (0-15).
//  Always available -- use these instead of the bare BGI names
//  (BLACK, BLUE ...) which may be skipped when graphics.h is present.
// ------------------------------------------------------------------

#define COLOR_BLACK         0
#define COLOR_BLUE          1
#define COLOR_GREEN         2
#define COLOR_CYAN          3
#define COLOR_RED           4
#define COLOR_MAGENTA       5
#define COLOR_BROWN         6
#define COLOR_LIGHTGRAY     7
#define COLOR_DARKGRAY      8
#define COLOR_LIGHTBLUE     9
#define COLOR_LIGHTGREEN   10
#define COLOR_LIGHTCYAN    11
#define COLOR_LIGHTRED     12
#define COLOR_LIGHTMAGENTA 13
#define COLOR_YELLOW       14
#define COLOR_WHITE        15

// ------------------------------------------------------------------
//  Web / CSS named colours -- each maps to the nearest 5x8x6 RGB
//  cube cell (indices 16-255).  Usable wherever the true-colour
//  palette is loaded (initializeRGBPalette()).  Naming follows the
//  CSS3 colour keyword list; underscores separate words.
// ------------------------------------------------------------------

#define COLOR_ALICE_BLUE           255
#define COLOR_ANTIQUE_WHITE        255
#define COLOR_AQUA                  63
#define COLOR_AQUAMARINE           158
#define COLOR_AZURE                255
#define COLOR_BEIGE                255
#define COLOR_BISQUE               254
#define COLOR_BLANCHED_ALMOND      254
#define COLOR_BLUE_VIOLET          123
#define COLOR_BURLY_WOOD           241
#define COLOR_CADET_BLUE            91
#define COLOR_CHARTREUSE           154
#define COLOR_CHOCOLATE            226
#define COLOR_CORAL                227
#define COLOR_CORNFLOWER_BLUE       93
#define COLOR_CORNSILK             255
#define COLOR_CRIMSON              209
#define COLOR_DARK_BLUE             19
#define COLOR_DARK_CYAN             43
#define COLOR_DARK_GOLDEN_ROD      184
#define COLOR_DARK_GRAY            193
#define COLOR_DARK_GREEN            34
#define COLOR_DARK_KHAKI           192
#define COLOR_DARK_MAGENTA         115
#define COLOR_DARK_OLIVE_GREEN      83
#define COLOR_DARK_ORANGE          232
#define COLOR_DARK_ORCHID          122
#define COLOR_DARK_RED             112
#define COLOR_DARK_SALMON          234
#define COLOR_DARK_SEA_GREEN       145
#define COLOR_DARK_SLATE_BLUE       73
#define COLOR_DARK_SLATE_GRAY       29
#define COLOR_DARK_TURQUOISE        56
#define COLOR_DARK_VIOLET          116
#define COLOR_DEEP_PINK            211
#define COLOR_DEEP_SKY_BLUE         51
#define COLOR_DIM_GRAY             132
#define COLOR_DODGER_BLUE           45
#define COLOR_FIRE_BRICK           166
#define COLOR_FLORAL_WHITE         255
#define COLOR_FOREST_GREEN          40
#define COLOR_FUCHSIA              213
#define COLOR_GAINSBORO            249
#define COLOR_GHOST_WHITE          255
#define COLOR_GOLD                 244
#define COLOR_GOLDEN_ROD           238
#define COLOR_GREEN_YELLOW         203
#define COLOR_HONEY_DEW            255
#define COLOR_HOT_PINK             230
#define COLOR_INDIAN_RED           222
#define COLOR_INDIGO                67
#define COLOR_IVORY                255
#define COLOR_KHAKI                253
#define COLOR_LAVENDER             255
#define COLOR_LAVENDER_BLUSH       255
#define COLOR_LAWN_GREEN           154
#define COLOR_LEMON_CHIFFON        254
#define COLOR_LIGHT_BLUE           201
#define COLOR_LIGHT_CORAL          235
#define COLOR_LIGHT_CYAN           255
#define COLOR_LIGHT_GOLDEN_ROD     254
#define COLOR_LIGHT_GREEN          157
#define COLOR_LIGHT_PINK           242
#define COLOR_LIGHT_SALMON         240
#define COLOR_LIGHT_SEA_GREEN       49
#define COLOR_LIGHT_SKY_BLUE       153
#define COLOR_LIGHT_SLATE_GRAY     139
#define COLOR_LIGHT_STEEL_BLUE     201
#define COLOR_LIGHT_YELLOW         255
#define COLOR_LIME                  58
#define COLOR_LIME_GREEN            53
#define COLOR_LINEN                255
#define COLOR_MAROON               112
#define COLOR_MEDIUM_AQUAMARINE    103
#define COLOR_MEDIUM_BLUE           20
#define COLOR_MEDIUM_ORCHID        176
#define COLOR_MEDIUM_PURPLE        135
#define COLOR_MEDIUM_SEA_GREEN      96
#define COLOR_MEDIUM_SLATE_BLUE    135
#define COLOR_MEDIUM_SPRING_GREEN   61
#define COLOR_MEDIUM_TURQUOISE     104
#define COLOR_MEDIUM_VIOLET_RED    163
#define COLOR_MIDNIGHT_BLUE         18
#define COLOR_MINT_CREAM           255
#define COLOR_MISTY_ROSE           255
#define COLOR_MOCCASIN             254
#define COLOR_NAVAJO_WHITE         248
#define COLOR_NAVY                  19
#define COLOR_OLD_LACE             255
#define COLOR_OLIVE                136
#define COLOR_OLIVE_DRAB           136
#define COLOR_ORANGE               238
#define COLOR_ORANGE_RED           220
#define COLOR_ORCHID               231
#define COLOR_PALE_GOLDEN_ROD      253
#define COLOR_PALE_GREEN           157
#define COLOR_PALE_TURQUOISE       207
#define COLOR_PALE_VIOLET_RED      229
#define COLOR_PAPAYA_WHIP          254
#define COLOR_PEACH_PUFF           248
#define COLOR_PERU                 233
#define COLOR_PINK                 248
#define COLOR_PLUM                 243
#define COLOR_POWDER_BLUE          207
#define COLOR_PURPLE               115
#define COLOR_REBECCA_PURPLE        73
#define COLOR_ROSY_BROWN           187
#define COLOR_ROYAL_BLUE            87
#define COLOR_SADDLE_BROWN         124
#define COLOR_SALMON               234
#define COLOR_SANDY_BROWN          240
#define COLOR_SEA_GREEN             42
#define COLOR_SEA_SHELL            255
#define COLOR_SIENNA               173
#define COLOR_SILVER               200
#define COLOR_SKY_BLUE             153
#define COLOR_SLATE_BLUE           128
#define COLOR_SLATE_GRAY           139
#define COLOR_SNOW                 255
#define COLOR_SPRING_GREEN          60
#define COLOR_STEEL_BLUE            92
#define COLOR_TAN                  241
#define COLOR_TEAL                  43
#define COLOR_THISTLE              243
#define COLOR_TOMATO               227
#define COLOR_TURQUOISE            110
#define COLOR_VIOLET               237
#define COLOR_WHEAT                248
#define COLOR_WHITE_SMOKE          255
#define COLOR_YELLOW_GREEN         197

// ------------------------------------------------------------------
//  putPixelRGB / putPixelRGBA - 24/32-bit -> indexed and write.
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

// Build a remap table from source palette indices to our RGB cube indices.
// map[i] = RGBToIndexed(srcPal[i].r, srcPal[i].g, srcPal[i].b) for 0 <= i < count.
static void buildPaletteMap(byte* map, RGBQuad* srcPal, int count)
{
    int i;
    for (i = 0; i < count && i < 256; i++)
        map[i] = RGBToIndexed(
            (byte)(unsigned char)srcPal[i].r,
            (byte)(unsigned char)srcPal[i].g,
            (byte)(unsigned char)srcPal[i].b);
}

// Initialise defaultPalette with VGA 16 + 5?8?6 RGB cube, then push to DAC.
static void initializeRGBPalette()
{
    int i;
    for (i = 0; i < 16; i++)
    {
        defaultPalette[i * 3]     = vgaPal[i][0];
        defaultPalette[i * 3 + 1] = vgaPal[i][1];
        defaultPalette[i * 3 + 2] = vgaPal[i][2];
    }
    for (i = 16; i < 256; i++)
    {
        int ii = i - 16;
        int ri = ii / 48, gi = (ii / 6) % 8, bi = ii % 6;
        defaultPalette[i * 3]     = (byte)((ri * 255 + 2) / 4);
        defaultPalette[i * 3 + 1] = (byte)(((gi * 255 + 3) / 7));
        defaultPalette[i * 3 + 2] = (byte)(((bi * 255 + 2) / 5));
    }
    setPaletteArray(defaultPalette, 256);
    updateSystemPalette();
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
