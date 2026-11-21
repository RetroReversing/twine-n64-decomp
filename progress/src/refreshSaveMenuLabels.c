s32 menuSetItemLabelIndices();
s32 func_80025E9C();
s32 formatTextEntry();
void *findEntryPayload();
s8 findTableIndexById();
s32 lookupDataEntry();
extern s16 D_800B5B28;
extern s8 gMenuNeedsRedraw;
extern char D_800BD8EC[];
extern char D_800D2A74[];
extern char sFmtEntryName[];
extern char D_800D2864[];
extern s16 gExpansionPakPresent;
extern void *gSaveMenuState;
extern u8 D_8010A4C0;
extern u8 gColorFadeLevel;
extern u8 gOptionFlagA;
extern u8 D_8010A4FF;

/* Redraws the save menu's label rows: finds the label entries, fills their text and option indices, and formats the status line. */
void refreshSaveMenuLabels(void) {
    s32 var_a0;
    s32 var_a0_4;
    void *temp_s0;
    void *temp_s1;
    void *temp_s2;
    void *temp_s4;
    void *temp_s5;
    void *var_s3;

    gMenuNeedsRedraw = 1;
    temp_s4 = findEntryPayload(D_800BD8EC, 0x1F);
    temp_s5 = findEntryPayload(D_800BD8EC, 0x20);
    temp_s1 = findEntryPayload(D_800BD8EC, 0x19);
    var_s3 = findEntryPayload(D_800BD8EC, 0x1C);
    D_800B5B28 = 1;
    if (var_s3 == (u32)NULL) {
        var_s3 = findEntryPayload(D_800BD8EC, 3);
    }
    if (((temp_s4 != NULL) & (temp_s5 != NULL)) && ((temp_s1 != NULL) & (var_s3 != NULL))) {
        (*(s32 *)((char *)(temp_s5) + 0x14)) = (s32) ((((gColorFadeLevel * (*(s32 *)((char *)(temp_s5) + 0x10))) + 2) << 0x10) | 8);
        formatTextEntry(temp_s1, sFmtEntryName, !gOptionFlagA ? lookupDataEntry(0x1A) : lookupDataEntry(0x1B));
        if (gExpansionPakPresent != 0) {
            temp_s2 = var_s3 - 0x28;
            temp_s0 = temp_s4 - 0x28;
            (*(s16 *)((char *)(var_s3) + -0x28)) = 3;
            func_80025E9C(temp_s2, var_s3, temp_s1 - 0x28, temp_s0, 1, 9);
            formatTextEntry(var_s3, D_800D2A74);
            menuSetItemLabelIndices(temp_s0, temp_s4, temp_s2, temp_s5 - 0x28, 0x1F, 1);
            temp_s2 = (*(void **)((char *)(gSaveMenuState) + 0x10));
            (*(s8 *)((char *)((*(void **)((char *)(gSaveMenuState) + 0x10))) + 4)) = findTableIndexById(temp_s2, 0x1F);
            goto updateLabel;
        }
        {
            (*(s16 *)((char *)(var_s3) + -0x28)) = 0x1C;
            menuSetItemLabelIndices(var_s3 - 0x28, var_s3, temp_s1 - 0x28, temp_s4 - 0x28, 0x1C, 1);
            var_a0 = 0x1B3;
            if (D_8010A4FF != 0) var_a0 = 0x1D;
            { formatTextEntry(var_s3, D_800D2864, lookupDataEntry(var_a0)); }
            func_80025E9C(temp_s4 - 0x28, temp_s4, var_s3 - 0x28, temp_s5 - 0x28, 1, 0xD);
            temp_s2 = (*(void **)((char *)(gSaveMenuState) + 0x10));
            (*(s8 *)((char *)((*(void **)((char *)(gSaveMenuState) + 0x10))) + 4)) = findTableIndexById(temp_s2, 0x20);
        }
updateLabel:
        if (D_8010A4C0 == 0) var_a0_4 = lookupDataEntry(0x16);
        else if (D_8010A4C0 == 1) var_a0_4 = lookupDataEntry(0x17);
        else var_a0_4 = lookupDataEntry(0x16);
        do { formatTextEntry(temp_s4, sFmtEntryName, var_a0_4); } while (0);
    }
}
