#ifndef INC_PLATFORM_H
#define INC_PLATFORM_H

// --- Platform Detection ---
// Key user-facing macros:
//   -DWIN         : target Windows (GDI backend, DOS compat stubs)
//   -DIBGI        : use Borland BGI backend (DOS)
//   -DISVGABGI    : SVGA hi-res BGI (requires IBGI)
//   -DIISO        : isometric projection engine
//   -DIZCLIP      : Z near/far plane clipping
//   -DIHSR        : hidden surface removal (back-face culling)
//   -DITEX        : texture-mapped objects
//   -DIZBUF       : Z-buffering

#if defined(WIN) || defined(_WIN32) || defined(WIN32)
  #ifndef PLATFORM_WINDOWS
    #define PLATFORM_WINDOWS
  #endif
#elif defined(__DOS__) || defined(__DJGPP__) || defined(MSDOS) || defined(__MSDOS__)
  #define PLATFORM_DOS
#elif defined(__WATCOMC__)
  #define PLATFORM_DOS
#endif

// --- Compiler Detection ---

#if defined(__WATCOMC__)
  #define COMPILER_WATCOM
#elif defined(__BORLANDC__)
  #define COMPILER_BORLAND
#elif defined(_MSC_VER)
  #define COMPILER_MSVC
#elif defined(__GNUC__) || defined(__MINGW32__) || defined(__MINGW64__)
  #define COMPILER_GCC
#endif

// --- Platform-specific Includes ---

#if defined(PLATFORM_DOS)
  #include <dos.h>
  #include <conio.h>
  #include <bios.h>
  #if defined(IBGI)
    #include <graphics.h>
    #ifdef ISVGABGI
      #include <SVGA256.H>
    #endif
  #endif
#elif defined(PLATFORM_WINDOWS)
  #include <windows.h>
  #include <conio.h>
#endif

// --- fstream Portability ---

#if defined(COMPILER_WATCOM) || defined(COMPILER_BORLAND)
  #include <fstream.h>
#else
  #include <fstream>
  using std::fstream;
  using std::ios;
#endif

#endif
