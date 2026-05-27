// Draws a Sphere With Spherical Co-Ordinates.

#include <INPUT.H>
#include <RENDER.H>

int main()
{
    double radius, thetaAngle, phiAngle, thetaRadians, phiRadians, aspectRatio = 1.2;
    Point3d point;
    graphicsInitialize();
    graphicsClear();
    radius = 8;
    for (thetaAngle = 0; thetaAngle <= 360; thetaAngle++)
    {
        thetaRadians = degToRad(thetaAngle);
        for (phiAngle = 0; phiAngle <= 180; phiAngle++)
        {
            phiRadians = degToRad(phiAngle);
            point.y = radius * cos(phiRadians);
            point.z = radius * sin(phiRadians) * sin(thetaRadians);
            point.x = aspectRatio * radius * sin(phiRadians) * cos(thetaRadians);
            sphContourPlot(point, 14, thetaAngle, phiAngle);
        }
    }
    drawAxis(1);
    graphicsUpdate();
    waitForKey();
    graphicsClose();
    return 0;
}