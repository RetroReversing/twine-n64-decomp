extern void func_80027E00(void);
extern void func_80027E88(void);
extern void func_80027EB4(void);
extern void func_80027EF4(void);
extern void func_80027F44(void);
extern void updateMenuState(void);
extern void func_80028158(void);
extern void func_800281E0(void);
extern void func_800282D0(void);
extern void func_800283B0(void);
extern void func_80028458(void);
extern void func_80028530(void);
extern void menuStateTimedUpdate(void);
extern void func_80028770(void);
extern void func_800287DC(void);
extern void func_80028A7C(void);
extern void func_80028E6C(void);
extern void func_80028EC8(void);
extern void func_80028F90(void);
extern u8 sMenuListKind;
extern u8 gMenuSlot;
extern u8 gMenuParamB;
extern void *sActiveMenu;
extern void *gMenuState;

/* Loads the menu's state data into globals and calls the handler for its state id, unless the menu's flag bit 0 is set. */ void dispatchMenuState(void *menu) {
    s32 stateId;
    void *stateData;

    if (!(*(s32 *)((u8 *)menu + 0x60) & 1)) {
        stateData = *(void **)((u8 *)menu + 0x6C);
        stateId = *(s16 *)((u8 *)menu + 0x7A);
        gMenuSlot = *(u8 *)((u8 *)stateData + 4);
        gMenuParamB = *(u8 *)((u8 *)stateData + 5);
        sMenuListKind = *(u8 *)((u8 *)stateData + 6);
        sActiveMenu = menu;
        gMenuState = stateData;
        switch (stateId) {
        case 0:
            func_80027E00();
            break;
        case 17:
            func_80027E88();
            break;
        case 12:
            func_80028530();
            break;
        case 16:
            func_80027EB4();
            break;
        case 2:
        case 3:
        case 4:
        case 5:
        case 6:
        case 7:
        case 8:
            func_80027F44();
            break;
        case 1:
            func_80027EF4();
            break;
        case 9:
            updateMenuState();
            break;
        case 11:
            func_80028458();
            break;
        case 13:
            func_80028158();
            break;
        case 14:
            func_800282D0();
            break;
        case 15:
            func_800283B0();
            break;
        case 10:
            func_800281E0();
            break;
        case 20:
            menuStateTimedUpdate();
            break;
        case 21:
            func_80028770();
            break;
        case 22:
            func_800287DC();
            break;
        case 23:
            func_80028A7C();
            break;
        case 24:
            func_80028E6C();
            break;
        case 19:
            func_80028EC8();
            break;
        case 18:
            func_80028F90();
            break;
        }
    }
}
