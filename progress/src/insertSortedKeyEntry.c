typedef struct {
    s32 words[3];
} TableEntry;

extern volatile s32 sLoadedSceneGroupCount;
extern s32 sLoadedSceneGroups;
extern u16 sLoadedSceneGroupIds, D_800F8162, D_800F8164;
extern TableEntry D_800F8168[];
void workerLockAcquire(void);
void workerLockRelease(void);

/* Inserts a key/value entry into the key-sorted table (max 256), or bumps the existing entry's refcount; returns 1 if added or bumped. */
s32 insertSortedKeyEntry(u16 key, const void *value, u16 extra) {
    s32 count, i, j, off, newCount;
    u32 wanted;
    TableEntry *dst, *src;

    workerLockAcquire();
    count = sLoadedSceneGroupCount;
    i = 0;
    if (count <= 0)
        goto append;
    wanted = key;
    off = 0;
scan:
    if (*(u16 *)((u8 *)&sLoadedSceneGroupIds + off) >= wanted)
        goto scanned;
    ++i;
    off += 12;
    if (i < count)
        goto scan;
scanned:
    count = sLoadedSceneGroupCount;
    if (i >= count)
        goto append;
    off = i * 12;
    if (*(u16 *)((u8 *)&sLoadedSceneGroupIds + off) == wanted)
        goto exists;
    if (count >= 256)
        goto fail;
    j = count - 1;
    if (j >= i) {
        volatile s64 padding;
        TableEntry *base = D_800F8168;
        s32 shift = j * 12;
        dst = &base[j];
        --base;
        src = &base[j];
        do {
            *dst = *src;
            dst--;
            j--;
            src--;
        } while (j >= i);
    }
    newCount = sLoadedSceneGroupCount + 1;
    goto insert;
exists:
    ++*(u16 *)((u8 *)&D_800F8164 + off);
    goto fail;
append:
    {
        s32 appendCount = sLoadedSceneGroupCount;
        if (appendCount < 256) {
            newCount = appendCount + 1;
            goto insert;
        }
    }
fail:
    workerLockRelease();
    return 0;
insert:
    do { sLoadedSceneGroupCount = newCount; } while (0);
    {
    s32 insertOffset = i * 12;
    *(u16 *)((u8 *)&sLoadedSceneGroupIds + insertOffset) = key;
    *(const void **)((u8 *)&sLoadedSceneGroups + insertOffset) = value;
    *(u16 *)((u8 *)&D_800F8162 + insertOffset) = extra;
    *(u16 *)((u8 *)&D_800F8164 + insertOffset) = 1;
    }
    workerLockRelease();
    return 1;
}
