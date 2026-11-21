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

s32 requestSound();
u32 randomIntBelow();
s32 func_80063C7C();
s32 setActionSlot();
s32 func_80073AF8();
s32 func_80084338();
s32 *lookupDataEntry();
s32 startBonusSceneActor();
s32 relinkTrackMarker();
s32 sprintf();
extern char D_800C447C[];
extern char D_800C4484[];
extern char D_800C469C[];
extern char D_800C46A1[];
extern char D_800C471C[];
extern char D_800C7C16[];
extern u8 gSceneType;
extern s32 gTrackMarkerSerial;
extern char gTrackMarkerTable[];
extern void *gBonusSceneHandle;

extern char D_800D41E0[];
extern char jtbl_800D41E8[];
s32 func_8005FE20(void *arg0, s32 *arg1) {
    char sp30[124];
    s32 (*temp_v0_10)(void *, s32 *);
    union { s32 * pointer; s32 value; } __repair_phase_storage;
    s32 *temp_s0_3;
    s32 *var_a1;
    s16 temp_v0_5;
    s16 temp_v0_8;
    s16 temp_v0_9;
    s32 temp_s3;
    
    s32 temp_v1;
    s32 var_a0_2;
    s32 var_v0;
    s8 temp_a1_2;
    u16 temp_a0;
    u16 temp_a0_3;
    s32 temp_s0;
    u16 temp_v0_3;
    u16 temp_v0_4;
    u16 temp_v1_3;
    u16 var_a0_3;
    u16 var_a0_4;
    u32 var_a0;
    u32 var_s0;
    u8 temp_s3_2;
    u8 temp_v1_6;
    void **var_v1;
    void *temp_a0_2;
    void *temp_a0_4;
    void *temp_a1;
    void *temp_s1;
    void *temp_s2;
    void *temp_s4;
    void *temp_v0;
    void *temp_v0_2;
    void *temp_v0_7;
    void *temp_v1_2;
    void *temp_v1_4;
    void *temp_v1_5;
    void *temp_v1_7;

    var_a1 = arg1;
    temp_s1 = M2C_FIELD(arg0, void **, 0x6C);
    temp_s2 = M2C_FIELD(var_a1, void **, 0x6C);
    if (gSceneType == 8) {
        temp_s3 = randomIntBelow(0x1E) / 10;
        var_s0 = 0;
        var_a1 = NULL;
        var_a0 = 0;
        var_v1 = &gBonusSceneHandle;
        do {
            temp_v0 = *var_v1;
            var_a0 += 1;
            if (temp_v0 != NULL) {
                temp_v0_2 = M2C_FIELD(M2C_FIELD(temp_v0, void **, 0x6C), void **, 0xB4);
                if (temp_v0_2 != NULL) {
                    var_s0 |= M2C_FIELD(temp_v0_2, u8 *, 0x10);
                }
            }
            var_v1 += 1;
        } while (var_a0 < 4U);
        if ((var_s0 ^ 1) & 1 & (temp_s3 == 0)) {
            relinkTrackMarker(temp_s1, 1);
            var_a1 = (s32 *)1;
        }
        if (((var_s0 >> 1) ^ 1) & 1 & (temp_s3 == 1)) {
            relinkTrackMarker(temp_s1, 2);
            var_a1 = (s32 *)1;
        }
        if (((var_s0 >> 2) ^ 1) & 1 & (temp_s3 == 2)) {
            relinkTrackMarker(temp_s1, 4);
            var_a1 = (s32 *)1;
        }
        if (var_a1 != NULL) {
            var_v0 = 1;
            if (M2C_FIELD(M2C_FIELD(temp_s1, void **, 0xB4), u8 *, 0x10) == 7) {
                startBonusSceneActor(temp_s1);
                return 1;
            }
            /* Duplicate return node #67. Try simplifying control flow for better match */
            return var_v0;
        }
        goto block_15;
    }
block_15:
    temp_s0 = M2C_FIELD(temp_s2, u16 *, 0x3C);
    if (temp_s0 != 1) {
        if ((s32) temp_s0 >= 2) {
            var_v0 = 1;
            if (temp_s0 == 2) {
                temp_a0 = M2C_FIELD(temp_s2, u16 *, 0x3E);
                temp_v1 = temp_a0 & 0xFFFF;
                var_v0 = 0;
                if (M2C_FIELD((temp_s1 + (temp_v1 * 2)), s16 *, 0x1BC) < *(s16 *)(D_800C7C16 + (temp_v1 * 4))) {
                    __repair_phase_storage.pointer = lookupDataEntry(temp_a0 | 0x9000, var_a1);
                    sprintf(&sp30, D_800D41E0, __repair_phase_storage.pointer, lookupDataEntry(0x16A));
                    gTrackMarkerSerial += 1;
                    func_80073AF8(0, *(s32 *)(gTrackMarkerTable + (M2C_FIELD(temp_s1, s8 *, 0x182) * 4)), &sp30, -1, -1, 1, 0, 0, 0, 0, 0);
                    temp_v0_3 = M2C_FIELD(temp_s2, u16 *, 0x3E);
                    switch (temp_v0_3) {
                    case 3:
                        var_a0_2 = 0x18;
                        break;
                    case 1:
                    case 2:
                    case 4:
                        var_a0_2 = 0x5A;
                        break;
                    case 5:
                        var_a0_2 = 0x64;
                        break;
                    case 6:
                        var_a0_2 = 0x3C;
                        break;
                    case 7:
                        var_a0_2 = 0x20;
                        break;
                    case 9:
                        var_a0_2 = 6;
                        break;
                    case 11:
                        var_a0_2 = 8;
                        break;
                    case 12:
                    case 13:
                        var_a0_2 = 0x14;
                        break;
                    default:
                        var_a0_2 = 0;
                        break;
                    }
                    temp_v1_2 = temp_s1 + (M2C_FIELD(temp_s2, u16 *, 0x3E) * 2);
                    M2C_FIELD(temp_v1_2, u16 *, 0x1BC) += var_a0_2;
                    temp_v0_4 = M2C_FIELD(temp_s2, u16 *, 0x3E);
                    temp_a0_2 = temp_s1 + (temp_v0_4 * 2);
                    temp_v0_5 = *(s16 *)(D_800C7C16 + (temp_v0_4 * 4));
                    if (temp_v0_5 < M2C_FIELD(temp_a0_2, s16 *, 0x1BC)) {
                        M2C_FIELD(temp_a0_2, s16 *, 0x1BC) = temp_v0_5;
                    }
                    var_a0_3 = 0xD8;
                    if (M2C_FIELD(arg0, u16 *, 0x78) == 3) {
                        goto block_63;
                    }
                    goto block_65;
                }
            }
            /* Duplicate return node #67. Try simplifying control flow for better match */
            return var_v0;
        }
        if (temp_s0 != 0) {
            return 1;
        }
        temp_v1_3 = M2C_FIELD(temp_s2, u16 *, 0x3E);
        __repair_phase_storage.value = temp_v1_3 * 0xE8;
        temp_s4 = __repair_phase_storage.value + D_800C469C;
        temp_s3_2 = M2C_FIELD(temp_s4, u8 *, 0x80);
        if ((u8) M2C_FIELD((temp_s1 + (temp_v1_3 * 8)), u8 *, 0x1FC) < (u8) *(D_800C46A1 + __repair_phase_storage.value)) {
            gTrackMarkerSerial += 1;
            func_80073AF8(0, *(s32 *)(gTrackMarkerTable + (M2C_FIELD(temp_s1, s8 *, 0x182) * 4)), lookupDataEntry(M2C_FIELD(temp_s2, u16 *, 0x3E) | 0x6000, D_800C469C), -1, -1, 1, 0, 0, 0, 0, 0);
            temp_v1_4 = temp_s1 + (M2C_FIELD(temp_s2, u16 *, 0x3E) * 8);
            M2C_FIELD(temp_v1_4, u8 *, 0x1FC) += 1;
            var_a0_4 = 0xD9;
            if (M2C_FIELD(arg0, u16 *, 0x78) != 3) {
                requestSound(0xD9U);
            } else {
                goto block_43;
            }
            goto block_45;
        }
        var_v0 = 0;
        if (M2C_FIELD((temp_s1 + (temp_s3_2 * 2)), s16 *, 0x1BC) < *(s16 *)(D_800C7C16 + (temp_s3_2 * 4))) {
            temp_s0_3 = lookupDataEntry(temp_s3_2 | 0x9000, D_800C469C);
            sprintf(&sp30, jtbl_800D41E8, temp_s0_3, lookupDataEntry(0x16A));
            gTrackMarkerSerial += 1;
            func_80073AF8(0, *(s32 *)(gTrackMarkerTable + (M2C_FIELD(temp_s1, s8 *, 0x182) * 4)), &sp30, -1, -1, 1, 0, 0, 0, 0, 0);
            var_a0_4 = 0xD8;
            if (M2C_FIELD(arg0, u16 *, 0x78) != 3) {
                requestSound(0xD8U);
            } else {
block_43:
                func_80084338(var_a0_4, arg0 + 0x24);
            }
block_45:
            if (M2C_FIELD((temp_s1 + ((s32) (func_80063C7C((s16) M2C_FIELD(temp_s2, u16 *, 0x3E)) << 0x10) >> 0xD)), s8 *, 0x1FF) == 0) {
                M2C_FIELD((temp_s1 + ((s32) (func_80063C7C((s16) M2C_FIELD(temp_s2, u16 *, 0x3E)) << 0x10) >> 0xD)), u8 *, 0x1FF) = (u8) M2C_FIELD(temp_s4, u8 *, 0x82);
                temp_v1_5 = temp_s1 + (temp_s3_2 * 2);
                M2C_FIELD(temp_v1_5, u16 *, 0x1BC) += M2C_FIELD(temp_s4, u8 *, 0x82);
            } else {
                temp_v0_7 = temp_s1 + (temp_s3_2 * 2);
                M2C_FIELD(temp_v0_7, u16 *, 0x1BC) += (M2C_FIELD(temp_s4, u8 *, 0x82) * 2);
            }
            temp_a1 = temp_s1 + (temp_s3_2 * 2);
            temp_v0_8 = *(s16 *)(D_800C7C16 + (temp_s3_2 * 4));
            if (temp_v0_8 < M2C_FIELD(temp_a1, s16 *, 0x1BC)) {
                M2C_FIELD(temp_a1, s16 *, 0x1BC) = temp_v0_8;
            }
            temp_a1_2 = M2C_FIELD(temp_s4, s8 *, 4);
            var_v0 = 1;
            if (temp_a1_2 != 0) {
                temp_a0_3 = M2C_FIELD(temp_s2, u16 *, 0x3E);
                temp_v1_6 = *(D_800C471C + ((temp_a0_3 + temp_a1_2) * 0xE8));
                if (temp_v1_6 != M2C_FIELD(temp_s4, u8 *, 0x80)) {
                    if (M2C_FIELD((temp_s1 + ((s32) (func_80063C7C((s16) (temp_a0_3 + temp_a1_2), temp_a1_2) << 0x10) >> 0xD)), s8 *, 0x1FF) == 0) {
                        M2C_FIELD((temp_s1 + ((s32) (func_80063C7C((s16) (M2C_FIELD(temp_s2, u16 *, 0x3E) + (s8) (u8) M2C_FIELD(temp_s4, s8 *, 4))) << 0x10) >> 0xD)), s8 *, 0x1FF) = 2;
                    } else {
                        temp_v1_7 = temp_s1 + (temp_v1_6 * 2);
                        M2C_FIELD(temp_v1_7, u16 *, 0x1BC) += 2;
                    }
                    temp_a0_4 = temp_s1 + (temp_v1_6 * 2);
                    temp_v0_9 = *(s16 *)(D_800C7C16 + (temp_v1_6 * 4));
                    if (temp_v0_9 < M2C_FIELD(temp_a0_4, s16 *, 0x1BC)) {
                        M2C_FIELD(temp_a0_4, s16 *, 0x1BC) = temp_v0_9;
                        goto block_66;
                    }
                    return 1;
                }
                goto block_66;
            }
            /* Duplicate return node #67. Try simplifying control flow for better match */
            return var_v0;
        }
        /* Duplicate return node #67. Try simplifying control flow for better match */
        return var_v0;
    }
    temp_v0_10 = *(s32 *)(D_800C447C + (M2C_FIELD(temp_s2, u16 *, 0x3E) * 0x10));
    if (temp_v0_10 != NULL) {
        temp_v0_10(arg0, var_a1);
    }
    setActionSlot(temp_s1, M2C_FIELD(temp_s2, u8 *, 0x3F), M2C_FIELD(temp_s2, u8 *, 0x3D), 0);
    gTrackMarkerSerial += 1;
    func_80073AF8(0, *(s32 *)(gTrackMarkerTable + (M2C_FIELD(temp_s1, s8 *, 0x182) * 4)), lookupDataEntry(M2C_FIELD(temp_s2, u16 *, 0x3E) | 0x7000), -1, -1, (s32) temp_s0, 0, 0, 0, 0, 0);
    if (M2C_FIELD(arg0, u16 *, 0x78) == 3) {
        var_a0_3 = *(u16 *)(D_800C4484 + (M2C_FIELD(temp_s2, u16 *, 0x3E) * 0x10));
block_63:
        func_80084338(var_a0_3, arg0 + 0x24);
        return 1;
    }
    var_a0_3 = *(u16 *)(D_800C4484 + (M2C_FIELD(temp_s2, u16 *, 0x3E) * 0x10));
block_65:
    requestSound(var_a0_3);
block_66:
    var_v0 = 1;
    return var_v0;
}
