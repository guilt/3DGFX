// Easy Image Demo.

#include <INPUT.H>
#include <IMAGE.H>
#include <FONTS.H>

int main()
{
    image i("odie.im");
    graphicsInitialize();
    setPaletteFromFile(DEFAULT_PAL);
    i.draw(0, 0);
    drawStringWithSize("Odie!", 180, 66, 4, 2);
    graphicsUpdate();
    waitForKey();
    setBwPalette(); // Watch the Fun!
    graphicsUpdate();
    waitForKey();
    graphicsClose();
    return 0;
}
