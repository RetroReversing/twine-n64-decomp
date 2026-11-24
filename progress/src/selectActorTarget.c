#define FIELD(base, type, offset) (*(type *)((char *)(base) + (offset)))
typedef struct { s32 f0; s32 pad[5]; } SaveRec;
typedef struct { u16 f0; u8 pad[10]; } Rec12a;
typedef struct { u8 f0; u8 pad[11]; } Rec12b;
#define SLOT_INDEX() (gSaveSlotInfo[getSaveSlotIndex((u16)FIELD(actorData, s8, 0x182)) & 0xFFFF].f0)
extern s32 getSaveSlotIndex(s32);
extern f32 approxDistance(void *, void *);
extern s32 raycastThroughRooms(void *, void *, s32, void *, s32, s32, s32, s32, s32);
extern s32 isFacingPosition(void *, void *, void *, u32);
extern s32 isStatBelowThreshold(void *, void *);
extern Rec12a D_800BF688[];
extern Rec12b D_800BF68B[];
extern SaveRec gSaveSlotInfo[];
extern u8 sSaveSlotTable[][24];
extern u8 gSceneType[];
extern u8 sProbeActive[];
extern u8 D_8011F169[];
extern s16 sActorPartnerSlots[];
extern u32 gSaveTotalSlots;
extern void *D_8011ECB0[];
extern void *gSaveSlots[];
extern void *sBonusObjectTable[];
extern void *sProbeOriginTable[];
extern void *gActorList;
extern void *gTrackMarkerParents[];
inline static int inline_fn(int arg0)
{
  return arg0;
}

/* Picks the best target object for an actor: scores nearby bonus objects by weighted distance and visibility, else scans the actor list. */
void *selectActorTarget(void *actor, u8 useFallback)
{
  f32 sp28[3];
  s32 sp38;
  u8 sp47;
  void *sp4C;
  void *sp54;
  f32 temp_fs0;
  f32 dist;
  f32 weight;
  f32 bestDist;
  f32 bestVisibleDist;
  s16 temp_v0_2;
  s16 temp_v1_6;
  s16 var_a0_2;
  s16 var_a2;
  long temp_v1;
  s32 var_a3;
  s32 var_fp;
  s32 minValue;
  s32 var_v0_2;
  s32 var_v0_3;
  s32 var_v0_4;
  s32 var_v0_6;
  s32 var_v0_7;
  s32 var_v0_8;
  u16 temp_v0;
  u16 temp_v1_2;
  int var_v0_5;
  u32 temp_v1_4;
  u32 var_s1;
  u8 temp_a1_2;
  u32 modeFlags;
  u8 temp_v1_3;
  u8 temp_v1_5;
  void **var_a0;
  void **var_s0;
  void *other;
  void *actorData;
  void *weights;
  void *candidate;
  void *bestTarget;
  void *var_v0;
  actorData = *((void **) (0x6C + ((char *) actor)));
  sp47 = useFallback;
  bestDist = 65536.0f;
  var_s1 = D_800BF688[SLOT_INDEX()].f0 & 3;
  weights = D_8011ECB0[var_s1];
  temp_v1 = SLOT_INDEX();
  bestTarget = NULL;
  sp4C = NULL;
  sp54 = NULL;
  modeFlags = D_800BF68B[temp_v1].f0;
  minValue = 0x270F;
  bestVisibleDist = 65536.0f;
  if (modeFlags & 2)
  {
    u32 total;
    var_s1 = 0;
    if ((u32)bestTarget < gSaveTotalSlots)
    {
      total = gSaveTotalSlots;
      var_a0 = gSaveSlots;
      do
      {
        temp_v1_2 = *((u16 *) (((char *) (*((void **) (((char *) (*var_a0)) + 0xB4)))) + 0xC));
        if (((s32) temp_v1_2) < minValue)
        {
          minValue = (s32) temp_v1_2;
        }
        var_s1 += 1;
        var_a0++;
      }
      while (var_s1 < total);
    }
    if (minValue <= 0)
    {
      minValue = 1;
    }
  }
  var_s1 = 0;
  var_s0 = sBonusObjectTable;
  var_fp = 0;
  do
  {
    if (((*var_s0) != NULL) && ((*var_s0) != actor))
    {
      other = FIELD(*var_s0, void *, 0x6C);
      if (!((*((f32 *) (((char *) (*var_s0)) + 0x74))) <= 0.0f))
      {
      temp_v0 = *((u16 *) (((char *) (*var_s0)) + 0x78));
      if ((((temp_v0 == 0x4D) | (temp_v0 == 0x61)) == 0) && (((temp_v1_3 = *((u8 *) (((char *) (*((void **) (((char *) actorData) + 0xB4)))) + 0x12)), temp_v1_3 == 2)) || (temp_v1_3 != (*((u8 *) (((char *) (*((void **) (((char *) other) + 0xB4)))) + 0x12))))))
      {
        dist = approxDistance(actor + 0x24, (*var_s0) + 0x24) * (*((f32 *) (((char *) weights) + 0x0)));
        if (((u32) (gSceneType[0] - 2)) < 2U)
        {
          if (sProbeOriginTable[*((u8 *) (((char *) (*((void **) (((char *) actorData) + 0xB4)))) + 0x12))] == (*var_s0))
          {
            dist *= 0.33333334f;
          }
        }
        if (modeFlags & 4)
        {
          dist = (dist * 0.01f) * (*((f32 *) (((char *) (*var_s0)) + 0x74)));
        }
        if (modeFlags & 2)
        {
          var_v0_5 = *((u16 *) (((char *) (*((void **) (((char *) (*((void **) (((char *) gSaveSlots) + var_fp)))) + 0xB4)))) + 0xC));
          if (((s32) var_v0_5) <= 0)
          {
            var_v0_5 = 1;
          }
          dist /= ((f32) var_v0_5) / ((f32) minValue);
        }
        if ((modeFlags & 8) && (var_s1 == sActorPartnerSlots[*((s8 *) (((char *) actorData) + 0x182))]))
        {
          dist *= 0.25f;
        }
        if (dist < bestDist)
        {
          bestDist = dist;
          sp4C = *var_s0;
        }
        if ((((dist < 50.0f) && (((dist < 6.0f) || (modeFlags & 1)) || (((isFacingPosition(actor, (*var_s0) + 0x24, &sp38, 0x448E38E4) << 22) << 2) != 0))) && ((raycastThroughRooms(((char *) gTrackMarkerParents[*((s8 *) (((char *) actorData) + 0x182))]) + 0x10, (*var_s0) + 0x24, *((s32 *) (((char *) actor) + 0x20)), &sp28, 0, 0, 0x20000, 1, 0) << 24) != 0)) && (dist < bestVisibleDist))
        {
          bestVisibleDist = dist;
          bestTarget = *var_s0;
        }
      }
      }
    }
    var_s0++;
    var_s1 += 1;
    var_fp += 4;
  }
  while (var_s1 < 4U);
  if ((*((s8 *) (((char *) (*((void **) (((char *) actor) + 0x68)))) + 0xE))) == 0)
  {
    bestDist = 65536.0f;
    bestTarget = NULL;
    sp4C = NULL;
    sp47 = 1;
  }
  if (bestTarget == NULL)
  {
    if (sp47 == 0)
    {
      do
      {
        return *((void **) (((char *) actorData) + 0xC0));
      }
      while (0);
    }
    candidate = gActorList;
    if (candidate != NULL)
    {
      void **origins;
      u8 *scene;
      u8 *otherActive;
      var_s1 = 3;
      origins = sProbeOriginTable;
      scene = gSceneType;
      otherActive = D_8011F169;
      do
      {
        weight = 1.0f;
        temp_v1_4 = (*((u16 *) (((char *) candidate) + 0x78))) - 0x28;
        var_a3 = 0;
        switch (temp_v1_4)
        {
          case 0:

          case 45:
            if ((*((s16 *) (((char *) candidate) + 0x7A))) == var_s1)
          {
            var_a3 = isStatBelowThreshold(actorData, candidate);
          }
            weight = *((f32 *) (((char *) weights) + 0x4));
            if ((*((s8 *) (((char *) (*((void **) (((char *) actor) + 0x68)))) + 0xE))) == 0)
          {
            weight = 0.01f;
          }
            break;

          case 1:
            weight = *((f32 *) (((char *) weights) + 0x8));
            if ((*((s16 *) (((char *) actor) + 0x7A))) != 7)
          {
            var_a3 = 1;
          }
            var_v0_7 = (*((s8 *) (((char *) (*((void **) (((char *) actor) + 0x68)))) + 0xE))) != 0;
            goto block_70;

          case 25:
            if ((*((s16 *) (((char *) candidate) + 0x7C))) != (*((u8 *) (((char *) (*((void **) (((char *) actorData) + 0xB4)))) + 0x12))))
          {
            var_a3 = 1;
          }
            weight = *((f32 *) (((char *) weights) + 0xC));
            break;

          case 29:
            temp_a1_2 = *((u8 *) (((char *) (*((void **) (((char *) actorData) + 0xB4)))) + 0x12));
            if ((*((s16 *) (((char *) candidate) + 0x7A))) == temp_a1_2)
          {
            if (origins[1 - temp_a1_2] == actor)
            {
              weight = 0.0f;
              var_a3 = 1;
              if (*scene == var_s1)
              {
                temp_v1_5 = sProbeActive[temp_a1_2];
                var_a2 = 0;
                if (temp_v1_5 == 0)
                {
                  if (((s32) temp_v1_5) < *(s32 *)(scene + 0x14))
                  {
                    var_a0_2 = 0;
                    do
                    {
                      if (sSaveSlotTable[var_a0_2][0] == temp_a1_2)
                      {
                        var_a2 += 1;
                      }
                      var_a0_2 += 1;
                    }
                    while (var_a0_2 < (s32) gSaveTotalSlots);
                  }
                  var_a3 &= -(var_a2 != 1);
                }
              }
            }
          }
          else
            if (*(otherActive - temp_a1_2) != 0)
          {
            weight = *((f32 *) (((char *) weights) + 0x10));
            var_a3 = 1;
          }
            var_v0_7 = (*((s16 *) (((char *) actor) + 0x7A))) != 7;
            block_70:
            var_a3 &= -var_v0_7;
            break;

          case 26:
            temp_v1_6 = *((s16 *) (((char *) candidate) + 0x7A));
            if ((origins[temp_v1_6] == 0) && (sProbeActive[temp_v1_6] == 0))
          {
            var_a3 = 1;
          }
            weight = *((f32 *) (((char *) weights) + 0x14));
            break;

          default:
            break;
        }

        if ((var_a3 & 0xFF) != 0)
        {
          dist = approxDistance(actor + 0x24, candidate + 0x24) * weight;
          if (dist < bestDist)
          {
            bestDist = dist;
            bestTarget = candidate;
          }
        }
        sp54 = candidate;
        candidate = *((void **) (((char *) candidate) + 0x10));
      }
      while (candidate != NULL);
    }
    if (bestTarget == NULL)
    {
      bestTarget = sp4C;
      if (sp4C == NULL)
      {
        bestTarget = sp54;
      }
    }
  }
  return bestTarget;
}
