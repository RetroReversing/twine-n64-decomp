/* machine draft (m2c) for gcc-2.7.2-kmc -G0 -mips3 -mgp32 -mfp32 -O2, tried by autopilot */

s32 func_8008C0D4();
s32 func_8008C11C();
extern s32 D_800F8158;
extern char D_800F815C[];
extern char D_800F8160[];
extern char D_800F8164[];

s32 func_80097454(s32 arg0) {
int __repair_argument_mask;

    s32 var_v1;
    s16 temp_v1;
    s32 var_a2;
    s32 temp_v0;
    void *var_t0;
    s32 temp_v0_2;
    s32 var_a3;
    s32 var_a1;
    s32 *var_a0;

    func_8008C0D4();
    var_a1 = 0;
    if (D_800F8158 > 0) {
        var_v1 = 0;
__repair_argument_mask = arg0 & 0xFFFF;
loop_2:
        if (*(u16 *)(D_800F8160 + var_v1) != __repair_argument_mask) {
            var_a1 += 1;
            var_v1 += 0xC;
            if (var_a1 < D_800F8158) {
                goto loop_2;
            }
        }
    }
    var_a3 = D_800F8158;
    if (var_a1 != var_a3) {
        register var_a2 = var_a1 * 0xC;
        var_a0 = D_800F815C;
        temp_v1 = *(u16 *)(D_800F8164 + var_a2) - 1;
        *(u16 *)(D_800F8164 + var_a2) = temp_v1;
        var_a2 = var_a1 + 1;
        if (!(temp_v1 & 0xFFFF)) {
            if (var_a2 < var_a3) {
                temp_v0_2 = var_a2 * 0xC;
                var_t0 = temp_v0_2 + (D_800F815C - 0xC);
                var_a3 = (s32) (temp_v0_2 + D_800F815C);
                do {
                    register var_a0 = (*(s32 **)((char *)(var_a3) + 8));
                    (*(s32 *)((char *)(var_t0) + 0)) = (s32) (*(s32 *)((char *)((unsigned short)var_a3) + 0));
                    (*(s32 *)((char *)(var_t0) + 4)) = (s32) (*(s32 *)((char *)(var_a3) + 4));
                    (*(s32 **)((char *)(var_t0) + 8)) = var_a0;
                    var_t0 += 0xC;/*__repair_loop_weight*/do {
                    var_a2 += 1;} while (0);
                    var_a3 += 0xC;
                } while (var_a2 < D_800F8158);
            }
            D_800F8158 -= 1;
            func_8008C11C(var_a0, var_a1, var_a2, (void *) var_a3);
            return 1;
        }
    }
    func_8008C11C();
    return 0;
}
