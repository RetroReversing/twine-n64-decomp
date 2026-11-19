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

s32 func_80000A40();
s32 func_80008434(void *, f32);
s32 func_800084C0();
s32 func_80008598();
s32 func_80008660();
s32 func_80008750();
s32 func_8000BF90();
s32 func_8000C34C();
s32 func_80038EE8();
s32 func_80038FA4();
s32 func_80039068();
s32 func_8006F974();
s32 func_80083A6C();
s32 guPositionF(void *, s32, s32, f32, f32, f32, f32, f32);
extern char D_800B1A50[];
extern u32 D_800B1D84;
extern u8 D_801002E4;
extern u8 D_80103020;
extern u8 D_8010302A;
extern u8 D_80103041;
extern u8 D_801032AC;
extern u8 D_80103EB1;
extern u32 D_80107EA0;
extern u8 D_80107ECD;
extern u8 D_80107ECE;
extern u8 D_80108F94;
extern u8 D_8010957C;
extern u8 D_80109684;
extern u8 D_80109A34;
extern s32 D_8010A924;
extern s32 D_8010A92C;
extern u8 D_8010D36C;
extern u8 D_8010D374;
extern s32 D_8010D538;
extern s32 D_80112E40;
extern f32 D_80112F90;
extern f32 D_80112F94;
extern f32 D_80112F98;
extern f32 D_80112FB0;
extern f32 D_80112FB4;
extern f32 D_80112FB8;
extern u8 D_80113022;
extern u8 D_80115318;
extern s32 *D_80115328;
extern void *volatile D_80117728;

typedef struct { unsigned char pad[88]; int value; } __repair_field_58;
typedef struct { int value; } __repair_field_0;
void func_800090A4(u8 *arg0, void *arg1, s32 arg2, s8 arg3) {
    u8 sp20;
    u8 sp21;
    u8 sp22;
    u8 sp23;
    u8 sp24;
    u8 sp25;
    u8 sp26;
    u8 sp27;
    u8 sp28;
    u8 sp29;
    u8 sp2A;
    u8 sp2B;
    u8 sp2C;
    u8 sp2D;
    u8 sp2E;
    f32 sp30[3];
    s32 *temp_a1_2;
    s32 *temp_a1_3;
    s32 *temp_t3;
    s32 *temp_t3_2;
    s32 *temp_t3_3;
    s32 *temp_t3_4;
    s32 *temp_v0_10;
    s32 *temp_v1_10;
    s32 *temp_v1_9;
    s32 *var_a0_2;
    s32 temp_a0_5;
    s32 temp_a1_5;
    s32 temp_a2;
    s32 temp_s1;
    s32 temp_s1_2;
    s32 temp_v0;
    s32 temp_v0_2;
    s32 temp_v0_3;
    s32 temp_v0_5;
    s32 temp_v0_6;
    s32 temp_v1_11;
    s32 temp_v1_3;
    s32 temp_v1_4;
    s32 temp_v1_5;
    s32 temp_v1_8;
    s32 var_s4;
    s32 var_v0_2;
    u32 temp_a0_6;
    u32 temp_v0_7;
    u32 temp_v0_8;
    u8 *temp_s0;
    u8 *var_a0;
    u8 temp_a0;
    u8 temp_a0_2;
    u8 temp_a0_3;
    
    u8 temp_a1;
    u8 temp_a2_2;
    u8 temp_a2_3;
    u8 temp_t1;
    u8 temp_t1_2;
    u8 temp_v0_4;
    u8 temp_v0_9;
    u8 temp_v1;
    u8 temp_v1_2;
    u8 temp_v1_6;
    u8 temp_v1_7;
    u8 var_a1;
    u8 var_a2;
    u8 var_a3;
    u8 var_a3_2;
    u8 var_v0;
    u8 var_v1;
    void *temp_a1_4;
    void *temp_s4;
    void *temp_t2;
    void *temp_t2_2;

    temp_v0 = ((__repair_field_58 *)arg0)->value;
    temp_s4 = M2C_FIELD(arg0, void **, 0x20);
    temp_s0 = M2C_FIELD(arg0, u8 **, 0x18);
    temp_a2 = temp_v0 & arg2;
    if (temp_a2 == 0) {
        if (temp_v0 & 0x400) {
            func_8000BF90(arg0, &sp20, &sp21, &sp22);
            temp_v1 = M2C_FIELD(arg0, u8 *, 0x7F);
            M2C_FIELD(arg0, u8 *, 0x7F) = (u8) (temp_v1 + ((sp20 >> 1) - (temp_v1 >> 1)));
            temp_v1_2 = M2C_FIELD(arg0, u8 *, 0x80);
            temp_a1 = M2C_FIELD(arg0, u8 *, 0x81);
            M2C_FIELD(arg0, u8 *, 0x80) = (u8) (temp_v1_2 + ((sp21 >> 1) - (temp_v1_2 >> 1)));
            ((__repair_field_58 *)arg0)->value &= ~4;
            M2C_FIELD(arg0, u8 *, 0x81) = (u8) (temp_a1 + ((sp22 >> 1) - (temp_a1 >> 1)));
        }
    } else {
        func_8006F974(arg1);
        temp_s1 = M2C_FIELD(arg0, s32 *, 0x70);
        func_80008750(arg1, M2C_FIELD(arg0, u8 *, 0x7E), arg3);
        temp_v1_3 = ((__repair_field_58 *)arg0)->value;
        if (temp_v1_3 & 0x400) {
            if (temp_v1_3 & 0x1000) {
                if (D_80112E40 != 1) {
                    D_80112E40 = 1;
                    func_80038FA4(arg1);
                }
            } else if (D_80112E40 != 0) {
                D_80112E40 = 0;
                func_80038EE8();
            }
            temp_v1_4 = M2C_FIELD(arg1, s32 *, 0x100);
            if (temp_v1_4 & 2) {
                if (((__repair_field_58 *)arg0)->value & 0x2000) {
                    temp_v0_2 = func_8000BF90(arg0, &sp23, &sp24, &sp25);
                    temp_a0 = M2C_FIELD(arg0, u8 *, 0x7F);
                    temp_a1 = M2C_FIELD(arg0, u8 *, 0x81);
                    M2C_FIELD(arg0, u8 *, 0x7F) = (u8) (temp_a0 + ((sp23 >> 1) - (temp_a0 >> 1)));
                    temp_a0_2 = M2C_FIELD(arg0, u8 *, 0x80);
                    M2C_FIELD(arg0, u8 *, 0x80) = (u8) (temp_a0_2 + ((sp24 >> 1) - (temp_a0_2 >> 1)));
                    var_s4 = temp_v0_2;
                    M2C_FIELD(arg0, u8 *, 0x81) = (u8) (temp_a1 + ((sp25 >> 1) - (temp_a1 >> 1)));
                    temp_t3 = D_80115328;
                    D_80115328 = temp_t3 + 8;
                    ((__repair_field_0 *)temp_t3)->value = 0xFA000000;
                    D_80115328 = temp_t3 + 0x10;
                    M2C_FIELD(temp_t3, s32 *, 0xC) = (s32) ((D_8010957C << 0x18) | (D_8010D374 << 0x10) | (D_80103EB1 << 8) | 0xFF);
                    M2C_FIELD(temp_t3, s32 *, 8) = 0xFB000000;
                    M2C_FIELD(temp_t3, s32 *, 4) = (s32) ((D_80103041 << 0x18) | (D_801032AC << 0x10) | (D_8010302A << 8) | M2C_FIELD(arg0, u8 *, 0x82));
                    func_80000A40(arg0, arg1, 0, 0, 0, (s32) arg3);
                    temp_a1_2 = D_80115328;
                    D_80115328 = temp_a1_2 + 8;
                    ((__repair_field_0 *)temp_a1_2)->value = 0xFB000000;
                    M2C_FIELD(temp_a1_2, s32 *, 4) = (s32) ((M2C_FIELD(arg1, u8 *, 0x143) << 0x18) | (M2C_FIELD(arg1, u8 *, 0x144) << 0x10) | (M2C_FIELD(arg1, u8 *, 0x145) << 8) | 0xFF);
                    if ((arg3 == 0) && (M2C_FIELD(arg0, u8 *, 0x82) == 0xFF)) {
                        var_v1 = D_80113022 + 1;
                        if ((u8) D_80113022 < 0xAU) {
                            var_a3 = sp23;
                            var_v0 = sp25;
                            goto block_21;
                        }
                    }
                }
            } else if (temp_v1_4 & 4) {
                if (((__repair_field_58 *)arg0)->value & 0x2000) {
                    temp_v0_3 = func_8000BF90(arg0, &sp26, &sp27, &sp28);
                    temp_a0_3 = M2C_FIELD(arg0, u8 *, 0x7F);
                    temp_a2_3 = M2C_FIELD(arg0, u8 *, 0x81);
                    M2C_FIELD(arg0, u8 *, 0x7F) = (u8) (temp_a0_3 + ((sp26 >> 1) - (temp_a0_3 >> 1)));
                    temp_a0_3 = M2C_FIELD(arg0, u8 *, 0x80);
                    M2C_FIELD(arg0, u8 *, 0x80) = (u8) (temp_a0_3 + ((sp27 >> 1) - (temp_a0_3 >> 1)));
                    var_s4 = temp_v0_3;
                    M2C_FIELD(arg0, u8 *, 0x81) = (u8) (temp_a2_3 + ((sp28 >> 1) - (temp_a2_3 >> 1)));
                    temp_t3_2 = D_80115328;
                    D_80115328 = temp_t3_2 + 8;
                    ((__repair_field_0 *)temp_t3_2)->value = 0xFA000000;
                    D_80115328 = temp_t3_2 + 0x10;
                    M2C_FIELD(temp_t3_2, s32 *, 0xC) = (s32) ((D_8010D36C << 0x18) | (D_801002E4 << 0x10) | (D_80107ECD << 8) | 0xFF);
                    M2C_FIELD(temp_t3_2, s32 *, 8) = 0xFB000000;
                    M2C_FIELD(temp_t3_2, s32 *, 4) = (s32) ((D_80107ECE << 0x18) | (D_80108F94 << 0x10) | (D_80103020 << 8) | M2C_FIELD(arg0, u8 *, 0x82));
                    func_80000A40(arg0, arg1, 0, 0, 0, (s32) arg3);
                    temp_a1_3 = D_80115328;
                    D_80115328 = temp_a1_3 + 8;
                    ((__repair_field_0 *)temp_a1_3)->value = 0xFB000000;
                    M2C_FIELD(temp_a1_3, s32 *, 4) = (s32) ((M2C_FIELD(arg1, u8 *, 0x143) << 0x18) | (M2C_FIELD(arg1, u8 *, 0x144) << 0x10) | (M2C_FIELD(arg1, u8 *, 0x145) << 8) | 0xFF);
                    if ((arg3 == 0) && (M2C_FIELD(arg0, u8 *, 0x82) == 0xFF)) {
                        var_v1 = D_80113022 + 1;
                        if ((u8) D_80113022 < 0xAU) {
                            var_a3 = sp26;
                            var_v0 = sp28;
block_21:
                            D_80113022 = var_v1;
                            func_8000C34C(arg0, var_s4, arg1, (u32) var_a3, (u32) var_v0);
                        }
                    }
                }
            } else {
                temp_v1_5 = ((__repair_field_58 *)arg0)->value;
                if (temp_v1_5 & 0x2000) {
                    var_a0 = arg0;
                    if (temp_v1_5 & 0x1000) {
                        var_a0 = temp_s0;
                    }
                    temp_s1_2 = func_8000BF90(var_a0, &sp29, &sp2A, &sp2B);
                    temp_v1_6 = M2C_FIELD(arg0, u8 *, 0x7F);
                    M2C_FIELD(arg0, u8 *, 0x7F) = (u8) (temp_v1_6 + ((sp29 >> 1) - (temp_v1_6 >> 1)));
                    temp_v1_7 = M2C_FIELD(arg0, u8 *, 0x80);
                    temp_t1 = M2C_FIELD(arg0, u8 *, 0x81);
                    M2C_FIELD(arg0, u8 *, 0x80) = (u8) (temp_v1_7 + ((sp2A >> 1) - (temp_v1_7 >> 1)));
                    temp_t1_2 = temp_t1 + ((sp2B >> 1) - (temp_t1 >> 1));
                    M2C_FIELD(arg0, u8 *, 0x81) = temp_t1_2;
                    temp_t2 = M2C_FIELD(temp_s4, void **, 0x20);
                    temp_t3_3 = D_80115328;
                    D_80115328 = temp_t3_3 + 8;
                    ((__repair_field_0 *)temp_t3_3)->value = 0xFA000000;
                    M2C_FIELD(temp_t3_3, s32 *, 4) = (s32) ((((u32) (M2C_FIELD(arg0, u8 *, 0x7F) * M2C_FIELD(temp_t2, u8 *, 0x64)) >> 8) << 0x18) | (((u32) (M2C_FIELD(arg0, u8 *, 0x80) * M2C_FIELD(temp_t2, u8 *, 0x65)) >> 8) << 0x10) | (((temp_t1_2 & 0xFF) * M2C_FIELD(temp_t2, u8 *, 0x66)) & 0xFF00) | M2C_FIELD(arg0, u8 *, 0x82));
                    func_80000A40(arg0, arg1, 0, 0, 0, (s32) arg3);
                    if ((arg3 == 0) && ((u8) D_80113022 < 0xAU)) {
                        D_80113022 += 1;
                        temp_v0_4 = M2C_FIELD(arg0, u8 *, 0x82);
                        func_8000C34C(arg0, temp_s1_2, arg1, (u32) (sp29 * temp_v0_4) >> 8, (u32) (sp2A * temp_v0_4) >> 8, (u32) (sp2B * temp_v0_4) >> 8);
                    }
                } else {
                    temp_t2_2 = M2C_FIELD(temp_s4, void **, 0x20);
                    temp_t3_4 = D_80115328;
                    D_80115328 = temp_t3_4 + 8;
                    ((__repair_field_0 *)temp_t3_4)->value = 0xFA000000;
                    M2C_FIELD(temp_t3_4, s32 *, 4) = (s32) ((((u32) (M2C_FIELD(arg0, u8 *, 0x7F) * M2C_FIELD(temp_t2_2, u8 *, 0x64)) >> 8) << 0x18) | (((u32) (M2C_FIELD(arg0, u8 *, 0x80) * M2C_FIELD(temp_t2_2, u8 *, 0x65)) >> 8) << 0x10) | ((M2C_FIELD(arg0, u8 *, 0x81) * M2C_FIELD(temp_t2_2, u8 *, 0x66)) & 0xFF00) | ((u8) M2C_FIELD(arg0, u8 *, 0x82) >> 1));
                    func_80000A40(arg0, arg1, 0, 0, 0, (s32) arg3);
                }
            }
            goto block_72;
        }
        if (temp_s1 != 0) {
            if (temp_v1_3 & 0x2000) {
                func_8000BF90(temp_s0, &sp2C, &sp2D, &sp2E);
                var_a2 = sp2C;
                var_a1 = sp2D;
                var_a3_2 = sp2E;
            } else if (temp_v1_3 & 0x10000) {
                var_a2 = M2C_FIELD(arg0, u8 *, 0x7F);
                var_a1 = M2C_FIELD(arg0, u8 *, 0x80);
                var_a3_2 = M2C_FIELD(arg0, u8 *, 0x81);
            } else {
                temp_a1_4 = M2C_FIELD(temp_s4, void **, 0x20);
                var_a2 = (u8) ((u32) (M2C_FIELD(arg0, u8 *, 0x7F) * M2C_FIELD(temp_a1_4, u8 *, 0x64)) >> 8);
                var_a1 = (u8) ((u32) (M2C_FIELD(arg0, u8 *, 0x80) * M2C_FIELD(temp_a1_4, u8 *, 0x65)) >> 8);
                var_a3_2 = (u8) ((u32) (M2C_FIELD(arg0, u8 *, 0x81) * M2C_FIELD(temp_a1_4, u8 *, 0x66)) >> 8);
            }
            temp_v1_8 = M2C_FIELD(arg1, s32 *, 0x100);
            if (temp_v1_8 & 2) {
                temp_a1_5 = ((var_a3_2 + (var_a1 + var_a2)) / 3) & 0xFFFF;
                temp_a0_5 = temp_a1_5 * D_80115318;
                temp_v0_5 = temp_a1_5 * D_80109A34;
                var_a3_2 = (u8) D_80115328;
                var_a2 = D_80109684;
                D_80115328 = var_a3_2 + 8;
                ((__repair_field_0 *)var_a3_2)->value = 0xFA000000;
                var_a1 = (temp_a1_5 * var_a2) & 0xFF00;
                M2C_FIELD(var_a3_2, s32 *, 4) = (s32) (((temp_a0_5 >> 8) << 0x18) | (((temp_v0_5 >> 8) & 0xFF) << 0x10) | var_a1 | M2C_FIELD(arg0, u8 *, 0x82));
            } else if (!(temp_v1_8 & 1)) {
                if (temp_v1_8 & 4) {
                    var_a0_2 = D_80115328;
                    D_80115328 = var_a0_2 + 8;
                    ((__repair_field_0 *)var_a0_2)->value = 0xFA000000;
                    var_v0_2 = (var_a2 << 0x18) | (var_a1 << 0x10) | (var_a3_2 << 8) | 0x80;
                    goto block_43;
                }
            } else {
                var_a0_2 = D_80115328;
                D_80115328 = var_a0_2 + 8;
                ((__repair_field_0 *)var_a0_2)->value = 0xFA000000;
                temp_v0_6 = (var_a2 << 0x18) | (var_a1 << 0x10);
                var_a1 = M2C_FIELD(arg0, u8 *, 0x82);
                var_v0_2 = temp_v0_6 | (var_a3_2 << 8) | var_a1;
block_43:
                M2C_FIELD(var_a0_2, s32 *, 4) = var_v0_2;
            }
            if (((__repair_field_58 *)arg0)->value & 0x1000) {
                if (D_80112E40 != 1) {
                    D_80112E40 = 1;
                    func_80038FA4(arg1, var_a1, var_a2, (s32 *) var_a3_2);
                }
                temp_v0_7 = D_80107EA0 + 1;
                if ((u32) D_80107EA0 < (u32) D_800B1D84) {
                    D_80107EA0 = temp_v0_7;
                    D_8010D538 = M2C_FIELD(D_80117728, s32 *, 0x74C) + (temp_v0_7 << 6);
                    if (((__repair_field_58 *)arg0)->value & 0x8000) {
                        func_80008434(arg0, 0.015625f);
                        D_80112FB0 *= M2C_FIELD(arg0, f32 *, 0x54);
                        D_80112FB4 *= M2C_FIELD(arg0, f32 *, 0x54);
                        D_80112FB8 *= M2C_FIELD(arg0, f32 *, 0x54);
                    } else {
                        func_80008434(arg0, M2C_FIELD(arg0, f32 *, 0x54));
                    }
                    if (((__repair_field_58 *)arg0)->value & 0x4000) {
                        D_80112F90 = -D_80112F90;
                        D_80112F94 = -D_80112F94;
                        D_80112F98 = -D_80112F98;
                        if (D_8010A924 != 0xB) {
                            temp_v1_9 = D_80115328;
                            D_8010A924 = 0xB;
                            D_80115328 = temp_v1_9 + 8;
                            ((__repair_field_0 *)temp_v1_9)->value = 0xDE000000;
                            M2C_FIELD(temp_v1_9, s32 **, 4) = D_800B1A50;
                        }
                    }
                    func_80008598(temp_s1);
                    if (((__repair_field_58 *)arg0)->value & 0x4000) {
                        temp_v1_10 = D_80115328;
                        D_80115328 = temp_v1_10 + 8;
                        D_80115328 = temp_v1_10 + 0x10;
                        ((__repair_field_0 *)temp_v1_10)->value = 0xD9FFFDFF;
                        M2C_FIELD(temp_v1_10, s32 *, 4) = 0;
                        M2C_FIELD(temp_v1_10, s32 *, 8) = 0xD9FFFFFF;
                        M2C_FIELD(temp_v1_10, s32 *, 0xC) = 0x400;
                    }
                    goto block_72;
                }
            } else {
                temp_a0_6 = D_80107EA0;
                if (temp_a0_6 < (u32) D_800B1D84) {
                    temp_v0_8 = temp_a0_6 + 1;
                    D_80107EA0 = temp_v0_8;
                    D_8010D538 = M2C_FIELD(D_80117728, s32 *, 0x74C) + (temp_v0_8 << 6);
                    temp_v0_9 = M2C_FIELD(arg0, u8 *, 0x7E);
                    switch (temp_v0_9) {
                    case 0:
                    case 1:
                    default:
                        if (D_80112E40 != 0) {
                            D_80112E40 = 0;
                            func_80038EE8(temp_a0_6, var_a1, var_a2, (s32 *) var_a3_2);
                        }
                        temp_v1_11 = ((__repair_field_58 *)arg0)->value;
                        if (temp_v1_11 & 0x40000) {
                            func_80008660(arg0);
                        } else if ((arg3 << 0x18) != 0) {
                            func_800084C0(arg0, temp_s4);
                        } else if (temp_v1_11 & 0x8000) {
                            func_80008434(arg0, 0.015625f);
                            D_80112FB0 *= M2C_FIELD(arg0, f32 *, 0x54);
                            D_80112FB4 *= M2C_FIELD(arg0, f32 *, 0x54);
                            D_80112FB8 *= M2C_FIELD(arg0, f32 *, 0x54);
                        } else {
                            func_80008434(arg0, M2C_FIELD(arg0, f32 *, 0x54));
                        }
                        break;
                    case 2:
                    case 4:
                    case 6:
                    case 9:
                        if (D_80112E40 != 2) {
                            D_80112E40 = 2;
                            func_80039068(arg1);
                        }
                        sp30[0] = M2C_FIELD(arg0, f32 *, 0x24) - M2C_FIELD(arg1, f32 *, 0x10);
                        sp30[1] = M2C_FIELD(arg0, f32 *, 0x28) - M2C_FIELD(arg1, f32 *, 0x14);
                        sp30[2] = M2C_FIELD(arg0, f32 *, 0x2C) - M2C_FIELD(arg1, f32 *, 0x18);
                        func_80083A6C(arg1 + 0xB8, sp30);
                        guPositionF(&D_80112F90, 0, 0, M2C_FIELD(arg0, f32 *, 0x44) * 0.087890625f, M2C_FIELD(arg0, f32 *, 0x54), sp30[0] * 64.0f, sp30[1] * 64.0f, sp30[2] * 64.0f);
                        break;
                    }
                    func_80008598(temp_s1);
                    goto block_72;
                }
            }
        } else {
block_72:
            if ((M2C_FIELD(arg0, u8 *, 0x7E) == 8) && (D_8010A92C != 1)) {
                temp_v0_10 = D_80115328;
                D_8010A92C = 1;
                D_80115328 = temp_v0_10 + 8;
                ((__repair_field_0 *)temp_v0_10)->value = 0xE2001E01;
                M2C_FIELD(temp_v0_10, s32 *, 4) = 0;
            }
        }
    }
}
