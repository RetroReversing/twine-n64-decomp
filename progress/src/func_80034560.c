typedef struct { u32 w0, w1; } Gfx;
typedef struct { u8 pad[0x50]; f32 x0, x1, z0, z1, ax, az; u8 pad68[8]; f32 bx, bz; } Win;
extern Gfx *D_80115328;

void func_80034560(Win *arg0) {
    f32 ulx = (arg0->x0 + arg0->ax + arg0->bx) * 4.0f;
    f32 uly = (arg0->z0 + arg0->az + arg0->bz) * 4.0f;
    f32 lrx = (arg0->x1 + arg0->ax - arg0->bx) * 4.0f;
    f32 lry = (arg0->z1 + arg0->az - arg0->bz) * 4.0f;
    Gfx *g = D_80115328++;

    g->w0 = 0xED000000 | (((s32)ulx & 0xFFF) << 12) | ((s32)uly & 0xFFF);
    g->w1 = (((s32)lrx & 0xFFF) << 12) | ((s32)lry & 0xFFF);
}
