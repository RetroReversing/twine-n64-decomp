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

s32 func_800160FC();
s32 spawnTrackMarker();
s32 func_80022A30();
s32 func_80022AD8();
s32 func_80022E18();
s32 func_80025D84();
s32 func_80025E9C();
s32 formatTextEntry();
s32 findEntryPayload();
s32 func_800274BC();
s32 func_8002A644();
s32 func_8002A7CC();
s32 func_8002A9A8();
s32 func_8002AC04();
u8 countValidSaveSlots();
s32 lookupDataEntry();
s32 sprintf();
extern char D_800D285C[];
extern char sFmtEntryName[];
extern u8 gCurrentSaveSlot;
extern u8 sMenuListKind;
extern s8 D_800BD690;
extern char D_800BD914[];
typedef struct { u8 f0; u8 pad[23]; } Slot_80100198;
extern Slot_80100198 D_80100198[];
extern u8 gPickupSavedByte;
extern char D_80100408[];
extern u8 D_801007C1;
extern u8 D_80102EB0;
extern u8 gValidSaveSlotCount;
extern char D_80102F48[];
extern u8 D_80104310;
extern u8 D_80108960;
extern void *gMenuItems;
extern u8 D_80109E20;
extern u8 D_8010A394;
extern char gPickupSearchBox[];
extern u8 D_8010D2B1;
extern u8 D_8010D454;
extern char D_80115088[];
extern char D_80115089[];
extern char D_8011508A[];
extern char D_8011508C[];
extern char D_8011508D[];
extern char D_8011508E[];
extern char D_8011508F[];
extern char D_80115090[];
extern char D_80115091[];
extern s32 func_8001AC88;
extern s32 bindMenuItemRecord;

void func_8001D738(void) {
    s32 temp_a0;
    s32 temp_s0;
    s32 temp_s2;
    s32 temp_s2_2;
    s32 temp_s3;
    s32 temp_s4;
    s32 temp_s5;
    s32 temp_s6;
    s32 temp_s7;
    s32 temp_v0_8;
    s32 temp_v1;
    s32 var_a0;
    s32 var_a0_2;
    s32 var_a0_3;
    s32 var_a0_4;
    s32 var_a0_5;
    s32 var_a0_6;
    s32 var_a0_7;
    s32 var_a0_8;
    s32 var_a0_9;
    s32 var_a2;
    s32 var_a3;
    s32 var_s1;
    s32 var_s1_2;
    u32 temp_s0_2;
    u8 temp_v0;
    u8 temp_v0_2;
    u8 temp_v0_3;
    u8 temp_v0_4;
    u8 temp_v0_5;
    u8 temp_v0_6;
    u8 temp_v0_7;
    s32 temp_v1_2;
    s32 temp_v1_3;

    D_800BD690 = 1;
    temp_s6 = findEntryPayload(D_800BD914, 0x78);
    temp_s2 = findEntryPayload(D_800BD914, 0x79);
    var_s1 = findEntryPayload(D_800BD914, 0x7A);
    if (var_s1 == 0) {
        var_s1 = findEntryPayload(D_800BD914, 0x13);
    }
    temp_s3 = findEntryPayload(D_800BD914, 0x7B);
    temp_s7 = findEntryPayload(D_800BD914, 0x7D);
    temp_s4 = findEntryPayload(D_800BD914, 0x7C);
    temp_s0 = findEntryPayload(D_800BD914, 0x162);
    temp_s5 = findEntryPayload(D_800BD914, 0x7F);
    if (((temp_s6 != 0) & (temp_s2 != 0)) && ((var_s1 != 0) & (temp_s3 != 0)) && ((temp_s7 != 0) & (temp_s4 != 0)) && ((temp_s5 != 0) & (temp_s0 != 0))) {
        gCurrentSaveSlot = gPickupSavedByte;
        temp_v1 = gPickupSavedByte & 0xFF;
        D_80100198[temp_v1].f0 = *(D_80115091 + (temp_v1 * 0xA0));
        temp_v0 = *(D_80115088 + (gCurrentSaveSlot * 0xA0));
        D_80109E20 = temp_v0;
        var_a0 = 0x10;
        if (temp_v0 != 0) {
            var_a0 = 0xF;
        }
        do { formatTextEntry(temp_s6, sFmtEntryName, lookupDataEntry(var_a0)); } while (0);
        temp_v0_2 = *(D_80115089 + (gCurrentSaveSlot * 0xA0));
        D_8010D454 = temp_v0_2;
        var_a0_2 = 0xA;
        if (temp_v0_2 != 0) {
            var_a0_2 = 9;
        }
        formatTextEntry(temp_s2, sFmtEntryName, lookupDataEntry(var_a0_2));
        D_8010D2B1 = *(D_8011508A + (gCurrentSaveSlot * 0xA0));
        temp_v1_2 = D_80100198[gCurrentSaveSlot].f0;
        temp_a0 = var_s1 - 0x28;
        if (((s32) temp_v1_2 < 2) && ((s32) temp_v1_2 >= 0)) {
            func_80025E9C(temp_a0, var_s1, temp_s2 - 0x28, temp_s3 - 0x28, 1, 0xD);
        } else {
            func_80025D84(temp_a0, var_s1, temp_s2 - 0x28, temp_s3 - 0x28, 0x7A, 1);
            var_a0_3 = 0x11;
            if (D_8010D2B1 != 0) {
                var_a0_3 = 0x12;
            }
            formatTextEntry(var_s1, sFmtEntryName, lookupDataEntry(var_a0_3));
        }
        temp_v0_3 = *(D_80115090 + (gCurrentSaveSlot * 0xA0));
        D_80102EB0 = temp_v0_3;
        var_a0_4 = 0xA;
        if (temp_v0_3 != 0) {
            var_a0_4 = 9;
        }
        formatTextEntry(temp_s3, sFmtEntryName, lookupDataEntry(var_a0_4));
        temp_v0_4 = *(D_8011508D + (gCurrentSaveSlot * 0xA0));
        D_801007C1 = temp_v0_4;
        var_a0_5 = 0xA;
        if (temp_v0_4 != 0) {
            var_a0_5 = 9;
        }
        do { formatTextEntry(temp_s7, sFmtEntryName, lookupDataEntry(var_a0_5)); } while (0);
        temp_v0_5 = *(D_8011508C + (gCurrentSaveSlot * 0xA0));
        D_8010A394 = temp_v0_5;
        var_a0_6 = 0xA;
        if (temp_v0_5 != 0) {
            var_a0_6 = 9;
        }
        formatTextEntry(temp_s4, sFmtEntryName, lookupDataEntry(var_a0_6));
        D_80108960 = *(D_8011508F + (gCurrentSaveSlot * 0xA0));
        temp_v1_3 = D_80100198[gCurrentSaveSlot].f0;
        if ((s32) temp_v1_3 >= 0) {
            var_a0_7 = temp_s0 - 0x28;
            if ((s32) temp_v1_3 >= 2) {
                if ((s32) temp_v1_3 < 6) {
                    if ((s32) temp_v1_3 >= 4) {
                        var_a0_7 = temp_s0 - 0x28;
                        goto block_27;
                    }
                    goto block_31;
                }
                goto block_30;
            }
block_27:
            func_80025E9C(var_a0_7, temp_s0, temp_s4 - 0x28, temp_s5 - 0x28, 1, 0xD);
            if (M2C_FIELD(gMenuItems, u8 *, 8) == 0xD) {
                func_800274BC(0x100, 2);
            }
        } else {
            var_a0_7 = temp_s0 - 0x28;
block_30:
block_31:
            func_80025D84(var_a0_7, temp_s0, temp_s4 - 0x28, temp_s5 - 0x28, 0x162, 1);
            var_a0_8 = 0xA;
            if (D_80108960 != 0) {
                var_a0_8 = 9;
            }
            formatTextEntry(temp_s0, sFmtEntryName, lookupDataEntry(var_a0_8));
        }
        temp_v0_6 = *(D_8011508E + (gCurrentSaveSlot * 0xA0));
        D_80104310 = temp_v0_6;
        var_a0_9 = 0xA;
        if (temp_v0_6 != 0) {
            var_a0_9 = 9;
        }
        var_s1_2 = 0;
        formatTextEntry(temp_s5, sFmtEntryName, lookupDataEntry(var_a0_9));
        func_8002A644(gPickupSearchBox, D_80100408, 0x1A4, 0xB, 0x25, 0xB4, 0x34, 0xE, 1, &bindMenuItemRecord, &func_8001AC88);
        func_80022A30(sMenuListKind, 0x23, 0x2C, 0x33, 0x9A);
        temp_v0_7 = countValidSaveSlots(0xA3);
        gValidSaveSlotCount = temp_v0_7;
        if (temp_v0_7 & 0xFF) {
            do {
                temp_s0_2 = var_s1_2 & 0xFFFF;
                temp_v0_8 = spawnTrackMarker(sMenuListKind);
                *(s32 *)((temp_s0_2 * 4) + D_80102F48) = temp_v0_8;
                if (temp_v0_8 != 0) {
                    temp_s5 = lookupDataEntry((var_s1_2 + 0x400D) & 0xFFFF);
                    if (temp_s0_2 < 4U) {
                        var_a2 = lookupDataEntry(0xAD);
                        var_a3 = temp_s0_2 + 1;
                    
                    sprintf(temp_s5, D_800D285C, var_a2, var_a3);} else {
                        var_a2 = lookupDataEntry(0x158);
                        var_a3 = temp_s0_2 - 3;
                    
                    sprintf(temp_s5, D_800D285C, var_a2, var_a3);}
                    func_800160FC(*(s32 *)(((var_s1_2 & 0xFFFF) * 4) + D_80102F48), temp_s5, 0x40);
                }
                func_8002A7CC(gPickupSearchBox, *(s32 *)(((var_s1_2 & 0xFFFF) * 4) + D_80102F48), var_s1_2 & 0xFF, 1);
                var_s1_2 += 1;
            } while ((u32) (var_s1_2 & 0xFFFF) < (u8) gValidSaveSlotCount);
        }
        func_80022E18(sMenuListKind);
        func_80022AD8(sMenuListKind);
        func_8002A9A8(gPickupSearchBox, gPickupSavedByte);
        func_8002AC04(gPickupSearchBox, 1);
    }
}
