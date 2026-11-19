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

f64 func_800AAF80(f64 arg0, s32 arg1, void *arg2) {
    s32 temp_v1;
    s32 temp_v1_2;
    s32 var_a1;
    u8 *temp_a0;

    M2C_FIELD(arg2, f64 *, 0) = arg0;
    temp_v1 = ((M2C_BITWISE(u32, M2C_FIELD(arg2, f64 *, 0)) >> 0x14) & 0x7FF) - 0x3FF;
    if (temp_v1 < 0) {
        M2C_FIELD(arg2, f64 *, 0) = 0;
        M2C_FIELD(arg2, s32 *, 4) = 0;
        return arg0;
    }
    temp_v1_2 = temp_v1 + 0xC;
    if (temp_v1 >= 0x34) {
        M2C_FIELD(arg2, f64 *, 0) = arg0;
        return 0.0;
    }
    var_a1 = temp_v1_2 >> 3;
    temp_a0 = arg2 + var_a1;
    *temp_a0 &= 0xFF << (8 - (temp_v1_2 & 7));
    if (var_a1 < 7) {
        do {
            var_a1 += 1;
            *(s8 *)(arg2 + var_a1) = 0;
        } while ((temp_v1_2 = var_a1) < 7);
    }
    return arg0 - M2C_FIELD(arg2, f64 *, 0);
}
