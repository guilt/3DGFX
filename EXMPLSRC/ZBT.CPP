// Textured Z-Buffered Object Demo .

// Keys to Press:
// x / y / z  : Axis (Default is z)
// Left/Right : to Move Counterclockwise on Axis
//        Esc :  to Quit

#define IHSR
#define IZBUF
#define IZCLIP

#include <conio.h>
#include <tmathren.h>

int main()
{
    char c, d;
    int flag = 2; // Default Z
    int v = 1, rot = 10;
    tobject o, o1;
    mkzbuf();
    readtobj("texo1.msh", o); // Load The Objects .... !
    readtobj("texo2.msh", o1);
    graini();
    loadtex("tex.tex"); // Load Common Textures .... !
    rinittex();
    atotrans(o1, 14, 14, 14);
    do
    {
        clearviewport();
        clrzbuf();
        drawtobj(o);
        drawtobj(o1);
        c = getch();
        if (c == 'x')
        {
            flag = 0;
        }
        if (c == 'y')
        {
            flag = 1;
        }
        if (c == 'z')
        {
            flag = 2;
        }
        if (c == 0)
        {
            d = getch();
        }
        if (d == 75)
        {
            v = 1;
            if (flag == 0)
            {
                atorot(o, v * rot, 0, 0);
                atorot(o1, v * rot, 0, 0);
            }
            if (flag == 1)
            {
                atorot(o, 0, v * rot, 0);
                atorot(o1, 0, v * rot, 0);
            }
            if (flag == 2)
            {
                atorot(o, 0, 0, v * rot);
                atorot(o1, 0, 0, v * rot);
            }
        }
        if (d == 77)
        {
            v = -1;
            if (flag == 0)
            {
                atorot(o, v * rot, 0, 0);
                atorot(o1, v * rot, 0, 0);
            }
            if (flag == 1)
            {
                atorot(o, 0, v * rot, 0);
                atorot(o1, 0, v * rot, 0);
            }
            if (flag == 2)
            {
                atorot(o, 0, 0, v * rot);
                atorot(o1, 0, 0, v * rot);
            }
        }
        d = -1;
    } while (c != 27);
    rmzbuf();
    graclo();
    return 0;
}