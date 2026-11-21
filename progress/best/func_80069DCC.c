typedef struct 
{
  f32 x;
  f32 y;
  f32 z;
} CopyVec3;
f32 absFloat(f32);
s32 actorInitFromSpawn(void *, void *, void *);
s32 actorUpdateBorderFade(void *);
s32 actorUpdateGatedState(void *, s32);
s32 clearProbeState(void *, u16);
f32 cosAngle(f32);
f32 cosTableLookup(f32);
s32 func_80002BD0(void *, s32);
s32 func_80002D50(void *, s32);
s32 func_80002EF0(void *);
s32 func_800179E8(void *, void *, s32, s32);
s32 func_800452E0(void *, void *, f32 *);
f32 func_8004572C(f32 *);
s32 func_80047B14(void *, f32, void *);
s32 func_80047FB4(s32, s32);
s32 func_8004BCC0(void *, void *, f32 *, f32);
s32 func_800635BC(void *, s32);
f32 func_80063758(f32, f32, f32);
s32 func_80064318(s32, s8);
s32 func_80065684(void *);
s32 func_80065D90(void *);
s32 func_80067E94(void *);
s32 func_8006899C(void *, s32);
s32 func_80069250(void *);
s32 func_800698D8(void *, f32, f32);
f32 func_80069998(void);
f32 func_80069A14(f32);
s32 func_8006D2E4(void *);
s32 func_8006E648(void *, void *, s32, s32 *, s32 *, s32 *, s32 *, s32 *);
s32 func_8007092C(void *, s32);
s32 func_80070F34(void *);
s32 func_800818AC(s32, s32);
s32 func_8008194C(s32, s32);
s32 func_80081AA4(s32, s32);
f32 func_80081B44(s32, s32, s32);
s32 func_80081CC0(int);
s32 func_80081D00(s32);
s32 func_80081D20(s32, s32);
s32 func_80119DB4(void *, void *);
s32 func_8011A234(void *, void *, f32, f32, s32, s32);
void *getObjectListHead(s8);
s32 listUnlinkFree(s32);
f32 probeTrackSteerAngle(void *, void *);
s32 requestSound(s32);
s32 setTrackMarkerActive(s32, void *);
f32 sinAngle(f32);
f32 sinTableLookup(f32);
s32 updateAirTimeGauge(void *);
s32 updateHudSprites(void *);
s32 updateSwayMotion(void *);
extern s32 D_800C4710;
extern u16 D_800C7C8E;
extern f32 D_800C7DBC;
extern f32 D_800C7DC4;
extern f64 D_800D45E0;
extern f64 D_800D45E8;
extern f32 D_800E19F0;
extern f32 D_800E19F8;
extern f32 D_800E1A04;
extern f32 D_800E1A08;
extern u8 D_800E1A0C;
extern f32 D_800E1A10;
extern s32 D_800E1A18;
extern f32 D_800E1A1C;
extern s8 D_800E1A20;
extern s32 D_800E1A24;
extern s32 D_800E1A28;
extern s32 D_800E1A2C;
extern u8 D_801002AE;
extern s8 D_80103EB0;
extern s16 gAirTimeGauge;
extern s32 gBorderSkipActive;
extern s32 gGameMode;
extern s32 gSaveSlotCount;
extern u8 gSceneFlagsB;
extern u8 gWheelsGrounded;
extern u8 sBonusSlots[];
extern void *sTrackMarkerTable[];
inline static s8 inline_fn(char *arg0, int arg1)
{
  return *((s8 *) (arg0 + arg1));
}

inline static f32 *inline_fn2(void *arg0)
{
  return (f32 *) (((char *) arg0) + 0x4C);
}

inline static char *inline_fn23(char *arg0, int arg1)
{
  return arg0 + arg1;
}

volatile unsigned int func_80069DCC(void *arg0)
{
  f32 *__base_D_800C7DBC;
  void *__repair_hoisted;
  f32 sp20[3];
  s32 probeOutputs[5];
  CopyVec3 probe;
  volatile f32 sp5C;
  void *sp64;
  f32 temp_fa0;
  f32 temp_fa0_2;
  f32 temp_fa0_3;
  f32 temp_fa0_4;
  f32 temp_fs0;
  f32 temp_fs0_2;
  f32 temp_fs0_3;
  f32 temp_fs0_4;
  f32 temp_fs0_5;
  f32 temp_fs1;
  f32 temp_fs1_2;
  f32 temp_fs2;
  f32 temp_fs2_2;
  f32 temp_fs2_3;
  f32 temp_fs3;
  f32 temp_fs3_10;
  f32 temp_fs3_11;
  f32 temp_fs3_2;
  f32 temp_fs3_3;
  f32 temp_fs3_4;
  f32 temp_fs3_5;
  f32 temp_fs3_6;
  f32 temp_fs3_7;
  f32 temp_fs3_8;
  f32 temp_fs3_9;
  f32 temp_fs4;
  f32 temp_fs5;
  f32 temp_fs5_2;
  f32 temp_ft0;
  f32 temp_ft0_2;
  f32 temp_ft0_3;
  f32 temp_ft1;
  f32 temp_ft1_2;
  f32 temp_fv0;
  f32 temp_fv0_11;
  f32 temp_fv0_12;
  f32 temp_fv0_13;
  f32 temp_fv0_14;
  f32 temp_fv0_15;
  f32 temp_fv0_16;
  f32 temp_fv0_17;
  f32 temp_fv0_18;
  f32 temp_fv0_19;
  f32 temp_fv0_20;
  f32 temp_fv0_21;
  f32 temp_fv0_22;
  f32 temp_fv0_23;
  f32 temp_fv0_24;
  f32 temp_fv0_25;
  f32 temp_fv0_26;
  f32 temp_fv0_27;
  f32 temp_fv0_28;
  f32 temp_fv0_29;
  f32 temp_fv0_2;
  f32 temp_fv0_30;
  f32 temp_fv0_31;
  f32 temp_fv0_32;
  f32 temp_fv0_3;
  f32 temp_fv0_4;
  f32 temp_fv0_5;
  f32 temp_fv0_6;
  f32 temp_fv0_7;
  f32 temp_fv0_8;
  f32 temp_fv0_9;
  f32 temp_fv1;
  f32 temp_fv1_10;
  f32 temp_fv1_11;
  f32 temp_fv1_12;
  f32 temp_fv1_13;
  f32 temp_fv1_2;
  f32 temp_fv1_3;
  f32 temp_fv1_4;
  f32 temp_fv1_5;
  f32 temp_fv1_6;
  f32 temp_fv1_7;
  f32 temp_fv1_8;
  f32 temp_fv1_9;
  f32 temp_s5;
  f32 temp_s5_2;
  f32 temp_fv0_10;
  f32 temp_s6;
  f32 temp_s6_2;
  f32 var_a2;
  f32 var_fp;
  f32 var_fs1;
  f32 var_fs2;
  f32 var_fs2_2;
  f32 var_fs2_3;
  f32 var_fs2_4;
  f32 var_fs2_5;
  f32 var_fs3;
  f32 var_fs3_2;
  f32 var_fs3_3;
  f32 var_fs3_4;
  f32 var_fs3_5;
  f32 var_fs3_6;
  f32 var_fs3_7;
  f32 var_fs3_8;
  f32 var_fv0;
  f32 var_fv1;
  f32 var_fv1_2;
  f32 var_fv1_3;
  f32 var_fv1_4;
  f32 var_fv1_5;
  f32 var_fv1_6;
  f32 var_s5;
  f32 var_s6;
  s16 temp_v0;
  s16 temp_v1;
  s32 temp_v1_15;
  s16 temp_v1_16;
  s16 temp_v1_23;
  s16 temp_v1_24;
  s16 temp_v1_27;
  s32 temp_a0;
  s32 temp_a0_4;
  s32 temp_v0_12;
  s32 temp_v1_7;
  s32 var_s0_3;
  s32 var_s3;
  s32 var_v0;
  s32 var_v0_10;
  s32 var_v0_11;
  s32 var_v0_12;
  s32 var_v0_13;
  s32 var_v0_14;
  s32 var_v0_15;
  s32 var_v0_16;
  s32 var_v0_17;
  s32 var_v0_18;
  s32 var_v0_19;
  s32 var_v0_20;
  s32 var_v0_21;
  s32 var_v0_22;
  s32 var_v0_23;
  s32 var_v0_24;
  s32 var_v0_2;
  s32 var_v0_3;
  s32 var_v0_4;
  s32 var_v0_5;
  s32 var_v0_6;
  s32 var_v0_7;
  s32 var_v0_8;
  s32 var_v0_9;
  s32 var_v1;
  s32 var_v1_10;
  s32 var_v1_11;
  s32 var_v1_12;
  s32 var_v1_13;
  s32 var_v1_14;
  s32 var_v1_15;
  s32 var_v1_16;
  s32 var_v1_17;
  s32 var_v1_18;
  s32 var_v1_19;
  s32 var_v1_20;
  s32 var_v1_21;
  s32 var_v1_22;
  s32 var_v1_23;
  s32 var_v1_2;
  s32 var_v1_3;
  s32 var_v1_4;
  s32 var_v1_5;
  s32 var_v1_6;
  s32 var_v1_7;
  s32 var_v1_8;
  s32 var_v1_9;
  s32 temp_s4;
  s8 temp_v0_3;
  unsigned char temp_v0_6;
  s8 temp_v0_7;
  s8 temp_v1_21;
  unsigned short temp_v1_22;
  s8 temp_v1_25;
  s8 temp_v1_26;
  s8 temp_v1_31;
  u16 temp_a0_7;
  u16 temp_v0_11;
  u16 temp_v1_17;
  u16 temp_v1_28;
  u16 temp_v1_2;
  u16 temp_v1_30;
  u16 temp_v1_3;
  u8 temp_v0_2;
  u8 temp_v0_5;
  u8 temp_v1_20;
  u8 temp_v1_35;
  u8 var_s0;
  void *temp_a0_10;
  void *temp_a0_2;
  void *temp_a0_3;
  void *temp_a0_5;
  void *temp_a0_6;
  void *temp_a0_8;
  void *temp_a0_9;
  void *temp_a1;
  void *temp_s1;
  void *temp_v0_10;
  void *temp_v0_4;
  void *temp_v0_8;
  void *temp_v0_9;
  void *temp_v1_10;
  void *temp_v1_11;
  void *temp_v1_12;
  void *temp_v1_13;
  void *temp_v1_14;
  void *temp_v1_18;
  void *temp_v1_19;
  void *temp_v1_29;
  void *temp_v1_32;
  void *temp_v1_33;
  void *temp_v1_34;
  void *temp_v1_36;
  void *temp_v1_4;
  void *temp_v1_5;
  void *temp_v1_6;
  void *temp_v1_8;
  void *temp_v1_9;
  void *var_s0_2;
  void *var_v0_25;
  temp_s1 = *((void **) (((char *) arg0) + 0x6C));
  sp64 = *((void **) (((char *) arg0) + 0x20));
  temp_s4 = inline_fn((char *) temp_s1, 0x182);
  __repair_hoisted = *((void **) (((char *) arg0) + 0x20));
  if (D_80103EB0 == 0)
  {
    temp_a0 = *((s32 *) (((char *) temp_s1) + 8));
    *((s32 *) (((char *) temp_s1) + 0x1B0)) = 0;
    if (temp_a0 != (-1))
    {
      listUnlinkFree(temp_a0);
      *((s32 *) (((char *) temp_s1) + 8)) = -1;
    }
    func_8006E648(__repair_hoisted, arg0, 0, &probeOutputs[0], &probeOutputs[1], &probeOutputs[2], &probeOutputs[3], &probeOutputs[4]);
    func_80002EF0(arg0);
    func_80070F34(arg0);
    temp_v1 = *((s16 *) (((char *) arg0) + 0x7A));
    if (temp_v1 < 4)
    {
      if (temp_v1 < 2)
      {
        *((s32 *) (((char *) arg0) + 0x60)) = 0;
        return;
        if (1)
        {
        }
      }
      if ((*((u8 *) (((char *) temp_s1) + 0x5A8))) != 3)
      {
        *((s32 *) (((char *) arg0) + 0x60)) = 0;
        return;
      }
      actorUpdateGatedState(arg0, 2);
      goto block_11;
    }
    block_11:
    *((s32 *) (((char *) arg0) + 0x60)) = 0;

    return;
  }
  if (D_801002AE == 0)
  {
    D_800E1A24 = 0x10;
    D_800E1A28 = 0;
    if (temp_s1 != NULL)
    {
      if ((*((u8 *) (((char *) temp_s1) + 0x185))) == 1)
      {
        temp_v1_2 = *((u16 *) (((char *) temp_s1) + 0x520));
        if (temp_v1_2 < 2U)
        {
          requestSound(0x58);
          setTrackMarkerActive(0, temp_s1);
        }
        else
        {
          *((u16 *) (((char *) temp_s1) + 0x520)) = (u16) (temp_v1_2 - 1);
          updateHudSprites(temp_s1);
        }
      }
      else
      {
        temp_v1_3 = *((u16 *) (((char *) temp_s1) + 0x520));
        if (temp_v1_3 < 0x706U)
        {
          *((u16 *) (((char *) temp_s1) + 0x520)) = (u16) (temp_v1_3 + 2);
        }
      }
      if (gAirTimeGauge != 0x546)
      {
        temp_v1_4 = *((void **) (((char *) temp_s1) + 0x404));
        *((s32 *) (((char *) temp_v1_4) + 0x28)) = (s32) (((*((s32 *) (((char *) temp_v1_4) + 0x28))) & (~0xFC)) | 0x10);
        temp_v1_5 = *((void **) (((char *) temp_s1) + 0x408));
        *((s32 *) (((char *) temp_v1_5) + 0x28)) = (s32) (((*((s32 *) (((char *) temp_v1_5) + 0x28))) & (~0xFC)) | 0x10);
        temp_v1_6 = *((void **) (((char *) temp_s1) + 0x40C));
        *((s32 *) (((char *) temp_v1_6) + 0x28)) = (s32) (((*((s32 *) (((char *) temp_v1_6) + 0x28))) & (~0xFC)) | 0x10);
        temp_a0_2 = *((void **) (((char *) temp_s1) + 0x404));
        temp_v1_7 = *((s32 *) (((char *) temp_a0_2) + 0x10));
        if (((u32) (temp_v1_7 & 0xFF)) < 0xF7U)
        {
          *((s32 *) (((char *) temp_a0_2) + 0x10)) = (s32) (temp_v1_7 + 8);
          temp_v1_8 = *((void **) (((char *) temp_s1) + 0x408));
          *((s32 *) (((char *) temp_v1_8) + 0x10)) = (s32) ((*((s32 *) (((char *) temp_v1_8) + 0x10))) + 4);
          temp_v1_9 = *((void **) (((char *) temp_s1) + 0x40C));
          *((s32 *) (((char *) temp_v1_9) + 0x10)) = (s32) ((*((s32 *) (((char *) temp_v1_9) + 0x10))) + 8);
        }
        temp_fv1 = ((f32) gAirTimeGauge) * 0.035555556f;
        temp_a0_3 = *((void **) (((char *) temp_s1) + 0x404));
        *((s16 *) (((char *) temp_a0_3) + 0x26)) = (u32) temp_fv1;
      }
      else
      {
        temp_v1_10 = *((void **) (((char *) temp_s1) + 0x404));
        temp_a0_4 = *((s32 *) (((char *) temp_v1_10) + 0x10));
        if (((u32) (temp_a0_4 & 0xFF)) >= 8U)
        {
          *((s32 *) (((char *) temp_v1_10) + 0x10)) = (s32) (temp_a0_4 - 8);
          temp_v1_13 = *((void **) (((char *) temp_s1) + 0x408));
          *((s32 *) (((char *) temp_v1_13) + 0x10)) = (s32) ((*((s32 *) (((char *) temp_v1_13) + 0x10))) - 4);
          temp_v1_14 = *((void **) (((char *) temp_s1) + 0x40C));
          *((s32 *) (((char *) temp_v1_14) + 0x10)) = (s32) ((*((s32 *) (((char *) temp_v1_14) + 0x10))) - 8);
        }
        else
        {
          *((s32 *) (((char *) temp_v1_10) + 0x28)) = (s32) (((*((s32 *) (((char *) temp_v1_10) + 0x28))) & (~0xFC)) | 0x1C);
          temp_v1_11 = *((void **) (((char *) temp_s1) + 0x408));
          *((s32 *) (((char *) temp_v1_11) + 0x28)) = (s32) (((*((s32 *) (((char *) temp_v1_11) + 0x28))) & (~0xFC)) | 0x1C);
          temp_v1_12 = *((void **) (((char *) temp_s1) + 0x40C));
          *((s32 *) (((char *) temp_v1_12) + 0x28)) = (s32) (((*((s32 *) (((char *) temp_v1_12) + 0x28))) & (~0xFC)) | 0x1C);
        }
      }
    }
    temp_v1_15 = *((s16 *) (((char *) arg0) + 0x7A));
    D_800E1A18 = (s32) (*((u16 *) (((char *) (*((void **) (((char *) arg0) + 0x68)))) + 0xC)));
    if (temp_v1_15 != 1)
    {
      if (temp_v1_15 >= 2)
      {
        if (temp_v1_15 < 4)
        {
          if ((*((u8 *) (((char *) temp_s1) + 0x5A8))) == 3)
          {
            actorUpdateGatedState(arg0, 2);
          }
        }
      }
      else
        if (temp_v1_15 == 0)
      {
        *((f32 *) (((char *) temp_s1) + 0x20)) = 0.0f;
        temp_fs0 = *((f32 *) (((char *) temp_s1) + 0x20));
        *((s32 *) (((char *) temp_s1) + 0x1C)) = 0;
        *((s8 *) (((char *) temp_s1) + 0x19B)) = 0;
        *((f32 *) (((char *) temp_s1) + 0x38)) = temp_fs0;
        *((f32 *) (((char *) temp_s1) + 0x34)) = temp_fs0;
        *((f32 *) (((char *) temp_s1) + 0x44)) = 1.0f;
        *((f32 *) (((char *) temp_s1) + 0x40)) = 1.0f;
        *((f32 *) (((char *) temp_s1) + 0x3C)) = 1.0f;
        func_80081CC0(temp_s4);
        actorInitFromSpawn(arg0, arg0 + 0x24, arg0 + 0x3C);
        *((void **) (((char *) temp_s1) + 0xB8)) = NULL;
        if (gGameMode == 0x19)
        {
          func_800635BC(arg0, 2);
          func_80119DB4(arg0, temp_s1 + 0xB8);
          D_800E1A20 = 0;
          *((f32 *) (((char *) (*((void **) (((char *) temp_s1) + 0xB8)))) + 0x4C)) = temp_fs0;
          func_80081D00(temp_s4);
        }
        switch (gGameMode)
        {
          case 1:

          case 16:

          case 20:

          case 25:

          case 29:

          case 33:

          case 34:

          case 40:

          case 41:
            func_8007092C(arg0, 0);
            break;

        }

        if ((gBorderSkipActive != 0) && (gSaveSlotCount < (inline_fn((char *) temp_s1, 0x182) + 1)))
        {
          *((s16 *) (((char *) arg0) + 0x78)) = 3;
          *((s16 *) (((char *) arg0) + 0x7A)) = 0;
        }
      }
      goto block_474;
    }
    sp5C = 0.0f;
    D_800E1A1C = 0.0f;
    var_s6 = 0.0f;
    func_80065D90(arg0);
    var_fp = 0.0f;
    var_s5 = 0.0f;
    if (gWheelsGrounded != 0)
    {
      temp_v0 = ((u16) gAirTimeGauge) + 8;
      gAirTimeGauge = temp_v0;
      if (temp_v0 >= 0x547)
      {
        gAirTimeGauge = 0x546;
      }
    }
    temp_v0_2 = *((u8 *) (((char *) temp_s1) + 0x186));
    if (temp_v0_2 != 0)
    {
      *((u8 *) (((char *) temp_s1) + 0x186)) = (u8) (temp_v0_2 - 1);
    }
    temp_v0_3 = inline_fn((char *) temp_s1, 0x188);
    if (temp_v0_3 != 0)
    {
      *((s8 *) (((char *) temp_s1) + 0x188)) = (s8) (temp_v0_3 - 1);
    }
    temp_v1_16 = *((s16 *) (((char *) arg0) + 0x7C));
    switch (temp_v1_16)
    {
      case 0:
        if (actorUpdateBorderFade(arg0) == 0)
      {
        if (!(((s32) (*((u16 *) (((char *) (*((void **) (((char *) arg0) + 0x68)))) + 0xC)))) & 0x410000))
        {
          var_fs3 = func_80081B44(temp_s4, 0, 1);
          temp_fs5 = absFloat(var_fs3);
          if ((*((u16 *) (((char *) (*((void **) (((char *) arg0) + 0x68)))) + 0xC))) & 8)
          {
            var_v1 = 1;
            if (!(var_fs3 <= 0.0002f))
            {
              var_v1 = 0;
            }
            var_v0 = 1;
            if (!(var_fs3 >= (-0.0002f)))
            {
              var_v0 = 0;
            }
            if (((var_v0 ^ 1) | (var_v1 ^ 1)) != 0)
            {
              temp_fv0 = var_fs3 * var_fs3;
              if (var_fs3 > 0.0f)
              {
                var_fs3 = (temp_fv0 * 0.2f) + 0.01f;
              }
              else
              {
                var_fs3 = (temp_fv0 * (-0.1f)) - 0.01f;
              }
            }
            var_fs2 = 0.2f;
          }
          else
          {
            var_v1_2 = 1;
            if (!(var_fs3 <= 0.0002f))
            {
              var_v1_2 = 0;
            }
            var_v0_2 = 1;
            if (!(var_fs3 >= (-0.0002f)))
            {
              var_v0_2 = 0;
            }
            if (((var_v0_2 ^ 1) | (var_v1_2 ^ 1)) != 0)
            {
              temp_fv1_2 = var_fs3 * var_fs3;
              if (var_fs3 > 0.0f)
              {
                if (var_v0_14)
                {
                  var_fs3 = temp_fv1_2 * 0.1f;
                }
                else
                {
                  var_fs3 = temp_fv1_2 * 0.1f;
                }
              }
              else
              {
                var_fs3 = temp_fv1_2 * (-0.1f);
              }
            }
            var_fs2 = 0.01f;
          }
          temp_v1_17 = *((u16 *) (((char *) (*((void **) (((char *) arg0) + 0x68)))) + 0xC));
          if (temp_v1_17 & 4)
          {
            var_fs3 *= 0.5f;
          }
          if (temp_v1_17 & 0x200)
          {
            var_fs3 *= *((f32 *) (((char *) temp_s1) + 0x94));
          }
          temp_fv0_2 = *((f32 *) (((char *) temp_s1) + 0x4C));
          temp_fa0 = ((var_fs3 - temp_fv0_2) * var_fs2) + temp_fv0_2;
          var_v0_3 = 1;
          *((f32 *) (((char *) temp_s1) + 0x4C)) = temp_fa0;
          if (!(var_fs3 <= 0.0002f))
          {
            var_v0_3 = 0;
          }
          var_v1_3 = 1;
          if (!(var_fs3 >= (-0.0002f)))
          {
            var_v1_3 = 0;
          }
          if ((var_v0_3 & var_v1_3) && (absFloat(temp_fa0) < 0.01f))
          {
            *inline_fn2(temp_s1) = 0.0f;
          }
          temp_fv0_3 = *inline_fn2(temp_s1);
          var_fv1 = -0.2f;
          if ((temp_fv0_3 < (-0.2f)) || ((var_fv1 = 0.2f, temp_fv0_3 > 0.2f)))
          {
            *inline_fn2(temp_s1) = var_fv1;
          }
          temp_fs3 = *((f32 *) (((char *) temp_s1) + 0x4C));
          var_v1_4 = 1;
          if (!(temp_fs3 <= 0.0002f))
          {
            var_v1_4 = 0;
          }
          var_v0_4 = 1;
          if (!(temp_fs3 >= (-0.0002f)))
          {
            var_v0_4 = 0;
          }
          if (((var_v1_4 ^ 1) | (var_v0_4 ^ 1)) == 0)
          {
            D_800E1A28 |= 0x80000;
          }
          var_s5 = 0.0f + (temp_fs3 * sinAngle(*((f32 *) (((char *) arg0) + 0x40))));
          var_s6 = 0.0f + (temp_fs3 * cosAngle(*((f32 *) (((char *) arg0) + 0x40))));
          *((f32 *) (((char *) (*((void **) (((char *) arg0) + 0x68)))) + 0x34)) = temp_fs3;
          temp_fs2 = absFloat(temp_fs3);
          func_800452E0(temp_s1 + 0x128, arg0 + 0x24, &probe.x);
          *((CopyVec3 *) (((char *) temp_s1) + 0x128)) = *((CopyVec3 *) (((char *) arg0) + 0x24));
          probe.y = 0.0f;
          var_s0 = 1;
          if (func_8004572C(&probe.x) <= 0.001f)
          {
            temp_fs0_2 = *((f32 *) (((char *) temp_s1) + 0x58));
            var_fs1 = 0.0f;
            func_80065684(arg0);
            *((f32 *) (((char *) temp_s1) + 0x58)) = temp_fs0_2;
          }
          else
          {
            var_fs1 = temp_fs2 * 5.0f;
            var_v0_5 = 1;
            if (!(var_fs1 <= 0.0002f))
            {
              var_v0_5 = 0;
            }
            var_v1_5 = 1;
            if (!(var_fs1 >= (-0.0002f)))
            {
              var_v1_5 = 0;
            }
            var_s0 = 1;
            if (!(var_v0_5 & var_v1_5))
            {
              var_v0_6 = 1;
              if (!(temp_fs5 <= 0.0002f))
              {
                var_v0_6 = 0;
              }
              var_v1_6 = 1;
              if (!(temp_fs5 >= (-0.0002f)))
              {
                var_v1_6 = 0;
              }
              var_s0 = 1;
              if (!(var_v0_6 & var_v1_6))
              {
                var_s0 = 4;
                var_v0_7 = 1;
                if (!(temp_fs5 > 0.0f))
                {
                  var_v0_7 = 0;
                }
                var_v1_7 = 1;
                if (!(temp_fs5 < 1.0f))
                {
                  var_v1_7 = 0;
                }
                if (var_v0_7 & var_v1_7)
                {
                  if (var_fs1 < 0.375f)
                  {
                    var_s0 = 2;
                  }
                  else
                    if (var_fs1 < 0.75f)
                  {
                    var_s0 = 3;
                  }
                }
              }
            }
          }
          if (var_s0 != (*((u8 *) (((char *) temp_s1) + 0x195))))
          {
            var_v0_8 = 1;
            if (!(var_fs1 <= 0.0002f))
            {
              var_v0_8 = 0;
            }
            var_v1_8 = 1;
            if (!(var_fs1 >= (-0.0002f)))
            {
              var_v1_8 = 0;
            }
            var_v0_9 = var_s0 * 2;
            if ((var_v0_8 & var_v1_8) || ((var_v0_9 = var_s0 * 2, absFloat(var_fs1 - (*((f32 *) (((char *) temp_s1) + 0x8C)))) > 0.03f)))
            {
              *((f32 *) (((char *) temp_s1) + 0x8C)) = var_fs1;
              *((u8 *) (((char *) temp_s1) + 0x195)) = var_s0;
              clearProbeState(arg0, *((u16 *) (((u8 *) (&D_800C7C8E)) + var_v0_9)));
              *((s32 *) (((char *) (*((void **) (((char *) arg0) + 0x68)))) + 0x30)) = 0;
            }
          }
          func_800698D8(arg0, temp_fs5, probeTrackSteerAngle(sp64, arg0));
          if (func_800818AC(temp_s4, 0xC) != 0)
          {
            if ((inline_fn((char *) temp_s1, 0x180) == 0) && (!((*((u16 *) (((char *) (*((void **) (((char *) arg0) + 0x68)))) + 0xC))) & 0x20)))
            {
              *((u8 *) (((char *) temp_s1) + 0x187)) = 0U;
              *((s8 *) (((char *) temp_s1) + 0x180)) = 1;
              *((f32 *) (((char *) temp_s1) + 0xCC)) = (f32) (((f64) (*((f32 *) (((char *) temp_s1) + 0xCC)))) + D_800D45E0);
              temp_v1_18 = *((void **) (((char *) arg0) + 0x68));
              *((u16 *) (((char *) temp_v1_18) + 0xC)) = (u16) ((*((u16 *) (((char *) temp_v1_18) + 0xC))) & 0xFFCB);
              requestSound(0xFF);
              if (gBorderSkipActive != 0)
              {
                temp_fv0_4 = *((f32 *) (((char *) temp_s1) + 0x4C));
                if (temp_fv0_4 <= 0.0002f)
                {
                  if (temp_fv0_4 >= (-0.0002f))
                  {
                    temp_fv0_5 = *((f32 *) (((char *) temp_s1) + 0x50));
                    if (temp_fv0_5 <= 0.0002f)
                    {
                      if (temp_fv0_5 >= (-0.0002f))
                      {
                        clearProbeState(arg0, 0x1ADU);
                      }
                    }
                  }
                }
              }
            }
          }
          temp_fv0_6 = func_80081B44(temp_s4, 4, 5);
          var_fs3_2 = (temp_fv0_6 * temp_fv0_6) * 82.8f;
          if (temp_fv0_6 < 0.0f)
          {
            var_fs3_2 = -var_fs3_2;
          }
          temp_fv0_7 = *((f32 *) (((char *) temp_s1) + 0x48));
          temp_fv1_3 = ((var_fs3_2 - temp_fv0_7) * 0.8f) + temp_fv0_7;
          *((f32 *) (((char *) temp_s1) + 0x48)) = temp_fv1_3;
          if (temp_fv1_3 < (-82.8f))
          {
            *((f32 *) (((char *) temp_s1) + 0x48)) = -82.8f;
          }
          else
            if (temp_fv1_3 > 82.8f)
          {
            *((f32 *) (((char *) temp_s1) + 0x48)) = 82.8f;
          }
          temp_v0_4 = *((void **) (((char *) arg0) + 0x68));
          D_800E1A1C -= *((f32 *) (((char *) temp_s1) + 0x48));
          if ((*((f32 *) (((char *) temp_v0_4) + 0x34))) <= 0.0f)
          {
            *((f32 *) (((char *) (*((void **) (((char *) arg0) + 0x68)))) + 0x20)) = absFloat(*((f32 *) (((char *) temp_v0_4) + 0x20)));
          }
          else
          {
            *((f32 *) (((char *) (*((void **) (((char *) arg0) + 0x68)))) + 0x20)) = (f32) (-absFloat(*((f32 *) (((char *) temp_v0_4) + 0x20))));
          }
          if ((*((u16 *) (((char *) (*((void **) (((char *) arg0) + 0x68)))) + 0xC))) & 8)
          {
            if ((func_800819EC((s32) temp_s4, 0xD) != 0) && (inline_fn((char *) temp_s1, 0x180) == 0))
            {
              temp_v1_19 = *((void **) (((char *) arg0) + 0x68));
              *((u16 *) (((char *) temp_v1_19) + 0xC)) = (u16) ((*((u16 *) (((char *) temp_v1_19) + 0xC))) | 0x40);
              clearProbeState(arg0, 0x177U);
              func_800635BC(arg0, 6);
            }
          }
        }
        var_fs2_2 = 0.01f;
        temp_fs3_2 = func_80081B44(temp_s4, 2, 3) * 0.15f;
        if ((*((u16 *) (((char *) (*((void **) (((char *) arg0) + 0x68)))) + 0xC))) & 8)
        {
          var_fs2_2 = 0.2f;
        }
        temp_fv0_8 = *((f32 *) (((char *) temp_s1) + 0x50));
        temp_fa0_2 = ((temp_fs3_2 - temp_fv0_8) * var_fs2_2) + temp_fv0_8;
        var_v0_10 = 1;
        *((f32 *) (((char *) temp_s1) + 0x50)) = temp_fa0_2;
        if (!(temp_fs3_2 <= 0.0002f))
        {
          var_v0_10 = 0;
        }
        var_v1_9 = 1;
        if (!(temp_fs3_2 >= (-0.0002f)))
        {
          var_v1_9 = 0;
        }
        if ((var_v0_10 & var_v1_9) && (absFloat(temp_fa0_2) < 0.01f))
        {
          *((f32 *) (((char *) temp_s1) + 0x50)) = 0.0f;
        }
        temp_fv0_9 = *((f32 *) (((char *) temp_s1) + 0x50));
        var_fv1_2 = -0.15f;
        if ((temp_fv0_9 < (-0.15f)) || ((var_fv1_2 = 0.15f, temp_fv0_9 > 0.15f)))
        {
          *((f32 *) (((char *) temp_s1) + 0x50)) = var_fv1_2;
        }
        temp_fs3_3 = *((f32 *) (((char *) temp_s1) + 0x50));
        var_s5 += temp_fs3_3 * sinAngle((*((f32 *) (((char *) arg0) + 0x40))) + 1024.0f);
        temp_a0_5 = *((void **) (((char *) arg0) + 0x68));
        var_s6 += temp_fs3_3 * cosAngle((*((f32 *) (((char *) arg0) + 0x40))) + 1024.0f);
        if ((!((*((u16 *) (((char *) temp_a0_5) + 0xC))) & 0x40)) && ((*((u8 *) (((char *) temp_s1) + 0x195))) == 1))
        {
          var_v0_11 = 1;
          if (!(temp_fs3_3 <= 0.0002f))
          {
            var_v0_11 = 0;
          }
          var_v1_10 = 1;
          if (!(temp_fs3_3 >= (-0.0002f)))
          {
            var_v1_10 = 0;
          }
          if (var_v0_11 & var_v1_10)
          {
            if (((*((s16 *) (((char *) temp_a0_5) + 0xA2))) != 0x1AD) || ((*((s32 *) (((char *) temp_a0_5) + 0x14))) & 0x20))
            {
              func_80002BD0(arg0, 0x159);
            }
          }
          else
            if (temp_fs3_3 < 0.0f)
          {
            func_80002BD0(arg0, 0x1A9);
            *((f32 *) (((char *) (*((void **) (((char *) arg0) + 0x68)))) + 0x34)) = (f32) (-temp_fs3_3);
          }
          else
            if (temp_fs3_3 > 0.0f)
          {
            func_80002BD0(arg0, 0x1A3);
            *((f32 *) (((char *) (*((void **) (((char *) arg0) + 0x68)))) + 0x34)) = temp_fs3_3;
          }
        }
      }

      default:
        block_430:
      updateAirTimeGauge(arg0);

        if (!((*((u16 *) (((char *) (*((void **) (((char *) arg0) + 0x68)))) + 0xC))) & 8))
      {
        temp_v1_20 = *((u8 *) (((char *) temp_s1) + 0x196));
        if (temp_v1_20 < 8U)
        {
          *((u8 *) (((char *) temp_s1) + 0x196)) = (u8) (temp_v1_20 + 1);
        }
      }
      else
      {
        if (((u8) (*((u8 *) (((char *) temp_s1) + 0x196)))) >= 8U)
        {
          D_800E1A28 |= 0x20000;
          requestSound(0x100);
        }
        *((u8 *) (((char *) temp_s1) + 0x196)) = 0U;
      }
        temp_v1_21 = inline_fn((char *) temp_s1, 0x180);
        switch (temp_v1_21)
      {
        case 2:
          if ((((*((u16 *) (((char *) (*((void **) (((char *) arg0) + 0x68)))) + 0xC))) & 8) && (func_800818AC(temp_s4, 0xC) == 0)) && (!((*((u16 *) (((char *) (*((void **) (((char *) arg0) + 0x68)))) + 0xC))) & 1)))
        {
          *((s8 *) (((char *) temp_s1) + 0x180)) = 0;
        }
          break;

        case 1:
          if ((!((*((u16 *) (((char *) (*((void **) (((char *) arg0) + 0x68)))) + 0xC))) & 0x20)) && (func_800818AC(temp_s4, 0xC) != 0))
        {
          temp_v0_5 = *((u8 *) (((char *) temp_s1) + 0x187));
          *((u8 *) (((char *) temp_s1) + 0x187)) = (u8) (temp_v0_5 + 1);
          if (((s8) temp_v0_5) >= 5)
          {
            goto block_444;
          }
          *((f32 *) (((char *) temp_s1) + 0xCC)) = (f32) (((f64) (*((f32 *) (((char *) temp_s1) + 0xCC)))) + D_800D45E8);
        }
        else
        {
          block_444:
          *((s8 *) (((char *) temp_s1) + 0x180)) = 2;

        }
          break;

      }

        if (sBonusSlots[inline_fn((char *) temp_s1, 0x182) * 0xA0] == 0)
      {
        temp_v1_22 = inline_fn((char *) temp_s1, 0x17E);
        if (((temp_v1_22 >= 0) && (temp_v1_22 >= 2)) && (temp_v1_22 < 4))
        {
          temp_v0_6 = inline_fn((char *) temp_s1, 0x19B);
          if (temp_v0_6 != 0)
          {
            *((s8 *) (((char *) temp_s1) + 0x19B)) = (s8) (temp_v0_6 - 1);
          }
          else
          {
            temp_ft1 = *((f32 *) (((char *) temp_s1) + 0x34));
            temp_ft0 = ((*((f32 *) (((char *) temp_s1) + 0x38))) - temp_ft1) * 0.15f;
            if (((*((s16 *) (((char *) arg0) + 0x7C))) != 0) || (inline_fn((char *) temp_s1, 0x180) == 0))
            {
              temp_fv0_10 = temp_ft1 + temp_ft0;
              var_fv1_3 = -1.0f;
              *((f32 *) (((char *) temp_s1) + 0x34)) = temp_fv0_10;
              if ((temp_fv0_10 < (-1.0f)) || ((var_fv1_3 = 1.0f, temp_fv0_10 > 1.0f)))
              {
                {
                  long long phantom_wide = temp_v0;
                }
                *((f32 *) (((char *) temp_s1) + 0x34)) = var_fv1_3;
              }
              var_v0_12 = 1;
              if (!(temp_ft0 <= 0.0002f))
              {
                var_v0_12 = 0;
              }
              var_v1_11 = 1;
              if (!(temp_ft0 >= (-0.0002f)))
              {
                var_v1_11 = 0;
              }
              if ((var_v0_12 & var_v1_11) && (inline_fn((char *) temp_s1, 0x17E) == 2))
              {
                *((s8 *) (((char *) temp_s1) + 0x17E)) = 3;
              }
            }
          }
        }
      }
        temp_v1_23 = *((s16 *) (((char *) arg0) + 0x7C));
        if ((temp_v1_23 == 0) || (temp_v1_23 == 6))
      {
        var_s5 -= *((f32 *) (((char *) temp_s1) + 0x11C));
        var_s6 -= *((f32 *) (((char *) temp_s1) + 0x124));
      }
        temp_a0_6 = temp_s1 + 0x11C;
        func_80047B14(temp_a0_6, 0.8f, temp_a0_6);
        *((f32 *) (((char *) arg0) + 0x24)) = (f32) ((*((f32 *) (((char *) arg0) + 0x24))) + var_s5);
        *((f32 *) (((char *) arg0) + 0x28)) = (f32) ((*((f32 *) (((char *) arg0) + 0x28))) + var_fp);
        *((f32 *) (((char *) arg0) + 0x40)) = (f32) ((*((f32 *) (((char *) arg0) + 0x40))) + D_800E1A1C);
        *((f32 *) (((char *) arg0) + 0x2C)) = (f32) ((*((f32 *) (((char *) arg0) + 0x2C))) + var_s6);
        *((f32 *) (((char *) arg0) + 0x3C)) = (f32) ((*((f32 *) (((char *) arg0) + 0x3C))) + sp5C);
        *((f32 *) (((char *) arg0) + 0x44)) = (f32) ((*((f32 *) (((char *) arg0) + 0x44))) + 0.0f);
        block_474:
      func_80002EF0(arg0);

        func_8006D2E4(arg0);
        temp_v1_24 = *((s16 *) (((char *) arg0) + 0x7A));
        if (temp_v1_24 < 4)
      {
        if (temp_v1_24 < 2)
        {
          if (temp_v1_24 != 1)
          {
          }
          else
            if (temp_s1)
          {
            goto block_479;
          }
          else
          {
            goto block_479;
          }
        }
        else
        {
          updateSwayMotion(arg0);
          func_80070F34(arg0);
        }
      }
      else
        if (temp_v1_24 == 4)
      {
        block_479:
        temp_v1_25 = inline_fn((char *) temp_s1, 0x307);

        *((u8 *) (((char *) temp_s1) + 0x197)) = (u8) ((*((u8 *) (((char *) temp_s1) + 0x197))) - 1);
        if (temp_v1_25 < inline_fn((char *) temp_s1, 0x317))
        {
          *((s8 *) (((char *) temp_s1) + 0x317)) = temp_v1_25;
        }
        temp_v0_7 = inline_fn((char *) temp_s1, 0x317);
        if (temp_v0_7 < inline_fn((char *) temp_s1, 0x307))
        {
          *((s8 *) (((char *) temp_s1) + 0x307)) = temp_v0_7;
        }
        if (((s8) (*((u8 *) (((char *) temp_s1) + 0x197)))) < 0)
        {
          temp_v1_26 = inline_fn((char *) temp_s1, 0x307);
          *((u8 *) (((char *) temp_s1) + 0x197)) = 0xFU;
          if (temp_v1_26 < 0x64)
          {
            *((s8 *) (((char *) temp_s1) + 0x307)) = (s8) (temp_v1_26 + 1);
          }
          *((s8 *) (((char *) temp_s1) + 0x317)) = (s8) ((u8) inline_fn((char *) temp_s1, 0x307));
        }
        func_80067E94(arg0);
        updateSwayMotion(arg0);
        func_80070F34(arg0);
        temp_v1_27 = *((s16 *) (((char *) arg0) + 0x7C));
        switch (temp_v1_27)
        {
          case 0:

          case 1:

          case 2:

          case 3:

          case 4:

          case 6:

          case 8:

          case 9:

          case 10:
            func_8006899C(arg0, 0);
            break;

        }

        func_800179E8(arg0 + 0x24, sp64, D_800E1A28, D_800E1A2C);
      }
        func_80047FB4((s32) sTrackMarkerTable[temp_s4], *((s32 *) (((char *) (&D_800C4710)) + (((s8) (*((u8 *) (((char *) (*((void **) (((char *) arg0) + 0x68)))) + 0xE)))) * 0xE8))));
        func_80069250(arg0);
        break;

      case 6:
        if (actorUpdateBorderFade(arg0) == 0)
      {
        if (!(((s32) (*((u32 *) (((char *) (*((void **) (((char *) arg0) + 0x68)))) + 0xC)))) & 0x410000))
        {
          temp_fs3_4 = func_80081B44(temp_s4, 0, 1);
          func_800698D8(arg0, temp_fs3_4, probeTrackSteerAngle(sp64, arg0));
          temp_v1_28 = *((u16 *) (((char *) (*((void **) (((char *) arg0) + 0x68)))) + 0xC));
          if (!(temp_v1_28 & 1))
          {
            if ((temp_v1_28 & 8) && ((func_800819EC((s32) temp_s4, 0xD) != 0) || (func_800819EC((s32) temp_s4, 0xC) != 0)))
            {
              if ((func_8004BCC0(sp64, arg0 + 0x24, &probe.x, 2.0f) << 0x18) == 0)
              {
                probe = *((CopyVec3 *) (((char *) arg0) + 0x24));
                probe.y += 2.0f;
              }
              if (((*((f32 *) (((char *) arg0) + 0x28))) + 1.46f) < probe.y)
              {
                func_80002D50(arg0, 0x177);
                func_800635BC(arg0, 0);
                temp_v1_29 = *((void **) (((char *) arg0) + 0x68));
                *((u16 *) (((char *) temp_v1_29) + 0xC)) = (u16) ((*((u16 *) (((char *) temp_v1_29) + 0xC))) | 0x40);
              }
            }
            else
              if ((*((s16 *) (((char *) arg0) + 0x7C))) != 0)
            {
              temp_fv0_11 = func_80081B44(temp_s4, 4, 5);
              var_fs3_3 = temp_fv0_11 * temp_fv0_11;
              if (temp_fv0_11 < 0.0f)
              {
                var_fs3_3 = -var_fs3_3;
              }
              temp_fv0_12 = *((f32 *) (((char *) temp_s1) + 0x48));
              temp_fv1_4 = (((var_fs3_3 * 82.8f) - temp_fv0_12) * 0.8f) + temp_fv0_12;
              *((f32 *) (((char *) temp_s1) + 0x48)) = temp_fv1_4;
              if (temp_fv1_4 < (-82.8f))
              {
                *((f32 *) (((char *) temp_s1) + 0x48)) = -82.8f;
              }
              else
                if (temp_fv1_4 > 82.8f)
              {
                *((f32 *) (((char *) temp_s1) + 0x48)) = 82.8f;
              }
              D_800E1A1C -= *((f32 *) (((char *) temp_s1) + 0x48));
              var_fs3_4 = func_80081B44(temp_s4, 0, 1);
              absFloat(var_fs3_4);
              if ((*((u16 *) (((char *) (*((void **) (((char *) arg0) + 0x68)))) + 0xC))) & 8)
              {
                var_v1_12 = 1;
                if (!(var_fs3_4 <= 0.0002f))
                {
                  var_v1_12 = (unsigned int) 0;
                }
                var_v0_13 = 1;
                if (!(var_fs3_4 >= (-0.0002f)))
                {
                  var_v0_13 = 0;
                }
                if (((var_v0_13 ^ 1) | (var_v1_12 ^ 1)) != 0)
                {
                  temp_fv0_13 = var_fs3_4 * var_fs3_4;
                  if (var_fs3_4 > 0.0f)
                  {
                    var_fs3_4 = (temp_fv0_13 * 0.09f) + 0.01f;
                  }
                  else
                  {
                    var_fs3_4 = (temp_fv0_13 * (-0.045f)) - 0.01f;
                  }
                }
                var_fs2_3 = 0.2f;
              }
              else
              {
                var_fs2_3 = 0.01f;
              }
              temp_v1_30 = *((u16 *) (((char *) (*((void **) (((char *) arg0) + 0x68)))) + 0xC));
              if (temp_v1_30 & 4)
              {
                var_fs3_4 *= 0.5f;
              }
              if (temp_v1_30 & 0x200)
              {
                var_fs3_4 = var_fs3_4 * (*((f32 *) (((char *) temp_s1) + 0x94)));
              }
              temp_fv0_14 = *((f32 *) (((char *) temp_s1) + 0x4C));
              temp_fa0_3 = ((var_fs3_4 - temp_fv0_14) * var_fs2_3) + temp_fv0_14;
              var_v0_14 = 1;
              *inline_fn2(temp_s1) = temp_fa0_3;
              if (!(var_fs3_4 <= 0.0002f))
              {
                var_v0_14 = 0;
              }
              var_v1_13 = 1;
              if (!(var_fs3_4 >= (-0.0002f)))
              {
                var_v1_13 = 0;
              }
              if ((var_v0_14 & var_v1_13) && (absFloat(temp_fa0_3) < 0.01f))
              {
                *inline_fn2(temp_s1) = 0.0f;
              }
              temp_fv0_15 = *inline_fn2(temp_s1);
              var_fv1_4 = -0.09f;
              if ((temp_fv0_15 < (-0.09f)) || ((var_fv1_4 = 0.09f, temp_fv0_15 > 0.09f)))
              {
                *((f32 *) (((char *) temp_s1) + 0x4C)) = var_fv1_4;
              }
              temp_fs3_5 = *((f32 *) (((char *) temp_s1) + 0x4C));
              var_v0_15 = 1;
              if (!(temp_fs3_5 <= 0.0002f))
              {
                var_v0_15 = 0;
              }
              var_v1_14 = 1;
              if (!(temp_fs3_5 >= (-0.0002f)))
              {
                var_v1_14 = 0;
              }
              if (var_v0_15 & var_v1_14)
              {
                temp_fs1 = *((f32 *) (((char *) temp_s1) + 0x50));
                var_v0_16 = 1;
                if (!(temp_fs1 <= 0.0002f))
                {
                  var_v0_16 = 0;
                }
                var_v1_15 = 1;
                if (!(temp_fs1 >= (-0.0002f)))
                {
                  var_v1_15 = 0;
                }
                if (var_v0_16 & var_v1_15)
                {
                  *((s32 *) (((char *) (*((void **) (((char *) arg0) + 0x68)))) + 0x30)) = 0;
                  func_80002BD0(arg0, 0x17D);
                }
                else
                {
                  *((f32 *) (((char *) (*((void **) (((char *) arg0) + 0x68)))) + 0x34)) = temp_fs1;
                  if (temp_fs1 > 0.0f)
                  {
                    func_80002BD0(arg0, 0x189);
                  }
                  else
                  {
                    func_80002BD0(arg0, 0x18F);
                  }
                }
              }
              else
              {
                func_80002BD0(arg0, 0x183);
                *((f32 *) (((char *) (*((void **) (((char *) arg0) + 0x68)))) + 0x34)) = temp_fs3_5;
                var_s5 = 0.0f + (temp_fs3_5 * sinAngle(*((f32 *) (((char *) arg0) + 0x40))));
                var_s6 = 0.0f + (temp_fs3_5 * cosAngle(*((f32 *) (((char *) arg0) + 0x40))));
              }
            }
          }
        }
        var_fs2_4 = 0.01f;
        temp_fs3_6 = func_80081B44(temp_s4, 2, 3) * 0.075f;
        if ((*((u16 *) (((char *) (*((void **) (((char *) arg0) + 0x68)))) + 0xC))) & 8)
        {
          var_fs2_4 = 0.2f;
        }
        temp_fv0_16 = *((f32 *) (((char *) temp_s1) + 0x50));
        temp_fa0_4 = ((temp_fs3_6 - temp_fv0_16) * var_fs2_4) + temp_fv0_16;
        var_v0_17 = 1;
        *((f32 *) (((char *) temp_s1) + 0x50)) = temp_fa0_4;
        if (!(temp_fs3_6 <= 0.0002f))
        {
          var_v0_17 = 0;
        }
        var_v1_16 = 1;
        if (!(temp_fs3_6 >= (-0.0002f)))
        {
          var_v1_16 = 0;
        }
        if ((var_v0_17 & var_v1_16) && (absFloat(temp_fa0_4) < 0.01f))
        {
          *((f32 *) (((char *) temp_s1) + 0x50)) = 0.0f;
        }
        temp_fv0_17 = *((f32 *) (((char *) temp_s1) + 0x50));
        var_fv1_5 = -0.075f;
        if ((temp_fv0_17 < (-0.075f)) || ((var_fv1_5 = 0.075f, temp_fv0_17 > 0.075f)))
        {
          *((f32 *) (((char *) temp_s1) + 0x50)) = var_fv1_5;
        }
        temp_fs1_2 = *((f32 *) (((char *) temp_s1) + 0x50));
        var_s5 += temp_fs1_2 * sinAngle((*((f32 *) (((char *) arg0) + 0x40))) + 1024.0f);
        var_s6 += temp_fs1_2 * cosAngle((*((f32 *) (((char *) arg0) + 0x40))) + 1024.0f);
      }
        goto block_430;

      case 1:
        if (temp_fv0_22)
      {
        *((f32 *) (((char *) temp_s1) + 0xCC)) = 0.0f;
        temp_a0_7 = *((u16 *) (((char *) (*((void **) (((char *) arg0) + 0x68)))) + 0xC));
      }
      else
      {
        *((f32 *) (((char *) temp_s1) + 0xCC)) = 0.0f;
        temp_a0_7 = *((u16 *) (((char *) (*((void **) (((char *) arg0) + 0x68)))) + 0xC));
      }
        if (!(temp_a0_7 & 1))
      {
        temp_v1_31 = inline_fn((char *) temp_s1, 0x181);
        switch (temp_v1_31)
        {
          case 1:
            if (!(temp_a0_7 & 0x40))
          {
            temp_fv0_18 = func_80081B44(temp_s4, 0, 1);
            var_fs3_5 = temp_fv0_18 * 0.04f;
            if ((*((u16 *) (((char *) (*((void **) (((char *) arg0) + 0x68)))) + 0xC))) & 0x200)
            {
              var_fs3_5 *= *((f32 *) (((char *) temp_s1) + 0x94));
            }
            if (var_fs3_5 < (-0.04f))
            {
              var_fs3_5 = -0.04f;
            }
            else
              if (var_fs3_5 > 0.04f)
            {
              var_fs3_5 = 0.04f;
            }
            temp_fs0_3 = var_fs3_5 + (*((f32 *) (((char *) arg0) + 0x28)));
            if (func_800818AC(temp_s4, 0xC) != 0)
            {
              *((s8 *) (((char *) temp_s1) + 0x181)) = 4;
              requestSound(0xFF);
            }
            else
              if ((*((f32 *) (((char *) temp_s1) + 0x14))) < temp_fs0_3)
            {
              if ((func_8004BCC0(sp64, arg0 + 0x24, &probe.x, 2.0f) << 0x18) == 0)
              {
                probe = *((CopyVec3 *) (((char *) arg0) + 0x24));
                probe.y += 2.0f;
              }
              if (((*((f32 *) (((char *) arg0) + 0x28))) + 1.46f) < probe.y)
              {
                temp_fv0_19 = func_80063758(*((f32 *) (((char *) arg0) + 0x40)), *((f32 *) (((char *) temp_s1) + 0x90)), 128.0f);
                var_fs3_5 = temp_fv0_19;
                if (temp_fv0_19 == 0.0f)
                {
                  *((f32 *) (((char *) arg0) + 0x28)) = (f32) (*((f32 *) (((char *) temp_s1) + 0x14)));
                  func_80002BD0(arg0, 0x298);
                  temp_v1_32 = *((void **) (((char *) arg0) + 0x68));
                  *((u16 *) (((char *) temp_v1_32) + 0xC)) = (u16) ((*((u16 *) (((char *) temp_v1_32) + 0xC))) | 0x40);
                  *((s8 *) (((char *) temp_s1) + 0x181)) = 2;
                  *((s8 *) (((char *) temp_s1) + 0x17E)) = 2;
                  func_800698D8(arg0, temp_fv0_18, 0.0f);
                  *((s8 *) (((char *) temp_s1) + 0x19B)) = 8;
                }
                else
                {
                  temp_fv0_20 = (*((f32 *) (((char *) arg0) + 0x40))) + var_fs3_5;
                  var_fs3_5 = 0.0f;
                  *((f32 *) (((char *) arg0) + 0x40)) = temp_fv0_20;
                }
              }
              else
              {
                var_fs3_5 = 0.0f;
              }
            }
            else
            {
              temp_fv0_21 = *((f32 *) (((char *) temp_s1) + 0x18));
              if (temp_fs0_3 < temp_fv0_21)
              {
                var_a2 = 0.0f;
                *((f32 *) (((char *) arg0) + 0x28)) = temp_fv0_21;
                *((s8 *) (((char *) temp_s1) + 0x181)) = 3;
                *((s8 *) (((char *) temp_s1) + 0x17E)) = 2;
              }
              else
              {
                *((f32 *) (((char *) arg0) + 0x28)) = temp_fs0_3;
                func_80002BD0(arg0, 0x295);
                var_a2 = func_80069998();
              }
              func_800698D8(arg0, temp_fv0_18, var_a2);
            }
            *((f32 *) (((char *) (*((void **) (((char *) arg0) + 0x68)))) + 0x34)) = var_fs3_5;
            *inline_fn2(temp_s1) = (f32) (var_fs3_5 * 5.0f);
          }
            break;

          case 2:
            if (!(temp_a0_7 & 0x40))
          {
            *((s8 *) (((char *) temp_s1) + 0x181)) = 3;
          }
            break;

          case 4:
            *inline_fn2(temp_s1) = 0.2f;
            var_s5 = sinAngle(*((f32 *) (((char *) arg0) + 0x40))) * 0.2f;
            var_s6 = cosAngle(*((f32 *) (((char *) arg0) + 0x40))) * 0.2f;
            *((f32 *) (((char *) temp_s1) + 0xCC)) = 0.0f;
            *((u8 *) (((char *) temp_s1) + 0x186)) = 0xAU;
            if (actorUpdateBorderFade(arg0) == 0)
          {
            *((s32 *) (((char *) (*((void **) (((char *) arg0) + 0x68)))) + 0x30)) = 0;
            func_80002BD0(arg0, 0x159);
            func_800635BC(arg0, 0);
          }
            break;

          case 3:
            func_80065684(arg0);
            *((f32 *) (((char *) temp_s1) + 0xCC)) = 0.0f;
            *((u8 *) (((char *) temp_s1) + 0x186)) = 0xAU;
            if (actorUpdateBorderFade(arg0) == 0)
          {
            *((s32 *) (((char *) (*((void **) (((char *) arg0) + 0x68)))) + 0x30)) = 0;
            func_80002BD0(arg0, 0x159);
            func_800635BC(arg0, 0);
          }
            break;

        }

      }
        goto block_430;

      case 2:
        if (D_800E1A20 <= 0)
      {
        D_800E19F0 = 0.495f;
        if ((*((s16 *) (((char *) (*((void **) (((char *) temp_s1) + 0xB8)))) + 0x94))) < 0xF)
        {
          if (func_800819EC((s32) temp_s4, 0x1B) != 0)
          {
            var_fv0 = 0.88000005f;
            goto block_294;
          }
          if (func_800819EC((s32) temp_s4, 0x1C) != 0)
          {
            var_fv0 = 0.275f;
            block_294:
            D_800E1A20 = 0x3C;

            D_800E19F0 = var_fv0;
          }
        }
      }
      else
      {
        D_800E1A20 -= 1;
      }
        temp_v0_8 = *((void **) (((char *) temp_s1) + 0xB8));
        temp_ft0_2 = *inline_fn2(temp_v0_8);
        *inline_fn2(temp_v0_8) = (f32) (((D_800E19F0 - temp_ft0_2) * 0.02f) + temp_ft0_2);
        temp_v0_9 = *((void **) (((char *) temp_s1) + 0xB8));
        var_fv1_6 = 0.275f;
        temp_fv0_22 = *inline_fn2(temp_v0_9);
        if ((temp_fv0_22 < 0.275f) || ((var_fv1_6 = 0.88000005f, temp_fv0_22 > 0.88000005f)))
      {
        if (temp_fv0_11)
        {
          *inline_fn2(temp_v0_9) = var_fv1_6;
        }
        else
        {
          *inline_fn2(temp_v0_9) = var_fv1_6;
        }
      }
        temp_fv0_23 = *((f32 *) (((char *) temp_s1) + 0x50));
        temp_fv1_5 = (((func_80081B44(temp_s4, 2, 3) * 0.2f) - temp_fv0_23) * 0.3f) + temp_fv0_23;
        *((f32 *) (((char *) temp_s1) + 0x50)) = temp_fv1_5;
        if (temp_fv1_5 < (-0.2f))
      {
        *((f32 *) (((char *) temp_s1) + 0x50)) = -0.2f;
      }
      else
        if (temp_fv1_5 > 0.2f)
      {
        *((f32 *) (((char *) temp_s1) + 0x50)) = 0.2f;
      }
        func_8011A234(arg0, *((void **) (((char *) temp_s1) + 0xB8)), *inline_fn2(*((void **) (((char *) temp_s1) + 0xB8))), *((f32 *) (((char *) temp_s1) + 0x50)), 0, 1);
        goto block_430;

      case 3:
        if (!((*((u16 *) (((char *) (*((void **) (((char *) arg0) + 0x68)))) + 0xC))) & 1))
      {
        if (func_80081AA4(temp_s4, 0xC) != 0)
        {
          var_fs3_6 = 0.2f;
          goto block_307;
        }
        if (!(D_800E1A0C != 0))
        {
          var_fs3_7 = -func_80081B44(temp_s4, 4, 5);
          var_v0_18 = 1;
          if (!(var_fs3_7 <= 0.0002f))
          {
            var_v0_18 = 0;
          }
          var_v1_17 = 1;
          if (!(var_fs3_7 >= (-0.0002f)))
          {
            var_v1_17 = 0;
          }
          if (var_v0_18 & var_v1_17)
          {
            var_fs3_7 = func_80081B44(temp_s4, 2, 3);
          }
          temp_fs2_2 = func_80081B44(temp_s4, 0, 1);
          var_v1_18 = 1;
          if (!(var_fs3_7 <= 0.0002f))
          {
            var_v1_18 = 0;
          }
          var_v0_19 = 1;
          if (!(var_fs3_7 >= (-0.0002f)))
          {
            var_v0_19 = 0;
          }
          if (((var_v1_18 ^ 1) | (var_v0_19 ^ 1)) == 0)
          {
            var_v1_19 = 1;
            if (!(temp_fs2_2 <= 0.0002f))
            {
              var_v1_19 = 0;
            }
            var_v0_20 = 1;
            if (!(temp_fs2_2 >= (-0.0002f)))
            {
              var_v0_20 = 0;
            }
            if (((var_v1_19 ^ 1) | (var_v0_20 ^ 1)) != 0)
            {
              goto block_327;
            }
            goto block_333;
          }
          block_327:
          temp_fv0_25 = func_80063758(*((f32 *) (((char *) arg0) + 0x40)), D_800E19F8 + 2048.0f, 64.0f);

          var_v1_20 = 1;
          if (!(temp_fv0_25 <= 0.0002f))
          {
            var_v1_20 = 0;
          }
          var_v0_21 = 1;
          if (!(temp_fv0_25 >= (-0.0002f)))
          {
            var_v0_21 = 0;
          }
          if (((var_v0_21 ^ 1) | (var_v1_20 ^ 1)) != 0)
          {
            D_800E1A0C = 1;
            *((f32 *) (((char *) temp_s1) + 0xCC)) = 0.0f;
          }
          else
          {
            block_333:
            temp_fv0_26 = *((f32 *) (((char *) temp_s1) + 0x48));

            temp_fv1_6 = (((var_fs3_7 * 32.0f) - temp_fv0_26) * 0.1f) + temp_fv0_26;
            *((f32 *) (((char *) temp_s1) + 0x48)) = temp_fv1_6;
            if (temp_fv1_6 < (-32.0f))
            {
              *((f32 *) (((char *) temp_s1) + 0x48)) = -32.0f;
            }
            else
              if (temp_fv1_6 > 32.0f)
            {
              *((f32 *) (((char *) temp_s1) + 0x48)) = 32.0f;
            }
            temp_fs3_7 = *((f32 *) (((char *) temp_s1) + 0x48));
            temp_fv1_7 = D_800E19F8 + temp_fs3_7;
            D_800E19F8 = temp_fv1_7;
            var_v1_21 = 1;
            if (!(temp_fs3_7 <= 0.0002f))
            {
              var_v1_21 = 0;
            }
            var_v0_22 = 1;
            if (!(temp_fs3_7 >= (-0.0002f)))
            {
              var_v0_22 = 0;
            }
            if (((var_v1_21 ^ 1) | (var_v0_22 ^ 1)) != 0)
            {
              *((f32 *) (((char *) arg0) + 0x40)) = (f32) (temp_fv1_7 + 2048.0f);
            }
            *((f32 *) (((char *) arg0) + 0x24)) = (f32) ((D_800E1A04 + (*((f32 *) (((char *) temp_s1) + 0xEC)))) + (sinAngle(D_800E19F8) * 0.22500001f));
            *((f32 *) (((char *) arg0) + 0x2C)) = (f32) ((D_800E1A08 + (*((f32 *) (((char *) temp_s1) + 0xF4)))) + (cosAngle(D_800E19F8) * 0.22500001f));
            func_800698D8(arg0, temp_fs2_2, func_80069A14(temp_fs2_2));
            temp_ft0_3 = *inline_fn2(temp_s1);
            temp_fv0_27 = (((temp_fs2_2 * 0.12f) - temp_ft0_3) * 0.2f) + temp_ft0_3;
            *((f32 *) (((char *) temp_s1) + 0x4C)) = temp_fv0_27;
            if (temp_fv0_27 < (-0.12f))
            {
              *((f32 *) (((char *) temp_s1) + 0x4C)) = -0.12f;
            }
            else
              if (temp_fv0_27 > 0.12f)
            {
              *inline_fn2(temp_s1) = 0.12f;
            }
            var_fs2_5 = *inline_fn2(temp_s1);
            if (var_fs2_5 < 0.0f)
            {
              var_fs2_5 *= 1.5f;
            }
            temp_fv0_28 = *((f32 *) (((char *) arg0) + 0x28));
            var_v0_23 = 1;
            if (!(var_fs2_5 > 0.0f))
            {
              var_v0_23 = 0;
            }
            var_v1_22 = 1;
            if (!(((*((f32 *) (((char *) temp_s1) + 0xF0))) - temp_fv0_28) <= 1.5f))
            {
              var_v1_22 = 0;
            }
            if (var_v0_23 & var_v1_22)
            {
              var_fs2_5 = 0.0f;
              goto block_360;
            }
            var_v0_24 = 1;
            if (!(var_fs2_5 < 0.0f))
            {
              var_v0_24 = 0;
            }
            var_v1_23 = 1;
            if (!((temp_fv0_28 - (*((f32 *) (((char *) temp_s1) + 0xFC)))) <= 1.5f))
            {
              var_v1_23 = 0;
            }
            var_fs3_6 = 0.0f;
            if (!(var_v0_24 & var_v1_23))
            {
              block_360:
              *((f32 *) (((char *) arg0) + 0x28)) = (f32) ((*((f32 *) (((char *) arg0) + 0x28))) + var_fs2_5);

              goto block_363;
            }
            block_307:
            *inline_fn2(temp_s1) = var_fs3_6;

            var_s5 = var_fs3_6 * sinAngle(*((f32 *) (((char *) arg0) + 0x40)));
            temp_fs3_8 = var_fs3_6 * cosAngle(*((f32 *) (((char *) arg0) + 0x40)));
            *((f32 *) (((char *) temp_s1) + 0xCC)) = 0.0f;
            *((s8 *) (((char *) temp_s1) + 0x188)) = 0x14;
            func_800635BC(arg0, 0);
            *((f32 *) (((char *) temp_s1) + 0x38)) = 0.0f;
            var_s6 = temp_fs3_8;
            *((s8 *) (((char *) temp_s1) + 0x17E)) = (unsigned char) 2;
            requestSound(0xFF);
            *((f32 *) (((char *) temp_s1) + 0xCC)) = 0.0f;
          }
        }
        else
          if (D_800E1A0C != 1)
        {
          *((f32 *) (((char *) temp_s1) + 0xCC)) = 0.0f;
        }
        else
        {
          temp_fv0_24 = func_80063758(*((f32 *) (((char *) arg0) + 0x40)), D_800E19F8 + 2048.0f, 64.0f);
          *((f32 *) (((char *) arg0) + 0x40)) = (f32) ((*((f32 *) (((char *) arg0) + 0x40))) + temp_fv0_24);
          if (temp_fv0_24 == 0.0f)
          {
            goto block_362;
          }
          goto block_363;
        }
      }
      else
      {
        block_362:
        D_800E1A0C = 0;

        block_363:
        *((f32 *) (((char *) temp_s1) + 0xCC)) = 0.0f;

      }
        goto block_430;

      case 7:
        var_v0_25 = *((void **) (((char *) temp_s1) + 0xBC));
        var_s3 = 0;
        loop_365:
      if (var_v0_25 == NULL)
      {
        var_s3 = 1;
        var_s0_2 = getObjectListHead(temp_s4);
        goto block_371;
      }

        var_s0_2 = *((void **) (((char *) var_v0_25) + 0x10));
        if (func_80081AA4(temp_s4, 0x12) != 0)
      {
        *((void **) (((char *) temp_s1) + 0xBC)) = NULL;
        *((s8 *) (((char *) temp_s1) + 0x184)) = 0;
        func_800635BC(arg0, 0);
        temp_v1_33 = *((void **) (((char *) arg0) + 0x68));
        *((u8 *) (((char *) temp_v1_33) + 0x10)) = (u8) (*((u8 *) (((char *) temp_v1_33) + 0xE)));
        *((s8 *) (((char *) (*((void **) (((char *) arg0) + 0x68)))) + 0xF)) = (s8) (*((u16 *) (((char *) temp_s1) + 0x134)));
        gSceneFlagsB |= 0x21;
        func_80064318(*((s32 *) (((char *) temp_s1) + 0xA8)), inline_fn((char *) temp_s1, 0x182));
        temp_v0_10 = sTrackMarkerTable[inline_fn((char *) temp_s1, 0x182)];
        *((CopyVec3 *) (((char *) arg0) + 0x30)) = *((CopyVec3 *) (((char *) arg0) + 0x24));
        *((CopyVec3 *) (((char *) temp_v0_10) + 0x10)) = *((CopyVec3 *) (((char *) arg0) + 0x30));
        *((CopyVec3 *) (((char *) temp_v0_10) + 0x28)) = *((CopyVec3 *) (((char *) temp_v0_10) + 0x10));
        *((void **) (((char *) sTrackMarkerTable[inline_fn((char *) temp_s1, 0x182)]) + 0xF4)) = (void *) (*((void **) (((char *) arg0) + 0x20)));
        func_80081D20(temp_s4, 0x12);
        return;
      }
        if (func_80081AA4(temp_s4, 0xE) != 0)
      {
        var_s3 = 1;
      }
        block_371:
      if (var_s3 != 0)
      {
        var_v0_25 = NULL;
        if (var_s0_2 != NULL)
        {
          for (;;)
          {
            temp_v0_11 = *((u16 *) (((char *) var_s0_2) + 0x78));
            if (((temp_v0_11 == 0x1B) | (temp_v0_11 == 0x5D)) != 0)
            {
              *((void **) (((char *) temp_s1) + 0xBC)) = var_s0_2;
            }
            else
            {
              var_s0_2 = *((void **) (((char *) var_s0_2) + 0x10));
              if (var_s0_2 != NULL)
              {
                continue;
              }
            }
            break;
          }

          goto block_377;
        }
        goto block_379;
      }

        block_377:
      if (var_s0_2 == NULL)
      {
        var_v0_25 = NULL;
        block_379:
        *((void **) (((char *) temp_s1) + 0xBC)) = NULL;

        goto loop_365;
      }

        *((s8 *) (((char *) temp_s1) + 0x184)) = 3;
        goto block_430;

      case 4:
        temp_fs4 = (*((f32 *) (((char *) arg0) + 0x3C))) - ((*((f32 *) (((char *) temp_s1) + 0x34))) * 1024.0f);
        temp_fs5_2 = func_80081B44(temp_s4, 0, 1);
        if (((*((f32 *) (((char *) (*((void **) (((char *) sp64) + 0x20)))) + 0x5C))) + 0.3f) <= (*((f32 *) (((char *) arg0) + 0x28))))
      {
        sp5C = 0.0f;
        func_800635BC(arg0, 0);
        *((f32 *) (((char *) arg0) + 0x3C)) = sp5C;
        *((s8 *) (((char *) temp_s1) + 0x17E)) = 2;
      }
      else
        if (!((*((u16 *) (((char *) (*((void **) (((char *) arg0) + 0x68)))) + 0xC))) & 1))
      {
        __base_D_800C7DBC = &D_800C7DBC;
        temp_s5 = 0.0f - (*__base_D_800C7DBC);
        temp_s6 = 0.0f - D_800C7DC4;
        temp_fs0_4 = sinTableLookup(D_800E1A10 * 3.0f);
        temp_fs3_9 = temp_fs0_4 * (cosTableLookup(D_800E1A10) * 0.1f);
        temp_fs0_5 = sinTableLookup(D_800E1A10);
        temp_fs2_3 = temp_fs0_5 * (cosTableLookup(D_800E1A10 * 3.0f) * 0.1f);
        *__base_D_800C7DBC = temp_fs3_9;
        D_800E1A10 += 0.01f;
        D_800C7DC4 = temp_fs2_3;
        temp_fv1_8 = *((f32 *) (((char *) temp_s1) + 0x48));
        temp_fv0_29 = (((func_80081B44(temp_s4, 4, 5) * 32.0f) - temp_fv1_8) * 0.1f) + temp_fv1_8;
        *((f32 *) (((char *) temp_s1) + 0x48)) = temp_fv0_29;
        if (temp_fv0_29 < (-32.0f))
        {
          *((f32 *) (((char *) temp_s1) + 0x48)) = -32.0f;
        }
        else
          if (temp_fv0_29 > 32.0f)
        {
          *((f32 *) (((char *) temp_s1) + 0x48)) = 32.0f;
        }
        var_fs3_8 = *((f32 *) (((char *) temp_s1) + 0x48));
        if (gWheelsGrounded != 0)
        {
          var_fs3_8 *= 2.0f;
        }
        var_s0_3 = 0;
        D_800E1A1C -= var_fs3_8;
        if ((func_800818AC(temp_s4, 0x16) != 0) || (func_800818AC(temp_s4, 0xC) != 0))
        {
          var_s0_3 = 1;
        }
        if ((func_800818AC(temp_s4, 0x17) != 0) || (func_800818AC(temp_s4, 0xD) != 0))
        {
          var_s0_3 = -1;
        }
        temp_fv1_9 = *((f32 *) (((char *) temp_s1) + 0x5C));
        temp_fv0_30 = (((((f32) var_s0_3) * 0.05f) - temp_fv1_9) * 0.05f) + temp_fv1_9;
        *((f32 *) (((char *) temp_s1) + 0x5C)) = temp_fv0_30;
        if (temp_fv0_30 < (-0.05f))
        {
          *((f32 *) (((char *) temp_s1) + 0x5C)) = -0.05f;
        }
        else
          if (temp_fv0_30 > 0.05f)
        {
          *((f32 *) (((char *) temp_s1) + 0x5C)) = 0.05f;
        }
        spherical_to_cartesian(sp20, *((f32 *) inline_fn23((char *) temp_s1, 0x5C)), (*((f32 *) (((char *) arg0) + 0x40))) * 0.0015339808f, (temp_fs4 * 0.0015339808f) - 1.5707964f);
        temp_fv1_10 = *((f32 *) (((char *) temp_s1) + 0x50));
        temp_fv0_31 = (((func_80081B44(temp_s4, 2, 3) * 0.05f) - temp_fv1_10) * 0.05f) + temp_fv1_10;
        *((f32 *) (((char *) temp_s1) + 0x50)) = temp_fv0_31;
        if (temp_fv0_31 < (-0.05f))
        {
          do
          {
            *((f32 *) (((char *) temp_s1) + 0x50)) = -0.05f;
          }
          while (0);
        }
        else
          if (temp_fv0_31 > 0.05f)
        {
          *((f32 *) (((char *) temp_s1) + 0x50)) = 0.05f;
        }
        temp_fs3_10 = *((f32 *) (((char *) temp_s1) + 0x50));
        temp_s5_2 = ((temp_s5 + temp_fs3_9) + sp20[0]) + (temp_fs3_10 * sinAngle((*((f32 *) (((char *) arg0) + 0x40))) + 1024.0f));
        temp_ft1_2 = *inline_fn2(temp_s1);
        temp_fv1_11 = (((temp_fs5_2 * 0.15f) - temp_ft1_2) * 0.05f) + temp_ft1_2;
        temp_s6_2 = ((temp_s6 + temp_fs2_3) + sp20[2]) + (temp_fs3_10 * cosAngle((*((f32 *) (((char *) arg0) + 0x40))) + 1024.0f));
        *((f32 *) (((char *) temp_s1) + 0x4C)) = (((temp_fs5_2 * 0.15f) - temp_ft1_2) * 0.05f) + temp_ft1_2;
        if (temp_fv1_11 < (-0.15f))
        {
          *((f32 *) (((char *) temp_s1) + 0x4C)) = -0.15f;
        }
        else
          if (temp_fv1_11 > 0.15f)
        {
          *inline_fn2(temp_s1) = 0.15f;
        }
        spherical_to_cartesian(sp20, *((f32 *) (((char *) temp_s1) + 0x4C)), (*((f32 *) (((char *) arg0) + 0x40))) * 0.0015339808f, temp_fs4 * 0.0015339808f);
        temp_v1_34 = *((void **) (((char *) arg0) + 0x68));
        *((f32 *) (((char *) temp_v1_34) + 0x34)) = 0.0f;
        var_s5 = temp_s5_2 + sp20[0];
        temp_fs3_11 = (*((f32 *) (((char *) (*((void **) (((char *) sp64) + 0x20)))) + 0x5C))) - 0.3f;
        var_fp = (0.0f - sp20[1]) - sp20[1];
        temp_fv1_12 = *((f32 *) (((char *) arg0) + 0x28));
        var_s6 = temp_s6_2 + sp20[2];
        if (temp_fv1_12 < temp_fs3_11)
        {
          if (temp_fs3_11 < (temp_fv1_12 + var_fp))
          {
            var_fp = temp_fs3_11 - temp_fv1_12;
          }
        }
        else
        {
          temp_fv0_32 = *((f32 *) (((char *) temp_v1_34) + 0x34));
          if (temp_fv0_32 < var_fp)
          {
            var_fp = temp_fv0_32;
          }
        }
      }
        goto block_430;

      case 5:
        temp_a0_8 = *((void **) (((char *) temp_s1) + 0xBC));
        temp_v1_35 = *((u8 *) (((char *) temp_s1) + 0x18A));
        temp_a1 = *((void **) (((char *) temp_a0_8) + 0x6C));
        switch (temp_v1_35)
      {
        case 0:
          temp_v0_12 = temp_s4 * 0xA0;
          *((u8 *) (((char *) temp_s1) + 0x18B)) = (u8) sBonusSlots[temp_v0_12];
          sBonusSlots[temp_v0_12] = 1;
          *((u8 *) (((char *) temp_s1) + 0x18A)) = 1U;
          *((f32 *) (((char *) arg0) + 0x3C)) = 0.0f;
          *((f32 *) (((char *) arg0) + 0x44)) = 0.0f;
          *((f32 *) (((char *) arg0) + 0x40)) = (f32) (*((f32 *) (((char *) temp_a1) + 0x10)));
          func_80002BD0(arg0, 0x20D);
          *((f32 *) (((char *) arg0) + 0x24)) = (f32) ((*((f32 *) (((char *) (*((void **) (((char *) temp_s1) + 0xBC)))) + 0x24))) - (sinAngle(*((f32 *) (((char *) arg0) + 0x40))) * 1.5f));
          temp_fv1_13 = (*((f32 *) (((char *) (*((void **) (((char *) temp_s1) + 0xBC)))) + 0x2C))) - (cosAngle(*((f32 *) (((char *) arg0) + 0x40))) * 1.5f);
          D_800E1A1C = 0.0f;
          sp5C = 0.0f;
          *((f32 *) (((char *) arg0) + 0x2C)) = temp_fv1_13;
          break;

        case 1:
          *((f32 *) (((char *) arg0) + 0x24)) = (f32) ((*((f32 *) (((char *) (*((void **) (((char *) temp_s1) + 0xBC)))) + 0x24))) - (sinAngle(*((f32 *) (((char *) temp_a0_8) + 0x40))) * 1.5f));
          *((f32 *) (((char *) arg0) + 0x2C)) = (f32) ((*((f32 *) (((char *) (*((void **) (((char *) temp_s1) + 0xBC)))) + 0x2C))) - (cosAngle(*((f32 *) (((char *) (*((void **) (((char *) temp_s1) + 0xBC)))) + 0x40))) * 1.5f));
          *((f32 *) (((char *) arg0) + 0x40)) = (f32) (*((f32 *) (((char *) (*((void **) (((char *) temp_s1) + 0xBC)))) + 0x40)));
          if (func_80081AA4(temp_s4, 0x12) != 0)
        {
          sBonusSlots[temp_s4 * 0xA0] = *((u8 *) (((char *) temp_s1) + 0x18B));
          *((u8 *) (((char *) temp_s1) + 0x18A)) = 2U;
        }
        else
          if (func_8008194C(temp_s4, 0xE) != 0)
        {
          temp_a0_9 = *((void **) (((char *) temp_s1) + 0xBC));
          if ((*((s16 *) (((char *) temp_a0_9) + 0x7A))) == 2)
          {
            *((s16 *) (((char *) temp_a0_9) + 0x7A)) = 6;
          }
        }
        else
        {
          temp_a0_10 = *((void **) (((char *) temp_s1) + 0xBC));
          if ((*((s16 *) (((char *) temp_a0_10) + 0x7A))) == 7)
          {
            *((s16 *) (((char *) temp_a0_10) + 0x7A)) = 8;
          }
        }
          break;

        case 2:
          sp5C = 0.0f;
          func_800635BC(arg0, 0);
          *((f32 *) (((char *) arg0) + 0x3C)) = sp5C;
          *((s16 *) (((char *) (*((void **) (((char *) temp_s1) + 0xBC)))) + 0x7A)) = 5;
          temp_v1_36 = *((void **) (((char *) arg0) + 0x68));
          *((u8 *) (((char *) temp_v1_36) + 0x10)) = (u8) (*((u8 *) (((char *) temp_v1_36) + 0xE)));
          *((s8 *) (((char *) (*((void **) (((char *) arg0) + 0x68)))) + 0xF)) = (s8) (*((u16 *) (((char *) temp_s1) + 0x134)));
          break;

      }

        goto block_430;

    }

  }
}

