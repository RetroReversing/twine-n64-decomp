typedef struct 
{
  u8 weight;
  u8 variant;
  u16 id;
} SelectionEntry;
s32 func_80002BD0(void *, s32);
u32 randomIntBelow(s32);
s32 isActionPathClear(void *, s32);
inline static int inline_fn(u8 *arg0, u32 arg1)
{
  return arg0[4] < arg1;
}

/* Rolls a weighted random entry (up to 3 tries) from a cumulative-weight table and starts the first one whose path is clear; returns 1 if started, else 0. */ s32 pickWeightedActorAction(void *actor, SelectionEntry *entries, s32 count)
{
  u8 *details = *((u8 **) (((u8 *) actor) + 0x6C));
  volatile s32 pad;
  volatile s32 weight = entries[count - 1].weight;
  volatile s32 spare;
  u32 attempt = 0;
  u32 index;
  u32 threshold;
  u32 limit;
  u8 *entry;
  unsigned short id;
 do { retry: index = 0; threshold = randomIntBelow(weight); } while (0);
  do
  {
    {
      u32 remaining = count - 1;
      if (remaining == 0)
      {
        goto increment_attempt;
      }
      limit = remaining;
    }
    {
      entry = (u8 *) entries;
      scan:
      if (inline_fn(entry, threshold))
      {
        index++;
        goto advance;
      }

      id = *((u16 *) (entry + 2));
    }
    
    if (id == 0)
    {
      return 0;
    }
    if ((((u32) isActionPathClear(actor, id)) << 24) == 0)
    {
      index++;
      goto advance;
    }
    if ((entry || entries) != 0.0f)
    {
      details[0x7F] = entry[1];
      func_80002BD0(actor, *((u16 *) (entry + 2)));
      return 1;
    }
    else
    {
      details[0x7F] = entry[1];
      func_80002BD0(actor, *((u16 *) (entry + 2)));
      return 1;
    }
    advance:
    entry += 4;

    if (index < limit)
    {
      goto scan;
    }
    increment_attempt:
    ++attempt;

    if (attempt < 3)
    {
      goto retry;
    }
  }
  while (0);
  return 0;
}

