/* machine draft (m2c) for gcc-2.7.2-kmc -G0 -mips3 -mgp32 -mfp32 -O2 -fno-strength-reduce, tried by autopilot */
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

s32 func_8008C1B0();
s32 func_8008C43C();
s32 func_8008C490();
s32 func_8008C4C0();
s32 func_8008C524();
s32 func_8008C7C8();
s32 func_8008CBD0();
s32 func_8008CC38();
s32 func_80090A4C();
s32 func_80090CD4();
s32 func_80091428();
s16 func_80095664();
s32 func_8009692C();
s32 func_80096CFC();
s32 func_80096D1C();
s32 func_80096D3C();
s32 func_80096D5C();
s32 func_80096D7C();
s32 func_80096D9C();
s32 func_80096DBC();
s32 func_80096DDC();
s32 func_80096DFC();
s32 func_8009AF94();
extern char D_80102FDC[];
extern u8 D_801032AD;
extern char D_80107ED4[];
extern char D_80107ED8[];
extern char D_80107EDC[];
extern char D_80107EE0[];
extern char D_80107EE4[];
extern char D_80107EE9[];
extern char D_80107EEC[];
extern char D_80107EF0[];
extern char D_80107EF4[];
extern char D_80107EF8[];
extern s32 D_80109680;
extern s32 D_8010D724;
extern u8 D_801176E8;

typedef struct { unsigned char pad[360]; int value; } __repair_field_168;
void func_8008D838(void) {
    char *var_a0;
    char *var_s0;
    char *var_s5;
    s32 temp_a0;
    s32 temp_a0_3;
    s32 temp_a1;
    s32 temp_a1_2;
    s32 temp_s2;
    
    s32 temp_s3;
    s32 temp_v0_4;
    s32 temp_v0_6;
    s32 temp_v0_7;
    s32 temp_v0_8;
    s32 temp_v1_10;
    s32 temp_v1_11;
    s32 temp_v1_13;
    s32 temp_v1_14;
    s32 temp_v1_4;
    s32 temp_v1_5;
    s32 temp_v1_6;
    s32 temp_v1_8;
    s32 temp_v1_9;
    s32 var_a0_2;
    s32 var_a0_3;
    s32 var_a0_4;
    s32 var_a3;
    s32 var_a3_2;
    s32 var_a3_3;
    s32 var_s0_4;
    s32 var_s0_5;
    s32 var_s2;
    s32 var_s2_2;
    s32 var_s2_4;
    s32 var_s3;
    s32 var_s6;
    s32 var_v0;
    s32 var_v0_3;
s32 __repair_result_var_v0_3;
    s32 var_v1_2;
    s32 var_v1_3;
    u16 var_v1;
    u32 temp_a0_4;
    u32 temp_a1_3;
    u32 temp_s0;
    u32 temp_s0_2;
    u32 temp_v0;
    u32 temp_v0_2;
    u32 temp_v0_5;
    u32 temp_v1;
    u32 temp_v1_2;
    u32 temp_v1_7;
    u32 var_a2;
    u32 var_s0_2;
    u32 var_s0_3;
    u32 var_s2_3;
    u8 temp_a0_2;
    u8 temp_a0_5;
    u8 temp_s4;
    u8 temp_v0_3;
    u8 temp_v1_12;
    u8 var_v0_2;
    union { void * pointer; s32 value; } __repair_phase_storage;
    void *var_s1;

    var_s5 = &D_8010D724;
    var_s6 = 0;
    if ((s32) D_801176E8 > 0) {
        var_s1 = D_8010D724 + 0xC2;
        do {
            if (*(s32 *)var_s5 != 0) {
                func_8009AF94(var_s5);
                goto block_5;
            }
            if (func_8008C1B0(var_s6) & 0xFF) {
block_5:
                if (M2C_FIELD(var_s1, u8 *, -5) == 0) {
                    var_s2 = 0;
                    var_s0 = var_s5;
                    do {
                        temp_v0 = M2C_FIELD(var_s0, u32 *, 0x16C);
                        if (temp_v0 != 0) {
                            temp_v1 = ((__repair_field_168 *)var_s0)->value + D_80109680;
                            ((__repair_field_168 *)var_s0)->value = temp_v1;
                            M2C_FIELD(var_s0, s16 *, 0x170) = func_80095664(((u32) ((temp_v1 % temp_v0) * 0x10) / (u32) (temp_v0 >> 8)) & 0xFFFF);
                        }
                        var_s2 += 1;
                        var_s0 += 0xC;
                    } while (var_s2 < 2);
                    var_s2_2 = 0;
                    if (M2C_FIELD(var_s1, s32 *, -0x9E) & 0x4000) {
                        temp_v0_2 = M2C_FIELD(var_s1, u32 *, -0x52);
                        temp_v1_2 = M2C_FIELD(var_s1, u32 *, -0x56) + D_80109680;
                        M2C_FIELD(var_s1, u32 *, -0x56) = temp_v1_2;
                        M2C_FIELD(var_s1, s32 *, -0x4E) = (s32) func_80095664(((u32) ((temp_v1_2 % temp_v0_2) * 0x10) / (u32) (temp_v0_2 >> 8)) & 0xFFFF);
                        var_s2_2 = 0;
                    }
                    var_a0 = var_s5;
                    do {
                        __repair_phase_storage.pointer = var_s5 + var_s2_2;
                        if (M2C_FIELD(__repair_phase_storage.pointer, u8 *, 0x48) != 0) {
                            temp_v0_3 = M2C_FIELD(__repair_phase_storage.pointer, u8 *, 0xB0) - 1;
                            M2C_FIELD(__repair_phase_storage.pointer, u8 *, 0xB0) = temp_v0_3;
                            if (!(temp_v0_3 & 0xFF)) {
                                M2C_FIELD(__repair_phase_storage.pointer, u8 *, 0xB0) = (u8) M2C_FIELD(__repair_phase_storage.pointer, u8 *, 0x48);
                                M2C_FIELD(var_a0, s32 *, 0x40) = 0;
                            } else {
                                M2C_FIELD(var_a0, s32 *, 0x40) += M2C_FIELD(var_a0, s32 *, 0x7C);
                            }
                        }
                        var_s2_2 += 1;
                        var_a0 += 4;
                    } while (var_s2_2 < 2);
                    if ((M2C_FIELD(var_s1, u8 *, -0x78) != 0xFF) && ((u32) (func_80096DBC(var_s5) & 0xFFFF) >= 0x1F81U)) {
                        var_v0 = M2C_FIELD(var_s1, s32 *, -0x9E) | 0x40000000;
                    } else {
                        var_v0 = M2C_FIELD(var_s1, s32 *, -0x9E) & 0xBFFFFFFF;
                    }
                    M2C_FIELD(var_s1, s32 *, -0x9E) = var_v0;
                    if (!(M2C_FIELD(var_s1, s32 *, -0x9E) & 0x1000)) {
                        if (M2C_FIELD(var_s1, u8 *, -0x78) != 0xFF) {
                            if ((u32) (func_80096DDC(var_s5) & 0xFFFF) < 0x1F81U) {
                                M2C_FIELD(var_s1, s32 *, -0x9E) &= ~0x800;
                                func_8009692C(M2C_FIELD(var_s1, u8 *, -0x78), M2C_FIELD(var_s1, u8 *, -0x77), 0);
                            } else {
                                temp_a0 = M2C_FIELD(var_s1, s32 *, -0x9E);
                                if (!(temp_a0 & 0x800)) {
                                    if (!(temp_a0 & 0x80000)) {
                                        if ((M2C_FIELD(var_s1, u8 *, -0x2A) == 1) && !(temp_a0 & 0x2000)) {
                                            M2C_FIELD(var_s1, s32 *, -0x36) = 0;
                                        } else {
                                            M2C_FIELD(var_s1, s32 *, -0x36) = (s32) M2C_FIELD(var_s1, s32 *, -0x32);
                                        }
                                        M2C_FIELD(var_s1, u32 *, -0x2E) = (u32) (M2C_FIELD(var_s1, u8 *, -1) << 0x10);
                                    }
                                    temp_a0_2 = M2C_FIELD(var_s1, u8 *, -0x78);
                                    if (temp_a0_2 != 0xFF) {
                                        func_8009692C(temp_a0_2, M2C_FIELD(var_s1, u8 *, -0x77), 1);
                                    }
                                }
                                M2C_FIELD(var_s1, s32 *, -0x9E) |= 0x800;
                            }
                        }
                        M2C_FIELD(var_s1, s32 *, -0x9E) |= 0x2000;
                    }
                    temp_v1_4 = M2C_FIELD(var_s1, s32 *, -0x9E);
                    if (temp_v1_4 & 0x20) {
                        M2C_FIELD(var_s1, s32 *, -0x9E) = (s32) ((temp_v1_4 & ~0x20) | 0x10);
                        func_8008C43C(var_s6);
                    }
                    if ((M2C_FIELD(var_s1, s32 *, -0x9E) & 0x80) && !(M2C_FIELD(var_s1, s32 *, -0x9E) & 0x40000000)) {
                        M2C_FIELD(var_s1, s32 *, -0x9E) &= ~0x90;
                        func_8008C490(var_s6);
                    }
                    temp_a0_3 = M2C_FIELD(var_s1, s32 *, -0x9A);
                    if (temp_a0_3 != 0) {
                        temp_v0_4 = temp_a0_3 - (M2C_FIELD(var_s1, u16 *, -0x96) * D_80109680);
                        M2C_FIELD(var_s1, s32 *, -0x9A) = temp_v0_4;
                        if (temp_v0_4 < 0) {
                            M2C_FIELD(var_s1, s32 *, -0x9A) = 0;
                        }
                    }
                    if (M2C_FIELD(var_s1, s32 *, -0x9E) & 0x10000) {
                        temp_v1_5 = M2C_FIELD(var_s1, s32 *, -0x16) - (((u32) M2C_FIELD(var_s1, u32 *, -0x1A) >> 8) * M2C_FIELD(var_s1, s32 *, -0x86));
                        M2C_FIELD(var_s1, s32 *, -0x8A) = temp_v1_5;
                        if (temp_v1_5 >= 0) {
                            var_a0_2 = 0x7F0000;
                            if ((u32) temp_v1_5 <= 0x7F0000U) {
                                var_a0_2 = temp_v1_5;
                            }
                        } else {
                            var_a0_2 = 0;
                        }
                        M2C_FIELD(var_s1, s32 *, -0x8A) = var_a0_2;
                        temp_v0_5 = M2C_FIELD(var_s1, u32 *, -0x1A) - D_80109680;
                        M2C_FIELD(var_s1, u32 *, -0x1A) = temp_v0_5;
                        if (temp_v0_5 == 0) {
                            M2C_FIELD(var_s1, s32 *, -0x9E) &= 0xFFFEFFFF;
                            M2C_FIELD(var_s1, s32 *, -0x8A) = (s32) M2C_FIELD(var_s1, s32 *, -0x16);
                        }
                    }
                    temp_a1 = M2C_FIELD(var_s1, u16 *, -0x72) << 0x10;
                    var_s0_2 = temp_a1 + ((M2C_FIELD(var_s1, s8 *, -2) << 0x10) / 100);
                    if (M2C_FIELD(var_s1, s32 *, -0x9E) & 0x40010) {
                        if (M2C_FIELD(var_s1, u8 *, -0x78) != 0xFF) {
                            var_v1 = func_80096D5C(var_s5, temp_a1, 0x40010) & 0xFFFF;
                            M2C_FIELD(var_s1, u16 *, -0xA) = var_v1;
                            goto block_56;
                        }
                    } else {
                        var_v1 = M2C_FIELD(var_s1, u16 *, -0xA);
block_56:
                        temp_v1_6 = var_v1 - 0x2000;
                        if (var_v1 != 0x2000) {
                            if (temp_v1_6 < 0) {
                                var_v0_2 = M2C_FIELD(var_s1, u8 *, -0x58);
                            } else {
                                var_v0_2 = M2C_FIELD(var_s1, u8 *, -0x57);
                            }
                            var_s0_2 += var_v0_2 * temp_v1_6 * 8;
                        }
                    }
                    temp_a1_2 = M2C_FIELD(var_s1, s32 *, -0x9E);
                    if (temp_a1_2 & 0x4000) {
                        temp_s2 = (M2C_FIELD(var_s1, u8 *, -0x4A) << 8) + ((M2C_FIELD(var_s1, u8 *, -0x49) << 8) / 100);
                        if ((temp_a1_2 & 0x8000) && (M2C_FIELD(var_s1, u8 *, -0x78) != 0xFF)) {
                            var_v1_2 = (s32) (M2C_FIELD(var_s1, s32 *, -0x4E) * ((u32) (func_80096D9C(var_s5, temp_a1_2) & 0xFFFF) >> 7)) >> 7;
                        } else {
                            var_v1_2 = M2C_FIELD(var_s1, s32 *, -0x4E);
                        }
                        var_s0_2 += (s32) (temp_s2 * var_v1_2) >> 4;
                    }
                    var_a2 = var_s0_2;
                    if (M2C_FIELD(var_s1, s32 *, -0x9E) & 0x800) {
                        temp_a0_4 = (u32) (M2C_FIELD(var_s1, s32 *, -0x32) - M2C_FIELD(var_s1, s32 *, -0x36)) >> 8;
                        if ((s32) temp_a0_4 > 0) {
                            temp_a1_3 = M2C_FIELD(var_s1, u32 *, -0x2E);
                            temp_v1_7 = temp_a1_3 + ((s32) (D_80109680 * ((s32) (var_s0_2 - temp_a1_3) >> 8)) / (s32) temp_a0_4);
                            M2C_FIELD(var_s1, u32 *, -0x2E) = temp_v1_7;
                            if (((temp_a1_3 < var_s0_2) && (temp_v1_7 < var_s0_2)) || ((var_s0_2 < temp_a1_3) && (var_s0_2 < temp_v1_7))) {
                                var_a2 = M2C_FIELD(var_s1, u32 *, -0x2E);
                                var_v0_3 = M2C_FIELD(var_s1, s32 *, -0x36) + D_80109680;
                            } else {
                                __repair_result_var_v0_3 = M2C_FIELD(var_s1, s32 *, -0x32);
                            }
                            M2C_FIELD(var_s1, s32 *, -0x36) = __repair_result_var_v0_3;
                        }
                    }
                    temp_s3 = var_a2 & 0xFFFF;
                    var_s2_3 = func_8008CC38((var_a2 >> 0x10) & 0xFF, M2C_FIELD(var_s1, s32 *, -0x66), var_a2) << 0x10;
                    if (temp_s3 != 0) {
                        temp_s0 = var_s2_3 >> 0x10;
                        var_s2_3 += ((func_8008CBD0(temp_s0) & 0xFFFF) - temp_s0) * temp_s3;
                    }
                    temp_s0_2 = var_s2_3 + (M2C_FIELD(var_s1, s32 *, -0x82) + M2C_FIELD(var_s1, s32 *, -0x7E));
                    if (M2C_FIELD(var_s1, u8 *, -0x78) != 0xFF) {
                        var_s0_3 = (u32) ((temp_s0_2 >> 0x10) * (func_80096D7C(var_s5) & 0xFFFF)) >> 0xD;
                    } else {
                        var_s0_3 = temp_s0_2 >> 0x10;
                    }
                    func_8008C4C0(var_s6, var_s0_3 & 0xFFFF);
                    if (M2C_FIELD(var_s1, s32 *, -0x9E) & 0x20000) {
                        temp_v1_8 = M2C_FIELD(var_s1, s32 *, -0x3A) - (((u32) M2C_FIELD(var_s1, u32 *, -0xE) >> 8) * M2C_FIELD(var_s1, s32 *, -0x3E));
                        M2C_FIELD(var_s1, s32 *, -0x92) = temp_v1_8;
                        if (temp_v1_8 >= 0) {
                            var_a0_3 = 0x7F0000;
                            if ((u32) temp_v1_8 <= 0x7F0000U) {
                                var_a0_3 = temp_v1_8;
                            }
                        } else {
                            var_a0_3 = 0;
                        }
                        M2C_FIELD(var_s1, s32 *, -0x92) = var_a0_3;
                        temp_v0_6 = M2C_FIELD(var_s1, u32 *, -0xE) - D_80109680;
                        M2C_FIELD(var_s1, u32 *, -0xE) = (u32) temp_v0_6;
                        if (temp_v0_6 <= 0) {
                            M2C_FIELD(var_s1, s32 *, -0x9E) &= 0xFFFDFFFF;
                            M2C_FIELD(var_s1, s32 *, -0x92) = (s32) M2C_FIELD(var_s1, s32 *, -0x3A);
                        }
                    }
                    temp_v1_9 = M2C_FIELD(var_s1, u8 *, -4) * 0x28;
                    var_s2_4 = M2C_FIELD(var_s1, s32 *, -0x8A);
                    temp_s4 = M2C_FIELD(var_s1, u8 *, -0x78);
                    var_a0_4 = 0x348;
                    if (M2C_FIELD(var_s1, u8 *, -0x76) != 0) {
                        var_a0_4 = 0x370;
                    }
                    temp_a0_5 = M2C_FIELD(var_s1, u8 *, -0x93);
                    var_s0_4 = ((s32) (((s32) (((s32) M2C_FIELD(var_s1, s32 *, -0x92) >> 7) * *(D_80107EEC + temp_v1_9)) >> 7) * *(D_80107ED4 + temp_v1_9)) >> 7) * *(D_80107ED4 + var_a0_4);
                    if (temp_a0_5 != 0xFF) {
                        var_s0_4 = (var_s0_4 >> 7) * *(D_80102FDC + temp_a0_5);
                    }
                    if (D_801032AD == 0) {
                        var_s3 = 0;
                        if (temp_s4 != 0xFF) {
                            var_s0_4 = (var_s0_4 >> 7) * ((u32) (func_80096CFC(var_s5) & 0xFFFF) >> 7);
                            if (var_s2_4 != 0x800000) {
                                __repair_phase_storage.value = var_s2_4 + ((((u32) (func_80096D1C(var_s5) & 0xFFFF) >> 7) - 0x40) << 0x10);
                                if (__repair_phase_storage.value >= 0) {
                                    var_v1_3 = 0x7F0000;
                                    if (__repair_phase_storage.value <= 0x7F0000) {
                                        var_v1_3 = __repair_phase_storage.value;
                                    }
                                } else {
                                    var_v1_3 = 0;
                                }
                                var_s2_4 = var_v1_3;
                            }
                            var_s3 = (func_80096D3C(var_s5) & 0xFFFF) << 9;
                            if (var_s3 > 0x7F0000) {
                                var_s3 = 0x7F0000;
                            }
                        }
                    } else {
                        var_s2_4 = 0x400000;
                        if (temp_s4 != 0xFF) {
                            var_s0_4 = (var_s0_4 >> 7) * ((u32) (func_80096CFC(var_s5) & 0xFFFF) >> 7);
                            var_s2_4 = 0x400000;
                        }
                        var_s3 = 0;
                    }
                    var_a3 = 0;
                    if (temp_s4 != 0xFF) {
                        var_a3_2 = (s32) (((u32) (func_80096DFC(var_s5) & 0xFFFF) >> 7) * var_s0_4) >> 7;
                        if (var_a3_2 > 0x7F0000) {
                            var_a3_2 = 0x7F0000;
                        }
                        var_a3_3 = (var_a3_2 >> 7) * M2C_FIELD(var_s1, u8 *, -0x29);
                        if (var_a3_3 > 0x7F0000) {
                            var_a3_3 = 0x7F0000;
                        }
                        var_a3 = var_a3_3 + (M2C_FIELD(var_s1, u8 *, -0x28) << 0x10);
                        if (var_a3 > 0x7F0000) {
                            var_a3 = 0x7F0000;
                        }
                    }
                    M2C_FIELD(var_s1, s16 *, 0) = (s16) (var_s0_4 >> 8);
                    func_8008C524(var_s6, var_s0_4, var_s2_4, var_s3, var_a3);
                }
            }
            var_s6 += 1;
            var_s1 += 0x1A0;
            var_s5 += 0x1A0;
        } while (var_s6 < (s32) D_801176E8);
        var_s6 = 0;
    }
    var_s0_5 = 0;
    do {
        temp_v1_10 = *(s32 *)(D_80107EE0 + var_s0_5);
        if (temp_v1_10 != 0) {
            temp_v0_7 = *(s32 *)(D_80107ED8 + var_s0_5) - ((temp_v1_10 >> 8) * *(s32 *)(D_80107EDC + var_s0_5));
            *(D_80107ED4 + var_s0_5) = temp_v0_7;
            if (temp_v0_7 < 0) {
                *(D_80107ED4 + var_s0_5) = 0;
            }
            temp_v1_11 = *(s32 *)(D_80107EE0 + var_s0_5) - D_80109680;
            *(s32 *)(D_80107EE0 + var_s0_5) = temp_v1_11;
            if (temp_v1_11 <= 0) {
                temp_v1_12 = *(D_80107EE9 + var_s0_5);
                *(s32 *)(D_80107EE0 + var_s0_5) = 0;
                *(D_80107ED4 + var_s0_5) = *(s32 *)(D_80107ED8 + var_s0_5);
                switch (temp_v1_12) {               /* irregular */
                case 1:
                    func_80090CD4(*(s32 *)(D_80107EE4 + var_s0_5));
                    break;
                case 2:
                    func_80090A4C(*(s32 *)(D_80107EE4 + var_s0_5));
                    break;
                case 3:
                    func_80091428(*(s32 *)(D_80107EE4 + var_s0_5), 0, 0);
                    break;
                }
            }
        }
        temp_v1_13 = *(s32 *)(D_80107EF8 + var_s0_5);
        if (temp_v1_13 != 0) {
            temp_v0_8 = *(s32 *)(D_80107EF0 + var_s0_5) - ((temp_v1_13 >> 8) * *(s32 *)(D_80107EF4 + var_s0_5));
            *(D_80107EEC + var_s0_5) = temp_v0_8;
            if (temp_v0_8 < 0) {
                *(D_80107EEC + var_s0_5) = 0;
            }
            temp_v1_14 = *(s32 *)(D_80107EF8 + var_s0_5) - D_80109680;
            *(s32 *)(D_80107EF8 + var_s0_5) = temp_v1_14;
            if (temp_v1_14 <= 0) {
                *(s32 *)(D_80107EF8 + var_s0_5) = 0;
                *(D_80107EEC + var_s0_5) = *(s32 *)(D_80107EF0 + var_s0_5);
            }
        }
        var_s6 += 1;
        var_s0_5 += 0x28;
    } while (var_s6 < 0x20);
    func_8008C7C8();
}
