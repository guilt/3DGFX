// Simple Bitmap Demo.

#include <INPUT.H>
#include <BITMAP.H>
#include <FONTS.H>

int main()
{
    Bitmap* bitmap = new Bitmap;
    graphicsInitialize();
    loadBitmapInto("kdemo1.bmp", *bitmap);
    drawBitmap(*bitmap, 0, 10);
    loadBitmapInto("kdemo2.bmp", *bitmap);
    drawBitmap(*bitmap, 95, 40);
    loadBitmapInto("kdemo3.bmp", *bitmap);
    drawBitmap(*bitmap, 190, 70);
    drawString("SwordFish", 5, 185, RGBToIndexed(255, 255, 255), 1);
    graphicsUpdate();
    waitForKey();
    graphicsClose();
    return 0;
}
