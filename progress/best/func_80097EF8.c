s32 workerLockAcquire();
s32 workerLockRelease();
typedef struct { s32 value; u16 key; u16 count; } Entry;
extern s32 D_800F8D5C;
extern u16 D_800F8D5E;
extern char D_800F8D60[];
extern char D_800F8D62[];
extern Entry D_800F9560[];
#define CNT(b) (*(u16 *)(D_800F8D60 + (b) * 4))
#define START(b) (*(u16 *)(D_800F8D62 + (b) * 4))

s32 func_80097EF8(u16 arg0, s32 arg1) {
    u32 key;
    u32 b;
    s32 start;
    s32 i;
    s32 idx;
    s32 j;
    s32 k;
    s32 cnt;
    char *p;

    workerLockAcquire();
    key = arg0;
    b = key >> 6;
    cnt = CNT(b);
    if (cnt == 0) {
        idx = D_800F8D5E;
        START(b) = D_800F8D5E;
        start = idx;
    } else {
        start = START(b);
        for (i = 0; i < cnt && D_800F9560[start + i].key < key; i++) ;
        idx = start + i;
        if (i < CNT(b)) {
            if (D_800F9560[idx].key == key) {
                D_800F9560[idx].count++;
                workerLockRelease();
                return 0;
            }
        }
    }
    if (D_800F8D5C < 0x800) {
        p = D_800F8D60;
        for (j = 0; j < 0x800; j += 4) {
            s32 s = *(u16 *)(D_800F8D62 + j);
            if (start < s) {
                *(u16 *)(p + 2) = s + 1;
            }
            p += 4;
        }
        for (k = D_800F8D5C - 1; k >= idx; k--) {
            D_800F9560[k + 1] = D_800F9560[k];
        }
        D_800F9560[idx].key = arg0;
        D_800F9560[idx].count = 1;
        D_800F9560[idx].value = arg1;
        CNT(b)++;
        D_800F8D5C++;
        workerLockRelease();
        return 1;
    }
    workerLockRelease();
    return 0;
}
