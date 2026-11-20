extern u32 *volatile D_80115328;
extern u8 *D_80117728;
extern s32 D_800E1710;
void func_80039068(void) {
    u32 *out = D_80115328;
    s32 index = D_800E1710;
    u8 *state = D_80117728;
    out[0] = 0xDA380007;
    out[1] = (u32)(state + (index << 6)) - 0x80000000;
    out[2] = 0xDA380005;
    out[3] = *(u32 *)(state + 0x74C) + 0x80000040;
    out[4] = 0xDC080008;
    out[5] = (u32)(state + ((index << 4) + 0x300));
    out[6] = 0xDB0E0000;
    out[7] = *(u16 *)(state + index * 2 + 0x360);
    D_80115328 = out + 2;
    D_80115328 = out + 4;
    D_80115328 = out + 6;
    D_80115328 = out + 8;
}
