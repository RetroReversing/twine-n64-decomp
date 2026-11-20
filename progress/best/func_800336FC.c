static __inline__ u8 __repair_inline(u8 a) { return a; }
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

s32 func_800328CC();
s32 func_80032978();
s32 func_800334A4();
s32 func_800A0220();
extern s8 D_80109A94;
extern void *D_8010A510;
extern s32 D_8010D2B4;

typedef struct { unsigned char pad[4]; int value; } __repair_field_4;
void func_800336FC(u8 *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, f32 arg5, s32 arg6, s32 arg7, s32 arg8, s32 *arg9, s32 *arg10) {
    volatile s64 reserve[3];
    s32 sp20;
    void *sp24;
    s32 sp2C;
    u8 sp37;
    s32 temp_s4;
    s32 temp_s4_2;
    s32 temp_s4_3;
    s32 temp_s4_4;
    s32 temp_v0_2;
    s32 var_v0;
    s32 var_v0_2;
    s32 var_v0_3;
    u32 temp_v0_3;
    u32 var_s2;
    u32 var_s2_2;
    u32 var_s2_3;
    u32 var_s2_4;
    u32 var_s2_5;
    u32 var_v1;
    u8 *temp_a1_5;
    u8 *temp_s1;
    u8 *var_a1;
    char *var_a1_2;
    char *var_s0_3;
    char *var_s1;
    u8 temp_a0;
    u8 temp_a2;
    u8 temp_a3;
    u8 temp_t3;
    s32 temp_v0;
    u8 temp_v1;
    u8 temp_v1_2;
    u8 temp_v1_3;
    u8 temp_v1_4;
    u8 temp_v1_5;
    u8 var_v0_4;
u8 __repair_result_var_v0_4;
    void *temp_a0_2;
    void *temp_a0_3;
    void *temp_a0_4;
    void *temp_a0_5;
    void *temp_a1;
    void *temp_a1_2;
    void *temp_a1_3;
    void *temp_a1_4;
    void *temp_v0_4;
    void *temp_v1_6;
    void *var_s0;
    void *var_s0_2;
    void *var_s0_4;
    void *var_s1_2;

    var_s1 = arg0;
    sp2C = arg3;
    sp20 = -1;
    D_80109A94 = 0;
    sp24 = D_8010A510;
    temp_a0 = __repair_inline(*(u8 *)var_s1);
    sp37 = (u8) arg8;
    if ((temp_a0 & 0xFF) != 0xC) {
        var_v1 = temp_a0 & 0xFF;
        var_v0 = var_v1 < 0xCU;
        do {
            if (var_v0 != 0) {
                switch (var_v1) {
                case 9:
                    var_s1 += 4;
                    break;
                case 0:
                    temp_s4 = D_8010D2B4;
                    var_s2 = 0;
                    if (M2C_FIELD(var_s1, u8 *, 1) != 0) {
                        var_s0 = var_s1 + 2;
                        do {
                            if ((s8) arg8 != 0) {
                                func_800328CC(D_8010D2B4, arg1, arg2, sp2C, (s32) M2C_FIELD(var_s0, u8 *, 0), (s32) M2C_FIELD(var_s0, u8 *, 1), (s32) M2C_FIELD(var_s0, u8 *, 2));
                                D_8010D2B4 += 0x10;
                            } else {
                                *arg9 += 1;
                            }
                            var_s2 += 1;
                            var_s0 += 3;
                        } while (var_s2 < (u8) M2C_FIELD(var_s1, u8 *, 1));
                    }
                    if ((s8) arg8 != 0) {
                        temp_a1 = D_8010A510;
                        D_8010A510 = temp_a1 + 8;
                        temp_v1 = M2C_FIELD(var_s1, u8 *, 1);
                        ((__repair_field_4 *)temp_a1)->value = (s32) (temp_s4 - 0x80000000);
                        M2C_FIELD(temp_a1, s32 *, 0) = (s32) ((temp_v1 << 0xC) | (((temp_v1 & 0x7F) * 2) | 0x01000000));
                    } else {
                        *arg10 += 1;
                    }
                    var_s1_2 = var_s1 + 1;
                    var_v0_2 = M2C_FIELD(var_s1, u8 *, 1) * 3;
block_46:
                    var_v0_3 = var_v0_2 + 1;
block_47:
                    var_s1 = var_s1_2 + var_v0_3;
                    break;
                case 1:
                    temp_s4_2 = D_8010D2B4;
                    var_s2_2 = 0;
                    if (M2C_FIELD(var_s1, u8 *, 1) != 0) {
                        var_s0_2 = var_s1 + 2;
                        do {
                            if ((s8) arg8 != 0) {
                                func_800328CC(D_8010D2B4, arg1, arg2, sp2C, (M2C_FIELD(var_s0_2, u8 *, 0) << 8) + M2C_FIELD(var_s0_2, u8 *, 1), (M2C_FIELD(var_s0_2, u8 *, 2) << 8) + M2C_FIELD(var_s0_2, u8 *, 3), (M2C_FIELD(var_s0_2, u8 *, 4) << 8) + M2C_FIELD(var_s0_2, u8 *, 5), arg5);
                                D_8010D2B4 += 0x10;
                            } else {
                                *arg9 += 1;
                            }
                            var_s2_2 += 1;
                            var_s0_2 += 6;
                        } while (var_s2_2 < (u8) M2C_FIELD(var_s1, u8 *, 1));
                    }
                    if ((s8) arg8 != 0) {
                        temp_a1_2 = D_8010A510;
                        D_8010A510 = temp_a1_2 + 8;
                        temp_v1_2 = M2C_FIELD(var_s1, u8 *, 1);
                        ((__repair_field_4 *)temp_a1_2)->value = (s32) (temp_s4_2 - 0x80000000);
                        M2C_FIELD(temp_a1_2, s32 *, 0) = (s32) ((temp_v1_2 << 0xC) | (((temp_v1_2 & 0x7F) * 2) | 0x01000000));
                    } else {
                        *arg10 += 1;
                    }
                    var_s1_2 = var_s1 + 1;
                    var_v0_4 = M2C_FIELD(var_s1, u8 *, 1) * 3;
block_45:
                    var_v0_2 = var_v0_4 * 2;
                    goto block_46;
                case 3:
                    temp_s4_3 = D_8010D2B4;
                    var_s2_3 = 0;
                    if (M2C_FIELD(var_s1, u8 *, 1) != 0) {
                        var_s0_3 = var_s1 + 2;
                        do {
                            temp_v0 = *(u8 *)var_s0_3;
                            if ((s8) arg8 != 0) {
                                func_800328CC(D_8010D2B4, arg1, arg2, sp2C, (s32) temp_v0, (s32) temp_v0, (s32) temp_v0, arg5);
                                D_8010D2B4 += 0x10;
                            } else {
                                *arg9 += 1;
                            }
                            var_s2_3 += 1;
                            var_s0_3 += 1;
                        } while (var_s2_3 < (u8) M2C_FIELD(var_s1, u8 *, 1));
                    }
                    if ((s8) arg8 != 0) {
                        temp_a1_3 = D_8010A510;
                        D_8010A510 = temp_a1_3 + 8;
                        temp_v1_3 = M2C_FIELD(var_s1, u8 *, 1);
                        ((__repair_field_4 *)temp_a1_3)->value = (s32) (temp_s4_3 - 0x80000000);
                        M2C_FIELD(temp_a1_3, s32 *, 0) = (s32) ((temp_v1_3 << 0xC) | (((temp_v1_3 & 0x7F) * 2) | 0x01000000));
                    } else {
                        *arg10 += 1;
                    }
                    var_s1_2 = var_s1 + 1;
                    var_v0_3 = M2C_FIELD(var_s1, u8 *, 1) + 1;
                    goto block_47;
                case 2:
                    temp_s4_4 = D_8010D2B4;
                    var_s2_4 = 0;
                    if (M2C_FIELD(var_s1, u8 *, 1) != 0) {
                        var_s0_4 = var_s1 + 2;
                        do {
                            temp_v0_2 = (M2C_FIELD(var_s0_4, u8 *, 0) << 8) + M2C_FIELD(var_s0_4, u8 *, 1);
                            if ((s8) arg8 != 0) {
                                func_800328CC(D_8010D2B4, arg1, arg2, sp2C, temp_v0_2, temp_v0_2, temp_v0_2, arg5);
                                D_8010D2B4 += 0x10;
                            } else {
                                *arg9 += 1;
                            }
                            var_s2_4 += 1;
                            var_s0_4 += 2;
                        } while (var_s2_4 < (u8) M2C_FIELD(var_s1, u8 *, 1));
                    }
                    if ((s8) arg8 != 0) {
                        temp_a1_4 = D_8010A510;
                        D_8010A510 = temp_a1_4 + 8;
                        temp_v1_4 = M2C_FIELD(var_s1, u8 *, 1);
                        ((__repair_field_4 *)temp_a1_4)->value = (s32) (temp_s4_4 - 0x80000000);
                        M2C_FIELD(temp_a1_4, s32 *, 0) = (s32) ((temp_v1_4 << 0xC) | (((temp_v1_4 & 0x7F) * 2) | 0x01000000));
                    } else {
                        *arg10 += 1;
                    }
                    var_s1_2 = var_s1 + 1;
                    __repair_result_var_v0_4 = M2C_FIELD(var_s1, u8 *, 1);
                    {var_v0_2 = var_v0_4 * 2;
                    goto block_46;}
                case 6:
                    func_800334A4(var_s1, arg1, &sp20, arg4, arg6, arg7, (s32) (s8) arg8, arg10);
                    temp_s1 = var_s1 + 1;
                    func_80032978(temp_s1, arg4, arg6, arg7, (s32) (s8) arg8, arg10);
                    var_s1 = temp_s1 + 1;
                case 5:
block_51:
                    temp_t3 = M2C_FIELD(var_s1, u8 *, 1);
                    var_s1 += 2;
                    temp_v0_3 = temp_t3 >> 1;
                    var_s2_5 = 0;
                    if (temp_v0_3 != 0) {
                        var_a1 = var_s1 + 2;
                        do {
                            temp_a1_5 = var_a1 + 3;
                            if ((s8) arg8 != 0) {
                                temp_a0_2 = D_8010A510;
                                D_8010A510 = temp_a0_2 + 8;
                                M2C_FIELD(temp_a0_2, s32 *, 0) = (s32) ((((M2C_FIELD(var_s1, u8 *, 0) * 2) & 0xFF) << 0x10) | ((M2C_FIELD(var_a1, u8 *, -1) << 9) & 0xFE00) | ((M2C_FIELD(var_a1, u8 *, 0) * 2) & 0xFF) | 0x06000000);
                                ((__repair_field_4 *)temp_a0_2)->value = (s32) ((((M2C_FIELD(var_s1, u8 *, 3) * 2) & 0xFF) << 0x10) | ((M2C_FIELD(temp_a1_5, u8 *, -1) << 9) & 0xFE00) | ((M2C_FIELD(var_a1, u8 *, 3) * 2) & 0xFF));
                            } else {
                                *arg10 += 1;
                            }
                            var_a1 = temp_a1_5 + 3;
                            var_s2_5 += 1;
                            var_s1 = var_s1 + 3 + 3;
                        } while (var_s2_5 < temp_v0_3);
                    }
                    if (temp_t3 & 1) {
                        if ((s8) arg8 != 0) {
                            temp_a0_3 = D_8010A510;
                            D_8010A510 = temp_a0_3 + 8;
                            M2C_FIELD(temp_a0_3, s32 *, 0) = (s32) ((((M2C_FIELD(var_s1, u8 *, 0) * 2) & 0xFF) << 0x10) | ((M2C_FIELD(var_s1, u8 *, 1) << 9) & 0xFE00) | ((M2C_FIELD(var_s1, u8 *, 2) * 2) & 0xFF) | 0x05000000);
                            ((__repair_field_4 *)temp_a0_3)->value = 0;
                        } else {
                            *arg10 += 1;
                        }
                        var_s1 += 3;
                    }
                    break;
                case 7:
                    func_80032978(var_s1, arg4, arg6, arg7, (s32) (s8) arg8, arg10);
                    func_800334A4(var_s1, &sp20, arg4, arg6, arg7, (s32) (s8) arg8, arg10);
                    var_s1 += 1;
                    goto block_51;
                case 8:
                    var_s1 += 3;
                    goto block_51;
                case 4:
                    var_a1_2 = var_s1 + 7;
                    if (M2C_FIELD(var_s1, u8 *, 0) == 4) {
                        do {
                            temp_v1_5 = M2C_FIELD(var_a1_2, u8 *, -6);
                            temp_s4 = (u8)(M2C_FIELD(var_a1_2, u8 *, -5));
                            temp_t3 = M2C_FIELD(var_a1_2, u8 *, -4);
                            if (M2C_FIELD(var_a1_2, u8 *, -3) == 4) {
                                if ((s8) arg8 != 0) {
                                    temp_a0_4 = D_8010A510;
                                    D_8010A510 = temp_a0_4 + 8;
                                    M2C_FIELD(temp_a0_4, s32 *, 0) = (s32) ((((temp_v1_5 * 2) & 0xFF) << 0x10) | ((temp_s4 << 9) & 0xFE00) | ((temp_t3 * 2) & 0xFF) | 0x06000000);
                                    ((__repair_field_4 *)temp_a0_4)->value = (s32) ((((M2C_FIELD(var_a1_2, u8 *, -2) * 2) & 0xFF) << 0x10) | ((M2C_FIELD(var_a1_2, u8 *, -1) << 9) & 0xFE00) | ((M2C_FIELD(var_a1_2, u8 *, 0) * 2) & 0xFF));
                                } else {
                                    *arg10 += 1;
                                }
                                var_a1_2 += 8;
                                var_s1 += 8;
                            } else {
                                if ((s8) arg8 != 0) {
                                    temp_a0_5 = D_8010A510;
                                    D_8010A510 = temp_a0_5 + 8;
                                    M2C_FIELD(temp_a0_5, s32 *, 0) = (s32) ((((temp_v1_5 * 2) & 0xFF) << 0x10) | ((temp_s4 << 9) & 0xFE00) | ((temp_t3 * 2) & 0xFF) | 0x05000000);
                                    ((__repair_field_4 *)temp_a0_5)->value = 0;
                                } else {
                                    *arg10 += 1;
                                }
                                var_a1_2 += 4;
                                var_s1 += 4;
                            }
                        } while (*(u8 *)var_s1 == 4);
                    }
                    break;
                case 10:
                    func_80032978(var_s1, arg4, arg6, arg7, (s32) (s8) arg8, arg10);
                    var_s1 += 2;
                    break;
                case 11:
                    func_800334A4(var_s1, &sp20, arg4, arg6, arg7, (s32) (s8) arg8, arg10);
                    var_s1 += 2;
                    break;
                }
            }
            var_v1 = *(u8 *)var_s1 & 0xFF;
            var_v0 = var_v1 < 0xCU;
        } while (var_v1 != 0xC);
    }
    if ((sp37 << 0x18) != 0) {
        temp_v1_6 = D_8010A510;
        temp_v0_4 = temp_v1_6 + 8;
        D_8010A510 = temp_v0_4;
        M2C_FIELD(temp_v1_6, s32 *, 0) = 0xDF000000;
        ((__repair_field_4 *)temp_v1_6)->value = 0;
        func_800A0220(&sp24, temp_v0_4 - sp24);
        return;
    }
    *arg10 += 1;
}
