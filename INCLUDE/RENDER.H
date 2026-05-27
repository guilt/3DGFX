// File That Draws 3D Objects.
#ifndef INC_RENDER_H
#define INC_RENDER_H
#include <PLATFORM.H>

#include <MATH3D.H>
#include <CANVAS.H>
#include <TEXTURE.H>
double xScale = 4.5, yScale = 4.5;
double thetaAngle = 0.0;

// Isometric Engine.
#ifdef IISO
double zScale = 2;
#define projPoint(ip)                                            \
    projected.x = (midX + (ip.x * xScale - ip.z * zScale) * 0.87); \
    projected.y = (midY + (ip.x * xScale + ip.z * zScale) * 0.5 - ip.y * yScale)
#define projPoint1(ip)                                            \
    projected1.x = (midX + (ip.x * xScale - ip.z * zScale) * 0.87); \
    projected1.y = (midY + (ip.x * xScale + ip.z * zScale) * 0.5 - ip.y * yScale)
#define projPoint2(ip)                                            \
    projected2.x = (midX + (ip.x * xScale - ip.z * zScale) * 0.87); \
    projected2.y = (midY + (ip.x * xScale + ip.z * zScale) * 0.5 - ip.y * yScale)
#define projSpherical(ip)                                                     \
    projected.x = (midX + (ip.r * cos(thetaAngle) * xScale - ip.z * zScale) * 0.87); \
    projected.y = (midY + (ip.r * cos(thetaAngle) * xScale + ip.z * zScale) * 0.5 -  \
            ip.r * sin(thetaAngle) * yScale)
#endif

// Default Non Isometric Engine.
#ifndef IISO
double zScale = 1.125;
#define projPoint(p)                 \
    projected.x = midX + p.x * xScale; \
    projected.y = midY - p.y * yScale; \
    projected.x -= p.z * zScale;       \
    projected.y += p.z * zScale
#define projPoint1(p)                 \
    projected1.x = midX + p.x * xScale; \
    projected1.y = midY - p.y * yScale; \
    projected1.x -= p.z * zScale;       \
    projected1.y += p.z * zScale
#define projPoint2(p)                 \
    projected2.x = midX + p.x * xScale; \
    projected2.y = midY - p.y * yScale; \
    projected2.x -= p.z * zScale;       \
    projected2.y += p.z * zScale
#define projSpherical(p)                          \
    projected.x = midX + p.r * cos(thetaAngle) * xScale; \
    projected.y = midY - p.r * sin(thetaAngle) * yScale; \
    projected.x -= p.z * zScale;                 \
    projected.y += p.z * zScale
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

void drawPoint(Point3d p, byte color = currentColor)
{
    projPoint(p);
    putPixel(projected.x, projected.y, color);
}

void drawPointC(Point3dc p, byte color = currentColor)
{
    thetaAngle = ((M_PI * p.o) / 180);
    projSpherical(p);
    putPixel(projected.x, projected.y, color);
}

void drawLine(Line3d l, byte color = currentColor)
{
    int tcolor = getColor();
    projPoint(l.p1);
    projPoint1(l.p2);
    setColor(color);
    drawLine(projected.x, projected.y, projected1.x, projected1.y);
    setColor(tcolor);
}

void drawTriangle(Triangle3d t, byte color = currentColor)
{
    Line3d l;
    l.p1 = t.p1, l.p2 = t.p2;
    drawLine(l, color);
    l.p1 = t.p2, l.p2 = t.p3;
    drawLine(l, color);
    l.p1 = t.p3, l.p2 = t.p1;
    drawLine(l, color);
}

void drawAxis(byte color = currentColor)
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

void contourPlot(Point3d p, byte color)
{
    if ((int(p.x * 1000) % 79 == 0) || (int(p.z * 1000) % 79 == 0))
    {
        drawPoint(p, color);
    }
}

void sphContourPlot(Point3d p, byte color, double oo, double pp)
{
    if (((int(oo) % 10) == 0) || ((int(pp) % 10) == 0))
    {
        drawPoint(p, color);
    }
}

void objectTranslate(Object3d& o, double x, double y, double z)
{
    int i;
    for (i = 0; i < o.pointCount; i++)
    {
        translate(o.points[i], x, y, z);
    }
}

void objectRotate(Object3d& o, int degx, int degy, int degz)
{
    int i;
    for (i = 0; i < o.pointCount; i++)
    {
        rotate(o.points[i], degx, degy, degz);
    }
}

int readObject(const char* fn, Object3d& o)
{
    char c;
    int i;
    fstream file;

    o.pointCount = 0;
    file.open(fn, ios::in);
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

void drawObject(Object3d o, byte color)
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

int16 *zbuffer;

void zBufferCreate()
{
    zbuffer = (int16*)malloc(ZMEM * sizeof(int16));
}

void zBufferClear()
{
    int32 i;
    for (i = 0; i < ZMEM; i++)
    {
        zbuffer[i] = -32768;
    }
}

#define zBufferTestAndSet(x, y, z, c) do { \
    int _off_ = (int)screenWidth * (int)(y) + (int)(x); \
    int16 _zc_ = (int16)(z) * ZPARAM; \
    if (_zc_ > zbuffer[_off_]) { \
        zbuffer[_off_] = _zc_; \
        putPixelFast(x, y, c); \
    } \
} while(0)

void zBufferDestroy()
{
    free(zbuffer);
}
#endif

// The Triangle Renderer.

#ifdef IZBUF
#endif

#define MIN(a, b) ((a < b) ? (a) : (b))
#define MAX(a, b) ((a > b) ? (a) : (b))

// Near and Far Clipping Planes.

#define Hither 30
#define Yon    -30

#define zclip(z)                          \
    (z <= 0) ? ((z <= Yon) ? z = Yon : z) \
             : ((z >= Hither) ? z = Hither : z)

ProjectedPoint tempPoint;
ProjectedPoint p1, p2, p3;

Texture FAR* tex = NULL;

struct TexTriangle3d
{
    Triangle3d triangle;
    int texIndex;
};

void sortVertices(ProjectedPoint& p1, ProjectedPoint& p2)
{
    if (p1.y > p2.y)
    {
        tempPoint = p1;
        p1 = p2;
        p2 = tempPoint;
    }
}

void texHLineFast(int x1, int x2, int y, int texIndex)
{
    int w = tex[texIndex].h.width;
    int h = tex[texIndex].h.height;
    for (int x = x1; x <= x2; x++)
        putPixelFast(x, y, tex[texIndex].data[x % w][h - 1 - (y % h)]);
}

void texHLine(int x1, int x2, int y, int texIndex, int u1, int v1, int u2, int v2)
{
    int w = tex[texIndex].h.width;
    int h = tex[texIndex].h.height;
    int dx = x2 - x1;
    int du = u2 - u1, dv = v2 - v1;
    for (int x = x1; x <= x2; x++)
    {
        int tu = dx ? (u1 + ((x - x1) * du / dx)) >> 8 : u1 >> 8;
        int tv = dx ? (v1 + ((x - x1) * dv / dx)) >> 8 : v1 >> 8;
        tu = (tu % w + w) % w;
        tv = (tv % h + h) % h;
#ifdef IZBUF
        zBufferTestAndSet(x, y, 0, tex[texIndex].data[tu][h - 1 - tv]);
#else
        putPixelFast(x, y, tex[texIndex].data[tu][h - 1 - tv]);
#endif
    }
}

void clearHLine(int x1, int x2, int y)
{
    for (int x = x1; x <= x2; x++)
        putPixelFast(x, y, 0);
}

void clearTriangle(TexTriangle3d t)
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
    /*Plane Equation: Ax+By+Cz+D=0 */
    D = -x1 * (y2 * z3 - y3 * z2) - x2 * (y3 * z1 - y1 * z3) -
        x3 * (y1 * z2 - y2 * z1);
    if (D >= 0)
    {
#endif
        projPoint(t.triangle.p1);
        projPoint1(t.triangle.p2);
        projPoint2(t.triangle.p3);
        p1 = projected;
        p2 = projected1;
        p3 = projected2;
        sortVertices(p1, p2);
        sortVertices(p2, p3);
        sortVertices(p1, p2);
        xd1 = p2.x - p1.x;
        yd1 = p2.y - p1.y;
        xd2 = p3.x - p1.x;
        yd2 = p3.y - p1.y;
        if (yd1)
        {
            for (i = p1.y; i <= p2.y; i++)
            {
                Lx = p1.x + (((i - p1.y) * xd1) / yd1);
                Rx = p1.x + (((i - p1.y) * xd2) / yd2);
                clearHLine(MIN(Lx, Rx), MAX(Lx, Rx), i);
            }
        }
        xd1 = p3.x - p2.x;
        yd1 = p3.y - p2.y;
        if (yd1)
        {
            for (i = p2.y; i <= p3.y; i++)
            {
                Lx = p1.x + (((i - p1.y) * xd2) / yd2);
                Rx = p2.x + (((i - p2.y) * xd1) / yd1);
                clearHLine(MIN(Lx, Rx), MAX(Lx, Rx), i);
            }
        }
#ifdef IHSR
    }
#endif
}

void renderTriangle(TexTriangle3d t)
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
        projPoint(t.triangle.p1);
        projPoint1(t.triangle.p2);
        projPoint2(t.triangle.p3);
        p1 = projected;
        p2 = projected1;
        p3 = projected2;
        sortVertices(p1, p2);
        sortVertices(p2, p3);
        sortVertices(p1, p2);

        // UV from object-space X/Y, Q8.8 fixed-point
        int u1 = (int)(t.triangle.p1.x * 256), v1 = (int)(t.triangle.p1.y * 256);
        int u2 = (int)(t.triangle.p2.x * 256), v2 = (int)(t.triangle.p2.y * 256);
        int u3 = (int)(t.triangle.p3.x * 256), v3 = (int)(t.triangle.p3.y * 256);
        int du12 = u2 - u1, dv12 = v2 - v1;
        int du13 = u3 - u1, dv13 = v3 - v1;
        int du23 = u3 - u2, dv23 = v3 - v2;

        xd1 = p2.x - p1.x;
        yd1 = p2.y - p1.y;
        xd2 = p3.x - p1.x;
        yd2 = p3.y - p1.y;
        if (yd1)
        {
            for (i = p1.y; i <= p2.y; i++)
            {
                int dy = i - p1.y;
                Lx = p1.x + dy * xd1 / yd1;
                Rx = p1.x + dy * xd2 / yd2;
                int uL = u1 + dy * du12 / yd1, vL = v1 + dy * dv12 / yd1;
                int uR = u1 + dy * du13 / yd2, vR = v1 + dy * dv13 / yd2;
                if (Lx <= Rx)
                    texHLine(Lx, Rx, i, t.texIndex, uL, vL, uR, vR);
                else
                    texHLine(Rx, Lx, i, t.texIndex, uR, vR, uL, vL);
            }
        }
        xd1 = p3.x - p2.x;
        yd1 = p3.y - p2.y;
        if (yd1)
        {
            for (i = p2.y; i <= p3.y; i++)
            {
                int dy1 = i - p1.y, dy2 = i - p2.y;
                Lx = p1.x + dy1 * xd2 / yd2;
                Rx = p2.x + dy2 * xd1 / yd1;
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

// File That Can Draw Textured Objects.
TexTriangle3d tri, clearTri;

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

void objectTranslate(TexturedObject& o, double x, double y, double z)
{
    int i;
    for (i = 0; i < o.pointCount; i++)
    {
        translate(o.points[i], x, y, z);
    }
}

void objectRotate(TexturedObject& o, int degx, int degy, int degz)
{
    int i;
    for (i = 0; i < o.pointCount; i++)
    {
        rotate(o.points[i], degx, degy, degz);
    }
}

bool loadTexturedObjectInto(const char* fn, TexturedObject& o)
{
    char c;
    int i;
    fstream file;
    o.pointCount = 0;
    file.open(fn, ios::in);
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

void loadTextures(const char* fn)
{
    int i;
    fstream file;
    file.open(fn, ios::in);
    if (!file) return;
    file >> texNameCount;
    texNameCount %= MAX_TEXTURES + 1;
    for (i = 0; i < texNameCount; i++)
        file >> texNames[i];
    file.close();
    if (!tex) tex = new Texture[MAX_TEXTURES];
}

static byte texLoaded[MAX_TEXTURES];

void loadUsedTextures(TexturedObject& o)
{
    int loaded = 0;
    if (!tex) { tex = new Texture[MAX_TEXTURES]; memset(texLoaded, 0, MAX_TEXTURES); }
    for (int i = 0; i < o.mesh.triCount; i++)
    {
        int ti = o.mesh.tris[i].texIndex;
        if (ti >= 0 && ti < texNameCount && !texLoaded[ti])
        {
            texLoaded[ti] = 1;
            loadTextureInto(texNames[ti], tex[ti]);
            loaded = 1;
        }
    }
    if (loaded) initTextures();
}

void drawTexturedObject(TexturedObject& o)
{
    for (int tdi = 0; tdi < o.mesh.triCount; tdi++)
    {
        tri.triangle.p1 = o.points[o.mesh.tris[tdi].p1];
        tri.triangle.p2 = o.points[o.mesh.tris[tdi].p2];
        tri.triangle.p3 = o.points[o.mesh.tris[tdi].p3];
        tri.texIndex = o.mesh.tris[tdi].texIndex;
        renderTriangle(tri);
    }
}

void clearTexturedObject(TexturedObject& o)
{
    for (int tdi = 0; tdi < o.mesh.triCount; tdi++)
    {
        clearTri.triangle.p1 = o.points[o.mesh.tris[tdi].p1];
        clearTri.triangle.p2 = o.points[o.mesh.tris[tdi].p2];
        clearTri.triangle.p3 = o.points[o.mesh.tris[tdi].p3];
        clearTri.texIndex = 0;
        clearTriangle(clearTri);
    }
}

#endif

