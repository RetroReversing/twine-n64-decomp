/* machine draft (m2c) for gcc-2.7.2-kmc -G0 -mips3 -mgp32 -mfp32 -O2 -fno-schedule-insns, tried by autopilot */
#ifndef M2C_DEFINES
#define M2C_DEFINES
typedef s32 M2C_UNK;
typedef s8 M2C_UNK8;
typedef s16 M2C_UNK16;
typedef s32 M2C_UNK32;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define M2C_CARRY 0
#define M2C_OVERFLOW(a) (0)
#endif

s32 func_800956E0();
extern s16 D_800F38E0;
extern s32 D_800FD560;
extern char D_800FD566[];
extern char D_800FD568[];
extern s32 func_800986FC;

s32 func_800985A8(s16 arg0) {
int __repair_literal;

    s32 var_s0;
    s32 var_s1;
    s32 var_v0;

    D_800F38E0 = arg0;
    var_s1 = 0;
__repair_literal = 0;

    if (D_800FD560 > __repair_literal) {
        var_s0 = 0;
        for (;;) {
            var_v0 = func_800956E0(&D_800F38E0, *(s32 *)(D_800FD568 + var_s0), *(u16 *)(D_800FD566 + var_s0), 0xC, &func_800986FC);
            var_s1 += 1;
            if (var_v0 != 0) {
                break;
            }
            var_s0 += 8;
            if (var_s1 >= D_800FD560) {
                goto block_4;
            }
        }
    } else {
block_4:
        var_v0 = 0;
    }
    return var_v0;
}
