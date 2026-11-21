typedef struct { u32 w0, w1; } Gx;
extern void emitScissorFromWindow();
extern void emit_projection_viewport_commands();
extern void func_80034928();
extern void func_80038FA4(void *);
extern u8 D_800B1AC8[];
extern Gx *D_801002FC;
extern s32 D_801032A0;
extern Gx *D_8010A4B4;
extern s32 D_8010A4D8;
extern s32 D_8010A924;
extern s32 gRenderMode;
extern Gx *sDisplayListCursor;
extern u8 *sRenderState;

void func_80037DC0(u8 *arg0) {
    s32 flags;
    s32 r, g, b;
    Gx *p;
    Gx *q;

    emitScissorFromWindow();
    if (gRenderMode != 1) {
        gRenderMode = 1;
        func_80038FA4(arg0);
    }
    if (D_8010A924 != 8) {
        p = sDisplayListCursor;
        D_8010A924 = 8;
        sDisplayListCursor = p + 1;
        p->w0 = 0xDE000000;
        p->w1 = (u32)D_800B1AC8;
    }
    if (D_801032A0 != 2) {
        p = sDisplayListCursor;
        D_801032A0 = 2;
        sDisplayListCursor = p + 1;
        p->w0 = 0xFC419883;
        p->w1 = 0xFF32FF7F;
    }
    func_80034928(arg0, 2);
    D_801002FC->w0 = 0xDF000000;
    D_801002FC->w1 = 0;
    flags = *(s32 *)(arg0 + 0x100);
    D_801002FC += 1;
    b = 0;
    if (flags & 2) {
        r = 0;
        g = 0xFF;
    } else {
        b = 0xFF;
        if (flags & 4) return;
        p = sDisplayListCursor;
        g = 0xFF;
        r = 0xFF;
        sDisplayListCursor = p + 1;
        p->w0 = 0xFB000000;
        p->w1 = 0xFF;
    }
    p = sDisplayListCursor;
    p[0].w0 = 0xFA000000;
    p[0].w1 = (r << 24) | (g << 16) | (b << 8) | 0xFF;
    p[1].w0 = 0xFB000000;
    p[1].w1 = 0xFF;
    p[2].w0 = 0xDE000000;
    sDisplayListCursor = p + 1;
    sDisplayListCursor = p + 2;
    sDisplayListCursor = p + 3;
    p[2].w1 = *(u32 *)(sRenderState + 0x1B68);
    if (gRenderMode != 0) {
        gRenderMode = 0;
        emit_projection_viewport_commands();
    }
    D_8010A4B4->w0 = 0xDF000000;
    D_8010A4B4->w1 = 0;
    sDisplayListCursor->w0 = 0xDE000000;
    sDisplayListCursor->w1 = *(u32 *)(sRenderState + 0x1C70);
    D_8010A4B4 += 1;
    q = sDisplayListCursor + 1;
    sDisplayListCursor = q;
    func_80034928(arg0, D_8010A4D8, q);
}
