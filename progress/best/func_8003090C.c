/* machine draft (m2c) for gcc-2.7.2-kmc -G0 -mips3 -mgp32 -mfp32 -O2, tried by autopilot */

extern s32 D_800BFF04;
extern u16 D_800E1608;

s32 func_8003090C(s32 arg0) {
    s16 temp_v0;
    s16 temp_v0_2;
    int var_a0;
    s32 temp_v1;
    s32 var_v0;

    temp_v0 = arg0 + (unsigned short)-1;
    if (D_800BFF04 != 0) {
        if (temp_v0 >= (s32) D_800E1608) {
            return -1;
        }
        var_a0 = 0;
        if (D_800E1608 != 0) {
            var_v0 = 0 << 0x10;
loop_6:
            temp_v1 = var_v0 >> 0x10;do{
            temp_v0_2 = var_a0 + 1;}while(0);
            if (*(s32 *)((temp_v1 * 8) + D_800BFF04) != (arg0 - 1)) {
                var_a0 = temp_v0_2;
                var_v0 = var_a0 << 0x10;
                if (temp_v0_2 >= (s32) D_800E1608) {
                    goto block_8;
                }
                goto loop_6;
            }
            return temp_v1;
        }
        goto block_8;
    }
block_8:
    return -1;
}
