/* machine draft (m2c) for gcc-2.7.2-kmc -G0 -mips3 -mgp32 -mfp32 -O2, tried by autopilot */

s32 func_800160FC();
s32 func_800162BC();
s32 func_80018318();
s32 func_80022A30();
s32 func_80022AD8();
s32 func_80026004();
s32 func_800262A8();
s32 func_8002A644();
s32 func_8002A7CC();
s32 func_8002A9A8();
s32 func_8002AC04();
s32 func_8002ACB4();
void *func_80087100();
s32 sprintf();
extern s16 D_800B60E2;
extern s32 *D_800B60E4;
extern s16 D_800B60E8;
extern u8 D_800BD68E;
extern u8 D_800BD68F;
extern char D_800BDBD0[];
extern char D_800CE92C[];
extern char D_800CE984[];
extern char D_800E0C70[];
extern char D_800E0C98[];
extern char D_800E0E40[];
extern char D_800E0ED4[];
extern u8 D_80102EE8;
extern s32 func_8001EA6C;
extern s32 func_8001EAF0;

extern char D_800D2A80[];
/* Sets up the menu list at D_800E0C70 and fills one text entry per item in the table for the current mode. */ void func_80020F84(void) {
    s32 *entryTable;
    void *entryText;
    s32 entryIndex;
    register s32 resultHandle;
    unsigned long entryHandle;
    s32 entryCounter;
    s32 *entrySlot;
    u32 entryCount;

    D_800B60E2 = 3;
    D_800B60E4 = D_800E0C70;
    func_8002A644(D_800E0C70, D_800E0C98, 0x1A4, 0xB, 0x2D, 0xB4, 0x4C, 0xB, 0, &func_8001EA6C, &func_8001EAF0);
    D_800B60E8 = 0;
    resultHandle = func_800262A8(D_800BDBD0, 0x4000);
    if (resultHandle) {
        { func_80022A30(D_800BD68E, 0x2D, 0x46, 0xDC, 0x7F); }
        entryTable = NULL;
        func_80026004(resultHandle, "%s", func_80087100(*(u16 *)(D_800E0ED4 + (D_800BD68F * 2)) | 0x7000));
        entryCount = 0;
        switch (D_80102EE8) {                       /* irregular */
        case 0:
            entryTable = D_800CE92C;
            entryCount = 5;
            break;
        case 1:
            entryTable = D_800CE984;
            entryCount = 6;
            break;
        case 2:
            entryTable = D_800CE984;
            entryCount = 6;
            break;
        }
        entryCounter = 0;
        if (entryCount) {
            do {
                entryHandle = func_800162BC(D_800BD68E);
                entryIndex = entryCounter & 0xFFFF;
                entrySlot = (entryIndex * 4) + D_800E0E40;
                *entrySlot = entryHandle;
                if (entryHandle != 0) {
                    entryText = func_80087100((entryCounter + 0x4002) & 0xFFFF);
                    (*(s8 *)((char *)(entryText) + 0)) = 3;
                    (*(s8 *)((char *)(entryText) + 1)) = 0x6E;
                    sprintf(entryText + 2, D_800D2A80, func_80087100((*(u16 *)((char *)entryTable + entryIndex * 8 + 6))));
                    func_800160FC(*entrySlot, entryText, 0x40);
                    func_8002A7CC(D_800B60E4, *entrySlot, entryCounter & 0xFF, func_80018318(*entrySlot) & 0xFF);
                }
                ++entryCounter;
            } while ((u32) (entryCounter & 0xFFFF) < entryCount);
        }
        func_80022AD8(D_800BD68E);
        func_8002A9A8(D_800B60E4, 0);
        func_8002AC04(D_800B60E4, 1);
        func_8002ACB4(D_800B60E4);
    }
}
