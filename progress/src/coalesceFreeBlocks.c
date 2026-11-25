typedef struct Blk { struct Blk *prev; struct Blk *next; s32 size; } Blk;
extern Blk *gHeapFreeList;

/* Merges physically adjacent blocks in the heap free list until no more merges happen. */
void coalesceFreeBlocks(s32 arg0) {
    Blk *block;
    Blk *adjacent;
    s16 didMerge;
    do {
        didMerge = 0;
        for (block = gHeapFreeList; block != 0; block = block->next) {
            adjacent = (Blk *)((u8 *)block + block->size);
            if (adjacent == block->next) {
                block->size += adjacent->size;
                block->next = adjacent->next;
                if (adjacent->next != 0) adjacent->next->prev = block;
                didMerge = 1;
            }
        }
    } while (didMerge);
}
