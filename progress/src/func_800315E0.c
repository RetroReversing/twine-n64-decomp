typedef struct { s16 id; u16 flags; u16 c; u16 d; } E315;
typedef struct { u8 pad[2]; s8 ch; } O315;
s16 func_80030898(void);
O315 *lookupDataEntry(u16);
extern E315 *gEntryTable;
extern u16 gEntryCount;

void func_800315E0(s32 arg0) {
    s16 i = arg0 - 1;
    O315 *o;

    if (i < gEntryCount) {
        if (i >= 0 && (gEntryTable[i].flags & 0x200)) {
            gEntryTable[i].flags &= ~0x200;
            gEntryTable[i].id = func_80030898();
            o = lookupDataEntry(gEntryTable[i].c);
            if (o != NULL) {
                o->ch = ((u8 *)&gEntryTable[i])[1] + 'A';
            }
            o = lookupDataEntry(gEntryTable[i].d);
            if (o != NULL) {
                o->ch = ((u8 *)&gEntryTable[i])[1] + 'A';
            }
        }
    }
}
