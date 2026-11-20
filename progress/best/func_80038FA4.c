typedef struct {
    u32 w0, w1;
} DisplayCommand;

extern s32 D_800E1710;
extern DisplayCommand *volatile D_80115328;
extern u8 *D_80117728;

void func_80038FA4(void) {
    u32 projection = 0xDA380007;
    u32 modelview = 0xDA380005;
    DisplayCommand *cmd = D_80115328;
    s32 index = D_800E1710;
    s32 matrixIndex = (index << 6) + 0x560;
    u8 *frame = D_80117728;
    u32 matrixOffset = 0x80000040;
    u32 matrixBase;
    u16 value;

    cmd[0].w0 = projection;
    cmd[0].w1 = (u32)(frame + matrixIndex) - 0x80000000;
    cmd[1].w0 = modelview;
    matrixBase = *(u32 *)(frame + 0x74C);
    cmd[2].w0 = 0xDC080008;
    cmd[2].w1 = (u32)(frame + ((index << 4) + 0x6E0));
    cmd[3].w0 = 0xDB0E0000;
    cmd[1].w1 = matrixBase + matrixOffset;
    value = *(u16 *)(frame + (index << 1) + 0x740);
    D_80115328 = cmd + 1;
    D_80115328 = cmd + 2;
    D_80115328 = cmd + 3;
    D_80115328 = cmd + 4;
    cmd[3].w1 = value;
}
