s32 workerLockAcquire();
s32 workerLockRelease();
typedef struct { u16 count; u16 start; } Bucket;
typedef struct { s32 value; u16 key; u16 count; } Entry;
extern s32 D_800F8D5C;
extern u16 D_800F8D5E;
extern Bucket D_800F8D60[];
extern Entry D_800F9560[];

s32 func_80097EF8(u16 arg0, s32 arg1) {
    u32 key;
    u32 b;
    s32 start;
    s32 i;
    s32 idx;
    s32 j;
    s32 k;

    workerLockAcquire();
    key = arg0;
    b = key >> 6;
    if (D_800F8D60[b].count == 0) {
        idx = D_800F8D5E;
        D_800F8D60[b].start = D_800F8D5E;
        start = idx;
    } else {
        start = D_800F8D60[b].start;
        i = 0;
        if (D_800F8D60[b].count != 0) {
            while (D_800F9560[start + i].key < key) {
                i++;
                if (i >= D_800F8D60[b].count) break;
            }
        }
        idx = start + i;
        if (i < D_800F8D60[b].count) {
            if (D_800F9560[idx].key == key) {
                D_800F9560[idx].count++;
                workerLockRelease();
                return 0;
            }
        }
    }
    if (D_800F8D5C < 0x800) {
        for (j = 0; j < 0x200; j++) {
            if (start < D_800F8D60[j].start) {
                D_800F8D60[j].start = D_800F8D60[j].start + 1;
            }
        }
        for (k = D_800F8D5C - 1; k >= idx; k--) {
            D_800F9560[k + 1] = D_800F9560[k];
        }
        D_800F9560[idx].key = arg0;
        D_800F9560[idx].count = 1;
        D_800F9560[idx].value = arg1;
        D_800F8D60[b].count++;
        D_800F8D5C++;
        workerLockRelease();
        return 1;
    }
    workerLockRelease();
    return 0;
}
