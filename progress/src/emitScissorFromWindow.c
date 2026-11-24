typedef struct { u32 w0, w1; } Gfx;
typedef struct { u8 pad[0x50]; f32 x0, x1, z0, z1, ax, az; u8 pad68[8]; f32 bx, bz; } Win;
extern Gfx *sDisplayListCursor;

/* Emits a G_SETSCISSOR display-list command from the window rectangle (10.2 fixed point). */ void emitScissorFromWindow(Win *win) {
    f32 ulx = (win->x0 + win->ax + win->bx) * 4.0f;
    f32 uly = (win->z0 + win->az + win->bz) * 4.0f;
    f32 lrx = (win->x1 + win->ax - win->bx) * 4.0f;
    f32 lry = (win->z1 + win->az - win->bz) * 4.0f;
    Gfx *gfx = sDisplayListCursor++;

    gfx->w0 = 0xED000000 | (((s32)ulx & 0xFFF) << 12) | ((s32)uly & 0xFFF);
    gfx->w1 = (((s32)lrx & 0xFFF) << 12) | ((s32)lry & 0xFFF);
}
