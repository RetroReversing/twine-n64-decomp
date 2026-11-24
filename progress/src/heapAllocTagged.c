typedef struct HeapBlock {
    struct HeapBlock *prev;
    struct HeapBlock *next;
    volatile u32 size;
} HeapBlock;

typedef struct {
    volatile u32 used;
    u8 alignment;
    char pad[3];
    const char *name;
} HeapTag;

extern HeapTag gHeapTags[];
extern volatile u32 gBumpAllocRemaining;
extern s8 gHeapActive;
extern volatile u32 gHeapFreeBytes;
extern volatile u32 gHeapUsedBytes;
extern HeapBlock *gHeapFreeList;
extern HeapBlock *volatile gHeapAllocList;
extern volatile u32 gTopBumpAllocPtr;
extern u32 gBumpAllocPtr;

/* Allocates size bytes under a heap tag. Before the heap is active it bump-allocates
 * (tag 45 from the top); afterwards it carves from the end of the first free block that fits,
 * honoring the tag's alignment. Returns 0 on failure. */
s32 heapAllocTagged(s32 size, s32 tag) {
    u32 misalign;
    if (gHeapActive == 0) {
        s32 mask = gHeapTags[tag].alignment - 1;
        if (tag == 45) {
            u32 old = gTopBumpAllocPtr;
            u32 end = old - size;
            u32 used;
            end -= end & mask;
            used = gBumpAllocRemaining;
            old -= end;
            gTopBumpAllocPtr = end;
            gBumpAllocRemaining = used + old;
            return end;
        } else {
            u32 old;
            u32 used;
            u32 start;
            u32 end;
            u32 inverse;
            old = gBumpAllocPtr;
            used = *(u32 *)&gHeapTags[tag].used;
            misalign = old + mask;
            inverse = ~mask;
            start = misalign & inverse;
            end = start + size;
            gBumpAllocPtr = end;
            gHeapTags[tag].used = used + (end - old);
            return start;
        }
    } else if (size != 0) {
        HeapBlock *block = gHeapFreeList;
        u32 minimum = size + 24;
        if (block != NULL) {
            do {
                u32 available;
                u8 *end;
                do { do { do { available = block->size; } while (0); } while (0); } while (0);
                do { end = (u8 *)block + available; } while (0);
                if (available >= minimum) {
                    u32 mask;
                    HeapBlock *newBlock;
                    mask = gHeapTags[tag].alignment - 1;
                    newBlock = (HeapBlock *)((u32)end - size);
                    misalign = (u32)newBlock & mask;
                    if (available >= minimum + misalign) {
                        u32 tagUsed;
                        u32 heapUsed;
                        u32 heapFree;
                        u32 blockFree;
                        HeapBlock *head;
                        size += misalign;
                        do { do { do { available = size + 12; } while (0); } while (0); } while (0);
                        tagUsed = gHeapTags[tag].used;
                        newBlock = (HeapBlock *)((u32)end - available);
                        do { heapFree = gHeapFreeBytes; } while (0);
                        tagUsed += 12;
                        gHeapTags[tag].used = tagUsed + size;
                        heapUsed = gHeapUsedBytes;
                        heapFree -= 12;
                        gHeapFreeBytes = heapFree - size;
                        blockFree = block->size;
                        heapUsed += 12;
                        gHeapUsedBytes = heapUsed + size;
                        head = gHeapAllocList;
                        blockFree -= 12;
                        block->size = blockFree - size;
                        newBlock->prev = NULL;
                        newBlock->size = available;
                        newBlock->next = head;
                        if (head)
                            head->prev = newBlock;
                        gHeapAllocList = newBlock;
                        return (s32)(newBlock + 1);
                    }
                }
                block = block->next;
            } while (block != NULL);
        }
    }
    return 0;
}
