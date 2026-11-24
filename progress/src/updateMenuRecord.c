extern void *gNameEntryState;
extern void freeMenuRecord(void *);
/* Runs the record's update callback; frees the record and returns 0 if flagged finished, else returns 1. */
s32 updateMenuRecord(void *record) {
    void *handler;
    void (*onUpdate)();
    s32 result = 0;
    gNameEntryState = record;
    if (record) {
        handler = *(void **)((char *)record + 4);
        if (handler) {
            onUpdate = *(void (**)())((char *)handler + 4);
            if (onUpdate) onUpdate();
        }
        if (*(u8 *)((char *)record + 15)) {
            freeMenuRecord(record);
            return 0;
        }
        return 1;
    }
    return 0;
}
