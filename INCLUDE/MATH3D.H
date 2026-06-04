// File That Does 3D Point Manipulation.
#ifndef INC_MATH3D_H
#define INC_MATH3D_H

#include <math.h>
#include <CANVAS.H>



#define mod(a) (((a) < 0) ? -(a) : (a))

struct ProjectedPoint
{
    double x, y;
};

static ProjectedPoint projected, projected1, projected2;

#define MAX_POINTS 50

struct Point3d
{
    double x, y, z;
};

struct Point3dc
{
    double r, o, z;
};

struct Line3d
{
    Point3d p1, p2;
};

struct Triangle3d
{
    Point3d p1, p2, p3;
};

#define translate(p, x, y, z)  do { (p).x += (x); (p).y += (y); (p).z += (z); } while(0)

static void rotate(Point3d& p, int degx, int degy, int degz)
{
    double x = p.x, y = p.y, z = p.z;
    double r, c, s, t;

    if (degx) { r = degToRad(degx); c = cos(r); s = sin(r); t = y*c - z*s; z = y*s + z*c; y = t; }
    if (degy) { r = degToRad(degy); c = cos(r); s = sin(r); t = z*c - x*s; x = z*s + x*c; z = t; }
    if (degz) { r = degToRad(degz); c = cos(r); s = sin(r); t = x*c - y*s; y = x*s + y*c; x = t; }

    p.x = x; p.y = y; p.z = z;
}

#define rotateLine(l, dx, dy, dz) \
    do { rotate((l).p1, (dx), (dy), (dz)); rotate((l).p2, (dx), (dy), (dz)); } while(0)

#define rotateTriangle(t, dx, dy, dz) \
    do { rotate((t).p1, (dx), (dy), (dz)); \
         rotate((t).p2, (dx), (dy), (dz)); \
         rotate((t).p3, (dx), (dy), (dz)); } while(0)


struct ProjectionState
{
    double xScale;
    double yScale;
    double zScale;
    int centerX;
    int centerY;
    double thetaOffset;

    ProjectionState() : xScale(4.5), yScale(4.5), zScale(1.125),
                        centerX(160), centerY(100), thetaOffset(0.0) {}
};

inline ProjectedPoint projectPoint(const Point3d& p, const ProjectionState& ps)
{
    ProjectedPoint pp;
    pp.x = ps.centerX + p.x * ps.xScale;
    pp.y = ps.centerY - p.y * ps.yScale;
    pp.x -= p.z * ps.zScale;
    pp.y += p.z * ps.zScale;
    return pp;
}

inline ProjectedPoint projectPointC(const Point3dc& p, const ProjectionState& ps)
{
    ProjectedPoint pp;
    double ot = ps.thetaOffset;
    pp.x = ps.centerX + p.r * cos(ot) * ps.xScale;
    pp.y = ps.centerY - p.r * sin(ot) * ps.yScale;
    pp.x -= p.z * ps.zScale;
    pp.y += p.z * ps.zScale;
    return pp;
}

#endif
