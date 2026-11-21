extern s32 gSaveSlotCount[];
extern s32 gSaveExtraSlotCount;
typedef struct 
{
  u8 id;
  u8 pad[23];
} Slot_801001A1;
extern Slot_801001A1 sSaveSlotTable[];
volatile int func_80019A3C(void)
{
  volatile s32 *base;
  volatile s32 *first;
  s32 id;
  s32 idx;
  s32 zero;
  s32 found;
  s32 firstPresent;
  s32 count;
  s32 key;
  long firstCount;
  id = 0;
  first = gSaveSlotCount;
  base = first + 1;
  firstCount = *first;
  firstPresent = (s16) (zero < firstCount);
  zero = 0;
  found = 0;
  outer:
  idx = 0;

  if (firstPresent)
  {
    if (zero)
    {
      key = (u16) id;
      count = gSaveSlotCount[0];
    }
    else
    {
      key = (u16) id;
      count = gSaveSlotCount[0];
    }
    first_loop:
    if (sSaveSlotTable[(u16) idx].id != key)
    {
      idx++;
      if (count > ((u16) idx))
      {
        goto first_loop;
      }
    }
    else
    {
      found = 1;
    }

  }
  second_scan:
  idx = 0;

  if (zero < (*base))
  {
    key = (u16) id;
    count = (u32) gSaveExtraSlotCount;
    second_loop:
    if (sSaveSlotTable[((u16) (idx++)) + 4].id == key)
    {
      goto set_found;
    }

    if (((u16) idx) < count)
    {
      goto second_loop;
    }
  }
  check:
  if (((u16) found) != 0)
  {
    goto next_id;
  }

  return 0;
  set_found:
  found = 1;

  goto check;
  next_id:
  id++;

  found = 0;
  if (((u16) id) < 2)
  {
    goto outer;
  }
  return 1;
}

