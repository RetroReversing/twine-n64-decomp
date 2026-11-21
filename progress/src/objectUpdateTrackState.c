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
s32 randomU32Next();
extern f64 D_800D4258;
extern u8 sTrackDoneFlags[];

/* Advances an object's track state: 0 waits for its done flag, 1 drifts scale/alpha randomly until a frame limit, 2 idles. */ void objectUpdateTrackState(void *obj) {
    f64 rndF;
    s16 state;
    s32 rnd;
    u32 animWord;
    u32 animWord2;
    void *track;

    state = M2C_FIELD(obj, s16 *, 0x7A);
    track = M2C_FIELD(obj, void **, 0x6C);
    switch (state) {                              /* irregular */
    case 0:
        if (*(sTrackDoneFlags + M2C_FIELD(track, u8 *, 4)) == M2C_FIELD(track, u8 *, 5)) {
            *(sTrackDoneFlags + M2C_FIELD(track, u8 *, 6)) = 1;
            animWord = M2C_FIELD(track, u32 *, 0);
            objectSetAnimFrame(obj, ((animWord >> 4) & 0xFFFF) + 1, animWord >> 0x14);
            M2C_FIELD(obj, s16 *, 0x7A) = 1;
            M2C_FIELD(obj, u16 *, 0x7C) = 0U;
            return;
        }
        return;
    case 1:
        M2C_FIELD(obj, u16 *, 0x7C) += 1;
        rnd = randomU32Next() & 0xFF;
        rndF = (f64) rnd;
        if (rnd < 0) {
            rndF += D_800D4258;
        }
        M2C_FIELD(obj, f32 *, 0x54) = (f32) ((((f32) rndF - 128.0f) * 0.00015625f) + 1.0f);
        M2C_FIELD(obj, u8 *, 0x82) = (u8) ((u32) (M2C_FIELD(obj, u8 *, 0x82) + (randomU32Next() & 0xFF)) >> 1);
        if ((s16) M2C_FIELD(obj, u16 *, 0x7C) >= 0xA8D) {
            animWord2 = M2C_FIELD(track, u32 *, 0);
            objectSetAnimFrame(obj, (animWord2 >> 4) & 0xFFFF, animWord2 >> 0x14);
            *(sTrackDoneFlags + M2C_FIELD(track, u8 *, 6)) = 0;
            M2C_FIELD(obj, s16 *, 0x7A) = 2;
        }
        break;
    case 2:
        break;
    }
}
