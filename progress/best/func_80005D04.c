/* machine draft (m2c) for gcc-2.7.2-kmc -G0 -mips3 -mgp32 -mfp32 -O2 -fno-schedule-insns, tried by autopilot */

extern s32 (*D_800D941C)(f32, void *, void *, void *);

void func_80005D04(u8 *arg0, const u8 *arg1, const u8 *arg2, f32 arg3) {
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
    
    s32 callbackFlag;
    s32 temp_s2;
    s32 temp_s6;
    s32 temp_v0;
    s32 var_a3;
    s32 var_s0;
    s32 var_s1;
    long var_s1_2;
    s32 var_s1_3;
    s32 var_t2;
    u32 temp_v1;
    void *var_a0;
    s32 shift_stage;
    s32 ymid;

    temp_v0 = (*(const s32 *)((char *)(arg1) + 0));
    temp_s2 = temp_v0 >> 0x10;
    callbackFlag = temp_v0 & 1;
    (*(s32 *)((char *)(arg0) + 0)) = temp_v0;
    if (temp_v0 & 2) {
        var_t2 = temp_s2 * 3;
    } else {
        var_t2 = 3;
    }
    var_s1 = 0;
    temp_s6 = var_t2 + temp_s2;
    if (var_s1 < var_t2) {
        var_a1 = arg0;
        var_a0 = arg2;
        var_v1 = arg1;
    interpolate: {
            temp_ft0 = (*(const f32 *)((char *)(var_a0) + 8));
            temp_ft3 = (*(const f32 *)((char *)(var_v1) + 8));
            temp_ft0 -= temp_ft3;
            temp_ft2 = (*(const f32 *)((char *)(var_v1) + 0xC));
            temp_fv1 = ((*(const f32 *)((char *)(var_a0) + 0xC))) - temp_ft2;
            temp_fv0 = (*(const f32 *)((char *)(var_a0) + 0x10));
            temp_ft1 = (*(const f32 *)((char *)(var_v1) + 0x10));
            temp_fv0 -= temp_ft1;
            temp_ft0 *= arg3;
            temp_fv1 *= arg3;
            temp_fv0 *= arg3;
            temp_ft0 += temp_ft3;
            var_a0 += 0xC;
            temp_fv1 += temp_ft2;
            var_v1 += 0xC;
            var_s1 += 3;
            (*(f32 *)((char *)(var_a1) + 8)) = temp_ft0;
            (*(f32 *)((char *)(var_a1) + 0xC)) = temp_fv1;
            (*(f32 *)((char *)(var_a1) + 0x10)) = (f32) (temp_fv0 + temp_ft1);
            var_a1 += 0xC;
        }
        if (var_s1 < var_t2) goto interpolate;
    }
    var_s1 = 0;
    if (var_s1 < temp_s2) {
    s32 temp_a0_arm;
    packed: {
            s32 resultX, resultY, resultZ;
            temp_a0_arm = (var_s1 + var_t2) * 4;
            temp_v1 = ((u32 (*)[0x1]) arg1)[temp_a0_arm >> 2][0x2];
            temp_a1 = temp_v1 >> 22;
            temp_a2 = temp_v1 >> 10;
            temp_a3 = temp_v1 << 1;
            temp_v1 = ((u32 (*)[0x1]) arg2)[temp_a0_arm >> 2][0x2];
            temp_a1 = (u32)temp_a1 << 2;
            do {
              shift_stage = (temp_v1 >> 22) * 4;
            } while (0);
            do {
              ymid = (temp_v1 >> 10) & 0xFFE;
            } while (0);
            temp_ft0_2 = (f32)((s32)((shift_stage - temp_a1) << 20) >> 20) * arg3;
            temp_a2 &= 0xFFE;
            temp_a3 &= 0xFFE;
            var_s1 += 1;
            temp_fv1_2 = (f32) ((s32)((ymid - temp_a2) << 20) >> 20) * arg3;
            temp_fv0_2 = (f32) ((s32)((((temp_v1 * 2) & 0xFFE) - temp_a3) << 20) >> 20) * arg3;
            shift_stage = (s32)temp_ft0_2 + temp_a1;
            ymid = (s32)temp_fv1_2 + temp_a2;
            temp_a3 = (s32)temp_fv0_2 + temp_a3;
            ((u32 (*)[0x1]) arg0)[temp_a0_arm >> 2][0x2] =
                ((temp_a3 & 0xFFE) >> 1) | ((ymid & 0xFFE) << 10) | ((u32)(shift_stage >> 2) << 22);
        }
        if (var_s1 < temp_s2) goto packed;
    }
    if (callbackFlag) {
        var_s1 = 0;
        if (var_s1 < temp_s2) {
            var_s0 = 2;
            do {
                var_a3 = temp_s6 + var_s0;
                var_s0 += 4;
                ++var_s1;
                temp_a0 = var_a3 * 4;
                D_800D941C(arg3, arg1 + temp_a0, arg2 + temp_a0, arg0 + temp_a0);
            } while (var_s1 < temp_s2);
        }
    }
}


