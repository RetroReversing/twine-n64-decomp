s32 func_800160FC();
s32 func_800162BC();
s32 func_80018318();
s32 func_80022A30();
s32 func_80022AD8();
s32 formatTextEntry();
s32 findEntryById();
s32 func_8002A644();
s32 func_8002A7CC();
s32 func_8002A9A8();
s32 func_8002AC04();
s32 func_8002ACB4();
void *lookupDataEntry();
s32 sprintf();
extern s16 gMenuMode;
extern s32 *gMenuList;
extern s16 D_800B60E8;
extern u8 gMenuListParam;
extern u8 gMenuSlot;
extern char D_800BDBD0[];
extern char D_800CE92C[];
extern char D_800CE984[];
extern char D_800E0C70[];
extern char D_800E0C98[];
extern char D_800E0E40[];
extern char D_800E0ED4[];
extern u8 D_80102EE8;
extern s32 func_8001EA6C;
extern s32 func_8001EAF0;
extern char D_800D2A80[];

/* Sets up the menu list at D_800E0C70 and fills one text entry per item in the table for the current mode. */
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
    gMenuList = D_800E0C70;
    func_8002A644(D_800E0C70, D_800E0C98, 0x1A4, 0xB, 0x2D, 0xB4, 0x4C, 0xB, 0, &func_8001EA6C, &func_8001EAF0);
    D_800B60E8 = 0;
    textHandle = findEntryById(D_800BDBD0, 0x4000);
    if (textHandle) {
        { func_80022A30(gMenuListParam, 0x2D, 0x46, 0xDC, 0x7F); }
        itemTable = NULL;
        formatTextEntry(textHandle, "%s", lookupDataEntry(*(u16 *)(D_800E0ED4 + (gMenuSlot * 2)) | 0x7000));
        itemCount = 0;
        switch (D_80102EE8) {                       /* irregular */
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
                slotHandle = func_800162BC(gMenuListParam);
                itemIndex = itemCounter & 0xFFFF;
                slotPtr = (itemIndex * 4) + D_800E0E40;
                *slotPtr = slotHandle;
                if (slotHandle != 0) {
                    itemText = lookupDataEntry((itemCounter + 0x4002) & 0xFFFF);
                    (*(s8 *)((char *)(itemText) + 0)) = 3;
                    (*(s8 *)((char *)(itemText) + 1)) = 0x6E;
                    sprintf(itemText + 2, D_800D2A80, lookupDataEntry((*(u16 *)((char *)itemTable + itemIndex * 8 + 6))));
                    func_800160FC(*slotPtr, itemText, 0x40);
                    func_8002A7CC(gMenuList, *slotPtr, itemCounter & 0xFF, func_80018318(*slotPtr) & 0xFF);
                }
                ++itemCounter;
            } while ((u32) (itemCounter & 0xFFFF) < itemCount);
        }
        func_80022AD8(gMenuListParam);
        func_8002A9A8(gMenuList, 0);
        func_8002AC04(gMenuList, 1);
        func_8002ACB4(gMenuList);
    }
}
