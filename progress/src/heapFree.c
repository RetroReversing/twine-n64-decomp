typedef struct MemBlock { u16 flags; s32 size; u32 unk[2]; } MemBlock;
extern MemBlock *sHeapFirstBlock;
void heapFree(void *ptr) {
    MemBlock *block, *prev, *end, *next;
    u16 flags;
    if (!ptr) return;
    block = sHeapFirstBlock;
    flags = block->flags;
    ptr = (char *)ptr - 16;
    prev = 0;
    if (!(flags & 8)) {
        do {
            end = (MemBlock *)((char *)block + block->size);
            next = end + 1;
            if (flags & 2) {
                if (ptr != block) goto advance;
                block->flags = 1;
                if (end[1].flags & 1) {
                    s32 a = block->size;
                    s32 b = end[1].size;
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
            block = next;
            flags = block->flags;
        } while (!(flags & 8));
    }
}
