void *findEntryPayload(void *, s32);
s32 formatTextEntry(void *, void *, s32);
s32 lookupDataEntry(s32);
extern u8 sOptionScaleX;
extern u8 sOptionScaleY;
extern u8 gOptionChoice;
extern u8 gOptionFlag;
extern void *gSaveMenuState;
extern s8 gMenuAnyController;
extern void *gMenuEntryTable;
extern char sFmtEntryName[];

/* Refreshes the option menu labels and their positions when all the menu entries exist; the text depends on the current option choice and flag. */
void updateOptionMenuText(void) {
    s32 var_a0;
    s32 var_a0_2;
    void *optionLabel;
    void *scaleXEntry;
    void *scaleYEntry;
    void *flagEntry;

    gMenuAnyController = 1;
    optionLabel = findEntryPayload(&gMenuEntryTable, 0x24);
    scaleXEntry = findEntryPayload(&gMenuEntryTable, 0x22);
    scaleYEntry = findEntryPayload(&gMenuEntryTable, 0x23);
    flagEntry = findEntryPayload(*(void **)((s8 *)gSaveMenuState + 0x10), 0x199);
    if (((optionLabel != NULL) & (scaleXEntry != NULL)) && ((scaleYEntry != NULL) & (flagEntry != NULL))) {
        switch (gOptionChoice) {
        case 0:
            var_a0 = 0x25;
            formatTextEntry(optionLabel, sFmtEntryName, lookupDataEntry(var_a0));
            break;
        case 2:
            var_a0 = 0x27;
            formatTextEntry(optionLabel, sFmtEntryName, lookupDataEntry(var_a0));
            break;
        case 1:
            var_a0 = 0x26;
            formatTextEntry(optionLabel, sFmtEntryName, lookupDataEntry(var_a0));
            break;
        }
        *(s32 *)((s8 *)scaleXEntry + 0x14) = (s32)((((sOptionScaleX * *(s32 *)((s8 *)scaleXEntry + 0x10)) + 2) << 0x10) | 8);
        *(s32 *)((s8 *)scaleYEntry + 0x14) = (s32)((((sOptionScaleY * *(s32 *)((s8 *)scaleYEntry + 0x10)) + 2) << 0x10) | 8);
        var_a0_2 = 0xA;
        if (gOptionFlag != 0) {
            var_a0_2 = 9;
        }
        formatTextEntry(flagEntry, sFmtEntryName, lookupDataEntry(var_a0_2));
    }
}
