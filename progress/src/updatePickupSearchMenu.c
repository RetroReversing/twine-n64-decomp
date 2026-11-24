extern s32 formatTextEntry(s32, const char *, s32);
extern s32 resetObjectPool(s32 *);
extern s32 setMenuActiveState(s32 *, s32);
extern s32 func_8002ACB4(s32 *);
extern s32 lookupDataEntry(s32);
extern s32 refreshSaveSlotMenu(u8);
extern s32 selectItemAndUpdateAmount(s32 *, u8);
extern s32 updateActiveMenuState(void);
extern u8 gPickupSavedByte;
extern s32 gPickupSearchBox;
extern void *gSaveMenuState;
extern u8 sPickupSlotTable[];
extern const char D_800D2AA0[];

/* Refreshes the pickup search menu: writes the selected slot's name text and reselects the saved item. */ void updatePickupSearchMenu(void) {
    updateActiveMenuState();
    if (*((u8 *)gSaveMenuState + 0x2D)) {
        u8 *savedIndexPtr = &gPickupSavedByte;
        u32 savedIndex = *savedIndexPtr;
        s32 textBase = *(s32 *)((u8 *)gSaveMenuState + 0x18);
        u32 slot = sPickupSlotTable[savedIndex * 24];
        s32 textDest = textBase + 0x28;
        if (slot >= 8U) {
            slot = 7;
        }
        formatTextEntry(textDest, D_800D2AA0, lookupDataEntry((u16)(slot + 0x96)));
        resetObjectPool(&gPickupSearchBox);
        refreshSaveSlotMenu(slot);
        setMenuActiveState(&gPickupSearchBox, 1);
        selectItemAndUpdateAmount(&gPickupSearchBox, *savedIndexPtr);
        func_8002ACB4(&gPickupSearchBox);
    }
}
