typedef struct { s32 data; u16 id; u16 ref; } E97704;
extern s32 sortedEntryCount;
extern E97704 sortedEntryValues[];
void workerLockAcquire(void);
void workerLockRelease(void);

/* Drops one reference to the sorted entry with the given id, under the worker lock. When the count reaches zero the entry is removed from the table; returns 1 if removed, else 0. */
s32 releaseSortedEntry(u16 id) {
    s32 i, j;

    workerLockAcquire();
    for (i = 0; i < sortedEntryCount; i++) {
        if (sortedEntryValues[i].id == id) {
            break;
        }
    }
    if (i != sortedEntryCount) {
        if (--sortedEntryValues[i].ref == 0) {
            for (j = i + 1; j < sortedEntryCount; j++) {
                sortedEntryValues[j - 1] = sortedEntryValues[j];
            }
            sortedEntryCount--;
            workerLockRelease();
            return 1;
        }
    }
    workerLockRelease();
    return 0;
}
