extern u32 *volatile sDisplayListCursor;
extern u8 *sRenderState;
extern s32 gFrameBufferIndex;
/* Appends four display-list commands (two matrix loads, a movemem, a perspective-norm word) taken from the render state for the current frame buffer. */ void appendFrameCameraCommands(void) {
    u32 *gfx = sDisplayListCursor;
    s32 frameIndex = gFrameBufferIndex;
    u8 *renderState = sRenderState;
    gfx[0] = 0xDA380007;
    gfx[1] = (u32)(renderState + (frameIndex << 6)) - 0x80000000;
    gfx[2] = 0xDA380005;
    gfx[3] = *(u32 *)(renderState + 0x74C) + 0x80000040;
    gfx[4] = 0xDC080008;
    gfx[5] = (u32)(renderState + ((frameIndex << 4) + 0x300));
    gfx[6] = 0xDB0E0000;
    gfx[7] = *(u16 *)(renderState + frameIndex * 2 + 0x360);
    sDisplayListCursor = gfx + 2;
    sDisplayListCursor = gfx + 4;
    sDisplayListCursor = gfx + 6;
    sDisplayListCursor = gfx + 8;
}
