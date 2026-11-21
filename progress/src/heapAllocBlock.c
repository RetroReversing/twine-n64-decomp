s32 func_8000B334();
s32 func_8000B35C(u16 *, u16 *);
extern u16 *sHeapFirstBlock;

/* Allocates a 16-byte aligned payload of size bytes from the heap block list, tagging the block
   with type. Picks the last free block large enough, splits off the remainder when it is at least
   0x20 bytes, and returns the payload pointer or NULL. */
u16 *heapAllocBlock(s32 size, s32 type) {
    u16 *bestBlock;
    u16 *block;
    u16 *result;
    char *nextBlock;
    s16 blockType;
    u16 blockFlags;
    s32 padded;

    result = NULL;
    blockType = type;
    if (size) {
        func_8000B334();
        block = sHeapFirstBlock;
        blockFlags = *block;
        padded = size + 0xF;
        size = padded & ~0xF;
        bestBlock = NULL;
        if (!(blockFlags & 8)) {
            do {
                if (((*(u16 *)((char *)(block) + 0)) & 1) && ((u32) (*(u32 *)((char *)(block) + 4)) >= (u32)size)) {
                    bestBlock = block;
                }
                nextBlock = (char *)block + (*(u32 *)((char *)(block) + 4));
                block = (u16 *)(nextBlock + 0x10);
            } while (!((*(u16 *)(nextBlock + 0x10)) & 8));
        }
        if (bestBlock != NULL) {
            result = (void *) ((0x10) + (s32) bestBlock);
            (*(u16 *)((char *)(bestBlock) + 0)) = 2;
            (*(s16 *)((char *)(bestBlock) + 2)) = blockType;
            if ((u32)size != (*(u32 *)((char *)(bestBlock) + 4))) {
                block = (void *) ((s32)result + (u32)size);
                if ((u32) ((*(u32 *)((char *)(bestBlock) + 4)) - (u32)size) >= 0x20U) {
                    (*(u16 *)((char *)(block) + 0)) = 1;
                    (*(s32 *)((char *)(block) + 4)) = (s32) (((*(u32 *)((char *)(bestBlock) + 4)) - (u32)size) - 0x10);
                    (*(u32 *)((char *)(bestBlock) + 4)) = (u32)size;
                }
            }
        }
        func_8000B35C(bestBlock, block);
    }
    return result;
}
