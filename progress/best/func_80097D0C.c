/* machine draft (m2c) for gcc-2.7.2-kmc -G0 -mips3 -mgp32 -mfp32 -O2, tried by autopilot */

s32 func_8008C0D4();
s32 func_8008C11C();
extern s32 D_800FD560;
extern char D_800FD564[];
extern char D_800FD566[];
extern char D_800FD568[];

s32 func_80097D0C(s16 arg0, void *arg1, s16 arg2) {
    s16 temp_s2;
    s16 temp_s1;
    int temp_v0;
    s32 temp_a2;
    s16 var_a2;
    s16 var_a0;
    
    s32 var_v1;
    short var_v1_2;
s32 __repair_phase_var_v1_2;
    void *var_s0;

    var_a0 = arg0;
    var_a2 = arg2;
    var_s0 = arg1;
    var_v1 = 0;
    var_v1_2 = (s16)(var_a0);
    temp_s2 = var_a2;
    if (D_800FD560 > 0) {
        register var_a2 = var_v1_2 & 0xFFFF;
        register var_a0 = 0;
loop_2:
        if (*(u16 *)(D_800FD564 + var_a0) != var_a2) {/*__repair_loop_weight*/do {
            var_v1 += 1;} while (0);
            var_a0 += 8;
            if (D_800FD560 > var_v1) {
                goto loop_2;
            }
        }
    }
    temp_a2 = 0;
    if (var_v1 == D_800FD560) {
        register temp_a2 = 0;
        if (var_v1 < 0x80) {
            func_8008C0D4(var_a0);
            temp_a2 = temp_s2 & 0xFFFF;
            temp_v0 = D_800FD560 * 8;
            *(u16 *)(D_800FD564 + temp_v0) = var_v1_2;
            *(u16 *)(D_800FD566 + temp_v0) = temp_s2;
            *(u16 *)(D_800FD568 + temp_v0) = var_s0;
            __repair_phase_var_v1_2 = 0;
            if (temp_a2 > 0) {
                do {
                    (*(s8 *)((char *)(var_s0) + 9)) = 0x1F;
                    __repair_phase_var_v1_2 += 1;
                    var_s0 += 0xC;
                } while (__repair_phase_var_v1_2 < temp_a2);
            }
            ++D_800FD560;
            func_8008C11C();
            temp_a2 = 1;
        }
    }
    return temp_a2;
}
