/* machine draft (m2c) for gcc-2.7.2-kmc -G0 -mips3 -mgp32 -mfp32 -O2, tried by autopilot */

s32 computeSaveChecksum();
s32 saveWaitCommand();
s32 getSaveErrorStatus();
s32 saveSubmitCommand();
extern u16 gSaveStatus;
extern char gSaveSlotTable[];
extern s16 gSaveSlot;
extern s32 D_800E0960;
extern u16 *D_800E0964;
extern s32 gSaveRequestSlot;
extern s32 gSaveCmdResult;

u16 readSaveBlockVerified(void) {
    gSaveStatus = 0;
    saveSubmitCommand(9, (gSaveSlot * 0x68) + gSaveSlotTable, gSaveRequestSlot, 0, 0, D_800E0960, D_800E0964, 0);
    if (saveWaitCommand() != 0) {
        return getSaveErrorStatus(gSaveCmdResult) & 0xFFFF;
    }
    if ((computeSaveChecksum((unsigned)D_800E0964 + 2, D_800E0960 - 2) & 0xFFFF) != *D_800E0964) {
        gSaveCmdResult = -1;
        gSaveStatus = 0x24;
    }
    return gSaveStatus;
}
