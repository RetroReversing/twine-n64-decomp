s32 initTextFromTemplate();
s32 func_800283B0();
s32 func_8002B02C();
s32 advanceTimerRecord();
s32 func_8002B150();
s32 func_8002EFD8();
s32 func_8002F068();
s32 func_8002F240();
s32 menuTimeoutTransition();
s32 updateObjectFade();
s32 decayObjectTimers();
s32 updateMenuAnimation();
s32 func_8002FBD4();
s32 func_8003099C();
s32 func_80081730();
s32 func_80087E74();
extern u16 sMenuAnimFlags;
extern char sMenuTextTemplates[];
extern s32 sMenuTextRecord;
extern s8 gMenuOutcome;
extern char sMenuTimer[];
extern u8 sSaveMenuFlag;
extern u8 D_80102EE0;
extern u8 sDifficultyLevel;
extern char D_80102EFC[];

typedef struct { s32 w[9]; } __W36;
/* Runs one frame of the menu state machine: dispatches on the menu state at +0x7A, advances text, and sets the outcome when done. */
void updateMenuStateMachine(void *arg0, void *arg1) {
    s16 menuState;
    u16 nextFrame;

    updateMenuAnimation();
    menuState = *(s16 *)((char *)arg1 + 0x7A);
    switch (menuState) {
    case 0:
        func_8002EFD8(arg0, arg1);
        menuTimeoutTransition(arg0, arg1);
        return;
    case 5:
        func_8002F068(arg0, arg1);
        menuTimeoutTransition(arg0, arg1);
        return;
    case 6:
        if (updateObjectFade(arg0) & 0xFF) {
            func_8002FBD4(arg1, 4);
        } else {
        default:
        tail:
        }
        menuTimeoutTransition(arg0, arg1);
        return;
    case 4:
        updateObjectFade(arg0);
        if (sSaveMenuFlag != 0) {
            advanceTimerRecord(sMenuTimer, 1);
        }
        if (!(func_80081730() & 0xFFFF)) {
            goto tail;
        }
        goto block_19;
    case 3:
        func_8002FBD4(arg1, 1);
        menuTimeoutTransition(arg0, arg1);
        return;
    case 1:
        if (decayObjectTimers(arg0) & 0xFF) {
            func_8002FBD4(arg1, 2);
        }
        menuTimeoutTransition(arg0, arg1);
        return;
    case 7:
        if (decayObjectTimers(arg0) & 0xFF) {
            nextFrame = sMenuAnimFlags + 1;
            sMenuAnimFlags = nextFrame;
            *(__W36 *)&sMenuTextRecord = *(__W36 *)(sMenuTextTemplates + (nextFrame & 1) * 0x24);
            {
            s32 t = *(s32 *)((char *)arg0 + 0x2C);
            sMenuAnimFlags += 1;
            initTextFromTemplate(t, &sMenuTextRecord);
            }
            func_8002FBD4(arg1, 0);
        }
        menuTimeoutTransition(arg0, arg1);
        return;
    case 8:
        func_8002F240(arg0, arg1);
        menuTimeoutTransition(arg0, arg1);
        return;
    case 9:
        updateObjectFade(arg0);
block_19:
        func_8002B150(sMenuTimer, 0, 0);
        menuTimeoutTransition(arg0, arg1);
        return;
    case 11:
        if (decayObjectTimers(arg0) & 0xFF) {
            func_8002B02C(D_80102EFC);
            func_800283B0();
            gMenuOutcome = 2;
            func_80087E74();
            func_8003099C(D_80102EE0, sDifficultyLevel);
            return;
        }
        menuTimeoutTransition(arg0, arg1);
        return;
    }
}
