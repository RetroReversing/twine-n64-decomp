s32 initTextFromTemplate();
s32 closeSaveMenu();
s32 clearEntryHeader();
s32 advanceTimerRecord();
s32 initTimer();
s32 fadeInColorAlpha();
s32 updateMenuCursorPulse();
s32 enterSaveMenuConfirmState();
s32 menuTimeoutTransition();
s32 updateObjectFade();
s32 decayObjectTimers();
s32 updateMenuAnimation();
s32 setStateMachineState();
s32 loadMapEntries();
s32 getUpdatePendingFlag();
s32 loadNextMenuBackdrop();
extern u16 sMenuAnimFlags;
extern char sMenuTextTemplates[];
extern s32 sMenuTextRecord;
extern s8 gMenuOutcome;
extern char sMenuTimer[];
extern u8 sSaveMenuFlag;
extern u8 gCurrentItemId;
extern u8 sDifficultyLevel;
extern char sProbeTimer[];

typedef struct { s32 w[9]; } __W36;
/* Runs one frame of the menu state machine: dispatches on the menu state at +0x7A, advances text, and sets the outcome when done. */
void updateMenuStateMachine(void *arg0, void *arg1) {
    s16 menuState;
    u16 nextFrame;

    updateMenuAnimation();
    menuState = *(s16 *)((char *)arg1 + 0x7A);
    switch (menuState) {
    case 0:
        fadeInColorAlpha(arg0, arg1);
        menuTimeoutTransition(arg0, arg1);
        return;
    case 5:
        updateMenuCursorPulse(arg0, arg1);
        menuTimeoutTransition(arg0, arg1);
        return;
    case 6:
        if (updateObjectFade(arg0) & 0xFF) {
            setStateMachineState(arg1, 4);
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
        if (!(getUpdatePendingFlag() & 0xFFFF)) {
            goto tail;
        }
        goto block_19;
    case 3:
        setStateMachineState(arg1, 1);
        menuTimeoutTransition(arg0, arg1);
        return;
    case 1:
        if (decayObjectTimers(arg0) & 0xFF) {
            setStateMachineState(arg1, 2);
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
            setStateMachineState(arg1, 0);
        }
        menuTimeoutTransition(arg0, arg1);
        return;
    case 8:
        enterSaveMenuConfirmState(arg0, arg1);
        menuTimeoutTransition(arg0, arg1);
        return;
    case 9:
        updateObjectFade(arg0);
block_19:
        initTimer(sMenuTimer, 0, 0);
        menuTimeoutTransition(arg0, arg1);
        return;
    case 11:
        if (decayObjectTimers(arg0) & 0xFF) {
            clearEntryHeader(sProbeTimer);
            closeSaveMenu();
            gMenuOutcome = 2;
            loadNextMenuBackdrop();
            loadMapEntries(gCurrentItemId, sDifficultyLevel);
            return;
        }
        menuTimeoutTransition(arg0, arg1);
        return;
    }
}
