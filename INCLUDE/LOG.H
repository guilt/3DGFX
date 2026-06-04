// LOG.H -- Simple logging.
//
//   Requires -DDEBUG at build time.  Without it all macros are no-ops
//   and zero code is emitted.
//
//   logInit()          open the log (DOS: DEBUG.LOG, Windows: debug buffer)
//   logQuit()          close / flush
//   logPrintf(fmt,..)  printf-style output (appends newline)

#ifndef INC_LOG_H
#define INC_LOG_H

#include <stdarg.h>
#include <stdio.h>

#if defined(DEBUG)

#  if defined(PLATFORM_WINDOWS)
#    include <windows.h>
#    define logInit()       ((void)0)
#    define logQuit()       ((void)0)
     static void logPrintf(const char* fmt, ...)
     {
         char buf[128];
         va_list ap; va_start(ap, fmt);
         vsprintf(buf, fmt, ap);
         va_end(ap);
         OutputDebugStringA(buf);
         OutputDebugStringA("\n");
     }
#  else
#    include <fstream.h>
     static ofstream _logFile;
#    define logInit()       do { _logFile.open("DEBUG.LOG"); } while(0)
#    define logQuit()       do { if(_logFile.good())_logFile.close(); } while(0)
     static void logPrintf(const char* fmt, ...)
     {
         if (_logFile.good()) {
             va_list ap; va_start(ap, fmt);
             char buf[128]; vsprintf(buf, fmt, ap);
             va_end(ap);
             _logFile << buf << endl;
         }
     }
#  endif

#else  /* !DEBUG -- all no-ops */
#  define logInit()       ((void)0)
#  define logQuit()       ((void)0)
   static void logPrintf(const char* fmt, ...) { (void)fmt; }
#endif

#endif
