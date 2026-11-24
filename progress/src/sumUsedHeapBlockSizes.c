/* machine draft (m2c) for gcc-2.7.2-kmc -G0 -mips3 -mgp32 -mfp32 -O2, tried by autopilot */
#ifndef M2C_DEFINES
#define M2C_DEFINES
typedef s32 M2C_UNK;
typedef s8 M2C_UNK8;
typedef s16 M2C_UNK16;
typedef s32 M2C_UNK32;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define M2C_CARRY 0
#define M2C_OVERFLOW(a) (0)
#endif

extern u16 *sHeapFirstBlock;

/* Walks the heap block list until the end block (flag 8) and totals the sizes of blocks with flag 2 set. */ s32 sumUsedHeapBlockSizes(void) {
    u8 *block;
    u8 *next;
    s32 blockSize;
    s32 totalSize;
    u16 flags;

    block = (u8 *)sHeapFirstBlock;
    totalSize = 0;
    if (!(*(u16 *)block & 8)) {
        do {
            blockSize = *(s32 *)(block + 4);
            flags = *(u16 *)block;
            block += blockSize;
            next = block + 0x10;
            if (flags & 2) {
                totalSize += blockSize;
            }
            flags = *(u16 *)(block + 0x10);
            block = next;
        } while (!(flags & 8));
    }
    return totalSize;
}
