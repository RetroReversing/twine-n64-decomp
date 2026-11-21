typedef struct { s32 data; u16 id; u16 ref; } E97704;
extern s32 gCountedEntryTotal;
extern E97704 sCountedEntries[];
void workerLockAcquire(void);
void workerLockRelease(void);

/* Drops one reference to the entry with the given id, under the worker lock. When the count reaches zero the entry is removed from the table; returns 1 if removed, else 0. */
s32 releaseCountedEntry(u16 id) {
    s32 i, j;

    workerLockAcquire();
    for (i = 0; i < gCountedEntryTotal; i++) {
        if (sCountedEntries[i].id == id) {
            break;
        }
    }
    if (i != gCountedEntryTotal) {
        if (--sCountedEntries[i].ref == 0) {
            for (j = i + 1; j < gCountedEntryTotal; j++) {
                sCountedEntries[j - 1] = sCountedEntries[j];
            }
            gCountedEntryTotal--;
            workerLockRelease();
            return 1;
        }
    }
    workerLockRelease();
    return 0;
}
