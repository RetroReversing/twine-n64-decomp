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
s32 func_8002B180();
s16 timerGetTotalSeconds();
s16 strlen();
extern s32 D_800BD65C;
extern s32 D_800BD66C;
extern u8 D_801002AC;
extern char sRaceTimer[];
extern s16 D_801002D0;
extern u8 gMenuUseTextList;
extern char D_8011F0D4[];
extern s32 D_8011F3A8;
extern void *D_8011F3B8;

/* Advances the race timer by frameDelta, then updates the HUD text, colour and warning sound. */ void updateRaceTimerHud(s16 frameDelta) {
    s32 textColor;
    u8 warnFlag;
    void *hudElement;

    if (gMenuUseTextList != 0) {
        advanceTimerRecord(sRaceTimer, frameDelta);
        if ((timerGetTotalSeconds(sRaceTimer - 8) << 0x10) != 0) {
            if (D_801002AC == 0) {
                warnFlag = (timerGetTotalSeconds(sRaceTimer) << 0x10) < 1;
                D_801002AC = warnFlag;
                if (warnFlag & 0xFF) {
                    D_8011F3A8 = 0x1E;
                }
            }
            if ((timerGetTotalSeconds(sRaceTimer) < 0xB) && (D_801002D0 == 0)) {
                requestSound(0x123);
            }
            hudElement = D_8011F3B8;
            if (hudElement != NULL) {
                if (timerGetTotalSeconds(sRaceTimer) < 0x3C) {
                    textColor = D_800BD65C;
                } else {
                    textColor = D_800BD66C;
                }
                M2C_FIELD(hudElement, s32 *, 0x10) = textColor;
                func_8002B180(sRaceTimer, D_8011F0D4);
                M2C_FIELD(hudElement, s16 *, 0x1C) = strlen(D_8011F0D4);
            }
        }
    }
}
