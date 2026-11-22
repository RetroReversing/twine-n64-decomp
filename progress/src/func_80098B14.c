typedef struct 
{
  u8 pad0[0x2e];
  u8 group;
  u8 pad2f[0x34];
  u8 slot;
} Entry;
typedef struct 
{
  u8 previous;
  u8 next;
  u16 used;
} SlotLinks;
typedef struct 
{
  u16 index;
  u16 pad;
} IndexLink;
extern SlotLinks D_80102CE0[];
extern u8 D_8010957D[];
extern u16 D_80109B1C;
extern IndexLink D_8010A51A[];
extern IndexLink D_8010A51C[];
extern void func_80098A18(void *);
void func_80098B14(Entry *entry, s32 group)
{
  u32 slot = entry->slot;
  SlotLinks *p = &D_80102CE0[slot];
  u16 head;
  u16 pos;
  u16 key;
  u16 prev;
  u16 cur;
  u8 next;
  if (p->used == 1)
  {
    if (entry->group == ((u8) group))
    {
      return;
    }
    func_80098A18(entry);
  }
  p->used = 1;
  p->previous = 0xFF;
  next = D_8010957D[(u8) group];
  p->next = next;
  if (next != 0xFF)
  {
    D_80102CE0[D_8010957D[(u8) group]].previous = slot;
  }
  else
  {
    head = D_80109B1C;
    if (head != 0xFFFF)
    {
      pos = (u8) group;
      if (pos >= head)
      {
cur = head;
key = pos;
        for (;;)
        {
          if (key >= cur)
          {
            prev = cur;
            cur = D_8010A51A[cur].index;
            if (cur != 0xFFFF)
            {
              continue;
            }
          }
          break;
        }
        D_8010A51A[prev].index = key;
        D_8010A51C[(u8) group].index = prev;
        D_8010A51A[(u8) group].index = cur;
        if (cur != 0xFFFF)
        {
          D_8010A51C[cur].index = key;
        }
      }
      else
      {
        D_8010A51A[(u8) group].index = head;
        D_8010A51C[(u8) group].index = 0xFFFF;
        D_8010A51C[head].index = pos;
        D_80109B1C = pos;
      }
    }
    else
    {
      D_8010A51A[(u8) group].index = 0xFFFF;
      D_8010A51C[(u8) group].index = 0xFFFF;
      D_80109B1C = (u8) group;
    }
  }
  D_8010957D[(u8) group] = slot;
  entry->group = (u8) group;
}
