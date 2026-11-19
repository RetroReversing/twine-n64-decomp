extern u8 D_800EE420[][16][0x86];
extern u8 D_800F2720[][0x86];

void func_80095A80(u8 arg0, u8 arg1, u8 arg2, u8 arg3) {
    if (arg2 != 0xFF) {
        D_800EE420[arg2][arg1][arg0] = arg3 & 0x7F;
    } else {
        D_800F2720[arg1][arg0] = arg3 & 0x7F;
    }
}
