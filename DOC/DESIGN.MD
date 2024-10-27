# Library Design

Some amount of 3D has been put into these Programs. Basically, 3D Surfaces are
drawn using the equation of the shape, such as surfaces. For having solid
shapes, use plot(); For countoured ones, use conplot(). For spherically countoured
shapes, use sconplot(). Function sconplot() has been written to show the curvature
with angles theta and phi, in spherical coordinates. Translation (linear movement)
and Scaling are pretty easy, though the code isn't given here. They use: 

```
   x' = x + v(x).t + (1/2)a(x).t^2
   y' = y + v(y).t + (1/2)a(y).t^2
   z' = z + v(z).t + (1/2)a(z).t^2
```

and then update them:

```
   x' = a.x
   y' = b.y
   z' = c.z
```

The rotation, however derives it's formula from polar coordinates. 
where in a 2D System of x and y, 

```
   R = r cos (theta) i^ + r sin (theta) j^
```

and is replaced by

```
   R = r cos (theta + R) i^ + r sin (theta + R) j^
```

and the formulae are applied for  cos (theta + R) and sin (theta + R), giving
the expressions user in rtrans(), where

```
   x  = r cos (theta)
   y  = r sin (theta)
```

and to rotate-translate:

```
   x' = r cos (theta + R)
   y' = r sin (theta + R)
```

The default xyz System is drawn as: 

```
    Y
    |
    |_____X
    /
   /
  Z
```

which is a left-handed system. 

There is yet another Engine, which functions differently. This is the Isometric Engine,
where the octant is drawn as: 

```
        Y
        |
	    |
       / \
      /   \
     Z     X
```

The Objects are drawn as follows: 

Choose the number of vertices of the Object 'n'. Then Plot them as per
the shape of the object. Name the vertices as 0, 1, 2. .... n-1. 
Then write out the 'l' lines that are to be joined in terms of the endpoints
,such as 1,2 (line joining vertex 1 and vertex 2). Now after all the l
lines are completed, do the File, whose format is: 

```
   n
   x(0),y(0),z(0)
   x(1),y(1),z(2)
   .
   .
   .
   x(n-1),y(n-1),z(n-1)
   l
   v(0)1,v(0)2
   v(1)1,v(1)2
   .
   .
   .
   v(l-1)1,v(l-1)2
```

The Textured Objects have a small Change: 

The Lines are replaced by Textured Triangles, whose elements are written as: 

```
   v(0)1,v(0)2,v(0)3:t(0)
```

Where `t(0)` is the **Texture Number** as defined in the `NEW.TEX` File: 

```
   nt
   t(0)
   t(1)
   .
   .
   .
   t(nt-1)
```

Of Course, you can use your own textures! 

This covers Basic 3D, But more graphics code will have to go into it, to get
a swell 3D Rendering program. You can extend this library to support Lighting, 
by making use of the 24-Bit Reduction System in the Extended Hierarchy. 

The Graphics Library used was first the **BGI**. Now this is a somewhat
Independent VGA library. Backward Compatibility with the BGI is Provided. 
But "Some" Features of the Library may be "Unusable" if the BGI is used. 

Read The `HEADERS.MD` File for Help on the **Library File Organization**, and the
`DESC.MD` file for a **Description of the Layout**: Where, what files can be found. 

Please Read the `README.MD`, for the usage and other thoughts. 