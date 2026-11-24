typedef struct { s16 id; u16 flags; u16 c; u16 d; } E315;
typedef struct { u8 pad[2]; s8 ch; } O315;
s16 func_80030898(void);
O315 *lookupDataEntry(u16);
extern E315 *gEntryTable;
extern u16 gEntryCount;

/* If the 1-based entry is flagged 0x200, clears the flag, assigns it a new id and writes its letter label into both linked data entries. */ void refreshEntryLabel(s32 entryNumber) {
    s16 index = entryNumber - 1;
    O315 *obj;

    if (index < gEntryCount) {
        if (index >= 0 && (gEntryTable[index].flags & 0x200)) {
            gEntryTable[index].flags &= ~0x200;
            gEntryTable[index].id = func_80030898();
            obj = lookupDataEntry(gEntryTable[index].c);
            if (obj != NULL) {
                obj->ch = ((u8 *)&gEntryTable[index])[1] + 'A';
            }
            obj = lookupDataEntry(gEntryTable[index].d);
            if (obj != NULL) {
                obj->ch = ((u8 *)&gEntryTable[index])[1] + 'A';
            }
        }
    }
}
