/* machine draft (m2c) for gcc-2.7.2-kmc -G0 -mips3 -mgp32 -mfp32 -O1, tried by autopilot */
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

extern char gTrackMarkerDone[];

/* If the object has flag 0x400000, clears it and marks its track marker (id read via +0x6C) as done. */ void markTrackMarkerDone(void *object) {
    u8 * markerIdPtr;

    s32 flags;
    u8 markerId;

    flags = M2C_FIELD(object, s32 *, 0x60);
    markerIdPtr = M2C_FIELD(object, u8 **, 0x6C);
    if (flags & 0x400000) {
        M2C_FIELD(object, s32 *, 0x60) = (s32) (flags & 0xFFBFFFFF);
        markerId = *markerIdPtr;
        if (markerId != 0) {
            *(gTrackMarkerDone + markerId) = 1;
        }
    }
}
