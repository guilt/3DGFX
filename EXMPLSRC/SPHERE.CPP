// Draws a Sphere With Spherical Co-Ordinates.

#include <conio.h>
#include <mathren.h>

int main()
{
    double ro, o, p, orad, pr, asp = 1.2;
    point3d p1;
    graini();
    clearviewport();
    ro = 8;
    for (o = 0; o <= 360; o++)
    {
        orad = rad(o);
        for (p = 0; p <= 180; p++)
        {
            pr = rad(p);
            p1.y = ro * cos(pr);
            p1.z = ro * sin(pr) * sin(orad);
            p1.x = asp * ro * sin(pr) * cos(orad);
            sconplot(p1, 14, o, p);
        }
    }
    drawaxis(1);
    getch();
    graclo();
    return 0;
}