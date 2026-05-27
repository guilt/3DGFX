// Textured Z-Buffered Object Demo.

// Keys to Press:
// x / y / z: Axis (Default is z)
// Left/Right: to Move Counterclockwise on Axis
//        Esc: to Quit

#define IHSR
#define IZBUF
#define IZCLIP

#include <INPUT.H>
#include <RENDER.H>

int main()
{
    int key;
    int selectedAxis = 2;
    int direction = 1, rotationIncrement = 10;
    TexturedObject object1, object2;
    zBufferCreate();
    loadTexturedObjectInto("texo1.msh", object1);
    loadTexturedObjectInto("texo2.msh", object2);
    graphicsInitialize();
    loadTextures("tex.tex");
    loadUsedTextures(object1);
    loadUsedTextures(object2);
    objectTranslate(object2, 14, 14, 14);
    do
    {
        graphicsClear();
        zBufferClear();
        drawTexturedObject(object1);
        drawTexturedObject(object2);
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
        if (key == KEY_LEFT)
        {
            direction = 1;
            if (selectedAxis == 0)
            {
                objectRotate(object1, direction * rotationIncrement, 0, 0);
                objectRotate(object2, direction * rotationIncrement, 0, 0);
            }
            if (selectedAxis == 1)
            {
                objectRotate(object1, 0, direction * rotationIncrement, 0);
                objectRotate(object2, 0, direction * rotationIncrement, 0);
            }
            if (selectedAxis == 2)
            {
                objectRotate(object1, 0, 0, direction * rotationIncrement);
                objectRotate(object2, 0, 0, direction * rotationIncrement);
            }
        }
        if (key == KEY_RIGHT)
        {
            direction = -1;
            if (selectedAxis == 0)
            {
                objectRotate(object1, direction * rotationIncrement, 0, 0);
                objectRotate(object2, direction * rotationIncrement, 0, 0);
            }
            if (selectedAxis == 1)
            {
                objectRotate(object1, 0, direction * rotationIncrement, 0);
                objectRotate(object2, 0, direction * rotationIncrement, 0);
            }
            if (selectedAxis == 2)
            {
                objectRotate(object1, 0, 0, direction * rotationIncrement);
                objectRotate(object2, 0, 0, direction * rotationIncrement);
            }
        }
    } while (key != KEY_ESC);
    zBufferDestroy();
    graphicsClose();
    return 0;
}