extern void *sDisplayListCursor;
/* Appends a G_SETSCISSOR (0xED) display list command for the given pixel rectangle (converted to 10.2 fixed point). */
void setScissorRect(s32 left, s32 top, s32 rectWidth, s32 rectHeight) {
    s32 word0X, word0Y, word1X, word1Y;
    void *cmd;
    left &= 0xFFFF;
    top &= 0xFFFF;
    cmd = sDisplayListCursor;
    word0X = ((s32)((f32)left * 4.0f) & 0xFFF) << 12;
    word0Y = ((s32)((f32)top * 4.0f) & 0xFFF) | 0xED000000;
    word1X = ((s32)((f32)(left + (rectWidth & 0xFFFF)) * 4.0f) & 0xFFF) << 12;
    word1Y = (s32)((f32)(top + (rectHeight & 0xFFFF)) * 4.0f) & 0xFFF;
    sDisplayListCursor = cmd + 8;
    *(s32 *)((s8 *)cmd + 0) = word0X | word0Y;
    *(s32 *)((s8 *)cmd + 4) = word1X | word1Y;
}
