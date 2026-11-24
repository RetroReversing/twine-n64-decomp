typedef struct { u16 id; u8 pad[0x26]; } Ent263B8;
typedef struct { Ent263B8 *arr; u8 pad4; u8 count; } Tbl263B8;

/* Returns the index of the entry with the given id, or 0 if the table is NULL or the id isn't found. */ s32 findTableIndexById(Tbl263B8 *table, u16 targetId) {
    u16 index;

    if (table == NULL) {
        return 0;
    }
    for (index = 0; index < table->count; index++) {
        if (table->arr[index].id == targetId) {
            return index;
        }
    }
    return 0;
}
