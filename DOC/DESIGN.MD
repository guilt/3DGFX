# Library Design

## 3D Pipeline

Wireframe objects are drawn via `drawPoint()` / `drawLine()` / `drawTriangle()` using
the projection defined by `projPoint()` / `projPoint1()` / `projPoint2()` (perspective by
default, isometric with `-DIISO`).  The projection parameters (`xScale`, `yScale`,
`zScale`) are globals set in `RENDER.H`; `midX`/`midY` are macros for the screen centre.

Contour surfaces use `contourPlot()` / `sphereContourPlot()` for spherical coordinates.

## Coordinate System

Right-handed:
```
    Y
    ^
    |
    |-----> X
   /
  /
 v
Z
```

Isometric (`-DIISO`):
```
        Y
        ^
        |
       / \
      /   \
     v     v
    Z       X
```

## Object File Format

Wireframe (.MSH):
```
n
x0, y0, z0
...
xN, yN, zN
l
v1, v2
...
```

Textured (.MSH):
```
n
x0, y0, z0
...
xN, yN, zN
l
v1, v2, v3: t
...
```

Texture list (.TEX):
```
nt
tex0.BMP
...
```

## Colour System

- **Indices 0?15**: Standard BGI/VGA colours (`BLACK`, `BLUE`, ?, `WHITE`).
  Use `putPixel(x, y, RED)` for direct BGI-compatible output.
- **Indices 16?255**: 5?8?6 RGB cube (240 colours).
  Use `putPixelRGB(x, y, r, g, b)` or `RGBToIndexed(r, g, b)`.
- `initializeRGBPalette()` sets up the full palette.
- `vgaIndexToRGB()` / `rgbToVgaIndex()` convert between index and RGB.

## Palette Abstraction

| Function | Purpose |
|----------|---------|
| `setPalette(i, r, g, b)` | Sets one entry in `defaultPalette` |
| `setPaletteArray(p, n)` | Bulk copy into `defaultPalette` |
| `updateSystemPalette()` | Commits `defaultPalette` to VGA DAC (DOS) or GDI DIB colour table (Windows) |
| `graphicsUpdate()` | Flushes framebuffer to screen (Windows: `present()`, DOS: no-op) |
| `graphicsClear()` | Fills screen with `currentBackgroundColor` (uses `memset`) |
| `graphicsDelay(ms)` | Millisecond sleep for frame timing (Windows: `Sleep`, DOS: busy loop) |

## Keyboard Input

Provided by `<INPUT.H>`:

| Function | Purpose |
|----------|---------|
| `readKey()` | Block until a key, return `KEY_` code |
| `keyPressed()` | Non-blocking check |
| `waitForKey()` | Block (ignore which key) |
| `pollKeyboard()` | Pump GDI message loop (Windows) |
| `escPressed()` | Direct ESC key state (no queue, uses `GetAsyncKeyState` on Windows) |
| `clearKeyBuffer()` | Flush buffered input |

On Windows GDI, `readKey()` drives `GetMessage()` so the window stays responsive and keyboard input works without a console. On DOS, it uses `conio getch()`/`kbhit()`.
`escPressed()` on Windows uses `GetAsyncKeyState(VK_ESCAPE)` (no message queue); on DOS it
falls back to `keyPressed() && readKey() == KEY_ESC`.

## Hot-Path Optimisation

`putPixelFast(x, y, c)` / `getPixelFast(x, y)` are macros that expand to a direct
framebuffer write with bounds clamping.  The standard `putPixel`/`getPixel` inline
functions remain available and include bounds checks.

Build with `BUILD.BAT BCC DEBUG=1` to add debug symbols (`-v` / `-g` / `/Zi`).
Without `DEBUG`, `check()` is still always active (not a toggle).
