// 3D Graphs with Normal Contours.

#include <INPUT.H>
#include <PIXEL.H>
#include <RENDER.H>

int main()
{
    double xPos, zPos;
    Point3d point;
    graphicsInitialize();
    initializeRGBPalette();
    graphicsClear();
    for (xPos = -8; xPos <= 8; xPos += 0.01)
    {
        point.x = xPos;
        for (zPos = -8; zPos <= 8; zPos += 0.01)
        {
            point.z = zPos;

            // Choose from among any equation Below.

            // point.y=((point.z*point.x)*((point.x*point.x)-(point.z*point.z))/((point.x*point.x)+(point.z*point.z)));

            // point.y=0.1*(point.z*point.z)-0.5*(point.x*point.x);

            point.y = 0.3 * (point.z * point.z) + 0.3 * (point.x * point.x);

            // point.y=(point.x*point.z)/((point.z*point.z)+(point.x*point.x))*20;

            // point.y=(((point.x*point.x)+1)/((point.z*point.z)+1))*0.4;

            contourPlot(point, 14);
        }
    }
    drawAxis(1);
    graphicsUpdate();
    waitForKey();
    graphicsClose();
    return 0;
}