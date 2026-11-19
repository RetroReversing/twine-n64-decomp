extern u8 D_800EE400[];
extern u8 D_800EE380[][16];
u8 func_800968E8(u8 arg0, u8 arg1) {
    u8 ret;
    if (arg1 == 0xFF) {
        ret = D_800EE400[arg0];
    } else {
        ret = D_800EE380[arg1][arg0];
    }
    return ret;
}
