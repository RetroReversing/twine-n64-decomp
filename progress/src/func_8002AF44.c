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

void func_80016314(void *handle);

void func_8002AF44(Record2AF *rec) {
    u32 i;
    if (rec && rec->entries) {
        if ((i = 0, rec->count)) {
            do {
                Entry2AF *entry = &rec->entries[(u16)i];
                if (entry->handle) {
                    func_80016314(entry->handle);
                    entry->handle = 0;
                }
                i++;
            } while ((u16)i < rec->count);
        }
        func_80016314(rec->handle);
        rec->handle = 0;
        rec->aux = 0;
        rec->entries = 0;
        rec->count = 0;
        rec->state = 0;
    }
}

