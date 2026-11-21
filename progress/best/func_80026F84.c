void copyStateTablesToRam();
u16 countValidSaveSlots(u16);
void func_8002D240();
s32 func_80081828(s32);
extern s32 sSaveMenuFlagsB, D_800BD64C, D_800BD664;
extern u8 sMenuListKind, gMenuSlot, D_800BD690[];
extern s8 gMenuParamB;
extern s32 D_800BD8C4;
extern u8 D_800E109F, D_800E10A0, D_800E10A1, D_800E10A2, D_800E10A3, D_800E10A4;
extern s8 D_800BF598, D_800E109C, D_800E109D, D_800E109E, D_801002AE, D_801002E6, D_801002E7, D_801002E8, D_801002E9, gValidSaveSlotCount, D_80102ED4, D_80102F04;
extern s32 gMenuSoundParams, D_80102EC0, sMenuDefaultSoundParams, gBorderSkipActive;
extern u8 gMenuUseTextList;
extern u8 *gMenuItems;
extern s32 gBonusObjects[];

void func_80026F84(u8 arg0) {
    u8 v;
    s32 slot;

    if (D_800BF598 != 0) {
        D_800E109F = 0xFF; D_800E10A0 = 0xFF; D_800E10A1 = 0xFF; D_800E10A2 = 0xFF; D_800E10A3 = 0xFF; D_800E10A4 = 0xFF;
        D_80102F04 = 0; D_800BF598 = 0; gMenuSlot = 0;
        D_800E109E = 0; D_800E109D = 0; D_800E109C = 0;
        D_801002E6 = -1; D_801002E7 = -1; D_801002E8 = -1; D_801002E9 = -1;
        gMenuItems = NULL;
        func_8002D240();
        copyStateTablesToRam();
    }
    gValidSaveSlotCount = countValidSaveSlots(0xA3);
    D_80102ED4 = 1;
    slot = arg0;
    if (gMenuItems != NULL) {
        gMenuItems[7] = 0;
        gMenuItems[0x2F] = 0;
        *(s32 *)(gMenuItems + 0x20) = 0;
        *(s32 *)(gMenuItems + 0x24) = 0;
        *(u16 *)(gMenuItems + 0x14) = 0;
        *(u16 *)(gMenuItems + 0x16) = 0;
        gMenuItems[0x28] = 0;
        *(s32 *)gMenuItems = 0;
        gMenuItems[0x29] = 0;
        gMenuItems[0x2C] = 0;
        *(u16 *)(gMenuItems + 0x2A) = 0x1D;
        gMenuItems[0x2D] = 0;
        *(s32 *)(gMenuItems + 0x1C) = 0;
        *(s32 *)(gMenuItems + 0x10) = 0;
        *(s32 **)(gMenuItems + 0xC) = &D_800BD8C4;
        slot = arg0;
    }
    D_801002AE = 0;
    D_800BD690[0] = 1;
    if (gBonusObjects[slot] != 0) gMenuSlot = arg0;
    else gMenuSlot = 0;
    gMenuParamB = func_80081828(gMenuSlot);
    if (gMenuUseTextList != 0) {
        v = 4;
        if (gBorderSkipActive == 0) {}
    } else {
        v = gMenuSlot;
    }
    sMenuListKind = v;
    D_80102EC0 = D_800BD664;
    gMenuSoundParams = D_800BD64C;
    sMenuDefaultSoundParams = sSaveMenuFlagsB;
}
