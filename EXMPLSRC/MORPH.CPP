// Morphing between two Pictures.

#include <INPUT.H>
#include <IMAGE.H>

#define MORPH_STEPS 80

void morph(int offsetX, int offsetY, image& image1, byte palette1[768], image& image2,
           byte palette2[768], bool& appQuit)
{
    int row, col, step, height1, width1, height2, width2, minHeight, minWidth,
        colorIndex1, colorIndex2, red1, green1, blue1, red2, green2, blue2,
        redResult, greenResult, blueResult;
    height1 = image1.height(), width1 = image1.width();
    height2 = image2.height(), width2 = image2.width();
    minHeight = height1 < height2 ? height1 : height2;
    minWidth = width1 < width2 ? width1 : width2;
    for (row = 0; row < minHeight; row++)
        for (col = 0; col < minWidth; col++)
            putPixel(offsetX + col, offsetY + row, 0);

    for (step = 0; step <= MORPH_STEPS; step++)
    {
        for (row = 0; row < minHeight; row++)
            for (col = 0; col < minWidth; col++)
            {
                colorIndex1 = image1.getPixel(col, row);
                colorIndex2 = image2.getPixel(col, row);
                red1   = palette1[(colorIndex1 * 3)];
                green1 = palette1[(colorIndex1 * 3) + 1];
                blue1  = palette1[(colorIndex1 * 3) + 2];
                red2   = palette2[(colorIndex2 * 3)];
                green2 = palette2[(colorIndex2 * 3) + 1];
                blue2  = palette2[(colorIndex2 * 3) + 2];
                redResult   = ((red1   * (MORPH_STEPS - step)) + (red2   * step)) / MORPH_STEPS;
                greenResult = ((green1 * (MORPH_STEPS - step)) + (green2 * step)) / MORPH_STEPS;
                blueResult  = ((blue1  * (MORPH_STEPS - step)) + (blue2  * step)) / MORPH_STEPS;
                putPixelRGB(offsetX + col, offsetY + row, redResult, greenResult, blueResult);
            }
        graphicsUpdate();
        graphicsDelay(20);
        pollKeyboard();
        if (escPressed()) { appQuit = true; break; }
    }
}

int main()
{
    image image1, image2;
    byte palette1[768], palette2[768];
    // Cheetah and The Suzuki.
    image1.load("cheetah.im", 196);
    readPaletteFile("cheetah.pal", palette1);
    image2.load("suzuki.im");
    readPaletteFile("suzuki.pal", palette2);
    graphicsInitialize();
    initializeRGBPalette(rgbPalette);
    graphicsClear();
    {
        bool appQuit = false;
        while (1)
        {
            if (!appQuit) morph(110, 30, image1, palette1, image2, palette2, appQuit);
            if (!appQuit) morph(110, 30, image2, palette2, image1, palette1, appQuit);
            if (appQuit) break;
        }
    }
    graphicsClose();
    return 0;
}