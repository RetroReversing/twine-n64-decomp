/* Opens the pickup search menu: points the menu entry at the saved slot record, then shows the search box. */
#ifndef M2C_DEFINES
#define M2C_DEFINES
typedef s32 M2C_UNK;
typedef s8 M2C_UNK8;
typedef s16 M2C_UNK16;
typedef s32 M2C_UNK32;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define M2C_CARRY 0
#define M2C_OVERFLOW(a) (0)
#endif

s32 refreshSaveSlotMenu();
s32 formatTextEntry();
void *findEntryPayload();
s32 func_8002A644();
s32 func_8002A9A8();
s32 func_8002AC04();
s32 lookupDataEntry();
extern s8 D_800BD690;
extern char D_800BD928[];
extern char sPickupSlotTable[];
extern u8 gPickupSavedByte;
extern char D_80100408[];
extern char gPickupSearchBox[];
extern s32 func_8001AC88;
extern s32 bindMenuItemRecord;

extern char sFmtEntryName[];
void openPickupSearchMenu(void) {
    u8 *savedByte;
    u8 *slotTableBase;
    s32 slotOffset;
    u8 slotLevel;
    void *menuEntry;

    D_800BD690 = 1;
    menuEntry = findEntryPayload(D_800BD928, 0x7E);
    if (menuEntry != NULL) {
        savedByte = &gPickupSavedByte;
        slotOffset = (*savedByte) * 0x18;
        slotLevel = *(sPickupSlotTable + slotOffset);
        if (slotLevel >= 8U) {
            slotLevel = 7;
        }
        slotTableBase = savedByte - 0x115;
        M2C_FIELD(menuEntry, void **, -0x18) = (void *) (slotOffset + slotTableBase);
        formatTextEntry(menuEntry, sFmtEntryName, lookupDataEntry((unsigned short)(slotLevel + 0x96)));
        func_8002A644(gPickupSearchBox, D_80100408, 0x1A4, 0xB, 0x1E, 0xB4, 0x34, 0xB, 1, &bindMenuItemRecord, &func_8001AC88);
        refreshSaveSlotMenu(slotLevel);
        func_8002A9A8(gPickupSearchBox, (*savedByte));
        func_8002AC04(gPickupSearchBox, 1);
    }
}
