/* identical to func_80097704 (matched), with its names changed by decompdecomp */
typedef struct { s32 data; u16 id; u16 ref; } E97704;
extern s32 gCountedEntryCount;
extern E97704 D_800F7958[];
void workerLockAcquire(void);
void workerLockRelease(void);

s32 func_80097194(u16 arg0) {
    s32 i, j;

    workerLockAcquire();
    for (i = 0; i < gCountedEntryCount; i++) {
        if (D_800F7958[i].id == arg0) {
            break;
        }
    }
    if (i != gCountedEntryCount) {
        if (--D_800F7958[i].ref == 0) {
            for (j = i + 1; j < gCountedEntryCount; j++) {
                D_800F7958[j - 1] = D_800F7958[j];
            }
            gCountedEntryCount--;
            workerLockRelease();
            return 1;
        }
    }
    workerLockRelease();
    return 0;
}
