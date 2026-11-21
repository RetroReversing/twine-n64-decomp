typedef struct 
{
  s16 slot;
  u16 flags;
  u16 first;
  u16 second;
} MapEntry;
extern void func_80030680(void);
extern s8 *func_80087100(u16);
extern s16 D_800BFF02;
extern MapEntry *D_800BFF04;
extern void *D_800BFF08;
extern u16 D_800BFF0C;
extern s32 D_800BFF10;
extern u8 D_800C02C0[];
extern MapEntry *D_800C02D4;
extern u16 D_800C02D8;
extern u16 D_800C02DA;
extern u8 D_800C02DC;
extern u16 D_800E1608;
extern u16 D_800E160A;
extern s8 D_80100768;
inline static MapEntry *inline_fn(u8 *arg0)
{
  return (MapEntry *) arg0;
}

inline static int inline_fn2(u16 arg0, int arg1)
{
  return arg0 & arg1;
}

void func_8003099C(u8 map, u8 level)
{
  short tableIndex;
  short i;
  u16 count;
  u16 flags;
  s32 newFlags;
  u16 mapSize;
  MapEntry *entries;
  MapEntry *entry;
  s8 *line;
  D_800BFF02 = 0; D_80100768 = map; D_800BFF10 = 6; tableIndex = 0;
  if (D_800C02D8 != 0)
  {
    do
    {
      s32 offset = ((u16) tableIndex) * 32;
      ++tableIndex;
      if ((*((u16 *) (((u8 *) (&D_800C02DA)) + offset))) == map)
      {
        entries = *((MapEntry **) (((u8 *) (&D_800C02D4)) + offset)); D_800BFF08 = D_800C02C0 + offset;
        mapSize = *((u16 *) (((u8 *) (&D_800C02D8)) + offset)); D_800BFF04 = entries;
        count = *((u8 *) ((&D_800C02DC) + offset)); D_800BFF0C = mapSize;
        D_800E160A = (u16) (level << 12); D_800E1608 = count;
        for (i = 0; ((u16) i) < count; ++i)
        {
          if (entries == NULL)
          {
            break;
          }
          entry = (MapEntry *) ((((u16) i) * 8) + ((u8 *) entries)); flags = entry->flags; newFlags = inline_fn2(flags, 0xFDF0); entry->flags = newFlags;
          if (newFlags & 0x400)
          {
            entry->flags = newFlags | 0x200;
          }
        }

        i = 0; tableIndex = 0;
        for (; ((u16) i) < D_800E1608; ++i)
        {
          MapEntry *base = D_800BFF04;
          entry = inline_fn((((u16) i) * 8) + ((u8 *) base)); entry->slot = -1;
          if (base == NULL)
          {
            break;
          }
          flags = entry->flags;
          if ((!(flags & 0x200)) && (D_800E160A >= (flags & 0xF000)))
          {
            entry->slot = tableIndex; line = func_80087100(entry->first);
            if (line != NULL)
            {
              line[0] = 6;
              line[1] = -1;
              line[2] = ((u8 *) (&D_800BFF04[(u16) i]))[1] + 'A';
            }
            newFlags = (u16) i;
            line = func_80087100(D_800BFF04[newFlags].second);
            if (line != NULL)
            {
              line[0] = 6;
              line[1] = -1;
              line[2] = ((u8 *) (&D_800BFF04[(u16) i]))[1] + 'A';
            }
            ++tableIndex;
          }
        }

        func_80030680();
        return;
      }
    }
    while ((*((u16 *) (((u8 *) (&D_800C02D8)) + (((u16) tableIndex) * 32)))) != 0);
  }
  D_800BFF04 = NULL; D_80100768 = 0; D_800E1608 = 0; D_800E160A = 0; D_800BFF0C = 3;
}

