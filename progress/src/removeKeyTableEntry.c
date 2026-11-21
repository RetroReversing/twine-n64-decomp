typedef struct { int a,b,c; } Entry;
extern Entry D_800F38E4[], D_800F38F0[];
extern int D_800F38EC;
extern int workerLockAcquire(int), workerLockRelease(void);
int func_8009794C(int arg0) {
    int i, j;
    for (i=0; i<D_800F38EC; i++) {
        if (D_800F38F0[i].a == arg0) break;
    }
    if (i != D_800F38EC) {
        workerLockAcquire(arg0);
        for (j=i+1; j<D_800F38EC; j++) D_800F38E4[j] = D_800F38E4[j+1];
        D_800F38EC--;
        workerLockRelease();
        return 1;
    }
    return 0;
}
