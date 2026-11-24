void emitFullScreenScissor(void);
typedef struct { u32 w0; u32 w1; } Gfx;
typedef struct { u8 pad0[0x58]; f32 f58; f32 f5C; u8 pad60[4]; f32 f64; u8 pad68[0x98]; u32 flags; } ViewInfo;
extern s16 gScreenHeight;
extern s16 gScreenWidth;
extern Gfx *sDisplayListCursor;
#define SHIFTL(v, s, w) (((u32)(v) & ((1 << (w)) - 1)) << (s))
#define CMD(a, b) { Gfx *_g = sDisplayListCursor++; _g->w0 = (a); _g->w1 = (b); }
#define FILLRECT(ulx, uly, lrx, lry) CMD(0xF6000000 | SHIFTL(lrx, 14, 10) | SHIFTL(lry, 2, 10), SHIFTL(ulx, 14, 10) | SHIFTL(uly, 2, 10))
/* Draws black letterbox bars above and below the viewport, with a 2-pixel edge line, when view flag 0x10 is set. */ void drawLetterboxBars(ViewInfo *view)
{
  if (view->flags & 0x10)
  {
    emitFullScreenScissor();
    CMD(0xE7000000, 0);
    CMD(0xE3000A01, 0x300000);
    CMD(0xE200001C, 0x0F0A4000);
    CMD(0xF7000000, 0);
    FILLRECT(0, 0, gScreenWidth - 1, view->f64 + view->f58);
    FILLRECT(0, view->f64 + view->f5C - 1.0f, gScreenWidth - 1, gScreenHeight - 1);
    CMD(0xE7000000, 0);
    CMD(0xE3000A01, 0);
    CMD(0xFCFFFFFF, 0xFFFDF6FB);
    CMD(0xE200001C, 0x5040C0);
    CMD(0xFA000000, 0x80);
    CMD(0xD9C0F9FA, 0);
    CMD(0xD9FFFFFF, 0x200004);
    CMD(0xE7000000, 0);
    CMD(0xE3001001, 0x8000);
    CMD(0xD7000002, 0x80008000);
    FILLRECT(0, view->f64 + view->f58, gScreenWidth, view->f64 + view->f58 + 2.0f);
    FILLRECT(0, view->f64 + view->f5C - 2.0f, gScreenWidth, view->f64 + view->f5C);
  }
}
