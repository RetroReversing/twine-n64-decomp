s32 menuSetItemLabelIndices();
s32 setupMenuItemPair();
s32 formatTextEntry();
void *findEntryPayload();
s8 findTableIndexById();
s32 lookupDataEntry();
extern s16 D_800B5B28;
extern s8 gMenuAnyController;
extern char D_800BD8EC[];
extern char D_800D2A74[];
extern char sFmtEntryName[];
extern char D_800D2864[];
extern s16 gExpansionPakPresent;
extern void *gSaveMenuState;
extern u8 gExpansionModeEnabled;
extern u8 gColorFadeLevel;
extern u8 gOptionFlagA;
extern u8 D_8010A4FF;

/* Redraws the save menu's label rows: finds the label entries, fills their text and option indices, and formats the status line. */
void refreshSaveMenuLabels(void) {
    s32 labelTextId;
    s32 statusTextId;
    void *slotNameEntry;
    void *slotDataEntry;
    void *statusEntry;
    void *fadeEntry;
    void *hintEntry;
    void *labelEntry;

    gMenuAnyController = 1;
    fadeEntry = findEntryPayload(D_800BD8EC, 0x1F);
    slotDataEntry = findEntryPayload(D_800BD8EC, 0x20);
    statusEntry = findEntryPayload(D_800BD8EC, 0x19);
    labelEntry = findEntryPayload(D_800BD8EC, 0x1C);
    D_800B5B28 = 1;
    if (labelEntry == (u32)NULL) {
        labelEntry = findEntryPayload(D_800BD8EC, 3);
    }
    if (((fadeEntry != NULL) & (slotDataEntry != NULL)) && ((statusEntry != NULL) & (labelEntry != NULL))) {
        (*(s32 *)((char *)(slotDataEntry) + 0x14)) = (s32) ((((gColorFadeLevel * (*(s32 *)((char *)(slotDataEntry) + 0x10))) + 2) << 0x10) | 8);
        formatTextEntry(statusEntry, sFmtEntryName, !gOptionFlagA ? lookupDataEntry(0x1A) : lookupDataEntry(0x1B));
        if (gExpansionPakPresent != 0) {
            hintEntry = labelEntry - 0x28;
            slotNameEntry = fadeEntry - 0x28;
            (*(s16 *)((char *)(labelEntry) + -0x28)) = 3;
            setupMenuItemPair(hintEntry, labelEntry, statusEntry - 0x28, slotNameEntry, 1, 9);
            formatTextEntry(labelEntry, D_800D2A74);
            menuSetItemLabelIndices(slotNameEntry, fadeEntry, hintEntry, slotDataEntry - 0x28, 0x1F, 1);
            hintEntry = (*(void **)((char *)(gSaveMenuState) + 0x10));
            (*(s8 *)((char *)((*(void **)((char *)(gSaveMenuState) + 0x10))) + 4)) = findTableIndexById(hintEntry, 0x1F);
            goto updateLabel;
        }
        {
            (*(s16 *)((char *)(labelEntry) + -0x28)) = 0x1C;
            menuSetItemLabelIndices(labelEntry - 0x28, labelEntry, statusEntry - 0x28, fadeEntry - 0x28, 0x1C, 1);
            labelTextId = 0x1B3;
            if (D_8010A4FF != 0) labelTextId = 0x1D;
            { formatTextEntry(labelEntry, D_800D2864, lookupDataEntry(labelTextId)); }
            setupMenuItemPair(fadeEntry - 0x28, fadeEntry, labelEntry - 0x28, slotDataEntry - 0x28, 1, 0xD);
            hintEntry = (*(void **)((char *)(gSaveMenuState) + 0x10));
            (*(s8 *)((char *)((*(void **)((char *)(gSaveMenuState) + 0x10))) + 4)) = findTableIndexById(hintEntry, 0x20);
        }
updateLabel:
        if (gExpansionModeEnabled == 0) statusTextId = lookupDataEntry(0x16);
        else if (gExpansionModeEnabled == 1) statusTextId = lookupDataEntry(0x17);
        else statusTextId = lookupDataEntry(0x16);
        do { formatTextEntry(fadeEntry, sFmtEntryName, statusTextId); } while (0);
    }
}
