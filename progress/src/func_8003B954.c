s32 decodeButtonMask840();
u32 func_80018080();
u32 func_800180D4();
void *func_80018510();
s32 func_80018578();
s32 func_8003FA78();
typedef union { struct { u32 w0; u32 w1; } words; long long force_structure_alignment; } Gfx;
typedef struct { u8 pad0[2]; u16 w; u16 h; u8 pad6[2]; u32 tex; } Ent;
typedef struct { u8 pad[0x18]; Ent *ents; } Res;
typedef struct { u8 *pairs; u8 pad4[0]; u8 n; } Kern;
typedef struct { u8 c0, c1, c2, c3; s8 c4; } Glyph;
typedef struct { u8 pad[0x148]; u8 lh; } GT;
typedef struct { u8 pad0[4]; s32 idx; GT *gt; u8 *kern; u8 space; s8 extra; } Font;
typedef struct { int v; } VI;
typedef struct { u8 *pairs; u8 n; } KE;
typedef struct { u8 pad[0x18]; u8 *text; u16 len; u16 flags; u16 x; u16 y; } Box;
extern u32 sMenuItemParamTable[];
extern u8 D_800C0738;
extern Res *D_800C0A24;
extern s32 D_800E1760;
extern u32 D_800E1764;
extern u16 D_800E1766;
extern s32 D_800E1768;
extern u8 *gSaveMenuState;
extern s32 gHiResScreen;
extern Gfx *sDisplayListCursor;

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
#define gSPTextureRectangle(pkt, xl, yl, xh, yh, tile, s, t, dsdx, dtdy) \
{ Gfx *_g = (Gfx *)(pkt); \
  _g->words.w0 = (_SHIFTL(0xE4, 24, 8) | _SHIFTL(xh, 12, 12) | _SHIFTL(yh, 0, 12)); \
  _g->words.w1 = (_SHIFTL(tile, 24, 3) | _SHIFTL(xl, 12, 12) | _SHIFTL(yl, 0, 12)); \
  gImmp1(pkt, 0xE1, (_SHIFTL(s, 16, 16) | _SHIFTL(t, 0, 16))); \
  gImmp1(pkt, 0xF1, (_SHIFTL(dsdx, 16, 16) | _SHIFTL(dtdy, 0, 16))); }
#define gDPSetPrimColor(pkt, m, l, r, g, b, a) \
{ Gfx *_g = (Gfx *)(pkt); \
  _g->words.w0 = (_SHIFTL(0xFA, 24, 8) | _SHIFTL(m, 8, 8) | _SHIFTL(l, 0, 8)); \
  _g->words.w1 = (_SHIFTL(r, 24, 8) | _SHIFTL(g, 16, 8) | _SHIFTL(b, 8, 8) | _SHIFTL(a, 0, 8)); }
#define gDPLoadTextureBlock_4b(pkt, timg, fmt, width, height, pal, cms, cmt, masks, maskt, shifts, shiftt) \
{ gSetImage(pkt, 0xFD, fmt, 2, 1, timg); \
  gDPSetTile(pkt, fmt, 2, 0, 0, 7, 0, cmt, maskt, shiftt, cms, masks, shifts); \
  gDPNoParam(pkt, 0xE6); \
  gDPLoadBlock(pkt, 7, 0, 0, (((width)*(height)+3)>>2)-1, CALC_DXT_4b(width)); \
  gDPNoParam(pkt, 0xE7); \
  gDPSetTile(pkt, fmt, 0, ((((width)>>1)+7)>>3), 0, 0, pal, cmt, maskt, shiftt, cms, masks, shifts); \
  gDPSetTileSize(pkt, 0, 0, 0, ((width)-1) << 2, ((height)-1) << 2) }

#define GL (&((Glyph *)font->gt)[t2])
#define ENT (res->ents[font->idx])
void func_8003B954(s32 ox, s32 oy, Box *box)
{
  s32 s0, t0; u16 dec, fl; s32 y3, ch2, nx, rem, dy, o, ya, prev = 0, y, w, ch, lh, e;
  u32 d, c, i, x, uw, k, t2;
  s32 g0, i5; Font *font; Res *res; u32 tex; s32 kv, a2k; void *a1p; u8 *pr;
  if (func_8003FA78(0x2A) << 24)
  {
    D_800E1764 = 0;
    D_800E1768 = 0;
    font = func_80018510(decodeButtonMask840(box->flags) & 0xFFFF);
    x = box->x;
    res = D_800C0A24;
    y = box->y;
    tex = ENT.tex;
    if (box->flags & 0x201)
    {
      uw = func_80018080(box);
      if (box->flags & 1) uw = uw >> 1;
      x -= uw;
    }
    gDPLoadTextureBlock_4b(PKT, tex, 4, ENT.w + 1, ENT.h + 1, 0, 3, 3, 0, 0, 0, 0);
    gRaw(PKT, 0xFC30B261, 0x5566FF7F);
    gRaw(PKT, 0xE3001001, 0);
    for (i = 0; i < box->len; i++)
    {
      ch = box->text[i];
      switch (ch)
      {
        case 9: if (ox) { x = ((x >> 4) + 1) << 4; break; } else { x = ((x >> 4) + 1) << 4; break; }
        case 1: i++; x = (s8)box->text[i] * 2; break;
        case 2: i++; w = (s8)box->text[i]; x += w; D_800E1760 += w; break;
        case 4: D_800E1768 = 0x12;
        case 3: i++; D_800E1764 = box->text[i] * 2; D_800E1760 = 0; break;
        case 6: i++; break;
        case 5:
          i++;
          if (!D_800C0738) {
            t2 = sMenuItemParamTable[(s8)box->text[i]];
            gDPSetPrimColor(PKT, 0, 0, t2 >> 24, t2 >> 16, t2 >> 8, t2);
          }
          break;
        case 7:
          i++;
          if (!D_800C0738) {
            t2 = (sMenuItemParamTable[box->text[i] & 0xF] & ~0xFF) | gSaveMenuState[0x30];
            gDPSetPrimColor(PKT, 0, 0, t2 >> 24, t2 >> 16, t2 >> 8, t2);
          }
          break;
        case 10:
          x = box->x; fl = box->flags; y += 3 + font->gt->lh; D_800E1760 = 0;
          if (fl & 1)
          { dec = decodeButtonMask840(fl); rem = box->len - 1; nx = i + 1; x -= func_800180D4(box->text + nx, (rem - i) & 0xFFFF, box->flags, dec, D_800E1766) >> 1; }
          break;
        case 32: w = font->space; x += w; D_800E1760 += w; break;
        default:
          if (D_800E1764 && D_800E1760 + (func_80018578(font, box->text + i) & 0xFFFF) >= D_800E1764)
          {
            fl = box->flags; y += 3 + font->gt->lh; D_800E1760 = 0;
            if (fl & 1)
            { dec = decodeButtonMask840(fl); x = box->x - (func_800180D4(box->text + i, (box->len - i) & 0xFFFF, box->flags, dec, D_800E1766) >> 1); }
            else
              x = box->x + D_800E1768;
          }
          ch2 = ch & 0xFF;
          t2 = ch2 - 0x21;
          if (font->kern != 0)
          {
            for (k = 0; k < ((KE *)font->kern)[prev].n; k++)
            {
              pr = (u8 *)(k * 2 + (s32)((KE *)font->kern)[prev].pairs);
              if (pr[0] == (ch & 0xFF)) { x -= (s8)pr[1]; break; }
            }
          }
          s0 = GL->c0 << 5; t0 = GL->c1 << 5; dy = GL->c4;
          if (gHiResScreen) {
              gSPTextureRectangle(PKT, (ox + x) * 4, (oy + ((y - dy) << 1)) * 4, (ox + (x + GL->c2)) * 4, ((oy + ((y - dy) << 1)) + GL->c3 * 2) * 4, 0, s0, t0, 0x400, 0x200);
          } else {
              gSPTextureRectangle(PKT, (ox + x) * 4, (oy + (y - dy)) * 4, (ox + x + GL->c2) * 4, ((oy + (y - dy)) + GL->c3) * 4, 0, s0, t0, 0x400, 0x400);
          }
          prev = t2;
          g0 = (s32)font->gt; i5 = t2 * 5; e = font->extra; w = ((Glyph *)(i5 + g0))->c2 + e;
          x += w;
          D_800E1760 += w;
          break;
      }
    }
    gDPNoParam(PKT, 0xE8);
  }
}
