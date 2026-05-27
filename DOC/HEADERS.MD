# Header Files

All 12 headers live under `INCLUDE/`.  The old `EINCLUDE/` has been merged in,
and `DEFS.H` was absorbed into `CANVAS.H`.

## Header Tree

```
TYPES.H          types, colour constants, RGBToIndexed, sign/math helpers
PLATFORM.H       WIN/DOS detection, <fstream> compat
CANVAS.H         VGA constants, putPixel/drawLine/palette, Canvas class,
|                VgaCanvas/GdiCanvas/BgiCanvas, graphicsInit/Close/Update,
|                GDI callbacks
+-- INPUT.H      readKey, keyPressed, waitForKey, pollKeyboard,
|                escPressed, clearKeyBuffer
|                (no CANVAS.H dependency)
+-- MATH3D.H     Point3d, translate/rotate, ProjectionState, projectPoint
+-- RENDER.H     Wireframe + 2D + triangle raster + Z-buffer + textures
+-- PIXEL.H      vgaIndexToRGB, putPixelRGB/YUV conversion, Pixel24 class
+-- BITMAP.H     BMP loader/renderer
+-- TEXTURE.H    Texture loader
+-- IMAGE.H      Easy Image loader, readPaletteFile, image class
+-- FONTS.H      8x8 bitmap font + drawString
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

## Feature Flags (`-D`)

| Flag       | Effect                             | Status      |
|------------|------------------------------------|-------------|
| `-DWIN`    | Windows GDI backend                | Active      |
| `-DIBGI`   | Borland BGI backend                | Active      |
| `-DISVGA`  | SVGA BGI hi-res (needs `-DIBGI`)   | Active      |
| `-DIISO`   | Isometric projection engine        | Active      |
| `-DIZCLIP` | Z near/far plane clipping          | Active      |
| `-DIHSR`   | Hidden surface removal             | Active      |
| `-DIZBUF`  | Z-buffering                        | Active      |

## Build

```shell
BUILD.BAT MINGW        # all 12 examples
BUILD.BAT MSVC
BUILD.BAT BCC
```

Single file:
```shell
g++ -std=c++98 -DWIN -IINCLUDE EXMPLSRC\TRI.CPP -o TRI.EXE \
    -static-libgcc -static-libstdc++ -static -mwindows -lgdi32 -luser32
```

## Key API

| Category | Functions |
|----------|-----------|
| Init     | `graphicsInitialize()`, `graphicsClose()` |
| Display  | `graphicsUpdate()`, `graphicsClear()`, `graphicsDelay(ms)` |
| Pixel    | `putPixel(x, y)`, `putPixelRGB(x, y, r, g, b)`, `putPixelFast(x,y,c)` |
| 2D       | `drawLine(x1, y1, x2, y2)`, `drawRect(l, t, r, b)`, `drawCircle(cx, cy, r)` |
| Palette  | `setPalette(i, r, g, b)`, `setPaletteArray(p, n)`, `updateSystemPalette()`,
|          | `setBlackWhitePalette()` |
| 3D       | `readObject()`, `drawObject()`, `objectRotate()`, `objectTranslate()`,
|          | `drawAxis()`, `contourPlot()`, `sphereContourPlot()` |
| Screen   | `setMode(mode)`, `clearScreen()` |
| Input    | `readKey()`, `keyPressed()`, `waitForKey()`, `pollKeyboard()`, `escPressed()` |
| Colour   | `RGBToIndexed(r, g, b)`, `vgaIndexToRGB()`, `rgbToVgaIndex()`,
|          | `rgbToY/U/V()`, `yuvToR/G/B()` |

All drawing functions default to `currentColor`. `graphicsClear()` uses `currentBackgroundColor`.
Settable via `setColor()`/`setBackgroundColor()`, readable via `getColor()`/`getBackgroundColor()`.
