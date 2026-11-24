typedef struct { u32 w0, w1; } TwineGfx;
extern TwineGfx *volatile sDisplayListCursor;
extern s32 gFrameBufferIndex;
extern u8 *sRenderState;
/* Appends display list commands that load the projection/modelview matrices, viewport and perspective-normalize value for the current frame buffer. */
void emitMatricesViewportAndPerspNorm(void) {
    TwineGfx *gfx = sDisplayListCursor;
    s32 frame = gFrameBufferIndex;
    u8 *state = sRenderState;
    u32 perspNorm;
    gfx[0].w0 = 0xda380007;
    gfx[0].w1 = (u32)(state + (frame * 0x40 + 0x370)) - 0x80000000;
    gfx[1].w0 = 0xda380005;
    gfx[1].w1 = (u32)(state + (frame * 0x40 + 0x180)) - 0x80000000;
    gfx[2].w0 = 0xdc080008;
    gfx[2].w1 = (u32)(state + (frame * 0x10 + 0x4f0));
    gfx[3].w0 = 0xdb0e0000;
    perspNorm = *(u16 *)(state + frame * 2 + 0x550);
    sDisplayListCursor = gfx + 1;
    sDisplayListCursor = gfx + 2;
    sDisplayListCursor = gfx + 3;
    sDisplayListCursor = gfx + 4;
    gfx[3].w1 = perspNorm;
}
