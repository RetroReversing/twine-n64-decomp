s32 workerLockAcquire();
s32 workerLockRelease();
typedef struct { s32 value; u16 key; u16 count; } Entry;
typedef struct { u16 cnt; u16 start; } Bucket;
extern s32 gEntryTableCount;
extern u16 gEntryTableNextStart;
extern Bucket gEntryBuckets[];
extern Entry gSortedEntries[];

/* Inserts a key/value into a bucketed sorted table, or bumps the count if the key exists; returns 1 if inserted, 0 otherwise. */ s32 insertSortedEntry(u16 entryKey, s32 entryValue) {
    u32 key;
    u32 bucket;
    s32 start;
    s32 i;
    s32 idx;
    s32 j;
    
    u16 cnt;

    workerLockAcquire();
    key = entryKey;
    bucket = key >> 6;
    cnt = gEntryBuckets[bucket].cnt;
    if (cnt == 0) {
        idx = gEntryTableNextStart;
        gEntryBuckets[bucket].start = gEntryTableNextStart;
        start = idx;
    } else {
        start = gEntryBuckets[bucket].start;
        for (i = 0; i < gEntryBuckets[bucket].cnt && gSortedEntries[start + i].key < key; i++) ;
        if (i < gEntryBuckets[bucket].cnt) {
            idx = start + i;
            if (gSortedEntries[idx].key == key) {
                gSortedEntries[idx].count++;
                workerLockRelease();
                return 0;
            }
        } else {
            idx = start + i;
        }
    }
    if (gEntryTableCount < 0x800) {
        Bucket *p = gEntryBuckets;
        for (j = 0; j < 0x800; j += 4) {
            s32 s = *(u16 *)((char *)&gEntryBuckets[0].start + j);
            if (start < s) {
                p->start = s + 1;
            }
            p++;
        }
        for (i = gEntryTableCount - 1; i >= idx; i--) {
            gSortedEntries[i + 1] = gSortedEntries[i];
        }
        gSortedEntries[idx].key = entryKey;
        gSortedEntries[idx].count = 1;
        gSortedEntries[idx].value = entryValue;
        gEntryBuckets[bucket].cnt++;
        gEntryTableCount++;
        workerLockRelease();
        return 1;
    }
    workerLockRelease();
    return 0;
}
