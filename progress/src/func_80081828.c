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

extern char D_80103022[];

s32 func_80081828(s32 arg0) {
    char *__base_D_80103022;
    s32 temp_a0;
    u8 var_a1;
    s32 var_v0;
    s32 var_v1;

    var_v1 = 0;
    var_a1 = 0;
    temp_a0 = arg0 & 0xFF;
__base_D_80103022 = D_80103022;
    for (;;) {
        if (*(u16 *)(((var_v1 & 0xFF) * 2) + __base_D_80103022) == 0) goto skip;
        var_a1 += 1;
        skip:;
        if ((var_a1 & 0xFF) != (temp_a0 + 1)) {
            var_v1 += 1;
            if ((u32) (var_v1 & 0xFF) < 4U) {
                continue;
            }
        }
        break;
    }
    var_v0 = 0;
    if (temp_a0 != 0) {
        var_v0 = var_v1 & 0xFF;
    }
    return var_v0;
}
