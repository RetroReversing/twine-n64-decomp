/* machine draft (m2c) for gcc-2.7.2-kmc -G0 -mips3 -mgp32 -mfp32 -O2 -fno-strength-reduce, tried by autopilot */
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

M2C_UNK walkHeapLists(s32, u32);                    /* extern */
extern M2C_UNK gHeapTags;

/* When the low byte of mode is 0, sums the first word of each of the 53 12-byte heap tag entries and then walks the heap lists; returns the sum (0 otherwise). */ s32 sumHeapTagSizes(s32 mode) {
    s32 modeByte;
    s32 total;
    s32 byteOffset;
    u32 index;

    index = 0;
    total = 0;
    modeByte = mode << 0x18;
    if (modeByte == 0) {
        byteOffset = 0;
        __repair_rows: {
            index += 1;
            total += *((M2C_UNK *)((s8 *)&gHeapTags + byteOffset));
            byteOffset += 0xC;
        }
if (index < 0x35U) goto __repair_rows;
        walkHeapLists(modeByte, index);
    }
    return total;
}
