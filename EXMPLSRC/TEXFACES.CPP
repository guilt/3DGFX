// Surfaces with Textures on them....

#include <INPUT.H>
#include <BITMAP.H>
#include <PIXEL.H>
#include <RENDER.H>

int main()
{
    int texelX, texelY;
    Point3d point;
    int pixelColor;
    Bitmap bitmap;
    int halfWidth;
    int halfHeight;
    int zCompression = 4;
    int xCompression = 1;
    loadBitmapInto("intex.bmp", bitmap);
    halfWidth = bitmap.h.width / 2;
    halfHeight = bitmap.h.height / 2;
    graphicsInitialize();
    initializeRGBPalette();
    graphicsClear();
    for (texelX = -1 * halfWidth; texelX < halfWidth; texelX++)
    {
        point.z = texelX / (zScale * zCompression);
        for (texelY = -1 * halfHeight; texelY < halfHeight; texelY++)
        {
            point.x = texelY / (xScale * xCompression);
            pixelColor = bitmap.data[(((texelY + halfHeight) % bitmap.h.height) * bitmap.h.width + ((texelX + halfWidth) % bitmap.h.width))];
            point.y = 0.015 * (-1 * (point.z * point.z) + (point.x * point.x));
            drawPoint(point, pixelColor);
        }
    }
    graphicsUpdate();
    waitForKey();
    graphicsClose();
    return 0;
}
