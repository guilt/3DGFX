// User Interactive Triangle Rotation and Revolution.

// Notice that when one of the Vertices is the Origin, Revolution changes
// to Rotation. But anyway, to Rotate a triangle, none of the vertices
// being the Origin, fix a point, such as the Vertex/Centroid as the Origin
// and proceed.

// Press x/y/z to choose the axis (default z). Press Up/Down to move
// in Counterclockwise, along that axis. Press Escape to Quit.

// Keys to Press:
// x / y / z: Axis (Default is z)
// Up / Down: to Move Counterclockwise on Axis
//       Esc: to Quit


#include <INPUT.H>
#include <PIXEL.H>
#include <RENDER.H>

int main()
{
    int key;
    int selectedAxis = 2;
    int rotationX = 0, rotationY = 0, rotationZ = 0;
    Triangle3d triangleOriginal1, triangleWorking1, triangleOriginal2, triangleWorking2;
    triangleOriginal1.p1.x = 0, triangleOriginal1.p1.y = 0, triangleOriginal1.p1.z = 0;
    triangleOriginal1.p2.x = 0, triangleOriginal1.p2.y = 0, triangleOriginal1.p2.z = 5;
    triangleOriginal1.p3.x = 5, triangleOriginal1.p3.y = 0, triangleOriginal1.p3.z = 0;
    triangleOriginal2.p1.x = 10, triangleOriginal2.p1.y = 10, triangleOriginal2.p1.z = 10;
    triangleOriginal2.p2.x = 10, triangleOriginal2.p2.y = 10, triangleOriginal2.p2.z = 15;
    triangleOriginal2.p3.x = 15, triangleOriginal2.p3.y = 10, triangleOriginal2.p3.z = 10;
    graphicsInitialize();
    initializeRGBPalette();
    graphicsClear();
    triangleWorking1 = triangleOriginal1;
    triangleWorking2 = triangleOriginal2;
    do
    {
        drawAxis(LIGHTBLUE);
        drawTriangle(triangleWorking1, RED);
        drawTriangle(triangleWorking2, GREEN);
        graphicsUpdate();
        key = readKey();
        if (key == KEY_X)
        {
            selectedAxis = 0;
        }
        if (key == KEY_Y)
        {
            selectedAxis = 1;
        }
        if (key == KEY_Z)
        {
            selectedAxis = 2;
        }
        if (key == KEY_UP)
        {
            if (selectedAxis == 0)
            {
                rotationX += 10;
            }
            if (selectedAxis == 1)
            {
                rotationY += 10;
            }
            if (selectedAxis == 2)
            {
                rotationZ += 10;
            }
        }
        if (key == KEY_DOWN)
        {
            if (selectedAxis == 0)
            {
                rotationX -= 10;
            }
            if (selectedAxis == 1)
            {
                rotationY -= 10;
            }
            if (selectedAxis == 2)
            {
                rotationZ -= 10;
            }
        }
        drawTriangle(triangleWorking1, BLACK);
        drawTriangle(triangleWorking2, BLACK);
        drawAxis(BLACK);
        triangleWorking1 = triangleOriginal1;
        triangleWorking2 = triangleOriginal2;
        rotateTriangle(triangleWorking1, rotationX, rotationY, rotationZ);
        rotateTriangle(triangleWorking2, rotationX, rotationY, rotationZ);
    } while (key != KEY_ESC);
    graphicsClose();
    return 0;
}