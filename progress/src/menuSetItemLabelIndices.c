typedef struct { u8 pad_0[16]; s32 labelTable; u8 pad_14[4]; s32 selectedItemId; } MenuItemsState;
extern MenuItemsState *gMenuItems;
s8 func_800263B8(s32, s32);
void func_80025F78(s32, s32);

/* Sets the label-table indices of two menu item records for labelId; altLabel selects the second byte pair. */
void menuSetItemLabelIndices(s32 itemId, s32 otherItemId, void *itemA, void *itemB, u16 labelId, u16 altLabel) {
    s32 labelIndex;

    func_80025F78(itemId, 0);
    func_80025F78(otherItemId, 0);
    if (itemId == gMenuItems->selectedItemId) {
        func_80025F78(itemId, 9);
    }
    if (((itemId != 0) & (itemA != NULL)) && (itemB != NULL)) {
        labelIndex = labelId & 0xFFFF;
        if (altLabel != 0) {
            *(s8 *)((s8 *)itemA + 0x27) = func_800263B8(gMenuItems->labelTable, labelIndex);
            *(s8 *)((s8 *)itemB + 0x26) = func_800263B8(gMenuItems->labelTable, labelIndex);
            return;
        }
        *(s8 *)((s8 *)itemA + 0x25) = func_800263B8(gMenuItems->labelTable, labelIndex);
        *(s8 *)((s8 *)itemB + 0x24) = func_800263B8(gMenuItems->labelTable, labelIndex);
    }
}
