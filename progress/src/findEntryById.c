/* adapted from similar verified C in findTableIndexById in TWINE (matched), with its names changed by decompdecomp */
typedef struct { u16 id; u8 pad[0x26]; } Ent263B8;
typedef struct { Ent263B8 *arr; u8 pad4; u8 count; } Tbl263B8;

/* Returns the table entry whose id matches, or 0 if the table is NULL or has no such entry. */ s32 findEntryById(Tbl263B8 *table, u16 entryId) {
    u16 index;

    if (table == NULL) {
        return 0;
    }
    for (index = 0; index < table->count; index++) {
        if (table->arr[index].id == entryId) {
            return (s32) &table->arr[index];
        }
    }
    return 0;
}
