// INPUT.H - Keyboard input abstraction.
// Windows GDI : reads keys via GetMessage/PeekMessage.
// DOS          : uses conio getch/kbhit.
//
// Key encoding: ASCII for letters/numbers, KEY_ESC = 27,
// KEY_UP = 256 for arrows, function keys, etc.
//
// No dependency on CANVAS.H - standalone header.

#ifndef INPUT_H
#define INPUT_H

#include <PLATFORM.H>
#include <TYPES.H>

// ------------------------------------------------------------------
//  Key constants
// ------------------------------------------------------------------

// Platform-specific scan codes (normalised to KEY_* at the boundary)
#define SCAN_UP      72
#define SCAN_DOWN    80
#define SCAN_LEFT    75
#define SCAN_RIGHT   77
#define SCAN_HOME    71
#define SCAN_END     79
#define SCAN_PGUP    73
#define SCAN_PGDN    81
#define SCAN_INSERT  82
#define SCAN_DELETE  83
#define SCAN_F1      59
#define SCAN_F2      60
#define SCAN_F3      61
#define SCAN_F4      62
#define SCAN_F5      63
#define SCAN_F6      64
#define SCAN_F7      65
#define SCAN_F8      66
#define SCAN_F9      67
#define SCAN_F10     68

#define KEY_BACKSPACE  8
#define KEY_TAB        9
#define KEY_ENTER     13
#define KEY_ESC       27
#define KEY_SPACE     32
#define KEY_DELETE   127

#define KEY_UP      256
#define KEY_DOWN    257
#define KEY_LEFT    258
#define KEY_RIGHT   259
#define KEY_HOME    260
#define KEY_END     261
#define KEY_PGUP    262
#define KEY_PGDN    263
#define KEY_INSERT  264
#define KEY_F1      265
#define KEY_F2      266
#define KEY_F3      267
#define KEY_F4      268
#define KEY_F5      269
#define KEY_F6      270
#define KEY_F7      271
#define KEY_F8      272
#define KEY_F9      273
#define KEY_F10     274

#define KEY_A  'A'
#define KEY_B  'B'
#define KEY_C  'C'
#define KEY_D  'D'
#define KEY_E  'E'
#define KEY_F  'F'
#define KEY_G  'G'
#define KEY_H  'H'
#define KEY_I  'I'
#define KEY_J  'J'
#define KEY_K  'K'
#define KEY_L  'L'
#define KEY_M  'M'
#define KEY_N  'N'
#define KEY_O  'O'
#define KEY_P  'P'
#define KEY_Q  'Q'
#define KEY_R  'R'
#define KEY_S  'S'
#define KEY_T  'T'
#define KEY_U  'U'
#define KEY_V  'V'
#define KEY_W  'W'
#define KEY_X  'X'
#define KEY_Y  'Y'
#define KEY_Z  'Z'
#define KEY_0  '0'
#define KEY_1  '1'
#define KEY_2  '2'
#define KEY_3  '3'
#define KEY_4  '4'
#define KEY_5  '5'
#define KEY_6  '6'
#define KEY_7  '7'
#define KEY_8  '8'
#define KEY_9  '9'

// ------------------------------------------------------------------
//  readKey - block until a key is pressed, return KEY_ code
// ------------------------------------------------------------------

static int readKey()
{
#if defined(PLATFORM_WINDOWS)
    MSG msg;
    while (true)
    {
        BOOL ret = GetMessage(&msg, NULL, 0, 0);
        if (ret <= 0) return KEY_ESC;

        if (msg.message == WM_CHAR)
        {
            int k = (int)msg.wParam;
            if (k >= 32 && k < 256)
            {
                TranslateMessage(&msg);
                DispatchMessage(&msg);
                return k;
            }
        }

        if (msg.message == WM_KEYDOWN)
        {
            int k = 0;
            switch (msg.wParam)
            {
                case VK_ESCAPE: k = KEY_ESC;   break;
                case VK_UP:     k = KEY_UP;    break;
                case VK_DOWN:   k = KEY_DOWN;  break;
                case VK_LEFT:   k = KEY_LEFT;  break;
                case VK_RIGHT:  k = KEY_RIGHT; break;
                case VK_HOME:   k = KEY_HOME;  break;
                case VK_END:    k = KEY_END;   break;
                case VK_PRIOR:  k = KEY_PGUP;  break;
                case VK_NEXT:   k = KEY_PGDN;  break;
                case VK_INSERT: k = KEY_INSERT; break;
                case VK_DELETE: k = KEY_DELETE; break;
                case VK_F1:  case VK_F2:  case VK_F3:  case VK_F4:
                case VK_F5:  case VK_F6:  case VK_F7:  case VK_F8:
                case VK_F9:  case VK_F10:
                    k = KEY_F1 + ((int)msg.wParam - VK_F1);
                    break;
                case VK_RETURN: k = KEY_ENTER;    break;
                case VK_BACK:   k = KEY_BACKSPACE; break;
                case VK_TAB:    k = KEY_TAB;      break;
                case VK_SPACE:  k = KEY_SPACE;    break;
            }
            if (k)
            {
                TranslateMessage(&msg);
                DispatchMessage(&msg);
                return k;
            }
        }

        if (msg.message == WM_CLOSE) return KEY_ESC;

        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
#else
    int ch = getch();
    if (ch == 0 || ch == 0xE0)
    {
        ch = getch();
        switch (ch)
        {
            case SCAN_UP:    return KEY_UP;    case SCAN_DOWN:   return KEY_DOWN;
            case SCAN_LEFT:  return KEY_LEFT;  case SCAN_RIGHT:  return KEY_RIGHT;
            case SCAN_HOME:  return KEY_HOME;  case SCAN_END:    return KEY_END;
            case SCAN_PGUP:  return KEY_PGUP;  case SCAN_PGDN:   return KEY_PGDN;
            case SCAN_INSERT:return KEY_INSERT; case SCAN_DELETE: return KEY_DELETE;
            case SCAN_F1:    return KEY_F1;    case SCAN_F2:     return KEY_F2;
            case SCAN_F3:    return KEY_F3;    case SCAN_F4:     return KEY_F4;
            case SCAN_F5:    return KEY_F5;    case SCAN_F6:     return KEY_F6;
            case SCAN_F7:    return KEY_F7;    case SCAN_F8:     return KEY_F8;
            case SCAN_F9:    return KEY_F9;    case SCAN_F10:    return KEY_F10;
            default: return ch + 256;
        }
    }
    return ch;
#endif
}

// ------------------------------------------------------------------
//  keyPressed - non-blocking check for pending key
// ------------------------------------------------------------------

static bool keyPressed()
{
#if defined(PLATFORM_WINDOWS)
    MSG msg;
    return PeekMessage(&msg, NULL, WM_KEYFIRST, WM_KEYLAST, PM_NOREMOVE) != 0;
#else
    return kbhit() != 0;
#endif
}

// ------------------------------------------------------------------
//  clearKeyBuffer - discard any buffered input
// ------------------------------------------------------------------

static void clearKeyBuffer()
{
}

// ------------------------------------------------------------------
//  waitForKey - blocking wait for any key press
// ------------------------------------------------------------------

static void waitForKey()
{
    readKey();
}

// ------------------------------------------------------------------
//  pollKeyboard - pump the GDI message loop (no-op on DOS)
// ------------------------------------------------------------------

static void pollKeyboard()
{
#if defined(PLATFORM_WINDOWS)
    MSG msg;
    while (PeekMessage(&msg, NULL, 0, 0, PM_NOREMOVE))
    {
        if (msg.message >= WM_KEYFIRST && msg.message <= WM_KEYLAST)
            break;
        PeekMessage(&msg, NULL, msg.message, msg.message, PM_REMOVE);
        if (msg.message == WM_QUIT) break;
        TranslateMessage(&msg); DispatchMessage(&msg);
    }
#endif
}

// ------------------------------------------------------------------
//  escPressed - direct ESC key state check (non-blocking, no queue)
// ------------------------------------------------------------------

static bool escPressed()
{
#if defined(PLATFORM_WINDOWS)
    return (GetAsyncKeyState(VK_ESCAPE) & 0x8000) != 0;
#else
    return keyPressed() && readKey() == KEY_ESC;
#endif
}

#endif // INPUT_H
