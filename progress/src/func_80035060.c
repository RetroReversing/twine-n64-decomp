typedef union { struct { u32 w0; u32 w1; } words; long long force_structure_alignment; } Gfx;
typedef struct { u8 pad0[0x50]; f32 x0, x1, y0, y1, ox, oy; u8 pad68[0x100 - 0x68]; s32 flags; u8 pad104[0x140 - 0x104]; s16 state; } Obj;
s32 func_80034EFC();
s32 osVirtualToPhysical(s32);
extern s32 D_80100304[];
extern u8 D_80100777;
extern u8 D_80100778;
extern u8 D_80100779;
extern u8 D_801007CF;
extern u8 D_801007D0;
extern u8 D_801007D1;
extern s32 D_80109A54;
extern s16 D_8010A4B0;
extern s32 D_8010A4EC[];
extern s16 D_8010D6F8;
extern s32 gBorderSkipActive[];
extern s32 gHiResScreen;
extern u8 gTrackMarkerActiveMask;
extern s32 gVisibleSaveSlotCount;
extern Gfx *sDisplayListCursor;
#define _SHIFTL(v, s, w) ((u32)(((u32)(v) & ((0x01 << (w)) - 1)) << (s)))
#define PKT (sDisplayListCursor++)
#define gDma(pkt, w0v, w1v) { Gfx *_g = (Gfx *)(pkt); _g->words.w0 = (w0v); _g->words.w1 = (w1v); }
#define gDPPipeSync(pkt) gDma(pkt, _SHIFTL(0xE7, 24, 8), 0)
#define gSetImage(pkt, cmd, fmt, siz, width, i) gDma(pkt, _SHIFTL(cmd, 24, 8) | _SHIFTL(fmt, 21, 3) | _SHIFTL(siz, 19, 2) | _SHIFTL((width)-1, 0, 12), (u32)(i))
#define gDPSetDepthImage(pkt, zb) gSetImage(pkt, 0xFE, 0, 0, 1, zb)
#define gDPSetColorImage(pkt, fmt, siz, width, i) gSetImage(pkt, 0xFF, fmt, siz, width, i)
#define gSPSetOtherMode(pkt, c, sft, len, data) gDma(pkt, _SHIFTL(c, 24, 8) | _SHIFTL(32 - (sft) - (len), 8, 8) | _SHIFTL((len) - 1, 0, 8), data)
#define gDPSetFillColor(pkt, d) gDma(pkt, _SHIFTL(0xF7, 24, 8), d)
#define gDPSetFillColorV(pkt, d) gDma(pkt, fillCmd, d)
#define gDPFillRectangle(pkt, ulx, uly, lrx, lry) gDma(pkt, _SHIFTL(0xF6, 24, 8) | _SHIFTL(lrx, 14, 10) | _SHIFTL(lry, 2, 10), _SHIFTL(ulx, 14, 10) | _SHIFTL(uly, 2, 10))
#define GPACK_RGBA5551(r, g, b, a) (((r) << 8) & 0xF800) | (((g) << 3) & 0x7C0)
void func_80035060(Obj *arg0)
{
  s32 ulx, uly, lrx, lry;
  u8 red, green, blue;
  u32 flg; u32 d; u32 color, c, t, rw0, rw1; s32 sz, mode; Gfx *gp;
  u32 fillCmd;
  if (arg0->flags & 0x40)
  {
    func_80034EFC(arg0);
    return;
  }
  ulx = (s32)(arg0->ox + arg0->x0);
  uly = (s32)(arg0->oy + arg0->y0);
  lrx = (s32)(arg0->ox + arg0->x1 - 1.0f);
  lry = (s32)(arg0->oy + arg0->y1 - 1.0f);
  gDPPipeSync(PKT);
  gDPSetDepthImage(PKT, osVirtualToPhysical(D_80109A54));
  gSPSetOtherMode(PKT, 0xE3, 20, 2, 0x300000);
  gSPSetOtherMode(PKT, 0xE2, 3, 29, 0x0F0A4000);
  gDPSetColorImage(PKT, 0, 2, D_8010D6F8, osVirtualToPhysical(D_80109A54));
  gp = sDisplayListCursor;
  rw0 = _SHIFTL(0xF6, 24, 8) | _SHIFTL(lrx, 14, 10) | _SHIFTL(lry, 2, 10);
  rw1 = _SHIFTL(ulx, 14, 10) | _SHIFTL(uly, 2, 10);
  fillCmd = _SHIFTL(0xF7, 24, 8);
  gp[0].words.w1 = 0xFFFCFFFC;
  gp[0].words.w0 = fillCmd;
  gp[1].words.w0 = rw0;
  gp[1].words.w1 = rw1;
  sDisplayListCursor++;
  mode = D_8010A4EC[0];
  sDisplayListCursor++;
  sz = 2;
  if (mode != 0) sz = ((-(gHiResScreen == 0)) & 3) | 2;
  gDma(PKT, 0xFF000000 | (sz << 0x13) | ((D_8010D6F8 - 1) & 0xFFF), osVirtualToPhysical(D_80100304[D_8010A4B0]));
  if (gBorderSkipActive[0])
  {
    if (arg0->state == 3 && gVisibleSaveSlotCount == arg0->state)
    {
      gDPSetFillColorV(PKT, 0);
      gDma(PKT, rw0, rw1);
      return;
    }
  }
  c = 0;
  if (!(arg0->flags & 0x20))
  {
    color = 0;
    if (D_8010A4EC[0])
    {
      if (arg0->flags & 2) color = (D_801007CF + D_801007D0 + D_801007D1) << 16;
      else
      {
        if (arg0->flags & 1) color = (D_801007CF << 24) + (D_801007D0 << 16) + (D_801007D1 << 8);
        else if (arg0->flags & 4) color = 0x4000;
        if (arg0->flags & 8) color = (D_80100777 << 24) + (D_80100778 << 16) + (D_80100779 << 8);
      }
    }
    else
    {
      if (arg0->flags & 2) c = (((D_801007CF + D_801007D0 + D_801007D1) / 3) * 8) & 0x7C0;
      else
      {
        if (arg0->flags & 1) { red = D_801007CF; green = D_801007D0; blue = D_801007D1; flg = ((red << 8) & 0xF800) | ((green << 3) & 0x7C0); c = ((blue >> 2) & 0x3E) | flg; }
        if (arg0->flags & 4) c = 0x10;
        if (arg0->flags & 8) { red = D_80100777; green = D_80100778; blue = D_80100779; d = ((red << 8) & 0xF800) | ((green << 3) & 0x7C0); c = ((blue >> 2) & 0x3E) | d; }
      }
      c |= 1;
      t = c & 0xFFFF;
      color = (t << 16) | t;
    }
    color &= -((arg0->flags & 0x40) == 0);
    if (gTrackMarkerActiveMask) gDPSetFillColor(PKT, color) else gDPSetFillColor(PKT, 0)
    gDPFillRectangle(PKT, ulx, uly, lrx, lry);
  }
}
