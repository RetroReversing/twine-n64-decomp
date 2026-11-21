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

s32 objectSetAnimFrame();
s32 func_80084338();
extern char gTrackMarkerDone[];

/* Advances the object's track state machine (0 idle, 1 start, 2 playing) and syncs its track done flags. */ void updateObjectTrackState(void *obj) {
    s16 state;
    u16 callArg;
    u16 trackIdx3;
    u16 trackIdx;
    u16 trackIdx2;
    u8 doneFlag;
    void *def;

    def = M2C_FIELD(obj, void **, 0x6C);
    if (M2C_FIELD(def, u16 *, 0x3A) == 1) {
        doneFlag = *(gTrackMarkerDone + M2C_FIELD(def, u16 *, 0x34));
        if (doneFlag < 2U) {
            objectSetAnimFrame(obj, M2C_FIELD(def, u16 *, 0x3C) + doneFlag, M2C_FIELD(def, u16 *, 0x3E));
        }
    }
    if (M2C_FIELD(obj, s32 *, 0x60) & 0x100000) {
        M2C_FIELD(obj, s32 *, 0x60) = 0;
    }
    state = M2C_FIELD(obj, s16 *, 0x7A);
    switch (state) {                            /* irregular */
    case 0:
        if (M2C_FIELD(obj, s32 *, 0x60) & M2C_FIELD(def, s32 *, 0x2C)) {
            M2C_FIELD(obj, s16 *, 0x7A) = 1;
            trackIdx = M2C_FIELD(def, u16 *, 0x34);
            if (trackIdx != 0) {
                *(gTrackMarkerDone + trackIdx) = 2;
            }
        }
        break;
    case 1:
        trackIdx2 = M2C_FIELD(def, u16 *, 0x34);
        if (trackIdx2 != 0) {
            *(gTrackMarkerDone + trackIdx2) = 1;
        }
        callArg = M2C_FIELD(def, u16 *, 0x36);
        if (callArg != 0) {
            func_80084338(callArg, obj + 0x24);
        }
        M2C_FIELD(obj, s16 *, 0x7A) = 2;
        break;
    case 2:
        trackIdx3 = M2C_FIELD(def, u16 *, 0x34);
        if (trackIdx3 != 0) {
            *(gTrackMarkerDone + trackIdx3) = 0;
        }
        if (!(M2C_FIELD(obj, s32 *, 0x60) & M2C_FIELD(def, s32 *, 0x2C))) {
            M2C_FIELD(obj, s16 *, 0x7A) = 0;
        }
        break;
    }
    M2C_FIELD(obj, s32 *, 0x60) &= 1;
}
