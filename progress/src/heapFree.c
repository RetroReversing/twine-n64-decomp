typedef struct MemBlock { u16 flags; s32 size; u32 unk[2]; } MemBlock;
extern MemBlock *sHeapFirstBlock;
/* Frees a heap allocation: marks its block free and coalesces with the following and previous free blocks. */
void heapFree(void *userPtr) {
    MemBlock *block, *prev, *blockEnd, *nextBlock;
    u16 flags;
    if (!userPtr) return;
    block = sHeapFirstBlock;
    flags = block->flags;
    userPtr = (char *)userPtr - 16;
    prev = 0;
    if (!(flags & 8)) {
        do {
            blockEnd = (MemBlock *)((char *)block + block->size);
            nextBlock = blockEnd + 1;
            if (flags & 2) {
                if (userPtr != block) goto advance;
                block->flags = 1;
                if (blockEnd[1].flags & 1) {
                    s32 a = block->size;
                    s32 b = blockEnd[1].size;
                    block->size = (a += 16) + b;
                }
                if (prev && (prev->flags & 1)) {
                    s32 a = prev->size;
                    s32 b = block->size;
                    prev->size = (a += 16) + b;
                }
                return;
            }
        advance:
            prev = block;
            block = nextBlock;
            flags = block->flags;
        } while (!(flags & 8));
    }
}
