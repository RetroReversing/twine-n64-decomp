extern u8 D_80115094[];

void func_80081D20(s32 row, s32 col) {
    u8 (*base)[2];
    base = (u8 (*)[2])(D_80115094 + row * 0xA0);
    base[col][0] |= 0x80;
}
