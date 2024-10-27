// Gun-Bullet Mesh Demo.

#include <conio.h>
#include <mathren.h>

int main()
{
    int i, j;
    object gun, gunOg, bullet, bulletOg;

    graini();
    clearviewport();

    readobj("GUN.MSH", gunOg);
    readobj("BULLET.MSH", bulletOg);

    gun = gunOg;
    bullet = bulletOg;

    for (j = 0; j <= 37; j++)
    {
        for (i = 0; i < 5; i++)
        {
            drawobj(gun, 7);
            drawobj(bullet, 15);
            delay(5);
            drawobj(gun, 0);
            aorot(gun, 0, 0, 7);
            drawobj(gun, 7);
            delay(5);
            drawobj(gun, 0);
            aorot(gun, 0, 0, -7);
            drawobj(gun, 7);
            delay(5);
            drawobj(gun, 0);
            drawobj(bullet, 0);
            bullet = bulletOg;
            aotrans(bullet, (i * 20), 0, 0);
            aorot(bullet, 0, (10 * j), 0);
        }
        gun = gunOg;
        aorot(gun, 0, (10 * j), 0);
    }

    drawobj(gun, 7);
    drawobj(bullet, 15);
    (void) getch();

    graclo();
    return 0;
}