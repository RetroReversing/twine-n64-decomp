/* Thin wrapper that calls restoreValidSlotValues. */ s32 restoreValidSlotValues(); void restoreSaveSlotValuesOnClose(void) { restoreValidSlotValues(); }
