#define WORD(p) (*(s32 *)(p))
#define HALF(p) (*(u16 *)(p))
#define PROCESS(off,tab,call)     key = inline_fn((u16 *)((u32)WORD(group + off) + (u32)group) + 4);     while ((lookup = *key) != 0xffff) {         entry = data + WORD(data + tab);         found = 0;         while (WORD(entry) != -1) {             found = entry;             if (HALF(entry + 4) == (u16)lookup) break;             entry += WORD(entry);             found = 0;         }         if (found) { call; }         key++;     }
extern u8 gWorkerActive;
extern s16 sSceneGroupStackCount;
extern u8 *sSceneGroupStack[];
extern s32 func_8008C758(s32);
extern u8 keyTableRegister(s32, s32);
extern void func_80097A40(u16, s32);
extern void func_80097EF8(u16, void *);
extern void insertOrRefSortedEntry(u16, void *);
extern void insertOrCountEntry(u16, void *);
extern void insertSortedKeyEntry(u16, void *, u16);
extern void registerWorkerEntry(s32, void *, u16);
inline static u16 *inline_fn(u16 *arg0)
{
  return arg0;
}

s32 func_80092A68(u8 *first, short id, s32 resource, s32 table, u8 *data)
{
  u8 *entry;
  u8 *found;
  u8 *group;
  u16 *key;
  s32 lookup;
  if (gWorkerActive && (sSceneGroupStackCount < 128))
  {
    group = first;
    if (WORD(group) == (-1))
    {
      return 0;
    }
    do
    {
      if (HALF(group + 4) == ((u16) id))
      {
        sSceneGroupStack[sSceneGroupStackCount] = group;
        PROCESS(8, 0, func_80097EF8(HALF(key), found + 8));
        key = inline_fn(((u16 *) (group + WORD(group + 12))) + 4);
        if (keyTableRegister(table, func_8008C758(resource)))
        {
          while ((lookup = *(key++)) != 0xffff)
          {
            func_80097A40(lookup, table);
          }

        }
        PROCESS(16, 4, insertOrRefSortedEntry(HALF(key), found + 8));
        PROCESS(20, 8, insertOrCountEntry(HALF(key), found + 8));
        PROCESS(24, 12, insertSortedKeyEntry(HALF(key), found + 12, HALF(found + 10)));
        if (HALF(group + 6) == 1)
        {
          entry = (u8 *)inline_fn((u16 *)((u32)WORD(group + 28) + (u32)group + 8));
          registerWorkerEntry((u16) id, entry + 4, HALF(entry));
        }
        sSceneGroupStackCount++;
        return 1;
      }
      group += WORD(group);
    }
    while (WORD(group) != (-1));
  }
  return 0;
}


