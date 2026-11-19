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

s32 func_8008C0D4();
s32 func_8008C11C();
extern char D_800FD55C[];
extern s32 D_800FD560;
extern char D_800FD564[];

typedef struct { s32 w[2]; } __repair_words2;
s32 func_80097E14(s32 arg0) {
int __repair_literal;

    s32 temp_v1;
    s32 var_a0;
    s32 var_a2;
    s32 var_s0;
    s32 var_v0;
    s32 var_v1;
    void *var_a3;
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
                M2C_FIELD(var_t0, __repair_words2 *, 0x0) = *(__repair_words2 *) ((s8 *) var_a3 + 0x0);
                var_t0 += 8;
                var_a2 += 1;
                var_a3 += 8;
            } while (var_a2 < D_800FD560);
        }
        D_800FD560 -= 1;
        func_8008C11C();
        var_v0 = 1;
    }
    return var_v0;
}
