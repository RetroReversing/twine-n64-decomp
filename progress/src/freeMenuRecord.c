typedef struct {
    u8 pad[8];
    void *handle;
    u8 tail[0x1C];
} Entry2AF;

typedef struct {
    Entry2AF *entries;
    void *aux;
    void *handle;
    s8 state;
    u8 pad;
    u8 count;
} Record2AF;

void freeMenuItemRecord(void *handle);

/* Frees every item handle and the record's own handle, then clears the record. */ void freeMenuRecord(Record2AF *record) {
    u32 index;
    if (record && record->entries) {
        if ((index = 0, record->count)) {
            do {
                Entry2AF *item = &record->entries[(u16)index];
                if (item->handle) {
                    freeMenuItemRecord(item->handle);
                    item->handle = 0;
                }
                index++;
            } while ((u16)index < record->count);
        }
        freeMenuItemRecord(record->handle);
        record->handle = 0;
        record->aux = 0;
        record->entries = 0;
        record->count = 0;
        record->state = 0;
    }
}

