@REM - Build Executables
@ECHO OFF
@IF "%2"=="DEBUG=1" SET ECHO ON

SET BUILD_LOG=..\BUILD.LOG
CD EXAMPLES

IF EXIST *.EXE DEL *.EXE
ECHO Build Started.

ECHO Build Started. > %BUILD_LOG%
ECHO -------- >> %BUILD_LOG%

REM ---------------------------------------------------------------
REM BLDPLATFORM selection via first argument
REM   BUILD BCC    - Borland C++ (DOS)
REM   BUILD WCL    - OpenWatcom C++ (DOS)
REM   BUILD CL     - Microsoft C/C++ for DOS
REM   BUILD MSVC   - Microsoft Visual C++ (Windows)
REM   BUILD DJGPP  - DJGPP GCC (DOS)
REM   BUILD MINGW  - MinGW-w64 / GCC (Windows GDI)
REM   (no args)    - Default: Borland C++ (DOS) / Microsoft Visual C++ (Windows)

IF "%1"=="BCC"       SET BLDPLATFORM=BCC
IF "%1"=="WCL"       SET BLDPLATFORM=WCL
IF "%1"=="CL"        SET BLDPLATFORM=CL
IF "%1"=="MSVC"      SET BLDPLATFORM=MSVC
IF "%1"=="DJGPP"     SET BLDPLATFORM=DJGPP
IF "%1"=="MINGW"     SET BLDPLATFORM=MINGW

IF "%BLDPLATFORM%"=="" IF "%WINDIR%"=="" SET BLDPLATFORM=BCC
IF "%BLDPLATFORM%"=="" SET BLDPLATFORM=MSVC

ECHO [CONFIG] BLDPLATFORM is now %BLDPLATFORM%
ECHO BLDPLATFORM is now %BLDPLATFORM% >> %BUILD_LOG%
ECHO -------- >> %BUILD_LOG%

REM ---------------------------------------------------------------
REM Compiler setup (per BLDPLATFORM)
REM   %OUT_TO%  = output-flag prefix (e.g. -o, /Fe)
REM   %LIBS%    = extra link-time libraries (e.g. -lgdi32 -luser32)
REM ---------------------------------------------------------------

IF "%BLDPLATFORM%"=="BCC" SET CC=BCC
IF "%BLDPLATFORM%"=="BCC" SET CFLAGS=/mh /I..\INCLUDE
IF "%BLDPLATFORM%"=="BCC" SET OUT_TO=-o
IF "%BLDPLATFORM%"=="BCC" SET LIBS=

IF "%BLDPLATFORM%"=="WCL" SET CC=WCL
IF "%BLDPLATFORM%"=="WCL" SET CFLAGS=/mh /k8192 /I..\INCLUDE
IF "%BLDPLATFORM%"=="WCL" SET OUT_TO=-fe=
IF "%BLDPLATFORM%"=="WCL" SET LIBS=

IF "%BLDPLATFORM%"=="CL"  SET CC=CL
IF "%BLDPLATFORM%"=="CL"  SET CFLAGS=/AH /F 8192 /I..\INCLUDE
IF "%BLDPLATFORM%"=="CL"  SET OUT_TO=/Fe
IF "%BLDPLATFORM%"=="CL"  SET LIBS=

IF "%BLDPLATFORM%"=="MSVC" SET CC=cl
IF "%BLDPLATFORM%"=="MSVC" SET CFLAGS=/nologo /EHsc /DWIN /I..\INCLUDE
IF "%BLDPLATFORM%"=="MSVC" SET OUT_TO=/Fe
IF "%BLDPLATFORM%"=="MSVC" SET LIBS=gdi32.lib user32.lib /link /SUBSYSTEM:WINDOWS /ENTRY:mainCRTStartup

IF "%BLDPLATFORM%"=="DJGPP" SET CC=gxx
IF "%BLDPLATFORM%"=="DJGPP" SET CFLAGS=-std=c++98 -I..\INCLUDE
IF "%BLDPLATFORM%"=="DJGPP" SET OUT_TO=-o
IF "%BLDPLATFORM%"=="DJGPP" SET LIBS=

IF "%BLDPLATFORM%"=="MINGW" SET CC=g++
IF "%BLDPLATFORM%"=="MINGW" SET CFLAGS=-std=c++98 -DWIN -I..\INCLUDE
IF "%BLDPLATFORM%"=="MINGW" SET OUT_TO=-o
IF "%BLDPLATFORM%"=="MINGW" SET LIBS=-static-libgcc -static-libstdc++ -static -mwindows -lgdi32 -luser32

REM ---------------------------------------------------------------
REM DEBUG mode (second arg: DEBUG=1)
REM   Adds -DDEBUG and debug info (-g /Zi) for crash analysis
REM ---------------------------------------------------------------

IF "%2"=="DEBUG=1" SET CFLAGS=%CFLAGS% -DDEBUG
IF "%2"=="DEBUG=1" IF "%BLDPLATFORM%"=="MINGW"  SET CFLAGS=%CFLAGS% -g
IF "%2"=="DEBUG=1" IF "%BLDPLATFORM%"=="MSVC"   SET CFLAGS=%CFLAGS% /Zi
IF "%2"=="DEBUG=1" IF "%BLDPLATFORM%"=="BCC"    SET CFLAGS=%CFLAGS% -v
IF "%2"=="DEBUG=1" IF "%BLDPLATFORM%"=="WCL"    SET CFLAGS=%CFLAGS% -d2
IF "%2"=="DEBUG=1" IF "%BLDPLATFORM%"=="DJGPP"  SET CFLAGS=%CFLAGS% -g
IF "%2"=="DEBUG=1" IF "%BLDPLATFORM%"=="CL"     SET CFLAGS=%CFLAGS% /Zi

ECHO [CONFIG] Configured
ECHO Build Flags
ECHO Compiler: %CC%
ECHO Compiler Flags: %CFLAGS%
ECHO Output To: %OUT_TO%
ECHO Libraries: %LIBS%

ECHO Build Flags >> %BUILD_LOG%
ECHO Compiler: %CC% >> %BUILD_LOG%
ECHO Compiler Flags: %CFLAGS% >> %BUILD_LOG%
ECHO Output To: %OUT_TO% >> %BUILD_LOG%
ECHO Libraries: %LIBS% >> %BUILD_LOG%
ECHO -------- >> %BUILD_LOG%

REM ---------------------------------------------------------------
REM Build all examples (same syntax for every BLDPLATFORM)
REM   %CC% %CFLAGS% %OUT_TO%EXENAME.EXE ..\EXMPLSRC\SOURCE.CPP %LIBS%
REM ---------------------------------------------------------------

ECHO [CC] BMP
%CC% %CFLAGS% %OUT_TO%BMP.EXE ..\EXMPLSRC\BMP.CPP %LIBS% >> %BUILD_LOG%
ECHO -------- >> %BUILD_LOG%

ECHO [CC] GUN
%CC% %CFLAGS% %OUT_TO%GUN.EXE ..\EXMPLSRC\GUN.CPP %LIBS% >> %BUILD_LOG%
ECHO -------- >> %BUILD_LOG%

ECHO [CC] IMAGE
%CC% %CFLAGS% %OUT_TO%IMAGE.EXE ..\EXMPLSRC\IMAGE.CPP %LIBS% >> %BUILD_LOG%
ECHO -------- >> %BUILD_LOG%

ECHO [CC] MACHINE
%CC% %CFLAGS% %OUT_TO%MACHINE.EXE ..\EXMPLSRC\MACHINE.CPP %LIBS% >> %BUILD_LOG%
ECHO -------- >> %BUILD_LOG%

ECHO [CC] MORPH
%CC% %CFLAGS% %OUT_TO%MORPH.EXE ..\EXMPLSRC\MORPH.CPP %LIBS% >> %BUILD_LOG%
ECHO -------- >> %BUILD_LOG%

ECHO [CC] SPHERE
%CC% %CFLAGS% %OUT_TO%SPHERE.EXE ..\EXMPLSRC\SPHERE.CPP %LIBS% >> %BUILD_LOG%
ECHO -------- >> %BUILD_LOG%

ECHO [CC] SURFACES
%CC% %CFLAGS% %OUT_TO%SURFACES.EXE ..\EXMPLSRC\SURFACES.CPP %LIBS% >> %BUILD_LOG%
ECHO -------- >> %BUILD_LOG%

ECHO [CC] TEX
%CC% %CFLAGS% %OUT_TO%TEX.EXE ..\EXMPLSRC\TEX.CPP %LIBS% >> %BUILD_LOG%
ECHO -------- >> %BUILD_LOG%

ECHO [CC] TEXFACES
%CC% %CFLAGS% %OUT_TO%TEXFACES.EXE ..\EXMPLSRC\TEXFACES.CPP %LIBS% >> %BUILD_LOG%
ECHO -------- >> %BUILD_LOG%

ECHO [CC] TRI
%CC% %CFLAGS% %OUT_TO%TRI.EXE ..\EXMPLSRC\TRI.CPP %LIBS% >> %BUILD_LOG%
ECHO -------- >> %BUILD_LOG%

ECHO [CC] ZBT
%CC% %CFLAGS% %OUT_TO%ZBT.EXE ..\EXMPLSRC\ZBT.CPP %LIBS% >> %BUILD_LOG%
ECHO -------- >> %BUILD_LOG%

ECHO [DONE]
ECHO -------- >> %BUILD_LOG%

CD..

ECHO Build Finished.
