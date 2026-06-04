// File That Draws 3D Objects.
#ifndef INC_RENDER_H
#define INC_RENDER_H
#include <PLATFORM.H>

#include <MATH3D.H>
#include <CANVAS.H>
#include <TEXTURE.H>
static double xScale = 4.5, yScale = 4.5;
static double thetaAngle = 0.0;

// Isometric Engine.
#ifdef IISO
static double zScale = 2;
#define projectPoint(out, p)                      \
    do {                                          \
        (out).x = (midX + ((p).x * xScale         \
                    - (p).z * zScale) * 0.87);    \
        (out).y = (midY + ((p).x * xScale         \
                    + (p).z * zScale) * 0.5       \
                    - (p).y * yScale);            \
    } while(0)

#define projectSpherical(out, p)                  \
    do {                                          \
        (out).x = (midX + ((p).r                  \
                    * cos(thetaAngle) * xScale     \
                    - (p).z * zScale) * 0.87);    \
        (out).y = (midY + ((p).r                  \
                    * cos(thetaAngle) * xScale     \
                    + (p).z * zScale) * 0.5       \
                    - (p).r * sin(thetaAngle)     \
                    * yScale);                    \
    } while(0)
#endif

// Default Non Isometric Engine.
#ifndef IISO
static double zScale = 1.125;
#define projectPoint(out, p)                      \
    do {                                          \
        (out).x = midX + (p).x * xScale           \
                        - (p).z * zScale;         \
        (out).y = midY - (p).y * yScale           \
                        + (p).z * zScale;         \
    } while(0)

#define projectSpherical(out, p)                  \
    do {                                          \
        (out).x = midX + (p).r * cos(thetaAngle)  \
                        * xScale - (p).z * zScale;\
        (out).y = midY - (p).r * sin(thetaAngle)  \
                        * yScale + (p).z * zScale;\
    } while(0)
#endif

struct LineSeg
{
    int p1, p2;
};

struct LineMesh
{
    LineSeg segments[MAX_POINTS];
    int segmentCount;
};

struct Object3d
{
    Point3d points[MAX_POINTS];
    int pointCount;
    Point3d center;
    LineMesh lineMesh;
};

static void drawPoint(const Point3d& p, byte color = currentColor)
{
    ProjectedPoint pp;
    projectPoint(pp, p);
    putPixel((int)pp.x, (int)pp.y, color);
}

static void drawPointC(const Point3dc& p, byte color = currentColor)
{
    thetaAngle = ((M_PI * p.o) / 180);
    ProjectedPoint pp;
    projectSpherical(pp, p);
    putPixel((int)pp.x, (int)pp.y, color);
}

static void drawLine(const Line3d& l, byte color = currentColor)
{
    int tcolor = getColor();
    ProjectedPoint p1, p2;
    projectPoint(p1, l.p1);
    projectPoint(p2, l.p2);
    setColor(color);
    drawLine((int)p1.x, (int)p1.y, (int)p2.x, (int)p2.y, color);
    setColor(tcolor);
}

static void drawTriangle(const Triangle3d& t, byte color = currentColor)
{
    ProjectedPoint pp1, pp2, pp3;
    projectPoint(pp1, t.p1);
    projectPoint(pp2, t.p2);
    projectPoint(pp3, t.p3);
    drawLine((int)pp1.x, (int)pp1.y, (int)pp2.x, (int)pp2.y, color);
    drawLine((int)pp2.x, (int)pp2.y, (int)pp3.x, (int)pp3.y, color);
    drawLine((int)pp3.x, (int)pp3.y, (int)pp1.x, (int)pp1.y, color);
}

static void drawAxis(byte color = currentColor)
{
    Line3d l;
    l.p1.x = 0, l.p1.y = 0, l.p1.z = 0;
    l.p2.x = 0, l.p2.y = 0, l.p2.z = 40;
    drawLine(l, color);
    l.p2.x = 0, l.p2.y = 20, l.p2.z = 0;
    drawLine(l, color);
    l.p2.x = 20, l.p2.y = 0, l.p2.z = 0;
    drawLine(l, color);
    l.p2.x = 0, l.p2.y = 0, l.p2.z = -40;
    drawLine(l, color);
    l.p2.x = 0, l.p2.y = -20, l.p2.z = 0;
    drawLine(l, color);
    l.p2.x = -20, l.p2.y = 0, l.p2.z = 0;
    drawLine(l, color);
}

static void contourPlot(const Point3d& p, byte color)
{
    if ((int(p.x * 1000) % 79 == 0) || (int(p.z * 1000) % 79 == 0))
    {
        drawPoint(p, color);
    }
}

static void sphContourPlot(const Point3d& p, byte color, double oo, double pp)
{
    if (((int(oo) % 10) == 0) || ((int(pp) % 10) == 0))
    {
        drawPoint(p, color);
    }
}

static void objectTranslate(Object3d& o, double x, double y, double z)
{
    int i;
    for (i = 0; i < o.pointCount; i++)
    {
        translate(o.points[i], x, y, z);
    }
}

static void objectRotate(Object3d& o, int degx, int degy, int degz)
{
    int i;
    for (i = 0; i < o.pointCount; i++)
    {
        rotate(o.points[i], degx, degy, degz);
    }
}

static int readObject(const char* fileName, Object3d& o)
{
    char c;
    int i;
    fstream file;

    o.pointCount = 0;
    file.open(fileName, ios::in);
    if (!file)
    {
        return -1;
    }
    file >> o.pointCount;
    o.center.x = 0, o.center.y = 0, o.center.z = 0;
    for (i = 0; i < o.pointCount; i++)
    {
        file >> o.points[i].x;
        o.center.x += o.points[i].x;
        file.get(c);
        file >> o.points[i].y;
        o.center.y += o.points[i].y;
        file.get(c);
        file >> o.points[i].z;
        o.center.z += o.points[i].z;
    }
    o.center.x /= o.pointCount, o.center.y /= o.pointCount, o.center.z /= o.pointCount;
    file >> o.lineMesh.segmentCount;
    for (i = 0; i < o.lineMesh.segmentCount; i++)
    {
        file >> o.lineMesh.segments[i].p1;
        file.get(c);
        file >> o.lineMesh.segments[i].p2;
    }
    file.close();
    return 0;
}

static void drawObject(const Object3d& o, byte color)
{
    int i;
    Line3d la;
    for (i = 0; i < o.lineMesh.segmentCount; i++)
    {
        la.p1 = o.points[o.lineMesh.segments[i].p1];
        la.p2 = o.points[o.lineMesh.segments[i].p2];
        drawLine(la, color);
    }
}


#ifndef __BORLANDC__
inline
#endif
static void drawLineBresenham(Canvas& canvas, int x1, int y1,
                               int x2, int y2, byte color)
{
    int dx = x2 - x1;
    int dy = y2 - y1;
    int dxAbs = abs(dx);
    int dyAbs = abs(dy);
    int sdx = sign(dx);
    int sdy = sign(dy);
    int x = dyAbs >> 1;
    int y = dxAbs >> 1;
    int px = x1;
    int py = y1;

    canvas.putPixel(px, py, color);

    if (dxAbs >= dyAbs)
    {
        int i;
        for (i = 0; i < dxAbs; i++)
        {
            y += dyAbs;
            if (y >= dxAbs)
            {
                y -= dxAbs;
                py += sdy;
            }
            px += sdx;
            canvas.putPixel(px, py, color);
        }
    }
    else
    {
        int i;
        for (i = 0; i < dyAbs; i++)
        {
            x += dxAbs;
            if (x >= dyAbs)
            {
                x -= dyAbs;
                px += sdx;
            }
            py += sdy;
            canvas.putPixel(px, py, color);
        }
    }
}

inline void drawRect(Canvas& canvas, int left, int top,
                      int right, int bottom, byte color)
{
    drawLineBresenham(canvas, left, top, right, top, color);
    drawLineBresenham(canvas, left, top, left, bottom, color);
    drawLineBresenham(canvas, right, top, right, bottom, color);
    drawLineBresenham(canvas, left, bottom, right, bottom, color);
}

#ifndef __BORLANDC__
inline
#endif
static void drawCircle(Canvas& canvas, int cx, int cy,
                        int radius, byte color)
{
    int o;
    for (o = 0; o < 360; o++)
    {
        double rx = radius * cos(degToRad(o));
        double ry = radius * sin(degToRad(o));
        canvas.putPixel(cx + (int)rx, cy + (int)ry, color);
    }
}

// The Important Z-Buffering File.

#ifndef IZBUF
#define zBufferTestAndSet(x, y, z, color)
#define zBufferCreate()
#define zBufferDestroy()
#define zBufferClear()
#endif

#ifdef IZBUF

#define ZMEM   screenHeight*screenWidth
#define ZPARAM 500

static int16 *zBuffer;

static void zBufferCreate()
{
    zBuffer = (int16*)malloc(ZMEM * sizeof(int16));
}

static void zBufferClear()
{
    int32 i;
    for (i = 0; i < ZMEM; i++)
    {
        zBuffer[i] = -32768;
    }
}

#define zBufferTestAndSet(x, y, z, c) do { \
    int _x_ = CLAMP_X(x), _y_ = CLAMP_Y(y); \
    int _off_ = (int)screenWidth * _y_ + _x_; \
    int16 _zc_ = (int16)(z) * ZPARAM; \
    if (_zc_ > zBuffer[_off_]) { \
        zBuffer[_off_] = _zc_; \
        putPixelFast(_x_, _y_, c); \
    } \
} while(0)

static void zBufferDestroy()
{
    free(zBuffer);
}
#endif

// The Triangle Renderer.

#define MIN(a, b) ((a < b) ? (a) : (b))
#define MAX(a, b) ((a > b) ? (a) : (b))

// Near and Far Clipping Planes.

#define Hither 30
#define Yon    -30

#define zclip(z)                          \
    (z <= 0) ? ((z <= Yon) ? z = Yon : z) \
             : ((z >= Hither) ? z = Hither : z)

#ifdef ITEX

Texture FAR* gTextures = NULL;

struct TexTriangle3d
{
    Triangle3d triangle;
    int texIndex;
};

static void sortVertices(ProjectedPoint& a, ProjectedPoint& b)
{
    if (a.y > b.y)
    {
        ProjectedPoint t = a;
        a = b;
        b = t;
    }
}

static void texHLineFast(int x1, int x2, int y, int texIndex)
{
    int w = gTextures[texIndex].width;
    int h = gTextures[texIndex].height;
    for (int x = x1; x <= x2; x++)
        putPixelFast(x, y, gTextures[texIndex].data[x % w][h - 1 - (y % h)]);
}

static void texHLine(int x1, int x2, int y, int texIndex, int u1, int v1, int u2, int v2)
{
    int w = gTextures[texIndex].width;
    int h = gTextures[texIndex].height;
    int dx = x2 - x1;
    int du = u2 - u1, dv = v2 - v1;
    for (int x = x1; x <= x2; x++)
    {
        int tu = dx ? (u1 + ((x - x1) * du / dx)) >> 8 : u1 >> 8;
        int tv = dx ? (v1 + ((x - x1) * dv / dx)) >> 8 : v1 >> 8;
        tu = (tu % w + w) % w;
        tv = (tv % h + h) % h;
#ifdef IZBUF
        zBufferTestAndSet(x, y, 0, gTextures[texIndex].data[tu][h - 1 - tv]);
#else
        putPixelFast(x, y, gTextures[texIndex].data[tu][h - 1 - tv]);
#endif
    }
}

static void clearHLine(int x1, int x2, int y)
{
    for (int x = x1; x <= x2; x++)
        putPixelFast(x, y, 0);
}

static void clearTriangle(TexTriangle3d& t, ProjectedPoint sp[3])
{
    int i;

#ifdef IHSR
    double x1, y1, z1;
    double x2, y2, z2;
    double x3, y3, z3;
    double D;
#endif
    int xd1, yd1, xd2, yd2;
    int Lx, Rx;
#ifdef IZCLIP
    zclip(t.triangle.p1.z);
    zclip(t.triangle.p2.z);
    zclip(t.triangle.p3.z);
#endif
#ifdef IHSR
    x1 = t.triangle.p1.x, y1 = t.triangle.p1.y, z1 = t.triangle.p1.z;
    x2 = t.triangle.p2.x, y2 = t.triangle.p2.y, z2 = t.triangle.p2.z;
    x3 = t.triangle.p3.x, y3 = t.triangle.p3.y, z3 = t.triangle.p3.z;
    D = -x1 * (y2 * z3 - y3 * z2) - x2 * (y3 * z1 - y1 * z3) -
        x3 * (y1 * z2 - y2 * z1);
    if (D >= 0)
    {
#endif
        sp[0] = projected;
        sp[1] = projected1;
        sp[2] = projected2;
        sortVertices(sp[0], sp[1]);
        sortVertices(sp[1], sp[2]);
        sortVertices(sp[0], sp[1]);
        xd1 = (int)(sp[1].x - sp[0].x);
        yd1 = (int)(sp[1].y - sp[0].y);
        xd2 = (int)(sp[2].x - sp[0].x);
        yd2 = (int)(sp[2].y - sp[0].y);
        if (yd1)
        {
            int yStart = (int)sp[0].y, yEnd = (int)sp[1].y;
            double sx = sp[0].x, sy = sp[0].y;
            for (i = yStart; i <= yEnd; i++)
            {
                Lx = (int)(sx + ((i - sy) * xd1) / yd1);
                Rx = (int)(sx + ((i - sy) * xd2) / yd2);
                clearHLine(MIN(Lx, Rx), MAX(Lx, Rx), i);
            }
        }
        xd1 = (int)(sp[2].x - sp[1].x);
        yd1 = (int)(sp[2].y - sp[1].y);
        if (yd1)
        {
            int yStart = (int)sp[1].y, yEnd = (int)sp[2].y;
            double sx = sp[1].x, sy = sp[1].y;
            double s0x = sp[0].x, s0y = sp[0].y;
            for (i = yStart; i <= yEnd; i++)
            {
                Lx = (int)(s0x + ((i - s0y) * xd2) / yd2);
                Rx = (int)(sx + ((i - sy) * xd1) / yd1);
                clearHLine(MIN(Lx, Rx), MAX(Lx, Rx), i);
            }
        }
#ifdef IHSR
    }
#endif
}

static void renderTriangle(TexTriangle3d& t, ProjectedPoint sp[3])
{
    int i;
    int xd1, yd1, xd2, yd2;
    int Lx, Rx;
#ifdef IHSR
    double x1, y1, z1;
    double x2, y2, z2;
    double x3, y3, z3;
    double D;
#endif
#ifdef IZCLIP
    zclip(t.triangle.p1.z);
    zclip(t.triangle.p2.z);
    zclip(t.triangle.p3.z);
#endif
#ifdef IHSR
    x1 = t.triangle.p1.x, y1 = t.triangle.p1.y, z1 = t.triangle.p1.z;
    x2 = t.triangle.p2.x, y2 = t.triangle.p2.y, z2 = t.triangle.p2.z;
    x3 = t.triangle.p3.x, y3 = t.triangle.p3.y, z3 = t.triangle.p3.z;
    D = -x1 * (y2 * z3 - y3 * z2) - x2 * (y3 * z1 - y1 * z3) -
        x3 * (y1 * z2 - y2 * z1);
    if (D >= 0)
    {
#endif
        sortVertices(sp[0], sp[1]);
        sortVertices(sp[1], sp[2]);
        sortVertices(sp[0], sp[1]);

        int u1 = (int)(t.triangle.p1.x * 256), v1 = (int)(t.triangle.p1.y * 256);
        int u2 = (int)(t.triangle.p2.x * 256), v2 = (int)(t.triangle.p2.y * 256);
        int u3 = (int)(t.triangle.p3.x * 256), v3 = (int)(t.triangle.p3.y * 256);
        int du12 = u2 - u1, dv12 = v2 - v1;
        int du13 = u3 - u1, dv13 = v3 - v1;
        int du23 = u3 - u2, dv23 = v3 - v2;

        xd1 = (int)(sp[1].x - sp[0].x);
        yd1 = (int)(sp[1].y - sp[0].y);
        xd2 = (int)(sp[2].x - sp[0].x);
        yd2 = (int)(sp[2].y - sp[0].y);
        if (yd1)
        {
            int yStart = (int)sp[0].y, yEnd = (int)sp[1].y;
            double sx = sp[0].x, sy = sp[0].y;
            for (i = yStart; i <= yEnd; i++)
            {
                int dy = i - (int)sy;
                Lx = (int)(sx + dy * xd1 / yd1);
                Rx = (int)(sx + dy * xd2 / yd2);
                int uL = u1 + dy * du12 / yd1, vL = v1 + dy * dv12 / yd1;
                int uR = u1 + dy * du13 / yd2, vR = v1 + dy * dv13 / yd2;
                if (Lx <= Rx)
                    texHLine(Lx, Rx, i, t.texIndex, uL, vL, uR, vR);
                else
                    texHLine(Rx, Lx, i, t.texIndex, uR, vR, uL, vL);
            }
        }
        xd1 = (int)(sp[2].x - sp[1].x);
        yd1 = (int)(sp[2].y - sp[1].y);
        if (yd1)
        {
            int yStart = (int)sp[1].y, yEnd = (int)sp[2].y;
            double s0x = sp[0].x, s0y = sp[0].y;
            double s1x = sp[1].x, s1y = sp[1].y;
            for (i = yStart; i <= yEnd; i++)
            {
                int dy1 = i - (int)s0y, dy2 = i - (int)s1y;
                Lx = (int)(s0x + dy1 * xd2 / yd2);
                Rx = (int)(s1x + dy2 * xd1 / yd1);
                int uL = u1 + dy1 * du13 / yd2, vL = v1 + dy1 * dv13 / yd2;
                int uR = u2 + dy2 * du23 / yd1, vR = v2 + dy2 * dv23 / yd1;
                if (Lx <= Rx)
                    texHLine(Lx, Rx, i, t.texIndex, uL, vL, uR, vR);
                else
                    texHLine(Rx, Lx, i, t.texIndex, uR, vR, uL, vL);
            }
        }
#ifdef IHSR
    }
#endif
}

struct TexturedTriMesh
{
    int p1, p2, p3, texIndex;
};

struct TexturedMesh
{
    TexturedTriMesh tris[MAX_POINTS];
    int triCount;
};

struct TexturedObject
{
    Point3d points[MAX_POINTS];
    int pointCount;
    Point3d center;
    TexturedMesh mesh;
};

static void objectTranslate(TexturedObject& o, double x, double y, double z)
{
    int i;
    for (i = 0; i < o.pointCount; i++)
    {
        translate(o.points[i], x, y, z);
    }
}

static void objectRotate(TexturedObject& o, int degx, int degy, int degz)
{
    int i;
    for (i = 0; i < o.pointCount; i++)
    {
        rotate(o.points[i], degx, degy, degz);
    }
}

static bool loadTexturedObjectInto(const char* fileName, TexturedObject& o)
{
    char c;
    int i;
    fstream file;
    o.pointCount = 0;
    file.open(fileName, ios::in);
    if (!file)
    {
        return false;
    }
    file >> o.pointCount;
    o.center.x = 0, o.center.y = 0, o.center.z = 0;
    for (i = 0; i < o.pointCount; i++)
    {
        file >> o.points[i].x;
        o.center.x += o.points[i].x;
        file.get(c);
        file >> o.points[i].y;
        o.center.y += o.points[i].y;
        file.get(c);
        file >> o.points[i].z;
        o.center.z += o.points[i].z;
    }
    o.center.x /= o.pointCount, o.center.y /= o.pointCount, o.center.z /= o.pointCount;
    file >> o.mesh.triCount;
    for (i = 0; i < o.mesh.triCount; i++)
    {
        file >> o.mesh.tris[i].p1;
        file.get(c);
        file >> o.mesh.tris[i].p2;
        file.get(c);
        file >> o.mesh.tris[i].p3;
        file.get(c);
        file >> o.mesh.tris[i].texIndex;
        o.mesh.tris[i].texIndex %= MAX_TEXTURES;
    }
    file.close();
    return true;
}

static char texNames[MAX_TEXTURES][MAX_FILENAME_LEN];
static int texNameCount = 0;

static void loadTextures(const char* fileName)
{
    int i;
    fstream file;
    file.open(fileName, ios::in);
    file >> texNameCount;
    texNameCount %= MAX_TEXTURES + 1;
    for (i = 0; i < texNameCount; i++)
    {
        file >> texNames[i];
    }
    file.close();
    if (!gTextures) gTextures = new Texture[MAX_TEXTURES];
}

static byte texLoaded[MAX_TEXTURES];

static void loadUsedTextures(TexturedObject& o)
{
    int loaded = 0;
    if (!gTextures) { gTextures = new Texture[MAX_TEXTURES]; memset(texLoaded, 0, MAX_TEXTURES); }
    for (int i = 0; i < o.mesh.triCount; i++)
    {
        int ti = o.mesh.tris[i].texIndex;
        if (ti >= 0 && ti < texNameCount && !texLoaded[ti])
        {
            texLoaded[ti] = 1;
            loadTextureInto(texNames[ti], gTextures[ti]);
            loaded = 1;
        }
    }
    (void)loaded;
}

static void drawTexturedObject(TexturedObject& o)
{
    ProjectedPoint sp[3];
    for (int tdi = 0; tdi < o.mesh.triCount; tdi++)
    {
        TexTriangle3d tri;
        tri.triangle.p1 = o.points[o.mesh.tris[tdi].p1];
        tri.triangle.p2 = o.points[o.mesh.tris[tdi].p2];
        tri.triangle.p3 = o.points[o.mesh.tris[tdi].p3];
        tri.texIndex = o.mesh.tris[tdi].texIndex;
        projectPoint(sp[0], tri.triangle.p1);
        projectPoint(sp[1], tri.triangle.p2);
        projectPoint(sp[2], tri.triangle.p3);
        renderTriangle(tri, sp);
    }
}

static void clearTexturedObject(TexturedObject& o)
{
    ProjectedPoint sp[3];
    for (int tdi = 0; tdi < o.mesh.triCount; tdi++)
    {
        TexTriangle3d tri;
        tri.triangle.p1 = o.points[o.mesh.tris[tdi].p1];
        tri.triangle.p2 = o.points[o.mesh.tris[tdi].p2];
        tri.triangle.p3 = o.points[o.mesh.tris[tdi].p3];
        tri.texIndex = 0;
        clearTriangle(tri, sp);
    }
}

#endif // ITEX

#endif // INC_RENDER_H

