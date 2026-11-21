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

s32 func_800015AC();
s32 func_80002BD0();
s32 func_80002D30();
s32 listUnlinkFree();
s32 requestSound();
void *func_80015F0C();
s32 func_80016314();
s32 func_800165E0();
s32 func_800448A4();
s32 func_800643EC();
s32 func_80065684();
s32 func_800656B0();
s32 func_8006591C();
s32 func_80065B68();
s32 func_80065BC4();
s32 func_800702AC();
s32 func_80070528();
s32 findActionSlot();
s32 func_8007092C();
s32 advanceActorPhaseSound();
s32 func_80070CA4();
s32 func_800818AC();
f32 func_80081B44();
f32 absFloat(f32);
extern char D_800C469C[];
extern char D_800C46A0[];
extern char D_800C46FC[];
extern char D_800C4738[];
extern u8 D_800E1A16;
extern f32 D_800E1A1C;
extern u8 D_80115088[];
extern u8 D_8011508A[];
extern char D_8011508B[];
extern u8 D_80115090[];
extern s32 gTrackMarkerTable;
extern s32 gVisibleSaveSlots;
extern s32 gBorderSkipFlag;

void func_80065D90(void *arg0) {
    s32 var_a0_2;
    s32 var_a1;
    f32 temp_fa0;
    f32 temp_fa0_2;
    f32 temp_fa0_3;
    f32 temp_fa0_4;
    f32 temp_fs0;
    f32 temp_fs0_2;
    f32 temp_fs0_3;
    f32 temp_fs1;
    f32 temp_fs1_2;
    f32 temp_fs1_3;
    f32 temp_fs1_4;
    f32 temp_fs3;
    f32 temp_fv0;
    f32 temp_fv0_10;
    f32 temp_fv0_11;
    f32 temp_fv0_12;
    f32 temp_fv0_13;
    f32 temp_fv0_14;
    f32 temp_fv0_15;
    f32 temp_fv0_16;
    f32 temp_fv0_17;
    f32 temp_fv0_18;
    f32 temp_fv0_2;
    f32 temp_fv0_3;
    f32 temp_fv0_4;
    f32 temp_fv0_5;
    f32 temp_fv0_6;
    f32 temp_fv0_7;
    f32 temp_fv0_8;
    f32 temp_fv0_9;
    f32 temp_fv1;
    f32 temp_fv1_2;
    f32 temp_fv1_3;
    f32 temp_fv1_4;
    f32 temp_fv1_5;
    f32 temp_fv1_6;
    f32 temp_fv1_7;
    f32 temp_fv1_8;
    f32 temp_fv1_9;
    f32 var_fs0;
    f32 var_fs0_2;
    f32 var_fs0_3;
    f32 var_fs1;
    f32 var_fs1_2;
    f32 var_fs1_3;
    f32 var_fs1_4;
    f32 var_fs1_5;
    f32 var_fs2;
    f32 var_fv0;
    f32 var_fv0_2;
    f32 var_fv1;
    f32 var_fv1_2;
    f32 var_fv1_3;
    f32 var_fv1_4;
    f32 var_fv1_5;
    f32 var_fv1_6;
    f32 var_fv1_7;
    f32 var_fv1_8;
    f32 var_fv1_9;
    s16 temp_v0_3;
    s16 temp_v1;
    s16 temp_v1_12;
    s16 temp_v1_8;
    s16 var_a0;
    s16 var_v0;
    s32 temp_a0;
    s32 temp_a0_3;
    s32 temp_a0_4;
    s32 temp_a0_5;
    s32 temp_a1_2;
    s32 temp_a3;
    s32 temp_ft0;
    s32 var_condition_bit;
    s32 var_condition_bit_2;
    s32 var_v0_10;
    s32 var_v0_11;
    s32 var_v0_2;
    s32 var_v0_3;
    s32 var_v0_4;
    s32 var_v0_5;
    s32 var_v0_6;
    s32 var_v0_7;
    s32 var_v0_8;
    s32 var_v0_9;
    s32 var_v1;
    s32 var_v1_10;
    s32 var_v1_11;
    s32 var_v1_12;
    s32 var_v1_2;
    s32 var_v1_3;
    s32 var_v1_4;
    s32 var_v1_5;
    s32 var_v1_6;
    s32 var_v1_7;
    s32 var_v1_8;
    s32 var_v1_9;
    s32 temp_s3;
    s8 temp_v0_2;
    s8 temp_v1_4;
    s8 temp_v1_5;
    u16 temp_a1_3;
    u16 temp_v1_3;
    u8 temp_v1_10;
    u8 temp_v1_9;
    void *temp_a0_2;
    void *temp_a1;
    void *temp_a1_4;
    void *temp_a2;
    void *temp_s0;
    void *temp_s0_2;
    void *temp_s1;
    void *temp_v0;
    void *temp_v0_4;
    void *temp_v0_5;
    void *temp_v1_11;
    void *temp_v1_2;
    void *temp_v1_6;
    void *temp_v1_7;

    temp_s1 = M2C_FIELD(arg0, void **, 0x6C);
    temp_v1 = M2C_FIELD(arg0, s16 *, 0x7C);
    temp_s3 = M2C_FIELD(temp_s1, s8 *, 0x182);
    if ((temp_v1 == 2) || (temp_v1 == 5)) {
        temp_v0 = M2C_FIELD(arg0, void **, 0x68);
        M2C_FIELD(temp_v0, u16 *, 0xC) |= 1;
        M2C_FIELD(temp_s1, f32 *, 0x40) = 1.0f;
    } else if (*(D_8011508A + (temp_s3 * 0xA0)) == 0) {
        temp_v1_2 = M2C_FIELD(arg0, void **, 0x68);
        M2C_FIELD(temp_v1_2, u16 *, 0xC) &= 0xFFFE;
        if (func_800818AC(temp_s3, 0x18) != 0) {
            var_v0 = M2C_FIELD(M2C_FIELD(arg0, void **, 0x68), u16 *, 0xC) | 1;
            goto block_8;
        }
    } else if (func_800819EC((s32) temp_s3, 0x18) != 0) {
        var_v0 = M2C_FIELD(M2C_FIELD(arg0, void **, 0x68), u16 *, 0xC) ^ 1;
block_8:
        M2C_FIELD(M2C_FIELD(arg0, void **, 0x68), s16 *, 0xC) = var_v0;
    }
    temp_a1 = M2C_FIELD(arg0, void **, 0x68);
    temp_v1_3 = M2C_FIELD(temp_a1, u16 *, 0xC);
    temp_a0 = temp_v1_3 & 1;
    if (temp_a0 != ((temp_v1_3 >> 1) & 1)) {
        M2C_FIELD(temp_a1, u16 *, 0xC) = (u16) (temp_v1_3 ^ 2);
        if (temp_a0 != 0) {
            func_80065BC4(arg0, temp_a1);
            M2C_FIELD(temp_s1, s8 *, 0x17E) = 0;
            func_80065684(arg0);
            func_800656B0(arg0);
            if (M2C_FIELD(arg0, s16 *, 0x7C) == 0) {
                func_80002BD0(arg0, 0x159);
            }
        } else {
            func_80065B68(arg0, temp_a1);
        }
    }
    if (func_800819EC((s32) temp_s3, 0x10) != 0) {
        if (M2C_FIELD(M2C_FIELD(temp_s1, void **, 0xA8), s16 *, 0x7A) == 0) {
            temp_a2 = M2C_FIELD(arg0, void **, 0x68);
            temp_v0_2 = M2C_FIELD(temp_a2, s8 *, 0xE);
            temp_a3 = temp_v0_2 * 8;
            temp_a1_2 = temp_v0_2 * 0xE8;
            temp_v1_4 = *(D_800C46A0 + temp_a1_2);
            if (temp_v1_4 != 0) {
                M2C_FIELD(temp_a2, s8 *, 0xE) = (s8) (temp_v0_2 + temp_v1_4);
                temp_v1_5 = M2C_FIELD(M2C_FIELD(arg0, void **, 0x68), s8 *, 0xE);
                var_a0 = 0;
                if (!(*(u16 *)(D_800C469C + (temp_v1_5 * 0xE8)) & 0x8000)) {
                    __repair_rows: {
                        var_a0 += 1;
                    }
if (!(*(u16 *)(D_800C469C + ((temp_v1_5 - var_a0) * 0xE8)) & 0x8000)) goto __repair_rows;
                }
                M2C_FIELD((temp_s1 + ((M2C_FIELD(M2C_FIELD(arg0, void **, 0x68), s8 *, 0xE) - var_a0) * 8)), s8 *, 0x1FE) = (s8) var_a0;
                func_800015AC(arg0, M2C_FIELD(M2C_FIELD(arg0, void **, 0x68), s8 *, 0xE), temp_a2, temp_a3);
                func_800643EC(arg0);
                temp_v1_6 = M2C_FIELD(arg0, void **, 0x68);
                M2C_FIELD(temp_v1_6, u8 *, 0xF) = (u8) M2C_FIELD(temp_v1_6, s8 *, 0xE);
                temp_a1_3 = *(u16 *)(D_800C4738 + (M2C_FIELD(M2C_FIELD(arg0, void **, 0x68), s8 *, 0xE) * 0xE8));
                if (temp_a1_3 != 0) {
                    func_80002D30(M2C_FIELD(temp_s1, void **, 0xA8), temp_a1_3);
                    M2C_FIELD(M2C_FIELD(temp_s1, void **, 0xA8), s16 *, 0x7A) = 6;
                }
                func_80065BC4(arg0);
                if (*(s32 *)(D_800C46FC + (M2C_FIELD(M2C_FIELD(arg0, void **, 0x68), s8 *, 0xE) * 0xE8)) & 4) {
                    requestSound(0x1DF);
                }
                if ((u32) ((u8) M2C_FIELD(M2C_FIELD(arg0, void **, 0x68), s8 *, 0xE) - 4) >= 2U) {
                    goto block_30;
                }
            } else {
                temp_a1_4 = temp_a1_2 + D_800C469C;
                temp_v1_7 = temp_s1 + temp_a3;
                if (M2C_FIELD(temp_a1_4, u8 *, 0x2A) != 1) {
                    M2C_FIELD(temp_v1_7, u8 *, 0x1FD) += 1;
                    temp_a0_2 = temp_s1 + (M2C_FIELD(M2C_FIELD(arg0, void **, 0x68), s8 *, 0xE) * 8);
                    if (M2C_FIELD(temp_a0_2, u8 *, 0x1FD) == M2C_FIELD(temp_a1_4, u8 *, 0x2A)) {
                        M2C_FIELD(temp_a0_2, u8 *, 0x1FD) = 0U;
                    }
block_30:
                    requestSound(0x11D);
                }
            }
        }
    }
    if ((findActionSlot(temp_s1, 0x15, 1) << 0x18) != 0) {
        if (func_800819EC((s32) temp_s3, 0x11) != 0) {
            func_800702AC(temp_s1);
        }
    } else if (((findActionSlot(temp_s1, 0x1B, 1) << 0x18) != 0) && (func_800819EC((s32) temp_s3, 0x11) != 0)) {
        func_80070528(temp_s1);
    }
    temp_v1_8 = M2C_FIELD(arg0, s16 *, 0x7C);
    if ((temp_v1_8 != 5) && (temp_v1_8 != 7)) {
        if (func_800819EC((s32) temp_s3, 0xF) != 0) {
            advanceActorPhaseSound(arg0);
        }
        if (func_800819EC((s32) temp_s3, 0x14) != 0) {
            func_8007092C(arg0, 0);
        }
        if (func_800819EC((s32) temp_s3, 0x13) != 0) {
            func_80070CA4(arg0);
        }
    }
    temp_fs3 = M2C_FIELD(temp_s1, f32 *, 0x3C);
    var_fs0 = 0.0f;
    if (M2C_FIELD(M2C_FIELD(arg0, void **, 0x68), u16 *, 0xC) & 1) {
        temp_v0_3 = M2C_FIELD(arg0, s16 *, 0x7C);
        if ((temp_v0_3 != 2) & (temp_v0_3 != 5)) {
            var_fs0 = func_80081B44(temp_s3, 0x19, 0x1A);
        }
    }
    temp_fs1 = var_fs0;
    if (temp_fs1 != 0.0f) {
        var_fs2 = 1.05f;
        if (temp_fs1 > 0.0f) {
            var_fs2 = 0.952381f;
        }
        M2C_FIELD(temp_s1, f32 *, 0x40) = (f32) (M2C_FIELD(temp_s1, f32 *, 0x40) * var_fs2);
    } else {
        var_fs0 = M2C_FIELD(temp_s1, f32 *, 0x3C) - M2C_FIELD(temp_s1, f32 *, 0x40);
        var_fs2 = 1.3f;
        if (var_fs0 > 0.0f) {
            var_fs2 = 0.7692308f;
        }
        temp_a0_3 = M2C_FIELD(temp_s1, s32 *, 0xC);
        if (temp_a0_3 != -1) {
            listUnlinkFree(temp_a0_3);
            M2C_FIELD(temp_s1, s32 *, 0xC) = -1;
        }
    }
    temp_fv1 = M2C_FIELD(temp_s1, f32 *, 0x44);
    if (temp_fv1 < M2C_FIELD(temp_s1, f32 *, 0x40)) {
        M2C_FIELD(temp_s1, f32 *, 0x40) = temp_fv1;
    }
    temp_fv0 = M2C_FIELD(temp_s1, f32 *, 0x40);
    var_fv1 = 1.0f;
    if ((temp_fv0 < 1.0f) || (var_fv1 = 10.0f, (temp_fv0 > 10.0f))) {
        M2C_FIELD(temp_s1, f32 *, 0x40) = var_fv1;
    }
    if (var_fs0 != 0.0f) {
        temp_fv0_2 = M2C_FIELD(temp_s1, f32 *, 0x3C) * var_fs2;
        M2C_FIELD(temp_s1, f32 *, 0x3C) = temp_fv0_2;
        if (var_fs0 < 0.0f) {
            var_condition_bit = M2C_FIELD(temp_s1, f32 *, 0x40) < temp_fv0_2;
        } else {
            var_condition_bit = temp_fv0_2 < M2C_FIELD(temp_s1, f32 *, 0x40);
        }
        if (var_condition_bit) {
            M2C_FIELD(temp_s1, f32 *, 0x3C) = M2C_FIELD(temp_s1, f32 *, 0x40);
        }
    }
    if (temp_fs1 != 0.0f) {
        M2C_FIELD(temp_s1, f32 *, 0x40) = (f32) M2C_FIELD(temp_s1, f32 *, 0x3C);
        M2C_FIELD((temp_s1 + (M2C_FIELD(M2C_FIELD(arg0, void **, 0x68), s8 *, 0xE) * 8)), f32 *, 0x200) = (f32) M2C_FIELD(temp_s1, f32 *, 0x3C);
        if (M2C_FIELD(temp_s1, f32 *, 0x3C) != temp_fs3) {
            if (func_800819EC((s32) temp_s3, 0x19) != 0) {
                temp_a0_4 = M2C_FIELD(temp_s1, s32 *, 0xC);
                if (temp_a0_4 == -1) {
                    var_a0_2 = 0x127;
                } else {
                    listUnlinkFree(temp_a0_4);
                    var_a0_2 = 0x127;
                }
                goto block_80;
            }
            if (func_800819EC((s32) temp_s3, 0x1A) != 0) {
                temp_a0_5 = M2C_FIELD(temp_s1, s32 *, 0xC);
                if (temp_a0_5 != -1) {
                    listUnlinkFree(temp_a0_5);
                }
                var_a0_2 = 0x128;
block_80:
                M2C_FIELD(temp_s1, s32 *, 0xC) = requestSound(var_a0_2);
            }
        }
    }
    if (!(M2C_FIELD(M2C_FIELD(arg0, void **, 0x68), u16 *, 0xC) & 1)) {
        if (*(D_80115090 + (temp_s3 * 0xA0)) != 0) {
            if ((M2C_FIELD(temp_s1, void **, 0x410) != NULL) || (temp_v0_4 = func_80015F0C(), M2C_FIELD(temp_s1, void **, 0x410) = temp_v0_4, func_800165E0(temp_v0_4, *(&gTrackMarkerTable + (temp_s3 * 4))), (M2C_FIELD(temp_s1, void **, 0x410) != NULL))) {
                temp_v1_9 = M2C_FIELD(temp_s1, u8 *, 0x185);
                temp_s0 = M2C_FIELD(temp_s1, void **, 0x410);
                switch (temp_v1_9) {                /* switch 1; irregular */
                case 2:                             /* switch 1 */
                    var_v1 = 0x3F3FFFFF;
                    break;
                default:                            /* switch 1 */
                    var_v1 = 0xFF0000FF;
                    break;
                case 1:                             /* switch 1 */
                    var_v1 = 0x3FFF3FFF;
                    break;
                }
                M2C_FIELD(temp_s0, s32 *, 0x10) = var_v1;
                M2C_FIELD(temp_s0, s32 *, 0x28) = (s32) ((M2C_FIELD(temp_s0, s32 *, 0x28) & ~0xFC) | 0x10);
                var_a1 = 0x1F;
                goto block_107;
            }
        } else {
            func_80016314(M2C_FIELD(temp_s1, void **, 0x410));
            M2C_FIELD(temp_s1, void **, 0x410) = NULL;
        }
    } else if ((M2C_FIELD(temp_s1, void **, 0x410) != NULL) || (temp_v0_5 = func_80015F0C(), M2C_FIELD(temp_s1, void **, 0x410) = temp_v0_5, func_800165E0(temp_v0_5, *(&gTrackMarkerTable + (temp_s3 * 4))), (M2C_FIELD(temp_s1, void **, 0x410) != NULL))) {
        temp_v1_10 = M2C_FIELD(temp_s1, u8 *, 0x185);
        temp_s0_2 = M2C_FIELD(temp_s1, void **, 0x410);
        switch (temp_v1_10) {                       /* switch 2; irregular */
        case 1:                                     /* switch 2 */
            var_v1_2 = 0x3FFF3FFF;
            break;
        case 2:                                     /* switch 2 */
            var_v1_2 = 0x3F3FFFFF;
            break;
        default:                                    /* switch 2 */
            var_v1_2 = 0xFF0000FF;
            break;
        }
        M2C_FIELD(temp_s0_2, s32 *, 0x10) = var_v1_2;
        M2C_FIELD(temp_s0_2, s32 *, 0x28) = (s32) ((M2C_FIELD(temp_s0_2, s32 *, 0x28) & ~0xFC) | 0x10);
        var_a1 = 0x18;
        if ((gBorderSkipFlag != 0) && (gVisibleSaveSlots >= 2)) {
            var_a1 = 0x2A;
        }
block_107:
        func_800448A4(M2C_FIELD(temp_s1, void **, 0x410), var_a1, 0x1B);
        M2C_FIELD(M2C_FIELD(temp_s1, void **, 0x410), s16 *, 0x1E) = 6;
    }
    temp_v1_11 = M2C_FIELD(arg0, void **, 0x68);
    if (M2C_FIELD(temp_v1_11, u16 *, 0xC) & 1) {
        M2C_FIELD(temp_v1_11, s32 *, 0x34) = 0;
        temp_fs0 = func_80081B44(temp_s3, 6, 7);
        var_fs1 = func_80081B44(temp_s3, 8, 9);
        if (*(D_80115088 + (temp_s3 * 0xA0)) != 0) {
            var_fs1 = -var_fs1;
        }
        temp_fs0_2 = temp_fs0 * 0.5625f;
        var_v0_2 = 1;
        temp_fs1_2 = var_fs1 * 0.6666667f;
        if (!(temp_fs0_2 <= 0.0002f)) {
            var_v0_2 = 0;
        }
        var_v1_3 = 1;
        if (!(temp_fs0_2 >= -0.0002f)) {
            var_v1_3 = 0;
        }
        if (var_v0_2 & var_v1_3) {
            temp_fv0_3 = M2C_FIELD(temp_s1, f32 *, 0x1C);
            temp_fa0 = (temp_fs0_2 - temp_fv0_3) + temp_fv0_3;
            M2C_FIELD(temp_s1, f32 *, 0x1C) = temp_fa0;
            if (absFloat(temp_fa0) < 0.01f) {
                M2C_FIELD(temp_s1, f32 *, 0x1C) = 0.0f;
            }
        } else {
            temp_fv0_4 = M2C_FIELD(temp_s1, f32 *, 0x1C);
            M2C_FIELD(temp_s1, f32 *, 0x1C) = (f32) (((temp_fs0_2 - temp_fv0_4) * 0.5f) + temp_fv0_4);
        }
        temp_fv0_5 = M2C_FIELD(temp_s1, f32 *, 0x1C);
        var_fv1_2 = -0.5625f;
        if ((temp_fv0_5 < -0.5625f) || (var_fv1_2 = 0.5625f, (temp_fv0_5 > 0.5625f))) {
            M2C_FIELD(temp_s1, f32 *, 0x1C) = var_fv1_2;
        }
        var_v0_3 = 1;
        if (!(temp_fs1_2 <= 0.0002f)) {
            var_v0_3 = 0;
        }
        var_v1_4 = 1;
        if (!(temp_fs1_2 >= -0.0002f)) {
            var_v1_4 = 0;
        }
        if (var_v0_3 & var_v1_4) {
            temp_fv0_6 = M2C_FIELD(temp_s1, f32 *, 0x20);
            temp_fa0_2 = (temp_fs1_2 - temp_fv0_6) + temp_fv0_6;
            M2C_FIELD(temp_s1, f32 *, 0x20) = temp_fa0_2;
            if (absFloat(temp_fa0_2) < 0.01f) {
                M2C_FIELD(temp_s1, f32 *, 0x20) = 0.0f;
            }
        } else {
            temp_fv0_7 = M2C_FIELD(temp_s1, f32 *, 0x20);
            M2C_FIELD(temp_s1, f32 *, 0x20) = (f32) (((temp_fs1_2 - temp_fv0_7) * 0.5f) + temp_fv0_7);
        }
        temp_fv0_8 = M2C_FIELD(temp_s1, f32 *, 0x20);
        var_fv1_3 = -0.6666667f;
        if ((temp_fv0_8 < -0.6666667f) || (var_fv1_3 = 0.6666667f, (temp_fv0_8 > 0.6666667f))) {
            M2C_FIELD(temp_s1, f32 *, 0x20) = var_fv1_3;
        }
        temp_fv1_2 = M2C_FIELD(temp_s1, f32 *, 0x1C);
        var_fs0_2 = 0.0f;
        var_fs1_2 = 0.0f;
        if (temp_fv1_2 < -0.37f) {
            var_fs1_2 = temp_fv1_2 + 0.37f;
        } else if (temp_fv1_2 > 0.37f) {
            var_fs1_2 = temp_fv1_2 - 0.37f;
        }
        temp_fv1_3 = M2C_FIELD(temp_s1, f32 *, 0x20);
        if (temp_fv1_3 < -0.5f) {
            var_fs0_2 = temp_fv1_3 + 0.5f;
        } else if (temp_fv1_3 > 0.5f) {
            var_fs0_2 = temp_fv1_3 - 0.5f;
        }
        temp_fs1_3 = var_fs1_2 * 0.47f;
        var_v0_4 = 1;
        temp_fs0_3 = var_fs0_2 * 0.34f;
        if (!(temp_fs1_3 <= 0.0002f)) {
            var_v0_4 = 0;
        }
        var_v1_5 = 1;
        if (!(temp_fs1_3 >= -0.0002f)) {
            var_v1_5 = 0;
        }
        if (var_v0_4 & var_v1_5) {
            temp_fv1_4 = M2C_FIELD(temp_s1, f32 *, 0x2C);
            temp_fa0_3 = ((temp_fs1_3 - temp_fv1_4) * 0.48f) + temp_fv1_4;
            M2C_FIELD(temp_s1, f32 *, 0x2C) = temp_fa0_3;
            if (absFloat(temp_fa0_3) < 0.01f) {
                M2C_FIELD(temp_s1, f32 *, 0x2C) = 0.0f;
            }
        } else {
            temp_fv0_9 = M2C_FIELD(temp_s1, f32 *, 0x2C);
            M2C_FIELD(temp_s1, f32 *, 0x2C) = (f32) (((temp_fs1_3 - temp_fv0_9) * 0.08f) + temp_fv0_9);
        }
        temp_fv0_10 = M2C_FIELD(temp_s1, f32 *, 0x2C);
        var_fv1_4 = -0.47f;
        if ((temp_fv0_10 < -0.47f) || (var_fv1_4 = 0.47f, (temp_fv0_10 > 0.47f))) {
            M2C_FIELD(temp_s1, f32 *, 0x2C) = var_fv1_4;
        }
        temp_fs1_4 = M2C_FIELD(temp_s1, f32 *, 0x2C);
        var_v0_5 = 1;
        if (!(temp_fs0_3 <= 0.0002f)) {
            var_v0_5 = 0;
        }
        var_v1_6 = 1;
        if (!(temp_fs0_3 >= -0.0002f)) {
            var_v1_6 = 0;
        }
        if (var_v0_5 & var_v1_6) {
            temp_fv1_5 = M2C_FIELD(temp_s1, f32 *, 0x30);
            temp_fa0_4 = ((temp_fs0_3 - temp_fv1_5) * 0.42000002f) + temp_fv1_5;
            M2C_FIELD(temp_s1, f32 *, 0x30) = temp_fa0_4;
            if (absFloat(temp_fa0_4) < 0.01f) {
                M2C_FIELD(temp_s1, f32 *, 0x30) = 0.0f;
            }
        } else {
            temp_fv0_11 = M2C_FIELD(temp_s1, f32 *, 0x30);
            M2C_FIELD(temp_s1, f32 *, 0x30) = (f32) (((temp_fs0_3 - temp_fv0_11) * 0.07f) + temp_fv0_11);
        }
        temp_fv0_12 = M2C_FIELD(temp_s1, f32 *, 0x30);
        var_fv1_5 = -0.34f;
        if ((temp_fv0_12 < -0.34f) || (var_fv1_5 = 0.34f, (temp_fv0_12 > 0.34f))) {
            M2C_FIELD(temp_s1, f32 *, 0x30) = var_fv1_5;
        }
        temp_fv0_13 = M2C_FIELD(temp_s1, f32 *, 0x3C);
        var_fs1_3 = temp_fs1_4 / temp_fv0_13;
        var_fs0_3 = M2C_FIELD(temp_s1, f32 *, 0x30) / temp_fv0_13;
        if (D_800E1A16 == 0) {
            var_fs1_3 *= 0.4f;
            var_fs0_3 *= 0.7f;
        }
        M2C_FIELD(temp_s1, f32 *, 0x34) += var_fs0_3;
        D_800E1A1C -= var_fs1_3 * 1024.0f;
    } else {
        var_fs0_3 = 0.0f;
        if (*(D_8011508B + (temp_s3 * 0xA0)) != 0) {
            temp_fv0_14 = func_80081B44(temp_s3, 8, 9);
            var_v1_7 = 1;
            if (!(temp_fv0_14 <= 0.0002f)) {
                var_v1_7 = 0;
            }
            var_v0_6 = 1;
            if (!(temp_fv0_14 >= -0.0002f)) {
                var_v0_6 = 0;
            }
            var_fs1_4 = 0.4f;
            if (((var_v1_7 ^ 1) | (var_v0_6 ^ 1)) != 0) {
                var_fs1_4 = 0.1f;
            }
            temp_fv1_6 = M2C_FIELD(temp_s1, f32 *, 0x58);
            temp_fv0_15 = ((temp_fv0_14 - temp_fv1_6) * var_fs1_4) + temp_fv1_6;
            var_fv1_6 = -1.0f;
            M2C_FIELD(temp_s1, f32 *, 0x58) = temp_fv0_15;
            if ((temp_fv0_15 < -1.0f) || (var_fv1_6 = 1.0f, (temp_fv0_15 > 1.0f))) {
                M2C_FIELD(temp_s1, f32 *, 0x58) = var_fv1_6;
            }
            var_fs0_3 = M2C_FIELD(temp_s1, f32 *, 0x58);
            var_v1_8 = 1;
            if (!(var_fs0_3 <= 0.0002f)) {
                var_v1_8 = 0;
            }
            var_v0_7 = 1;
            if (!(var_fs0_3 >= -0.0002f)) {
                var_v0_7 = 0;
            }
            if (((var_v1_8 ^ 1) | (var_v0_7 ^ 1)) != 0) {
                if (*(D_80115088 + (temp_s3 * 0xA0)) != 0) {
                    var_fs0_3 = -var_fs0_3;
                }
                var_fs0_3 *= 0.048f;
                if (D_800E1A16 == 0) {
                    var_fs0_3 *= 0.6f;
                }
                M2C_FIELD(temp_s1, f32 *, 0x34) += var_fs0_3;
            }
        }
        var_v0_8 = 1;
        if (!(var_fs0_3 <= 0.0002f)) {
            var_v0_8 = 0;
        }
        var_v1_9 = 1;
        if (!(var_fs0_3 >= -0.0002f)) {
            var_v1_9 = 0;
        }
        if ((var_v0_8 & var_v1_9) && ((u32) ((u16) M2C_FIELD(arg0, s16 *, 0x7C) - 4) >= 2U)) {
            temp_fv0_16 = func_80081B44(temp_s3, 0xA, 0xB);
            var_v0_9 = 1;
            if (!(temp_fv0_16 <= 0.0002f)) {
                var_v0_9 = 0;
            }
            var_v1_10 = 1;
            if (!(temp_fv0_16 >= -0.0002f)) {
                var_v1_10 = 0;
            }
            var_fs1_5 = 0.4f;
            if (((var_v0_9 ^ 1) | (var_v1_10 ^ 1)) != 0) {
                var_fs1_5 = 0.1f;
            }
            temp_fv1_7 = M2C_FIELD(temp_s1, f32 *, 0x58);
            temp_fv0_17 = ((temp_fv0_16 - temp_fv1_7) * var_fs1_5) + temp_fv1_7;
            var_fv1_7 = -1.0f;
            M2C_FIELD(temp_s1, f32 *, 0x58) = temp_fv0_17;
            if ((temp_fv0_17 < -1.0f) || (var_fv1_7 = 1.0f, (temp_fv0_17 > 1.0f))) {
                M2C_FIELD(temp_s1, f32 *, 0x58) = var_fv1_7;
            }
            var_fs0_3 = M2C_FIELD(temp_s1, f32 *, 0x58);
            var_v1_11 = 1;
            if (!(var_fs0_3 <= 0.0002f)) {
                var_v1_11 = 0;
            }
            var_v0_10 = 1;
            if (!(var_fs0_3 >= -0.0002f)) {
                var_v0_10 = 0;
            }
            if (((var_v1_11 ^ 1) | (var_v0_10 ^ 1)) != 0) {
                M2C_FIELD(temp_s1, s8 *, 0x17E) = 1;
                if (*(D_80115088 + (temp_s3 * 0xA0)) != 0) {
                    var_fs0_3 = -var_fs0_3;
                }
                var_fs0_3 *= 0.04f;
                M2C_FIELD(temp_s1, f32 *, 0x34) += var_fs0_3;
            }
        }
    }
    temp_v1_12 = M2C_FIELD(arg0, s16 *, 0x7C);
    if (temp_v1_12 != 2) {
        if (temp_v1_12 != 5) {
            if (M2C_FIELD(temp_s1, f32 *, 0x34) < -1.0f) {
                M2C_FIELD(temp_s1, f32 *, 0x34) = -1.0f;
            } else {
                var_fv1_8 = 1.0f;
                goto block_237;
            }
        } else {
            temp_ft0 = (s32) M2C_FIELD(M2C_FIELD(M2C_FIELD(temp_s1, void **, 0xBC), void **, 0x6C), f32 *, 0x10);
            temp_fv1_8 = (f32) ((s32) (((s32) M2C_FIELD(arg0, f32 *, 0x40) - temp_ft0) << 0x14) >> 0x14);
            if (temp_fv1_8 < -358.54425f) {
                var_fv0 = (f32) temp_ft0 - 358.54425f;
                goto block_243;
            }
            if (temp_fv1_8 > 358.54425f) {
                var_fv0 = (f32) temp_ft0 + 358.54425f;
block_243:
                M2C_FIELD(arg0, f32 *, 0x40) = var_fv0;
            }
            temp_fv0_18 = M2C_FIELD(temp_s1, f32 *, 0x34);
            var_fv1_9 = -0.3f;
            if ((temp_fv0_18 < -0.3f) || (var_fv1_9 = 0.3f, (temp_fv0_18 > 0.3f))) {
                M2C_FIELD(temp_s1, f32 *, 0x34) = var_fv1_9;
            }
            D_800E1A1C = 0.0f;
        }
    } else {
        var_v0_11 = 1;
        if (!(var_fs0_3 <= 0.0002f)) {
            var_v0_11 = 0;
        }
        var_v1_12 = 1;
        if (!(var_fs0_3 >= -0.0002f)) {
            var_v1_12 = 0;
        }
        if (var_v0_11 & var_v1_12) {
            temp_fv1_9 = M2C_FIELD(temp_s1, f32 *, 0x34);
            if (temp_fv1_9 < 0.0f) {
                var_fv0_2 = temp_fv1_9 + 0.02f;
                var_condition_bit_2 = var_fv0_2 > 0.0f;
            } else {
                var_fv0_2 = temp_fv1_9 - 0.02f;
                var_condition_bit_2 = var_fv0_2 < 0.0f;
            }
            M2C_FIELD(temp_s1, f32 *, 0x34) = var_fv0_2;
            if (var_condition_bit_2) {
                M2C_FIELD(temp_s1, f32 *, 0x34) = 0.0f;
            }
        }
        if (M2C_FIELD(temp_s1, f32 *, 0x34) < -0.3f) {
            M2C_FIELD(temp_s1, f32 *, 0x34) = -0.3f;
        } else {
            var_fv1_8 = 0.3f;
block_237:
            if (var_fv1_8 < M2C_FIELD(temp_s1, f32 *, 0x34)) {
                M2C_FIELD(temp_s1, f32 *, 0x34) = var_fv1_8;
            }
        }
    }
    func_8006591C(arg0);
}
