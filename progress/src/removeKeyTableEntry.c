typedef struct {
    int key;
    int b;
    int c;
} KeyTableSlot;
extern KeyTableSlot D_800F38E4[], sKeyTableSlots[];
extern int sKeyTableCount;
extern int workerLockAcquire(int), workerLockRelease(void);

/* Removes the key table entry whose key matches the argument, shifting later entries down; returns 1 if found, 0 otherwise. */
int removeKeyTableEntry(int key) {
    int i, j;
    for (i = 0; i < sKeyTableCount; i++) {
        if (sKeyTableSlots[i].key == key) break;
    }
    if (i != sKeyTableCount) {
        workerLockAcquire(key);
        for (j = i + 1; j < sKeyTableCount; j++) D_800F38E4[j] = D_800F38E4[j + 1];
        sKeyTableCount--;
        workerLockRelease();
        return 1;
    }
    return 0;
}
