s32 actorUnlinkFromSurface(void *, void *);
void freeMenuItemRecord(void *);
s32 playMusicStream(s32, s32);
f32 distanceXZ(void *, s32);
void *getObjectListHead();
void objectListInsert(void *, void *);
s32 requestSound(s32);
void showTrackMarker(u32);
void *spawnTextNode(s16 *);
extern s16 D_800C7EA0;
extern s32 D_800C7EA4;
extern s32 D_800C7EC4;
extern void *gBonusTextNodes[];
extern s32 gBonusTextActiveIndex;
extern s32 gBonusTotalCount[][7];
extern s32 gBonusCollectedCount[][7];
extern u8 gTrackMarkerDone[];
extern s32 sBonusObjectTable;
inline static u8 inline_fn(void *arg0)
{
  return *((u8 *) (((char *) arg0) + 0x34));
}

/* Per-frame update of a collectible bonus object: waits until collectable, plays the pickup, fades out, then frees it. */
void updateBonusObject(void *actor)
{
  u8 *__base_D_8010D2C0;
  s32 temp_v1;
  s16 var_v0;
  s32 *temp_v1_8;
  s32 temp_a0_4;
  s32 temp_a1_3;
  s32 temp_s0;
  s32 temp_v0_2;
  s32 temp_v0_5;
  s32 temp_v0_7;
  unsigned temp_v1_2;
  s32 temp_v1_3;
  s32 temp_v1_5;
  s32 temp_v1_6;
  s32 var_v0_2;
  u16 temp_v0_3;
  u16 temp_v0_4;
  u8 temp_a0;
  u8 temp_a0_3;
  u8 temp_a1_2;
  u8 temp_v1_4;
  void *temp_a0_2;
  void *temp_a0_5;
  void *temp_a0_6;
  void *temp_a0_7;
  void *temp_a1;
  void *bonus;
  void *visual;
  void *temp_v0;
  void *temp_v0_6;
  void *temp_v1_7;
  void *other;
  bonus = *((void **) (((char *) actor) + 0x6C));
  temp_v0 = *((void **) (((char *) bonus) + 0x2C));
  if ((temp_v0 != NULL) && ((*((u16 *) (((char *) temp_v0) + 0x78))) != 1))
  {
    *((void **) (((char *) bonus) + 0x2C)) = NULL;
  }
  temp_v1 = *((s16 *) (((char *) actor) + 0x7A));
  *((f32 *) (((char *) actor) + 0x40)) = (f32) ((*((f32 *) (((char *) actor) + 0x40))) + (*((f32 *) (((char *) bonus) + 0x14))));
  switch (temp_v1)
  {
    case 0:
      if (gBonusCollectedCount[*((u8 *) ((char *) bonus + 0x33))][*((u8 *) ((char *) bonus + 0x34))] == *((s32 *) ((char *) bonus + 0x18)))
    {
      visual = *((void **) (((char *) bonus) + 4));
      if (((*((f32 *) (((char *) bonus) + 0xC))) != 65536.0f) && (distanceXZ(bonus + 8, sBonusObjectTable + 0x24) > (2.0f * (*((f32 *) (((char *) bonus) + 0x28))))))
      {
        other = getObjectListHead();
        while (other != NULL)
        {
          if (((*((u16 *) (((char *) other) + 0x78))) == 0x19) && ((*((s32 *) (((char *) (*((void **) (((char *) other) + 0x6C)))) + 0x20))) == (*((s32 *) (((char *) bonus) + 0x20)))))
          {
            temp_a0 = *((u8 *) (((char *) bonus) + 0x32));
            if (temp_a0 != 0)
            {
              showTrackMarker(temp_a0);
            }
            temp_v1_2 = *((s32 *) (((char *) bonus) + 0x24));
            if ((temp_v1_2 != 0) && (!(temp_v1_2 & 0x80000000)))
            {
              temp_v1_3 = temp_v1_2 & 0xFF;
              gTrackMarkerDone[temp_v1_3] = gTrackMarkerDone[temp_v1_3] ^ 1;
            }
            *((s16 *) (((char *) other) + 0x7A)) = 8;
          }
          other = *((void **) (((char *) other) + 0x10));
        }

      }
      else
      {
        temp_v0_2 = *((s32 *) (((char *) bonus) + 0x24));
        if (temp_v0_2 < 0)
        {
          gBonusTextActiveIndex = playMusicStream(temp_v0_2 & 0xFFFFFF, 0x64);
        }
        *((s32 *) (((char *) visual) + 0x28)) = (s32) ((*((s32 *) (((char *) visual) + 0x28))) & (~0xFC));
        temp_v1_4 = *((u8 *) (((char *) bonus) + 0x34));
        if (temp_v1_4 == 3)
        {
          
          *((s32 *) (((char *) visual) + 0x10)) = 0;
            *((s16 *) (((char *) actor) + 0x7A)) = 1;
}
        else
        {
          *((s32 *) (((char *) visual) + 0x10)) = (s32) ((*((&D_800C7EC4) + temp_v1_4)) | 0xF0);
          
            *((s16 *) (((char *) actor) + 0x7A)) = 7;
}
        *((void **) (((char *) actor) + 0x18)) = (void *) (*((void **) (((char *) bonus) + 0)));
        if (((*((s8 *) (((char *) bonus) + 0x135))) != 0) && (((*((volatile s16 *) (&D_800C7EA0)) = (s16) (*((u8 *) (((char *) bonus) + 0x33))), gBonusTextNodes[*((u8 *) (((char *) bonus) + 0x34))] != 0)) || ((gBonusTextNodes[*((u8 *) (((char *) bonus) + 0x34))] = spawnTextNode((s16 *) (((s8 *) (&D_800C7EA0)) - 0x20)), gBonusTextNodes[*((u8 *) (((char *) bonus) + 0x34))] != 0))))
        {
          void *temp_a0_2_a1;
          *((s8 *) (((char *) gBonusTextNodes[inline_fn(bonus)]) + 0x29)) = 0x1C;
          *((s16 *) (((char *) gBonusTextNodes[*((u8 *) (((char *) bonus) + 0x34))]) + 0x22)) = (s16) ((*((u16 *) (((char *) visual) + 0x22))) - 5);
          *((s32 *) (((char *) gBonusTextNodes[*((u8 *) (((char *) bonus) + 0x34))]) + 0x10)) = 0x88;
          temp_a0_2_a1 = gBonusTextNodes[*((u8 *) (((char *) bonus) + 0x34))];
          *((s32 *) (((char *) temp_a0_2_a1) + 0x28)) = (s32) (((*((s32 *) (((char *) temp_a0_2_a1) + 0x28))) & (~0xFC)) | 0x10);
        }
        temp_a0_3 = *((u8 *) (((char *) bonus) + 0x32));
        if (temp_a0_3 != 0)
        {
          showTrackMarker(temp_a0_3);
        }
        if ((*((s32 *) (((char *) bonus) + 0x24))) >= 0)
        {
          temp_a0_4 = *((&D_800C7EA4) + (*((u8 *) (((char *) bonus) + 0x34))));
          if (temp_a0_4)
          {
            requestSound(temp_a0_4);
          }
        }
      }
    }
      break;

    case 1:
      temp_a0_2 = *((void **) (((char *) bonus) + 4));
      if (((*((u16 *) (((char *) actor) + 0x7C))) & 2) && ((*((s8 *) (((char *) bonus) + 0x136))) != 0))
    {
      var_v0_2 = (*((&D_800C7EC4) + (*((u8 *) (((char *) bonus) + 0x34))))) | 0x10;
    }
    else
    {
      var_v0_2 = (*((&D_800C7EC4) + (*((u8 *) (((char *) bonus) + 0x34))))) | 0xF0;
    }
      *((s32 *) (((char *) temp_a0_2) + 0x10)) = var_v0_2;
      temp_v0_3 = (*((u16 *) (((char *) actor) + 0x7C))) + 1;
      *((u16 *) (((char *) actor) + 0x7C)) = temp_v0_3;
      if (((s16) temp_v0_3) == 0xE)
    {
      *((s16 *) (((char *) actor) + 0x7A)) = 7;
    }
      break;

    case 7:
      temp_a1 = *((void **) (((char *) actor) + 0x18));
      if (temp_a1 != NULL)
    {
      temp_s0 = *((s32 *) (((char *) temp_a1) + 0x20));
      if (temp_s0 != (*((s32 *) (((char *) actor) + 0x20))))
      {
        actorUnlinkFromSurface(actor, temp_a1);
        objectListInsert(actor, (void *) temp_s0);
      }
    }
      temp_v0_4 = (*((u16 *) (((char *) bonus) + 0x30))) - 1;
      *((u16 *) (((char *) bonus) + 0x30)) = temp_v0_4;
      if (((s16) temp_v0_4) < 0)
    {
      temp_a0_5 = *((void **) (((char *) bonus) + 4));
      if (temp_a0_5 != NULL)
      {
        temp_v0_5 = (*((s32 *) (((char *) temp_a0_5) + 0x10))) + 0xF7FFF7F0;
        *((s32 *) (((char *) temp_a0_5) + 0x10)) = temp_v0_5;
        if (!(temp_v0_5 & 0xFF))
        {
          temp_v1_5 = *((s32 *) (((char *) bonus) + 0x24));
          if (temp_v1_5 != 0)
          {
            if (temp_v1_5 >= 0)
            {
              temp_v1_5 &= 0xFF;
              temp_v1_6 = temp_v1_5;
              gTrackMarkerDone[temp_v1_6] = gTrackMarkerDone[temp_v1_6] ^ 1;
            }
          }
          *((s16 *) (((char *) actor) + 0x7A)) = 8;
        }
      }
    }
      temp_v1_7 = gBonusTextNodes[*((u8 *) (((char *) bonus) + 0x34))];
      if (temp_v1_7 != NULL)
    {
      temp_v0_6 = *((void **) (((char *) bonus) + 4));
      if (temp_v0_6 != NULL)
      {
        *((u32 *) (((char *) temp_v1_7) + 0x10)) = (u32) (((u32) ((*((s32 *) (((char *) temp_v0_6) + 0x10))) & 0xFE)) >> 1);
      }
    }
      break;

    case 8:
      freeMenuItemRecord(*((void **) (((char *) bonus) + 4)));
      *((void **) (((char *) bonus) + 4)) = NULL;
      if ((*((s32 *) (((char *) bonus) + 0x1C))) & 1)
    {
      gBonusCollectedCount[*((u8 *) (((char *) bonus) + 0x33))][*((u8 *) (((char *) bonus) + 0x34))] += 1;
    }
      temp_a1_2 = *((u8 *) (((char *) bonus) + 0x34));
      temp_a1_3 = temp_a1_2;
      if (temp_a1_2 != 0)
    {
      if (gBonusCollectedCount[*((u8 *) (((char *) bonus) + 0x33))][temp_a1_3] == gBonusTotalCount[*((u8 *) (((char *) bonus) + 0x33))][temp_a1_3])
      {
        temp_a0_6 = gBonusTextNodes[temp_a1_2];
        if (temp_a0_6 != NULL)
        {
          freeMenuItemRecord(temp_a0_6);
          gBonusTextNodes[*((u8 *) (((char *) bonus) + 0x34))] = 0;
        }
      }
    }
      *((s32 *) (((char *) actor) + 0x60)) = (s32) ((*((s32 *) (((char *) actor) + 0x60))) | 1);
      break;

  }

  if (!((*((s32 *) (((char *) actor) + 0x60))) & 1))
  {
    temp_a0_7 = *((void **) (((char *) bonus) + 0x2C));
    if (temp_a0_7 != NULL)
    {
      *((s32 *) (((char *) temp_a0_7) + 0x60)) = (s32) ((*((s32 *) (((char *) temp_a0_7) + 0x60))) | 0x10000000);
    }
  }
}
