typedef struct { s32 a[6]; } Arr6;
extern Arr6 gBlockSizeClasses;

/* Returns the entry at index from the block size class table (copied to a local first). */ s32 getBlockSizeClass(s32 index) {
    Arr6 classes = gBlockSizeClasses;
    return classes.a[index];
}

typedef struct Blk { struct Blk *prev; struct Blk *next; s32 size; } Blk;
extern Blk *gHeapFreeList;

void coalesceFreeBlocks(void) {
    Blk *b, *n;
    s32 merged;
    do {
        merged = 0;
        for (b = gHeapFreeList; b != 0; b = b->next) {
            n = (Blk *)((u8 *)b + b->size);
            if (n == b->next) {
                b->size += n->size;
                b->next = n->next;
                if (n->next != 0) n->next->prev = b;
                merged = 1;
            }
        }
    } while (merged);
}
