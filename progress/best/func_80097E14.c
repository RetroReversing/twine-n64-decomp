/* machine draft (m2c) for gcc-2.7.2-kmc -G0 -mips3 -mgp32 -mfp32 -O2, tried by autopilot */

s32 func_8008C0D4();
s32 func_8008C11C();
extern char D_800FD55C[];
extern s32 D_800FD560;
extern char D_800FD564[];

s32 func_80097E14(s32 arg0) {
int __repair_literal;

    s32 temp_v1;
    s32 var_a0;
    void *var_a3;
    s32 var_s0;
    s32 var_v0;
    s32 var_v1;
    s32 var_a2;
    void *var_t0;

    var_a0 = arg0;
    var_s0 = 0;
__repair_literal = 0;

    if (D_800FD560 > __repair_literal) {
        var_a0 &= 0xFFFF;
        var_v1 = 0;
        for (;;) {
            if (*(u16 *)(D_800FD564 + var_v1) != var_a0) {
                var_s0 += 1;
                var_v1 += 8;
                if (var_s0 < D_800FD560) {
                    continue;
                }
            }
            break;
        }
    }
    var_v0 = 0;
    if (var_s0 != D_800FD560) {
        func_8008C0D4(var_a0, D_800FD560);
        var_a2 = var_s0 + 1;
        temp_v1 = var_a2 * 8;
        if (var_a2 < D_800FD560) {
            var_t0 = temp_v1 + D_800FD55C;
            var_a3 = temp_v1 + (D_800FD55C + 8);
            do {
                (*(s32 *)((char *)(var_t0) + 0)) = (s32) (*(s32 *)((char *)(var_a3) + 0));
                var_t0 += 8;
                (*(s32 *)((char *)(var_t0) + 4)) = (s32) (*(s32 *)((char *)(var_a3) + 4));
                var_a3 += 8;
                ++var_a2;
            } while (D_800FD560 > var_a2);
        }
        D_800FD560 -= 1;
        func_8008C11C();
        var_v0 = 1;
    }
    return var_v0;
}
