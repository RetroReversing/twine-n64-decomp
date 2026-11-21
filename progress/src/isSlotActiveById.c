extern u8 sDataBankInitialised;
extern u8 sDataBankFlags;
extern s32 sDataBankSlots;

static inline s32 find_active_slot(s32 id) {
    u32 i = 0;
    s32 offset = 0;

    for (; i < 2; i++, offset += 0x1228) {
        if (*(u8 *)((u8 *)&sDataBankFlags + offset) != 0 &&
            *(s32 *)((u8 *)&sDataBankSlots + offset) == id) {
            return i;
        }
    }
    return -1;
}

s32 isSlotActiveById(s32 id) {
    s32 offset;
    if (sDataBankInitialised != 0) {
        register s32 key = id;
        id = 0;
        offset = 0;
        do {
            if (*(u8 *)((u8 *)&sDataBankFlags + offset) != 0 &&
                *(s32 *)((u8 *)&sDataBankSlots + offset) == key) {
                goto found;
            }
            id++;
            offset += 0x1228;
        } while ((u32)id < 2);
        id = -1;
found:
        key = id;
        if (key != -1) {
            return *(u8 *)((u8 *)&sDataBankFlags + key * 0x1228) != 0;
        }
    }
    return 0;
}
