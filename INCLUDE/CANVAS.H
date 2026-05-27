// CANVAS.H - Display, drawing primitives, palette, Canvas backends.
// Merged from: DOSCOMP.H + MODE.H + VGA.H + DEFS.H + CANVAS.H.
// No input handling - keyboard lives in INPUT.H.
#ifndef INC_CANVAS_H
#define INC_CANVAS_H

#include <TYPES.H>
#include <PLATFORM.H>
#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

// DOS compatibility stubs (Windows/MinGW).
// Provides enough of <dos.h>, <bios.h>, <conio.h> to compile
// old DOS-targeted code under -DWIN.

#if defined(PLATFORM_WINDOWS)

// Callback so VGA.H can reach the GDI canvas without needing the
// full GdiCanvas definition.
extern void (*g_updatePalette)(const unsigned char* palette, int count);

// --- Stub for <dos.h> types ---
struct REGS
{
    union
    {
        struct
        {
            unsigned char al, ah;
        } h;
        struct
        {
            unsigned short ax;
        } x;
    };
};

inline int int86(int, REGS*, REGS*)
{
    return 0;
}

// --- Stub for <bios.h> (outp) ---
inline void outp(int, int)
{
}

// --- conio wrappers ---
inline int kbhit()
{
    return _kbhit();
}

// --- delay ---
inline void delay(int ms)
{
    Sleep(ms);
}

// --- clearScreen ---
inline void clearScreen()
{
}

// --- FP_SEG/FP_OFF stubs ---
#define FP_SEG(p) ((unsigned short)0)
#define FP_OFF(p) ((unsigned short)0)

#endif

// Set The Ball Rolling ....
// The Entry point of this Library Starts Here .
#ifndef INC_MODE_H
#define INC_MODE_H




#define VGA_VIDEO_INT        0x10
#define VGA_SET_MODE         0x00
#define VGA_TEXT_MODE        0x03
#define VGA_256_COLOR_MODE   0x13
#define VGA_PAL_INDEX        0x03c8
#define VGA_PAL_DATA         0x03c9


#if defined(__BORLANDC__) || defined(__WATCOMC__)
#define FAR __far
#else
#define FAR
#endif
byte FAR* VGA = (byte FAR*)0xA0000000L;

word screenWidth = 320, screenHeight = 200;

void setMode(byte mode)
{
#if !defined(PLATFORM_WINDOWS)
    union REGS regs;
    regs.h.ah = VGA_SET_MODE;
    regs.h.al = mode;
    int86(VGA_VIDEO_INT, &regs, &regs);
#else
    (void)mode;
#endif
}

#endif

// Basic VGA Library Routines.
#ifndef INC_VGA_H
#define INC_VGA_H




byte currentColor = WHITE;
byte currentBackgroundColor = BLACK;
byte defaultPalette[PALETTE_BYTES];

#define CLAMP_X(x)  ((int)(x) < 0 ? 0 : ((int)(x) >= (int)screenWidth  ? (int)screenWidth  - 1 : (int)(x)))
#define CLAMP_Y(y)  ((int)(y) < 0 ? 0 : ((int)(y) >= (int)screenHeight ? (int)screenHeight - 1 : (int)(y)))

inline void check(int& x, int& y) { x = CLAMP_X(x); y = CLAMP_Y(y); }

inline void putPixel(int x, int y, byte color = currentColor)
{
    x = CLAMP_X(x); y = CLAMP_Y(y);
    VGA[y * (int)screenWidth + x] = color;
}

inline byte getPixel(int x, int y)
{
    x = CLAMP_X(x); y = CLAMP_Y(y);
    return VGA[y * (int)screenWidth + x];
}

#define putPixelFast(x, y, c) \
    VGA[CLAMP_Y(y) * (int)screenWidth + CLAMP_X(x)] = (byte)(c)
#define getPixelFast(x, y) \
    VGA[CLAMP_Y(y) * (int)screenWidth + CLAMP_X(x)]

void drawLine(int x1, int y1, int x2, int y2, byte color = currentColor)
{
    check(x1, y1);
    check(x2, y2);
    int i, dx, dy, sdx, sdy, dxabs, dyabs, x, y, px, py;
    dx = x2 - x1;
    dy = y2 - y1;
    dxabs = abs(dx);
    dyabs = abs(dy);
    sdx = sign(dx);
    sdy = sign(dy);
    x = dyabs >> 1;
    y = dxabs >> 1;
    px = x1;
    py = y1;
    putPixel(px, py, color);
    if (dxabs >= dyabs)
    {
        for (i = 0; i < dxabs; i++)
        {
            y += dyabs;
            if (y >= dxabs)
            {
                y -= dxabs;
                py += sdy;
            }
            px += sdx;
            putPixelFast(px, py, color);
        }
    }
    else
    {
        for (i = 0; i < dyabs; i++)
        {
            x += dxabs;
            if (x >= dyabs)
            {
                x -= dxabs;
                px += sdx;
            }
            py += sdy;
            putPixelFast(px, py, color);
        }
    }
}

void drawRect(int left, int top, int right, int bottom, byte color = currentColor)
{
    drawLine(left, top, right, top, color);
    drawLine(left, top, left, bottom, color);
    drawLine(right, top, right, bottom, color);
    drawLine(left, bottom, right, bottom, color);
}

void drawCircle(int x, int y, int radius, byte color = currentColor)
{
    check(x, y);
    int o;
    double rx, ry;
    for (o = 0; o < 360; o++)
    {
        rx = radius * cos(degToRad(o));
        ry = radius * sin(degToRad(o));
        putPixelFast((int)(x + rx), (int)(y + ry), color);
    }
}

// --- Palette abstraction ---
// setPalette(i,r,g,b)  - sets defaultPalette[i] in memory
// setPaletteArray(p)   - bulk copy into defaultPalette
// updateSystemPalette() - pushes defaultPalette to VGA DAC (DOS) or
//                         GDI DIB colour table (Windows)
// setBlackWhitePalette() - greyscale derived from defaultPalette

void setPalette(int index, byte r, byte g, byte b)
{
    if (index < 0 || index >= 256) return;
    defaultPalette[index * 3]     = r;
    defaultPalette[index * 3 + 1] = g;
    defaultPalette[index * 3 + 2] = b;
}

void setPaletteArray(byte* palette, int count)
{
    int i;
    for (i = 0; i < count && i < 256; i++)
    {
        defaultPalette[i * 3]     = palette[i * 3];
        defaultPalette[i * 3 + 1] = palette[i * 3 + 1];
        defaultPalette[i * 3 + 2] = palette[i * 3 + 2];
    }
}

void updateSystemPalette()
{
#if !defined(PLATFORM_WINDOWS)
    int i;
    outp(VGA_PAL_INDEX, 0);
    for (i = 0; i < 256 * 3; i++)
    {
        outp(VGA_PAL_DATA, defaultPalette[i]);
    }
#else
    if (g_updatePalette) g_updatePalette(defaultPalette, 256);
#endif
}

void setBwPalette()
{
    for (int i = 0; i < NUM_COLORS; i++)
    {
        byte grey = (defaultPalette[i * 3] + defaultPalette[i * 3 + 1] +
                     defaultPalette[i * 3 + 2]) / 3;
        defaultPalette[i * 3] = defaultPalette[i * 3 + 1] = defaultPalette[i * 3 + 2] = grey;
    }
    updateSystemPalette();
}

void fadeIn()
{
    for (int i = 0; i < NUM_COLORS * 3; i++)
        defaultPalette[i] = 0;
    updateSystemPalette();
}

void setColor(byte color)
{
    currentColor = color;
}

byte getColor()
{
    return currentColor;
}

word getMaxX()
{
    return screenWidth - 1;
}

word getMaxY()
{
    return screenHeight - 1;
}

void graphicsClear()
{
    memset(VGA, currentBackgroundColor, (size_t)screenWidth * screenHeight);
}

void setRgbPalette(int color, int r, int g, int b)
{
    setPalette(color, (byte)r, (byte)g, (byte)b);
    updateSystemPalette();
}

#endif


// ------------------------------------------------------------------
//  Abstract Canvas interface
// ------------------------------------------------------------------

class Canvas
{
public:
    Canvas() : currentColor(0) {}
    virtual ~Canvas() {}

    virtual bool init(int width, int height) = 0;
    virtual void shutdown() = 0;

    virtual int width() const = 0;
    virtual int height() const = 0;

    virtual void putPixel(int x, int y, byte color) = 0;
    virtual byte getPixel(int x, int y) = 0;

    virtual void clear(byte color) = 0;

    virtual void setPalette(int index, byte r, byte g, byte b) = 0;
    virtual void setPaletteArray(const byte* palette, int count) = 0;

    virtual void present() {}

    virtual byte* frameBuffer() { return NULL; }

    void setPaletteFromRGB(const byte* rgbPalette, int count);

    void setColor(byte color) { currentColor = color; }
    byte getColor() const { return currentColor; }
    void setBackgroundColor(byte color) { currentBackgroundColor = color; }
    byte getBackgroundColor() const { return currentBackgroundColor; }

    int maxX() const { return width() - 1; }
    int maxY() const { return height() - 1; }
    int midX() const { return width() / 2; }
    int midY() const { return height() / 2; }

protected:
    byte currentColor;
};

#ifndef __BORLANDC__
inline
#endif
void Canvas::setPaletteFromRGB(const byte* rgbPalette, int count)
{
    for (int i = 0; i < count && i < NUM_COLORS; i++)
        setPalette(i, rgbPalette[i * 3], rgbPalette[i * 3 + 1], rgbPalette[i * 3 + 2]);
}

// ------------------------------------------------------------------
//  VgaCanvas - native DOS VGA Mode 13h
// ------------------------------------------------------------------

#if defined(PLATFORM_DOS)

class VgaCanvas : public Canvas
{
    word screenWidth, screenHeight;

public:
    VgaCanvas() : Canvas(), screenWidth(0), screenHeight(0) {}
    virtual ~VgaCanvas() {}

    virtual bool init(int width, int height);
    virtual void shutdown();
    virtual int width() const { return screenWidth; }
    virtual int height() const { return screenHeight; }
    virtual void putPixel(int x, int y, byte color);
    virtual byte getPixel(int x, int y);
    virtual void clear(byte color);
    virtual void setPalette(int index, byte r, byte g, byte b);
    virtual void setPaletteArray(const byte* palette, int count);

private:
    void setMode(byte mode)
    {
        union REGS regs;
        regs.h.ah = VGA_SET_MODE;
        regs.h.al = mode;
        int86(VGA_VIDEO_INT, &regs, &regs);
    }

    void clamp(int& x, int& y)
    {
        if (x < 0) x = 0;
        if (y < 0) y = 0;
        if (x >= screenWidth)  x = screenWidth - 1;
        if (y >= screenHeight) y = screenHeight - 1;
    }
};

bool VgaCanvas::init(int width, int height)
{
    screenWidth = (word)width;
    screenHeight = (word)height;
    setMode(VGA_256_COLOR_MODE);
    VGA = (byte FAR*)0xA0000000L;
    return true;
}

void VgaCanvas::shutdown()
{
    setMode(VGA_TEXT_MODE);
}

void VgaCanvas::putPixel(int x, int y, byte color)
{
    clamp(x, y);
    VGA[y * screenWidth + x] = color;
}

byte VgaCanvas::getPixel(int x, int y)
{
    clamp(x, y);
    return VGA[y * screenWidth + x];
}

void VgaCanvas::clear(byte color)
{
    memset(VGA, color, (size_t)screenWidth * screenHeight);
}

void VgaCanvas::setPalette(int index, byte r, byte g, byte b)
{
    outp(VGA_PAL_INDEX, index);
    outp(VGA_PAL_DATA, r);
    outp(VGA_PAL_DATA, g);
    outp(VGA_PAL_DATA, b);
}

void VgaCanvas::setPaletteArray(const byte* palette, int count)
{
    outp(VGA_PAL_INDEX, 0);
    for (int i = 0; i < count * 3; i++)
        outp(VGA_PAL_DATA, palette[i]);
}

#endif

// ------------------------------------------------------------------
//  GdiCanvas - Windows GDI (DIB section)
// ------------------------------------------------------------------

#if defined(PLATFORM_WINDOWS)

class GdiCanvas : public Canvas
{
public:
    GdiCanvas() : Canvas(), hWnd(NULL), hDC(NULL), hMemDC(NULL),
                  hBitmap(NULL), hOldBitmap(NULL), dibBits(NULL),
                  screenWidth(0), screenHeight(0), running(false) {}
    virtual ~GdiCanvas() {}

    virtual bool init(int width, int height)
    {
        screenWidth = width;
        screenHeight = height;

        HINSTANCE hInstance = (HINSTANCE)GetModuleHandle(NULL);
        if (!hInstance) return false;

        WNDCLASS wc;
        wc.style = CS_HREDRAW | CS_VREDRAW;
        wc.lpfnWndProc = windowProc;
        wc.cbClsExtra = sizeof(GdiCanvas*);
        wc.cbWndExtra = 0;
        wc.hInstance = hInstance;
        wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);
        wc.hCursor = LoadCursor(NULL, IDC_ARROW);
        wc.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);
        wc.lpszMenuName = NULL;
        wc.lpszClassName = "GdiCanvasClass";

        RegisterClass(&wc);

        RECT rect = {0, 0, width, height};
        AdjustWindowRect(&rect, WS_OVERLAPPED | WS_CAPTION | WS_SYSMENU, FALSE);
        int winWidth = rect.right - rect.left;
        int winHeight = rect.bottom - rect.top;

        hWnd = CreateWindow("GdiCanvasClass", "3DGFX",
                            WS_OVERLAPPED | WS_CAPTION | WS_SYSMENU,
                            CW_USEDEFAULT, CW_USEDEFAULT,
                            winWidth, winHeight, NULL, NULL, hInstance, this);
        if (!hWnd) return false;

        hDC = GetDC(hWnd);
        hMemDC = CreateCompatibleDC(hDC);

        struct { BITMAPINFOHEADER h; RGBQUAD c[256]; } bmi;
        ZeroMemory(&bmi, sizeof(bmi));
        bmi.h.biSize = sizeof(BITMAPINFOHEADER);
        bmi.h.biWidth = width;
        bmi.h.biHeight = -height;
        bmi.h.biPlanes = 1;
        bmi.h.biBitCount = 8;
        bmi.h.biCompression = BI_RGB;
        bmi.h.biSizeImage = 0;
        bmi.h.biClrUsed = 256;
        bmi.h.biClrImportant = 256;

        hBitmap = CreateDIBSection(hMemDC, (BITMAPINFO*)&bmi, DIB_RGB_COLORS,
                                   (void**)&dibBits, NULL, 0);
        if (!hBitmap)
        {
            ReleaseDC(hWnd, hDC); DeleteDC(hMemDC);
            DestroyWindow(hWnd); hWnd = NULL;
            return false;
        }

        hOldBitmap = (HBITMAP)SelectObject(hMemDC, hBitmap);
        initDefaultPalette();
        SetWindowLongPtr(hWnd, GWLP_USERDATA, (LONG_PTR)this);
        ShowWindow(hWnd, SW_SHOW);
        UpdateWindow(hWnd);
        running = true;
        return true;
    }

    virtual void shutdown()
    {
        running = false;
        if (hMemDC) { if (hBitmap) SelectObject(hMemDC, hOldBitmap); DeleteDC(hMemDC); }
        if (hBitmap) DeleteObject(hBitmap);
        if (hDC && hWnd) ReleaseDC(hWnd, hDC);
        if (hWnd) DestroyWindow(hWnd);
        hWnd = NULL; hDC = NULL; hMemDC = NULL; hBitmap = NULL; dibBits = NULL;
    }

    virtual int width() const { return screenWidth; }
    virtual int height() const { return screenHeight; }

    virtual void putPixel(int x, int y, byte color)
    {
        if (x >= 0 && x < screenWidth && y >= 0 && y < screenHeight)
            dibBits[y * screenWidth + x] = color;
    }

    virtual byte getPixel(int x, int y)
    {
        if (x >= 0 && x < screenWidth && y >= 0 && y < screenHeight)
            return dibBits[y * screenWidth + x];
        return 0;
    }

    virtual void clear(byte color)
    {
        memset(dibBits, color, (size_t)screenWidth * screenHeight);
    }

    virtual void setPalette(int index, byte r, byte g, byte b)
    {
        if (index < 0 || index >= 256 || !hMemDC || !hBitmap) return;
        RGBQUAD colorTable[256];
        GetDIBColorTable(hMemDC, 0, 256, colorTable);
        colorTable[index].rgbRed = r;
        colorTable[index].rgbGreen = g;
        colorTable[index].rgbBlue = b;
        SetDIBColorTable(hMemDC, 0, 256, colorTable);
    }

    virtual void setPaletteArray(const byte* palette, int count)
    {
        if (!hMemDC || !hBitmap) return;
        RGBQUAD colorTable[256];
        int numColors = count > 256 ? 256 : count;
        for (int i = 0; i < numColors; i++)
        {
            colorTable[i].rgbRed = palette[i * 3];
            colorTable[i].rgbGreen = palette[i * 3 + 1];
            colorTable[i].rgbBlue = palette[i * 3 + 2];
            colorTable[i].rgbReserved = 0;
        }
        SetDIBColorTable(hMemDC, 0, numColors, colorTable);
    }

    virtual void present()
    {
        if (!hWnd || !hDC || !hMemDC) return;
        BitBlt(hDC, 0, 0, screenWidth, screenHeight, hMemDC, 0, 0, SRCCOPY);
        MSG msg;
        while (PeekMessage(&msg, hWnd, 0, 0, PM_NOREMOVE))
        {
            if (msg.message >= WM_KEYFIRST && msg.message <= WM_KEYLAST)
                break; // leave keyboard messages for keyPressed/readKey
            PeekMessage(&msg, hWnd, msg.message, msg.message, PM_REMOVE);
            if (msg.message == WM_QUIT) { running = false; break; }
            TranslateMessage(&msg); DispatchMessage(&msg);
        }
    }

    bool isRunning() const { return running; }

    virtual byte* frameBuffer() { return dibBits; }

private:
    HWND hWnd; HDC hDC, hMemDC;
    HBITMAP hBitmap, hOldBitmap;
    byte* dibBits;
    int screenWidth, screenHeight;
    bool running;

    void initDefaultPalette()
    {
        static const byte vga16[16][3] = {
            {  0,  0,  0 }, {  0,  0,170 }, {  0,170,  0 }, {  0,170,170 },
            {170,  0,  0 }, {170,  0,170 }, {170, 85,  0 }, {170,170,170 },
            { 85, 85, 85 }, { 85, 85,255 }, { 85,255, 85 }, { 85,255,255 },
            {255, 85, 85 }, {255, 85,255 }, {255,255, 85 }, {255,255,255 },
        };
        RGBQUAD colorTable[256];
        for (int i = 0; i < 256; i++)
        {
            if (i < 16) {
                colorTable[i].rgbRed = vga16[i][0];
                colorTable[i].rgbGreen = vga16[i][1];
                colorTable[i].rgbBlue = vga16[i][2];
            } else {
                // 5?8?6 RGB cube ? native 8-bit
                int ii = i - 16;
                int ri = ii / 48, gi = (ii / 6) % 8, bi = ii % 6;
                colorTable[i].rgbRed   = (byte)((ri * 255 + 2) / 4);
                colorTable[i].rgbGreen = (byte)((gi * 255 + 3) / 7);
                colorTable[i].rgbBlue  = (byte)((bi * 255 + 2) / 5);
            }
            colorTable[i].rgbReserved = 0;
        }
        SetDIBColorTable(hMemDC, 0, 256, colorTable);
    }

    static LRESULT CALLBACK windowProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
    {
        GdiCanvas* c = (GdiCanvas*)GetWindowLongPtr(hWnd, GWLP_USERDATA);
        if (msg == WM_CLOSE) { if (c) c->running = false; return 0; }
        if (msg == WM_DESTROY) { PostQuitMessage(0); return 0; }
        if (msg == WM_PAINT && c)
        {
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hWnd, &ps);
            BitBlt(hdc, 0, 0, c->screenWidth, c->screenHeight,
                   c->hMemDC, 0, 0, SRCCOPY);
            EndPaint(hWnd, &ps);
            return 0;
        }
        return DefWindowProc(hWnd, msg, wParam, lParam);
    }

    GdiCanvas(const GdiCanvas&);
    GdiCanvas& operator=(const GdiCanvas&);
};

#endif

// ------------------------------------------------------------------
//  BgiCanvas - Borland BGI backend
// ------------------------------------------------------------------

#if defined(IBGI)

class BgiCanvas : public Canvas
{
public:
    BgiCanvas() : Canvas(), bgDriver(0), bgMode(0) {}
    virtual ~BgiCanvas() {}

    virtual bool init(int, int)
    {
        bgDriver = DETECT;
        initgraph(&bgDriver, &bgMode, "..\\INCLUDE\\BGI");
        return graphresult() == grOk;
    }

    virtual void shutdown() { closegraph(); restorecrtmode(); }

    virtual int width() const  { return getmaxx() + 1; }
    virtual int height() const { return getmaxy() + 1; }

    virtual void putPixel(int x, int y, byte color) { putpixel(x, y, (int)color); }
    virtual byte getPixel(int x, int y) { return (byte)getpixel(x, y); }

    virtual void clear(byte) { cleardevice(); }

    virtual void setPalette(int index, byte r, byte g, byte b)
    { setrgbpalette(index, (int)r, (int)g, (int)b); }

    virtual void setPaletteArray(const byte* palette, int count)
    {
        for (int i = 0; i < count && i < 256; i++)
            setrgbpalette(i, (int)palette[i * 3],
                          (int)palette[i * 3 + 1],
                          (int)palette[i * 3 + 2]);
    }

private:
    int bgDriver, bgMode;
};

#endif

// ------------------------------------------------------------------
//  graphicsInitialize / graphicsClose / graphicsUpdate
// ------------------------------------------------------------------

#if defined(PLATFORM_WINDOWS)

inline GdiCanvas* getGdiCanvas()
{
    static GdiCanvas canvas;
    return &canvas;
}

void updatePalette(const unsigned char* palette, int count)
{
    getGdiCanvas()->setPaletteArray(palette, count);
}

void (*g_updatePalette)(const unsigned char*, int) = updatePalette;

#define maxX screenWidth - 1
#define maxY screenHeight - 1
#define midX (screenWidth / 2)
#define midY (screenHeight / 2)

void graphicsInitialize()
{
    clearScreen();
    getGdiCanvas()->init(320, 200);
    VGA = getGdiCanvas()->frameBuffer();
    screenWidth  = (word)getGdiCanvas()->width();
    screenHeight = (word)getGdiCanvas()->height();
}

void graphicsClose()
{
    getGdiCanvas()->shutdown();
}

#elif defined(_MSC_VER) || defined(__GNUC__) || defined(__WATCOMC__) || defined(__BORLANDC__)

void clearScreen()
{
    printf("\f");
}

#endif

// ------------------------------------------------------------------
//  BGI Backend
// ------------------------------------------------------------------

#ifdef IBGI

int bgiDriver, bgiMode;
char bgiPath[] = {"..\\BGI"};

#ifndef ISVGA
void graphicsInitialize()
{
    clearScreen();
    bgiDriver = DETECT;
    initgraph(&bgiDriver, &bgiMode, bgiPath);
}
#endif

#ifdef ISVGA
#define SVGAPATH "SVGA256"

void graphicsInitialize()
{
    bgiDriver = installuserdriver(SVGAPATH, NULL), bgiMode = SVGA640x480x256;
    initgraph(&bgiDriver, &bgiMode, bgiPath);
    if (graphresult() != grOk) return;
}
#endif

void graphicsClose()
{
    closegraph();
    restorecrtmode();
    clearScreen();
}

#define maxX          getmaxx()
#define maxY          getmaxy()
#define midX          (maxX + 1) / 2
#define midY          (maxY + 1) / 2
#define screenWidth  maxX + 1
#define screenHeight maxY + 1

#endif

// ------------------------------------------------------------------
//  Native DOS VGA Backend
// ------------------------------------------------------------------

#if !defined(IBGI) && !defined(PLATFORM_WINDOWS)

#define maxX screenWidth - 1
#define maxY screenHeight - 1
#define midX (screenWidth / 2)
#define midY (screenHeight / 2)

void graphicsInitialize()
{
    clearScreen();
    setMode(VGA_256_COLOR_MODE);
}

void graphicsClose()
{
    setMode(VGA_TEXT_MODE);
}

#endif

// ------------------------------------------------------------------
//  graphicsUpdate
// ------------------------------------------------------------------

#if defined(PLATFORM_WINDOWS)
inline void graphicsUpdate()
{
    getGdiCanvas()->present();
}
#else
inline void graphicsUpdate() {}
#endif

// ------------------------------------------------------------------
//  graphicsDelay - millisecond sleep for frame timing
// ------------------------------------------------------------------

#if defined(PLATFORM_WINDOWS)
inline void graphicsDelay(uint32 ms)
{
    Sleep(ms);
}
#else
static void graphicsDelay(uint32 ms)
{
    delay((int)ms);
}
#endif

#endif
