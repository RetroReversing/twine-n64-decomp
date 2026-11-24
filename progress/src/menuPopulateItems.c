s32 initTextWidget();
s32 spawnTrackMarker();
s32 getTextLength();
s32 setCursorMarker();
s32 updateTrackMarker();
s32 formatTextEntry();
s32 findEntryById();
s32 initMenuWindow();
s32 appendWeightedListEntry();
s32 selectItemAndUpdateAmount();
s32 setMenuActiveState();
s32 drawMenuList();
void *lookupDataEntry();
s32 sprintf();
extern s16 gMenuMode;
extern s32 *gMenuList;
extern s16 D_800B60E8;
extern u8 sMenuListKind;
extern u8 gMenuSlot;
extern char D_800BDBD0[];
extern char D_800CE92C[];
extern char D_800CE984[];
extern char gSaveMenuRows[];
extern char D_800E0C98[];
extern char D_800E0E40[];
extern char sBonusSlotValueB[];
extern u8 sDifficultyLevel;
extern s32 updateMenuItemRecord;
extern s32 releaseMenuItemRecord;
extern char D_800D2A80[];

/* Sets up the menu list at gSaveMenuRows and fills one text entry per item in the table for the current mode. */
void menuPopulateItems(void) {
    s32 *itemTable;
    void *itemText;
    s32 itemIndex;
    register s32 textHandle;
    unsigned long slotHandle;
    s32 itemCounter;
    s32 *slotPtr;
    u32 itemCount;

    gMenuMode = 3;
    gMenuList = gSaveMenuRows;
    initMenuWindow(gSaveMenuRows, D_800E0C98, 0x1A4, 0xB, 0x2D, 0xB4, 0x4C, 0xB, 0, &updateMenuItemRecord, &releaseMenuItemRecord);
    D_800B60E8 = 0;
    textHandle = findEntryById(D_800BDBD0, 0x4000);
    if (textHandle) {
        { setCursorMarker(sMenuListKind, 0x2D, 0x46, 0xDC, 0x7F); }
        itemTable = NULL;
        formatTextEntry(textHandle, "%s", lookupDataEntry(*(u16 *)(sBonusSlotValueB + (gMenuSlot * 2)) | 0x7000));
        itemCount = 0;
        switch (sDifficultyLevel) {                       /* irregular */
        case 0:
            itemTable = D_800CE92C;
            itemCount = 5;
            break;
        case 1:
            itemTable = D_800CE984;
            itemCount = 6;
            break;
        case 2:
            itemTable = D_800CE984;
            itemCount = 6;
            break;
        }
        itemCounter = 0;
        if (itemCount) {
            do {
                slotHandle = spawnTrackMarker(sMenuListKind);
                itemIndex = itemCounter & 0xFFFF;
                slotPtr = (itemIndex * 4) + D_800E0E40;
                *slotPtr = slotHandle;
                if (slotHandle != 0) {
                    itemText = lookupDataEntry((itemCounter + 0x4002) & 0xFFFF);
                    (*(s8 *)((char *)(itemText) + 0)) = 3;
                    (*(s8 *)((char *)(itemText) + 1)) = 0x6E;
                    sprintf(itemText + 2, D_800D2A80, lookupDataEntry((*(u16 *)((char *)itemTable + itemIndex * 8 + 6))));
                    initTextWidget(*slotPtr, itemText, 0x40);
                    appendWeightedListEntry(gMenuList, *slotPtr, itemCounter & 0xFF, getTextLength(*slotPtr) & 0xFF);
                }
                ++itemCounter;
            } while ((u32) (itemCounter & 0xFFFF) < itemCount);
        }
        updateTrackMarker(sMenuListKind);
        selectItemAndUpdateAmount(gMenuList, 0);
        setMenuActiveState(gMenuList, 1);
        drawMenuList(gMenuList);
    }
}
