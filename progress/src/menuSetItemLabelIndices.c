s8 findTableIndexById(s32, s32);
s32 func_80025F78(s32, s32);
extern void *gSaveMenuState;

/* Resets the highlight state of two menu items, then stores the table index for the given id into one or both label records. */
void menuSetItemLabelIndices(s32 itemA, s32 itemB, void *labelA, void *labelB, u16 itemId, u16 useAltSlot) {
    s32 key;

    func_80025F78(itemA, 0);
    func_80025F78(itemB, 0);
    if (itemA == *(s32 *)((s8 *)gSaveMenuState + 0x18)) {
        func_80025F78(itemA, 9);
    }
    if (((itemA != 0) & (labelA != NULL)) && labelB != NULL) {
        key = itemId & 0xFFFF;
        if (useAltSlot != 0) {
            *(s8 *)((s8 *)labelA + 0x27) = findTableIndexById(*(s32 *)((s8 *)gSaveMenuState + 0x10), key);
            *(s8 *)((s8 *)labelB + 0x26) = findTableIndexById(*(s32 *)((s8 *)gSaveMenuState + 0x10), key);
            return;
        }
        *(s8 *)((s8 *)labelA + 0x25) = findTableIndexById(*(s32 *)((s8 *)gSaveMenuState + 0x10), key);
        *(s8 *)((s8 *)labelB + 0x24) = findTableIndexById(*(s32 *)((s8 *)gSaveMenuState + 0x10), key);
    }
}
