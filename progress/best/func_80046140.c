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

f32 func_800828D0(f32);                             /* extern */

f32 func_80046140(f32 arg1) {
    f32 temp_fs2;
    f32 temp_fv0;
    f32 var_ft0;
    f32 var_fa0;

    temp_fs2 = func_800828D0(arg1);
    temp_fv0 = func_800828D0(arg1);
    if (temp_fv0 < temp_fs2) {
        var_fa0 = temp_fs2;
        var_ft0 = temp_fv0;
    } else {
        var_fa0 = temp_fv0;
        var_ft0 = temp_fs2;
    }
    return (var_fa0 * 0.9604f) + (var_ft0 * 0.3978f);
}
