extern u8 D_801002EA;
extern u8 D_801005B0;
extern u8 D_801007C0;
typedef struct { u8 previous; u8 next; u16 used; } SlotLinks;
typedef struct { u16 index; u16 pad; } IndexLink;
extern SlotLinks D_80102CE0[];
extern u8 D_8010957D[];
extern u16 D_80109B1C;
extern IndexLink D_8010A51A[];
extern u8 D_8010A930;
extern u8 D_8010D720;
extern char sSoundVoiceFlags[];
extern char D_8010D74C[];
extern char D_8010D752[];
extern u8 sVoiceKeepFlags[];
extern char D_8010D7DE[];
extern u8 D_8010D7E1[];
extern u8 D_80110DB0;
extern u8 sDmaThreadStackTop;
extern SlotLinks sVoiceFreeList[];
extern u8 sVoiceCount;

inline static int inline_fn(s32 arg0)
{
  return arg0 * 0x1A0;
}

/* Picks a voice slot for soundId: reuses the oldest matching voice when over the limit, else takes a free one; returns -1 on failure. */
s32 allocVoiceSlot(s32 priority, s32 maxVoices, s32 soundId, s32 keepFlag)
{
  u32 used;
  u32 limit;
  u32 below;
  u8 strict;
  s32 count;
  s32 best;
  u32 pos;
  u16 cur;
  s32 idx;
  u16 head;
  u32 t1;
  u32 t2;
  s32 off;
  SlotLinks *link;
  s32 t;
  s32 u;

  if (sDmaThreadStackTop == 0)
  {
  if (keepFlag & 0xFF)
  {
    used = D_8010A930;
    limit = D_801007C0;
    below = used < limit;
  }
  else
  {
    used = D_8010D720;
    limit = D_801005B0;
    below = used < limit;
  }
  do
  {
    strict = 0;
  }
  while (0);
  if (below == 0)
  {
    strict = limit < sVoiceCount;
  }
  count = 0;
  if ((maxVoices & 0xFF) < limit)
  {
    cur = D_80109B1C;
    best = -1;
    if ((cur & 0xFFFF) != 0xFFFF)
    {
      for (;;)
      {
        pos = cur & 0xFFFF;
        if (((priority & 0xFF) >= pos) & ((~best) == 0))
        {
          idx = *(D_8010957D + pos);
          while (idx != 0xFF)
          {
              off = idx * 0x1A0;
              if (*(D_8010D7E1 + off) == 0)
              {
                if (*((u16 *) (D_8010D7DE + off)) == (soundId & 0xFFFF))
                {
                  count += 1;
                  if ((strict == 0) || (*(sVoiceKeepFlags + off) == (keepFlag & 0xFF)))
                  {
                    if (!(*((u32 *) (sSoundVoiceFlags + off)) & 2))
                    {
                      if ((best == -1) || (*((u32 *) (D_8010D74C + off)) < *((u32 *) (D_8010D74C + inline_fn(best)))))
                      {
                        best = idx;
                      }
                    }
                  }
                }
              }
              idx = D_80102CE0[idx].next;
          }
          cur = D_8010A51A[cur].index;
          if ((cur & 0xFFFF) != 0xFFFF)
          {
            continue;
          }
        }
        break;
      }
    }
    if (count < (maxVoices & 0xFF))
    {
      if ((cur & 0xFFFF) != 0xFFFF)
      {
        for (;;)
        {
          if (!(count < (maxVoices & 0xFF)))
          {
            goto commit;
          }
          idx = *(D_8010957D + (cur & 0xFFFF));
          while (idx != 0xFF)
          {
              off = idx * 0x1A0;
              if (*(D_8010D7E1 + off) == 0)
              {
                count += *((u16 *) (D_8010D7DE + off)) == (soundId & 0xFFFF);
              }
              idx = D_80102CE0[idx].next;
          }
          cur = D_8010A51A[cur].index;
          if (cur != 0xFFFF)
          {
            continue;
          }
          break;
        }
      }
      if (!(count < (maxVoices & 0xFF)))
      {
        goto commit;
      }
    }
    else
    {
      goto commit;
    }
  }
  best = -1;
  if ((D_801002EA != 0xFF) & (!strict))
  {
    best = D_801002EA;
    goto check;
  }
  head = D_80109B1C;
  t2 = priority & 0xFF;
  t1 = head & 0xFFFF;
  if (t2 < t1)
  {
    return -1;
  }
  cur = head;
  if (t1 != 0xFFFF)
  {
    for (;;)
    {
      t1 = cur & 0xFFFF;
      if (((priority & 0xFF) >= t1) & ((~best) == 0))
      {
        idx = *(D_8010957D + t1);
        while (idx != 0xFF)
        {
            t1 = idx * 0x1A0;
            do { if (*(D_8010D7E1 + t1) == 0)
            {
              if ((strict == 0) || (*(sVoiceKeepFlags + t1) == (keepFlag & 0xFF)))
              {
                if (!(*((u32 *) (sSoundVoiceFlags + t1)) & 2))
                {
                  if ((best == -1) || (*((u32 *) (D_8010D74C + inline_fn(best))) > *((u32 *) (D_8010D74C + t1))))
                  {
                    best = idx;
                  }
                }
              }
            } } while (0);
            idx = D_80102CE0[idx].next;
        }
        cur = D_8010A51A[cur].index;
        if ((cur & 0xFFFF) != 0xFFFF)
        {
          continue;
        }
      }
      break;
    }
  }
  if (best == -1)
  {
    return -1;
  }
check:
  if (((u32) (priority & 0xFF)) < *((u8 *) (D_8010D752 + inline_fn(best))))
  {
    return -1;
  }
commit:
  if (best != -1)
  {
  if (sVoiceFreeList[best].used == 1)
  {
    link = &sVoiceFreeList[best];
    idx = link->previous;
    if (idx != 0xFF)
    {
      sVoiceFreeList[idx].next = link->next;
    }
    else
    {
      D_801002EA = link->next;
    }
    idx = link->next;
    if (idx != 0xFF)
    {
      sVoiceFreeList[idx].previous = link->previous;
    }
    if (best == D_80110DB0)
    {
      D_80110DB0 = link->previous;
    }
    link->used = 0;
  }
  else
  {
    if (*(sVoiceKeepFlags + inline_fn(best)) != 0)
    {
      D_8010A930 -= 1;
    }
    else
    {
      D_8010D720 -= 1;
    }
  }
  if (keepFlag & 0xFF)
  {
    D_8010A930 += 1;
  }
  else
  {
    D_8010D720 += 1;
  }
  return best;
  }
  }
  return -1;
}
