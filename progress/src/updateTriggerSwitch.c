s32 advanceActorMotion(void *, s32);
f32 approxDistance(void *, s32);
s32 effectSetAnimFrame(void *, s32, u16);
s32 playSoundAtPos(u16, void *);
s32 markObjectsNearPos(s32, s32, s32, void *, f32, s32);
extern u8 gTrackMarkerDone;
extern s32 sBonusObjectTable;
extern u8 sDifficultyLevel;
inline static s32 inline_fn(u8 arg0)
{
  return arg0;
}

/* Per-frame state machine for a switch/trigger actor: toggles marker flags and plays a sound when pressed, optionally moves the actor, then releases. */
void updateTriggerSwitch(void *actor)
{
  int __repair_constant = 0xFF;
  s16 state;
  s32 var_v0;
  s32 __repair_phase_var_v0;
  u16 soundId;
  u16 temp_v0;
  int colorValue;
  u16 temp_v0_2;
  u16 temp_v0_3;
  u16 temp_v1_3;
  u16 temp_v1_4;
  u16 temp_v1_5;
  u8 temp_v1;
  void *def;
  def = *((void **) (((char *) actor) + 0x6C));
  if ((*((u16 *) (((char *) def) + 0x3A))) == 1)
  {
    temp_v1 = *((u8 *) (((s8 *) (&gTrackMarkerDone)) + (*((u16 *) (((char *) def) + 0x34)))));
    if (temp_v1 < 2U)
    {
      effectSetAnimFrame(actor, (*((u16 *) (((char *) def) + 0x3C))) + temp_v1, *((u16 *) (((char *) def) + 0x3E)));
    }
  }
  if ((*((s32 *) (((char *) actor) + 0x60))) & 0x100000)
  {
    *((s32 *) (((char *) actor) + 0x60)) = 0;
  }
  if (((((sDifficultyLevel == 0) && (sBonusObjectTable != 0)) && ((*((s32 *) (((char *) def) + 0x4C))) & 0x80)) && ((*((s32 *) (((char *) actor) + 0x58))) & 4)) && (approxDistance(actor + 0x24, sBonusObjectTable + 0x24) < 4.0f))
  {
    if ((*((s32 *) (((char *) def) + 0x2C))) & 0x08000802)
    {
      temp_v0 = (*((u16 *) (((char *) def) + 0x42))) + 1;
      *((u16 *) (((char *) def) + 0x42)) = temp_v0;
      if (!(temp_v0 & 0x10))
      {
        colorValue = 0xBF;
        goto L_tail;
      }
      *((u8 *) (((char *) actor) + 0x7F)) = 0xFF;
      *((u8 *) (((char *) actor) + 0x80)) = 0xFF;
      *((u8 *) (((char *) actor) + 0x81)) = 0xFF;
    }
    else
    {
      colorValue = 0xFF;
      L_tail:
      *((u8 *) (((char *) actor) + 0x81)) = colorValue;
      *((u8 *) (((char *) actor) + 0x80)) = colorValue;
      *((u8 *) (((char *) actor) + 0x7F)) = colorValue;
    }
  }
  state = *((s16 *) (((char *) actor) + 0x7A));
  switch (state)
  {
    case 0:
      if (((*((s32 *) (((char *) actor) + 0x60))) & (*((s32 *) (((char *) def) + 0x2C)))) && (((temp_v0_2 = *((u16 *) (((char *) def) + 0x36)), temp_v0_2 == 0)) || (inline_fn(*((u8 *) (((s8 *) (&gTrackMarkerDone)) + temp_v0_2))) == (*((u16 *) (((char *) def) + 0x38))))))
    {
      temp_v1_3 = *((u16 *) (((char *) def) + 0x34));
      if (temp_v1_3 != 0)
      {
        *((u8 *) (((s8 *) (&gTrackMarkerDone)) + temp_v1_3)) = (*((u8 *) (((s8 *) (&gTrackMarkerDone)) + temp_v1_3))) ^ 1;
      }
      temp_v1_3 = *((u16 *) (((char *) def) + 0x40));
      if (temp_v1_3 != 0)
      {
        playSoundAtPos(temp_v1_3, actor + 0x24);
      }
      *((s16 *) (((char *) actor) + 0x7A)) = 1;
    }
      break;

    case 1:
      if (!((*((s32 *) (((char *) actor) + 0x60))) & (*((s32 *) (((char *) def) + 0x2C)))))
    {
      *((s16 *) (((char *) actor) + 0x7A)) = 2;
    }
      break;

    case 2:
      if ((*((s32 *) (((char *) def) + 4))) != 0)
    {
      markObjectsNearPos(*((s32 *) (((char *) actor) + 0x20)), 0, 0x01000000, actor + 0x24, (*((f32 *) (((char *) (*((void **) (((char *) actor) + 0x70)))) + 0x14))) + 1.0f, 0);
      if ((advanceActorMotion(actor, 1) << 0x18) != 0)
      {
        *((f32 *) (((char *) def) + 8)) = 1.0f;
        *((s16 *) (((char *) actor) + 0x7A)) = 3;
      }
    }
    else
    {
      *((s16 *) (((char *) actor) + 0x7A)) = 3;
    }
      break;

    case 3:
      if (((*((s32 *) (((char *) actor) + 0x60))) & (*((s32 *) (((char *) def) + 0x2C)))) && (((temp_v0_3 = *((u16 *) (((char *) def) + 0x36)), temp_v0_3 == 0)) || ((*((u8 *) (((s8 *) (&gTrackMarkerDone)) + temp_v0_3))) == (*((u16 *) (((char *) def) + 0x38))))))
    {
      temp_v1_4 = *((u16 *) (((char *) actor) + 0x78));
      if (temp_v1_4 != 0x12)
      {
        if (temp_v1_4 != 0x60)
        {
          if ((*((u16 *) (((char *) def) + 0x34))) != 0)
          {
            *((s16 *) (((char *) actor) + 0x7A)) = 4;
          }
          __repair_phase_var_v0 = (u16) (*((u16 *) (((char *) def) + 0x34)));
          *((u8 *) (((s8 *) (&gTrackMarkerDone)) + __repair_phase_var_v0)) = (*((u8 *) (((s8 *) (&gTrackMarkerDone)) + __repair_phase_var_v0))) ^ 1;
          soundId = *((u16 *) (((char *) def) + 0x40));
          if (soundId != 0)
          {
            playSoundAtPos(soundId, actor + 0x24);
          }
        }
      }
    }
      break;

    case 4:
      if (!((*((s32 *) (((char *) actor) + 0x60))) & (*((s32 *) (((char *) def) + 0x2C)))))
    {
      *((s16 *) (((char *) actor) + 0x7A)) = 5;
    }
      break;

    case 5:
      if ((*((s32 *) (((char *) def) + 4))) != 0)
    {
      markObjectsNearPos(*((s32 *) (((char *) actor) + 0x20)), 0, 0x01000000, actor + 0x24, (*((f32 *) (((char *) (*((void **) (((char *) actor) + 0x70)))) + 0x14))) + 1.0f, 0);
      if ((advanceActorMotion(actor, -1) << 0x18) != 0)
      {
        *((f32 *) (((char *) def) + 8)) = 1.0f;
        goto block_45;
      }
    }
    else
    {
      block_45:
      *((s16 *) (((char *) actor) + 0x7A)) = 0;

    }
      break;

  }

  *((s32 *) (((char *) actor) + 0x60)) = (s32) ((*((s32 *) (((char *) actor) + 0x60))) & 1);
}
