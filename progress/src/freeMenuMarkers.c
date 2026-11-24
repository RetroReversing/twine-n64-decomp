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

M2C_UNK freeMenuItemRecord(s32);                         /* extern */
extern s32 gTrackMarker;
extern s32 gCursorMarker;

/* Frees the track and cursor menu marker records if allocated and clears both pointers. */ void freeMenuMarkers(void) {
    if (gTrackMarker != 0) {
        freeMenuItemRecord(gTrackMarker);
    }
    gTrackMarker = 0;
    if (gCursorMarker != 0) {
        freeMenuItemRecord(gCursorMarker);
    }
    gCursorMarker = 0;
}
