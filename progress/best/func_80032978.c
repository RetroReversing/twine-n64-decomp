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

s32 func_800326BC();
s32 func_80032830();
extern s8 D_80109A94;
extern void *D_8010A510;

void func_80032978(void *arg0, u32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 *arg5) {
    u8 sp17;
    s32 sp1C;
    s32 temp_a0_3;
    s32 temp_a0_6;
    s32 temp_a2;
    s32 temp_a2_2;
    s32 temp_a2_3;
    s32 temp_a3;
    s32 temp_s0;
    s32 temp_s0_2;
    s32 temp_s0_3;
    s32 temp_s0_4;
    s32 temp_s0_5;
    s32 temp_s0_6;
    s32 temp_s0_7;
    s32 temp_s6;
    s32 temp_s7;
    s32 temp_v0_2;
    s32 temp_v1_2;
    s32 temp_v1_3;
    s32 var_a1_3;
    s32 var_a2;
    s32 var_a2_2;
    s32 var_v0;
    s32 var_v0_2;
    s32 var_v0_3;
    s32 var_v0_4;
    s32 var_v0_5;
    s32 var_v0_6;
    s32 var_v0_7;
    s32 var_v1_4;
    u32 temp_a0;
    u32 temp_a0_4;
    u32 temp_a0_7;
    u32 temp_a0_9;
    u32 temp_s2;
    u32 temp_s3;
    u32 var_a0;
    u32 var_a1_2;
    u32 var_a3;
    u32 var_a3_2;
    u32 var_a3_3;
    u32 var_a3_4;
    u32 var_v1;
    u32 var_v1_2;
    u32 var_v1_3;
    u32 var_v1_5;
    u32 var_v1_6;
    u8 temp_v1;
    void *temp_a0_2;
    void *temp_a0_5;
    void *temp_a0_8;
    void *temp_a1;
    void *temp_a1_2;
    void *temp_a1_3;
    void *temp_s1;
    void *temp_s1_2;
    void *temp_s1_3;
    void *temp_s1_4;
    void *temp_s1_5;
    void *temp_s1_6;
    void *temp_v0;
    void *var_a1;

    temp_a1 = (M2C_FIELD(arg0, u8 *, 1) * 0xC) + arg2;
    temp_v1 = M2C_FIELD(temp_a1, u8 *, 0);
    sp17 = (u8) arg4;
    temp_s7 = -((temp_v1 & 2) != 0) & 3;
    temp_s6 = -((temp_v1 & 4) != 0) & 3;
    if (((arg4 << 0x18) != 0) && (M2C_FIELD(temp_a1, u8 *, 6) != 1)) {
        D_80109A94 = 1;
        func_800326BC(arg2 + (M2C_FIELD(arg0, u8 *, 1) * 0xC), temp_a1);
    }
    temp_v0 = (M2C_FIELD(arg0, u8 *, 1) * 0xC) + arg2;
    temp_s2 = M2C_FIELD(temp_v0, u16 *, 2) + 1;
    sp1C = M2C_FIELD(temp_v0, s32 *, 8);
    temp_s3 = M2C_FIELD(temp_v0, u16 *, 4) + 1;
    switch (arg1) {
    case 1:
    case 2:
    case 3:
    case 4:
    case 7:
    case 8:
    case 10:
    case 12:
    case 13:
    case 14:
    case 16:
        if (*(s32 *)((M2C_FIELD(arg0, u8 *, 1) * 0xC) + arg2) & 1) {
            if ((sp17 << 0x18) != 0) {
                temp_s1 = D_8010A510;
                D_8010A510 = temp_s1 + 8;
                M2C_FIELD(temp_s1, s32 *, 0) = 0xFD500000;
                M2C_FIELD(temp_s1, s32 *, 4) = (s32) (sp1C & ~7);
                D_8010A510 = temp_s1 + 0x10;
                M2C_FIELD(temp_s1, s32 *, 8) = 0xF5500000;
                temp_s0 = func_80032830(temp_s3);
                var_a3 = 0x800;
                temp_a1_2 = D_8010A510;
                temp_a0 = temp_s2 >> 3;
                M2C_FIELD(temp_s1, s32 *, 0xC) = (s32) ((temp_s6 << 0x12) | (((temp_s0 & 0xF) << 0xE) | 0x07000000) | (temp_s7 << 8) | ((func_80032830(temp_s2) & 0xF) * 0x10));
                D_8010A510 = temp_a1_2 + 8;
                M2C_FIELD(temp_a1_2, s32 *, 0) = 0xE6000000;
                D_8010A510 = temp_a1_2 + 0x10;
                M2C_FIELD(temp_a1_2, s32 *, 4) = 0;
                M2C_FIELD(temp_a1_2, s32 *, 8) = 0xF3000000;
                if (temp_a0 != 0) {
                    var_a3 = temp_a0 + 0x7FF;
                }
                var_v1 = ((u32) ((temp_s2 * temp_s3) + 1) >> 1) - 1;
                if (var_v1 >= 0x800U) {
                    var_v1 = 0x7FF;
                }
                temp_a2 = ((var_v1 & 0xFFF) << 0xC) | 0x07000000;
                if (temp_a0 != 0) {
                    var_v0 = (var_a3 / temp_a0) & 0xFFF;
                } else {
                    var_v0 = var_a3 & 0xFFF;
                }
                M2C_FIELD(temp_a1_2, s32 *, 0xC) = (s32) (temp_a2 | var_v0);
                temp_s1_2 = D_8010A510;
                D_8010A510 = temp_s1_2 + 8;
                M2C_FIELD(temp_s1_2, s32 *, 0) = 0xE7000000;
                D_8010A510 = temp_s1_2 + 0x10;
                M2C_FIELD(temp_s1_2, s32 *, 4) = 0;
                M2C_FIELD(temp_s1_2, s32 *, 8) = (s32) (((((u32) (temp_s2 + 7) >> 3) & 0x1FF) << 9) | 0xF5480000);
                temp_s0_2 = func_80032830(temp_s3, temp_a1_2, temp_a2, var_a3);
                temp_a0_2 = D_8010A510;
                M2C_FIELD(temp_s1_2, s32 *, 0xC) = (s32) ((temp_s6 << 0x12) | ((temp_s0_2 & 0xF) << 0xE) | (temp_s7 << 8) | ((func_80032830(temp_s2) & 0xF) * 0x10));
                D_8010A510 = temp_a0_2 + 8;
                M2C_FIELD(temp_a0_2, s32 *, 0) = 0xF2000000;
                M2C_FIELD(temp_a0_2, s32 *, 4) = (s32) (((((temp_s2 - 1) * 4) & 0xFFF) << 0xC) | (((temp_s3 - 1) * 4) & 0xFFF));
            } else {
                *arg5 += 7;
            }
            if (!(*(s32 *)((M2C_FIELD(arg0, u8 *, 1) * 0xC) + arg2) & 1)) {
                goto block_17;
            }
        } else {
block_17:
            temp_v0_2 = temp_s7 == 0;
            if ((sp17 << 0x18) != 0) {
                var_a1 = NULL;
                var_a2 = 0;
                if (temp_v0_2 & (temp_s6 == 0)) {
                    temp_a3 = temp_s3 == 0x40;
                    if ((temp_s2 == 0x40) & temp_a3) {
                        var_a1 = (void *)1;
                        var_a2 = 5;
                    } else {
                        temp_a0_3 = temp_s2 == 0x20;
                        if (temp_a0_3 & (temp_s3 == 0x80)) {
                            var_a1 = (void *)1;
                            var_a2 = 4;
                        } else {
                            temp_v1_2 = temp_s3 == 0x20;
                            if ((temp_s2 == 0x80) & temp_v1_2) {
                                var_a1 = (void *)1;
                                var_a2 = 3;
                            } else if (temp_a0_3 & temp_a3) {
                                var_a1 = (void *)1;
                                var_a2 = 2;
                            } else if (temp_a0_3 & temp_v1_2) {
                                var_a1 = (void *)1;
                                var_a2 = 1;
                            }
                        }
                    }
                }
                temp_s1_3 = D_8010A510;
                D_8010A510 = temp_s1_3 + 8;
                M2C_FIELD(temp_s1_3, s32 *, 0) = 0xFD500000;
                M2C_FIELD(temp_s1_3, s32 *, 4) = sp1C;
                if (var_a1 != NULL) {
                    var_v1_2 = 0x800;
                    D_8010A510 = temp_s1_3 + 0x10;
                    M2C_FIELD(temp_s1_3, s32 *, 8) = 0xE6000000;
                    D_8010A510 = temp_s1_3 + 0x18;
                    var_a1_2 = temp_s2 >> 4;
                    M2C_FIELD(temp_s1_3, s32 *, 0xC) = 0;
                    M2C_FIELD(temp_s1_3, s32 *, 0x10) = 0xF3000000;
                    if (var_a1_2 != 0) {
                        var_v1_2 = var_a1_2 + 0x7FF;
                    }
                    var_a0 = ((u32) ((temp_s2 * temp_s3) + 3) >> 2) - 1;
                    var_a2_2 = var_a2 << 0x18;
                    if (var_a0 >= 0x800U) {
                        var_a0 = 0x7FF;
                    }
                    if (var_a1_2 != 0) {
                        var_v0_2 = (var_v1_2 / var_a1_2) & 0xFFF;
                    } else {
                        var_v0_2 = var_v1_2 & 0xFFF;
                    }
                    M2C_FIELD(temp_s1_3, s32 *, 0x14) = (s32) (var_a2_2 | ((var_a0 & 0xFFF) << 0xC) | var_v0_2);
                } else {
                    D_8010A510 = temp_s1_3 + 0x10;
                    M2C_FIELD(temp_s1_3, s32 *, 8) = 0xF5500000;
                    temp_s0_3 = func_80032830(temp_s3, var_a1, var_a2);
                    var_a3_2 = 0x800;
                    var_a1_2 = (u32) D_8010A510;
                    temp_a0_4 = temp_s2 >> 4;
                    M2C_FIELD(temp_s1_3, s32 *, 0xC) = (s32) ((temp_s6 << 0x12) | (((temp_s0_3 & 0xF) << 0xE) | 0x07000000) | (temp_s7 << 8) | ((func_80032830(temp_s2) & 0xF) * 0x10));
                    D_8010A510 = var_a1_2 + 8;
                    M2C_FIELD(var_a1_2, s32 *, 0) = 0xE6000000;
                    D_8010A510 = var_a1_2 + 0x10;
                    M2C_FIELD(var_a1_2, s32 *, 4) = 0;
                    M2C_FIELD(var_a1_2, s32 *, 8) = 0xF3000000;
                    if (temp_a0_4 != 0) {
                        var_a3_2 = temp_a0_4 + 0x7FF;
                    }
                    var_v1_3 = ((u32) ((temp_s2 * temp_s3) + 3) >> 2) - 1;
                    if (var_v1_3 >= 0x800U) {
                        var_v1_3 = 0x7FF;
                    }
                    var_a2_2 = ((var_v1_3 & 0xFFF) << 0xC) | 0x07000000;
                    if (temp_a0_4 != 0) {
                        var_v0_3 = (var_a3_2 / temp_a0_4) & 0xFFF;
                    } else {
                        var_v0_3 = var_a3_2 & 0xFFF;
                    }
                    M2C_FIELD(var_a1_2, s32 *, 0xC) = (s32) (var_a2_2 | var_v0_3);
                }
                var_v1_4 = 0xF5400000;
block_79:
                D_8010A510 += 8;
                M2C_FIELD(D_8010A510, s32 *, 0) = 0xE7000000;
                D_8010A510 += 0x10;
                M2C_FIELD(D_8010A510, s32 *, 4) = 0;
                M2C_FIELD(D_8010A510, s32 *, 8) = (s32) (((((u32) ((temp_s2 >> 1) + 7) >> 3) & 0x1FF) << 9) | var_v1_4);
                temp_s0_4 = func_80032830(temp_s3, (void *) var_a1_2, var_a2_2);
                temp_a0_5 = D_8010A510;
                M2C_FIELD(D_8010A510, s32 *, 0xC) = (s32) ((temp_s6 << 0x12) | ((temp_s0_4 & 0xF) << 0xE) | (temp_s7 << 8) | ((func_80032830(temp_s2) & 0xF) * 0x10));
                D_8010A510 = temp_a0_5 + 8;
                M2C_FIELD(temp_a0_5, s32 *, 0) = 0xF2000000;
                M2C_FIELD(temp_a0_5, s32 *, 4) = (s32) (((((temp_s2 - 1) * 4) & 0xFFF) << 0xC) | (((temp_s3 - 1) * 4) & 0xFFF));
                return;
            }
            var_a1_3 = 0;
            if (temp_v0_2 & (temp_s6 == 0)) {
                temp_a2_2 = temp_s3 == 0x40;
                if (((temp_s2 == 0x40) & temp_a2_2) || (temp_a0_6 = temp_s2 == 0x20, ((temp_a0_6 & (temp_s3 == 0x80)) != 0)) || (temp_v1_3 = temp_s3 == 0x20, (((temp_s2 == 0x80) & temp_v1_3) != 0)) || (temp_a0_6 & temp_a2_2) || (var_v0_4 = 0, ((temp_a0_6 & temp_v1_3) != 0))) {
                    var_a1_3 = 1;
                    goto block_54;
                }
            } else {
block_54:
                var_v0_4 = var_a1_3;
            }
            if (var_v0_4 == 0) {
                *arg5 += 1;
            }
            var_v0_5 = *arg5 + 6;
block_81:
            *arg5 = var_v0_5;
        default:
            return;
        }
        break;
    case 5:
    case 6:
    case 9:
    case 15:
        if (*(s32 *)((M2C_FIELD(arg0, u8 *, 1) * 0xC) + arg2) & 1) {
            if ((sp17 << 0x18) != 0) {
                temp_s1_4 = D_8010A510;
                D_8010A510 = temp_s1_4 + 8;
                M2C_FIELD(temp_s1_4, s32 *, 0) = 0xFD900000;
                M2C_FIELD(temp_s1_4, s32 *, 4) = (s32) (sp1C & ~7);
                D_8010A510 = temp_s1_4 + 0x10;
                M2C_FIELD(temp_s1_4, s32 *, 8) = 0xF5900000;
                temp_s0_5 = func_80032830(temp_s3);
                var_a3_3 = 0x800;
                temp_a1_3 = D_8010A510;
                temp_a0_7 = temp_s2 >> 3;
                M2C_FIELD(temp_s1_4, s32 *, 0xC) = (s32) ((temp_s6 << 0x12) | (((temp_s0_5 & 0xF) << 0xE) | 0x07000000) | (temp_s7 << 8) | ((func_80032830(temp_s2) & 0xF) * 0x10));
                D_8010A510 = temp_a1_3 + 8;
                M2C_FIELD(temp_a1_3, s32 *, 0) = 0xE6000000;
                D_8010A510 = temp_a1_3 + 0x10;
                M2C_FIELD(temp_a1_3, s32 *, 4) = 0;
                M2C_FIELD(temp_a1_3, s32 *, 8) = 0xF3000000;
                if (temp_a0_7 != 0) {
                    var_a3_3 = temp_a0_7 + 0x7FF;
                }
                var_v1_5 = ((u32) ((temp_s2 * temp_s3) + 1) >> 1) - 1;
                if (var_v1_5 >= 0x800U) {
                    var_v1_5 = 0x7FF;
                }
                temp_a2_3 = ((var_v1_5 & 0xFFF) << 0xC) | 0x07000000;
                if (temp_a0_7 != 0) {
                    var_v0_6 = (var_a3_3 / temp_a0_7) & 0xFFF;
                } else {
                    var_v0_6 = var_a3_3 & 0xFFF;
                }
                M2C_FIELD(temp_a1_3, s32 *, 0xC) = (s32) (temp_a2_3 | var_v0_6);
                temp_s1_5 = D_8010A510;
                D_8010A510 = temp_s1_5 + 8;
                M2C_FIELD(temp_s1_5, s32 *, 0) = 0xE7000000;
                D_8010A510 = temp_s1_5 + 0x10;
                M2C_FIELD(temp_s1_5, s32 *, 4) = 0;
                M2C_FIELD(temp_s1_5, s32 *, 8) = (s32) (((((u32) (temp_s2 + 7) >> 3) & 0x1FF) << 9) | 0xF5880000);
                temp_s0_6 = func_80032830(temp_s3, temp_a1_3, temp_a2_3, var_a3_3);
                temp_a0_8 = D_8010A510;
                M2C_FIELD(temp_s1_5, s32 *, 0xC) = (s32) ((temp_s6 << 0x12) | ((temp_s0_6 & 0xF) << 0xE) | (temp_s7 << 8) | ((func_80032830(temp_s2) & 0xF) * 0x10));
                D_8010A510 = temp_a0_8 + 8;
                M2C_FIELD(temp_a0_8, s32 *, 0) = 0xF2000000;
                M2C_FIELD(temp_a0_8, s32 *, 4) = (s32) (((((temp_s2 - 1) * 4) & 0xFFF) << 0xC) | (((temp_s3 - 1) * 4) & 0xFFF));
            } else {
                *arg5 += 7;
            }
            if (!(*(s32 *)((M2C_FIELD(arg0, u8 *, 1) * 0xC) + arg2) & 1)) {
                goto block_70;
            }
        } else {
block_70:
            if ((sp17 << 0x18) != 0) {
                temp_s1_6 = D_8010A510;
                D_8010A510 = temp_s1_6 + 8;
                M2C_FIELD(temp_s1_6, s32 *, 0) = 0xFD900000;
                M2C_FIELD(temp_s1_6, s32 *, 4) = (s32) (sp1C & ~7);
                D_8010A510 = temp_s1_6 + 0x10;
                M2C_FIELD(temp_s1_6, s32 *, 8) = 0xF5900000;
                temp_s0_7 = func_80032830(temp_s3);
                var_a3_4 = 0x800;
                var_a1_2 = (u32) D_8010A510;
                temp_a0_9 = temp_s2 >> 4;
                M2C_FIELD(temp_s1_6, s32 *, 0xC) = (s32) ((temp_s6 << 0x12) | (((temp_s0_7 & 0xF) << 0xE) | 0x07000000) | (temp_s7 << 8) | ((func_80032830(temp_s2) & 0xF) * 0x10));
                D_8010A510 = var_a1_2 + 8;
                M2C_FIELD(var_a1_2, s32 *, 0) = 0xE6000000;
                D_8010A510 = var_a1_2 + 0x10;
                M2C_FIELD(var_a1_2, s32 *, 4) = 0;
                M2C_FIELD(var_a1_2, s32 *, 8) = 0xF3000000;
                if (temp_a0_9 != 0) {
                    var_a3_4 = temp_a0_9 + 0x7FF;
                }
                var_v1_6 = ((u32) ((temp_s2 * temp_s3) + 3) >> 2) - 1;
                if (var_v1_6 >= 0x800U) {
                    var_v1_6 = 0x7FF;
                }
                var_a2_2 = ((var_v1_6 & 0xFFF) << 0xC) | 0x07000000;
                if (temp_a0_9 != 0) {
                    var_v0_7 = (var_a3_4 / temp_a0_9) & 0xFFF;
                } else {
                    var_v0_7 = var_a3_4 & 0xFFF;
                }
                M2C_FIELD(var_a1_2, s32 *, 0xC) = (s32) (var_a2_2 | var_v0_7);
                var_v1_4 = 0xF5800000;
                goto block_79;
            }
            var_v0_5 = *arg5 + 7;
            goto block_81;
        }
        break;
    }
}
