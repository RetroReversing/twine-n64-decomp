s16 randomIntBelow(u32);
f32 approxDistance(void *, s32);
s32 func_80063DB4(void *);
extern u8 gSceneType;
extern s32 gSaveTotalSlots;
extern u32 gTrackMarkerCount;
extern u8 gTrackMarkerGroup[];
extern s32 gTrackMarkerIndex;
extern s32 gBonusObjects;
extern s32 gTrackMarkerPosTable;
inline static int inline_fn(u16 arg0)
{
  return arg0 & 0xFFFF;
}

/* Picks a track marker for the actor: a random one not near another player, or in group scenes the marker farthest from all other players, then stores it. */
void pickActorTrackMarker(void *actor)
{
  f32 dist;
  f32 minDist;
  f32 bestDist;
  u16 marker;
  s16 temp_v0;
  s16 temp_v0_2;
  s16 slot;
  s16 slot2;
  
  s16 chosenMarker;
  u8 isGroupScene;
  void *actorData;
  bestDist = -1.0f;
  actorData = *((void **) (((char *) actor) + 0x6C));
  isGroupScene = ((u32) (gSceneType - 2)) < 2U;
  chosenMarker = 0;
  if (isGroupScene == 0)
  {
    loop_1:
    slot = 0;

    marker = randomIntBelow(gTrackMarkerCount);
    if (gSaveTotalSlots > 0)
    {
      do
      {
        if (slot != (*((s8 *) (((char *) actorData) + 0x182))))
        {
          dist = approxDistance((inline_fn(marker) * 0xC) + ((char *) (&gTrackMarkerPosTable)), (&gBonusObjects)[slot] + 0x24);
          if (dist < 3.0f) { do { goto loop_1; } while (0); }
        }
        temp_v0 = slot + 1;
        slot = temp_v0;
      }
      while (temp_v0 < gSaveTotalSlots);

    }
    chosenMarker = marker;
  }
  else
  {
    marker = 0;
    if (gTrackMarkerCount != 0)
    {
      do
      {
        if ((isGroupScene == 0) || ((*(gTrackMarkerGroup + inline_fn(marker))) == (*((u8 *) (((char *) (*((void **) (((char *) actorData) + 0xB4)))) + 0x12)))))
        {
          minDist = 4194304.0f;
          slot2 = 0;
          if (gSaveTotalSlots > 0)
          {
            do
            {
              if (slot2 != (*((s8 *) (((char *) actorData) + 0x182))))
              {
                dist = approxDistance((inline_fn(marker) * 0xC) + ((char *) (&gTrackMarkerPosTable)), (&gBonusObjects)[slot2] + 0x24);
                if (dist < minDist)
                {
                  do
                  {
                    minDist = dist;
                  }
                  while (0);
                }
              }
              temp_v0_2 = slot2 + 1;
              slot2 = temp_v0_2;
            }
            while (temp_v0_2 < gSaveTotalSlots);
          }
          if (bestDist < minDist)
          {
            bestDist = minDist;
            chosenMarker = marker;
          }
        }
        marker += 1;
      }
      while (((u32) inline_fn(marker)) < ((u32) gTrackMarkerCount));
    }
  }
  gTrackMarkerIndex = (s32) chosenMarker;
  func_80063DB4(actor);
}
