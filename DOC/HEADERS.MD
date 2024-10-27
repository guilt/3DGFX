# Header Files

## Header File Hierarchy 

```
   MODE.H      GRAPHICS.H
       \         /
      VGA.H     /
          \    /
           DEFS.H       MATH3D.H
          /  / |  \      |
	     /  /  |   \     |
        /  /   |    \    |
       / BMP.H TEX.H \   |       
      /               MATHREN.H
    ZBUF.H               |
        \                |
         \___________    |
                     \   |
                     TRIREN.H
                        |                     
                     TMATHREN.H
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

- `    MODE.H` :  Deals with Lowest Level Of Graphics, Initialisation etc. 
- `     VGA.H` :  Deals with Some Basic Functions such as `putpixel()`. 
- `  MATH3D.H` :  Contains the Basic Data Structures and the Code to Deal with
                  their rotation etc.
- ` MATHREN.H` :  Contains Some Algorithms to draw 3D Lines and Points and
                  Meshed Objects etc. Here, you can alter the Basic Rendering
                  Engine.
- `    DEFS.H` :  Used for Basic Graphics Initialisation. Switch between BGI and MODE Graphics.
- `     BMP.H` :  Bitmap loading. Surface Programming is highly Encouraged. 
- `     TEX.H` :  Texture loading. You should either include this one or `BMP.H`, not both.
- `    ZBUF.H` :  Contains the Z-Buffering Algorithm. 
- `  TRIREN.H` :  Basic Triangle Rendering Program. Adapted From the 3D
                  Black Hole.
- `TMATHREN.H` :  Contains Routines To Draw Textured Objects. 
- `   24PIX.H` :  Allows one to Run-Time Dither a **24-Bit** Pixel into an **8-Bit**
                  one and is pretty useful for getting lots of Graphic Effects. 
- `   FONTS.H` :  A sample **8x8** System Font Bitmap. 
- `   IMAGE.H` :  Used to draw the easy Images themselves.
- `  IMAWRI.H` :  Used for converting **8-Bit** BMPs into easy Images. 

-----------------------------------------------------------------------------

## Macros

Use these Macros to change the way things are drawn: 

- `     IBGI` :  Use The Full Functionality of the BGI
- `    ISVGA` :  Use the Hi-Res SVGA Driver; Requires `IBGI`.
- `   I24BIT` :  Use the Palette Reduction technology. Requires not `IBGI`.
- `     IISO` :  Use an Isometric Engine for Rendering
- `   IZCLIP` :  Use Z-Clipping
- `     IHSR` :  Use Hidden Surface Removal
- `    IZBUF` :  Use Z-Buffer
 
Before including any of the Header Files, define these Macros by using
the `#define` pre-processor macros to use them.

-----------------------------------------------------------------------------