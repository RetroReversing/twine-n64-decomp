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

s32 func_8008C758();
s32 func_80097814();
s32 func_80097A40();

void func_800929AC(u16 *arg0, s32 arg1, s32 arg2) {
    char *var_s0;
    u16 var_a0;

    if (func_80097814(arg2, func_8008C758(arg1)) & 0xFF) {
        var_a0 = *arg0;
        if ((var_a0 & 0xFFFF) != 0xFFFF) {
            var_s0 = (void *)(arg0); var_s0 = (void *)((char *)var_s0 + (s32)(2));
            do {
                func_80097A40(var_a0, arg2);
                var_a0 = *(u16 *)var_s0;
                var_s0 += 2;
            } while (var_a0 != 0xFFFF);
        }
    }
}
