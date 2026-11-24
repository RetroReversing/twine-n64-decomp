/* Refreshes the menu list for the current slot: resets the list, loads entries and graphics, and updates the selection state. */
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

M2C_UNK initTextWidget(s32, s32, M2C_UNK);           /* extern */
s32 func_800162BC(u8);                              /* extern */
s32 getTextLength(s32);                             /* extern */
s16 makeMenuEntryId(M2C_UNK, u8);                     /* extern */
M2C_UNK func_8002135C(s16, s16);                    /* extern */
M2C_UNK setCursorMarker(u8, M2C_UNK, M2C_UNK, M2C_UNK, s32); /* extern */
M2C_UNK updateTrackMarker(u8);                          /* extern */
M2C_UNK showTextPopup(u8);                          /* extern */
void *func_800262A8(s32, M2C_UNK);                  /* extern */
void *func_8002638C(s32, M2C_UNK);                  /* extern */
M2C_UNK initMenuWindow(M2C_UNK *, M2C_UNK *, M2C_UNK, M2C_UNK, s32, s32, s32, s32, s32, M2C_UNK *, M2C_UNK *); /* extern */
M2C_UNK appendWeightedListEntry(M2C_UNK *, s32, s32, s32);    /* extern */
void *func_8002A9A8(M2C_UNK *, s16);                /* extern */
M2C_UNK setMenuActiveState(M2C_UNK *, M2C_UNK);          /* extern */
s32 func_80087100(s32);                             /* extern */
extern s16 D_800B60E2;
extern M2C_UNK *D_800B60E4;
extern u8 D_800BD68E;
extern u8 D_800BD68F;
extern M2C_UNK D_800C469E;
extern M2C_UNK D_800C46D8;
extern M2C_UNK D_800C46DA;
extern M2C_UNK sBonusSlotValueA;
extern M2C_UNK D_801003E0;
extern M2C_UNK D_801093A8;
extern void *D_80109BB0;
extern M2C_UNK D_80109D28;
extern M2C_UNK D_8010A500;
extern M2C_UNK styleMenuItemText;
extern M2C_UNK releaseMenuItemRecord;

/* Refreshes the menu list for the current slot: resets the list, loads entries and graphics, and updates the selection state. */ void menuRefreshSlot(void) {
    char *__repair_addr;
    s16 listPosition;
    union { s32 * pointer; s32 value; } __repair_phase_storage;
    s32 slotEntries;
    s32 temp_v0_2;
    u16 entryId;
    s32 entryIndex;
    s8 var_v0;
    u16 *temp_a1;
    u16 *temp_v1;
    u16 temp_a0;
    void *temp_s0_2;
    void *temp_s1;
    void *slotData;
    void *selectedItem;

    D_800B60E4 = &D_801003E0;
    (*(u16 *)&D_800B60E2) = 0;
    initMenuWindow(&D_801003E0, &D_801093A8, 0x1D4, 6, 0x22, 0xB4, 0x46, 0xD, 1, &styleMenuItemText, &releaseMenuItemRecord);
    slotData = *((M2C_UNK *)((s8 *)&D_8010A500 + (D_800BD68F * 4)));
    selectedItem = NULL;
    if (slotData != NULL) {
        slotEntries = M2C_FIELD(slotData, s32 *, 0x6C);
        if (slotEntries != 0) {
            setCursorMarker(D_800BD68E, 0x20, 0x42, 0x72, 0x50);
            temp_v1 = (void *)((D_800BD68F * 2)); temp_v1 = (void *)((char *)temp_v1 + (s32)(&sBonusSlotValueA));
            if ((u16) *temp_v1 >= 0x28U) {
                *temp_v1 = 0;
            }
            temp_a1 = (void *)((D_800BD68F * 2)); temp_a1 = (void *)((char *)temp_a1 + (s32)(&sBonusSlotValueA));
            temp_a0 = *((u16 *)((s8 *)&D_800C469E + (*temp_a1 * 0xE8)));
            if ((temp_a0 & 0xFFFF) != 0x21) {
                *temp_a1 = temp_a0;
            }
            entryIndex = 0;
            listPosition = 0;
            do {
                entryId = entryIndex & 0xFFFF;
__repair_addr = (char *)((slotEntries + (entryId * 8)));

                if (((M2C_FIELD(__repair_addr, u8 *, 0x1FC) != 0) | (entryId == 0)) != 0) {
                    temp_v0_2 = func_800162BC(D_800BD68E);
                    __repair_phase_storage.pointer = entryId + &D_80109D28;
                    *__repair_phase_storage.pointer = temp_v0_2;
                    if (temp_v0_2 != 0) {
                        initTextWidget(*__repair_phase_storage.pointer, func_80087100((entryIndex | 0x6000) & 0xFFFF), 0x40);
                        appendWeightedListEntry(D_800B60E4, *__repair_phase_storage.pointer, entryIndex & 0xFF, getTextLength(*__repair_phase_storage.pointer) & 0xFF);
                    }
                    if (entryId == *((u16 *)&sBonusSlotValueA + D_800BD68F)) {
                        selectedItem = func_8002A9A8(D_800B60E4, listPosition);
                    }
                    listPosition += 1;
                }
                entryIndex += 1;
            } while ((u32) (entryIndex & 0xFFFF) < 0x25U);
            if (selectedItem != NULL) {
                s32 offset;
                temp_s1 = func_8002638C(M2C_FIELD(D_80109BB0, s32 *, 0x10), 0x62);
                temp_s0_2 = func_800262A8(M2C_FIELD(D_80109BB0, s32 *, 0x10), 0x1E);
                offset = M2C_FIELD(selectedItem, u8 *, 8) * 0xE8;
                func_8002135C(*((s16 *)((s8 *)&D_800C46D8 + offset)), *((s16 *)((s8 *)&D_800C46DA + offset)));
                if (temp_s1 != NULL) {
                    M2C_FIELD(temp_s1, s16 *, 0) = makeMenuEntryId(0, M2C_FIELD(selectedItem, u8 *, 8));
                    M2C_FIELD(temp_s1, u16 *, 0x28) = makeMenuEntryId(1, M2C_FIELD(selectedItem, u8 *, 8));
                }
                if (temp_s0_2 != NULL) {
                    if (M2C_FIELD(selectedItem, u8 *, 8) == 0x24) {
                        M2C_FIELD(temp_s0_2, u8 *, 0x1C) = 0x80;
                    } else {
                        M2C_FIELD(temp_s0_2, u8 *, 0x1C) = 0x90;
                    }
                }
                M2C_FIELD(D_80109BB0, u8 *, 0x30) = 0xFF;
            }
            showTextPopup(D_800BD68E);
            updateTrackMarker(D_800BD68E);
            setMenuActiveState(D_800B60E4, 1);
        }
    }
}
