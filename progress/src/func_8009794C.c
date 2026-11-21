typedef struct { int a,b,c; } Entry;
extern Entry D_800F38E4[], sKeyTableSlots[];
extern int sKeyTableCount;
extern int workerLockAcquire(int), workerLockRelease(void);
int func_8009794C(int arg0) {
    int i, j;
    for (i=0; i<sKeyTableCount; i++) {
        if (sKeyTableSlots[i].a == arg0) break;
    }
    if (i != sKeyTableCount) {
        workerLockAcquire(arg0);
        for (j=i+1; j<sKeyTableCount; j++) D_800F38E4[j] = D_800F38E4[j+1];
        sKeyTableCount--;
        workerLockRelease();
        return 1;
    }
    return 0;
}
