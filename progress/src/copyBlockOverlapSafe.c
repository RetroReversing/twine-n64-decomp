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

/* memmove-style copy: copies count bytes from the block's source (+0xC) to its destination, going backwards if the ranges overlap. */ void copyBlockOverlapSafe(void *block) {
    u8 *dst;
    u8 *src;
    s32 count;

    src = (u8 *) M2C_FIELD(block, s32 *, 4) + 0xC;
    dst = (u8 *) M2C_FIELD(block, s32 *, 0);
    count = M2C_FIELD(block, s32 *, 0xC);
    if ((src >= dst) || (dst >= src + count)) {
        while (count-- != 0) {
            *dst++ = *src++;
        }
    } else {
        dst += count - 1;
        src += count - 1;
        while (count-- != 0) {
            *dst-- = *src--;
        }
    }
}
