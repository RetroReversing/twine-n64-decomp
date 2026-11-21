extern s32 formatTextEntry(s32, const char *, s32);
extern s32 func_8002A700(s32 *);
extern s32 func_8002AC04(s32 *, s32);
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

void func_80022044(void) {
    updateActiveMenuState();
    if (*((u8 *)gSaveMenuState + 0x2D)) {
        u8 *saved = &gPickupSavedByte;
        u32 index = *saved;
        s32 base = *(s32 *)((u8 *)gSaveMenuState + 0x18);
        u32 slot = sPickupSlotTable[index * 24];
        s32 dest = base + 0x28;
        if (slot >= 8U) {
            slot = 7;
        }
        formatTextEntry(dest, D_800D2AA0, lookupDataEntry((u16)(slot + 0x96)));
        func_8002A700(&gPickupSearchBox);
        refreshSaveSlotMenu(slot);
        func_8002AC04(&gPickupSearchBox, 1);
        selectItemAndUpdateAmount(&gPickupSearchBox, *saved);
        func_8002ACB4(&gPickupSearchBox);
    }
}
