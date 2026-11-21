extern u8 sPickupSlotTable[];
extern u8 gPickupSavedByte;
extern void *gSaveMenuState;
extern u8 gPickupSearchBox[];
extern const char D_800D2AA0[];
void updateActiveMenuState(void);
void formatTextEntry(void *, const char *, ...);
s32 lookupDataEntry(u16);
void refreshSaveSlotMenu(u8);
void func_8002A700(void *);
void func_8002AC04(void *, s32);
void selectItemAndUpdateAmount(void *, u8);
void func_8002ACB4(void *);

void func_80022044(void) {
    u8 slot;
    void *entry;

    updateActiveMenuState();
    if (*((u8 *)gSaveMenuState + 0x2D)) {
        u8 *saved = &gPickupSavedByte;
        void *box;
        slot = sPickupSlotTable[*saved * 24];
        entry = *(u8 **)((u8 *)gSaveMenuState + 0x18) + 0x28;
        if (slot >= 8U) {
            slot = 7;
        }
        formatTextEntry(entry, D_800D2AA0, lookupDataEntry(slot + 0x96));
        box = gPickupSearchBox;
        func_8002A700(box);
        refreshSaveSlotMenu(slot);
        func_8002AC04(box, 1);
        selectItemAndUpdateAmount(box, *saved);
        func_8002ACB4(box);
    }
}
