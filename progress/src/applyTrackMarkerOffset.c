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

extern u8 gTrackMarkerDone[];

/* Adds the marker's position offset to the object once its required track marker is done (or if none is required). */ void applyTrackMarkerOffset(void *obj) {
    u8 markerId;
    void *marker;

    marker = M2C_FIELD(obj, void **, 0x6C);
    markerId = M2C_FIELD(marker, u8 *, 0xC);
    if ((markerId == 0) || (*(gTrackMarkerDone + markerId) == M2C_FIELD(marker, u8 *, 0xD))) {
        M2C_FIELD(obj, f32 *, 0x3C) += M2C_FIELD(marker, f32 *, 0);
        M2C_FIELD(obj, f32 *, 0x40) += M2C_FIELD(marker, f32 *, 4);
        M2C_FIELD(obj, f32 *, 0x44) += M2C_FIELD(marker, f32 *, 8);
    }
}
