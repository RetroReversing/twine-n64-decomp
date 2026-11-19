/* machine draft (m2c) for gcc-2.7.2-kmc -G0 -mips3 -mgp32 -mfp32 -O1, tried by autopilot */
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

extern f64 D_800D2EF0;
extern s32 D_8010A4E8;

void func_80039A10(s32 *arg0, s32 arg1, s32 arg2, s32 arg3, u32 arg4, s32 arg6, s32 arg7, u32 arg8, u32 arg9, u32 arg10, u32 arg11, f32 arg12, f32 arg13) {
    s32 *sp4;
    s32 spC;
    u32 sp14;
    s32 sp1C;
    s32 sp24;
    u32 sp2C;
    f32 temp_ft1;
    f32 temp_fv0;
    f32 var_fv0;
    f32 var_fv1;
    s32 temp_a0;
    s32 temp_a0_2;
    s32 temp_a0_3;
    s32 temp_a1;
    s32 temp_a1_2;
    s32 temp_a1_3;
    s32 temp_a1_4;
    s32 temp_a2;
    s32 temp_a2_2;
    s32 temp_a2_3;
    s32 temp_a2_4;
    s32 temp_a3;
    s32 temp_t3;
    s32 temp_t8;
    s32 temp_v1;
    s32 temp_v1_3;
    s32 var_a0_2;
    s32 var_t1;
    s32 var_t1_2;
    s32 var_t5;
    s32 var_t7;
    u32 temp_s5;
    u32 temp_t9;
    u32 temp_v1_2;
    u32 var_a0;
    u32 var_a3;
    u32 var_t2;
    u32 var_t4;
    u32 var_t6;
    u32 var_v1;
    void *temp_t0;
    void *temp_t0_10;
    void *temp_t0_11;
    void *temp_t0_12;
    void *temp_t0_13;
    void *temp_t0_2;
    void *temp_t0_3;
    void *temp_t0_4;
    void *temp_t0_5;
    void *temp_t0_6;
    void *temp_t0_7;
    void *temp_t0_8;
    void *temp_t0_9;
    void *var_t0;
    void *var_t0_2;
    void *var_t0_3;

    sp4 = arg0;
    spC = arg3;
    var_t1 = *arg0;
    var_t6 = arg9;
    var_t7 = (s32) arg13;
    if (var_t6 < arg11) {
        temp_s5 = arg10 - 1;
        sp2C = arg11 - 1;
        temp_t8 = (arg2 & 7) << 0x15;
        sp14 = arg4 >> 1;
        do {
            var_t4 = arg8;
            var_t5 = (s32) arg12;
            if (var_t4 < arg10) {
                var_t0 = var_t1 - 4;
                sp1C = temp_t8 | (((sp14 - 1) & 0xFFF) | 0xFD080000);
                sp24 = temp_t8 | (((arg4 - 1) & 0xFFF) | 0xFD080000);
                temp_ft1 = (f32) ((f64) (f32) var_t6 + D_800D2EF0);
                temp_t9 = var_t7 + (arg11 - var_t6);
                do {
                    temp_a1 = var_t4 - 1;
                    temp_t3 = temp_a1 & ((s32) ~temp_a1 >> 0x1F);
                    var_t2 = var_t4 + arg6;
                    temp_fv0 = (f32) ((f64) (f32) var_t4 + D_800D2EF0);
                    if (temp_s5 < var_t2) {
                        var_t2 = temp_s5;
                    }
                    temp_a2 = var_t6 - 1;
                    temp_a2_2 = temp_a2 & ((s32) ~temp_a2 >> 0x1F);
                    var_a3 = var_t6 + arg7;
                    if (sp2C < var_a3) {
                        var_a3 = sp2C;
                    }
                    temp_t0 = var_t0 + 8;
                    if (spC == 0) {
                        temp_a0 = (((s32) (((s32) ((var_t2 - temp_t3) + 1) >> 1) + 7) >> 3) & 0x1FF) << 9;
                        temp_a1_2 = (temp_a2_2 * 4) & 0xFFF;
                        temp_a2_3 = (var_a3 * 4) & 0xFFF;
                        var_t1_2 = var_t1 + 0x38;
                        M2C_FIELD(var_t0, s32 *, 8) = arg1;
                        M2C_FIELD(temp_t0, s32 *, -4) = sp1C;
                        temp_t0_2 = temp_t0 + 8;
                        M2C_FIELD(temp_t0_2, s32 *, -4) = (s32) (temp_t8 | (temp_a0 | 0xF5080000));
                        M2C_FIELD(temp_t0, s32 *, 8) = 0x07080200;
                        temp_t0_3 = temp_t0_2 + 8;
                        M2C_FIELD(temp_t0_3, s32 *, -4) = 0xE6000000;
                        M2C_FIELD(temp_t0_2, s32 *, 8) = 0;
                        temp_t0_4 = temp_t0_3 + 8;
                        M2C_FIELD(temp_t0_4, s32 *, -4) = (s32) ((((temp_t3 * 2) & 0xFFF) << 0xC) | (temp_a1_2 | 0xF4000000));
                        M2C_FIELD(temp_t0_3, s32 *, 8) = (s32) ((((var_t2 * 2) & 0xFFF) << 0xC) | (temp_a2_3 | 0x07000000));
                        temp_t0_5 = temp_t0_4 + 8;
                        M2C_FIELD(temp_t0_5, s32 *, -4) = 0xE7000000;
                        M2C_FIELD(temp_t0_4, s32 *, 8) = 0;
                        temp_t0_6 = temp_t0_5 + 8;
                        M2C_FIELD(temp_t0_6, s32 *, -4) = (s32) (temp_t8 | (temp_a0 | 0xF5000000));
                        M2C_FIELD(temp_t0_5, s32 *, 8) = 0x80200;
                        var_t0_2 = temp_t0_6 + 8;
                        M2C_FIELD(var_t0_2, s32 *, -4) = (s32) ((((temp_t3 * 4) & 0xFFF) << 0xC) | (temp_a1_2 | 0xF2000000));
                        M2C_FIELD(temp_t0_6, s32 *, 8) = (s32) ((((var_t2 * 4) & 0xFFF) << 0xC) | temp_a2_3);
                    } else {
                        temp_v1 = temp_t8 | (((((s32) ((var_t2 - temp_t3) + 8) >> 3) & 0x1FF) << 9) | 0xF5080000);
                        temp_a1_3 = ((temp_t3 * 4) & 0xFFF) << 0xC;
                        temp_a2_4 = (temp_a2_2 * 4) & 0xFFF;
                        temp_a0_2 = ((var_t2 * 4) & 0xFFF) << 0xC;
                        temp_a3 = (var_a3 * 4) & 0xFFF;
                        var_t1_2 = var_t1 + 0x38;
                        M2C_FIELD(var_t0, s32 *, 8) = arg1;
                        M2C_FIELD(temp_t0, s32 *, -4) = sp24;
                        temp_t0_7 = temp_t0 + 8;
                        M2C_FIELD(temp_t0_7, s32 *, -4) = temp_v1;
                        M2C_FIELD(temp_t0, s32 *, 8) = 0x07080200;
                        temp_t0_8 = temp_t0_7 + 8;
                        M2C_FIELD(temp_t0_8, s32 *, -4) = 0xE6000000;
                        M2C_FIELD(temp_t0_7, s32 *, 8) = 0;
                        temp_t0_9 = temp_t0_8 + 8;
                        M2C_FIELD(temp_t0_9, s32 *, -4) = (s32) (temp_a1_3 | (temp_a2_4 | 0xF4000000));
                        M2C_FIELD(temp_t0_8, s32 *, 8) = (s32) (temp_a0_2 | (temp_a3 | 0x07000000));
                        temp_t0_10 = temp_t0_9 + 8;
                        M2C_FIELD(temp_t0_10, s32 *, -4) = 0xE7000000;
                        M2C_FIELD(temp_t0_9, s32 *, 8) = 0;
                        temp_t0_11 = temp_t0_10 + 8;
                        M2C_FIELD(temp_t0_11, s32 *, -4) = temp_v1;
                        M2C_FIELD(temp_t0_10, s32 *, 8) = 0x80200;
                        var_t0_2 = temp_t0_11 + 8;
                        M2C_FIELD(var_t0_2, s32 *, -4) = (s32) (temp_a1_3 | (temp_a2_4 | 0xF2000000));
                        M2C_FIELD(temp_t0_11, s32 *, 8) = (s32) (temp_a0_2 | temp_a3);
                    }
                    var_a0 = var_t5 + arg6;
                    temp_v1_2 = var_t5 + (arg10 - var_t4);
                    if (temp_v1_2 < var_a0) {
                        var_a0 = temp_v1_2;
                    }
                    if ((s32) var_a0 >= 0x141) {
                        var_a0 = 0x140;
                    }
                    var_v1 = var_t7 + arg7;
                    if (temp_t9 < var_v1) {
                        var_v1 = temp_t9;
                    }
                    if ((s32) var_v1 >= 0xF1) {
                        var_v1 = 0xF0;
                    }
                    temp_a0_3 = var_a0 * 4;
                    temp_v1_3 = var_v1 * 4;
                    temp_a1_4 = var_t5 * 4;
                    if (D_8010A4E8 != 0) {
                        temp_t0_12 = var_t0_2 + 8;
                        var_fv1 = temp_fv0 * 32.0f;
                        M2C_FIELD(temp_t0_12, s32 *, -4) = (s32) (((temp_a0_3 & 0xFFF) << 0xC) | (((temp_v1_3 * 2) & 0xFFF) | 0xE4000000));
                        M2C_FIELD(var_t0_2, s32 *, 8) = (s32) (((temp_a1_4 & 0xFFF) << 0xC) | ((var_t7 * 8) & 0xFFF));
                        var_t0_3 = temp_t0_12 + 8;
                        var_t1 = var_t1_2 + 0x18;
                        var_fv0 = temp_ft1 * 32.0f;
                        var_a0_2 = 0x04000200;
                    } else {
                        temp_t0_13 = var_t0_2 + 8;
                        M2C_FIELD(temp_t0_13, s32 *, -4) = (s32) (((temp_a0_3 & 0xFFF) << 0xC) | ((temp_v1_3 & 0xFFF) | 0xE4000000));
                        var_fv1 = temp_fv0 * 32.0f;
                        M2C_FIELD(var_t0_2, s32 *, 8) = (s32) (((temp_a1_4 & 0xFFF) << 0xC) | ((var_t7 * 4) & 0xFFF));
                        var_t0_3 = temp_t0_13 + 8;
                        var_t1 = var_t1_2 + 0x18;
                        var_fv0 = temp_ft1 * 32.0f;
                        var_a0_2 = 0x04000400;
                    }
                    M2C_FIELD(var_t0_3, s32 *, -4) = 0xE1000000;
                    M2C_FIELD(var_t0_3, s32 *, 0) = (s32) (((s32) var_fv1 << 0x10) | ((s32) var_fv0 & 0xFFFF));
                    var_t0 = var_t0_3 + 8;
                    M2C_FIELD(var_t0, s32 *, -4) = 0xF1000000;
                    M2C_FIELD(var_t0_3, s32 *, 8) = var_a0_2;
                    var_t4 += arg6;
                    var_t5 += arg6;
                } while (var_t4 < arg10);
            }
            var_t6 += arg7;
            var_t7 += arg7;
        } while (var_t6 < arg11);
    }
    *sp4 = var_t1;
}
