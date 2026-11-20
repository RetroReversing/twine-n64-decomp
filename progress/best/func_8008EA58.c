s32 func_800989B8();
extern u8 D_800CF540;
extern s32 D_8010D734;
extern s32 D_8010D748;
extern s32 D_8010D784;
s32 func_8008EA58(void) {
    s32 temp_v1;
    s32 var_a0;
    s32 var_s0;
    s32 var_v0;
    s32 var_v0_2;
    var_s0 = -1;
    if (D_800CF540 != 0) {
        var_a0 = func_800989B8();
        var_v0 = -1;
        if (var_a0 != -1) {
            var_v0_2 = var_a0 & 0xFF;
            do {
                temp_v1 = var_v0_2 * 0x1A0;
                if (*(&D_8010D784 + temp_v1) == var_a0) {
                    var_s0 = 0;
                    *(&D_8010D748 + temp_v1) = *(&D_8010D748 + temp_v1) | 8;
                }
                var_a0 = *(&D_8010D734 + temp_v1);
                var_v0_2 = var_a0 & 0xFF;
            } while (var_a0 != -1);
            goto block_6;
        }
    } else {
block_6:
        var_v0 = var_s0;
    }
    return var_v0;
}
