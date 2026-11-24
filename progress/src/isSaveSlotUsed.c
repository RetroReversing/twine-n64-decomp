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

extern char gSaveSlotHeaders[];

/* Returns 1 if the slot index (0-15) is in range and its 0x18-byte save header starts with a nonzero halfword, else 0. */ s32 isSaveSlotUsed(s32 slot) {
    s32 used;
    u32 slotIndex;

    slotIndex = slot & 0xFFFF;
    if ((slotIndex >= 0x10U) || (used = 1, (*(u16 *)(gSaveSlotHeaders + (slotIndex * 0x18)) == 0))) {
        return 0;
    }
    return used;
}
