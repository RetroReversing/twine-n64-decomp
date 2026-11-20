/* machine draft (m2c) for gcc-2.7.2-kmc -G0 -mips3 -mgp32 -mfp32 -O2, tried by autopilot */

s32 func_80010958();
s32 saveWaitCommand();
s32 func_80010B60();
s32 saveSubmitCommand();
extern u16 gSaveStatus;
extern char gSaveSlotTable[];
extern s16 gSaveSlot;
extern s32 D_800E0960;
extern u16 *D_800E0964;
extern s32 D_800E0978;
extern s32 gSaveCmdResult;

u16 func_8001233C(void) {
    gSaveStatus = 0;
    saveSubmitCommand(9, (gSaveSlot * 0x68) + gSaveSlotTable, D_800E0978, 0, 0, D_800E0960, D_800E0964, 0);
    if (saveWaitCommand() != 0) {
        return func_80010B60(gSaveCmdResult) & 0xFFFF;
    }
    if ((func_80010958((unsigned)D_800E0964 + 2, D_800E0960 - 2) & 0xFFFF) != *D_800E0964) {
        gSaveCmdResult = -1;
        gSaveStatus = 0x24;
    }
    return gSaveStatus;
}
