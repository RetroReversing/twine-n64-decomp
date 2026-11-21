void *findEntryPayload(s32, s32);
s32 formatTextEntry(void *, void *, s32);
s32 func_8002A644(void *, void *, s32, s32, s32, s32, s32, s32, s32, void *, void *);
s32 func_8002AC04(void *, s32);
s32 lookupDataEntry(s32);
s32 refreshSaveSlotMenu(u8);
s32 selectItemAndUpdateAmount(void *, u8);
extern const char D_800D2A80[];
extern s32 D_80100408;
extern s32 bindMenuItemRecord;
extern s32 func_8001AC88;
extern s32 gBorderSkipActive;
extern u8 gPickupSavedByte;
extern s32 gPickupSearchBox;
extern void *gSaveMenuState;
extern s32 sPickupSlotTable;

/* Refreshes the pickup label: formats the saved pickup's text and, when border skip is active, rebinds the search box. */
void pickupRefreshLabel(void) {
    s32 entryOffset;
    u32 pickupLevel;
    void *label;

    label = findEntryPayload(*(s32 *)((s8 *)gSaveMenuState + 0x10), 0x7E);
    if (label != NULL) {
        u8 *saved = &gPickupSavedByte;
        entryOffset = *saved * 0x18;
        pickupLevel = *((u8 *)&sPickupSlotTable + entryOffset);
        if (pickupLevel >= 8U) {
            pickupLevel = 7;
        }
        *(void **)((s8 *)label - 0x18) = (void *) (entryOffset + (&gPickupSavedByte - 0x115));
        formatTextEntry(label, (void *)D_800D2A80, lookupDataEntry((u16)(pickupLevel + 0x96)));
        {
            s32 *borderSkip = &gBorderSkipActive;
            if (*borderSkip != 0) {
                func_8002A644(&gPickupSearchBox, &D_80100408, 0x1A4, 4, 0x21, 0xB4, 0x4F, 0xB, 1, &bindMenuItemRecord, &func_8001AC88);
            }
            refreshSaveSlotMenu(pickupLevel);
            if (*borderSkip != 0) {
                selectItemAndUpdateAmount(&gPickupSearchBox, *saved);
                func_8002AC04(&gPickupSearchBox, 1);
            }
        }
    }
}
