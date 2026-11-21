/* machine draft (m2c) for gcc-2.7.2-kmc -G0 -mips3 -mgp32 -mfp32 -O2, tried by autopilot */

s32 func_800160FC();
s32 func_800162BC();
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
s8 countValidSaveSlots();
s32 func_800316B8();
s32 lookupDataEntry();
s32 sprintf();
extern u8 gCurrentSaveSlot;
extern u8 gMenuListParam;
typedef struct { u8 f0; u8 pad[23]; } Slot_80100198;
extern Slot_80100198 D_80100198[];
extern u8 gPickupSavedByte;
extern s32 gSaveSlotCount;
extern char D_80100408[];
extern u8 D_801007C1;
extern u8 D_80102EB0;
extern s8 gValidSaveSlotCount;
extern s32 gBorderSkipFlag;
extern char D_80102F48[];
extern u8 D_80104310;
extern u8 D_80108960;
extern void *gMenuState;
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
extern s32 func_8001AC88;
extern s32 func_80022C04;

void func_8001F9A4(void) {
    s32 sp34;
    s32 sp3C;
    s32 temp_a0;
    s32 temp_fp;
    s32 temp_s1;
    s32 temp_s1_2;
    s32 temp_s2;
    s32 temp_s2_2;
    s32 temp_s3;
    s32 temp_s4;
    s32 temp_s6;
    s32 temp_s7;
    s32 temp_v0_7;
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
    s32 var_s0;
    s32 var_s0_2;
    u32 temp_s1_3;
    u8 temp_v0;
    u8 temp_v0_2;
    u8 temp_v0_3;
    u8 temp_v0_4;
    u8 temp_v0_5;
    u8 temp_v0_6;
    u8 temp_v1;
    s32 temp_v1_2;

    temp_s2 = findEntryPayload((*(void **)((char *)(gMenuState) + 0x10)), 0x79);
    temp_s1 = findEntryPayload((*(void **)((char *)(gMenuState) + 0x10)), 0x78);
    var_s0 = findEntryPayload((*(void **)((char *)(gMenuState) + 0x10)), 0x7A);
    if (var_s0 == 0) {
        var_s0 = findEntryPayload((*(void **)((char *)(gMenuState) + 0x10)), 0x13);
    }
    temp_s7 = findEntryPayload((*(void **)((char *)(gMenuState) + 0x10)), 0x7B);
    sp34 = findEntryPayload((*(void **)((char *)(gMenuState) + 0x10)), 0x7D);
    temp_fp = findEntryPayload((*(void **)((char *)(gMenuState) + 0x10)), 0x7C);
    temp_s6 = findEntryPayload((*(void **)((char *)(gMenuState) + 0x10)), 0x162);
    sp3C = findEntryPayload((*(void **)((char *)(gMenuState) + 0x10)), 0x7F);
    if (((temp_s1 != 0) & (temp_s2 != 0)) && ((var_s0 != 0) & (temp_s7 != 0)) && ((sp34 != 0) & (temp_fp != 0)) && ((sp3C != 0) & (temp_s6 != 0))) {
        (*(s8 *)((char *)((*(void **)((char *)(gMenuState) + 0x10))) + 4)) = 1;
        if (gBorderSkipFlag == 0) {
            gPickupSavedByte = 0;
        }
        gCurrentSaveSlot = gPickupSavedByte;
        temp_v0 = *(D_80115088 + (gPickupSavedByte * 0xA0));
        D_80109E20 = temp_v0;
        var_a0 = 0x10;
        if (temp_v0 != 0) {
            var_a0 = 0xF;
        }
        formatTextEntry(temp_s1, "%s", lookupDataEntry(var_a0));
        temp_v0_2 = *(D_80115089 + (gCurrentSaveSlot * 0xA0));
        D_8010D454 = temp_v0_2;
        var_a0_2 = 0xA;
        if (temp_v0_2 != 0) {
            var_a0_2 = 9;
        }
        temp_s4 = temp_s2 - 0x28;
        formatTextEntry(temp_s2, "%s", lookupDataEntry(var_a0_2));
        temp_s3 = temp_s1 - 0x28;
        temp_s1_2 = var_s0 - 0x28;
        func_80025D84(temp_s4, temp_s2, temp_s3, temp_s1_2, 0x79, 1);
        if ((gBorderSkipFlag == 0) && ((func_800316B8() & 0xFFFF) == 2)) {
            func_80025E9C(temp_s4, temp_s2, temp_s3, temp_s1_2, 1, 0xD);
        }
        D_8010D2B1 = *(D_8011508A + (gCurrentSaveSlot * 0xA0));
        temp_v1 = D_80100198[gCurrentSaveSlot].f0;
        temp_a0 = var_s0 - 0x28;
        if (((s32) temp_v1 < 2) && ((s32) temp_v1 >= 0)) {
            func_80025E9C(temp_a0, var_s0, temp_s2 - 0x28, temp_s7 - 0x28, 1, 0xD);
        } else {
            func_80025D84(temp_a0, var_s0, temp_s2 - 0x28, temp_s7 - 0x28, 0x7A, 1);
            var_a0_3 = 0x11;
            if (D_8010D2B1 != 0) {
                var_a0_3 = 0x12;
            }
            formatTextEntry(var_s0, "%s", lookupDataEntry(var_a0_3));
        }
        temp_v0_3 = *(D_80115090 + (gCurrentSaveSlot * 0xA0));
        D_80102EB0 = temp_v0_3;
        var_a0_4 = 0xA;
        if (temp_v0_3 != 0) {
            var_a0_4 = 9;
        }
        formatTextEntry(temp_s7, "%s", lookupDataEntry(var_a0_4));
        temp_v0_4 = *(D_8011508D + (gCurrentSaveSlot * 0xA0));
        D_801007C1 = temp_v0_4;
        var_a0_5 = 0xA;
        if (temp_v0_4 != 0) {
            var_a0_5 = 9;
        }
        formatTextEntry(sp34, "%s", lookupDataEntry(var_a0_5));
        temp_v0_5 = *(D_8011508C + (gCurrentSaveSlot * 0xA0));
        D_8010A394 = temp_v0_5;
        var_a0_6 = 0xA;
        if (temp_v0_5 != 0) {
            var_a0_6 = 9;
        }
        formatTextEntry(temp_fp, "%s", lookupDataEntry(var_a0_6));
        D_80108960 = *(D_8011508F + (gCurrentSaveSlot * 0xA0));
        temp_v1_2 = D_80100198[gCurrentSaveSlot].f0;
        if ((s32) temp_v1_2 >= 0) {
            var_a0_7 = temp_s6 - 0x28;
            if ((s32) temp_v1_2 >= 2) {
                if ((s32) temp_v1_2 < 6) {
                    if ((s32) temp_v1_2 >= 4) {
                        var_a0_7 = temp_s6 - 0x28;
                        goto block_32;
                    }
                    goto block_36;
                }
                goto block_35;
            }
block_32:
            { func_80025E9C(var_a0_7, temp_s6, temp_fp - 0x28, sp3C - 0x28, 1, 0xD); }
            if ((*(u8 *)((char *)(gMenuState) + 8)) == 0xD) {
                func_800274BC(0x100, 2);
            }
        } else {
            var_a0_7 = temp_s6 - 0x28;
block_35:
block_36:
            func_80025D84(var_a0_7, temp_s6, temp_fp - 0x28, sp3C - 0x28, 0x162, 1);
            var_a0_8 = 0xA;
            if (D_80108960 != 0) {
                var_a0_8 = 9;
            }
            formatTextEntry(temp_s6, "%s", lookupDataEntry(var_a0_8));
        }
        temp_v0_6 = *(D_8011508E + (gCurrentSaveSlot * 0xA0));
        D_80104310 = temp_v0_6;
        var_a0_9 = 0xA;
        if (temp_v0_6 != 0) {
            var_a0_9 = 9;
        }
        formatTextEntry(sp3C, "%s", lookupDataEntry(var_a0_9));
        if (gBorderSkipFlag != 0) {
            func_8002A644(gPickupSearchBox, D_80100408, 0x1A4, 8, 0x27, 0xB4, 0x4C, 0xE, 1, &func_80022C04, &func_8001AC88);
            gValidSaveSlotCount = countValidSaveSlots(0xA3);
            func_80022A30(gMenuListParam, 0x25, 0x48, 0x32, 0x76);
            var_s0_2 = 0;
            if (gSaveSlotCount > 0) {
                do {
                    temp_s1_3 = var_s0_2 & 0xFFFF;
                    temp_v0_7 = func_800162BC(gMenuListParam);
                    *((temp_s1_3 * 4) + D_80102F48) = temp_v0_7;
                    if (temp_v0_7 != 0) {
                        temp_s2_2 = lookupDataEntry((var_s0_2 + 0x400C) & 0xFFFF);
                        if (temp_s1_3 < 4U) {
                            var_a2 = lookupDataEntry(0xAD);
                            var_a3 = temp_s1_3 + 1;
                        
                        sprintf(temp_s2_2, "%s %d", var_a2, var_a3);} else {
                            var_a2 = lookupDataEntry(0x158);
                            var_a3 = temp_s1_3 - 3;
                        
                        sprintf(temp_s2_2, "%s %d", var_a2, var_a3);}
                        func_800160FC(*(((var_s0_2 & 0xFFFF) * 4) + D_80102F48), temp_s2_2, 0x40);
                    }
                    func_8002A7CC(gPickupSearchBox, *(((var_s0_2 & 0xFFFF) * 4) + D_80102F48), var_s0_2 & 0xFF, 1);
                    var_s0_2 += 1;
                } while ((var_s0_2 & 0xFFFF) < gSaveSlotCount);
            }
            func_80022E18(gMenuListParam);
            func_80022AD8(gMenuListParam);
            func_8002A9A8(gPickupSearchBox, gPickupSavedByte);
            func_8002AC04(gPickupSearchBox, 1);
        }
    }
}
