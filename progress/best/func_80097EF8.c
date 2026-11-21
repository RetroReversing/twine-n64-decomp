s32 workerLockAcquire();
s32 workerLockRelease();
typedef struct { s32 value; u16 key; u16 count; } Entry;
typedef struct { u16 cnt; u16 start; } Bucket;
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
    u16 cnt;

    workerLockAcquire();
    key = arg0;
    b = key >> 6;
    cnt = D_800F8D60[b].cnt;
    if (cnt == 0) {
        idx = D_800F8D5E;
        D_800F8D60[b].start = D_800F8D5E;
        start = idx;
    } else {
        start = D_800F8D60[b].start;
        for (i = 0; i < D_800F8D60[b].cnt && D_800F9560[start + i].key < key; i++) ;
        if (i < D_800F8D60[b].cnt) {
            idx = start + i;
            if (D_800F9560[idx].key == key) {
                D_800F9560[idx].count++;
                workerLockRelease();
                return 0;
            }
        } else {
            idx = start + i;
        }
    }
    if (D_800F8D5C < 0x800) {
        Bucket *p = D_800F8D60;
        for (j = 0; j < 0x800; j += 4) {
            s32 s = *(u16 *)((char *)&D_800F8D60[0].start + j);
            if (start < s) {
                p->start = s + 1;
            }
            p++;
        }
        for (k = D_800F8D5C - 1; k >= idx; k--) {
            D_800F9560[k + 1] = D_800F9560[k];
        }
        D_800F9560[idx].key = arg0;
        D_800F9560[idx].count = 1;
        D_800F9560[idx].value = arg1;
        D_800F8D60[b].cnt++;
        D_800F8D5C++;
        workerLockRelease();
        return 1;
    }
    workerLockRelease();
    return 0;
}
