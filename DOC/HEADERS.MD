# Header Files

All headers live under `INCLUDE/`. The old `EINCLUDE/` has been merged in,
and `DEFS.H` was absorbed into `CANVAS.H`.

## Header Tree

```
TYPES.H          types, BGI colour constants, RGBToIndexed, sign/math helpers
PLATFORM.H       WIN/DOS detection, compiler detection, <fstream> compat
CANVAS.H         VGA constants, putPixel/drawLine/palette, Canvas class,
|                VgaCanvas/GdiCanvas/BgiCanvas, graphicsInit/Close/Update
+-- INPUT.H      readKey, keyPressed, waitForKey, pollKeyboard,
|                escPressed (no CANVAS.H dependency)
+-- MATH3D.H     Point3d, translate/rotate, ProjectionState, projectPoint
+-- PIXEL.H      COLOR_*/web colour constants, vgaIndexToRGB, buildPaletteMap,
|                initializeRGBPalette, putPixelRGB, YUV conversion
+-- RENDER.H     Wireframe + triangle raster + Z-buffer + textures
+-- BITMAP.H     Universal BMP loader (all bit depths, RLE, BI_BITFIELDS),
|                converts to 8-bit RGB cube indices at load time
+-- TEXTURE.H    BMP texture loader (ITEX-gated), converts to RGB cube indices
+-- IMAGE.H      Easy Image loader (.IM format), readPaletteFile, image class
+-- FTDEF.H      8×8 font type + DEFAULT_FONT bitmap + GlyphRange/FontDesc structs
+-- FTARK.H      ARK-Pixel-Font master (includes FTARK00–217.H per Unicode range)
|   +-- FTARK00–217.H  per-range ARK glyph data (3161 glyphs, 218 blocks)
+-- FTUNI.H      GNU Unifont BMP master (includes FTUNI00–222.H per block)
|   +-- FTUNI00–222.H  per-range Unifont glyph data (57086 glyphs, 223 blocks)
+-- FONTS.H      8×8 bitmap font + Unicode renderer + drawString/drawPrintf
+-- LOG.H        Debug logging (logInit/logQuit/logPrintf, DEBUG-gated)
+-- SVGA256.H    SVGA BGI driver header
```

## Platform Selection (BUILD.BAT)

| Command         | Compiler                        | `%OUT_TO%` | `%LIBS%` |
|-----------------|---------------------------------|------------|----------|
| `BUILD MINGW`   | MinGW-w64 GCC (Windows GDI)     | `-o`       | `-static-libgcc -static-libstdc++ -static -mwindows -lgdi32 -luser32` |
| `BUILD MSVC`    | MSVC (Windows GDI)              | `/Fe`      | `gdi32.lib user32.lib` |
| `BUILD BCC`     | Borland C++ (DOS)               | `-o`       | *(empty)* |
| `BUILD WCL`     | OpenWatcom C++ (DOS)            | `-fe=`     | *(empty)* |
| `BUILD DJGPP`   | DJGPP GCC (DOS)                 | `-o`       | *(empty)* |
| `BUILD CL`      | Microsoft C/C++ for DOS         | `/Fe`      | *(empty)* |

Add any second argument for debug mode: `BUILD.BAT MSVC 1`
Adds `-DDEBUG` and debug-info flags (`-g` / `/Zi` / `-v`).

## Feature Flags (`-D`)

| Flag         | Effect                             | Default     |
|--------------|------------------------------------|-------------|
| `-DWIN`      | Windows GDI backend                | On for Win  |
| `-DIBGI`     | Borland BGI backend                | Off         |
| `-DISVGABGI` | SVGA BGI hi-res (needs `-DIBGI`)   | Off         |
| `-DIISO`     | Isometric projection engine        | Off         |
| `-DIZCLIP`   | Z near/far plane clipping          | Off         |
| `-DITEX`     | Texture-mapped objects             | Off         |
| `-DIZBUF`    | Z-buffering                        | Off         |
| `-DIHSR`     | Hidden surface removal             | Off         |
| `-DDEBUG`    | Enable logInit/logPrintf logging   | Off         |

## Build

```shell
BUILD.BAT MINGW
BUILD.BAT MSVC
BUILD.BAT BCC
BUILD.BAT MSVC 1       # debug build
BUILD.BAT BCC 1        # debug build (DOSBox)
```

Single file (Windows):
```shell
g++ -std=c++98 -DWIN -IINCLUDE EXMPLSRC\TRI.CPP -o TRI.EXE \
    -static-libgcc -static-libstdc++ -static -mwindows -lgdi32 -luser32
```

## Key API

| Category   | Functions |
|------------|-----------|
| Init       | `graphicsInitialize()`, `graphicsClose()` |
| Display    | `graphicsUpdate()`, `graphicsClear()`, `graphicsDelay(ms)` |
| Pixel      | `putPixel(x, y, c)`, `putPixelRGB(x, y, r, g, b)`, `putPixelFast(x,y,c)` |
| 2D         | `drawLine(x1, y1, x2, y2)`, `drawRect(l, t, r, b)`, `drawCircle(cx, cy, r)` |
| Palette    | `initializeRGBPalette()`, `setPalette(i, r, g, b)`, `setPaletteArray(p, n)`, |
|            | `updateSystemPalette()`, `setBwPalette()`, `fadeIn()` |
| Colour     | `COLOR_BLACK` ... `COLOR_WHITE` (VGA hw indices 0-15), |
|            | `COLOR_CORAL`, `COLOR_NAVY` ... 140+ web colour constants (indices 16-255), |
|            | `RED`, `GREEN` ... (bare BGI names), |
|            | `RGBToIndexed(r,g,b)`, `vgaIndexToRGB(i)`, `rgbToVgaIndex(r,g,b)`, |
|            | `rgbToY/U/V()`, `yuvToR/G/B()` |
| 3D         | `readObject()`, `drawObject()`, `objectRotate()`, `objectTranslate()`, |
|            | `drawAxis()`, `drawPoint()`, `contourPlot()`, `sphContourPlot()` |
| Font       | `drawString(text, x, y, color)`, `drawStringFixed(text, x, y, color)` |
|            | `drawStringCP(text, x, y, color)`, `drawStringWithSize(text, x, y, color, size)` |
|            | `drawStringScaled(text, x, y, color, scale)` – Unicode text at any scale |
|            | `textWidth(text, scale)` – pixel width of a string at given scale |
|            | `drawPrintf(x, y, color, fmt, ...)`, `drawPrintfFixed(x, y, color, fmt, ...)` |
|            | Unicode renderer always available — include `<FTARK.H>` / `<FTUNI.H>` for data: |
|            | `drawString` = proportional advance (per‑glyph width) |
|            | `drawStringFixed` = uniform cell‑width advance (8px for ARK) |
|            | `drawStringScaled` = draw at integer scale multiplier |
|            | `textWidth(text, scale)` – pixel width of a string |
|            | `isCpControl(cp)`, `isCpSpace(cp)`, `isCpZero(cp)` — codepoint classification macros |
|            | `cpAdvance(fa, g, m)` — advance width helper macro |
|            | Greek, Cyrillic, Japanese, CJK via ARK font (FTARK.H) |
|            | Devanagari, Tamil, Thai, Arabic, Hebrew, etc. via Unifont fallback (FTUNI.H) |
|            | Combining marks, ZWJ/ZWNJ handled automatically |
|            | RTL auto‑detection for Arabic, Hebrew, Persian, Urdu |
|            | **Sparse include**: `#define WANT_FTARK_SELECT` + `WANT_FTARK_00` etc. |
|            | **Custom font chain**: `#define CUSTOM_FONT_CHAIN`, define `_fontChain[]` + `FONT_CHAIN_COUNT` |
|            | `dispChar()` renders with transparency (skips background pixels) |
|            | See `EXMPLSRC\TEXT.CPP` for scrolling multi‑script demo |
| Bitmap     | `loadBitmapInto(fileName, bmp, flags)`, `drawBitmap(bmp, x, y)`, `bitmapPixel(bmp, x, y)` |
|            | `BitmapFlags::ToIndexed8`, `BitmapFlags::KeepSourcePalette` |
| Image      | `image::load(fn, xorKey, flags)`, `image::draw(x,y)`, |
|            | `image::loadPalette(fn)`, `image::convertToTruePalette()` |
|            | `ImageFlags::ToIndexed8` |
| Texture    | (ITEX-gated) `loadTextures()`, `loadUsedTextures()`, `drawTexturedObject()` |
| Logging    | (DEBUG-gated) `logInit()`, `logQuit()`, `logPrintf(fmt, ...)` |
| Input      | `readKey()`, `keyPressed()`, `waitForKey()`, `pollKeyboard()`, `escPressed()` |

All drawing functions default to `currentColor`. `graphicsClear()` uses `currentBackgroundColor`.
Settable via `setColor(c)`/`setBackgroundColor(c)`, readable via `getColor()`/`getBackgroundColor()`.
