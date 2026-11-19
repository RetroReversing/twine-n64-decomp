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

s32 func_800972A4();

void func_800928F4(u16 *arg0, void *arg1) {
    s32 *var_a1;
    s32 *var_v0;
    char *var_s0;
    u16 var_a0;

    var_s0 = arg0;
    var_a0 = *(u16 *)var_s0;
    if ((var_a0 & 0xFFFF) != 0xFFFF) {
        do {
            var_a1 = arg1 + M2C_FIELD(arg1, s32 *, 0xC);
            var_v0 = NULL;
            if (*var_a1 != -1) {
                for (;;) {
                    var_v0 = var_a1;
                    if (M2C_FIELD(var_a1, u16 *, 4) != (var_a0 & 0xFFFF)) {
                        var_a1 += M2C_FIELD(var_a1, s32 *, 0);
                        var_v0 = NULL;
                        if (*var_a1 != -1) {
                            continue;
                        }
                    }
                    break;
                }
            }
            if (var_v0 != NULL) {
                func_800972A4(*(u16 *)var_s0, (s8 *) var_v0 + 0xC, M2C_FIELD(var_v0, u16 *, 0xA));
            }
            var_s0 += 2;
            var_a0 = *(u16 *)var_s0;
        } while (var_a0 != 0xFFFF);
    }
}
