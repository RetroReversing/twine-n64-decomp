s32 saveWaitCommand(void);
s32 saveFindTaggedSlot(void);
u16 func_80010B60(u32);
u16 saveVerifySlot(void);
s32 saveSubmitCommand(u16, void *, s16, s32, s32, s32, s32, s32);
s32 func_80012F50(void);
extern u16 gSaveStatus;
extern u16 D_800E0768[4];
extern u8 D_800E076A[16];
extern u8 D_800E076B[16];
extern u8 gSaveSlotTable[];
extern s16 D_800E0938, gSaveSlot, D_800E093C, D_800E093E;
extern s16 gSaveSlotFlags[4];
extern s32 gSaveCmdResult;
extern s16 D_801083D4[4];
extern u8 D_80108F75;
extern s16 gSaveSlotLoaded[4], gSaveSlotValid[4];
extern s8 gSaveSlotCodeBuf, D_8010A3C6, D_8010A3C7, D_8010A3C8;
u16 func_80012C70(void) {
    u8 *__base_D_800E0790;
    s32 state = -1;
    gSaveSlotCodeBuf = 0; D_8010A3C6 = 0; D_8010A3C7 = 0; D_8010A3C8 = 0;
    D_800E093E = 0;
    gSaveSlot = 0;
    D_800E093C = -1;
    D_800E093E = 0;
    D_800E0938 = -1;
    saveSubmitCommand(0xD, 0, 0, 0, 0, 0, 0, 0);
    saveWaitCommand();
    gSaveSlot = 0;
    for (;;) {
        s32 i = gSaveSlot;
        gSaveSlotFlags[i] = 0;
        gSaveSlotLoaded[i] = 0;
        D_801083D4[i] = 0;
        gSaveSlotValid[i] = 0;
        if (D_800E076B[i * 4] == 0 &&
            (D_80108F75 >> i) != 0 &&
            ((D_800E0768[i * 2] & 0x1F07) != 5 || (gSaveSlotFlags[i] = 1, (D_800E076A[i * 4] & 1) != 0))) {
            switch ((u32)(saveVerifySlot())) {
            case 0xA4:
                if (state != 0 && gSaveSlot == 0) {
                    state = 0;
                    gSaveSlotLoaded[0] = 1;
                    if (func_80012F50() == 0 && saveFindTaggedSlot() != 0) gSaveStatus = 0x30;
                }
                break;
            case 0xA5:
                __base_D_800E0790 = gSaveSlotTable;
                saveSubmitCommand(0xC, __base_D_800E0790 + gSaveSlot * 0x68, gSaveSlot, 0, 0, 0, 0, 0);
                saveWaitCommand();
                break;
            case 0x20:
                if (gSaveSlot == 0) return func_80010B60(gSaveCmdResult);
                break;
            case 0x12:
                if (gSaveSlot == 0) return 0x12;
                break;
            case 166:
                break;
            }
        }
        gSaveSlot++;
        if (gSaveSlot >= 4) {
            if (state == 0) gSaveSlot = 0;
            else state = -1;
            if (state < 0) gSaveStatus = 0x10;
            return gSaveStatus;
        }
    }
}
