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

s32 requestSound();
s32 advanceTimerRecord();
s32 formatTimeString();
s16 timerGetTotalSeconds();
s16 strlen();
extern s32 D_800BD65C;
extern s32 gMenuTimerColor;
extern u8 gBonusGoalReached;
extern char sRaceTimer[];
extern s16 D_801002D0;
extern u8 gMenuUseTextList;
extern char gMenuTimerText[];
extern s32 gBonusEndDelayFrames;
extern void *gMenuItemList;

/* Advances the race timer by frameDelta, then updates the HUD text, colour and warning sound. */ void updateRaceTimerHud(s16 frameDelta) {
    s32 textColor;
    u8 warnFlag;
    void *hudElement;

    if (gMenuUseTextList != 0) {
        advanceTimerRecord(sRaceTimer, frameDelta);
        if ((timerGetTotalSeconds(sRaceTimer - 8) << 0x10) != 0) {
            if (gBonusGoalReached == 0) {
                warnFlag = (timerGetTotalSeconds(sRaceTimer) << 0x10) < 1;
                gBonusGoalReached = warnFlag;
                if (warnFlag & 0xFF) {
                    gBonusEndDelayFrames = 0x1E;
                }
            }
            if ((timerGetTotalSeconds(sRaceTimer) < 0xB) && (D_801002D0 == 0)) {
                requestSound(0x123);
            }
            hudElement = gMenuItemList;
            if (hudElement != NULL) {
                if (timerGetTotalSeconds(sRaceTimer) < 0x3C) {
                    textColor = D_800BD65C;
                } else {
                    textColor = gMenuTimerColor;
                }
                M2C_FIELD(hudElement, s32 *, 0x10) = textColor;
                formatTimeString(sRaceTimer, gMenuTimerText);
                M2C_FIELD(hudElement, s16 *, 0x1C) = strlen(gMenuTimerText);
            }
        }
    }
}
