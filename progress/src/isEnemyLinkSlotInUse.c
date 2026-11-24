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

extern u8 sEnemyDefLinkSlot[];

/* Returns 1 if any active entry in slots 4..0x20 of the owner's table uses the given enemy-def link slot, else 0. */ s32 isEnemyLinkSlotInUse(void *owner, s32 linkSlot) {
    s32 defOffset;
    u32 index;
    void *entryPtr;

    index = 4;
    defOffset = 0x3A0;
    entryPtr = M2C_FIELD(owner, s32 *, 0x6C) + 0x20;
    do {
        if ((M2C_FIELD(entryPtr, u8 *, 0x1FC) != 0) && (*(sEnemyDefLinkSlot + defOffset) == linkSlot)) {
            return 1;
        }
        defOffset += 0xE8;
        index += 1;
        entryPtr += 8;
    } while (index < 0x21U);
    return 0;
}
