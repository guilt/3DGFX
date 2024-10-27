# Header Files

## Header File Hierarchy 

```
   SVGA.H
       \
      VGA.H GRAPHICS.H SVGA256.H
	     \  /
	     MATH3D.H
	           \
             MATHD.H
                \
              DEFS.H
                / \
           BMP.H  TEX.H
                   \
                   ZBUF.H
                    \
                    TRIL.H
                      \
                    MATHTD.H
```

-----------------------------------------------------------------------------

## Extended Header File Hierarchy: 

```
DEFS.H  IMAWRI.H
 \
  24PIX.H
   \
    FONTS.H
     \
     IMAGE.H
```

-----------------------------------------------------------------------------

## Description of Header Files

- `    SVGA.H` :  Deals with Lowest Level Of Graphics, Initialisation etc. 
- `     VGA.H` :  Deals with Some Basic Functions such as `putpixel()`. 
- `  MATH3D.H` :  Contains the Basic Data Structures and the Code to Deal with
                  their rotation etc. Here is Where Splitting between BGI
                  and 3DGFX takes Place. use `#define IBGI` before your Program
                  to use BGI. 
- `   MATHD.H` :  Contains Some Algorithms to draw 3D Lines and Points and
                  Meshed Objects etc. Here, you can alter the Basic Rendering
                  Engine.
- ` SVGA256.H` :  Contains Hi-Res SVGA Drivers. 
- `    DEFS.H` :  Used for Graphics Initialisation. Overall Coverage of 3D
                  Functions. 
- `     BMP.H` :  For Differentiation. Surface Programming is highly Encouraged. 
- `     TEX.H` :  Here, care is taken to be checked that `BMP.H` has not been
                  included. 
- `    ZBUF.H` :  Contains the Important Z-Buffering Algorithm. 
- `    TRIL.H` :  Basic Triangle Rendering Program. Adapted From the 3D
                  Black Hole. 
- `  MATHTD.H` :  Contains Routines To Draw Textured Objects. Some Routines
                  must be Changed. 
- `   24PIX.H` :  Allows one to Run-Time Dither a **24-Bit** Pixel into an **8-Bit**
                  one and is pretty useful for getting lots of Graphic Effects. 
- `   FONTS.H` :  A sample **8x8** System Font Bitmap. 
- `   IMAGE.H` :  Used to draw the easy Images themselves. Use for  
                  Side-Scrollers. 
- `  IMAWRI.H` :  Used for converting **8-Bit** BMPs into easy Images. 

-----------------------------------------------------------------------------

## Macros

Use these Macros to change the way things are drawn: 

- `    ISVGA` :  Use the Hi-Res Full Library; Requires BGI
- `     IBGI` :  Use The Full Functionality of the BGI
- `   I24BIT` :  Use the Palette Reduction technology for the Extended Hierarchy. 
                 Requires non BGI graphics;
- `     IISO` :  Use an Isometric Engine for Rendering
- `   IZCLIP` :  Use Z-Clipping 
- `     IHSR` :  Include Hidden Surface Removal
- `    IZBUF` :  Use Z-Buffer ;Requires HSR, non BGI graphics
 
Before including any of the Header Files, define these Macros by using
the `#define` pre-processor macros to use them.

-----------------------------------------------------------------------------