// Font Drawing Routines.
#ifndef INC_FONTS_H
#define INC_FONTS_H

#include <PIXEL.H>
#include <CANVAS.H>
#include <stdarg.h>
#include "FTDEF.H"

// ---------------------------------------------------------------------------
//  Low-level: single glyph rasteriser
// ---------------------------------------------------------------------------

static void dispChar(const byte arr[FONT_CHAR_WIDTH], int x = 0, int y = 0, int color = WHITE, int size = 1)
{
    int i, j, k, p, q;
    for (i = 0; i < FONT_CHAR_WIDTH; i++)
    {
        for (j = 128, k = 0; k < FONT_CHAR_WIDTH; k++, j /= 2)
        {
            if (arr[i] & j)
            {
                for (p = 0; p < size; p++)
                    for (q = 0; q < size; q++)
                        putPixel(x + (k * size) + q, y + (i * size) + p, color);
            }
        }
    }
}

// ---------------------------------------------------------------------------
//  Always-available UTF-8 decoder (shared by all rendering paths)
// ---------------------------------------------------------------------------

static unsigned long _utf8Decode(const unsigned char **src)
{
    const unsigned char *s = *src;
    unsigned long cp;
    if (!s || !*s) return 0xFFFFFFFF;
    if ((s[0] & 0x80) == 0) {
        cp = s[0];
        *src += 1;
    } else if ((s[0] & 0xE0) == 0xC0 && (s[1] & 0xC0) == 0x80) {
        cp = ((unsigned long)(s[0] & 0x1F) << 6) | (s[1] & 0x3F);
        *src += 2;
    } else if ((s[0] & 0xF0) == 0xE0 && (s[1] & 0xC0) == 0x80
               && (s[2] & 0xC0) == 0x80) {
        cp = ((unsigned long)(s[0] & 0x0F) << 12)
           | ((unsigned long)(s[1] & 0x3F) << 6)
           | (s[2] & 0x3F);
        *src += 3;
    } else if ((s[0] & 0xF8) == 0xF0 && (s[1] & 0xC0) == 0x80
               && (s[2] & 0xC0) == 0x80 && (s[3] & 0xC0) == 0x80) {
        cp = ((unsigned long)(s[0] & 0x07) << 18)
           | ((unsigned long)(s[1] & 0x3F) << 12)
           | ((unsigned long)(s[2] & 0x3F) << 6)
           | (s[3] & 0x3F);
        *src += 4;
    } else {
        return 0xFFFFFFFF;
    }
    return cp;
}

// ---------------------------------------------------------------------------
//  UTF-8 rendering path (decodes input, works with any 8x8 bitmap font)
//  Codepoints 0-255 -> font.chars[] lookup
//  Codepoints >255  -> '?' fallback
// ---------------------------------------------------------------------------

static void _drawStringWithSize(const font& userFont, const char text[], int x = 0, int y = 0, int color = WHITE, int size = 1)
{
    const unsigned char *p = (const unsigned char *)text;
    int curX = x;
    while (*p) {
        unsigned long cp = _utf8Decode(&p);
        if (cp > 255) continue;                     // beyond 8x8 font
        dispChar(userFont.chars[(int)cp], curX, y, color, size);
        curX += FONT_CHAR_WIDTH * size;
    }
}

// ---------------------------------------------------------------------------
//  Codepage rendering path (raw byte values, no UTF-8 decoding)
// ---------------------------------------------------------------------------

static void _drawStringCPWithSize(const font& userFont, const char text[], int x = 0, int y = 0, int color = WHITE, int size = 1)
{
    int i;
    for (i = 0; text[i] != 0; i++)
        dispChar(userFont.chars[(unsigned char)text[i]], x + (i * size * FONT_CHAR_WIDTH), y, color, size);
}

static void _drawPrintfWithSize(const font& userFont, int x, int y, int color, int size, const char* fmt, ...)
{
    char buf[128];
    va_list ap;
    va_start(ap, fmt);
    vsprintf(buf, fmt, ap);
    va_end(ap);
    _drawStringWithSize(userFont, buf, x, y, color, size);
}

static void _drawPrintfCPWithSize(const font& userFont, int x, int y, int color, int size, const char* fmt, ...)
{
    char buf[128];
    va_list ap;
    va_start(ap, fmt);
    vsprintf(buf, fmt, ap);
    va_end(ap);
    _drawStringCPWithSize(userFont, buf, x, y, color, size);
}

// --------------------------------------------------------------------------
//  Unicode extension -- FontDesc, combining marks, RTL, text width
//  Include FTARK.H / FTUNI.H (or individual FTARKXX.H / FTUNIXX.H) for data.
//  Define CUSTOM_FONT_CHAIN + _fontChain[] + FONT_CHAIN_COUNT to override.
//  Define NO_UNICODE to exclude this entire block (saves space on DOS).
// --------------------------------------------------------------------------

// GlyphRange and FontDesc are in FTDEF.H (included above)

#ifndef CUSTOM_FONT_CHAIN
// Default chain is empty.  Include FTARK.H / FTUNI.H before FONTS.H to add
// Unicode font data, or define CUSTOM_FONT_CHAIN + _fontChain[] yourself.
// Without font data, _drawString falls back to the 8x8 DEFAULT_FONT.
static const struct FontDesc *_fontChain[] = { NULL };
#define FONT_CHAIN_COUNT 0
#endif

//  Combining range lookup table (sorted for binary search)

static const struct { unsigned long lo, hi; } _combRanges[] = {
    { 0x0300, 0x036F }, { 0x0900, 0x0903 }, { 0x093A, 0x094D },
    { 0x0951, 0x0957 }, { 0x0962, 0x0963 }, { 0x0981, 0x0983 },
    { 0x09BC, 0x09BC }, { 0x09BE, 0x09C4 }, { 0x09C7, 0x09C8 },
    { 0x09CB, 0x09CD }, { 0x09D7, 0x09D7 }, { 0x09E2, 0x09E3 },
    { 0x0A01, 0x0A03 }, { 0x0A3C, 0x0A3C }, { 0x0A3E, 0x0A42 },
    { 0x0A47, 0x0A48 }, { 0x0A4B, 0x0A4D }, { 0x0A70, 0x0A71 },
    { 0x0A81, 0x0A83 }, { 0x0ABC, 0x0ABC }, { 0x0ABE, 0x0AC5 },
    { 0x0AC7, 0x0AC9 }, { 0x0ACB, 0x0ACD }, { 0x0AE2, 0x0AE3 },
    { 0x0B01, 0x0B03 }, { 0x0B3C, 0x0B3C }, { 0x0B3E, 0x0B43 },
    { 0x0B47, 0x0B48 }, { 0x0B4B, 0x0B4D }, { 0x0B56, 0x0B57 },
    { 0x0B62, 0x0B63 }, { 0x0B82, 0x0B82 }, { 0x0BBE, 0x0BC2 },
    { 0x0BC6, 0x0BC8 }, { 0x0BCA, 0x0BCD }, { 0x0BD7, 0x0BD7 },
    { 0x0C01, 0x0C03 }, { 0x0C3E, 0x0C44 }, { 0x0C46, 0x0C48 },
    { 0x0C4A, 0x0C4D }, { 0x0C55, 0x0C56 }, { 0x0C62, 0x0C63 },
    { 0x0C82, 0x0C83 }, { 0x0CBC, 0x0CBC }, { 0x0CBE, 0x0CC4 },
    { 0x0CC6, 0x0CC8 }, { 0x0CCA, 0x0CCD }, { 0x0CD5, 0x0CD6 },
    { 0x0CE2, 0x0CE3 }, { 0x0D02, 0x0D03 }, { 0x0D3E, 0x0D43 },
    { 0x0D46, 0x0D48 }, { 0x0D4A, 0x0D4D }, { 0x0D57, 0x0D57 },
    { 0x0D62, 0x0D63 }, { 0x0D82, 0x0D83 }, { 0x0DCA, 0x0DCA },
    { 0x0DCF, 0x0DD4 }, { 0x0DD6, 0x0DD6 }, { 0x0DD8, 0x0DDF },
    { 0x0DF2, 0x0DF3 }, { 0x0E31, 0x0E31 }, { 0x0E34, 0x0E3A },
    { 0x0E47, 0x0E4E }, { 0x1DC0, 0x1DFF }, { 0x20D0, 0x20FF },
    { 0xFE20, 0xFE2F },
};

static int isCombining(unsigned long cp)
{
    int lo = 0, hi = (int)(sizeof(_combRanges) / sizeof(_combRanges[0])) - 1;
    while (lo <= hi) {
        int mid = (lo + hi) / 2;
        if (cp < _combRanges[mid].lo)      hi = mid - 1;
        else if (cp > _combRanges[mid].hi) lo = mid + 1;
        else return 1;
    }
    return 0;
}

static int isRTL(unsigned long cp)
{
    return (cp >= 0x0590 && cp <= 0x05FF) ||  // Hebrew
           (cp >= 0x0600 && cp <= 0x06FF) ||  // Arabic
           (cp >= 0x0700 && cp <= 0x074F) ||  // Syriac
           (cp >= 0x0750 && cp <= 0x077F) ||  // Arabic Supplement
           (cp >= 0x08A0 && cp <= 0x08FF) ||  // Arabic Extended-A
           (cp >= 0xFB50 && cp <= 0xFDFF) ||  // Arabic Pres. Forms-A
           (cp >= 0xFE70 && cp <= 0xFEFF);     // Arabic Pres. Forms-B
}

static int detectRTL(const unsigned char *text)
{
    const unsigned char *p = text;
    int rtlCount = 0, ltrCount = 0;
    while (*p && rtlCount + ltrCount < 20) {
        unsigned long cp = _utf8Decode(&p);
        if (cp == 0xFFFFFFFF) break;
        if (isRTL(cp)) rtlCount++;
        else if (cp > 0x7F) ltrCount++;
    }
    return rtlCount > ltrCount;
}

//  Forward declarations

static void             renderCp(const struct FontDesc *const *chain, int chainLen, unsigned long cp, int x, int y, int color, int scale);
static void             renderTofu(int x, int y, int color, int scale, int cellH, int cellW);
static const unsigned char *findGlyph(const struct FontDesc *const *chain, int chainLen, unsigned long cp, int *outW);
static void             renderGlyphData(const unsigned char *glyphData, int x, int y, int color, int scale, int cellH);

// Macros for common codepoint checks (faster than function calls)
#define isCpControl(cp)   ((cp) <= 0x1F || ((cp) >= 0x7F && (cp) <= 0x9F))
#define isCpSpace(cp)     ((cp) == ' ' || (cp) == 0xA0)
#define isCpZero(cp)      ((cp) == 0x00AD || (cp) == 0x200C || (cp) == 0x200D)
#define cpAdvance(fa, g, m)  ((fa) > 0 ? (fa) : (g) ? (g) : (m))

static int _drawStringUnicode(int x, int y, int color,
                               const unsigned char *utf8Text,
                               int fixedAdvance, int scale,
                               const struct FontDesc *const *chain,
                               int chainLen)
{
    const struct FontDesc *f0 = chain[0];
    const unsigned char *p = utf8Text;
    int curX = x, curY = y, baseX = x;
    int pendingCombine = 0;
    int mul = scale > 0 ? scale : 1;
    int spaceAdv = f0->cellW * mul;
    int rtl = detectRTL(utf8Text);

    // RTL pre-pass: calculate total advance
    if (rtl) {
        int total = 0;
        p = utf8Text;
        while (*p) {
            unsigned long cp = _utf8Decode(&p);
            if (isCpControl(cp) || isCpZero(cp) || isCombining(cp)) continue;
            int gw;
            if (isCpSpace(cp))
                total += spaceAdv;
            else if (findGlyph(chain, chainLen, cp, &gw))
                total += cpAdvance(fixedAdvance, gw, 0) * mul;
            else
                total += cpAdvance(fixedAdvance, 0, f0->maxW) * mul;
        }
        curX = x + total;
        baseX = curX;
    }

    p = utf8Text;
    while (*p) {
        unsigned long cp = _utf8Decode(&p);

        if (isCpControl(cp)) {
            if (cp == '\t' && !pendingCombine)
                curX += rtl ? -spaceAdv * 4 : spaceAdv * 4;
            if (cp == '\n') { curX = x; curY += f0->cellH * mul; }
            continue;
        }

        if (cp == 0x200C) { pendingCombine = 0; continue; }
        if (cp == 0x200D) { pendingCombine = 1; continue; }
        if (isCpSpace(cp)) {
            if (!pendingCombine) {
                int sp = cpAdvance(fixedAdvance, 0, f0->cellW) * mul;
                curX += rtl ? -sp : sp;
            }
            continue;
        }
        if (cp == 0x00AD) continue;

        if (isCombining(cp)) { renderCp(chain, chainLen, cp, baseX, curY, color, mul); continue; }

        {
            int gw;
            const unsigned char *gd = findGlyph(chain, chainLen, cp, &gw);
            int adv = cpAdvance(fixedAdvance, gw, f0->maxW) * mul;
            if (rtl) curX -= adv;
            if (gd) {
                renderGlyphData(gd, curX, curY, color, mul, f0->cellH);
                baseX = curX;
            } else {
                renderTofu(curX, curY, color, mul, f0->cellH, f0->maxW);
                baseX = curX;
            }
            if (!rtl && !pendingCombine) curX += adv;
        }
        pendingCombine = 0;
    }
    return rtl ? x : curX;
}

static int _textWidth(const struct FontDesc *const *chain, int chainLen,
                       const char *text, int scale)
{
    const struct FontDesc *f0 = chain[0];
    const unsigned char *p = (const unsigned char *)text;
    int total = 0, mul = scale > 0 ? scale : 1;
    while (*p) {
        unsigned long cp = _utf8Decode(&p);
        if (isCpControl(cp) || isCpZero(cp) || isCombining(cp)) continue;
        int gw;
        if (isCpSpace(cp))
            total += f0->cellW * mul;
        else if (findGlyph(chain, chainLen, cp, &gw))
            total += gw * mul;
        else
            total += f0->maxW * mul;
    }
    return total;
}

static void _drawString(const font& f, const char text[], int x = 0, int y = 0, int color = WHITE)
{
    if (FONT_CHAIN_COUNT == 0 || _fontChain[0] == NULL)
        _drawStringWithSize(f, text, x, y, color, 1);
    else
        _drawStringUnicode(x, y, color, (const unsigned char *)text, 0, 1,
                           _fontChain, FONT_CHAIN_COUNT);
}

static void _drawStringScaled(const font& f, int size, const char text[], int x = 0, int y = 0, int color = WHITE)
{
    if (FONT_CHAIN_COUNT == 0 || _fontChain[0] == NULL)
        _drawStringWithSize(f, text, x, y, color, size);
    else
        _drawStringUnicode(x, y, color, (const unsigned char *)text, 0, size,
                           _fontChain, FONT_CHAIN_COUNT);
}

static void _drawStringFixed(const font& f, const char text[], int x = 0, int y = 0, int color = WHITE)
{
    if (FONT_CHAIN_COUNT == 0 || _fontChain[0] == NULL)
        _drawStringWithSize(f, text, x, y, color, 1);
    else
        _drawStringUnicode(x, y, color, (const unsigned char *)text, _fontChain[0]->cellW, 1,
                           _fontChain, FONT_CHAIN_COUNT);
}

static void _drawPrintf(const font& f, int x, int y, int color, const char* fmt, ...)
{
    char buf[128];
    va_list ap;
    va_start(ap, fmt);
    vsprintf(buf, fmt, ap);
    va_end(ap);
    if (FONT_CHAIN_COUNT == 0 || _fontChain[0] == NULL)
        _drawStringWithSize(f, buf, x, y, color, 1);
    else
        _drawStringUnicode(x, y, color, (const unsigned char *)buf, 0, 1,
                           _fontChain, FONT_CHAIN_COUNT);
}

static void _drawPrintfFixed(const font& f, int x, int y, int color, const char* fmt, ...)
{
    char buf[128];
    va_list ap;
    va_start(ap, fmt);
    vsprintf(buf, fmt, ap);
    va_end(ap);
    if (FONT_CHAIN_COUNT == 0 || _fontChain[0] == NULL)
        _drawStringWithSize(f, buf, x, y, color, 1);
    else
        _drawStringUnicode(x, y, color, (const unsigned char *)buf, _fontChain[0]->cellW, 1,
                           _fontChain, FONT_CHAIN_COUNT);
}

//  Low-level helpers

static void renderCp(const struct FontDesc *const *chain, int chainLen,
                      unsigned long cp, int x, int y, int color, int scale)
{
    int gw;
    const unsigned char *gd = findGlyph(chain, chainLen, cp, &gw);
    if (gd) renderGlyphData(gd, x, y, color, scale, chain[0]->cellH);
}

static void renderTofu(int x, int y, int color, int scale, int cellH, int cellW)
{
    int i, j, p, q;
    for (i = 0; i < cellH; i++)
        for (j = 0; j < cellW; j++)
            if (i == 0 || i == cellH - 1 ||
                j == 0 || j == cellW - 1)
                for (p = 0; p < scale; p++)
                    for (q = 0; q < scale; q++)
                        putPixel(x + j * scale + q, y + i * scale + p, color);
}

static const unsigned char *_scanRange(
    const unsigned char *data, int height,
    unsigned long start, unsigned long end,
    unsigned long codepoint, int *outWidth)
{
    unsigned long offset = codepoint - start;
    if (codepoint < start || codepoint > end) return NULL;
    const unsigned char *cursor = data;
    unsigned long o;
    for (o = 0; o < offset; o++) {
        int fl = cursor[0], w = cursor[1];
        if (w == 0) { cursor += 2; continue; }
        if (fl & 1) {
            int cx = 0, cy = 0;
            const unsigned char *rp = cursor + 2;
            while (cy < height) {
                int t = *rp++, oo = *rp++;
                cx += t + oo;
                if (cx >= w) { cx = 0; cy++; }
            }
            cursor = rp;
        } else {
            cursor += 2 + ((w + 7) / 8) * height;
        }
    }
    *outWidth = cursor[1];
    return cursor;
}

static const unsigned char *findGlyph(const struct FontDesc *const *chain,
                                       int chainLen, unsigned long cp,
                                       int *outW)
{
    int f, i;
    for (f = 0; f < chainLen; f++) {
        for (i = 0; i < chain[f]->rangeCount; i++) {
            const unsigned char *gd = _scanRange(
                chain[f]->ranges[i].data, chain[f]->ranges[i].height,
                chain[f]->ranges[i].start, chain[f]->ranges[i].end,
                cp, outW);
            if (gd) return gd;
        }
    }
    *outW = 0;
    return NULL;
}

static void renderGlyphData(const unsigned char *glyphData,
                             int x, int y,
                             int color, int scale, int cellH)
{
    int w, h, fl, i, j;
    if (!glyphData) return;
    fl = glyphData[0]; w = glyphData[1];
    if (w == 0) return;
    h = cellH;

    if (fl & 1) {
        const unsigned char *rp = glyphData + 2;
        int cx = 0, cy = 0;
        while (cy < h) {
            int t = *rp++, o = *rp++;
            cx += t + o;
            for (int px = cx - o; px < cx; px++) {
                int p, q;
                for (p = 0; p < scale; p++)
                    for (q = 0; q < scale; q++)
                        putPixel(x + px * scale + q, y + cy * scale + p, color);
            }
            if (cx >= w) { cx = 0; cy++; }
        }
    } else {
        int pitch = (w + 7) / 8;
        const unsigned char *bits = glyphData + 2;
        for (i = 0; i < h; i++)
            for (j = 0; j < w; j++)
                if (bits[i * pitch + j / 8] & (0x80 >> (j & 7))) {
                    int p, q;
                    for (p = 0; p < scale; p++)
                        for (q = 0; q < scale; q++)
                            putPixel(x + j * scale + q, y + i * scale + p, color);
                }
    }
}

// --------------------------------------------------------------------------
//  Macros -- inject DEFAULT_FONT for old-style calls
//  _drawString*   = UTF-8 input
//  _drawStringCP* = codepage (raw byte) input
// --------------------------------------------------------------------------

#define drawString(text, x, y, color)                 _drawString(DEFAULT_FONT, text, x, y, color)
#define drawStringScaled(text, x, y, color, sz)        _drawStringScaled(DEFAULT_FONT, sz, text, x, y, color)
#define drawStringFixed(text, x, y, color)            _drawStringFixed(DEFAULT_FONT, text, x, y, color)
#define drawStringCP(text, x, y, color)               _drawStringCP(DEFAULT_FONT, text, x, y, color)
#define drawStringWithSize(text, x, y, color, sz)     _drawStringWithSize(DEFAULT_FONT, text, x, y, color, sz)
#define drawStringCPWithSize(text, x, y, color, sz) _drawStringCPWithSize(DEFAULT_FONT, text, x, y, color, sz)
#define textWidth(text, sz)                            _textWidth(_fontChain, FONT_CHAIN_COUNT, text, sz)

// Variadic macros -- Borland C++ 4.52 does not support __VA_ARGS__
#ifndef __BORLANDC__
#define drawPrintf(x, y, color, ...)                _drawPrintf(DEFAULT_FONT, x, y, color, __VA_ARGS__)
#define drawPrintfFixed(x, y, color, ...)           _drawPrintfFixed(DEFAULT_FONT, x, y, color, __VA_ARGS__)
#define drawPrintfCP(x, y, color, ...)              _drawPrintfCP(DEFAULT_FONT, x, y, color, __VA_ARGS__)
#define drawPrintfWithSize(x, y, color, sz, ...)    _drawPrintfWithSize(DEFAULT_FONT, x, y, color, sz, __VA_ARGS__)
#define drawPrintfCPWithSize(x, y, color, sz, ...)  _drawPrintfCPWithSize(DEFAULT_FONT, x, y, color, sz, __VA_ARGS__)
#else
// Borland: simplified non-variadic wrappers (call _drawPrintf directly for variadic)
#define drawPrintf(x, y, color, fmt)                _drawPrintf(DEFAULT_FONT, x, y, color, fmt)
#define drawPrintfFixed(x, y, color, fmt)           _drawPrintfFixed(DEFAULT_FONT, x, y, color, fmt)
#define drawPrintfCP(x, y, color, fmt)              _drawPrintfCP(DEFAULT_FONT, x, y, color, fmt)
#define drawPrintfWithSize(x, y, color, sz, fmt)    _drawPrintfWithSize(DEFAULT_FONT, x, y, color, sz, fmt)
#define drawPrintfCPWithSize(x, y, color, sz, fmt)  _drawPrintfCPWithSize(DEFAULT_FONT, x, y, color, sz, fmt)
#endif

#endif
