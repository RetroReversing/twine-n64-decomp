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

extern char gSaveSlotFlags[];

/* Returns the index of the (n+1)-th save slot (of 4) with nonzero flags, or 0 if n is 0. */ s32 findNthUsedSaveSlot(s32 n) {
    char *flags;
    s32 target;
    u8 usedCount;
    s32 result;
    s32 slot;

    slot = 0;
    usedCount = 0;
    target = n & 0xFF;
flags = gSaveSlotFlags;
    for (;;) {
        if (*(u16 *)(((slot & 0xFF) * 2) + flags) == 0) goto skip;
        usedCount += 1;
        skip:;
        if ((usedCount & 0xFF) != (target + 1)) {
            slot += 1;
            if ((u32) (slot & 0xFF) < 4U) {
                continue;
            }
        }
        break;
    }
    result = 0;
    if (target != 0) {
        result = slot & 0xFF;
    }
    return result;
}
