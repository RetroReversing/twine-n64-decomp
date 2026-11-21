s32 advanceActorMotion(void *, s32);
f32 approxDistance(void *, s32);
s32 effectSetAnimFrame(void *, s32, u16);
s32 func_80084338(u16, void *);
s32 markObjectsNearPos(s32, s32, s32, void *, f32, s32);
extern u8 gTrackMarkerDone;
extern s32 sBonusObjectTable;
extern u8 sDifficultyLevel;
inline static s32 inline_fn(u8 arg0)
{
  return arg0;
}

void func_8005DED8(void *arg0)
{
  int __repair_constant = 0xFF;
  s16 temp_v1_2;
  s32 var_v0;
  s32 __repair_phase_var_v0;
  u16 temp_a0_2;
  u16 temp_v0;
  u16 temp_v0_2;
  u16 temp_v0_3;
  u16 temp_v1_3;
  u16 temp_v1_4;
  u16 temp_v1_5;
  u8 temp_v1;
  void *temp_s1;
  temp_s1 = *((void **) (((char *) arg0) + 0x6C));
  if ((*((u16 *) (((char *) temp_s1) + 0x3A))) == 1)
  {
    temp_v1 = *((u8 *) (((s8 *) (&gTrackMarkerDone)) + (*((u16 *) (((char *) temp_s1) + 0x34)))));
    if (temp_v1 < 2U)
    {
      effectSetAnimFrame(arg0, (*((u16 *) (((char *) temp_s1) + 0x3C))) + temp_v1, *((u16 *) (((char *) temp_s1) + 0x3E)));
    }
  }
  if ((*((s32 *) (((char *) arg0) + 0x60))) & 0x100000)
  {
    *((s32 *) (((char *) arg0) + 0x60)) = 0;
  }
  if (((((sDifficultyLevel == 0) && (sBonusObjectTable != 0)) && ((*((s32 *) (((char *) temp_s1) + 0x4C))) & 0x80)) && ((*((s32 *) (((char *) arg0) + 0x58))) & 4)) && (approxDistance(arg0 + 0x24, sBonusObjectTable + 0x24) < 4.0f))
  {
    if ((*((s32 *) (((char *) temp_s1) + 0x2C))) & 0x08000802)
    {
      temp_v0 = (*((u16 *) (((char *) temp_s1) + 0x42))) + 1;
      *((u16 *) (((char *) temp_s1) + 0x42)) = temp_v0;
      if (temp_v0 & 0x10)
      {
        goto L_ff;
      }
      *((u8 *) (((char *) arg0) + 0x7F)) = 0xBF;
      *((u8 *) (((char *) arg0) + 0x80)) = 0xBF;
      *((u8 *) (((char *) arg0) + 0x81)) = 0xBF;
    }
    else
    {
      L_ff:
      *((u8 *) (((char *) arg0) + 0x81)) = 0xFF;
      *((u8 *) (((char *) arg0) + 0x80)) = 0xFF;
      *((u8 *) (((char *) arg0) + 0x7F)) = 0xFF;
    }
  }
  temp_v1_2 = *((s16 *) (((char *) arg0) + 0x7A));
  switch (temp_v1_2)
  {
    case 0:
      if (((*((s32 *) (((char *) arg0) + 0x60))) & (*((s32 *) (((char *) temp_s1) + 0x2C)))) && (((temp_v0_2 = *((u16 *) (((char *) temp_s1) + 0x36)), temp_v0_2 == 0)) || (inline_fn(*((u8 *) (((s8 *) (&gTrackMarkerDone)) + temp_v0_2))) == (*((u16 *) (((char *) temp_s1) + 0x38))))))
    {
      temp_v1_3 = *((u16 *) (((char *) temp_s1) + 0x34));
      if (temp_v1_3 != 0)
      {
        *((u8 *) (((s8 *) (&gTrackMarkerDone)) + temp_v1_3)) = (*((u8 *) (((s8 *) (&gTrackMarkerDone)) + temp_v1_3))) ^ 1;
      }
      temp_v1_3 = *((u16 *) (((char *) temp_s1) + 0x40));
      if (temp_v1_3 != 0)
      {
        func_80084338(temp_v1_3, arg0 + 0x24);
      }
      *((s16 *) (((char *) arg0) + 0x7A)) = 1;
    }
      break;

    case 1:
      if (!((*((s32 *) (((char *) arg0) + 0x60))) & (*((s32 *) (((char *) temp_s1) + 0x2C)))))
    {
      *((s16 *) (((char *) arg0) + 0x7A)) = 2;
    }
      break;

    case 2:
      if ((*((s32 *) (((char *) temp_s1) + 4))) != 0)
    {
      markObjectsNearPos(*((s32 *) (((char *) arg0) + 0x20)), 0, 0x01000000, arg0 + 0x24, (*((f32 *) (((char *) (*((void **) (((char *) arg0) + 0x70)))) + 0x14))) + 1.0f, 0);
      if ((advanceActorMotion(arg0, 1) << 0x18) != 0)
      {
        *((f32 *) (((char *) temp_s1) + 8)) = 1.0f;
        *((s16 *) (((char *) arg0) + 0x7A)) = 3;
      }
    }
    else
    {
      *((s16 *) (((char *) arg0) + 0x7A)) = 3;
    }
      break;

    case 3:
      if (((*((s32 *) (((char *) arg0) + 0x60))) & (*((s32 *) (((char *) temp_s1) + 0x2C)))) && (((temp_v0_3 = *((u16 *) (((char *) temp_s1) + 0x36)), temp_v0_3 == 0)) || ((*((u8 *) (((s8 *) (&gTrackMarkerDone)) + temp_v0_3))) == (*((u16 *) (((char *) temp_s1) + 0x38))))))
    {
      temp_v1_4 = *((u16 *) (((char *) arg0) + 0x78));
      if (temp_v1_4 != 0x12)
      {
        if (temp_v1_4 != 0x60)
        {
          if ((*((u16 *) (((char *) temp_s1) + 0x34))) != 0)
          {
            *((s16 *) (((char *) arg0) + 0x7A)) = 4;
          }
          __repair_phase_var_v0 = (u16) (*((u16 *) (((char *) temp_s1) + 0x34)));
          *((u8 *) (((s8 *) (&gTrackMarkerDone)) + __repair_phase_var_v0)) = (*((u8 *) (((s8 *) (&gTrackMarkerDone)) + __repair_phase_var_v0))) ^ 1;
          temp_a0_2 = *((u16 *) (((char *) temp_s1) + 0x40));
          if (temp_a0_2 != 0)
          {
            func_80084338(temp_a0_2, arg0 + 0x24);
          }
        }
      }
    }
      break;

    case 4:
      if (!((*((s32 *) (((char *) arg0) + 0x60))) & (*((s32 *) (((char *) temp_s1) + 0x2C)))))
    {
      *((s16 *) (((char *) arg0) + 0x7A)) = 5;
    }
      break;

    case 5:
      if ((*((s32 *) (((char *) temp_s1) + 4))) != 0)
    {
      markObjectsNearPos(*((s32 *) (((char *) arg0) + 0x20)), 0, 0x01000000, arg0 + 0x24, (*((f32 *) (((char *) (*((void **) (((char *) arg0) + 0x70)))) + 0x14))) + 1.0f, 0);
      if ((advanceActorMotion(arg0, -1) << 0x18) != 0)
      {
        *((f32 *) (((char *) temp_s1) + 8)) = 1.0f;
        goto block_45;
      }
    }
    else
    {
      block_45:
      *((s16 *) (((char *) arg0) + 0x7A)) = 0;

    }
      break;

  }

  *((s32 *) (((char *) arg0) + 0x60)) = (s32) ((*((s32 *) (((char *) arg0) + 0x60))) & 1);
}

