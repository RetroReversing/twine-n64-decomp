typedef struct AudioSlot { struct AudioSlot *next; struct AudioSlot *prev; u8 *buf; s32 a, b; } AudioSlot;
extern AudioSlot *sSlotPool;
extern u8 *sSlotBufferBase;
extern s32 D_800E4248;
extern s32 sSlotActiveList;
extern AudioSlot *sSlotFreeList;
extern void *(*gDataBankHandler)(s32, s32);
void flushDCacheRange(void *, s32);

/* Allocates the slot array and a 256-byte buffer per slot, then links the slots into the free list. */
void audioInitSlotPool(s32 slotCount) {
    s32 i;
    void *(**alloc)(s32, s32) = &gDataBankHandler;
    s32 bufferBytes;

    sSlotPool = (*alloc)(slotCount * sizeof(AudioSlot), 0);
    bufferBytes = slotCount << 8;
    sSlotBufferBase = (*alloc)(bufferBytes, 0);
    flushDCacheRange(sSlotBufferBase, bufferBytes);
    sSlotActiveList = 0;
    sSlotFreeList = sSlotPool;
    sSlotPool[0].buf = sSlotBufferBase;
    sSlotPool[0].prev = NULL;
    for (i = 1; i < slotCount; i++) {
        sSlotPool[i].prev = &sSlotPool[i - 1];
        sSlotPool[i].buf = sSlotBufferBase + i * 0x100;
        sSlotPool[i - 1].next = &sSlotPool[i];
    }
    D_800E4248 = 0;
    sSlotPool[i - 1].next = NULL;
}
