extern s32 D_800E4290[];

s32 func_8008CE0C(u8 *arg0) {
    s32 *tbl = D_800E4290;
    u8 i = arg0[0x4B];
    s32 *p;

    if (i != 0xFF) {
        p = &tbl[i];
    } else {
        p = &tbl[8];
    }
    return *p;
}
