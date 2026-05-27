# 3DGFX - 3D Graphics Library

Please read all of this Documentation:

- [Library Design](DOC/DESIGN.MD)
- [Header Reference](DOC/HEADERS.MD)
- [Directory Layout](DOC/DESC.MD)

This Library is released with an accompanying [License](LICENSE.MD).  
See also [FILE_ID.DIZ](FILE_ID.DIZ).

## Building

On **Windows (GDI)**:
```
BUILD.BAT MINGW       MinGW-w64 GCC
BUILD.BAT MSVC        Microsoft Visual C++
```

On **DOS** (DOSBox-X etc.):
```
BUILD.BAT BCC         Borland C++
BUILD.BAT WCL         OpenWatcom C++
BUILD.BAT DJGPP       DJGPP GCC
BUILD.BAT CL          Microsoft C/C++ for DOS
```

Cross-compile for DOS with OpenWatcom:
```
cmake -G "Watcom WMake" -D CMAKE_SYSTEM_NAME=DOS -D CMAKE_SYSTEM_PROCESSOR=I86 -S . -B Build
cmake --build Build
```

## Demo

Once built:
```
RUNDEMO.BAT
```

## Acknowledgments

David Brackeen, Johan Peitz - VGA Programming tutorials.  
Jerome St-Louis - Triangle Filling, HSR, Z-Buffering.  
Jordan Hargraphix - [SVGA BGI Driver](https://github.com/jharg93/SvgaBGI).  
Diana Gruber - [Action Arcade Adventure Set](https://archive.org/details/action-arcade-adventure-set).  
Math teachers Srinivasan, Radha Venkatesh.  
Computer Science teacher K. N. Rukmini.

*Author: Karthik Kumar Viswanathan*  
*Web: http://karthikkumar.org*  
*Email: me@karthikkumar.org*
