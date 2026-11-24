extern u16 gSlotBackupValues[];
extern u16 gSlotValues[];
void resetControllerSlotState(u16);

/* Snapshots each of the 4 controller slots' values into the backup array and resets the slot state. */ void resetAllSlotStates(void) {
    u16 slot;

    for (slot = 0; slot < 4; slot++) {
        gSlotBackupValues[slot] = gSlotValues[slot];
        resetControllerSlotState(slot);
    }
}
