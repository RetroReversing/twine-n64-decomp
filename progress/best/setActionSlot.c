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
  s16 i;
  s16 index;
  s32 id;
  if (object != 0)
  {
    id = (u8) action;
    if ((((u8) (action - 23)) < 2) | (id == 25))
    {
      return 0;
    }
    i = 1;
    do
    {
      if (object[0x139 + inline_fn(i)] == ((u8) action))
      {
        goto found;
      }
      i++;
    }
    while (i < 30);
    id = (u8)action;
    index = gPhaseSlotIds[id].index;
    if (index != (-1))
    {
      object[0x1fc + (index * 8)] = 1;
    }
    if ((u32)id < 31)
    {
      *((u16 *) ((object + 0x138) + inline_fn(id))) = id | ((u8)value << 8);
      found:
      return 1;

    }
  }
  return 0;
}


