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

s32 func_8005E350();
s32 func_8005EF30();
s32 func_80063C7C();
s32 func_80073AF8();
s32 func_80084338();
s32 *lookupDataEntry();
s32 relinkTrackMarkerSlot();
s32 requestSound();
s32 showTrackMarker();
s32 sprintf();
s32 startBonusSceneActor();
extern char D_800C46A1[];
extern char D_800D41A8[];
extern s16 D_800C7C14[];
extern s16 D_800C7C16[];
extern s32 gBorderSkipActive;
extern u8 gSceneType;
extern s32 gTrackMarkerSerial;
extern s32 sEnemyDefTable;
extern s32 sTrackMarkerTable;

typedef struct { unsigned char pad_0[38]; unsigned short field_26; unsigned short field_28; unsigned short field_2A; } __repair_record_temp_s3;
s32 func_8005EF84(void *arg0, void *arg1) {
    char sp30[128];
    char spB0[128];
    s32 *var_v0_2;
    s32 *var_v0_3;
    s32 var_a0_2;
    s32 var_a1;
    f32 temp_fv1;
    f32 temp_fv1_2;
    f32 temp_fv1_3;
    s16 temp_v0_2;
    s16 temp_v0_4;
    s16 temp_v0_6;
    s32 temp_v0_3;
    s32 var_a0;
    s32 var_a0_3;
    s32 var_s0;
    s32 var_s0_2;
    s32 var_s6;
    s32 var_v0;
    s32 var_v1;
    s8 temp_v0_5;
    u16 temp_a1;
    u16 temp_v0;
    u16 temp_v1;
    u16 temp_v1_2;
    u16 temp_v1_4;
    u16 temp_v1_9;
    u8 temp_s0;
    s32 temp_s2;
    s32 temp_v1_7;
    void *temp_a0;
    void *temp_a0_2;
    void *temp_a1_2;
    void *temp_s0_2;
    void *temp_s1;
    void *temp_s3;
    void *temp_s5;
    void *temp_v1_3;
    void *temp_v1_5;
    void *temp_v1_8;

    temp_s3 = M2C_FIELD(arg1, void **, 0x6C);
    temp_v1 = ((__repair_record_temp_s3*)temp_s3)->field_26;
    temp_s1 = M2C_FIELD(arg0, void **, 0x6C);
    switch (temp_v1) {                              /* switch 1; irregular */
    case 2:                                         /* switch 1 */
        temp_a1 = ((__repair_record_temp_s3*)temp_s3)->field_28;
        if (M2C_FIELD((temp_s1 + (temp_a1 * 2)), s16 *, 0x1BC) < D_800C7C16[temp_a1 * 2]) {
            if ((func_8005EF30(arg0, temp_a1) << 0x18) != 0) {
                if (gBorderSkipActive != 0) {
                    var_v0_2 = lookupDataEntry(((__repair_record_temp_s3*)temp_s3)->field_28 | 0x9000);
                    var_a0 = 0xA2;
                } else {
                    var_v0_2 = lookupDataEntry(((__repair_record_temp_s3*)temp_s3)->field_28 | 0x9000);
                    var_a0 = 0x16A;
                }
                sprintf(sp30, D_800D41A8, var_v0_2, lookupDataEntry(var_a0));
                gTrackMarkerSerial += 1;
                func_80073AF8(0, (&sTrackMarkerTable)[M2C_FIELD(temp_s1, s8 *, 0x182)], sp30, -1, -1, 1, 0, 0, 0, 0, 0);
                temp_v1_2 = ((__repair_record_temp_s3*)temp_s3)->field_28;
                temp_v1_3 = temp_s1 + (temp_v1_2 * 2);
                M2C_FIELD(temp_v1_3, u16 *, 0x1BC) += D_800C7C14[temp_v1_2 * 2];
                temp_v0 = ((__repair_record_temp_s3*)temp_s3)->field_28;
                temp_a0 = temp_s1 + (temp_v0 * 2);
                temp_v0_2 = D_800C7C16[temp_v0 * 2];
                if (temp_v0_2 < M2C_FIELD(temp_a0, s16 *, 0x1BC)) {
                    M2C_FIELD(temp_a0, s16 *, 0x1BC) = temp_v0_2;
                }
                if (M2C_FIELD(arg0, u16 *, 0x78) == 3) {
                    func_80084338(0xD8, arg0 + 0x24);
                } else {
                    requestSound(0xD8);
                }
                goto block_66;
            }
        }
        return 0;
    case 0:                                         /* switch 1 */
        temp_v1_4 = ((__repair_record_temp_s3*)temp_s3)->field_28;
        temp_v0_3 = temp_v1_4 * 0xE8;
        temp_s5 = temp_v0_3 + (char *)&sEnemyDefTable;
        temp_s2 = M2C_FIELD(temp_s5, u8 *, 0x80);
        var_s6 = 0;
        if ((u8) M2C_FIELD((temp_s1 + (temp_v1_4 * 8)), u8 *, 0x1FC) < (u8) *(D_800C46A1 + temp_v0_3)) {
            gTrackMarkerSerial += 1;
            func_80073AF8(0, (&sTrackMarkerTable)[M2C_FIELD(temp_s1, s8 *, 0x182)], lookupDataEntry(((__repair_record_temp_s3*)temp_s3)->field_28 | 0x6000), -1, -1, 1, 0, 0, 0, 0, 0);
            temp_v1_5 = temp_s1 + (((__repair_record_temp_s3*)temp_s3)->field_28 * 8);
            M2C_FIELD(temp_v1_5, u8 *, 0x1FC) += 1;
            var_s6 = 1;
            if (M2C_FIELD(arg0, u16 *, 0x78) == 3) {
                var_a0_2 = 0xD9;
                goto block_26;
            }
            var_a0_2 = 0xD9;
            goto block_27;
            goto block_28;
        }
        var_v0 = 1;
        if (M2C_FIELD((temp_s1 + (temp_s2 * 2)), s16 *, 0x1BC) < D_800C7C16[temp_s2 * 2]) {
            if (gBorderSkipActive != 0) {
                var_v0_3 = lookupDataEntry(temp_s2 | 0x9000);
                var_a0_3 = 0x16A;
            } else {
                var_v0_3 = lookupDataEntry(temp_s2 | 0x9000);
                var_a0_3 = 0xA2;
            }
            sprintf(spB0, D_800D41A8, var_v0_3, lookupDataEntry(var_a0_3));
            gTrackMarkerSerial += 1;
            func_80073AF8(0, (&sTrackMarkerTable)[M2C_FIELD(temp_s1, s8 *, 0x182)], spB0, -1, -1, 1, 0, 0, 0, 0, 0);
            var_a0_2 = 0xD8;
            if (M2C_FIELD(arg0, u16 *, 0x78) == 3) {
block_26:
                func_80084338(var_a0_2, arg0 + 0x24);
            } else {
block_27:
                requestSound(var_a0_2);
            }
block_28:
            temp_fv1 = randomFloatScaled(0.5f);
            if (var_s6 != 0) {
                temp_s0 = M2C_FIELD(temp_s5, u8 *, 0x82);
                M2C_FIELD((temp_s1 + ((s32) (func_80063C7C((s16) ((__repair_record_temp_s3*)temp_s3)->field_28) << 0x10) >> 0xD)), u8 *, 0x1FF) = temp_s0;
            } else {
                temp_fv1_2 = (temp_fv1 * (f32) M2C_FIELD(temp_s5, u8 *, 0x82)) + 1.0f;
                var_s0 = (u32)temp_fv1_2;
                ((u16 (*)[0x1]) temp_s1)[temp_s2][0xde] += var_s0;
            }
            temp_a1_2 = temp_s1 + (temp_s2 * 2);
            temp_v0_4 = D_800C7C16[temp_s2 * 2];
            if (temp_v0_4 < M2C_FIELD(temp_a1_2, s16 *, 0x1BC)) {
                M2C_FIELD(temp_a1_2, s16 *, 0x1BC) = temp_v0_4;
                return 0;
            }
            temp_v0_5 = M2C_FIELD(temp_s5, s8 *, 4);
            if (temp_v0_5 != 0) {
                temp_s0_2 = ((((__repair_record_temp_s3*)temp_s3)->field_28 + temp_v0_5) * 0xE8) + (char *)&sEnemyDefTable;
                temp_v1_7 = M2C_FIELD(temp_s0_2, u8 *, 0x80);
                if (temp_v1_7 != M2C_FIELD(temp_s5, u8 *, 0x80)) {
                    temp_fv1_3 = ((randomFloatScaled(0.5f) + 0.5f) * (f32) M2C_FIELD(temp_s0_2, u8 *, 0x82)) + 1.0f;
                    var_s0_2 = (u32)temp_fv1_3;
                    if (var_s6 != 0) {
                        M2C_FIELD((temp_s1 + ((s32) (func_80063C7C((s16) (((__repair_record_temp_s3*)temp_s3)->field_28 + (s8) (u8) M2C_FIELD(temp_s5, s8 *, 4))) << 0x10) >> 0xD)), s8 *, 0x1FF) = (s8) var_s0_2;
                    } else {
                        temp_v1_8 = temp_s1 + (temp_v1_7 * 2);
                        M2C_FIELD(temp_v1_8, u16 *, 0x1BC) += var_s0_2;
                    }
                    temp_a0_2 = temp_s1 + (temp_s2 * 2);
                    temp_v0_6 = D_800C7C16[temp_s2 * 2];
                    if (temp_v0_6 < M2C_FIELD(temp_a0_2, s16 *, 0x1BC)) {
                        M2C_FIELD(temp_a0_2, s16 *, 0x1BC) = temp_v0_6;
                    }
                }
            }
            goto block_66;
        }
        /* Duplicate return node #67. Try simplifying control flow for better match */
        return var_v0;
    case 1:                                         /* switch 1 */
        func_8005E350(arg0, ((__repair_record_temp_s3*)temp_s3)->field_28, 1);
        if ((gBorderSkipActive != 0) && (gSceneType == 8)) {
            temp_v1_9 = ((__repair_record_temp_s3*)temp_s3)->field_28;
            switch (temp_v1_9) {                    /* switch 2; irregular */
            case 23:                                /* switch 2 */
                var_a1 = 1;
                relinkTrackMarkerSlot(temp_s1, var_a1);
                if (M2C_FIELD(M2C_FIELD(temp_s1, void **, 0xB4), u8 *, 0x10) == 7) {
                    startBonusSceneActor(temp_s1);
                }
                break;
            case 24:                                /* switch 2 */
                var_a1 = 2;
                relinkTrackMarkerSlot(temp_s1, var_a1);
                if (M2C_FIELD(M2C_FIELD(temp_s1, void **, 0xB4), u8 *, 0x10) == 7) {
                    startBonusSceneActor(temp_s1);
                }
                break;
            case 25:                                /* switch 2 */
                var_a1 = 4;
                relinkTrackMarkerSlot(temp_s1, var_a1);
                if (M2C_FIELD(M2C_FIELD(temp_s1, void **, 0xB4), u8 *, 0x10) == 7) {
                    startBonusSceneActor(temp_s1);
                }
                break;
            }
        }
        M2C_FIELD(arg1, s32 *, 0x60) |= 1;
        goto block_66;
    default:
block_66:
        showTrackMarker(((__repair_record_temp_s3*)temp_s3)->field_2A);
        return 1;
    }
}

