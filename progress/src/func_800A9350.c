s32 func_800AA440(void);
s32 func_800A9350(s32 arg0, s32 *arg1) {
    if (func_800AA440() != 0) return -1;
    *arg1 = *(volatile s32 *)((u32)arg0 | 0xA0000000U);
    return 0;
}
