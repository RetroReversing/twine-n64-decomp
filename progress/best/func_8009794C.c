/* machine draft (m2c) for gcc-2.7.2-kmc -G0 -mips3 -mgp32 -mfp32 -O2, tried by autopilot */

s32 func_8008C0D4();
s32 func_8008C11C();
extern char D_800F38E4[];
extern s32 D_800F38EC;
extern char D_800F38F0[];

s32 func_8009794C(s32 arg0) {
int __repair_literal;

    s32 temp_v0;
    s32 var_a2;
    register s32 var_s0;
    s32 var_v0;
    void *var_a3;
    void *var_t0;
    s32 var_v1;

    var_s0 = 0;
__repair_literal = 0;

    if (__repair_literal < D_800F38EC) {
        var_v1 = 0;
loop_2:
        if (*((s32 *)((s8 *)D_800F38F0 + var_v1)) != arg0) {
            ++var_s0;
            var_v1 += 0xC;
            if (D_800F38EC > var_s0) {
                goto loop_2;
            }
        }
    }
    var_v0 = 0;
    if (var_s0 != D_800F38EC) {
        func_8008C0D4(arg0, D_800F38EC);
        var_a2 = var_s0 + 1;
        if (var_a2 < D_800F38EC) {
            temp_v0 = var_a2 * 0xC;
            var_t0 = temp_v0 + D_800F38E4;
            var_a3 = temp_v0 + ((s32 *)((s8 *)D_800F38E4 + 0xC));
            __repair_rows: {
                (*(s32 *)((char *)(var_t0) + 0)) = (s32) (*(s32 *)((char *)(var_a3) + 0));
                (*(s32 *)((char *)(var_t0) + 8)) = (s32) (*(s32 *)((char *)(var_a3) + 8));
                var_t0 += 0xC;
                (*(s32 *)((char *)(var_t0) + 4)) = (s32) (*(s32 *)((char *)(var_a3) + 4));
                var_a2++;
                var_a3 += 0xC;
            }
if (var_a2 < D_800F38EC) goto __repair_rows;
        }
        D_800F38EC -= 1;
        func_8008C11C();
        var_v0 = 1;
    }
    return var_v0;
}
