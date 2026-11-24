extern u8 sDataBankInitialised, sDataBankFlags[];
extern char sDataBankSlots[];
s32 isSlotActiveById(s32 i) {
    s32 key = i;
    s32 offset;
    if (sDataBankInitialised) {
        i = 0;
        offset = 0;
        do {
            if (sDataBankFlags[offset] && *(s32 *)(sDataBankSlots + offset) == key) goto found;
            offset += 0x1228;
        } while ((u32)++i < 2);
        i = -1;
found:
        key = i;
        if (key != -1) return sDataBankFlags[key * 0x1228] != 0;
    }
    return 0;
}
extern s32 formatTextEntry(s32, s32 *, s32);
extern s32 updateActiveMenuState();
extern s32 lookupDataEntry(s32);
extern void *gSaveMenuState;
extern u8 gBorderFlipFlag;
void updateMenuToggleLabel(void) {
    s32 id;
    updateActiveMenuState();
    if (*((u8 *)gSaveMenuState + 0x2D) != 0) {
        id = 0x67;
        if (gBorderFlipFlag != 0) id = 0x68;
        formatTextEntry(*(s32 *)((u8 *)gSaveMenuState + 0x18) + 0x28, "%s", lookupDataEntry(id));
    }
}
extern s32 gSoundRequestQueue[];
extern s32 gSoundRequestWriteIndex;
/* Pushes a sound id into a 16-entry ring buffer, skipping slots that are already occupied (-1 marks an empty slot). */ void enqueueSoundRequest(s32 soundId) {
    u32 writeIndex;
    s32 *queue;
    s32 triesLeft;
    if (soundId != -1) {
        writeIndex = gSoundRequestWriteIndex;
        triesLeft = 15;
        queue = gSoundRequestQueue;
        do {
            s32 entry = queue[writeIndex];
            if (entry == -1) break;
            entry = writeIndex + 1;
            writeIndex = entry & 15;
        } while (triesLeft--);
        queue[writeIndex] = soundId;
        gSoundRequestWriteIndex = (writeIndex + 1) & 15;
    }
}
