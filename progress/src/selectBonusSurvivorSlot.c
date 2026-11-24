
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
extern SaveSlot *gSaveSlots[];
extern BonusSlot *sBonusObjectTable[];
extern s32 gBonusEndDelayFrames;
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

inline static volatile s32 inline_fn23456(volatile s32 *arg0)
{
  return *arg0;
}

/* Picks the one surviving bonus slot (a type-7 save slot, else the first active bonus object) and ends all other bonus objects. */ void selectBonusSurvivorSlot(void)
{
  s32 survivorIndex;
  s16 slot;
  s32 index;
  s16 survivor = -1;
  SaveSlot *saveEntry;
  BonusSlot *bonusObj;
  s32 count;
  s16 state;
  if ((gSceneType.type == 8) && ((slot = 0, gSaveTotalSlots > 0)))
  {
    do
    {
      index = (s16) slot;
      saveEntry = gSaveSlots[index];
      if ((saveEntry != 0) && (saveEntry->meta->type == 7))
      {
        {
          survivor = slot; slot = 0;
          if (slot < gSceneType.count)
          {
            {
              survivorIndex = index;
              do
              {
 do { if (slot == survivorIndex) { goto next_scene; } saveEntry = gSaveSlots[slot]; loop_goto_1: { if ((saveEntry == 0) || (saveEntry->meta->disabled != 0)) { goto next_scene; } gSaveSlots[survivorIndex]->meta->count++; } if (0) { goto loop_goto_1; } do { next_scene: slot++; } while (0); } while (0);
              }
              while (inline_fn23456((volatile s32 *) (&gSaveTotalSlots)) > ((s16) slot));
            }
          }
        }
        break;
      }
      slot++;
    }
    while (inline_fn2345(slot, *((volatile s32 *) (((u8 *) (&gSceneType)) + 0x14))));
  }
  if (((s16) survivor) == (-1))
  {
    BonusSlot *candidate;
    s16 candidateSlot;
    candidateSlot = 0;
    count = gSaveTotalSlots;
    loop_goto_2:
    {
      if (count <= 0)
      {
        goto done;
      }
      do
      {
        candidate = sBonusObjectTable[candidateSlot];
        if (candidate != 0)
        {
          state = candidate->state;
          if ((state < 2) & (state != 6))
          {
            survivor = candidateSlot;
            goto update;
          }
        }
        candidateSlot++;
      }
      while (candidateSlot < gSaveTotalSlots);
    }
    if (0)
    {
        goto loop_goto_2;
    }
  }
  update:
  slot = 0;

  if (inline_fn23456((volatile s32 *) (&gSaveTotalSlots)) > 0)
  {
    do
    {
      if (inline_fn23(slot) == ((s16) survivor)) goto skip3;
      bonusObj = sBonusObjectTable[(s16) slot];
      if (bonusObj != 0)
      {
        if ((bonusObj->type ^ 0) == 2) { bonusObj->state = 2; } else { bonusObj->state = 6; }
      }
      do { skip3: slot++; } while (0);
    }
    while (inline_fn23456((volatile s32 *) (&gSaveTotalSlots)) > ((s16) slot));
  }
  done:
  if (((s16) survivor) < 0)
  {
    gBonusEndDelayFrames = 0;
  }

}

