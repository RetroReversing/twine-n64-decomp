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

s32 effectSetAnimFrame();
extern char gTrackMarkerDone[];

/* Sets an effect's animation frame from packed marker data; the frame offset is flipped by the marker's done flag. */ void setEffectFrameFromMarker(void *effect) {
    s32 frameOffset;
    u32 packed;
    void *markerInfo;

    markerInfo = M2C_FIELD(effect, void **, 0x6C);
    packed = M2C_FIELD(markerInfo, u32 *, 0);
    frameOffset = M2C_FIELD(markerInfo, u8 *, 5) ^ (*(gTrackMarkerDone + M2C_FIELD(markerInfo, u8 *, 4)) & 1);
    effectSetAnimFrame(effect, ((packed >> 4) & 0xFFFF) + frameOffset, packed >> 0x14, frameOffset);
}
