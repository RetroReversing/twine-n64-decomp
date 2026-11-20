typedef struct { u32 w0, w1; } TwineGfx;
extern TwineGfx *volatile D_80115328;
extern s32 D_800E1710;
extern u8 *D_80117728;
void emit_matrices_viewport_and_persp_norm(void) {
    TwineGfx *p = D_80115328;
    s32 i = D_800E1710;
    u8 *base = D_80117728;
    u32 segment;
    p[0].w0 = 0xda380007;
    p[0].w1 = (u32)(base + (i * 0x40 + 0x370)) - 0x80000000;
    p[1].w0 = 0xda380005;
    p[1].w1 = (u32)(base + (i * 0x40 + 0x180)) - 0x80000000;
    p[2].w0 = 0xdc080008;
    p[2].w1 = (u32)(base + (i * 0x10 + 0x4f0));
    p[3].w0 = 0xdb0e0000;
    segment = *(u16 *)(base + i * 2 + 0x550);
    D_80115328 = p + 1;
    D_80115328 = p + 2;
    D_80115328 = p + 3;
    D_80115328 = p + 4;
    p[3].w1 = segment;
}
