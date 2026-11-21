typedef struct SaveMenuState {
    unsigned char pad_00[20];
    unsigned short choice;      /* 0x14: 1 means the first option was chosen */
    unsigned char pad_16[22];
    unsigned char isOpen;       /* 0x2C */
    unsigned char pad_2D[1];
    unsigned char isBusy;       /* 0x2E: non-zero blocks input */
    signed char pendingClose;   /* 0x2F */
} SaveMenuState;

extern unsigned short sSaveMenuPhase;
extern s8 sSaveMenuFlag;
extern s32 sActiveMenu;
extern void *gSaveMenuState;
s32 func_80026424();
s32 updateActiveMenuState();
s32 func_800294E4();
s32 func_8002CBF4();

/* Steps the save menu phase machine each frame: phase 3 waits for input, phase 4 finishes closing. */
void updateSaveMenuPhase(void) {
    u16 temp_a0;

    if ((((SaveMenuState *)gSaveMenuState)->isOpen == 0) || (((SaveMenuState *)gSaveMenuState)->isBusy != 0)) {
        sSaveMenuPhase = 3U;
        sSaveMenuFlag = ((SaveMenuState *)gSaveMenuState)->choice == 1;
        updateActiveMenuState();
        return;
    }
    temp_a0 = sSaveMenuPhase;
    switch (temp_a0) {                              /* irregular */
    case 3:
        sSaveMenuFlag = 0;
        if (!(func_8002CBF4() & 0xFFFF)) {
            sSaveMenuPhase = 4U;
            return;
        }
        sSaveMenuPhase = 3U;
        ((SaveMenuState *)gSaveMenuState)->isOpen = 0U;
        func_80026424(sActiveMenu, 0x18);
        return;
    case 4:
        ((SaveMenuState *)gSaveMenuState)->pendingClose = 1;
        sSaveMenuPhase = 3U;
        func_800294E4();
        ((SaveMenuState *)gSaveMenuState)->isOpen = 1U;
        return;
    }
}
