// Unicode scrolling greetings demo -- 8 diverse scripts, no tofu

#include <INPUT.H>    // before TYPES.H so conio.h COLOR enum compiles before macros

#define WANT_FTARK_SELECT
#define WANT_FTARK_00   // Basic Latin
#define WANT_FTARK_01   // Latin-1 Supplement
#define WANT_FTARK_02   // Latin-1 Extended (accents)
#define WANT_FTARK_03   // Latin Extended-A
#include <FTARK.H>

#define WANT_FTUNI_SELECT
#define WANT_FTUNI_05   // Hebrew
#define WANT_FTUNI_06   // Arabic
#define WANT_FTUNI_09   // Devanagari, Bengali
#define WANT_FTUNI_11   // Tamil
#define WANT_FTUNI_14   // Thai
#include <FTUNI.H>

static const struct FontDesc *_fontChain[] = { &_fArk, &_fFTUNI };
#define FONT_CHAIN_COUNT 2
#define CUSTOM_FONT_CHAIN

#include <FONTS.H>
#include <string.h>

static const struct { const char *lang; const char *text; int rtl; } greetings[] = {
    {"English", "Hello!  Good Morning!"},
    {"Spanish", "\302\241Hola!  Buenos d\303\255as!"},
    {"Arabic", "\330\247\331\204\330\263\331\204\330\247\331\205 \330\271\331\204\331\212\331\203\331\205", 1},
    {"Hindi", "\340\244\250\340\244\256\340\244\270\340\245\215\340\244\244\340\245\207"},
    {"Hebrew", "\327\251\327\234\327\225\327\235", 1},
    {"Tamil", "\340\256\265\340\256\243\340\256\225\340\257\215\340\256\225\340\256\256\340\257\215"},
    {"Thai", "\340\270\252\340\270\247\340\270\261\340\270\252\340\270\224\340\270\265"},
    {"Bengali", "\340\246\250\340\246\256\340\246\270\340\247\215\340\246\225\340\246\276\340\246\260"},
};

#define N (sizeof(greetings) / sizeof(greetings[0]))

struct Tracer { int x, y, greetIdx, speed, spawnFrames, totalWidth, greetScale; };

int main()
{
    int frame = 0, i;
    const int gap = 20, nTracers = 6;
    const int slotY[6] = { 8, 38, 68, 98, 128, 158 };
    const int colors[6] = {
        COLOR_RED, COLOR_ORANGE_RED, COLOR_GOLD,
        COLOR_LIME_GREEN, COLOR_DODGER_BLUE, COLOR_HOT_PINK,
    };
    struct Tracer tracers[6];

    graphicsInitialize();
    initializeRGBPalette();

    for (i = 0; i < nTracers; i++) {
        tracers[i].x = 400 + i * 100;
        tracers[i].y = slotY[i];
        tracers[i].greetIdx = rand() % (int)N;
        tracers[i].speed = 3 + rand() % 3;
        tracers[i].spawnFrames = i * 30;
        tracers[i].greetScale = 1 + rand() % 3;
        tracers[i].totalWidth = 0;
    }

    while (!escPressed())
    {
        graphicsClear();

        for (i = 0; i < nTracers; i++) {
            if (frame < tracers[i].spawnFrames) continue;

            int sc = tracers[i].greetScale;
            int labelSize = sc * 2;

            if (tracers[i].totalWidth == 0) {
                int greetWidth = textWidth(greetings[tracers[i].greetIdx].text, sc);
                int labelWidth = ((int)strlen(greetings[tracers[i].greetIdx].lang) + 2) * 8 * labelSize;
                tracers[i].totalWidth = greetWidth + gap + labelWidth;
            }

            if (tracers[i].x < -tracers[i].totalWidth) {
                tracers[i].greetIdx = rand() % (int)N;
                tracers[i].x = 320 + rand() % 40;
                tracers[i].speed = 3 + rand() % 3;
                tracers[i].greetScale = 1 + rand() % 3;
                tracers[i].totalWidth = 0;
            }

            int color = colors[i];
            char labelBuf[32];
            sprintf(labelBuf, "[%s]", greetings[tracers[i].greetIdx].lang);
            drawStringWithSize(labelBuf, tracers[i].x, tracers[i].y, color, labelSize);
            int labelWidth = ((int)strlen(greetings[tracers[i].greetIdx].lang) + 2) * 8 * labelSize;
            drawStringScaled(greetings[tracers[i].greetIdx].text, tracers[i].x + labelWidth + gap, tracers[i].y, color, sc);
            tracers[i].x -= tracers[i].speed;
        }

        graphicsUpdate();
        graphicsDelay(16);
        frame++;
    }

    graphicsClose();
    return 0;
}
