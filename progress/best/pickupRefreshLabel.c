#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
s32 findEntryPayload(s32, s32);
void formatTextEntry(void *, s32, ...);
s32 func_8002A644(void *, s32, u16, s8, u16, s32, u8, u8, u8, s32, s32);
s32 func_8002AC04(void *, s32);
void *lookupDataEntry(s32);
void refreshSaveSlotMenu(void);
s32 selectItemAndUpdateAmount(void *, s16);
extern u8 gPickupSavedByte;
extern u32 sPickupSlotTable;
extern u16 gBorderSkipActive;
extern void *gSaveMenuState;
extern u8 gPickupSearchBox[36];
extern u8 D_80100408[420];
extern s32 bindMenuItemRecord;
extern s32 func_8001AC88;
void pickupRefreshLabel(void) {
    s32 temp_v1;
    u8 var_s1;
    void *temp_v0;

    temp_v0 = (void *)findEntryPayload(*(s32 *)(gSaveMenuState + 0x10), 0x7E);
    if (temp_v0 != NULL) {
        temp_v1 = gPickupSavedByte * 0x18;
        var_s1 = *(&((u8 *)&sPickupSlotTable)[temp_v1]);
        if (var_s1 >= 8U) {
            var_s1 = 7;
        }
        M2C_FIELD(temp_v0, void **, -0x18) = (void *) (temp_v1 + (&gPickupSavedByte - 0x115));
        formatTextEntry(temp_v0, 0x25, 0x73, 0);
        if (gBorderSkipActive != 0) {
            func_8002A644(gPickupSearchBox, (s32)D_80100408, 0x1A4, 4, 0x21, 0xB4, 0x4F, 0xB, 1, (s32)&bindMenuItemRecord, (s32)&func_8001AC88);
        }
        refreshSaveSlotMenu();
        if (gBorderSkipActive != 0) {
            selectItemAndUpdateAmount(gPickupSearchBox, gPickupSavedByte);
            func_8002AC04(gPickupSearchBox, 1);
        }
    }
}
