// Definitions File.

#ifndef IDEF
#define IDEF

#if defined(_MSC_VER) || defined(__GNUC__) || defined(__WATCOMC__)

#include <stdio.h>

void clrscr()
{
    printf("\f");
}

void delay(int delaytime)
{
   //TODO: Implement for Microsoft C/C++.
}

#endif

#ifdef IBGI
#include <graphics.h>

int bgm, bgd;
char bgpath[] = {"..\\BGI"}; // Fix Your Own BGI Path !

#ifndef ISVGA
void graini()
{
    clrscr();
    bgd = DETECT;
    initgraph(&bgd, &bgm, bgpath);
}
#endif

#ifdef ISVGA
#include <svga256.h>
#define SVGAPATH "SVGA256"

void setsvgapal()
{
    int i;
    DacPalette256 PalBuf;
    REGPACK reg;
    PalBuf[0][0] = PalBuf[0][1] = PalBuf[0][2] = 0;
    for (i = 1; i < 256; i++)
    {
        PalBuf[i][0] = i / 16;
        PalBuf[i][1] = i % 64;
        PalBuf[i][2] = (255 - i) / 4;
    }
    reg.r_ax = 0x1013;
    reg.r_bx = 0;
    reg.r_cx = 256;
    reg.r_es = FP_SEG(PalBuf);
    reg.r_dx = FP_OFF(PalBuf);
    intr(0x10, &reg);
}

void graini(int tm = SVGA640x480x256)
{
    bgd = installuserdriver(SVGAPATH, NULL), bgm = tm;
    initgraph(&bgd, &bgm, bgpath);
    if (graphresult() != grOk)
    {
        return;
    }
    setsvgapal();
}

#endif

void graclo()
{
    closegraph();
    restorecrtmode();
    clrscr();
}

#define svgraini() graini()

#define maxx          getmaxx()
#define maxy          getmaxy()
#define midx          (maxx + 1) / 2
#define midy          (maxy + 1) / 2
#define screen_width  maxx + 1
#define screen_height maxy + 1

#endif

#ifndef IBGI
#include <vga.h>

#define maxx screen_width - 1
#define maxy screen_height - 1
#define midx (screen_width / 2)
#define midy (screen_height / 2)

void graini()
{
    clrscr();
    set_mode(VGA_256_COLOR_MODE);
}

void graclo()
{
    set_mode(TEXT_MODE);
}
#endif

#endif
