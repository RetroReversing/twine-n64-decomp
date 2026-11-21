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

s32 func_8000B534(void) {
    u8 *p;
    u8 *next;
    s32 n;
    s32 sum;
    u16 flags;

    p = (u8 *)sHeapFirstBlock;
    sum = 0;
    if (!(*(u16 *)p & 8)) {
        do {
            n = *(s32 *)(p + 4);
            flags = *(u16 *)p;
            p += n;
            next = p + 0x10;
            if (flags & 2) {
                sum += n;
            }
            flags = *(u16 *)(p + 0x10);
            p = next;
        } while (!(flags & 8));
    }
    return sum;
}
