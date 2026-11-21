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

extern HeapTag D_800CE354[];
extern volatile u32 D_800CE570;
extern s8 D_800E1A90;
extern volatile u32 D_800E1A9C;
extern volatile u32 D_800E1AA0;
extern HeapBlock *D_800E1AAC;
extern HeapBlock *volatile D_800E1AB0;
extern volatile u32 D_80102CB8;
extern volatile u32 D_80109A90;

s32 func_80083E90(s32 size, s32 tag) {
    if (D_800E1A90 == 0) {
        s32 mask = D_800CE354[tag].alignment - 1;
        s32 inverse = ~mask;
        if (tag == 45) {
            u32 old = D_80102CB8;
            u32 end = old - size;
            u32 used;
            end -= end & mask;
            used = D_800CE570;
            old -= end;
            D_80102CB8 = end;
            D_800CE570 = used + old;
            return end;
        } else {
            u32 old = D_80109A90;
            u32 used = D_800CE354[tag].used;
            u32 start = (old + mask) & inverse;
            u32 end = start + size;
            D_80109A90 = end;
            D_800CE354[tag].used = used + (end - old);
            return start;
        }
    } else if (size != 0) {
        HeapBlock *block = D_800E1AAC;
        u32 minimum = size + 24;
        if (block != NULL) {
            do {
                u32 available = block->size;
                u8 *end = (u8 *)block + available;
                if (available >= minimum) {
                    u32 mask = D_800CE354[tag].alignment - 1;
                    HeapBlock *newBlock = (HeapBlock *)((u32)end - size);
                    u32 extra = (u32)newBlock & mask;
                    if (available >= minimum + extra) {
                        u32 tagUsed;
                        u32 heapUsed;
                        u32 heapFree;
                        u32 blockFree;
                        HeapBlock *head;
                        size += extra;
                        available = size + 12;
                        tagUsed = D_800CE354[tag].used;
                        newBlock = (HeapBlock *)((u32)end - available);
                        heapFree = D_800E1A9C;
                        tagUsed += 12;
                        D_800CE354[tag].used = tagUsed + size;
                        heapUsed = D_800E1AA0;
                        heapFree -= 12;
                        D_800E1A9C = heapFree - size;
                        blockFree = block->size;
                        heapUsed += 12;
                        D_800E1AA0 = heapUsed + size;
                        head = D_800E1AB0;
                        blockFree -= 12;
                        block->size = blockFree - size;
                        newBlock->prev = NULL;
                        newBlock->size = available;
                        newBlock->next = head;
                        if (head)
                            head->prev = newBlock;
                        D_800E1AB0 = newBlock;
                        return (s32)(newBlock + 1);
                    }
                }
                block = block->next;
            } while (block != NULL);
        }
    }
    return 0;
}
