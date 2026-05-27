// Planes and Bitmap Sizing Demo.

#include <INPUT.H>
#include <BITMAP.H>
#include <RENDER.H>

int main()
{
    int texelX, texelY;
    Point3d point;
    int pixelColor;
    Bitmap bitmap;
    int halfWidth;
    int halfHeight;
    double compressionFactor = 2;
    loadBitmapInto("demog.bmp", bitmap);
    halfWidth = bitmap.h.width / 2;
    halfHeight = bitmap.h.height / 2;
    graphicsInitialize();
    initBitmap(bitmap);
    graphicsClear();
    for (texelX = -1 * halfWidth; texelX < halfWidth; texelX++)
    {
        point.x = texelX / (xScale * compressionFactor);
        for (texelY = -1 * halfHeight; texelY < halfHeight; texelY++)
        {
            point.y = texelY / (yScale * compressionFactor);
            point.z = 0;
            pixelColor = bitmap.data[(((texelY + halfHeight) % bitmap.h.height) * bitmap.h.width + ((texelX + halfWidth) % bitmap.h.width))];
            drawPoint(point, pixelColor);
        }
    }
    graphicsUpdate();
    waitForKey();
    graphicsClear();
    for (texelX = -1 * halfWidth; texelX < halfWidth; texelX++)
    {
        point.z = texelX / (zScale * compressionFactor);
        for (texelY = -1 * halfHeight; texelY < halfHeight; texelY++)
        {
            point.x = texelY / (xScale * compressionFactor);
            point.y = 0;
            pixelColor = bitmap.data[(((texelY + halfHeight) % bitmap.h.height) * bitmap.h.width + ((texelX + halfWidth) % bitmap.h.width))];
            drawPoint(point, pixelColor);
        }
    }
    graphicsUpdate();
    waitForKey();
    graphicsClear();
    for (texelX = -1 * halfWidth; texelX < halfWidth; texelX++)
    {
        point.y = texelX / (yScale * compressionFactor);
        for (texelY = -1 * halfHeight; texelY < halfHeight; texelY++)
        {
            point.z = texelY / (zScale * compressionFactor);
            point.x = 0;
            pixelColor = bitmap.data[(((texelY + halfHeight) % bitmap.h.height) * bitmap.h.width + ((texelX + halfWidth) % bitmap.h.width))];
            drawPoint(point, pixelColor);
        }
    }
    graphicsUpdate();
    waitForKey();
    graphicsClose();
    return 0;
}
