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

s32 func_80002BD0();
s32 func_800158A4();
f32 func_80045590();
s32 randomIntBelow();
s32 func_80077960();
s32 func_800779C4();
s32 func_80077A94();
s32 func_80077B58();
s32 func_80077E00();
s32 func_80077ED8();
void *func_8007847C();
s32 tryCollectBonusObject();
s32 actorTargetInAngleRange(void *, void *, void *, f32);
s32 func_8007AA40();
s32 func_8007AB18(s32, s32, f32);
s32 actorPlaySpeechLine();
s32 func_8007C094();
s32 func_8007C120(s32, s32, f32);
s32 func_8007C214();
s32 func_8007C3F0();
extern char D_800C2E64[];
extern s32 gGameMode;
extern void *gBonusObjects;
extern s8 D_80115319;
extern s16 D_80117386;

typedef struct { s32 w[3]; } __repair_words3;
s32 func_8007898C(void *arg0) {
    s32 __repair_store_0;
    s32 __repair_store_1;
    s32 __repair_store_2;
    volatile long long frame_padding;
    s32 sp28;
    s32 sp2C;
    s32 sp30;
    s32 sp34;
    s32 sp38;
    s32 sp48;
    s32 sp4C;
    s32 sp50;
    s32 sp54;
    s32 sp58;
    s32 sp5C;
    s32 var_a1;
    s32 temp_a2;
    s32 temp_a2_2;
    s32 temp_a2_3;
    s32 temp_a3;
    s32 temp_a3_2;
    s32 temp_a3_3;
    s32 temp_a3_4;
    s32 temp_a3_5;
    s32 temp_a3_6;
    s32 temp_a3_7;
    s32 temp_a3_8;
    s32 temp_v1_3;
    
    u8 temp_v1;
    u8 temp_v1_2;
    void *temp_s1;
    void *temp_s2;
    void *temp_v0;
    void *temp_v0_10;
    void *temp_v0_11;
    void *temp_v0_2;
    void *temp_v0_3;
    void *temp_v0_4;
    void *temp_v0_5;
    void *temp_v0_6;
    void *temp_v0_7;
    void *temp_v0_8;
    void *temp_v0_9;

    temp_s1 = M2C_FIELD(arg0, void **, 0x6C);
    var_a1 = 1;
    if (D_80115319 == 0) {
        temp_v1 = M2C_FIELD(temp_s1, u8 *, 0x82);
        if (((s32) temp_v1 < 0x15) && ((s32) temp_v1 >= 0x13) && (M2C_FIELD(temp_s1, u8 *, 0x81) != 0)) {
            var_a1 = 1;
            if (M2C_FIELD(gBonusObjects, s32 *, 0x20) == M2C_FIELD(arg0, s32 *, 0x20)) {
                if ((func_8007C094(arg0, gBonusObjects + 0x24) << 0x18) != 0) {
                    var_a1 = 0x46;
                    goto block_113;
                }
                goto block_114;
            }
            /* Duplicate return node #120. Try simplifying control flow for better match */
            return var_a1;
        }
        temp_v0 = func_8007847C(arg0);
        M2C_FIELD(temp_s1, void **, 0x40) = temp_v0;
        if (temp_v0 != NULL) {
            temp_v1_2 = M2C_FIELD(temp_s1, u8 *, 0x82);
            if ((s32) temp_v1_2 >= 0x10) {
                if ((s32) temp_v1_2 >= 0x12) {
                    if (temp_v1_2 == 0x2C) {
                        return 0;
                    }
                    goto block_17;
                }
                var_a1 = 0;
                if (M2C_FIELD(arg0, s32 *, 0x60) & 0x1000) {
                    var_a1 = 0;
                    if (M2C_FIELD(temp_s1, s32 *, 0x44) == 0) {
                        __repair_store_0 = (s32) M2C_FIELD(temp_v0, s32 *, 0x24);
                        __repair_store_1 = (s32) M2C_FIELD(temp_v0, s32 *, 0x28);
                        __repair_store_2 = (s32) M2C_FIELD(temp_v0, s32 *, 0x2C);
                        M2C_FIELD(temp_s1, s32 *, 0x18) = __repair_store_0;
                        M2C_FIELD(temp_s1, s32 *, 0x1C) = __repair_store_1;
                        M2C_FIELD(temp_s1, s32 *, 0x20) = __repair_store_2;
                        var_a1 = 0;
                        if ((func_8007AA40(arg0, temp_s1 + 0x18, &sp28) << 0x18) == 0) {
                            if ((func_80077E00(arg0) << 0x18) != 0) {
                                func_80002BD0(arg0, 0x124);
                                func_80077960(arg0, 7);
                                return 0;
                            }
                            goto block_119;
                        }
                    }
                }
                /* Duplicate return node #120. Try simplifying control flow for better match */
                return var_a1;
            }
block_17:
            if (temp_v1_2 != 0x1E) {
                if ((s32) temp_v1_2 < 0x1F) {
                    if ((s32) temp_v1_2 < 0xC) {
                        if ((s32) temp_v1_2 < 9) {
                            goto block_40;
                        }
                        goto block_23;
                    }
                    goto block_40;
                }
                if (temp_v1_2 == 0x23) {
                    goto block_23;
                }
block_40:
                if ((u32) (M2C_FIELD(temp_s1, u8 *, 0x82) - 0xA) < 2U) {
                    var_a1 = 0;
                    if (M2C_FIELD(arg0, s32 *, 0x60) & 0x7000) {
                        func_800779C4(arg0);
                        var_a1 = 1;
                        if ((func_8007C3F0(arg0, 0) << 0x18) == 0) {
                            temp_v0_2 = M2C_FIELD(temp_s1, void **, 0x40);
                            temp_a3 = M2C_FIELD(temp_v0_2, s32 *, 0x28);
                            M2C_FIELD(temp_s1, s32 *, 0x18) = (s32) M2C_FIELD(temp_v0_2, s32 *, 0x24);
                            M2C_FIELD(temp_s1, s32 *, 0x1C) = temp_a3;
                            M2C_FIELD(temp_s1, s32 *, 0x20) = (s32) M2C_FIELD(temp_v0_2, s32 *, 0x2C);
                            var_a1 = 0;
                            if ((func_8007AA40(arg0, temp_s1 + 0x18, &sp30, temp_a3) << 0x18) == 0) {
                                if ((func_80077E00(arg0) << 0x18) != 0) {
                                    func_80002BD0(arg0, 0x14D);
                                    var_a1 = 0xB;
                                    goto block_113;
                                }
                                goto block_119;
                            }
                        }
                    }
                    /* Duplicate return node #120. Try simplifying control flow for better match */
                    return var_a1;
                }
                if (M2C_FIELD(arg0, s32 *, 0x60) & 0x800000) {
                    temp_s2 = temp_s1 + 0x50;
                    if (((actorTargetInAngleRange(arg0, temp_s2, &sp34, *(f32 *)(D_800C2E64 + (gGameMode * 4)) * 0.95f) << 0x18) != 0) && ((func_800158A4(*M2C_FIELD(arg0, s32 **, 0x68) + 0xA8, temp_s2, M2C_FIELD(arg0, s32 *, 0x20), &sp38, 0, 0, 0, 1, 0) << 0x18) != 0)) {
                        func_800779C4(arg0);
                        M2C_FIELD(temp_s1, __repair_words3 *, 0x18) = *(__repair_words3 *) ((s8 *) temp_s1 + 0x50);
                        if (((func_8007AA40(arg0, temp_s1 + 0x18, &sp48) << 0x18) == 0) && ((func_80077E00(arg0) << 0x18) != 0)) {
                            func_80002BD0(arg0, 0x14D);
                            var_a1 = 0xB;
                            goto block_113;
                        }
                    }
                }
                if (M2C_FIELD(temp_s1, s32 *, 0x88) & 0x40000000) {
                    temp_v1_3 = M2C_FIELD(arg0, s32 *, 0x60);
                    if (temp_v1_3 & 0x1000) {
                        temp_v0_3 = M2C_FIELD(temp_s1, void **, 0x40);
                        temp_a2 = M2C_FIELD(temp_v0_3, s32 *, 0x28);
                        temp_a3_2 = M2C_FIELD(temp_v0_3, s32 *, 0x2C);
                        M2C_FIELD(temp_s1, s32 *, 0x18) = (s32) M2C_FIELD(temp_v0_3, s32 *, 0x24);
                        M2C_FIELD(temp_s1, s32 *, 0x1C) = temp_a2;
                        M2C_FIELD(temp_s1, s32 *, 0x20) = temp_a3_2;
                        var_a1 = 1;
                        if ((func_8007C3F0(arg0, 1, temp_a2, temp_a3_2) << 0x18) == 0) {
                            temp_v0_4 = M2C_FIELD(temp_s1, void **, 0x40);
                            temp_a2_2 = M2C_FIELD(temp_v0_4, s32 *, 0x28);
                            temp_a3_3 = M2C_FIELD(temp_v0_4, s32 *, 0x2C);
                            M2C_FIELD(temp_s1, s32 *, 0x18) = (s32) M2C_FIELD(temp_v0_4, s32 *, 0x24);
                            M2C_FIELD(temp_s1, s32 *, 0x1C) = temp_a2_2;
                            M2C_FIELD(temp_s1, s32 *, 0x20) = temp_a3_3;
                            func_80077960(arg0, 5, temp_a2_2, temp_a3_3);
                            goto block_63;
                        }
                        /* Duplicate return node #120. Try simplifying control flow for better match */
                        return var_a1;
                    }
                    if (temp_v1_3 & 0x6000) {
                        var_a1 = 1;
                        if ((func_8007C3F0(arg0, 0) << 0x18) == 0) {
                            var_a1 = 1;
                            if ((M2C_FIELD(temp_s1, u8 *, 0x80) == 0) && (M2C_FIELD(temp_s1, u8 *, 0x82) != 1)) {
                                var_a1 = 0x11;
                                goto block_113;
                            }
                        }
                        /* Duplicate return node #120. Try simplifying control flow for better match */
                        return var_a1;
                    }
                    if (!(temp_v1_3 & 0x8000) || (var_a1 = 1, ((func_8007C3F0(arg0, 0) << 0x18) == 0))) {
block_63:
                        if (!(M2C_FIELD(arg0, s32 *, 0x58) & 4) || (temp_v0_5 = M2C_FIELD(temp_s1, void **, 0x40), temp_a2_3 = M2C_FIELD(temp_v0_5, s32 *, 0x28), temp_a3_4 = M2C_FIELD(temp_v0_5, s32 *, 0x2C), M2C_FIELD(temp_s1, s32 *, 0x18) = (s32) M2C_FIELD(temp_v0_5, s32 *, 0x24), M2C_FIELD(temp_s1, s32 *, 0x1C) = temp_a2_3, M2C_FIELD(temp_s1, s32 *, 0x20) = temp_a3_4, var_a1 = 1, ((func_8007C3F0(arg0, 1, temp_a2_3, temp_a3_4) << 0x18) == 0))) {
                            goto block_65;
                        }
                        /* Duplicate return node #120. Try simplifying control flow for better match */
                        return var_a1;
                    }
                    /* Duplicate return node #120. Try simplifying control flow for better match */
                    return var_a1;
                }
block_65:
                if (M2C_FIELD(temp_s1, s32 *, 0x88) & 0x20000000) {
                    if (M2C_FIELD(arg0, s32 *, 0x60) & 0xF004) {
                        if ((func_8007C214(arg0, M2C_FIELD(temp_s1, void **, 0x40)) << 0x18) == 0) {
                            if ((actorTargetInAngleRange(arg0, M2C_FIELD(temp_s1, void **, 0x40) + 0x24, &sp4C, *(f32 *)(D_800C2E64 + (D_80117386 * 4)) * 0.75f) << 0x18) != 0) {
                                if (!(M2C_FIELD(temp_s1, s32 *, 0x88) & 0x40000000)) {
                                    func_80077ED8(arg0);
                                }
                                func_80077B58(arg0);
                                if ((func_80045590(arg0 + 0x24, temp_s1) < 0.75f) && (M2C_FIELD(temp_s1, s32 *, 0x44) == 0)) {
                                    func_80077960(arg0, 0x86);
                                }
                                goto block_77;
                            }
                            temp_v0_6 = M2C_FIELD(temp_s1, void **, 0x40);
                            temp_a3_5 = M2C_FIELD(temp_v0_6, s32 *, 0x28);
                            M2C_FIELD(temp_s1, s32 *, 0x18) = (s32) M2C_FIELD(temp_v0_6, s32 *, 0x24);
                            M2C_FIELD(temp_s1, s32 *, 0x1C) = temp_a3_5;
                            M2C_FIELD(temp_s1, s32 *, 0x20) = (s32) M2C_FIELD(temp_v0_6, s32 *, 0x2C);
                            if (((func_8007AA40(arg0, temp_s1 + 0x18, &sp50, temp_a3_5) << 0x18) == 0) && ((func_80077E00(arg0) << 0x18) != 0)) {
                                func_80002BD0(arg0, 0x14D);
                                var_a1 = 0xB;
                                goto block_113;
                            }
block_77:
                            var_a1 = 1;
                            if ((tryCollectBonusObject(arg0) << 0x18) == 0) {
                                goto block_78;
                            }
                            /* Duplicate return node #120. Try simplifying control flow for better match */
                            return var_a1;
                        }
                        {
                            func_800779C4(arg0);return 1;}
                    }
block_78:
                    if ((randomIntBelow(0xF) != 0) || !(M2C_FIELD(arg0, s32 *, 0x58) & 4) || (temp_v0_7 = M2C_FIELD(temp_s1, void **, 0x40), M2C_FIELD(temp_s1, s32 *, 0x18) = (s32) M2C_FIELD(temp_v0_7, s32 *, 0x24), M2C_FIELD(temp_s1, s32 *, 0x1C) = (s32) M2C_FIELD(temp_v0_7, s32 *, 0x28), M2C_FIELD(temp_s1, s32 *, 0x20) = (s32) M2C_FIELD(temp_v0_7, s32 *, 0x2C), ((func_8007C214(arg0, M2C_FIELD(temp_s1, void **, 0x40)) << 0x18) == 0))) {
                        goto block_81;
                    }
                    goto block_118;
                }
block_81:
                if (M2C_FIELD(arg0, s32 *, 0x60) & 0x1000) {
                    if ((randomIntBelow(0xF) != 0) || ((func_8007C214(arg0, M2C_FIELD(temp_s1, void **, 0x40)) << 0x18) == 0)) {
                        if ((M2C_FIELD(arg0, s32 *, 0x60) & 0x10000) && ((func_8007C120(arg0, temp_s1 + 0x50, 6.0f) << 0x18) != 0)) {
                            func_800779C4(arg0);
                            temp_v0_8 = M2C_FIELD(temp_s1, void **, 0x40);
                            temp_a3_6 = M2C_FIELD(temp_v0_8, s32 *, 0x28);
                            M2C_FIELD(temp_s1, s32 *, 0x18) = (s32) M2C_FIELD(temp_v0_8, s32 *, 0x24);
                            M2C_FIELD(temp_s1, s32 *, 0x1C) = temp_a3_6;
                            M2C_FIELD(temp_s1, s32 *, 0x20) = (s32) M2C_FIELD(temp_v0_8, s32 *, 0x2C);
                            if (((func_8007AA40(arg0, temp_s1 + 0x18, &sp54, temp_a3_6) << 0x18) == 0) && ((func_80077E00(arg0) << 0x18) != 0)) {
                                func_80002BD0(arg0, 0x14D);
                                var_a1 = 0xB;
                                goto block_113;
                            }
                        }
                        if (!(M2C_FIELD(arg0, s32 *, 0x60) & 0x20000) || ((func_8007C120(arg0, temp_s1 + 0x50, 3.0f) << 0x18) == 0)) {
                            var_a1 = 1;
                            if ((tryCollectBonusObject(arg0) << 0x18) == 0) {
                                goto block_92;
                            }
                            /* Duplicate return node #120. Try simplifying control flow for better match */
                            return var_a1;
                        }
                        goto block_112;
                    }
                    goto block_118;
                }
block_92:
                if (M2C_FIELD(arg0, s32 *, 0x60) & 0x2000) {
                    if ((randomIntBelow(0xF) != 0) || ((func_8007C214(arg0, M2C_FIELD(temp_s1, void **, 0x40)) << 0x18) == 0)) {
                        if ((M2C_FIELD(arg0, s32 *, 0x60) & 0x10000) && ((func_8007C120(arg0, temp_s1 + 0x50, 6.0f) << 0x18) != 0)) {
                            func_800779C4(arg0);
                            temp_v0_9 = M2C_FIELD(temp_s1, void **, 0x40);
                            temp_a3_7 = M2C_FIELD(temp_v0_9, s32 *, 0x28);
                            M2C_FIELD(temp_s1, s32 *, 0x18) = (s32) M2C_FIELD(temp_v0_9, s32 *, 0x24);
                            M2C_FIELD(temp_s1, s32 *, 0x1C) = temp_a3_7;
                            M2C_FIELD(temp_s1, s32 *, 0x20) = (s32) M2C_FIELD(temp_v0_9, s32 *, 0x2C);
                            if (((func_8007AA40(arg0, temp_s1 + 0x18, &sp58, temp_a3_7) << 0x18) == 0) && ((func_80077E00(arg0) << 0x18) != 0)) {
                                func_80002BD0(arg0, 0x14D);
                                var_a1 = 0xB;
                                goto block_113;
                            }
                        }
                        if (!(M2C_FIELD(arg0, s32 *, 0x60) & 0x20000) || ((func_8007C120(arg0, temp_s1 + 0x50, 3.0f) << 0x18) == 0)) {
                            goto block_102;
                        }
                        goto block_112;
                    }
                    goto block_118;
                }
block_102:
                if (M2C_FIELD(arg0, s32 *, 0x60) & 0xC004) {
                    if ((randomIntBelow(0x1E) != 0) || ((func_8007C214(arg0, M2C_FIELD(temp_s1, void **, 0x40)) << 0x18) == 0)) {
                        if ((M2C_FIELD(arg0, s32 *, 0x60) & 0x10000) && ((func_8007C120(arg0, temp_s1 + 0x50, 6.0f) << 0x18) != 0)) {
                            func_80077A94(arg0);
                            temp_v0_10 = M2C_FIELD(temp_s1, void **, 0x40);
                            temp_a3_8 = M2C_FIELD(temp_v0_10, s32 *, 0x28);
                            M2C_FIELD(temp_s1, s32 *, 0x18) = (s32) M2C_FIELD(temp_v0_10, s32 *, 0x24);
                            M2C_FIELD(temp_s1, s32 *, 0x1C) = temp_a3_8;
                            M2C_FIELD(temp_s1, s32 *, 0x20) = (s32) M2C_FIELD(temp_v0_10, s32 *, 0x2C);
                            if (((func_8007AA40(arg0, temp_s1 + 0x18, &sp5C, temp_a3_8) << 0x18) == 0) && ((func_80077E00(arg0) << 0x18) != 0)) {
                                func_80002BD0(arg0, 0x14D);
                                var_a1 = 0xB;
                                goto block_113;
                            }
                        }
                        if ((M2C_FIELD(arg0, s32 *, 0x60) & 0x20000) && ((func_8007C120(arg0, temp_s1 + 0x50, 3.0f) << 0x18) != 0)) {
block_112:
                            func_80077A94(arg0);
                            M2C_FIELD(temp_s1, s32 *, 0x18) = (s32) M2C_FIELD(temp_s1, s32 *, 0x50);
                            M2C_FIELD(temp_s1, s32 *, 0x1C) = (s32) M2C_FIELD(temp_s1, s32 *, 0x54);
                            M2C_FIELD(temp_s1, s32 *, 0x20) = (s32) M2C_FIELD(temp_s1, s32 *, 0x58);
                            var_a1 = 0xD;
                            goto block_113;
                        }
                        goto block_115;
                    }
                    goto block_118;
                }
block_115:
                var_a1 = 0;
                if (randomIntBelow(0x1E) == 0) {
                    var_a1 = 0;
                    if (M2C_FIELD(arg0, s32 *, 0x58) & 4) {
                        var_a1 = 0;
                        if ((func_8007C214(arg0, M2C_FIELD(temp_s1, void **, 0x40)) << 0x18) != 0) {
block_118:
                            func_800779C4(arg0);
                            return 1;
                        }
                    }
                }
                /* Duplicate return node #120. Try simplifying control flow for better match */
                return var_a1;
            }
block_23:
            if (M2C_FIELD(temp_s1, s32 *, 0x88) & 0x08000000) {
                if ((M2C_FIELD(arg0, s32 *, 0x60) & 0xF000) || (var_a1 = 0, ((M2C_FIELD(arg0, s32 *, 0x58) & 4) != 0))) {
                    if ((func_8007AA40(arg0, M2C_FIELD(temp_s1, void **, 0x40) + 0x24, &sp2C) << 0x18) == 0) {
                        func_8007AB18(arg0, M2C_FIELD(temp_s1, void **, 0x40) + 0x24, 0.2f);
                        return 0;
                    }
                    if ((func_8007C214(arg0, M2C_FIELD(temp_s1, void **, 0x40)) << 0x18) != 0) {
                        actorPlaySpeechLine(arg0);
                        var_a1 = 0x21;
                        goto block_113;
                    }
                    M2C_FIELD(temp_s1, s32 *, 0x88) &= 0xF7FFFFFF;
                    goto block_119;
                }
                /* Duplicate return node #120. Try simplifying control flow for better match */
                return var_a1;
            }
            if ((M2C_FIELD(arg0, s32 *, 0x60) & 0xF000) || (var_a1 = 0, ((M2C_FIELD(arg0, s32 *, 0x58) & 4) != 0))) {
                if ((randomIntBelow(0xF) == 0) && ((func_8007C214(arg0, M2C_FIELD(temp_s1, void **, 0x40)) << 0x18) != 0)) {
                    M2C_FIELD(temp_s1, s32 *, 0x88) |= 0x40000000 | 0x08000000;
                    return 1;
                }
                if (M2C_FIELD(arg0, s32 *, 0x60) & 0x10000) {
                    temp_v0_11 = M2C_FIELD(temp_s1, void **, 0x40);
                    M2C_FIELD(temp_s1, s32 *, 0x18) = (s32) M2C_FIELD(temp_v0_11, s32 *, 0x24);
                    M2C_FIELD(temp_s1, s32 *, 0x1C) = (s32) M2C_FIELD(temp_v0_11, s32 *, 0x28);
                    M2C_FIELD(temp_s1, s32 *, 0x20) = (s32) M2C_FIELD(temp_v0_11, s32 *, 0x2C);
                    var_a1 = 0xA6;
block_113:
                    func_80077960(arg0, var_a1);
block_114:
                    return 1;
                }
                var_a1 = 1;
                if ((tryCollectBonusObject(arg0) << 0x18) == 0) {
                    return 0;
                }
                /* Duplicate return node #120. Try simplifying control flow for better match */
                return var_a1;
            }
            /* Duplicate return node #120. Try simplifying control flow for better match */
            return var_a1;
        }
block_119:
        var_a1 = 0;
        /* Duplicate return node #120. Try simplifying control flow for better match */
        return var_a1;
    }
    return var_a1;
}
