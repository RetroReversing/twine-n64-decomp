extern void resetSaveMenuSlots(void);
extern void loadTableAndSelectCurrentMenuItem(void);
extern void callSaveMenuHandler(void);
extern void updateSaveStatusMenuState(void);
extern void updateMenuTimedTransition(void);
extern void updateMenuState(void);
extern void updateSaveMenuInput(void);
extern void runSaveMenuCallbacks(void);
extern void runSaveMenuIdleState(void);
extern void closeSaveMenu(void);
extern void enterMenuState(void);
extern void enterSaveMenu(void);
extern void menuStateTimedUpdate(void);
extern void updateSaveMenuPage(void);
extern void updateSaveMenuFadeIn(void);
extern void updateSaveMenuFade(void);
extern void handleMenuInputResult(void);
extern void updateSaveMenuState(void);
extern void updateSaveRecoveryMenu(void);
extern u8 sMenuListKind;
extern u8 gMenuSlot;
extern u8 gMenuActiveController;
extern void *sActiveMenu;
extern void *gSaveMenuState;

/* Loads the menu's state data into globals and calls the handler for its state id, unless the menu's flag bit 0 is set. */ void dispatchMenuState(void *menu) {
    s32 stateId;
    void *stateData;

    if (!(*(s32 *)((u8 *)menu + 0x60) & 1)) {
        stateData = *(void **)((u8 *)menu + 0x6C);
        stateId = *(s16 *)((u8 *)menu + 0x7A);
        gMenuSlot = *(u8 *)((u8 *)stateData + 4);
        gMenuActiveController = *(u8 *)((u8 *)stateData + 5);
        sMenuListKind = *(u8 *)((u8 *)stateData + 6);
        sActiveMenu = menu;
        gSaveMenuState = stateData;
        switch (stateId) {
        case 0:
            resetSaveMenuSlots();
            break;
        case 17:
            loadTableAndSelectCurrentMenuItem();
            break;
        case 12:
            enterSaveMenu();
            break;
        case 16:
            callSaveMenuHandler();
            break;
        case 2:
        case 3:
        case 4:
        case 5:
        case 6:
        case 7:
        case 8:
            updateMenuTimedTransition();
            break;
        case 1:
            updateSaveStatusMenuState();
            break;
        case 9:
            updateMenuState();
            break;
        case 11:
            enterMenuState();
            break;
        case 13:
            updateSaveMenuInput();
            break;
        case 14:
            runSaveMenuIdleState();
            break;
        case 15:
            closeSaveMenu();
            break;
        case 10:
            runSaveMenuCallbacks();
            break;
        case 20:
            menuStateTimedUpdate();
            break;
        case 21:
            updateSaveMenuPage();
            break;
        case 22:
            updateSaveMenuFadeIn();
            break;
        case 23:
            updateSaveMenuFade();
            break;
        case 24:
            handleMenuInputResult();
            break;
        case 19:
            updateSaveMenuState();
            break;
        case 18:
            updateSaveRecoveryMenu();
            break;
        }
    }
}
