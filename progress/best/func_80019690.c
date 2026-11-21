
s32 func_8000A29C();
s32 requestSound();
s32 func_8000C8BC();
s32 func_80011938();
s32 getSaveSlotIndex();
s32 func_80026424();
s32 func_80027C60();
s32 updateActiveMenuState();
s32 func_8002B02C();
s32 func_8002B9CC();
s32 func_8003099C();
s32 func_80045130();
s32 func_80081CC0();
extern char gSharedItemId[];
extern s8 D_800BD690;
extern s16 gSaveStatus;
extern char D_800C3CF8[];
extern s8 D_800CA338;
extern char gSaveSlotInfo[];
extern s8 D_801002A3;
extern u8 D_801002A4;
extern s8 D_801002AC;
extern s8 gPickupSavedByte;
extern volatile s32 gSaveTotalSlots;
extern s32 D_801002C4;
extern s32 D_801002C8;
extern s32 sRaceTimer;
extern s32 D_801002D0;
extern s16 D_80102CBC;
extern s16 D_80102CBE;
extern s16 D_80102CC0;
extern s32 gBorderSkipFlag;
extern s8 gMenuUseTextList;
extern u8 D_80102EE0;
extern u8 sDifficultyLevel;
extern s32 D_80102EF0;
extern char D_80102EFC[];
extern void *sActiveMenu;
extern void *gMenuItems;
extern s32 D_8010A4E4;

void func_80019690(void) {
    char *__base_D_800C3CF8;
    void *p;
    s32 i;
    unsigned k;
    register s32 sw;

    p = (*(void **)((char *)(gMenuItems) + 0x18));
    (*(u8 *)((char *)(p) + 0x1C)) |= 0x10;
    if (func_80027C60(0x23) & 0xFF) {
        (*(u8 *)((char *)(gMenuItems) + 0x2C)) = 1;
        (*(s8 *)((char *)(gMenuItems) + 0x2F)) = 1;
    }
    if ((*(u8 *)((char *)(gMenuItems) + 0x2C)) == 0) {
        updateActiveMenuState();
        return;
    }
    if ((*(s32 *)((char *)((*(void **)((char *)(gMenuItems) + 0x18))) + 0x14)) != 0 && gSaveTotalSlots < 2) {
        (*(u8 *)((char *)(gMenuItems) + 0x2C)) = 0;
        requestSound(0xEA);
        return;
    }
    if (sActiveMenu != NULL && (*(s16 *)((char *)(sActiveMenu) + 0x7A)) != 0xF) {
        if ((*(s16 *)((char *)(sActiveMenu) + 0x7A)) != 0xE) {
            (*(s16 *)((char *)(sActiveMenu) + 0x7A)) = 0xE;
            gSaveStatus = 0x60;
            func_80026424(sActiveMenu, 0x18);
            D_800BD690 = 0;
        }
    } else {
        func_8003099C(D_80102EE0, sDifficultyLevel);
        gMenuUseTextList = 1;
        p = (*(void **)((char *)(gMenuItems) + 0x18));
        if ((*(s32 *)((char *)(p) + 0x10)) != 0) {
            gBorderSkipFlag = (*(s32 *)((char *)(p) + 0x14));
        }
        if (gBorderSkipFlag != 0) {
            D_801002AC = 0;
            D_801002A3 = 0;
            gPickupSavedByte = 0;
            sRaceTimer = D_801002C4;
            D_801002D0 = D_801002C8;
            D_80102EF0 = 0;
            i = 0;
            if (gSaveTotalSlots > 0) {
                do {
                    s32 row = getSaveSlotIndex((u16)i);
                    s32 key = *(s32 *)(((u16)row * 3 << 3) + (u32)gSaveSlotInfo);
                    s32 index = func_8002B9CC(key);
                    *(s16 *)(gSharedItemId + (u16)i * 2) = **(u16 **)(D_800C3CF8 + (index * 3 << 2));
                    i++;
                } while ((i & 0xFFFF) < gSaveTotalSlots);
            }
            *(s16 *)(gSharedItemId + ((i & 0xFFFF) * 2)) = -1;
            k = 0;
        } else {
            D_80102EF0 = 1;
            k = 0;
        }
        do {
            func_80081CC0(k & 0xFFFF);
            func_80011938(k & 0xFFFF, 0);
            k++;
        } while ((k & 0xFFFF) < 4);
        func_8002B02C(D_80102EFC);
        func_8000A29C();
        D_80102CBC = 0;
        D_80102CBE = 0;
        D_80102CC0 = 0;
        D_8010A4E4 = 0;
        if (gBorderSkipFlag != 0) {
            D_800CA338 = 0;
            func_80045130(D_801002A4);
            return;
        }
        switch (D_80102EE0) {
        default:
            D_800CA338 = 0;
            sw = -1;
            func_80045130(D_80102EE0);
            break;
        case 2: sw = 4; break;
        case 20: sw = 0x10; break;
        case 16: sw = 0xE; break;
        case 34: sw = 0x22; break;
        case 25: sw = 0x11; break;
        case 38: sw = 0x2C; break;
        case 1: sw = 1; break;
        case 11: sw = 8; break;
        case 41: sw = 0x2F; break;
        case 40: sw = 0x31; break;
        case 28: sw = 0xC; break;
        case 18: sw = 0x25; break;
        case 29: sw = 0x18; break;
        case 33: sw = 0x1A; break;
        }
        if (sw >= 0) {
            func_8000C8BC(sw);
        }
    }
}
