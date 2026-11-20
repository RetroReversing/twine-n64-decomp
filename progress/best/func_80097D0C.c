static __inline__ int __repair_inline(s32 a, s32 b) { return a > b; }
/* machine draft (m2c) for gcc-2.7.2-kmc -G0 -mips3 -mgp32 -mfp32 -O2, tried by autopilot */

s32 func_8008C0D4();
s32 func_8008C11C();
extern s32 D_800FD560;
extern char D_800FD564[];
extern char D_800FD566[];
extern char D_800FD568[];

s32 func_80097D0C(s16 arg0, void *arg1, s16 arg2) {
int __repair_literal;

    s16 temp_s1;
    s16 temp_s2;
    u16 var_a2;
    s32 var_a0;
s32 __repair_phase_temp_a2;
    s32 temp_v0;
    
    s32 var_v1;
    s32 var_v1_2;
s32 __repair_phase_var_v1_2;
    void *var_s0;

    var_a2 = arg2;
    var_s0 = arg1;
    var_a0 = arg0;
    var_v1 = 0;
    var_v1_2 = (s16)(var_a0);
    temp_s2 = var_a2;
__repair_literal = 0;

    if (D_800FD560 > __repair_literal) {
        var_a2 = var_v1_2 & 0xFFFF;
        var_a0 = 0;
        for (;;) {
            if (*(u16 *)(D_800FD564 + var_a0) != var_a2) {
                var_v1 += 1;
                var_a0 += 8;
                if (var_v1 < D_800FD560) {
                    continue;
                }
            }
            break;
        }
    }
    if (var_v1 == D_800FD560) {
        if (var_v1 < 0x80) {
            func_8008C0D4(var_a0);
            temp_v0 = D_800FD560 * 8;
            *(u16 *)(D_800FD564 + (unsigned)temp_v0) = var_v1_2;
            *(u16 *)(D_800FD566 + temp_v0) = temp_s2;
            *(void **)(D_800FD568 + temp_v0) = var_s0;
            __repair_phase_var_v1_2 = 0;
            __repair_phase_temp_a2 = temp_s2 & 0xFFFF;
            if (__repair_inline(__repair_phase_temp_a2, 0)) {
                do {
                    (*(s8 *)((char *)(var_s0) + 9)) = 0x1F;
                    __repair_phase_var_v1_2 += 1;
                    var_s0 += 0xC;
                } while (__repair_phase_var_v1_2 < __repair_phase_temp_a2);
            }
            D_800FD560 += 1;
            func_8008C11C();
            return 1;
        }
    }
    return 0;
}
