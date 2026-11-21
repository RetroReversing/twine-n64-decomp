void refreshSlotMenuLabels(void);
void func_80026424(s32, s32);
s32 func_8002AF30(void *);
void func_8002CB5C(u8);
u16 func_8002CC14();
extern s16 gSaveStatus;
extern s32 sActiveMenu;
extern u8 *gSaveMenuState;
extern u8 D_8010A950;

/* Handles a save menu event code (0 = confirm, 0x2000 = apply option, 0x4000 = check slot, 0x8000 = refresh labels) and returns the next menu state code. */
s32 handleSaveMenuEvent(u16 event, u8 arg1) {
    switch (event) {
    case 0:
        if (func_8002CC14()) {
            gSaveMenuState[0x2C] = 0;
            func_80026424(sActiveMenu, 0x18);
            return 3;
        }
        gSaveStatus = 0x10D;
        func_80026424(sActiveMenu, 0x18);
        return 0x4003;
    case 0x4000:
        if ((u8)func_8002AF30(&D_8010A950) == 1) {
            return 0x2003;
        }
        return 0x8003;
    case 0x2000:
        func_8002CB5C(arg1);
        func_80026424(sActiveMenu, 0x18);
        return 0x8003;
    case 0x8000:
        refreshSlotMenuLabels();
        gSaveMenuState[0x2C] = 0;
        return 3;
    default:
        return 3;
    }
}
