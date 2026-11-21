typedef struct { u8 pad[0x18]; s32 key; } Rec;
void refreshSlotMenuLabels(void);
void func_80026424(s32, s32);
Rec ***func_8002A920(void *, s8);
s32 func_8002AF30(void *);
void func_8002CA90(void *);
void func_8002CB2C(u8);
u16 func_8002CC14();
s32 lookupDataEntry(s32);
s32 func_800AB950(s32, s32);
extern s16 gSaveStatus;
extern s32 sActiveMenu;
extern u8 D_80107EA8;
extern u8 *gMenuItems;
extern u8 D_8010A950;
extern char D_800D2AC8[];

/* Runs one save-menu command (flags in command) and returns the next menu result code. */
s32 saveMenuHandleCommand(u16 command, u8 arg1) {
    Rec ***pp;
    Rec **p;

    switch (command) {
    case 0:
        func_8002CA90(D_800D2AC8);
        if (func_8002CC14()) {
            func_80026424(sActiveMenu, 0x18);
            return 2;
        }
        pp = func_8002A920(&D_80107EA8, arg1);
        if (pp == NULL) {
            return 0x8002;
        }
        p = *pp;
        if (p == NULL) {
            return 0x8002;
        }
        if ((*p)->key == 0) {
            return 0x8002;
        }
        if (func_800AB950((*p)->key, lookupDataEntry(0x3004)) != 0) {
            return 0x2002;
        }
        gSaveStatus = 0x10E;
        func_80026424(sActiveMenu, 0x18);
        return 0x4002;
    case 0x4000:
        if ((u8)func_8002AF30(&D_8010A950) == 1) {
            return 0x2002;
        }
        return 0x8002;
    case 0x2000:
        func_8002CB2C(arg1);
        func_80026424(sActiveMenu, 0x18);
        return 0x8002;
    case 0x8000:
        refreshSlotMenuLabels();
        gMenuItems[0x2C] = 0;
        return 2;
    default:
        return 2;
    }
}
