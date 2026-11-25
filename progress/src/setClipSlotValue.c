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

extern char gClipSlotBanks[];
extern char gClipSlotDefaultBank[];

/* Stores value at a slot in a 16-slot bank row; bank 0xFF selects the separate default row. */ void setClipSlotValue(u8 slot, u8 bankId, u8 value) {
    s32 bank = (u8)bankId;
    if (bank != 0xFF) {
        char *banks = gClipSlotBanks;
        u8 column = slot;
        char *bankRow = (char *)((bank << 4) + (s32)banks);
        *(bankRow + column) = value;
    } else {
        gClipSlotDefaultBank[(u8)slot] = value;
    }
}
