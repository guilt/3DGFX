// File That Does 3D Point Manipulation.
#ifndef INC_MATH3D_H
#define INC_MATH3D_H

#include <math.h>
#include <CANVAS.H>



double mod(double a)
{
    if (a < 0)
    {
        a *= -1;
    }
    return a;
}

struct ProjectedPoint
{
    double x, y;
} projected, projected1, projected2;

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

void translate(Point3d& p, double x, double y, double z)
{
    p.x += x;
    p.y += y;
    p.z += z;
}

void translateLine(Line3d& l, double x, double y, double z)
{
    translate(l.p1, x, y, z);
    translate(l.p2, x, y, z);
}

void translateTriangle(Triangle3d& t, double x, double y, double z)
{
    translate(t.p1, x, y, z);
    translate(t.p2, x, y, z);
    translate(t.p3, x, y, z);
}

void rotate2d(double& x, double& y, int deg)
{
    double r = degToRad(deg);
    double x1 = x * cos(r) - y * sin(r);
    double y1 = x * sin(r) + y * cos(r);
    x = x1;
    y = y1;
}

void rotate(Point3d& p, int degx, int degy, int degz)
{
    rotate2d(p.y, p.z, degx);
    rotate2d(p.z, p.x, degy);
    rotate2d(p.x, p.y, degz);
}

void rotateLine(Line3d& l, int degx, int degy, int degz)
{
    rotate(l.p1, degx, degy, degz);
    rotate(l.p2, degx, degy, degz);
}

void rotateTriangle(Triangle3d& t, int degx, int degy, int degz)
{
    rotate(t.p1, degx, degy, degz);
    rotate(t.p2, degx, degy, degz);
    rotate(t.p3, degx, degy, degz);
}


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
