// Gun-Bullet Mesh Demo.

#include <INPUT.H>
#include <PIXEL.H>
#include <RENDER.H>

int main()
{
    int bulletStep, angleStep;
    Object3d gun, gunOriginal, bullet, bulletOriginal;

    graphicsInitialize();
    initializeRGBPalette();
    graphicsClear();

    readObject("GUN.MSH", gunOriginal);
    readObject("BULLET.MSH", bulletOriginal);

    gun = gunOriginal;
    bullet = bulletOriginal;

    for (angleStep = 0; angleStep <= 37; angleStep++)
    {
        for (bulletStep = 0; bulletStep < 5; bulletStep++)
        {
            drawObject(gun, 7);
            drawObject(bullet, 15);
            graphicsUpdate();
            delay(5);
            drawObject(gun, 0);
            objectRotate(gun, 0, 0, 7);
            drawObject(gun, 7);
            graphicsUpdate();
            delay(5);
            drawObject(gun, 0);
            objectRotate(gun, 0, 0, -7);
            drawObject(gun, 7);
            graphicsUpdate();
            delay(5);
            drawObject(gun, 0);
            drawObject(bullet, 0);
            bullet = bulletOriginal;
            objectTranslate(bullet, (bulletStep * 20), 0, 0);
            objectRotate(bullet, 0, (10 * angleStep), 0);
        }
        gun = gunOriginal;
        objectRotate(gun, 0, (10 * angleStep), 0);
    }

    drawObject(gun, 7);
    drawObject(bullet, 15);
    waitForKey();

    graphicsClose();
    return 0;
}