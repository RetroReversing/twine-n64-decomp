typedef struct Node { struct Node *a; struct Node *b; s32 size; } Node;
extern struct { s32 value; s32 pad[2]; } gHeapTags[];
extern s8 gHeapActive;
extern s32 gHeapFreeBytes;
extern s32 gHeapUsedBytes;
extern Node *gHeapFreeList;
extern Node *gHeapAllocList;
void coalesceFreeBlocks();

/* Frees a heap allocation: unlinks it from the allocated list, inserts it into the address-sorted free list, then coalesces neighbours. */ void freeHeapBlock(void *ptr, s32 tag) {
    Node *block;
    Node *prevBlock;
    Node *nextBlock;
    Node *freeBlock;
    Node *nextFree;
    Node *before;

    if (gHeapActive != 0) {
        if (ptr != NULL) {
            block = (Node *)((char *)ptr - 12);
            gHeapTags[tag].value -= block->size;
            gHeapFreeBytes += block->size;
            gHeapUsedBytes -= block->size;
            prevBlock = block->b;
            nextBlock = block->a;
            if (prevBlock != NULL) {
                prevBlock->a = nextBlock;
            }
            if (nextBlock != NULL) {
                nextBlock->b = prevBlock;
            }
            if (block == gHeapAllocList) {
                gHeapAllocList = ((volatile Node *)block)->b;
            }
            block->a = NULL;
            block->b = NULL;
            freeBlock = gHeapFreeList;
            if (freeBlock != NULL) {
                do {
                    nextFree = freeBlock->b;
                    if (nextFree == NULL) {
                        if (freeBlock < block) {
                            freeBlock->b = block;
                            block->b = NULL;
                            block->a = freeBlock;
                        } else {
                            before = freeBlock->a;
                            if (before != NULL) {
                                before->b = block;
                            }
                            freeBlock->a = block;
                            block->b = freeBlock;
                            block->a = before;
                        }
                        break;
                    }
                    if ((u8)((freeBlock < block) & (block < nextFree)) == 0) {
                        freeBlock = nextFree;
                    } else {
                        freeBlock->b = block;
                        block->a = freeBlock;
                        nextFree->a = block;
                        block->b = nextFree;
                        break;
                    }
                } while (freeBlock != NULL);
            }
            coalesceFreeBlocks(freeBlock);
        }
    }
}
