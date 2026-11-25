typedef struct { u8 pad[0x18]; s32 key; } Rec;
void refreshSlotMenuLabels(void);
void setSaveMenuState(s32, s32);
Rec ***getMenuEntry(void *, s8);
s32 getSaveEntryByteD(void *);
void setupSaveFileForName(void *);
void requestSaveSlotAfterRefresh(u8);
u16 getSaveSlotHeadersLow16();
s32 lookupDataEntry(s32);
s32 findSubstring(s32, s32);
extern s16 gSaveStatus;
extern s32 sActiveMenu;
extern u8 gSaveMenuObjectPool;
extern u8 *gSaveMenuState;
extern u8 D_8010A950;
extern char D_800D2AC8[];

/* Runs one save-menu command (flags in command) and returns the next menu result code. */
u16 saveMenuHandleCommand(u16 command, u8 arg1) {
    Rec ***pp;
    Rec **p;

    switch (command) {
    case 0:
        setupSaveFileForName(D_800D2AC8);
        if (getSaveSlotHeadersLow16()) {
            setSaveMenuState(sActiveMenu, 0x18);
            return 2;
        }
        pp = getMenuEntry(&gSaveMenuObjectPool, arg1);
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
        if (findSubstring((*p)->key, lookupDataEntry(0x3004)) != 0) {
            return 0x2002;
        }
        gSaveStatus = 0x10E;
        setSaveMenuState(sActiveMenu, 0x18);
        return 0x4002;
    case 0x4000:
        if ((u8)getSaveEntryByteD(&D_8010A950) == 1) {
            return 0x2002;
        }
        return 0x8002;
    case 0x2000:
        requestSaveSlotAfterRefresh(arg1);
        setSaveMenuState(sActiveMenu, 0x18);
        return 0x8002;
    case 0x8000:
        refreshSlotMenuLabels();
        gSaveMenuState[0x2C] = 0;
        return 2;
    default:
        return 2;
    }
}
