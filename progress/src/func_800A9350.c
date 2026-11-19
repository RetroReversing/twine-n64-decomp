s32 func_800AA440(void);

s32 func_800A9350(u32 devAddr, u32 *data) {
    if (func_800AA440()) {
        return -1;
    }
    *data = *(volatile u32 *)(devAddr | 0xA0000000);
    return 0;
}

s32 func_800A93A0(u32 devAddr, u32 data) {
    if (func_800AA440()) {
        return -1;
    }
    *(volatile u32 *)(devAddr | 0xA0000000) = data;
    return 0;
}
