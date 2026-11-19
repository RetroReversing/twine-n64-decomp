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

s32 func_80046DC0(s32 arg0, f32 *arg1, f32 *arg2, f32 arg3, f32 arg4) {
    u8 __repair_frame[8];
    char *var_a3;
    char *var_t1;
    f32 temp_ft1;
    f32 temp_ft2;
    f32 temp_fv1;
    s32 var_t0;
    s32 var_t2;
    s32 var_v1;

    var_t0 = 0;
    var_v1 = arg0 - 1;
    var_t2 = 0;
    if (arg0 > 0) {
        var_a3 = arg2;
        var_t1 = arg1;
        do {
            temp_fv1 = *(f32 *)var_a3;
            if (!(temp_fv1 <= arg4) || !(arg4 < arg2[var_v1])) {
                if (arg2[var_v1] <= arg4) {
                    if (arg4 < temp_fv1) {
                        goto block_8;
                    }
                }
            } else {
block_8:
                temp_ft1 = *(f32 *)var_a3;
                if (arg3 < ((((arg1[var_v1] - (temp_ft2 = *(f32 *)var_t1)) * (arg4 - temp_ft1)) / (arg2[var_v1] - temp_ft1)) + temp_ft2)) {
                    var_t2 = var_t2 == 0;
                }
            }
            var_v1 = var_t0;
            var_a3 += 4;
            var_t0 += 1;
            var_t1 += 4;
        } while (var_t0 < arg0);
    }
    return var_t2;
}
