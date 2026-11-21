typedef struct { u16 a; u16 flags; u32 b; } Ent30C7C;
extern u32 gEntryMode;
extern Ent30C7C *gEntryTable;
extern u16 gEntryCount;
extern u16 gEntryLevelLimit;

s32 func_80030C7C(void) {
    u16 i;

    switch (gEntryMode) {
    case 7:
        return 0x76;
    case 4:
        return 0x9F;
    case 9:
        return 0x75;
    }
    for (i = 0; gEntryTable != NULL && i < gEntryCount; i++) {
        u16 f = gEntryTable[i].flags;
        if ((f & 0xF000) <= gEntryLevelLimit && !(f & 0x200)) {
            if ((f & 0xF) == 2) {
                return 0x9F;
            }
            if ((f & 0xF) == 0) {
                return 0x9E;
            }
        }
    }
    return 0xA0;
}
