typedef struct { u16 a; u16 b; } Pair982B4;
extern Pair982B4 gEntryBuckets[];
extern s32 D_800F3880;
extern s32 D_800F3884;
extern s16 D_800F388C;
extern s32 *D_800F3890;
extern u8 gSortedEntries[];
s32 *binarySearchRecords(void *, void *, s32, s32, void *);
void compareEntryKey(void);

/* Looks up a 16-bit key: picks a bucket from its top bits, binary-searches the bucket's sorted entries, returns the match's first word or 0. */ s32 lookupSortedEntry(s16 key) {
    u32 idx = (u16)key >> 6;
    s16 *p;
    s32 *r;
    s32 b;

    D_800F3884 = idx;
    if (gEntryBuckets[idx].a != 0) {
        b = gEntryBuckets[idx].b;
        p = &D_800F388C;
        *p = key;
        D_800F3880 = b;
        r = binarySearchRecords((u8 *)p - 4, &gSortedEntries[b * 8], gEntryBuckets[idx].a, 8, compareEntryKey);
        D_800F3890 = r;
        if (r == NULL) {
            return 0;
        }
        return *r;
    }
    return 0;
}
