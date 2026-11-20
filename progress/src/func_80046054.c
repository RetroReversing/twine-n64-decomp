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
/* machine draft (m2c) for gcc-2.7.2-kmc -G0 -mips3 -mgp32 -mfp32 -O2, tried by autopilot */

f32 absFloat(f32);

f32 func_80046054(f32 arg0, f32 arg1, f32 arg2) {
    f32 temp_fv0;
    f32 temp_fv0_2;
    f32 temp_fv0_3;
    f32 var_fs0;
    f32 var_fs2;
    f32 var_ft1;

    var_fs2 = absFloat(arg0);
    var_fs0 = absFloat(arg1);
    var_ft1 = absFloat(arg2);
    if (var_fs2 < var_fs0) {
        temp_fv0 = var_fs2;
        var_fs2 = var_fs0;
        var_fs0 = temp_fv0;
    }
    temp_fv0_2 = var_ft1;
    if (var_fs2 < var_ft1) {
        var_ft1 = var_fs2;
        var_fs2 = temp_fv0_2;
    }
    temp_fv0_3 = var_fs0;
    if (var_fs0 < var_ft1) {
        var_fs0 = var_ft1;
        var_ft1 = temp_fv0_3;
    }
    return (var_fs2 * 0.9398f) + (var_fs0 * 0.3893f) + (var_ft1 * 0.2987f);
}
