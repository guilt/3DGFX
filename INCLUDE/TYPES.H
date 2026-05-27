#ifndef INC_TYPES_H
#define INC_TYPES_H

// Portable fixed-width types

// Borland < 5.0 lacks built-in bool (5.0/5.5+ have it as a keyword)
#if defined(__BORLANDC__) && __BORLANDC__ < 0x0500
  typedef int bool;
  #ifndef true
  #define true 1
  #endif
  #ifndef false
  #define false 0
  #endif
#endif

typedef signed char int8;
typedef short int16;
#if defined(__BORLANDC__) || defined(__WATCOMC__)
typedef long int32;
#else
typedef int int32;
#endif
typedef unsigned char uint8;
typedef unsigned short uint16;
#if defined(__BORLANDC__) || defined(__WATCOMC__)
typedef unsigned long uint32;
#else
typedef unsigned int uint32;
#endif
typedef float float32;
typedef double float64;

typedef uint8 byte;
typedef uint16 word;
typedef uint32 dword;

static const int NUM_COLORS = 256;
static const int PALETTE_BYTES = 3 * NUM_COLORS;

struct RGBQuad { char b, g, r, a; };

// ------------------------------------------------------------------
//  BGI colour constants (same as graphics.h enum)
//  Bare names defined only if compiler doesn't already define them.
//  COLOR_ prefixed names always work.
// ------------------------------------------------------------------

#ifndef BLACK
#define BLACK          0
#endif
#ifndef BLUE
#define BLUE           1
#endif
#ifndef GREEN
#define GREEN          2
#endif
#ifndef CYAN
#define CYAN           3
#endif
#ifndef RED
#define RED            4
#endif
#ifndef MAGENTA
#define MAGENTA        5
#endif
#ifndef BROWN
#define BROWN          6
#endif
#ifndef LIGHTGRAY
#define LIGHTGRAY      7
#endif
#ifndef DARKGRAY
#define DARKGRAY       8
#endif
#ifndef LIGHTBLUE
#define LIGHTBLUE      9
#endif
#ifndef LIGHTGREEN
#define LIGHTGREEN    10
#endif
#ifndef LIGHTCYAN
#define LIGHTCYAN     11
#endif
#ifndef LIGHTRED
#define LIGHTRED      12
#endif
#ifndef LIGHTMAGENTA
#define LIGHTMAGENTA  13
#endif
#ifndef YELLOW
#define YELLOW        14
#endif
#ifndef WHITE
#define WHITE         15
#endif

// ------------------------------------------------------------------
//  RGB ? indexed conversion (compile-time evaluable macro)
//  Maps 24-bit RGB to the 5?8?6 cube (indices 16-255).
//  For BGI colours 0-15 use the bare name directly: putPixel(x,y,RED)
// ------------------------------------------------------------------

#define RGBToIndexed(r, g, b) ((byte)( \
    16 + \
    (((unsigned)(r) * 5 / 256) * 48) + \
    (((unsigned)(g) * 8 / 256) * 6) + \
    ((unsigned)(b) * 6 / 256) \
))

#define RGBAToIndexed(r, g, b, a) RGBToIndexed(r, g, b)

// ------------------------------------------------------------------
//  Math constants
// ------------------------------------------------------------------

// M_PI from <math.h> - use system value if available
#if defined(_MSC_VER)
  #define _USE_MATH_DEFINES
#endif
#include <math.h>
#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

#ifndef degToRad
#define degToRad(o) ((o) * M_PI / 180)
#endif

// ------------------------------------------------------------------
//  Clamp / sign helpers
// ------------------------------------------------------------------

#ifndef clamp255
#define clamp255(x)  ((x) < 0 ? 0 : ((x) > 255 ? 255 : (x)))
#endif

#define sign(x) (((x) > 0) - ((x) < 0))

#endif
