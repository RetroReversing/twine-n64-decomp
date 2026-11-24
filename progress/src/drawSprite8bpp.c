s32 drawImageTiles(void **, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, f32, f32);
s32 drawScaledImageTiles(void **, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, f32, f32);
typedef union { struct { u32 w0; u32 w1; } words; long long force_structure_alignment; } Gfx;
extern s8 gSpriteFilterMode;
extern s32 gHiResScreen;
extern Gfx *sDisplayListCursor;
typedef struct {
  u8 pad0[8];
  u32 img;
  u32 pal;
  u8 pad10[14];
  u16 flags;
  u16 x;
  u16 y;
  u16 w;
  u16 tw;
  union {
    struct { u8 h; u8 th; } a;
    struct { unsigned pad:16; unsigned rows:4; unsigned cols:4; unsigned rest:8; } b;
  } u;
} Rec;
#define HH u.a.h
#define TH u.a.th
#define W28(r) (*(s32 *)((u8 *)(r) + 0x28))
#define _SHIFTL(v, s, w) ((u32)(((u32)(v) & ((0x01 << (w)) - 1)) << (s)))
#define gSetImage(pkt, cmd, fmt, siz, width, i) { Gfx *_g = (Gfx *)(pkt); _g->words.w0 = (_SHIFTL(cmd, 24, 8) | _SHIFTL(fmt, 21, 3) | _SHIFTL(siz, 19, 2) | _SHIFTL((width) - 1, 0, 12)); _g->words.w1 = (u32)(i); }
#define gDPSetTile(pkt, fmt, siz, line, tmem, tile, palette, cmt, maskt, shiftt, cms, masks, shifts) { Gfx *_g = (Gfx *)(pkt); _g->words.w0 = (_SHIFTL(0xF5, 24, 8) | _SHIFTL(fmt, 21, 3) | _SHIFTL(siz, 19, 2) | _SHIFTL(line, 9, 9) | _SHIFTL(tmem, 0, 9)); _g->words.w1 = (_SHIFTL(tile, 24, 3) | _SHIFTL(palette, 20, 4) | _SHIFTL(cmt, 18, 2) | _SHIFTL(maskt, 14, 4) | _SHIFTL(shiftt, 10, 4) | _SHIFTL(cms, 8, 2) | _SHIFTL(masks, 4, 4) | _SHIFTL(shifts, 0, 4)); }
#define gDPLoadBlock(pkt, tile, uls, ult, lrs, dxt) { Gfx *_g = (Gfx *)(pkt); _g->words.w0 = (_SHIFTL(0xF3, 24, 8) | _SHIFTL(uls, 12, 12) | _SHIFTL(ult, 0, 12)); _g->words.w1 = (_SHIFTL(tile, 24, 3) | _SHIFTL(MINL(lrs, 2047), 12, 12) | _SHIFTL(dxt, 0, 12)); }
#define gDPSetTileSize(pkt, t, uls, ult, lrs, lrt) { Gfx *_g = (Gfx *)(pkt); _g->words.w0 = (_SHIFTL(0xF2, 24, 8) | _SHIFTL(uls, 12, 12) | _SHIFTL(ult, 0, 12)); _g->words.w1 = (_SHIFTL(t, 24, 3) | _SHIFTL(lrs, 12, 12) | _SHIFTL(lrt, 0, 12)); }
#define MINL(a, b) (((a) < (b)) ? (a) : (b))
#define TXLW(x) ((x) ? (x) : 1)
#define CALC_DXT(w) ((0x800 + TXLW(w) - 1) / TXLW(w))
#define gDPLoadTextureBlock8(pkt, timg, fmt, width, height) \
{ \
  gSetImage(pkt, 0xFD, fmt, 2, 1, timg); \
  gDPSetTile(pkt, fmt, 2, 0, 0, 7, 0, 3, 0, 0, 3, 0, 0); \
  gDma(pkt, 0xE6000000, 0); \
  gDPLoadBlock(pkt, 7, 0, 0, (((width) * (height) + 1) >> 1) - 1, CALC_DXT((width) >> 3)); \
  gDma(pkt, 0xE7000000, 0); \
  gDPSetTile(pkt, fmt, 1, (((width) + 7) >> 3), 0, 0, 0, 3, 0, 0, 3, 0, 0); \
  gDPSetTileSize(pkt, 0, 0, 0, ((width) - 1) << 2, ((height) - 1) << 2); \
}
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define gImmp1(pkt, c, p0) { Gfx *_g = (Gfx *)(pkt); _g->words.w0 = _SHIFTL((c), 24, 8); _g->words.w1 = (u32)(p0); }
#define PKT (sDisplayListCursor++)
#define gDma(pkt, a, b) { Gfx *_g = (Gfx *)(pkt); _g->words.w0 = (a); _g->words.w1 = (b); }
#define SCIS_ADJ(l, d) (((s16)(l) < 0) ? (((s16)(d) < 0) ? MAX(((s16)(l) * (s16)(d)) >> 7, 0) : MIN(((s16)(l) * (s16)(d)) >> 7, 0)) : 0)
#define SCIS_ADJY(c, k, d) (((c) < 0) ? (((s16)(d) < 0) ? MAX(((s16)(k) * (s16)(d)) >> 7, 0) : MIN(((s16)(k) * (s16)(d)) >> 7, 0)) : 0)
#define gSPScisTexRect(pkt, xl, yl, xh, yh, tile, s, t, dsdx, dtdy, ycond, ycorr) \
{ Gfx *_g = (Gfx *)(pkt); \
  _g->words.w0 = (_SHIFTL(0xE4, 24, 8) | _SHIFTL(MAX((s16)(xh), 0), 12, 12) | _SHIFTL(MAX((s16)(yh), 0), 0, 12)); \
  _g->words.w1 = (_SHIFTL(tile, 24, 3) | _SHIFTL(MAX((s16)(xl), 0), 12, 12) | _SHIFTL(MAX((s16)(yl), 0), 0, 12)); \
  gImmp1(pkt, 0xE1, _SHIFTL((s) - SCIS_ADJ(xl, dsdx), 16, 16) | _SHIFTL((t) - SCIS_ADJY(ycond, ycorr, dtdy), 0, 16)); \
  gImmp1(pkt, 0xF1, (_SHIFTL(dsdx, 16, 16) | _SHIFTL(dtdy, 0, 16))); }
#define gSPScisTexRectHi(pkt, xl, yl, xh, yh, tile, s, t, dsdx, dtdy, ycond, ycorr) gSPScisTexRect(pkt, xl, yl, xh, yh, tile, s, t, dsdx, dtdy, ycond, ycorr)

/* Draws a sprite at an offset using 8-bit texel loading, emitting scissored texture rectangles, or delegating to the tiled draw helpers for large images. */ void drawSprite8bpp(s32 offsetX, s32 offsetY, Rec *r)
{
  s32 fmt;
  u32 limit;
  s32 dsdx, dtdy, s, t;
  u16 i, j;
  u16 __repair_tx_arm;
  u16 __repair_ty_u16;
  u16 ty; u16 ly;
  u16 tx;
  u16 __repair_tx_u16;
  s32 rows;
  if (r->flags & 2)
  {
    fmt = 4;
    if (r->flags & 0x4000)
    {
      if (gSpriteFilterMode == 1)
      {
        gSpriteFilterMode = 0;
        gDma(PKT, 0xE200001C, 0x504340);
      }
    }
    else if (gSpriteFilterMode == 0)
    {
      gSpriteFilterMode = 1;
      gDma(PKT, 0xE200001C, 0x5040C0);
    }
    gDma(PKT, 0xFC30B261, 0x5566FF7F);
    gDma(PKT, 0xE3001001, 0);
    limit = 0x1000;
  }
  else
  {
    fmt = 2;
    gDma(PKT, 0xFC119623, 0xFF2FFFFF);
    gDma(PKT, 0xE3001001, 0x8000);
    gDma(PKT, 0xFD100000, r->pal);
    gDma(PKT, 0xE8000000, 0);
    gDma(PKT, 0xF5000100, 0x07000000);
    gDma(PKT, 0xE6000000, 0);
    gDma(PKT, 0xF0000000, 0x073FC000);
    gDma(PKT, 0xE7000000, 0);
    limit = 0x800;
  }
  if (limit < r->w * r->HH)
  {
    if (r->tw == r->w && r->TH == r->HH)
    {
      drawImageTiles((void **) &sDisplayListCursor, r->img, 2, 1, r->tw, r->HH, 0x20, 0x20, 0, 0, r->w, r->HH, (f32) (r->x + offsetX), (f32) (r->y + offsetY));
      return;
    }
    drawScaledImageTiles((void **) &sDisplayListCursor, r->img, 2, 1, r->w, r->HH, r->tw, r->TH, 0x20, 0x20, 0, 0, r->w, r->HH, (f32) (r->x + offsetX), (f32) (r->y + offsetY));
    return;
  }
  if (gHiResScreen != 0)
  { dsdx = 0x400; dtdy = 0x200; }
  else
  { dsdx = 0x400; dtdy = 0x400; }
  dsdx = dsdx * r->w / r->tw;
  dtdy = dtdy * r->HH / r->TH;
  if (r->flags & 0x80)
  { s = r->w << 5; dsdx = ~dsdx; }
  else
    s = 0;
  t = 0;
  if (r->flags & 0x100)
  {
    dtdy = ~dtdy;
    t = r->HH << 5;
  }
  gDPLoadTextureBlock8(PKT, r->img, fmt, r->w, r->HH);
  for (i = 0; i < r->u.b.rows; i++)
  {
    for (j = 0; j < r->u.b.cols; j++)
    {
      tx = r->x + offsetX + r->tw * i; __repair_tx_u16 = tx;
      ty = r->y + r->TH * j; __repair_ty_u16 = ty;
      if (gHiResScreen != 0)
      {
        __repair_tx_arm = __repair_tx_u16;
        if (r->flags & 4)
          ly = ty + offsetY;
        else
          ly = offsetY + (__repair_ty_u16) * 2;
        gSPScisTexRectHi(PKT, (s16) (__repair_tx_arm << 2), ly << 2, (__repair_tx_u16 + r->tw) << 2, (ly + r->TH * 2) << 2, 0, s, t, dsdx, dtdy, (__repair_ty_u16) * 8, ly << 2);
      }
      else
      {
        gSPScisTexRect(PKT, tx << 2, (ty + offsetY) << 2, (tx + r->tw) << 2, (r->TH + (ty + offsetY)) << 2, 0, s, t, dsdx, dtdy, ((__repair_ty_u16 + offsetY) * 4), ((__repair_ty_u16 + offsetY) << 2));
      }
    }
  }
  gDma(PKT, 0xE8000000, 0);
}

