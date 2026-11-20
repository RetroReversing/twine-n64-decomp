/* machine draft (m2c) for gcc-2.7.2-kmc -G0 -mips3 -mgp32 -mfp32 -O2 -fno-schedule-insns, tried by autopilot */
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

extern s32 (*D_800D941C)(f32, void *, void *, void *);

void func_80005D04(u8 *arg0, u8 *arg1, u8 *arg2, f32 arg3) {
    f32 temp_ft0;
    f32 temp_ft0_2;
    f32 temp_ft1;
    f32 temp_ft2;
    f32 temp_ft3;
    f32 temp_fv0;
    f32 temp_fv0_2;
    f32 temp_fv1;
    f32 temp_fv1_2;
    char *var_a1;
    char *var_v1;
    s32 temp_a0;
    s32 temp_a1;
    s32 temp_a2;
    s32 temp_a3;
    
    volatile u64 scratch[3];
    s32 callbackFlag;
    s32 temp_s2;
    s32 temp_s6;
    s32 temp_v0;
    s32 var_a3;
    s32 var_s0;
    s32 var_s1;
    s32 var_s1_2;
    s32 var_s1_3;
    s32 var_t2;
    u32 temp_v1;
    u32 temp_v1_2;
    void *var_a0;

    temp_v0 = M2C_FIELD(arg1, s32 *, 0);
    temp_s2 = temp_v0 >> 0x10;
    callbackFlag = temp_v0 & 1;
    M2C_FIELD(arg0, s32 *, 0) = temp_v0;
    if (temp_v0 & 2) {
        var_t2 = temp_s2 * 3;
    } else {
        var_t2 = 3;
    }
    var_s1 = 0;
    temp_s6 = var_t2 + temp_s2;
    if (var_t2 > 0) {
        var_a1 = arg0;
        var_a0 = arg2;
        var_v1 = arg1;
    interpolate: {
            temp_ft0 = M2C_FIELD(var_a0, f32 *, 8);
            temp_ft3 = M2C_FIELD(var_v1, f32 *, 8);
            temp_ft0 -= temp_ft3;
            temp_fv1 = M2C_FIELD(var_a0, f32 *, 0xC);
            temp_ft2 = M2C_FIELD(var_v1, f32 *, 0xC);
            temp_fv1 -= temp_ft2;
            temp_fv0 = M2C_FIELD(var_a0, f32 *, 0x10);
            temp_ft1 = M2C_FIELD(var_v1, f32 *, 0x10);
            temp_fv0 -= temp_ft1;
            temp_ft0 *= arg3;
            temp_fv1 *= arg3;
            temp_fv0 *= arg3;
            temp_ft0 += temp_ft3;
            temp_fv1 += temp_ft2;
            var_a0 += 0xC;
            var_v1 += 0xC;
            var_s1 += 3;
            M2C_FIELD(var_a1, f32 *, 8) = temp_ft0;
            M2C_FIELD(var_a1, f32 *, 0xC) = temp_fv1;
            M2C_FIELD(var_a1, f32 *, 0x10) = (f32) (temp_fv0 + temp_ft1);
            var_a1 += 0xC;
        }
        if (var_s1 < var_t2) goto interpolate;
    }
    var_s1 = 0;
    if (temp_s2 > 0) {
    packed: {
            temp_a0 = (var_s1 + var_t2) * 4;
            temp_v1 = M2C_FIELD((temp_a0 + arg1), u32 *, 8);
            temp_a1 = temp_v1 >> 22;
            temp_a2 = temp_v1 >> 10;
            temp_a3 = temp_v1 << 1;
            temp_v1_2 = M2C_FIELD((temp_a0 + arg2), u32 *, 8);
            temp_a1 *= 4;
            temp_ft0_2 = (f32)((s32)(((temp_v1_2 >> 22) * 4U - temp_a1) << 20) >> 20) * arg3;
            temp_a2 &= 0xFFE;
            temp_a3 &= 0xFFE;
            temp_fv1_2 = (f32) ((s32)((((temp_v1_2 >> 10) & 0xFFE) - temp_a2) << 20) >> 20) * arg3;
            temp_fv0_2 = (f32) ((s32)((((temp_v1_2 * 2) & 0xFFE) - temp_a3) << 20) >> 20) * arg3;
            var_s1 += 1;
            M2C_FIELD((temp_a0 + arg0), s32 *, 8) = (s32) (((s32) (((s32) temp_fv0_2 + temp_a3) & 0xFFE) >> 1) | ((((s32) temp_fv1_2 + temp_a2) & 0xFFE) << 0xA) | ((u32)(((s32)temp_ft0_2 + temp_a1) >> 2) << 22));
        }
        if (var_s1 < temp_s2) goto packed;
    }
    if (callbackFlag) {
        var_s1 = 0;
        if (temp_s2 > 0) {
            var_s0 = 2;
            do {
                var_a3 = temp_s6 + var_s0;
                var_s0 += 4;
                var_s1 += 1;
                temp_a0 = var_a3 * 4;
                D_800D941C(arg3, arg1 + temp_a0, arg2 + temp_a0, arg0 + temp_a0);
            } while (var_s1 < temp_s2);
        }
    }
}

