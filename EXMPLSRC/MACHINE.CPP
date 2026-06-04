// Machine Simulation.

// Keys to Press:
//        1 Auxiliary Arm
//        2 Primary Arm
//        3 Moving Rod (By Default)
//        4 Base
//  Up/Down to Move
//      Esc to Quit

#include <INPUT.H>
#include <PIXEL.H>
#include <RENDER.H>

int main()
{
    /*
    Array Index:
    Base 0
    Primary Arm 1
    Auxilliary Arm 2
    Moving Rod 3
    */
    int key;
    int selectedPart = 2, auxiliaryAngle = 0, primaryAngle = 0;
    double leverOffset = 0, baseOffset = 0;
    Object3d* parts = new Object3d[4];
    if (!parts)
    {
        return 1;
    }
    graphicsInitialize();
    initializeRGBPalette();
    readObject("base.msh", parts[0]);
    readObject("armb.msh", parts[1]);
    readObject("lever.msh", parts[2]);
    readObject("armaux.msh", parts[3]);
    do
    {
        drawObject(parts[0], 1);
        drawObject(parts[1], 2);
        drawObject(parts[3], 3);
        drawObject(parts[2], 4);
        graphicsUpdate();
        key = readKey();
        if (key == KEY_1)
        {
            selectedPart = 0;
        }
        if (key == KEY_2)
        {
            selectedPart = 1;
        }
        if (key == KEY_3)
        {
            selectedPart = 2;
        }
        if (key == KEY_4)
        {
            selectedPart = 3;
        }
        drawObject(parts[0], 0);
        drawObject(parts[1], 0);
        drawObject(parts[3], 0);
        drawObject(parts[2], 0);
        if (key == KEY_UP)
        {
            if (selectedPart == 0)
            {
                if (auxiliaryAngle < 9)
                {
                    objectRotate(parts[2], 0, 10, 0);
                    objectRotate(parts[3], 0, 10, 0);
                    auxiliaryAngle++;
                }
            }
            if (selectedPart == 1)
            {
                if (primaryAngle < 9)
                {
                    objectRotate(parts[1], 0, 10, 0);
                    objectRotate(parts[2], 0, 10, 0);
                    objectRotate(parts[3], 0, 10, 0);
                    primaryAngle++;
                }
            }
            if (selectedPart == 2)
            {
                if (leverOffset < 2)
                {
                    objectTranslate(parts[2], 0, 2, 0);
                    leverOffset++;
                }
            }
            if (selectedPart == 3)
            {
                if (baseOffset < 4)
                {
                    objectTranslate(parts[0], 2, 0, 0);
                    baseOffset++;
                }
            }
        }
        if (key == KEY_DOWN)
        {
            if (selectedPart == 0)
            {
                if (auxiliaryAngle > -9)
                {
                    objectRotate(parts[2], 0, -10, 0);
                    objectRotate(parts[3], 0, -10, 0);
                    auxiliaryAngle--;
                }
            }
            if (selectedPart == 1)
            {
                if (primaryAngle > -9)
                {
                    objectRotate(parts[1], 0, -10, 0);
                    objectRotate(parts[2], 0, -10, 0);
                    objectRotate(parts[3], 0, -10, 0);
                    primaryAngle--;
                }
            }
            if (selectedPart == 2)
            {
                if (leverOffset > -2)
                {
                    objectTranslate(parts[2], 0, -2, 0);
                    leverOffset--;
                }
            }
            if (selectedPart == 3)
            {
                if (baseOffset > -4)
                {
                    objectTranslate(parts[0], -2, 0, 0);
                    baseOffset--;
                }
            }
        };
    } while (key != KEY_ESC);
    graphicsClose();
    return 0;
}