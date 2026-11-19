/* identical to func_800968E8 (matched), with its names changed by decompdecomp */
extern u8 D_800F3860[];
extern u8 D_800F37E0[][16];
u8 func_80096970(u8 arg0, u8 arg1) {
    u8 ret;
    if (arg1 == 0xFF) {
        ret = D_800F3860[arg0];
    } else {
        ret = D_800F37E0[arg1][arg0];
    }
    return ret;
}
