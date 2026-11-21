extern u32 *volatile sDisplayListCursor;
extern u8 *sRenderState;
extern s32 D_800E1710;
void func_80039068(void) {
    u32 *out = sDisplayListCursor;
    s32 index = D_800E1710;
    u8 *state = sRenderState;
    out[0] = 0xDA380007;
    out[1] = (u32)(state + (index << 6)) - 0x80000000;
    out[2] = 0xDA380005;
    out[3] = *(u32 *)(state + 0x74C) + 0x80000040;
    out[4] = 0xDC080008;
    out[5] = (u32)(state + ((index << 4) + 0x300));
    out[6] = 0xDB0E0000;
    out[7] = *(u16 *)(state + index * 2 + 0x360);
    sDisplayListCursor = out + 2;
    sDisplayListCursor = out + 4;
    sDisplayListCursor = out + 6;
    sDisplayListCursor = out + 8;
}
