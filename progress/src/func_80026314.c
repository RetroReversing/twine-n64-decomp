typedef struct { u16 id; u8 rest[0x26]; } Record26314;
typedef struct { Record26314 *records; u8 pad; u8 count; } List26314;
Record26314 *func_80026314(List26314 *list, u16 id, u8 occurrence) {
    u16 i, seen;
    u8 count;
    Record26314 *base, *entry;

    seen = 0;
    if (list == NULL)
        return NULL;
    count = list->count;
    i = 0;
    if (count) {
        base = list->records;
        do {
            entry = (Record26314 *)((u32)(i * sizeof(*entry)) + (u32)base);
            i++;
            if (entry->id == id) {
                seen++;
                if (seen == occurrence)
                    return entry;
            }
        } while (i < count);
    }
    return NULL;
}
