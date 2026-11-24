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
/* Moves a voice slot to the front of its group's list, adding the group to the sorted list of non-empty groups if needed. */
void linkVoiceIntoGroup(Entry *entry, s32 group)
{
  u32 slot = entry->slot;
  SlotLinks *links = &D_80102CE0[slot];
  u16 headGroup;
  u16 newGroup;
  u16 insertKey;
  u16 prevGroup;
  u16 curGroup;
  u8 oldFirst;
  if (links->used == 1)
  {
    if (entry->group == ((u8) group))
    {
      return;
    }
    func_80098A18(entry);
  }
  links->used = 1;
  links->previous = 0xFF;
  oldFirst = D_8010957D[(u8) group];
  links->next = oldFirst;
  if (oldFirst != 0xFF)
  {
    D_80102CE0[D_8010957D[(u8) group]].previous = slot;
  }
  else
  {
    headGroup = D_80109B1C;
    if (headGroup != 0xFFFF)
    {
      newGroup = (u8) group;
      if (newGroup >= headGroup)
      {
curGroup = headGroup;
insertKey = newGroup;
        for (;;)
        {
          if (insertKey >= curGroup)
          {
            prevGroup = curGroup;
            curGroup = D_8010A51A[curGroup].index;
            if (curGroup != 0xFFFF)
            {
              continue;
            }
          }
          break;
        }
        D_8010A51A[prevGroup].index = insertKey;
        D_8010A51C[(u8) group].index = prevGroup;
        D_8010A51A[(u8) group].index = curGroup;
        if (curGroup != 0xFFFF)
        {
          D_8010A51C[curGroup].index = insertKey;
        }
      }
      else
      {
        D_8010A51A[(u8) group].index = headGroup;
        D_8010A51C[(u8) group].index = 0xFFFF;
        D_8010A51C[headGroup].index = newGroup;
        D_80109B1C = newGroup;
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
