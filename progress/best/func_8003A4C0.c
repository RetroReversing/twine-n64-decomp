typedef union { struct { u32 w0; u32 w1; } words; long long force_structure_alignment; } Gfx;
typedef struct {
  u8 pad0[8];
  u32 tex;
  u32 pal;
  u8 pad10[8];
  s32 f18;
  u8 pad1C[2];
  u16 flags;
  u16 x;
  u16 y;
  u16 w;
  u16 cw;
  u8 h;
  u8 ch;
  u8 rc;
  u8 pad2B;
} Spr;
#define ROWS(p) ((s32)((*(u32 *)&(p)->h >> 12) & 0xF))
#define COLS(p) ((s32)((*(u32 *)&(p)->h >> 8) & 0xF))
extern s8 D_800E176D;
extern s32 gHiResScreen;
extern Gfx *sDisplayListCursor;
void func_80039A10(Gfx **, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, f32, f32);
void func_80039EFC(Gfx **, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, f32, f32);

#define _SHIFTL(v, s, w) ((u32)(((u32)(v) & ((0x01 << (w)) - 1)) << (s)))
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define TXL2WORDS_4b(txls) MAX(1, ((txls)/16))
#define CALC_DXT_4b(width) (((1 << 11) + TXL2WORDS_4b(width) - 1) / TXL2WORDS_4b(width))
#define PKT (sDisplayListCursor++)
#define gRaw(pkt, a, b) { Gfx *_g = (Gfx *)(pkt); _g->words.w0 = (a); _g->words.w1 = (b); }
#define gSetImage(pkt, cmd, fmt, siz, width, i) \
{ Gfx *_g = (Gfx *)(pkt); \
  _g->words.w0 = _SHIFTL(cmd, 24, 8) | _SHIFTL(fmt, 21, 3) | _SHIFTL(siz, 19, 2) | _SHIFTL((width)-1, 0, 12); \
  _g->words.w1 = (u32)(i); }
#define gDPSetTile(pkt, fmt, siz, line, tmem, tile, palette, cmt, maskt, shiftt, cms, masks, shifts) \
{ Gfx *_g = (Gfx *)(pkt); \
  _g->words.w0 = _SHIFTL(0xF5, 24, 8) | _SHIFTL(fmt, 21, 3) | _SHIFTL(siz, 19, 2) | _SHIFTL(line, 9, 9) | _SHIFTL(tmem, 0, 9); \
  _g->words.w1 = _SHIFTL(tile, 24, 3) | _SHIFTL(palette, 20, 4) | _SHIFTL(cmt, 18, 2) | _SHIFTL(maskt, 14, 4) | \
                 _SHIFTL(shiftt, 10, 4) | _SHIFTL(cms, 8, 2) | _SHIFTL(masks, 4, 4) | _SHIFTL(shifts, 0, 4); }
#define gDPNoParam(pkt, cmd) { Gfx *_g = (Gfx *)(pkt); _g->words.w0 = _SHIFTL(cmd, 24, 8); _g->words.w1 = 0; }
#define gDPLoadBlock(pkt, tile, uls, ult, lrs, dxt) \
{ Gfx *_g = (Gfx *)(pkt); \
  _g->words.w0 = (_SHIFTL(0xF3, 24, 8) | _SHIFTL(uls, 12, 12) | _SHIFTL(ult, 0, 12)); \
  _g->words.w1 = (_SHIFTL(tile, 24, 3) | _SHIFTL((MIN(lrs, 2047)), 12, 12) | _SHIFTL(dxt, 0, 12)); }
#define gDPSetTileSize(pkt, t, uls, ult, lrs, lrt) \
{ Gfx *_g = (Gfx *)(pkt); \
  _g->words.w0 = _SHIFTL(0xF2, 24, 8) | _SHIFTL(uls, 12, 12) | _SHIFTL(ult, 0, 12); \
  _g->words.w1 = _SHIFTL(t, 24, 3) | _SHIFTL(lrs, 12, 12) | _SHIFTL(lrt, 0, 12); }
#define gImmp1(pkt, c, p0) { Gfx *_g = (Gfx *)(pkt); _g->words.w0 = _SHIFTL((c), 24, 8); _g->words.w1 = (u32)(p0); }
#define gDPLoadTextureBlock_4b(pkt, timg, fmt, width, height, pal, cms, cmt, masks, maskt, shifts, shiftt) \
{ gSetImage(pkt, 0xFD, fmt, 2, 1, timg); \
  gDPSetTile(pkt, fmt, 2, 0, 0, 7, 0, cmt, maskt, shiftt, cms, masks, shifts); \
  gDPNoParam(pkt, 0xE6); \
  gDPLoadBlock(pkt, 7, 0, 0, (((width)*(height)+3)>>2)-1, CALC_DXT_4b(width)); \
  gDPNoParam(pkt, 0xE7); \
  gDPSetTile(pkt, fmt, 0, ((((width)>>1)+7)>>3), 0, 0, pal, cmt, maskt, shiftt, cms, masks, shifts); \
  gDPSetTileSize(pkt, 0, 0, 0, ((width)-1) << 2, ((height)-1) << 2) }
#define SCIS_ADJ(l, d) (((s16)(l) < 0) ? (((s16)(d) < 0) ? MAX(((s16)(l) * (s16)(d)) >> 7, 0) : MIN(((s16)(l) * (s16)(d)) >> 7, 0)) : 0)
#define SCIS_ADJY(c, l, d) (((c) < 0) ? (((s16)(d) < 0) ? MAX(((s16)(l) * (s16)(d)) >> 7, 0) : MIN(((s16)(l) * (s16)(d)) >> 7, 0)) : 0)
#define gSPScisTexRect(pkt, xl, yl, xh, yh, tile, s, t, dsdx, dtdy, ycond) \
{ Gfx *_g = (Gfx *)(pkt); \
  _g->words.w0 = (_SHIFTL(0xE4, 24, 8) | _SHIFTL(MAX((s16)(xh), 0), 12, 12) | _SHIFTL(MAX((s16)(yh), 0), 0, 12)); \
  _g->words.w1 = (_SHIFTL(tile, 24, 3) | _SHIFTL(MAX((s16)(xl), 0), 12, 12) | _SHIFTL(MAX((s16)(yl), 0), 0, 12)); \
  gImmp1(pkt, 0xE1, _SHIFTL((s) - SCIS_ADJ(xl, dsdx), 16, 16) | _SHIFTL((t) - SCIS_ADJY(ycond, yl, dtdy), 0, 16)); \
  gImmp1(pkt, 0xF1, (_SHIFTL(dsdx, 16, 16) | _SHIFTL(dtdy, 0, 16))); }
#define gSPScisTexRectHi(pkt, xl, yl, xh, yh, tile, s, t, dsdx, dtdy, ycond) gSPScisTexRect(pkt, xl, yl, xh, yh, tile, s, t, dsdx, dtdy, ycond)

void func_8003A4C0(s32 arg0, s32 arg1, Spr *spr)
{
  s32 __repair_tx_arm;
  u16 __repair_ty_u16;
  s32 fmt;
  u32 limit;
  s32 dsdx, dtdy, s, t;
  u16 i, j;
  s32 tx, ty, ly, ny;
  if (spr->f18 != 0 || (spr->cw != 0 && spr->ch != 0))
  {
    if (spr->flags & 2)
    {
      fmt = 4;
      if (spr->flags & 0x4000)
      {
        if (D_800E176D == 1)
        {
          D_800E176D = 0;
          gRaw(PKT, 0xE200001C, 0x504340);
        }
      }
      else if (D_800E176D == 0)
      {
        D_800E176D = 1;
        gRaw(PKT, 0xE200001C, 0x5040C0);
      }
      gRaw(PKT, 0xE3001001, 0);
      gRaw(PKT, 0xFC30B261, 0x5566FF7F);
      limit = 0x2000;
    }
    else
    {
      fmt = 2;
      gRaw(PKT, 0xFD100000, spr->pal);
      gRaw(PKT, 0xE8000000, 0);
      gRaw(PKT, 0xF5000100, 0x07000000);
      gRaw(PKT, 0xE6000000, 0);
      gRaw(PKT, 0xF0000000, 0x0703C000);
      gRaw(PKT, 0xE7000000, 0);
      gRaw(PKT, 0xE3001001, 0x8000);
      gRaw(PKT, 0xFC119623, 0xFF2FFFFF);
      limit = 0x1000;
    }
    if (limit < spr->w * spr->h)
    {
      if (spr->cw == spr->w && spr->ch == spr->h)
      {
        func_80039A10(&sDisplayListCursor, spr->tex, fmt, 0, spr->cw, spr->h, 0x20, 0x40, 0, 0, spr->w, spr->h, (f32) (spr->x + arg0), (f32) (spr->y + arg1));
      }
      else
      {
        func_80039EFC(&sDisplayListCursor, spr->tex, fmt, 0, spr->w, spr->h, spr->cw, spr->ch, 0x20, 0x40, 0, 0, spr->w, spr->h, (f32) (spr->x + arg0), (f32) (spr->y + arg1));
      }
      return;
    }
    if (gHiResScreen != 0) { dsdx = 0x400; dtdy = 0x200; } else { dsdx = 0x400; dtdy = 0x400; }
    dsdx = (dsdx * spr->w) / spr->cw;
    dtdy = (dtdy * spr->h) / spr->ch;
    s = spr->w << 5;
    if (spr->flags & 0x80)
      dsdx = ~dsdx;
    else
      s = 0;
    t = 0;
    if (spr->flags & 0x100)
    {
      dtdy = ~dtdy;
      t = spr->h << 5;
    }
    gDPLoadTextureBlock_4b(PKT, spr->tex, fmt, spr->w, spr->h, 0, 3, 3, 0, 0, 0, 0);
    for (i = 0; i < ROWS(spr); i++)
    {
      for (j = 0; j < COLS(spr); j++)
      {
        tx = spr->x + arg0 + spr->cw * i;
        ty = spr->y + spr->ch * j; __repair_ty_u16 = ty;
        if (gHiResScreen != 0)
        {
__repair_tx_arm = tx;
          if (spr->flags & 4)
            ly = ty + arg1;
          else
            ly = arg1 + (__repair_ty_u16) * 2;
          gSPScisTexRectHi(PKT, (s16) (__repair_tx_arm * 4), ly * 4, (__repair_tx_arm + spr->cw) * 4, (ly + spr->ch * 2) * 4, 0, s, t, dsdx, dtdy, (__repair_ty_u16) * 8);
        }
        else
        {
          ny = ty + arg1;
          gSPScisTexRect(PKT, (s16) (tx * 4), ny * 4, (tx + spr->cw) * 4, (ny + spr->ch) * 4, 0, s, t, dsdx, dtdy, ((__repair_ty_u16 + arg1) * 4));
        }
      }
    }
    gRaw(PKT, 0xE8000000, 0);
  }
}
