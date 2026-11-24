extern char gBonusSlotValueBase[];
void setBonusSlotState();
/* Resets the slot's 16-bit value (stride 0xA0) to -1 and passes the old value to setBonusSlotState. */ void clearBonusSlotValue(s32 slot) {
 s32 offset = slot * 0xA0;
 s32 oldValue = *(s16 *)(gBonusSlotValueBase + offset);
 *(s16 *)(gBonusSlotValueBase + offset) = -1;
 setBonusSlotState(slot, oldValue);
}
