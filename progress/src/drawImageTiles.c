extern f64 D_800D2EF0;
extern s32 gHiResScreen;
typedef struct { u32 w0; u32 w1; } Gfx;
#define SHIFTL(v, s, w) (((u32) (v) & ((1 << (w)) - 1)) << (s))
#define SETIMG(pkt, f, sz, w, i) { Gfx *_g = (pkt); _g->w0 = (SHIFTL(0xFD, 24, 8) | SHIFTL(f, 21, 3) | SHIFTL(sz, 19, 2) | SHIFTL((w) - 1, 0, 12)); _g->w1 = (u32) (i); }
#define SETTILE(pkt, f, sz, line, tmem, tile, pal, cmt, maskt, shiftt, cms, masks, shifts) { Gfx *_g = (pkt); _g->w0 = (SHIFTL(0xF5, 24, 8) | SHIFTL(f, 21, 3) | SHIFTL(sz, 19, 2) | SHIFTL(line, 9, 9) | SHIFTL(tmem, 0, 9)); _g->w1 = (SHIFTL(tile, 24, 3) | SHIFTL(pal, 20, 4) | SHIFTL(cmt, 18, 2) | SHIFTL(maskt, 14, 4) | SHIFTL(shiftt, 10, 4) | SHIFTL(cms, 8, 2) | SHIFTL(masks, 4, 4) | SHIFTL(shifts, 0, 4)); }
#define SYNC(pkt, op) { Gfx *_g = (pkt); _g->w0 = SHIFTL(op, 24, 8); _g->w1 = 0; }
#define TILECMD(pkt, op, t, uls, ult, lrs, lrt) { Gfx *_g = (pkt); _g->w0 = (SHIFTL(op, 24, 8) | SHIFTL(uls, 12, 12) | SHIFTL(ult, 0, 12)); _g->w1 = (SHIFTL(t, 24, 3) | SHIFTL(lrs, 12, 12) | SHIFTL(lrt, 0, 12)); }
#define IMM(pkt, op, a, b) { Gfx *_g = (pkt); _g->w0 = SHIFTL(op, 24, 8); _g->w1 = (a); }
#define TEXRECT(pkt, ulx, uly, lrx, lry, tile, s, t, dsdx, dtdy) { Gfx *_g = (pkt); _g->w0 = (SHIFTL(0xE4, 24, 8) | SHIFTL(lrx, 12, 12) | SHIFTL(lry, 0, 12)); _g->w1 = (SHIFTL(tile, 24, 3) | SHIFTL(ulx, 12, 12) | SHIFTL(uly, 0, 12)); } \
  { Gfx *_g = (pkt); _g->w0 = SHIFTL(0xE1, 24, 8); _g->w1 = (SHIFTL(s, 16, 16) | SHIFTL(t, 0, 16)); } \
  { Gfx *_g = (pkt); _g->w0 = SHIFTL(0xF1, 24, 8); _g->w1 = (SHIFTL(dsdx, 16, 16) | SHIFTL(dtdy, 0, 16)); }
/* Draws a source image region to the screen in tiles: each tile is loaded into TMEM and drawn with a texture rectangle. */
void drawImageTiles(Gfx **gfxp, u32 imageAddr, u32 format, s32 mode, u32 imageWidth, u32 unused, u32 tileW, u32 tileH, u32 srcX0, u32 srcY0, u32 srcX1, u32 srcY1, f32 destX, f32 destY)
{
  Gfx *g = *gfxp;
  s32 t;
  u32 y;
  for (y = srcY0, t = destY; y < srcY1; y += tileH, t += tileH)
  {
    u32 x;
    s32 s = destX;
    for (x = srcX0; x < srcX1; x += tileW, s += tileW)
    {
      s32 x0, y0;
      u32 x1, y1;
      s32 a, b, ulx, uly;
      f32 fx = (f32) (s32) x + 0.5, fy = (f32) (s32) y + 0.5;
      x0 = x - 1;
      if (x0 < 0) x0 = 0;
      x1 = x + tileW;
      if (x1 > srcX1 - 1) x1 = srcX1 - 1;
      y0 = y - 1;
      if (y0 < 0) y0 = 0;
      y1 = y + tileH;
      if (y1 > srcY1 - 1) y1 = srcY1 - 1;
      if (mode == 0)
      {
        s32 line = (((s32) (x1 - x0 + 1) >> 1) + 7) >> 3;
        SETIMG(g++, format, 1, imageWidth >> 1, imageAddr);
        SETTILE(g++, format, 1, line, 0, 7, 0, 2, 0, 0, 2, 0, 0);
        SYNC(g++, 0xE6);
        TILECMD(g++, 0xF4, 7, x0 * 2, y0 * 4, x1 * 2, y1 * 4);
        SYNC(g++, 0xE7);
        SETTILE(g++, format, 0, line, 0, 0, 0, 2, 0, 0, 2, 0, 0);
        TILECMD(g++, 0xF2, 0, x0 * 4, y0 * 4, x1 * 4, y1 * 4);
      }
      else
      {
        s32 line = ((s32) (x1 - x0 + 8)) >> 3;
        SETIMG(g++, format, 1, imageWidth, imageAddr);
        SETTILE(g++, format, 1, line, 0, 7, 0, 2, 0, 0, 2, 0, 0);
        SYNC(g++, 0xE6);
        TILECMD(g++, 0xF4, 7, x0 * 4, y0 * 4, x1 * 4, y1 * 4);
        SYNC(g++, 0xE7);
        SETTILE(g++, format, 1, line, 0, 0, 0, 2, 0, 0, 2, 0, 0);
        TILECMD(g++, 0xF2, 0, x0 * 4, y0 * 4, x1 * 4, y1 * 4);
      }
      a = s + tileW;
      if ((u32) (s + (srcX1 - x)) < (u32) a) a = s + (srcX1 - x);
      if (a >= 0x141) a = 0x140;
      b = t + tileH;
      if ((u32) (t + (srcY1 - y)) < (u32) b) b = t + (srcY1 - y);
      if (b >= 0xF1) b = 0xF0;
      a = a * 4; b = b * 4; ulx = s * 4; uly = t * 4;
      if (gHiResScreen != 0)
      {
        TEXRECT(g++, ulx, t * 8, a, b * 2, 0, (s32) (fx * 32.0f), (s32) (fy * 32.0f), 0x400, 0x200);
      }
      else
      {
        TEXRECT(g++, ulx, uly, a, b, 0, (s32) (fx * 32.0f), (s32) (fy * 32.0f), 0x400, 0x400);
      }
    }
  }
  *gfxp = g;
}
