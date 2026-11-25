typedef struct { u16 key; s16 state; u8 pad[0x18]; } N97814;
typedef struct { N97814 *list; s32 arg; u16 count; } Slot97814;
extern s32 sResourceTableCount;
extern Slot97814 sResourceTableSlots[];
void workerLockAcquire(void);
void workerLockRelease(void);
extern u8 D_800F38F4[];
extern u8 D_800F38F8[];

/* Registers a 0xFFFF-terminated key list in a free slot (max 8) and resets its entry states; returns 0 if full. */
u8 keyTableRegister(s32 keyList, s32 value) {
    s32 slot;
    u16 count;
    u16 k;
    N97814 *entry;

    for (slot = 0; slot < sResourceTableCount; slot++) {
        if (sResourceTableSlots[slot].list == keyList) {
            break;
        }
    }
    if (slot != sResourceTableCount) {
        return 1;
    }
    if (slot < 8) {
    count = 0;
    for (entry = keyList; entry->key != 0xFFFF; entry++) {
        count++;
    }
    workerLockAcquire();
    entry = keyList;
    slot = sResourceTableCount;
    *(N97814 **)((u8 *)sResourceTableSlots + slot * 12) = entry;
    *(u16 *)(D_800F38F8 + slot * 12) = count;
    *(s32 *)(D_800F38F4 + slot * 12) = value;
    slot = count;
    for (k = 0; k < (u32)slot; k++, entry++) {
        entry->state = 0;
    }
    sResourceTableCount++;
    workerLockRelease();
    return 1;
    }
    return 0;
}
