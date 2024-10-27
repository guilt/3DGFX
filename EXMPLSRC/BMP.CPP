// Simple Bitmap Demo.

#include <conio.h>
#include <stdio.h>
#include <bmp.h>

int main()
{
    bitmap* b = new bitmap;
    graini();
    printf("SwordFish");
    loadbmp("kdemo1.bmp", *b);
    drawbmp(*b, 0, 10);
    loadbmp("kdemo2.bmp", *b);
    drawbmp(*b, 95, 40);
    loadbmp("kdemo3.bmp", *b);
    drawbmp(*b, 190, 70);
    getch();
    graclo();
    return 0;
}
