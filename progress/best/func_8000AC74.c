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

s32 func_8000A270();
s32 func_8009C930();
extern u8 D_800B1FE0[];
extern char D_800B2230[];
extern f64 D_800D2170;
extern s32 D_801002EC;

s32 func_8000AC74(s32 arg0, s32 arg1, f32 arg2) {
    f32 temp_ft0;
    f32 temp_fv0;
    f32 temp_fv1;
    f32 var_fv1;

    if (D_801002EC != 0) {
        if (arg0 != -1) {
            temp_ft0 = (f32) *(D_800B1FE0 + arg1);
            var_fv1 = arg2 - temp_ft0;
            temp_fv0 = (f32) *(D_800B2230 + arg1);
            if (var_fv1 < 0.0f) {
                var_fv1 = 0.0f;
            }
            if (!(temp_fv0 <= arg2)) {
                temp_fv1 = var_fv1 / (temp_fv0 - temp_ft0);
                func_8009C930(arg0, (s32) (D_800D2170 - (f64) (temp_fv1 * temp_fv1 * 127.0f)) & 0xFF);
                return arg0;
            }
            func_8000A270(arg0);
            goto block_7;
        }
        /* Duplicate return node #8. Try simplifying control flow for better match */
        return -1;
    }
block_7:
    return -1;
}
