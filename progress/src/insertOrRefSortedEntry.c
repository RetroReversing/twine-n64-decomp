#define SORTED_TABLE_MAX 0x800

typedef struct { s32 value, keyRefs; } EntryWords;

void workerLockAcquire(void);
void workerLockRelease(void);
extern volatile s32 sortedEntryCount;
extern char sortedEntryValues[];
extern char sortedEntryKeys[];
extern char sortedEntryShiftBuf[];

/* Under the worker lock, inserts key into the sorted entry table, or bumps its refcount if already present. Returns 1 if inserted, 0 if full or duplicate. */
s32 insertOrRefSortedEntry(u16 key, s32 value) {
    struct { s32 value; u16 key; u16 refs; } previous;
    s32 entryCount;
    s32 currentCount;
    s32 insertIndex;
    s32 insertOffset;
    s32 moveIndex;
    s32 newCount;
    s32 probeOffset;
    s32 entryOffset;
    s32 moveOffset;
    u32 keyU32;
    void *dstPtr;
    void *srcPtr;

    workerLockAcquire();
    entryCount = sortedEntryCount;
    insertIndex = 0;
    if (entryCount > 0) {
        keyU32 = key & 0xFFFF;
        probeOffset = 0;
loop_2:
        if ((u16) *(u16 *)(sortedEntryKeys + probeOffset) < keyU32) {
            insertIndex += 1;
            probeOffset += 8;
            if (insertIndex < entryCount) {
                goto loop_2;
            }
        }
        insertOffset = insertIndex * 8;
        if (insertIndex < (currentCount = sortedEntryCount)) {
            if (*(u16 *)(sortedEntryKeys + insertOffset) != keyU32) {
                moveIndex = currentCount - 1;
                if (currentCount < SORTED_TABLE_MAX) {
                    moveOffset = moveIndex * 8;
                    if (moveIndex >= insertIndex) {
                        dstPtr = moveOffset + sortedEntryShiftBuf;
                        srcPtr = moveOffset + (sortedEntryShiftBuf - 8);
                        do {
                            *(EntryWords *)dstPtr = *(EntryWords *)srcPtr;
                            dstPtr -= 8;
                            moveIndex -= 1;
                            srcPtr -= 8;
                        } while (moveIndex >= insertIndex);
                    }
                    newCount = sortedEntryCount + 1;
                    goto block_15;
                }
                goto block_14;
            }
            workerLockRelease();
            *(u16 *)(sortedEntryKeys + 2 + insertOffset) = *(u16 *)(sortedEntryKeys + 2 + insertOffset) + 1;
            return 0;
        }
        goto check_capacity;
    }
    currentCount = sortedEntryCount;
check_capacity:
    if (currentCount < SORTED_TABLE_MAX) {
        newCount = currentCount + 1;
        goto block_15;
    }
block_14:
    workerLockRelease();
    return 0;
block_15:
    sortedEntryCount = newCount;
    entryOffset = insertIndex * 8;
    *(u16 *)(sortedEntryKeys + entryOffset) = key;
    *(s32 *)(sortedEntryValues + entryOffset) = value;
    *(u16 *)(sortedEntryKeys + 2 + entryOffset) = 1;
    workerLockRelease();
    return 1;
}
