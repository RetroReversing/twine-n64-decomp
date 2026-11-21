s32 updateSaveMenuSprites(s32, u16, u8, s32);
s32 findSaveSlotByMode(u16);
s8 findTableIndexById(s32, s32);
s32 func_80026424(s32, s32);
s32 func_800274BC(s32, s32);
s32 updateActiveMenuState();
s32 selectItemAndUpdateAmount(s32 *, s32);
s32 func_8002CC14();
extern u16 sSaveMenuAction;
extern s8 sSaveMenuRefresh;
extern s32 sActiveMenu;
extern s32 D_80107EA8;
extern void *gSaveMenuState;

/* Per-frame save menu update: refreshes the sprites and the active menu state, and when a selection is confirmed (flag at 0x2C set, 0x2E clear) applies it and clears the flag. */
void updateSaveMenuFrame(void) {
    void *itemList;
    void *cursorInfo;

    *(u8 *)((s8 *)gSaveMenuState + 0x2C) = 0U;
    itemList = *(void **)((s8 *)gSaveMenuState + 0x18);
    sSaveMenuRefresh = 0;
    updateSaveMenuSprites(sSaveMenuAction, *(u16 *)((s8 *)itemList + 0x18), *(u8 *)((s8 *)itemList + 0x1B), 1);
    updateActiveMenuState();
    if ((*(u8 *)((s8 *)gSaveMenuState + 0x2C) != 0) && (*(u8 *)((s8 *)gSaveMenuState + 0x2E) == 0)) {
        if (func_8002CC14() & 0xFFFF) {
            func_80026424(sActiveMenu, 0x18);
        }
        cursorInfo = *(void **)((s8 *)gSaveMenuState + 0x18);
        updateSaveMenuSprites(*(s32 *)((s8 *)cursorInfo + 0x14), *(u16 *)((s8 *)cursorInfo + 0x18), *(u8 *)((s8 *)cursorInfo + 0x1B), 1);
        selectItemAndUpdateAmount(&D_80107EA8, findSaveSlotByMode(sSaveMenuAction) & 0xFF);
        *(s8 *)((s8 *)gSaveMenuState + 8) = findTableIndexById(*(s32 *)((s8 *)gSaveMenuState + 0x10), 3);
        *(u8 *)((s8 *)gSaveMenuState + 0x2C) = 0U;
        func_800274BC(0x101, 0xFF);
    }
}
