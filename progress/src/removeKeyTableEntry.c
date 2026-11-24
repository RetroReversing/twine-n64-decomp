typedef struct {
    int key;
    int b;
    int c;
} KeyTableSlot;
extern KeyTableSlot D_800F38E4[], sResourceTableSlots[];
extern int sResourceTableCount;
extern int workerLockAcquire(int), workerLockRelease(void);

/* Removes the key table entry whose key matches the argument, shifting later entries down; returns 1 if found, 0 otherwise. */
int removeKeyTableEntry(int key) {
    int i, j;
    for (i = 0; i < sResourceTableCount; i++) {
        if (sResourceTableSlots[i].key == key) break;
    }
    if (i != sResourceTableCount) {
        workerLockAcquire(key);
        for (j = i + 1; j < sResourceTableCount; j++) D_800F38E4[j] = D_800F38E4[j + 1];
        sResourceTableCount--;
        workerLockRelease();
        return 1;
    }
    return 0;
}
