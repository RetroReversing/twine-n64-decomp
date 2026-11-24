/* machine draft (m2c) for gcc-2.7.2-kmc -G0 -mips3 -mgp32 -mfp32 -O2 -fno-schedule-insns, tried by autopilot */

extern s32 (*gAnimPoseExtraLerpCallback)(f32, void *, void *, void *);

/* Linearly interpolates between two animation poses (floats, packed 11-bit vectors, optional callback data) by t into dst. */ void lerpAnimPose(u8 *dst, const u8 *poseA, const u8 *poseB, f32 t) {
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
    
    s32 callbackFlag;
    s32 packedCount;
    s32 extraBase;
    s32 temp_v0;
    s32 var_a3;
    s32 var_s0;
    s32 i;
    long var_s1_2;
    s32 var_s1_3;
    s32 floatWords;
    u32 temp_v1;
    void *var_a0;
    s32 shift_stage;
    s32 ymid;

    temp_v0 = (*(const s32 *)((char *)(poseA) + 0));
    packedCount = temp_v0 >> 0x10;
    callbackFlag = temp_v0 & 1;
    (*(s32 *)((char *)(dst) + 0)) = temp_v0;
    if (temp_v0 & 2) {
        floatWords = packedCount * 3;
    } else {
        floatWords = 3;
    }
    i = 0;
    extraBase = floatWords + packedCount;
    if (i < floatWords) {
        var_a1 = dst;
        var_a0 = poseB;
        var_v1 = poseA;
    interpolate: {
            (*(f32 *)((char *)(var_a1) + 8)) = ((*(const f32 *)((char *)(var_a0) + 8)) - (*(const f32 *)((char *)(var_v1) + 8))) * t + (*(const f32 *)((char *)(var_v1) + 8));
            (*(f32 *)((char *)(var_a1) + 0xC)) = ((*(const f32 *)((char *)(var_a0) + 0xC)) - (*(const f32 *)((char *)(var_v1) + 0xC))) * t + (*(const f32 *)((char *)(var_v1) + 0xC));
            (*(f32 *)((char *)(var_a1) + 0x10)) = ((*(const f32 *)((char *)(var_a0) + 0x10)) - (*(const f32 *)((char *)(var_v1) + 0x10))) * t + (*(const f32 *)((char *)(var_v1) + 0x10));
            var_a0 += 0xC;
            var_v1 += 0xC;
            i += 3;
            var_a1 += 0xC;
        }
        if (i < floatWords) goto interpolate;
    }
    i = 0;
    if (i < packedCount) {
    s32 temp_a0_arm;
    packed: {
            s32 resultX, resultY, resultZ;
            temp_a0_arm = (i + floatWords) * 4;
            temp_v1 = ((u32 (*)[0x1]) poseA)[temp_a0_arm >> 2][0x2];
            temp_a1 = temp_v1 >> 22;
            temp_a2 = temp_v1 >> 10;
            var_a3 = temp_v1 << 1;
            temp_v1 = ((u32 (*)[0x1]) poseB)[temp_a0_arm >> 2][0x2];
            temp_a1 = (u32)temp_a1 << 2;
            do {
              shift_stage = (temp_v1 >> 22) * 4;
            } while (0);
            do {
              ymid = (temp_v1 >> 10) & 0xFFE;
            } while (0);
            temp_ft0_2 = (f32)((s32)((shift_stage - temp_a1) << 20) >> 20) * t;
            temp_a2 &= 0xFFE;
            var_a3 &= 0xFFE;
            i += 1;
            temp_fv1_2 = (f32) ((s32)((ymid - temp_a2) << 20) >> 20) * t;
            temp_v1 = temp_v1 * 2;
            temp_fv0_2 = (f32) ((s32)((((temp_v1) & 0xFFE) - var_a3) << 20) >> 20) * t;
            shift_stage = (s32)temp_ft0_2 + temp_a1;
            ymid = (s32)temp_fv1_2 + temp_a2;
            temp_v0 = (s32)temp_fv0_2 + var_a3;
            ((u32 (*)[0x1]) dst)[temp_a0_arm >> 2][0x2] =
                ((temp_v0 & 0xFFE) >> 1) | ((ymid & 0xFFE) << 10) | ((u32)(shift_stage >> 2) << 22);
        }
        if (i < packedCount) goto packed;
    }
    if (callbackFlag) {
        i = 0;
        if (i < packedCount) {
            var_s0 = 2;
            do {
                var_a3 = extraBase + var_s0;
                var_s0 += 4;
                ++i;
                var_a3 = var_a3 * 4;
                temp_a1 = (s32)(poseA + var_a3);
                temp_a2 = (s32)(poseB + var_a3);
                gAnimPoseExtraLerpCallback(t, (void *)temp_a1, (void *)temp_a2, dst + var_a3);
            } while (i < packedCount);
        }
    }
}



