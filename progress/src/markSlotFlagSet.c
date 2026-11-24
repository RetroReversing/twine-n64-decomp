extern u8 sBonusSlots[];
/* Sets the flag byte to 1 in the 0xA0-byte slot at slotIndex. */ void markSlotFlagSet(s32 slotIndex) { *(sBonusSlots + (slotIndex * 0xA0)) = 1; }
