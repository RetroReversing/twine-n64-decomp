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

f64 func_800ABA40(M2C_UNK, M2C_UNK *, f32, f64, s32, s32, s32, s32); /* extern */
extern f64 D_800D7038;
extern f64 D_800D7040;

f64 func_800AB4A0(f64 arg0, f32 arg1) {
    f32 temp_fv0;
    f32 temp_fv0_2;
    f32 var_a1_2;
    f64 var_a1;
    s32 temp_a1;
    s32 temp_a2;
    s32 var_a3;

    if (M2C_BITWISE(s32, arg1) < 0) {
        return func_800ABA40(1, "sqrt", arg1, arg0, 0, 0, 0, 0);
    }
    temp_a2 = (M2C_BITWISE(u32, arg1) >> 0x14) & 0x7FF;
    if (temp_a2 == 0) {
        return 0.0;
    }
    temp_fv0 = (f32) arg0;
    temp_a1 = (M2C_BITWISE(s32, temp_fv0) & 0xC07FFFFF) | 0x3D000000;
    if ((temp_a2 - 0x3FF) & 1) {
        var_a1_2 = (f32) ((f64) (temp_fv0 + M2C_BITWISE(f32, temp_a1)) + D_800D7038);
    } else {
        var_a1_2 = (f32) ((f64) (temp_fv0 - M2C_BITWISE(f32, temp_a1)) + D_800D7040);
    }
    temp_fv0_2 = var_a1_2 + ((f32) arg0 / var_a1_2);
    var_a1 = (f64) ((M2C_BITWISE(s32, temp_fv0_2) & 0xC07FFFFF) | (((M2C_BITWISE(s32, temp_fv0_2) & 0x3F800000) + 0xFF800000) & 0x3F800000));
    var_a3 = 0;
    __repair_rows: {
        var_a1 += arg0 / var_a1;
        var_a3 += 1;
    }
if (var_a3 < 2) goto __repair_rows;
    return var_a1;
}
