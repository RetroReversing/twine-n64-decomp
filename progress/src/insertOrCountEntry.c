s32 workerLockAcquire();
s32 workerLockRelease();
extern s32 gCountedEntryCount;
extern char D_800F7958[];
extern char D_800F795C[];
extern char D_800F7960[];
typedef struct { s32 w[2]; } __repair_words2;

/* Inserts (key, value) into the sorted counted table, or bumps the count of an existing key. Returns 1 if stored, 0 if the table is full. */
s32 insertOrCountEntry(u16 key, s32 value) {
    int __repair_literal;
    s32 newCount, currentCount, entryCount, shiftIndex, insertIndex, nextCount, scanOffset, shiftOffset;
    u32 keyValue;
    void *srcEntry, *dstEntry;

    workerLockAcquire();
    entryCount = gCountedEntryCount;
    insertIndex = 0;
__repair_literal = 0;
    if (entryCount > __repair_literal) {
        keyValue = key & 0xFFFF;
        scanOffset = 0;
loop_2:
        if ((u16)*(u16 *)(D_800F795C + scanOffset) < keyValue) {
            insertIndex += 1;
            scanOffset += 8;
            if (insertIndex < entryCount) goto loop_2;
        }
        entryCount = insertIndex * 8;
        if (insertIndex < gCountedEntryCount) {
            if (*(u16 *)(D_800F795C + entryCount) != keyValue) {
                shiftIndex = gCountedEntryCount - 1;
                if (gCountedEntryCount < 0x800) {
                    shiftOffset = shiftIndex * 8;
                    if (shiftIndex >= insertIndex) {
                        dstEntry = shiftOffset + D_800F7960;
                        srcEntry = shiftOffset + (D_800F7960 - 8);
                        do {
                            *((__repair_words2 *)dstEntry) = *((__repair_words2 *)srcEntry);
                            dstEntry -= 8;
                            shiftIndex -= 1;
                            srcEntry -= 8;
                        } while (shiftIndex >= insertIndex);
                    }
                    nextCount = gCountedEntryCount + 1;
                    goto block_15;
                }
                goto block_14;
            }
            *(u16 *)(D_800F795C + 2 + entryCount) = *(u16 *)(D_800F795C + 2 + entryCount) + 1;
            goto block_14;
        }
        goto block_13;
    }
block_13:
    currentCount = gCountedEntryCount;
    if (currentCount < 0x800) {
        nextCount = currentCount + 1;
        goto block_15;
    }
block_14:
    workerLockRelease();
    return 0;
block_15:
    gCountedEntryCount = nextCount;
    newCount = insertIndex * 8;
    *(u16 *)(D_800F795C + newCount) = key;
    *(s32 *)(D_800F7958 + newCount) = value;
    *(u16 *)(D_800F795C + 2 + newCount) = 1;
    workerLockRelease();
    return 1;
}
