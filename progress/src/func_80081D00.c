extern u8 sBonusSlotEntries[];
void func_80081D00(s32 arg0) { *(sBonusSlotEntries + (arg0 * 0xA0)) = 1; }
