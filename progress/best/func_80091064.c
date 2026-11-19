/* machine draft (m2c) for gcc-2.7.2-kmc -G0 -mips3 -mgp32 -mfp32 -O2, tried by autopilot */

extern char D_800E5AC4[];
extern u8 D_800E6A85[];
extern char D_800E6A86[];
extern char D_800E6AB0[];
extern char D_800E6AB2[];

void func_80091064(s32 arg0, s16 arg1) {
    register s32 var_a0;
    int temp_v0;
    register s32 var_v1;
    long var_a0_2;

    var_a0 = 0;
    var_v1 = 0;
loop_1:
    if ((*(D_800E6A85 + var_v1) != 0) || (*(s32 *)(D_800E5AC4 + var_v1) != (arg0 & (short)0x7FFFFFFF))) {
        var_v1 += 0xFF8;
        ++var_a0;
        if (var_a0 >= 8U) {
            var_a0_2 = -1;
        } else {
            goto loop_1;
        }
    } else {
        var_a0_2 = var_a0 | (arg0 & 0x7fffffff);
    }
    if (var_a0_2 != -1) {
        if (var_a0_2 >= 0) {
            *(s16 *)(D_800E6A86 + (var_a0_2 * 0xFF8)) = arg1;
            return;
        }
        var_v1 = (var_a0_2 & 0x7FFFFFFF) * 0xFF8;
        *(D_800E6AB2 + var_v1) = *(D_800E6AB2 + var_v1) | 0x20;
        *(s16 *)(D_800E6AB0 + var_v1) = arg1;
    }
}
