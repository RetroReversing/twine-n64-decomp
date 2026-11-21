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

s32 func_8000A724();
s32 func_8009C930();
s32 func_8009CC3C();
extern u8 D_800B1D90[];
extern u8 D_800B1FE0[];
extern u8 D_800B2230[];
extern f64 D_800D2168;
extern s32 D_801002EC;

s32 playDistanceSound(s32 arg0, f32 arg1, u8 arg2) {
    f32 temp_ft0;
    f32 temp_fv0;
    f32 temp_fv1;
    f32 var_fv1;
    s32 temp_s0;
    s32 temp_v0;
    s32 var_v0;

    if (D_801002EC == 0) goto failed;
    {
        temp_ft0 = (f32) *(D_800B1FE0 + arg0);
        var_fv1 = arg1 - temp_ft0;
        temp_fv0 = (f32) *(D_800B2230 + arg0);
        if (var_fv1 < 0.0f) {
            var_fv1 = 0.0f;
        }
        var_v0 = -1;
        if (!(temp_fv0 <= arg1)) {
            var_fv1 /= (temp_fv0 - temp_ft0);
            var_fv1 *= var_fv1;
            temp_s0 = (s32) (D_800D2168 - (f64) (var_fv1 * 127.0f));
            temp_v0 = func_8009CC3C(arg0 & 0xFFFF, arg2 & 0xFF, 0xFF);
            func_8009C930(temp_v0, temp_s0 & 0xFF);
            if (*(D_800B1D90 + arg0) == 0) {
failed:
                var_v0 = -1;
            } else {
                func_8000A724(temp_v0);
                var_v0 = temp_v0;
            }
        }
        return var_v0;
    }
}

