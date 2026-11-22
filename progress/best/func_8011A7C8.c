typedef struct SlotMeta
{
  u8 pad[0xC];
  u16 count;
  u8 padE[2];
  u8 type;
  u8 disabled;
} SlotMeta;
typedef struct SaveSlot
{
  u8 pad[0xB4];
  SlotMeta *meta;
} SaveSlot;
typedef struct BonusSlot
{
  u8 pad[0x78];
  u16 type;
  s16 state;
} BonusSlot;
typedef struct SceneSlots
{
  u8 type;
  u8 pad[0x13];
  s32 count;
} SceneSlots;
extern SceneSlots gSceneType;
extern s32 gSaveTotalSlots;
extern SaveSlot *D_80102CD0[];
extern BonusSlot *sBonusObjectTable[];
extern s32 D_8011F3A8;
inline static int inline_fn(int arg0)
{
  return !arg0;
}

inline static u8 *inline_fn2(u8 *arg0, SceneSlots *arg1)
{
  return ((u8 *) (&gSceneType)) + (arg0 - ((u8 *) arg1));
}

inline static s16 inline_fn23(s16 arg0)
{
  return (s16) arg0;
}

inline static SceneSlots *inline_fn234()
{
  return &gSceneType;
}

inline static int inline_fn2345(s16 arg0, s32 arg1)
{
  return ((s16) arg0) < arg1;
}

void func_8011A7C8(void)
{
  s16 i;
  s32 index;
  s16 chosen = -1;

  SaveSlot *entry;
  BonusSlot *bonus;
  s32 count;
  s16 state;
  if ((gSceneType.type == 8) && ((i = 0, gSaveTotalSlots > 0)))
  {
    do
    {
      index = (s16) i;
      entry = D_80102CD0[index];
      if ((entry != 0) && (entry->meta->type == 7))
      {
        chosen = i;
        i = 0;
        if (i < gSceneType.count)
        {
          do
          {
            if (i == index)
            {
              goto next_scene;
            }
            entry = D_80102CD0[i];
            do
            {
              if ((entry == 0) || (entry->meta->disabled != 0))
              {
                goto next_scene;
              }
              D_80102CD0[index]->meta->count++;
            }
            while (0);
 do { next_scene: i++; } while (0);
          }
          while (((s16) i) < (*((volatile s32 *) inline_fn2((u8 *) (&gSaveTotalSlots), inline_fn234()))));
        }
        break;
      }
      i++;
    }
    while (inline_fn2345(i, gSceneType.count));
  }
  if (((s16) chosen) == (-1))
  {
    i = 0;
    count = gSaveTotalSlots;
    do
    {
      if (count <= 0)
      {
        goto done;
      }
      do
      {
        bonus = sBonusObjectTable[(s16) i];
        if (bonus == 0)
        {
          goto next_bonus;
        }
        state = bonus->state;
        if (inline_fn((state < 2) & (state != 6)))
        {
          goto next_bonus;
        }
        chosen = i;
        goto update;
        next_bonus:
        i++;

      }
      while (inline_fn2345(i, gSaveTotalSlots));
      goto done;
    }
    while (0);
  }
  update:
  i = 0;

  if ((*((volatile s32 *) (&gSaveTotalSlots))) > 0)
  {
    do
    {
      if (inline_fn23(i) != ((s16) chosen))
      {
        bonus = sBonusObjectTable[(s16) i];
        if (bonus != 0)
        {
          if (bonus->type == 2)
          {
            bonus->state = 2;
          }
          else
          {
            bonus->state = 6;
          }
        }
      }
      i++;
    }
    while (((s16) i) < (*((volatile s32 *) (&gSaveTotalSlots))));
  }
  done:
  if (((s16) chosen) < 0)
  {
    D_8011F3A8 = 0;
  }

}

