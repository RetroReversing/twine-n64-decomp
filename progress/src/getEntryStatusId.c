typedef struct { u16 a; u16 flags; u32 b; } Ent30C7C;
extern u32 gEntryMode;
extern Ent30C7C *gEntryTable;
extern u16 gEntryCount;
extern u16 gEntryLevelLimit;

/* Picks a status id: fixed ids for modes 7/4/9, otherwise the first unlocked table entry (within the level limit) decides between 0x9F, 0x9E, or the default 0xA0. */ s32 getEntryStatusId(void) {
    u16 index;

    switch (gEntryMode) {
    case 7:
        return 0x76;
    case 4:
        return 0x9F;
    case 9:
        return 0x75;
    }
    for (index = 0; gEntryTable != NULL && index < gEntryCount; index++) {
        u16 entryFlags = gEntryTable[index].flags;
        if ((entryFlags & 0xF000) <= gEntryLevelLimit && !(entryFlags & 0x200)) {
            if ((entryFlags & 0xF) == 2) {
                return 0x9F;
            }
            if ((entryFlags & 0xF) == 0) {
                return 0x9E;
            }
        }
    }
    return 0xA0;
}
