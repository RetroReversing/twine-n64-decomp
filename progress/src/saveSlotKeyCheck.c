extern struct { s32 value; char pad[20]; } gSaveSlotInfo[];
extern u8 sSaveSlotTable[];
extern u8 gSaveKeyRelaxed;
extern s32 gSaveSlotCount, gSaveExtraSlotCount;
u8 getKeyEntryFlag(s32);

// Returns 0x159 if slot 'slot' can be used, or 0x15a if its key clashes with another slot's key or fails the getKeyEntryFlag check.
/* Returns 0x159 if the slot's key is unique and valid, or 0x15a if it clashes with another slot's key. */ s32 saveSlotKeyCheck(s32 slotIndex) {
    u16 i = 0;
    s32 slotCount;
    s32 slotKey;
    s32 slotOffset = (u16)slotIndex * 24;
    slotCount = gSaveSlotCount;
    slotKey = *(s32 *)((s8 *)gSaveSlotInfo + slotOffset);
    for (i = 0; i < slotCount; i++) {
        if (i != (u16)slotIndex && gSaveSlotInfo[i].value == slotKey) return 0x15a;
    }
    for (i = 4; i < gSaveExtraSlotCount + 4; i++) {
        if (i != (u16)slotIndex && gSaveSlotInfo[i].value == slotKey) return 0x15a;
    }
    if (gSaveKeyRelaxed) {
        if (getKeyEntryFlag(slotKey) & 0xff) goto __shared_return_345;
        if (!sSaveSlotTable[(u16)slotIndex * 24]) return 0x15a;
        goto __shared_return_345;
    }
    if ((getKeyEntryFlag(slotKey) & 0xff)) goto __shared_return_345;
    for (i = 0; i < gSaveSlotCount; i++) {
        if (i != (u16)slotIndex && !getKeyEntryFlag(gSaveSlotInfo[i].value)) return 0x15a;
    }
    for (i = 4; gSaveExtraSlotCount + 4 > i; i++) {
        if (i != (u16)slotIndex && !getKeyEntryFlag(gSaveSlotInfo[i].value)) return 0x15a;
    }
    __shared_return_345:
    return 0x159;
}
