typedef struct 
{
  s16 index;
  u8 pad[14];
} ActionRecord706;
extern ActionRecord706 gPhaseSlotIds[];
inline static int inline_fn(s16 arg0)
{
  return arg0 * 2;
}

/* Registers an action in the actor's slot table (30 entries) unless already present; returns 1 on success, 0 if rejected. */ s32 setActionSlot(u8 *actor, u8 actionId, s32 param)
{
  u8 unusedFrame[16];
  s16 slotIndex; s16 slot;  u16 us;
  s32 actionIndex; u8 *slotRecord;
 do { if (actor != 0) { if ((((u8) (actionId - 23)) < 2) | (((u8) actionId) == 25)) { return 0; } actionIndex = (u8) actionId; slot = 1; do { if (actor[0x139 + inline_fn(slot)] == ((u8) actionId)) { goto found; } slot++; } while (slot < 30); actionIndex = (u8) actionId; slotIndex = gPhaseSlotIds[actionIndex].index; if (slotIndex != (-1)) { slotRecord = actor + (slotIndex * 8); slotRecord[0x1fc] = 1; } slot = (u8) actionId; if (((u32) actionIndex) < 31) { *((u16 *) ((actor + 0x138) + inline_fn(slot))) = slot | (((u8) param) << 8); found: return 1; } } return 0; } while (0);
}


