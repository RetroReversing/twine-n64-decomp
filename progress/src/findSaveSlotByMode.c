extern void ***func_8002A920(void *, s8);
extern char *lookupDataEntry(s32);
extern char *func_800AB950(char *, char *);
extern s16 gSaveFoundSlot;
extern s32 D_80107EA8;
extern char D_800D2AC0[];
/* Scans the 16 save slot entries and returns a slot index chosen by mode (1 = found slot, 2/3 = name matching). */
s32 findSaveSlotByMode(s32 mode) {
    u8 slot = 0;
    s32 searchMode = mode & 0xfff;
    void ***entry;
    void **info;
    char *name;
    do {
        entry = func_8002A920(&D_80107EA8, slot);
        if (entry && (info = *entry) && *(char **)((char *)*info + 0x18)) {
            switch (searchMode) {
            case 1:
                if (gSaveFoundSlot != -1) return (u8)gSaveFoundSlot;
                return 0;
            case 2:
                name = lookupDataEntry(0x3004);
                if (func_800AB950(*(char **)((char *)*info + 0x18), name)) return slot;
                if (func_800AB950(*(char **)((char *)*info + 0x18), D_800D2AC0)) return slot;
                break;
            case 3:
                name = lookupDataEntry(0x3004);
                if (func_800AB950(*(char **)((char *)*info + 0x18), name)) {
                    slot++;
                    goto check_next;
                }
                return slot;
            }
        }
        slot++;
check_next:
        ;
    } while (slot < 16);
    return 0;
}
