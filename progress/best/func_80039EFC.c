/* machine draft (m2c) for gcc-2.7.2-kmc -G0 -mips3 -mgp32 -mfp32 -O2, tried by autopilot */

extern f64 D_800D2EF8;
extern f64 D_800D2F00;
extern f64 D_800D2F08;
extern f64 D_800D2F10;
extern f64 D_800D2F18;
extern f64 D_800D2F20;
extern f64 D_800D2F28;
extern s32 D_8010A4E8;

void func_80039EFC(s32 *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6, s32 arg7, s32 arg8, s32 arg9, u32 arg10, u32 arg11, u32 arg12, u32 arg13, f32 arg14, f32 arg15) {
    s32 temp_a2_4;
    unsigned long spC;
    u32 sp14;
    s32 sp1C;
    s32 temp_a1_4;
    s32 sp2C;
    f32 temp_ft1;
    f32 temp_fv0;
    f32 var_fv0;
    f32 var_fv1_3;
    register f64 var_ft0;
    u32 var_t5;
    f64 var_ft0_3;
    u32 var_t2;
    f64 var_fv1;
    f64 var_fv1_2;
    f64 var_ft0_2;
    s32 temp_a0_2;
    s32 sp24;
    f64 var_ft0_4;
    s32 temp_a1_2;
    s32 temp_a3;
    void *var_t0;
    s32 temp_a2;
    s32 temp_a2_2;
    void *temp_t0_13;
    register s32 *sp4;
    s32 temp_a1_3;
    register s32 temp_fv1;
    s32 temp_t3;
    s32 temp_t7;
    s32 temp_v1;
    s32 temp_v1_2;
    s32 var_a0;
    s32 temp_a1;
    s32 var_t1;
    void *temp_t0_9;
    s32 var_t6;
    s32 var_t8;
    s32 var_v1;
    unsigned int temp_s0;
    register u32 temp_s1;
    register s32 var_a0_2;
    s32 temp_a2_3;
    void *temp_t0_7;
    s32 temp_a0;
    void *temp_t0;
    void *temp_t0_10;
    void *temp_t0_11;
    void *temp_t0_12;
    u32 var_a3;
    void *temp_t0_2;
    void *temp_t0_3;
    void *temp_t0_4;
    void *temp_t0_5;
    void *temp_t0_6;
    u32 var_t4;
    void *temp_t0_8;
    s32 var_t1_2;
    s32 temp_a0_3;
    void *var_t0_2;
    void *var_t0_3;

    sp4 = arg0;
    spC = arg3;
    var_t1 = *arg0;
    var_ft0 = (f64) arg6;
    if (0 > arg6) {
        var_ft0 += D_800D2EF8;
    }
    var_fv1 = (f64) arg4;
    if (arg4 < 0) {
        var_fv1 += D_800D2F00;
    }
    var_ft0_2 = (f64) arg7;
    if (arg7 < 0) {
        var_ft0_2 += D_800D2F08;
    }
    var_fv1_2 = (f64) arg5;
    if (arg5 < 0) {
        var_fv1_2 += D_800D2F10;
    }
    var_ft0_3 = (f64) arg8;
    if (arg8 < 0) {
        var_ft0_3 += D_800D2F18;
    }
    var_ft0_4 = (f64) arg9;
    temp_fv1 = (s32) ((f32) var_ft0_3 * ((f32) var_ft0 / (f32) var_fv1));
    if (arg9 < 0) {
        var_ft0_4 += D_800D2F20;
    }
    var_t5 = arg11;
    var_t8 = (s32) arg15;
    sp2C = (s32) ((f32) var_ft0_4 * ((f32) var_ft0_2 / (f32) var_fv1_2));
    if (var_t5 < arg13) {
        temp_s1 = arg12 - 1;
        temp_s0 = arg13 - 1;
        temp_t7 = (arg2 & 7) << 0x15;
        sp14 = (u32) arg4 >> 1;
        __repair_rows: {
            var_t4 = arg10;
            var_t6 = (s32) arg14;
            if (var_t4 < arg12) {
                register var_t0 = var_t1 - 4;
                sp1C = temp_t7 | (((sp14 - 1) & 0xFFF) | 0xFD080000);
                sp24 = temp_t7 | (((arg4 - 1) & 0xFFF) | 0xFD080000);
                temp_ft1 = (f32) ((f64) (f32) var_t5 + D_800D2F28);
                do {
                    temp_a1 = var_t4 - 1;
                    temp_t3 = temp_a1 & ((s32) ~temp_a1 >> 0x1F);
                    var_t2 = var_t4 + arg8;
                    temp_fv0 = (f32) ((f64) (f32) var_t4 + D_800D2F28);
                    if (var_t2 > temp_s1) {
                        var_t2 = temp_s1;
                    }
                    temp_a0 = var_t5 - 1;
                    temp_a2_2 = temp_a0 & ((s32) ~temp_a0 >> 0x1F);
                    var_a3 = var_t5 + arg9;
                    if (var_a3 > temp_s0) {
                        var_a3 = temp_s0;
                    }
                    temp_t0 = var_t0 + 8;
                    if (spC == 0) {
                        temp_a0 = (((s32) (((s32) ((var_t2 - temp_t3) + 1) >> 1) + 7) >> 3) & 0x1FF) << 9;
                        temp_a1_2 = (temp_a2_2 * 4) & 0xFFF;
                        temp_a2_3 = (temp_s0 * 4) & 0xFFF;
                        var_t1_2 = var_t1 + 0x38;
                        (*(s32 *)((char *)(var_t0) + 8)) = arg1;
                        (*(s32 *)((char *)(temp_t0) + -4)) = sp1C;
                        temp_t0_2 = temp_t0 + 8;
                        (*(s32 *)((char *)(temp_t0_2) + -4)) = (s32) (temp_t7 | (temp_a0 | 0xF5080000));
                        (*(s32 *)((char *)(temp_t0) + 8)) = 0x07080200;
                        temp_t0_3 = temp_t0_2 + 8;
                        (*(s32 *)((char *)(temp_t0_3) + -4)) = 0xE6000000;
                        (*(s32 *)((char *)(temp_t0_2) + 8)) = 0;
                        temp_t0_4 = temp_t0_3 + 8;
                        (*(s32 *)((char *)(temp_t0_4) + -4)) = (s32) ((((temp_t3 * 2) & 0xFFF) << 0xC) | (temp_a1_2 | (unsigned short)0xF4000000));
                        (*(s32 *)((char *)(temp_t0_3) + 8)) = (s32) ((((var_t2 * 2) & 0xFFF) << 0xC) | (temp_a2_3 | 0x07000000));
                        temp_t0_5 = temp_t0_4 + 8;
                        (*(s32 *)((char *)(temp_t0_5) + -4)) = 0xE7000000;
                        (*(s32 *)((char *)(temp_t0_4) + 8)) = 0;
                        temp_t0_6 = temp_t0_5 + 8;
                        (*(s32 *)((char *)(temp_t0_6) + -4)) = (s32) (temp_t7 | (temp_a0 | 0xF5000000));
                        var_t0_2 = temp_t0_6 + 8;
                        (*(s32 *)((char *)(temp_t0_5) + 8)) = 0x80200;
                        (*(s32 *)((char *)(var_t0_2) + -4)) = (s32) ((((temp_t3 * 4) & 0xFFF) << 0xC) | (temp_a1_2 | 0xF2000000));
                        (*(s32 *)((char *)(temp_t0_6) + 8)) = (s32) ((((var_t2 * 4) & 0xFFF) << 0xC) | temp_a2_3);
                    } else {
                        temp_v1 = temp_t7 | (((((s32) ((var_t2 - temp_t3) + 8) >> 3) & 0x1FF) << 9) | 0xF5080000);
                        temp_a1_3 = ((temp_t3 * 4) & 0xFFF) << 0xC;
                        temp_a2_4 = (temp_a2_2 * 4) & 0xFFF;
                        temp_a0_2 = ((var_t2 * 4) & 0xFFF) << 0xC;
                        temp_a3 = (var_a3 * 4) & 0xFFF;
                        var_t1_2 = var_t1 + 0x38;
                        (*(s32 *)((char *)(var_t0) + 8)) = arg1;
                        (*(s32 *)((char *)(temp_t0) + -4)) = sp24;
                        temp_t0_7 = temp_t0 + 8;
                        (*(s32 *)((char *)(temp_t0_7) + -4)) = temp_v1;
                        (*(s32 *)((char *)(temp_t0) + 8)) = 0x07080200;
                        temp_t0_8 = temp_t0_7 + 8;
                        (*(s32 *)((char *)(temp_t0_8) + -4)) = 0xE6000000;
                        (*(s32 *)((char *)(temp_t0_7) + 8)) = 0;
                        temp_t0_9 = temp_t0_8 + 8;
                        (*(s32 *)((char *)(temp_t0_9) + -4)) = (s32) (temp_a1_3 | (temp_a2_4 | 0xF4000000));
                        (*(s32 *)((char *)(temp_t0_8) + 8)) = (s32) (temp_a0_2 | (temp_a3 | 0x07000000));
                        temp_t0_10 = temp_t0_9 + 8;
                        (*(s32 *)((char *)(temp_t0_10) + -4)) = 0xE7000000;
                        (*(s32 *)((char *)(temp_t0_9) + 8)) = 0;
                        temp_t0_11 = temp_t0_10 + 8;
                        (*(s32 *)((char *)(temp_t0_11) + -4)) = temp_v1;
                        (*(s32 *)((char *)(temp_t0_10) + 8)) = 0x80200;
                        var_t0_2 = temp_t0_11 + 8;
                        (*(s32 *)((char *)(temp_t0_11) + 8)) = (s32) (temp_a0_2 | temp_a3);
                        (*(s32 *)((char *)(var_t0_2) + -4)) = (s32) (temp_a1_3 | (temp_a2_4 | 0xF2000000));
                    }
                    var_a0 = var_t6 + temp_fv1;
                    var_v1 = var_t8 + sp2C;
                    if (var_a0 >= 0x141) {
                        var_a0 = 0x140;
                    }
                    if (var_v1 >= 0xF1) {
                        var_v1 = 0xF0;
                    }
                    temp_t3 = var_a0 * 4;
                    temp_v1_2 = var_v1 * 4;
                    temp_a0 = var_t6 * 4;
                    if (D_8010A4E8 != 0) {
                        temp_t0_12 = var_t0_2 + 8;
                        var_fv1_3 = temp_fv0 * 32.0f;
                        (*(s32 *)((char *)(temp_t0_12) + -4)) = (s32) (((temp_t3 & 0xFFF) << 0xC) | (((temp_v1_2 * 2) & 0xFFF) | 0xE4000000));
                        (*(s32 *)((char *)(var_t0_2) + 8)) = (s32) (((temp_a0 & 0xFFF) << 0xC) | ((var_t8 * 8) & 0xFFF));
                        var_t0_3 = temp_t0_12 + 8;
                        var_t1 = var_t1_2 + 0x18;
                        var_fv0 = temp_ft1 * 32.0f;
                        var_a0_2 = 0x04000200;
                    } else {
                        temp_t0_13 = var_t0_2 + 8;
                        (*(s32 *)((char *)(temp_t0_13) + -4)) = (s32) (((temp_t3 & 0xFFF) << 0xC) | ((temp_v1_2 & 0xFFF) | 0xE4000000));
                        var_fv1_3 = temp_fv0 * 32.0f;
                        (*(s32 *)((char *)(var_t0_2) + 8)) = (s32) (((temp_a0 & 0xFFF) << 0xC) | ((var_t8 * 4) & 0xFFF));
                        var_t0_3 = temp_t0_13 + 8;
                        var_t1 = var_t1_2 + 0x18;
                        var_fv0 = temp_ft1 * 32.0f;
                        var_a0_2 = 0x04000400;
                    }
                    (*(s32 *)((char *)(var_t0_3) + -4)) = 0xE1000000;
                    (*(s32 *)((char *)(var_t0_3) + 0)) = (s32) (((s32) var_fv1_3 << 0x10) | ((s32) var_fv0 & 0xFFFF));
                    var_t0 = var_t0_3 + 8;
                    (*(s32 *)((char *)(var_t0) + -4)) = 0xF1000000;
                    (*(s32 *)((char *)(var_t0_3) + 8)) = var_a0_2;
                    var_t4 += (s32)arg8;
                    var_t6 += temp_fv1;
                } while (var_t4 < arg12);
            }
            var_t5 += arg9;
            var_t8 += sp2C;
        }
if (var_t5 < arg13) goto __repair_rows;
    }
    *sp4 = var_t1;
}
