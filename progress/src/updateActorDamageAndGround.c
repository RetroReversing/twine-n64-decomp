typedef struct 
{
  f32 x;
  f32 y;
  f32 z;
} HitVec;
f32 vec3DistanceBetween(f32 *, void *);
f32 absFloat(f32);
s32 actorFinishIfMatch(void *, s32);
s32 angleDelta12(s32, s32);
f32 approximateAtan2(f32, f32);
s32 clearProbeState(void *, s32);
f32 cosAngle(f32);
s32 effectSetAnimFrame(void *, s32, s32);
s32 freeMenuItemRecord(void *, void *);
s32 func_80002BD0(void *, s32);
s32 resetHiscoresAndEnterTransition(s32);
void *func_80015F0C();
s32 linkNodeAfter(void *, void *);
s32 vec3Subtract(void *, void *, s32 *);
f32 vec3NormalizeLength(s32 *, s32 *);
s32 vec3Scale(s32 *, f32, s32 *);
s32 setActorStateAndReset(void *, s32);
s32 clearActorSubstateFields(void *);
s32 updateCameraFollowMode(void *);
s32 setActorGlowColor(void *);
s32 updateActorGroundPhysics(s32, void *, s32, s32 *, void **, void **, s32 *, s32 *);
s32 func_80070730(void *, s32, s32);
s32 setObjectsOfType25ToState8(void);
s32 setSaveSlotEntryPercent(char, s32, s32);
s32 playRandomTrackMarkerSound(void *, s32, s32);
s32 playFootstepSound(void *, s32, s32);
s32 playMarkerVariantSound(void *, s32, s32);
s32 playRandomDistanceSound();
s32 func_8008558C(void *);
void *func_8011B3D8(s32);
s32 getSaveSlotIndex(s32);
s32 initObjectFromBankEntry(void *, s32, s32);
s32 randomIntBelow(s32);
s32 randomU32Next();
s32 requestSound(s32);
s32 segmentClosestPoint(f32 *, void *, void *, void *);
f32 sinAngle(f32);
s32 updateSwingAnimation(void *, f32);
s32 vec3Add(s32 *, s32 *, s32 *);
extern s32 D_800BF688;
extern u8 D_800C7DAC[];
typedef struct 
{
  s32 f0;
  s32 unused;
} Slot_800C7DC8;
extern Slot_800C7DC8 D_800C7DC8[];
typedef struct 
{
  s32 f0;
  s32 unused;
} Slot_800C7DCC;
extern Slot_800C7DCC D_800C7DCC[];
extern f64 D_800D4650;
extern s8 gSpecialTriggerHit;
extern f32 D_800E19F8;
extern f32 D_800E19FC;
extern s32 D_800E1A04;
extern s32 D_800E1A08;
extern s32 D_800E1A24;
extern u8 D_801002D5;
extern u8 D_80100B18;
extern u8 D_80109A73;
extern s32 D_80112F68;
extern u8 gBorderFlipFlag;
extern s32 gBorderSkipActive;
extern s32 gGameMode;
extern u8 gSaveKeyRelaxed;
extern s32 gSaveSlotCount;
extern s32 gSaveSlotInfo;
extern s32 gSwingPhase;
extern s32 gVisibleSaveSlotCount;
extern u8 gWheelsGrounded;
extern u8 sDifficultyLevel;
extern void *gTrackMarkerParents[];
typedef struct 
{
  unsigned char pad_0[96];
  int field_60;
  unsigned char pad_64[12];
  void *field_70;
} __repair_record_sp38;
inline static s32 inline_fn()
{
  return (s32) sDifficultyLevel;
}

typedef struct 
{
  f32 v;
} Field_f32;
typedef struct 
{
  s16 v;
} Field_s16;
typedef struct 
{
  s32 v;
} Field_s32;
typedef struct 
{
  s8 v;
} Field_s8;
typedef struct 
{
  u16 v;
} Field_u16;
typedef struct 
{
  u32 v;
} Field_u32;
typedef struct 
{
  u8 v;
} Field_u8;
/* Per-frame actor update: applies incoming hit damage (scaled by difficulty), spawns hit markers and sounds, then runs ground physics, ledge grabs and swing animation. */ void updateActorDamageAndGround(void *actor)
{
  struct 
  {
    s32 vec20[3];
    s32 pad2C;
    s32 flags30;
    void *out34;
    void *out38;
    s32 flags3C;
    s32 out40;
    s32 pad44;
    f32 vec48[3];
    s32 pad54;
    f32 vec58[3];
    s32 framePad[1];
  } locals;
  const u8 *table;
  s32 *temp_s0_2;
  s32 var_a1_2;
  s32 var_a2_3;
  f32 temp_fa0;
  f32 temp_fa0_2;
  f32 temp_fs0;
  f32 temp_fv0;
  f32 temp_fv0_2;
  f32 temp_fv0_3;
  f32 temp_fv1;
  f32 temp_fv1_2;
  f32 temp_fv1_3;
  f32 damage;
  f32 var_fv0;
  f32 var_fv0_2;
  f32 var_fv1;
  f64 var_ft0;
  s16 temp_v0_10;
  s16 temp_v0_14;
  s16 var_a1;
  s32 temp_s1;
  s32 groundObj;
  unsigned int temp_v0_4;
  s32 temp_v0_5;
  s32 temp_v0_7;
  s32 temp_v1;
  s32 temp_v1_2;
  s32 temp_v1_3;
  s32 var_a0;
  s32 var_a0_2;
  s32 var_a2;
  s32 var_a2_2;
  s32 var_condition_bit;
  s32 var_s0;
  unsigned short var_v0;
  s32 var_v0_2;
  s32 var_v0_3;
  s32 var_v1;
  s8 temp_a0;
  int slotIndex;
  s32 temp_v0_2;
  short var_a0_3;
  u32 temp_v0_8;
  u32 temp_v0_9;
  void *temp_a1;
  register void *temp_s0_3;
  void *actorState;
  void *temp_v0;
  void *temp_v0_11;
  void *temp_v0_12;
  void *temp_v0_13;
  void *temp_v0_15;
  void *temp_v0_3;
  void *temp_v0_6;
  s32 tw;
  void *pb;
  void *p24;
  void *p6;
  void *temp_v1_4;
  void *temp_v1_5;
  s16 sv;
  u32 wq;
  s32 o40;
  actorState = *((void **) (((char *) actor) + 0x6C));
  slotIndex = ((Field_s8 *) (((char *) actorState) + 0x182))->v;
  damage = 0.0f;
  locals.out40 = 0;
  locals.out34 = NULL;
  locals.out38 = NULL;
  locals.flags3C = 0;
  locals.flags30 = 0;
  groundObj = ((Field_s32 *) (((char *) actor) + 0x20))->v;
  if (((gBorderSkipActive != 0) && (gSaveKeyRelaxed != 0)) && (D_801002D5 == 0))
  {
    temp_v0 = func_8011B3D8(((Field_s32 *) (((char *) actorState) + 0x1B8))->v);
    if ((temp_v0 != NULL) && (((*((u8 *) (((char *) (*((void **) (((char *) actorState) + 0xB4)))) + 0x12))) == (*((u8 *) (((char *) (*((void **) (((char *) temp_v0) + 0xB4)))) + 0x12)))) & (((s32) actorState) != ((s32) temp_v0))))
    {
      ((Field_s32 *) (((char *) actor) + 0x60))->v = (s32) (((Field_s32 *) (((char *) actor) + 0x60))->v & (~0x62));
    }
  }
  if ((D_80112F68 == 0) && ((sv = ((Field_s16 *) (((char *) actor) + 0x7A))->v) == 1))
  {
    if (((Field_s8 *) (((char *) actorState) + 0x198))->v > 0)
    {
      ((Field_s8 *) (((char *) actorState) + 0x198))->v--;
    }
    if (((Field_s32 *) (((char *) actor) + 0x60))->v & 0x20)
    {
      ((Field_s8 *) (((char *) actorState) + 0x198))->v = 0;
    }
    if (((Field_s32 *) (((char *) actor) + 0x60))->v & 4)
    {
      playRandomDistanceSound();
      ((Field_s32 *) (((char *) actor) + 0x60))->v = (s32) (((Field_s32 *) (((char *) actor) + 0x60))->v & (~4));
    }
    temp_v1 = ((Field_s32 *) (((char *) actor) + 0x60))->v;
    if (temp_v1 & 0x42000022)
    {
      if (temp_v1 & 0x40000020)
      {
        wq = ((Field_u32 *) (((char *) actorState) + 0x18C))->v;
        wq &= 0xFFFF0FFF;
        wq |= 0x7000;
        damage = ((Field_f32 *) (((char *) actorState) + 0x1B0))->v;
        ((Field_f32 *) (((char *) actorState) + 0x1B0))->v = 0.0f;
        ((Field_u32 *) (((char *) actorState) + 0x18C))->v = wq;
      }
      if (((Field_s32 *) (((char *) actor) + 0x60))->v & 2)
      {
        if (gBorderSkipActive != 0)
        {
          temp_v0_3 = func_8011B3D8(((Field_s32 *) (((char *) actorState) + 4))->v);
          table = D_800C7DAC;
          if (temp_v0_3 != NULL)
          {
            temp_a0 = ((Field_s8 *) (((char *) temp_v0_3) + 0x182))->v;
            if (temp_a0 >= gSaveSlotCount)
            {
              temp_v0_4 = (((u16) (*((u16 *) (((u8 *) (&D_800BF688)) + ((*((s32 *) (((u8 *) (&gSaveSlotInfo)) + ((getSaveSlotIndex(temp_a0 & 0xFFFF) & 0xFFFF) * 0x18)))) * 0xC))))) >> 5) & 7;
              switch (temp_v0_4)
              {
                case 1:

                default:
                  var_s0 = 1;
                  break;

                case 2:
                  var_s0 = 5;
                  break;

                case 3:
                  var_s0 = 0xA;
                  break;

                case 4:
                  var_s0 = 0x19;
                  break;

                case 5:
                  var_s0 = 0x32;
                  break;

              }

              if (((((Field_u32 *) (((char *) actorState) + 0x18C))->v & 0xF000) == 0xE000) && (var_s0 < randomIntBelow(0x64)))
              {
                ((Field_u32 *) (((char *) actorState) + 0x18C))->v = (u32) ((((Field_u32 *) (((char *) actorState) + 0x18C))->v & 0xFFFF0FFF) | 0x7000);
              }
            }
          }
          temp_fs0 = (*((f32 *) (((char *) actorState) + 0x1B0))) * ((f32) table[((*((u32 *) (((char *) actorState) + 0x18C))) >> 12) & 15]);
          temp_fv1 = temp_fs0 * 0.1f;
          var_a0 = (u32) temp_fv1;
          temp_v0_5 = randomIntBelow(var_a0);
          var_ft0 = (f64) temp_v0_5;
          if (temp_v0_5 < 0)
          {
            var_ft0 += D_800D4650;
          }
          damage = temp_fs0 + ((f32) ((s16) ((s32) (((f32) var_ft0) - (temp_fs0 * 0.05f)))));
          if (damage <= 0.0f)
          {
            *((f32 *) (((char *) actorState) + 0x1B0)) = 0.0f;
            damage = 1.0f;
          }
          else
          {
            *((f32 *) (((char *) actorState) + 0x1B0)) = 0.0f;
          }
        }
        else
        {
          if (sDifficultyLevel == sv)
          {
            goto normal_scale;
          }
          if (inline_fn() < 2)
          {
            goto low_scale;
          }
          if (sDifficultyLevel == 2)
          {
            goto high_scale;
          }
          low_scale:
          var_fv1 = 0.90000004f;

          goto apply_scale;
          normal_scale:
          var_fv1 = 1.35f;

          goto apply_scale;
          high_scale:
          var_fv1 = 1.8000001f;

          apply_scale:
          temp_fv0 = ((Field_f32 *) (((char *) actorState) + 0x1B0))->v;

          ((Field_f32 *) (((char *) actorState) + 0x1B0))->v = 0.0f;
          damage = temp_fv0 * var_fv1;
        }
      }
      if (!(((Field_s32 *) (((char *) actor) + 0x60))->v & 0x40000000))
      {
        temp_fv0_2 = ((Field_f32 *) (((char *) actorState) + 0x60))->v;
        if (((temp_fv0_2 > 0.0f) && (((Field_s8 *) (((char *) actorState) + 0x198))->v == 0)) && ((((Field_u32 *) (((char *) actorState) + 0x18C))->v & 0xF000) != 0xE000))
        {
          temp_fv0_3 = temp_fv0_2 - damage;
          ((Field_f32 *) (((char *) actorState) + 0x60))->v = temp_fv0_3;
          if (temp_fv0_3 < 0.0f)
          {
            ((Field_f32 *) (((char *) actorState) + 0x60))->v = 0.0f;
            damage = -temp_fv0_3;
            func_80070730(actorState, 0x1A, 1);
          }
          else
          {
            damage = 0.0f;
          }
        }
      }
      if (!(((Field_s32 *) (((char *) actor) + 0x60))->v & 0x02000000))
      {
        if (((Field_u16 *) (((char *) actor) + 0x78))->v == 2)
        {
          var_a2 = (((*(D_800C7DAC + ((((u32) ((Field_u32 *) (((char *) actorState) + 0x18C))->v) >> 0xC) & 0xF))) * 0x46) / 25) + 0x1E;
          if (var_a2 <= 0)
          {
            var_a2 = 1;
          }
          else
            if (var_a2 >= 0x65)
          {
            var_a2 = 0x64;
          }
          setSaveSlotEntryPercent(slotIndex, 8, var_a2);
        }
        if (((Field_s32 *) (((char *) actor) + 0x60))->v & 0x02000000)
        {
          goto block_62;
        }
        goto block_95;
      }
      block_62:
      if (gWheelsGrounded == 0)
      {
        if (randomIntBelow(0x1E) == 0)
        {
          ((Field_s8 *) (((char *) actorState) + 0x198))->v = 0;
          switch (sDifficultyLevel)
          {
            case 0:

            default:
              damage = 1.1f;
              break;

            case 1:
              damage = 1.15f;
              break;

            case 2:
              damage = 1.2f;
              break;

          }

          if (randomU32Next() & 1)
          {
            requestSound(0x1AB);
          }
          else
          {
            requestSound(0x1AC);
          }
        }
      }
      else
      {
        var_a0_2 = 8;
        if (((Field_s16 *) (((char *) actor) + 0x7C))->v == 6)
        {
          var_a0_2 = 0x10;
        }
        if (randomIntBelow(var_a0_2) == 0)
        {
          ((Field_s8 *) (((char *) actorState) + 0x198))->v = 0;
          if ((sDifficultyLevel != 1) && ((inline_fn() < 2) || (sDifficultyLevel != 2)))
          {
            damage = 1.0f;
          }
          else
          {
            damage = 2.0f;
          }
          temp_fv1_2 = ((Field_f32 *) (((char *) actor) + 0x74))->v;
          var_v0 = (u32) temp_fv1_2;
          if (!(var_v0 & 3))
          {
            func_8008558C(actor);
          }
        }
      }

      *((HitVec *) (((char *) actorState) + 0x1A0)) = *((HitVec *) (((char *) actor) + 0x24));
      if ((damage > 0.0f) && (((Field_u16 *) (((char *) actor) + 0x78))->v == 2))
      {
        var_a2_2 = (s32) (damage * 40.0f);
        if (var_a2_2 <= 0)
        {
          var_a2_2 = 1;
        }
        else
          if (var_a2_2 >= 0x65)
        {
          var_a2_2 = 0x64;
        }
        setSaveSlotEntryPercent(slotIndex, 8, var_a2_2);
        block_95:;
      }
      if (damage > 0.0f)
      {
        if (((Field_s8 *) (((char *) actorState) + 0x198))->v == 0)
        {
          ((Field_s8 *) (((char *) actorState) + 0x198))->v = 5;
          ((Field_f32 *) (((char *) actor) + 0x74))->v = (f32) (((Field_f32 *) (((char *) actor) + 0x74))->v - damage);
          if ((*((void **) (((char *) actorState) + 0x414))) == NULL)
          {
            temp_v0_6 = func_80015F0C();
            *((void **) (((char *) actorState) + 0x414)) = temp_v0_6;
            if (temp_v0_6 != NULL)
            {
              p6 = temp_v0_6;
              temp_s1 = (angleDelta12((s32) (approximateAtan2(((Field_f32 *) (((char *) actor) + 0x24))->v - ((Field_f32 *) (((char *) actorState) + 0x1A0))->v, (*((f32 *) (((char *) actor) - (-0x2C)))) - ((Field_f32 *) (((char *) actorState) + 0x1A8))->v) * 651.8986f), (s32) (((Field_f32 *) (((char *) actor) + 0x40))->v + 256.0f)) >> 9) & 7;
              temp_v0_7 = temp_s1 * 8;
              ((Field_s32 *) (((char *) p6) + 0x28))->v = (s32) ((((Field_s32 *) (((char *) p6) + 0x28))->v & (~0xFC)) | 0x10);
              initObjectFromBankEntry(p6, D_800C7DC8[temp_s1].f0, 0x1B);
              linkNodeAfter(*((void **) (((char *) actorState) + 0x414)), gTrackMarkerParents[slotIndex]);
              var_a1 = 0x140;
              var_a0_3 = 0xF0;
              if (gBorderSkipActive != 0)
              {
              if (gVisibleSaveSlotCount != 2)
              {
              var_v0_2 = temp_s1 * 8;
              if (gVisibleSaveSlotCount >= 2)
              {
              var_v0_2 = temp_s1 * 8;
              if (gVisibleSaveSlotCount < 5)
              {
              var_a1 = 0xA0;
              var_a0_3 = 0x78;
              goto block_108;
              }
              }
              }
              else
              {
              if (gBorderFlipFlag == 1)
              {
              var_a1 = 0xA0;
              }
              else
              {
              block_107:
              var_a0_3 = 0x78;
              }
              goto block_108;
              }
              }
              else
              {
              block_108:
              var_v0_2 = temp_s1 * 8;
              }
              
              ((Field_s16 *) (((char *) p6) + 0x20))->v = 0;
              ((Field_s16 *) (((char *) p6) + 0x22))->v = 0;
              ((Field_s16 *) (((char *) p6) + 0x26))->v = var_a1;
              ((Field_s8 *) (((char *) p6) + 0x29))->v = var_a0_3;
              ((Field_s16 *) (((char *) p6) + 0x1E))->v = (s16) (D_800C7DCC[temp_s1].f0 | 0x4402);
            }
          }
          setActorGlowColor(actor);
        }
        if ((!(((Field_s32 *) (((char *) actor) + 0x60))->v & 0x02000000)) || (gWheelsGrounded != 0))
        {
          var_a2_3 = 1;
          if (!(((Field_f32 *) (((char *) actor) + 0x74))->v > 0.0f))
          {
            var_a2_3 = 0;
          }
          playFootstepSound(actor, 1, var_a2_3);
        }
      }
      temp_v1_2 = ((Field_s32 *) (((char *) actor) + 0x60))->v;
      var_a2_3 = 1;
      if (temp_v1_2 & 0x40)
      {
        p24 = actor + 0x24;
        if (!(((Field_f32 *) (((char *) actor) + 0x74))->v > 0.0f))
        {
          var_a2_3 = 0;
        }
        playMarkerVariantSound(p24, 1, var_a2_3);
      }
      else
        if (temp_v1_2 & 2)
      {
        p24 = actor + 0x24;
        if (!(((Field_f32 *) (((char *) actor) + 0x74))->v > 0.0f))
        {
          var_a2_3 = 0;
        }
        playRandomTrackMarkerSound(p24, 1, var_a2_3);
      }
      if ((actorFinishIfMatch(actor, 2) << 0x18) == 0)
      {
        if (((Field_s32 *) (((char *) actor) + 0x60))->v & 0x40000022)
        {
          vec3Subtract(actorState + 0x1A0, actor + 0x24, locals.vec20);
          vec3NormalizeLength(locals.vec20, locals.vec20);
          vec3Scale(locals.vec20, 0.075f, locals.vec20);
          ;
          temp_s0_2 = actorState + 0x11C;
          vec3Add(locals.vec20, temp_s0_2, temp_s0_2);
          var_fv0 = vec3NormalizeLength(temp_s0_2, temp_s0_2);
          if (var_fv0 > 0.075f)
          {
            var_fv0 = 0.075f;
          }
          vec3Scale(temp_s0_2, var_fv0, temp_s0_2);
        }
        goto block_130;
      }
    }
    else
    {
      goto block_130;
    }
  }
  else
  {
    block_130:
    if (groundObj)
    {
      updateActorGroundPhysics(groundObj, actor, D_800E1A24, &locals.flags30, &locals.out34, &locals.out38, &locals.flags3C, &locals.out40);
    }

    temp_a1 = *((void **) (((char *) actorState) + 0x414));
    if (temp_a1 != NULL)
    {
      tw = ((Field_s32 *) (((char *) temp_a1) + 0x10))->v;
      temp_v0_8 = tw & 0xFF;
      temp_v0_9 = temp_v0_8 - (temp_v0_8 >> 2);
      ((Field_s32 *) (((char *) temp_a1) + 0x10))->v = (s32) ((tw & (~0xFF)) | temp_v0_9);
      if (temp_v0_9 < 4U)
      {
        freeMenuItemRecord(*((void **) (((char *) actorState) + 0x414)), temp_a1);
        *((void **) (((char *) actorState) + 0x414)) = NULL;
      }
    }
    if (((u32) (((u16) ((Field_s16 *) (((char *) actor) + 0x7A))->v) - 2)) >= 2U)
    {
      if (((((gSpecialTriggerHit == 0) && (gGameMode == 0xB)) && (locals.out38 != NULL)) && (D_80109A73 != 0)) && (((*((s32 *) (((char *) ((__repair_record_sp38 *) locals.out38)->field_70) + 0x30))) & 0xFFFF0) == 0x610))
      {
        gSpecialTriggerHit = 1;
        ((__repair_record_sp38 *) locals.out38)->field_60 = (s32) (((__repair_record_sp38 *) locals.out38)->field_60 | 1);
        setObjectsOfType25ToState8();
        resetHiscoresAndEnterTransition(7);
      }
      if ((locals.out34 != NULL) && (locals.flags30 & 1))
      {
        temp_v0_10 = ((Field_s16 *) (((char *) actor) + 0x7C))->v;
        if ((((temp_v0_10 != 1) & (temp_v0_10 != 3)) && (((Field_u8 *) (((char *) actorState) + 0x186))->v == 0)) && (((f32) angleDelta12((s32) ((Field_f32 *) (((char *) actor) + 0x40))->v, (s32) (((Field_f32 *) (((char *) locals.out34) + 0x34))->v * 651.8986f))) < 0.0f))
        {
          pb = locals.out34;
          ((Field_f32 *) (((char *) actorState) + 0x14))->v = (f32) ((((Field_f32 *) (((char *) pb) + 0x44))->v + ((Field_f32 *) (((char *) pb) + 0x4C))->v) + (-1.1f));
          ((Field_f32 *) (((char *) actorState) + 0x18))->v = (f32) ((((Field_f32 *) (((char *) pb) + 0x44))->v - ((Field_f32 *) (((char *) pb) + 0x4C))->v) + 0.9f);
          temp_fa0 = (((Field_f32 *) (((char *) pb) + 0x34))->v * 651.8986f) + 1024.0f;
          locals.vec48[1] = temp_fa0;
          locals.vec58[0] = ((Field_f32 *) (((char *) pb) + 0x24))->v;
          locals.vec58[1] = ((Field_f32 *) (((char *) actor) + 0x28))->v;
          locals.vec58[2] = ((Field_f32 *) (((char *) pb) + 0x2C))->v;
          locals.vec58[0] -= sinAngle(temp_fa0) * 0.43f;
          locals.vec58[2] -= cosAngle(locals.vec48[1]) * 0.43f;
          if ((!(locals.vec58[1] > ((Field_f32 *) (((char *) actorState) + 0x14))->v)) && (!(locals.vec58[1] < ((Field_f32 *) (((char *) actorState) + 0x18))->v)))
          {
            *((HitVec *) (((char *) actor) + 0x24)) = *((HitVec *) locals.vec58);
            ((Field_f32 *) (((char *) actor) + 0x3C))->v = 0.0f;
            ((Field_f32 *) (((char *) actor) + 0x40))->v = locals.vec48[1];
            ((Field_f32 *) (((char *) actor) + 0x44))->v = 0.0f;
            ((Field_f32 *) (((char *) actorState) + 0x90))->v = (f32) ((Field_f32 *) (((char *) actor) + 0x40))->v;
            if (absFloat(((Field_f32 *) (((char *) actor) + 0x28))->v - ((Field_f32 *) (((char *) actorState) + 0x18))->v) < 0.15f)
            {
              var_a1_2 = 0x296;
              func_80002BD0(actor, var_a1_2);
              temp_v1_4 = *((void **) (((char *) actor) + 0x68));
              ((Field_u16 *) (((char *) temp_v1_4) + 0xC))->v = (u16) (((Field_u16 *) (((char *) temp_v1_4) + 0xC))->v | 0x40);
            }
            else
            {
              var_a1_2 = 0x297;
              if (absFloat(((Field_f32 *) (((char *) actor) + 0x28))->v - ((Field_f32 *) (((char *) actorState) + 0x14))->v) < 0.15f)
              {
                func_80002BD0(actor, var_a1_2);
                temp_v1_4 = *((void **) (((char *) actor) + 0x68));
                ((Field_u16 *) (((char *) temp_v1_4) + 0xC))->v = (u16) (((Field_u16 *) (((char *) temp_v1_4) + 0xC))->v | 0x40);
              }
              else
              {
                func_80002BD0(actor, 0x295);
              }
            }
            requestSound(0x1B);
            *((s32 *) (((char *) (*((void **) (((char *) actor) + 0x68)))) + 0x30)) = 0;
            *((s32 *) (((char *) (*((void **) (((char *) actor) + 0x68)))) + 0x34)) = 0;
            clearActorSubstateFields(actor);
            setActorStateAndReset(actor, 1);
            ((Field_s8 *) (((char *) actorState) + 0x181))->v = 1;
            ((Field_s8 *) (((char *) actorState) + 0x17E))->v = 2;
          }
        }
      }
      switch (D_80100B18)
      {
        case 0:
          if (((Field_s8 *) (((char *) actorState) + 0x19C))->v != 0)
        {
          temp_v0_11 = *((void **) (((char *) actorState) + 0xC4));
          *((HitVec *) (((char *) temp_v0_11) + 0x24)) = *((HitVec *) (((char *) actorState) + 0xEC));
          *((f32 *) (((char *) (*((void **) (((char *) actorState) + 0xC4)))) + 0x3C)) = -1024.0f;
          *((s32 *) (((char *) (*((void **) (((char *) actorState) + 0xC4)))) + 0x40)) = 0;
          *((s32 *) (((char *) (*((void **) (((char *) actorState) + 0xC4)))) + 0x44)) = 0;
          *((f32 *) (((char *) (*((void **) (((char *) actorState) + 0xC4)))) + 0x54)) = 0.0f;
          effectSetAnimFrame(*((void **) (((char *) actorState) + 0xC4)), 0xC, 0x1B);
          var_fv0_2 = (((Field_f32 *) (((char *) actorState) + 0xF0))->v - ((Field_f32 *) (((char *) actorState) + 0xFC))->v) - 0.4f;
          if (var_fv0_2 < 0.4f)
          {
            var_fv0_2 = 0.4f;
          }
          D_80100B18 = 1;
          D_800E19FC = var_fv0_2;
          gSwingPhase = 0;
          D_800E1A04 = 0;
          D_800E1A08 = 0;
          if (((Field_s16 *) (((char *) actor) + 0x7C))->v == 3)
          {
            ((Field_s32 *) (((char *) actorState) + 0xCC))->v = 0;
            ((Field_s8 *) (((char *) actorState) + 0x188))->v = 0x14;
            setActorStateAndReset(actor, 0);
          }
        }
          break;

        case 1:
          updateSwingAnimation(actor, randomFloatScaled(0.1f) + 0.1f);
          temp_v0_12 = *((void **) (((char *) actorState) + 0xC4));
          ((Field_f32 *) (((char *) temp_v0_12) + 0x54))->v = (f32) (((Field_f32 *) (((char *) temp_v0_12) + 0x54))->v + (D_800E19FC * 0.016666668f));
          temp_v0_13 = *((void **) (((char *) actorState) + 0xC4));
          if (D_800E19FC <= ((Field_f32 *) (((char *) temp_v0_13) + 0x54))->v)
        {
          ((Field_f32 *) (((char *) temp_v0_13) + 0x54))->v = (f32) D_800E19FC;
          D_80100B18 = 2;
        }
          break;

        case 2:
          updateSwingAnimation(actor, 0.01f);
          temp_v0_14 = ((Field_s16 *) (((char *) actor) + 0x7C))->v;
          if (((temp_v0_14 != 3) & (temp_v0_14 != 1)) && (((Field_s8 *) (((char *) actorState) + 0x188))->v == 0))
        {
          temp_s0_3 = actor + 0x24;
          segmentClosestPoint(locals.vec48, actorState + 0xEC, actorState + 0xF8, temp_s0_3);
          if (vec3DistanceBetween(locals.vec48, temp_s0_3) < 0.8f)
          {
            temp_fa0_2 = approximateAtan2(((Field_f32 *) (((char *) actor) + 0x24))->v - locals.vec48[0], ((Field_f32 *) (((char *) actor) + 0x2C))->v - locals.vec48[2]) * 651.8986f;
            temp_fv1_3 = (f32) (((s32) ((((s32) ((Field_f32 *) (((char *) actor) + 0x40))->v) - ((s32) temp_fa0_2)) << 0x14)) >> 0x14);
            D_800E19F8 = temp_fa0_2;
            var_v0_3 = 1;
            if (!(temp_fv1_3 > 1800.0f))
            {
              var_v0_3 = 0;
            }
            var_v1 = 1;
            if (!(temp_fv1_3 < (-1800.0f)))
            {
              var_v1 = 0;
            }
            if ((var_v0_3 | var_v1) != 0)
            {
              ((Field_f32 *) (((char *) actor) + 0x40))->v = (f32) (temp_fa0_2 + 2048.0f);
              locals.vec48[0] = ((Field_f32 *) (((char *) actorState) + 0xEC))->v + (sinAngle(temp_fa0_2) * 0.22500001f);
              locals.vec48[2] = ((Field_f32 *) (((char *) actorState) + 0xF4))->v + (cosAngle(D_800E19F8) * 0.22500001f);
              *((HitVec *) (((char *) actor) + 0x24)) = *((HitVec *) locals.vec48);
              clearActorSubstateFields(actor);
              setActorStateAndReset(actor, 3);
              clearProbeState(actor, 0x159);
              ((Field_s8 *) (((char *) actorState) + 0x17E))->v = 2;
              ((Field_s8 *) (((char *) actorState) + 0x181))->v = 1;
              *((s32 *) (((char *) (*((void **) (((char *) actor) + 0x68)))) + 0x34)) = 0;
            }
          }
        }
          break;

      }

      temp_v0_15 = *((void **) (((char *) actor) + 0x68));
      o40 = locals.out40;
      ((Field_u16 *) (((char *) temp_v0_15) + 0xC))->v = (u16) (((Field_u16 *) (((char *) temp_v0_15) + 0xC))->v & 0xFFFB);
      if ((o40 != 0) && (locals.flags3C & 2))
      {
        temp_v1_5 = *((void **) (((char *) actor) + 0x68));
        ((Field_u16 *) (((char *) temp_v1_5) + 0xC))->v = (u16) (((Field_u16 *) (((char *) temp_v1_5) + 0xC))->v | 4);
      }
    }
    ((Field_s32 *) (((char *) actor) + 0x60))->v = (s32) (((Field_s32 *) (((char *) actor) + 0x60))->v & 0xBDFFFF9D);
    *((s32 *) (((char *) gTrackMarkerParents[slotIndex]) + 0xFC)) = (s32) ((Field_u8 *) (((char *) actorState) + 0x184))->v;
    ((Field_s32 *) (((char *) actor) + 0x58))->v = (s32) (((Field_s32 *) (((char *) actor) + 0x58))->v | 1);
    updateCameraFollowMode(actor);
    ((Field_s32 *) (((char *) actorState) + 4))->v = 0;
  }
}


