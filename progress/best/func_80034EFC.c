typedef struct {
    u32 w0, w1;
} Gfx34EFC;

extern Gfx34EFC *volatile D_80115328;
extern s16 D_8010D6F8, D_80108F80, D_8010A4B0;
extern s32 D_8010A4E8, D_8010A4EC;
extern s32 D_80100304[];
s32 osVirtualToPhysical(s32);

void func_80034EFC(void) {
    register Gfx34EFC *base = D_80115328;
    Gfx34EFC *cmd;
    s32 width, height, size;
    register long cycle;
    s32 buffer, tag;
    s32 render = 0xE200001C;
    u32 modes = 0x0F0A4000;
    cycle = 0xE3000A01;

    D_80115328 = base + 1;
    base[0].w0 = 0xE7000000;
    D_80115328 = base + 2;
    base[1].w1 = 0x300000;
    D_80115328 = base + 3;
    height = D_80108F80 - 1;
    width = (int)D_8010D6F8 - 1;
    base[1].w0 = cycle;
    base[0].w1 = 0;
    base[2].w1 = modes;
    size = 2;
    base[2].w0 = render;
    if (*(volatile s32 *)&D_8010A4EC) {
        size = (-(D_8010A4E8 == 0) & 3) | 2;
    }

    tag = 0xFF000000;
    base[3].w0 = (size << 19) | ((width & 0xFFF) | tag);
    buffer = D_8010A4B0;
    D_80115328 = base + 4;
    base[3].w1 = osVirtualToPhysical(D_80100304[buffer]);
    cmd = D_80115328;
    D_80115328 = cmd + 1;
    cmd[0].w0 = 0xF7000000;
    D_80115328 = cmd + 2;
    cmd[0].w1 = 0;
    cmd[1].w0 = (((height & 0x3FF) << 2) | 0xF6000000u) | ((width & 0x3FF) << 14);
    cmd[1].w1 = 0;
}
