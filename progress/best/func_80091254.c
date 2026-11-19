/* machine draft (m2c) for gcc-2.7.2-kmc -G0 -mips3 -mgp32 -mfp32 -O2, tried by autopilot */

extern char D_800E5AC4[];
extern char D_800E6A84[];
extern u8 D_800E6A85[];
extern char D_800E6AB2[];

void func_80091254(s32 arg0) {
    unsigned temp_v1;
    s32 var_a0_2;
    
    long var_a0;

    var_a0 = 0;
    var_a0_2 = 0;
loop_1:
    if ((*(D_800E6A85 + var_a0_2) != 0) || (*(s32 *)(D_800E5AC4 + var_a0_2) != (arg0 & (short)0x7FFFFFFF))) {
        var_a0_2 += 0xFF8;
        var_a0 += 1;
        if (8U <= var_a0) {
            var_a0_2 = -1;
        } else {
            goto loop_1;
        }
    } else {
        var_a0_2 = var_a0 | (arg0 & 0x7fffffff);
    }
    if (var_a0_2 != -1) {
        if (0 <= var_a0_2) {
            *(D_800E6A84 + (var_a0_2 * 0xFF8)) = 1;
            return;
        }
        temp_v1 = (var_a0_2 & 0x7FFFFFFF) * 0xFF8;
        *(D_800E6AB2 + temp_v1) = *(D_800E6AB2 + temp_v1) & 0xF7;
    }
}
