/* machine draft (m2c) for gcc-2.7.2-kmc -G0 -mips3 -mgp32 -mfp32 -O2, tried by autopilot */
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

extern int D_801002B8;
extern int D_801002BC;
extern char D_801001A1[];

s32 func_80019A3C(void) {
    s32 var_a0;
    s32 var_a0_2;
    s32 var_a3;
    s32 var_t0;
    s32 var_v0;
    s32 var_v0_2;

    var_a3 = 0;
    var_t0 = 0;
loop_1:
    var_a0 = 0;
    if (D_801002B8 > 0) {
        var_v0 = 0 & 0xFFFF;
loop_3:
        if (*(D_801001A1 + (var_v0 * 0x18)) == (var_a3 & 0xFFFF)) {
            var_t0 = 1;
        } else {
            var_a0 += 1;
            var_v0 = var_a0 & 0xFFFF;
            if ((var_a0 & 0xFFFF) < D_801002B8) {
                goto loop_3;
            }
        }
    }
    var_a0_2 = 0;
    if (D_801002BC > 0) {
        var_v0_2 = 0 & 0xFFFF;
loop_9:
        var_a0_2 += 1;
        if (*(D_801001A1 + ((var_v0_2 + 4) * 0x18)) != (var_a3 & 0xFFFF)) {
            var_v0_2 = var_a0_2 & 0xFFFF;
            if ((var_a0_2 & 0xFFFF) < D_801002BC) {
                goto loop_9;
            }
        } else {
            var_t0 = 1;
        }
    }
    if (var_t0 & 0xFFFF) {
        var_a3 += 1;
        var_t0 = 0;
        if ((u32) (var_a3 & 0xFFFF) >= 2U) {
            return 1;
        }
        goto loop_1;
    }
    return 0;
}
