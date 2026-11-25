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

M2C_UNK freeMenuItemRecord(s32);                         /* extern */

/* Frees and clears the track's 4 records at +0x3D4 and 6 records at +0x3E4. */ void freeTrackSpriteSlots(void *track, s32 arg1) {
    s32 record;
    s32 record2;
    u32 i;
    u32 j;
    void *slotA;
    void *slotB;

    i = 0;
    slotA = track;
    do {
        record = M2C_FIELD(slotA, s32 *, 0x3D4);
        i += 1;
        if (record != 0) {
            freeMenuItemRecord(record);
            M2C_FIELD(slotA, s32 *, 0x3D4) = 0;
        }
        slotA += 4;
    } while (i < 4U);
    j = 0;
    slotB = track;
    do {
        record2 = M2C_FIELD(slotB, s32 *, 0x3E4);
        j += 1;
        if (record2 != 0) {
            freeMenuItemRecord(record2);
            M2C_FIELD(slotB, s32 *, 0x3E4) = 0;
        }
        slotB += 4;
    } while (j < 6U);
}
