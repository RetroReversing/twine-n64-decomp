s32 isSaveSlotValid(s32);
u16 readSaveBlockVerified(void);
s32 loadSaveSlotHeaders();
extern u16 gSaveStatus;
extern s32 gSaveRequestSlot;
/* Loads the given save slot: reads slot headers, validates the slot, then reads and verifies its save block. Returns the status code. */ s32 loadSaveSlot(s32 slot) {
    s32 temp_a0;
    temp_a0 = slot & 0xFFFF;
    gSaveStatus = 1;
    gSaveRequestSlot = temp_a0;
    if (!(loadSaveSlotHeaders() & 0xFFFF)) {
        if ((isSaveSlotValid(gSaveRequestSlot) == 0) || (gSaveRequestSlot >= 0x10)) {
            gSaveStatus = 0x82;
            return 0x82U;
        }
        if (!(readSaveBlockVerified() & 0xFFFF)) {
            gSaveStatus = 1;
            return 1U;
        }
    }
    return gSaveStatus;
}
