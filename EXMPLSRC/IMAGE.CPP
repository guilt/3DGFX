// Easy Image Demo.

#include <conio.h>
#include <defs.h>
#include <image.h>
#include <fonts.h>

int main()
{
    image i("odie.im");
    graini();
    loadfilepalette();
    i.draw(0, 0);
    drawstring("Odie!", 180, 66, 4, 0, 2);
    getch();
    setbwpal(); // Watch the Fun!
    getch();
    graclo();
    return 0;
}
