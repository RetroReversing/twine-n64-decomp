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

s32 func_80048734(f32);
s8 clamp_level_step(s32, s32, s8 *);
extern f32 D_800C0740;
extern u8 D_801007CC;
extern u8 D_801007CD;
extern u8 D_801007CE;
extern u8 D_801007CF;
extern u8 D_801007D0;
extern u8 D_801007D1;
extern u8 D_801007D2;
extern u8 D_801007D3;
extern u8 D_801007D4;
extern s8 D_801007D5;
extern u8 D_801096A0;
extern u8 gTrackMarkerDone[];

/* Advances one channel's state machine: waits for the stored byte pair to match, then applies per-channel level deltas. */ void update_channel_state(void *ctrl) {
    u8 *level_ptr;
    s8 any_changed;
    s16 state;
    u8 level;
    u8 cue;
    void *rec;

    state = M2C_FIELD(ctrl, s16 *, 0x7A);
    rec = M2C_FIELD(ctrl, void **, 0x6C);
    switch (state) {                              /* irregular */
    case 0:
        if (*(gTrackMarkerDone + M2C_FIELD(rec, u8 *, 0x10)) != M2C_FIELD(rec, u8 *, 0x11)) {
            M2C_FIELD(ctrl, s16 *, 0x7A) = 1;
            return;
        }
        return;
    case 1:
        if (*(gTrackMarkerDone + M2C_FIELD(rec, u8 *, 0x10)) == M2C_FIELD(rec, u8 *, 0x11)) {
            s8 *flag = &D_801007D5;
            if (*flag != 0) break;
            *flag = 1;
            M2C_FIELD(ctrl, s16 *, 0x7A) = 2;
            return;
        }
        break;
    case 2:
        any_changed = 0;
        level_ptr = &D_801007CC;
        (*level_ptr) += clamp_level_step((*level_ptr), M2C_FIELD(rec, u8 *, 4), &any_changed);
        D_801007CD += clamp_level_step(D_801007CD, M2C_FIELD(rec, u8 *, 5), &any_changed);
        D_801007CE += clamp_level_step(D_801007CE, M2C_FIELD(rec, u8 *, 6), &any_changed);
        D_801007CF += clamp_level_step(D_801007CF, M2C_FIELD(rec, u8 *, 7), &any_changed);
        D_801007D0 += clamp_level_step(D_801007D0, M2C_FIELD(rec, u8 *, 8), &any_changed);
        D_801007D1 += clamp_level_step(D_801007D1, M2C_FIELD(rec, u8 *, 9), &any_changed);
        if (M2C_FIELD(ctrl, u16 *, 0x78) == 0x4E) {
            D_801007D2 += clamp_level_step(D_801007D2, M2C_FIELD(rec, u8 *, 0xA), &any_changed);
            D_801007D3 += clamp_level_step(D_801007D3, M2C_FIELD(rec, u8 *, 0xB), &any_changed);
            D_801007D4 += clamp_level_step(D_801007D4, M2C_FIELD(rec, u8 *, 0xC), &any_changed);
        } else {
            level = M2C_FIELD(rec, u8 *, 0xC);
            if (level != 0) {
                D_801096A0 = level;
            }
            cue = M2C_FIELD(rec, u8 *, 0xB);
            if (cue != 0) {
                D_800C0740 = (f32) cue;
                func_80048734(60.0f);
            }
        }
        if (any_changed == 0) {
            (*(u8 *)&D_801007D5) = 0;
            M2C_FIELD(ctrl, s16 *, 0x7A) = 0;
        }
        break;
    }
}
