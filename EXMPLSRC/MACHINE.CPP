// Machine Simulation.

// Keys to Press:
//        1 Auxiliary Arm
//        2 Primary Arm
//        3 Moving Rod (By Default)
//        4 Base
//  Up/Down to Move
//      Esc to Quit

#include <conio.h>
#include <mathren.h>

int main()
{
    /*
    Array Index :
    Base 0
    Primary Arm 1
    Auxilliary Arm 2
    Moving Rod 3
    */
    char c, d;
    int flag = 2, armauxdeg = 0, bdeg = 0;
    double levermovt = 0, basemovt = 0;
    object* o = new object[4];
    if (!o)
    {
        return 1;
    }
    graini();
    readobj("base.msh", o[0]);
    readobj("armb.msh", o[1]);
    readobj("lever.msh", o[2]);
    readobj("armaux.msh", o[3]);
    do
    {
        drawobj(o[0], 1);
        drawobj(o[1], 2);
        drawobj(o[3], 3);
        drawobj(o[2], 4);
        c = getch();
        if (c == '1')
        {
            flag = 0;
        }
        if (c == '2')
        {
            flag = 1;
        }
        if (c == '3')
        {
            flag = 2;
        }
        if (c == '4')
        {
            flag = 3;
        }
        if (c == 0)
        {
            d = getch();
        }
        drawobj(o[0], 0);
        drawobj(o[1], 0);
        drawobj(o[3], 0);
        drawobj(o[2], 0);
        if (d == 72)
        {
            if (flag == 0)
            {
                if (armauxdeg < 9)
                {
                    aorot(o[2], 0, 10, 0);
                    aorot(o[3], 0, 10, 0);
                    armauxdeg++;
                }
            }
            if (flag == 1)
            {
                if (bdeg < 9)
                {
                    aorot(o[1], 0, 10, 0);
                    aorot(o[2], 0, 10, 0);
                    aorot(o[3], 0, 10, 0);
                    bdeg++;
                }
            }
            if (flag == 2)
            {
                if (levermovt < 2)
                {
                    aotrans(o[2], 0, 2, 0);
                    levermovt++;
                }
            }
            if (flag == 3)
            {
                if (basemovt < 4)
                {
                    aotrans(o[0], 2, 0, 0);
                    basemovt++;
                }
            }
        }
        if (d == 80)
        {
            if (flag == 0)
            {
                if (armauxdeg > -9)
                {
                    aorot(o[2], 0, -10, 0);
                    aorot(o[3], 0, -10, 0);
                    armauxdeg--;
                }
            }
            if (flag == 1)
            {
                if (bdeg > -9)
                {
                    aorot(o[1], 0, -10, 0);
                    aorot(o[2], 0, -10, 0);
                    aorot(o[3], 0, -10, 0);
                    bdeg--;
                }
            }
            if (flag == 2)
            {
                if (levermovt > -2)
                {
                    aotrans(o[2], 0, -2, 0);
                    levermovt--;
                }
            }
            if (flag == 3)
            {
                if (basemovt > -4)
                {
                    aotrans(o[0], -2, 0, 0);
                    basemovt--;
                }
            }
        }
        d = -1;
    } while (c != 27);
    graclo();
    return 0;
}