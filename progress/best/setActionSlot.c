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

s32 setActionSlot(u8 *object, u8 action, s32 value)
{
  u8 frame[16];
  s16 i; s16 j;  u16 us;
  s32 id; s32 id3;
 do { if (object != 0) { if ((((u8) (action - 23)) < 2) | (((u8) action) == 25)) { return 0; } j = 1; do { if (object[0x139 + inline_fn(j)] == ((u8) action)) { goto found; } j++; } while (j < 30); id3 = (u8) action; i = gPhaseSlotIds[id3].index; if (i != (-1)) { object[0x1fc + (i * 8)] = 1; } if (((u32) id3) < 31) { j = (u8) action; *((u16 *) ((object + 0x138) + inline_fn(j))) = j | (((u8) value) << 8); found: return 1; } } return 0; } while (0);
}

