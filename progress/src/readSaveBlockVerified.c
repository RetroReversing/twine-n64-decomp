/* machine draft (m2c) for gcc-2.7.2-kmc -G0 -mips3 -mgp32 -mfp32 -O2, tried by autopilot */

s32 computeSaveChecksum();
s32 saveWaitCommand();
s32 getSaveErrorStatus();
s32 saveSubmitCommand();
extern u16 gSaveStatus;
extern char gRumblePaks[];
extern s16 gSaveSlot;
extern s32 gSaveBufferSize;
extern u16 *gSaveBuffer;
extern s32 gSaveRequestSlot;
extern s32 gSaveCmdResult;

/* Reads the current save slot's block into the save buffer and verifies its checksum; returns the save status (0x24 on checksum mismatch). */ s32 readSaveBlockVerified(void) {
    gSaveStatus = 0;
    saveSubmitCommand(9, (gSaveSlot * 0x68) + gRumblePaks, gSaveRequestSlot, 0, 0, gSaveBufferSize, gSaveBuffer, 0);
    if (saveWaitCommand() != 0) {
        return getSaveErrorStatus(gSaveCmdResult) & 0xFFFF;
    }
    if ((computeSaveChecksum((unsigned)gSaveBuffer + 2, gSaveBufferSize - 2) & 0xFFFF) != *gSaveBuffer) {
        gSaveCmdResult = -1;
        gSaveStatus = 0x24;
    }
    return gSaveStatus;
}
