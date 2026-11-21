typedef struct 
{
  s32 x;
  s32 y;
  s32 z;
} ProbeTriple;
void actorUnlinkFromSurface(void *);
f32 approxDistance(void *, void *);
s32 func_80064370(void *, s32);
s32 func_80073AF8(s32, s32, s32 *, s32, s32, s32, s32, s32, s32, s32, s32);
void listUnlinkFree(s32);
s32 lookupDataEntry(s32);
s32 objectListInsert(void *, s32);
s32 requestSound(s32);
volatile long long setActorStatusBits(s32);
extern int sprintf(char *, const char *, ...);
s16 timerGetTotalSeconds(s32 *);
s32 unlinkNode(void *, void *, void *);
extern s32 D_8010969C;
extern s32 D_8011ED10;
extern s32 D_8011EFE0;
extern s32 D_8011EFEC;
extern s32 D_8011F170;
extern s32 D_8011F29C;
extern s32 D_8011F2A0;
extern u8 gSceneType;
extern s32 sBonusObjectTable;
extern s32 sProbeActive;
extern s32 sProbeActors;
extern s32 sProbeHandles;
extern s32 sProbeObjects;
extern s32 sProbeOriginTable;
extern s32 sProbePositions;
extern s32 sProbeStates;
extern s32 sProbeTimer;
extern s32 sProbeTimes;
extern s32 sTrackMarkerTable;
inline static u8 *inline_fn(s32 *arg0, s32 arg1)
{
  return ((u8 *) arg0) + arg1;
}

void func_8011B5F0(void *arg0)
{
  s32 *sp34;
  void **sp3C;
  s32 var_a2;
  s32 var_a2_2;
  s32 var_a2_3;
  s32 *temp_s0_5;
  s32 *temp_s0_7;
  s32 temp_a0;
  s32 temp_a1;
  s32 temp_a1_2;
  s32 temp_a1_3;
  s32 temp_a1_4;
  s32 temp_s0;
  s32 temp_s0_3;
  unsigned int temp_s0_6;
  s32 temp_s0_8;
  s32 temp_s0_9;
  s32 temp_s1;
  s32 temp_s1_2;
  s32 temp_s1_3;
  s32 temp_s3_2;
  s32 temp_s3_3;
  s32 temp_s3_4;
  s32 temp_s5;
  s32 temp_s6_2;
  s32 temp_v0_5;
  s32 temp_v0_7;
  s32 temp_v0_8;
  s32 temp_v1;
  s32 __repair_phase_temp_v1;
  s32 var_a0;
  s32 var_a0_2;
  s32 var_a0_3;
  s32 var_a0_4;
  u16 var_s5;
  s32 sceneTwo;
  unsigned char var_v0;
  u16 temp_v0_4;
  u8 temp_s6;
  union 
  {
    void **pointer;
    s32 value;
  } __repair_phase_storage;
  void **temp_s3;
  void **temp_s7;
  void *temp_a0_2;
  void *temp_a0_4;
  void *temp_a0_5;
  void *temp_s4;
  void *temp_v0;
  void *temp_v0_2;
  void *temp_v0_3;
  void *temp_v0_6;
  temp_s6 = *((u8 *) (((char *) arg0) + 0x7B));
  temp_s0 = temp_s6 & 0xFF;
  *((s32 *) (((char *) arg0) + 0x58)) = (s32) ((*((s32 *) (((char *) arg0) + 0x58))) | 1);
  temp_a0 = temp_s0 * 4;
  temp_s3 = (void **) (((u8 *) (&sProbeOriginTable)) + temp_a0);
  temp_v0 = *temp_s3;
  var_s5 = 0;
  if (temp_v0 != NULL)
  {
    if ((*((f32 *) (((char *) temp_v0) + 0x74))) > 0.0f)
    {
      temp_v0_2 = *((void **) (((char *) (*((void **) (((char *) temp_v0) + 0x68)))) + 4));
      *((ProbeTriple *) (((char *) arg0) + 0x24)) = *((ProbeTriple *) (((char *) temp_v0_2) + 0x9c));
      temp_v0_3 = *temp_s3;
      *((ProbeTriple *) (((char *) arg0) + 0x3C)) = *((ProbeTriple *) (((char *) temp_v0_3) + 0x3C));
      if (gSceneType != 3)
      {
        *((f32 *) (((char *) arg0) + 0x40)) = (f32) ((*((f32 *) (((char *) arg0) + 0x40))) + 1024.0f);
      }
      actorUnlinkFromSurface(arg0);
      objectListInsert(arg0, *((s32 *) (((char *) (*temp_s3)) + 0x20)));
    }
  }
  else
  {
    sceneTwo = 2;
    sp34 = (s32 *) inline_fn(&sProbeHandles, temp_a0);
    temp_s7 = (void **) (((u8 *) (&sProbeStates)) + temp_a0);
    sp3C = temp_s3;
    var_v0 = 0 & 0xFFFF;
    loop_6:
    __repair_phase_storage.pointer = (void **) (((u8 *) (&sBonusObjectTable)) + (var_v0 * 4));

    if (temp_s0)
    {
      if (var_a0_4 || arg0)
      {
        temp_a0_2 = *__repair_phase_storage.pointer;
      }
      else
      {
        temp_a0_2 = *__repair_phase_storage.pointer;
      }
    }
    else
    {
      temp_a0_2 = *__repair_phase_storage.pointer;
    }
    if (temp_a0_2 == NULL)
    {
      goto next_object;
    }
    temp_v0_4 = *((u16 *) (((char *) temp_a0_2) + 0x78));
    if (((temp_v0_4 == 0x4D) | (temp_v0_4 == 0x61)) != 0)
    {
      goto next_object;
    }
    if (!(approxDistance(temp_a0_2 + 0x24, arg0 + 0x24) < 2.0f))
    {
      goto next_object;
    }
    temp_s4 = *((void **) (((char *) (*__repair_phase_storage.pointer)) + 0x6C));
    __repair_phase_storage.value = temp_s0 == 0;
    if (temp_s4 != NULL)
    {
      var_a0 = -__repair_phase_storage.value;
      if ((*((u8 *) (((char *) (*((void **) (((char *) temp_s4) + 0xB4)))) + 0x12))) == temp_s0)
      {
        if ((*(((u8 *) (&sProbeActive)) + temp_s0)) != 0)
        {
          goto next_object;
        }
        temp_s3_3 = lookupDataEntry(((-(temp_s0 != 0)) & 0x6F) | 0x6E);
        var_a0_3 = 0x290;
        temp_s0_6 = lookupDataEntry(0x28E);
        if (gSceneType == sceneTwo)
        {
          var_a0_3 = 0x28F;
        }
        temp_v0_7 = lookupDataEntry(var_a0_3);
        var_a2_2 = 5;
 do { if (temp_s0 == 0) { var_a2_2 = 0xC; } sprintf((char *) (&D_8011F170), (char *) (&D_8011EFE0), var_a2_2, temp_s3_3, temp_s0_6, temp_v0_7); requestSound(0x219); func_80073AF8(0, D_8010969C, &D_8011F170, -1, -1, 1, 0, 0, 6, 0, 0x3C); temp_v0_8 = temp_s0 * 0xC; } while (0);
        *(((u8 *) (&sProbeActive)) + temp_s0) = 1;
        *((ProbeTriple *) (((char *) arg0) + 0x30)) = *((ProbeTriple *) (((char *) (&sProbePositions)) + temp_v0_8));
        *((ProbeTriple *) (((char *) arg0) + 0x24)) = *((ProbeTriple *) (((char *) arg0) + 0x30));
        temp_s1_3 = temp_s0 * 4;
        temp_s0_7 = (s32 *) (((u8 *) (&sProbeHandles)) + temp_s1_3);
        listUnlinkFree(*temp_s0_7);
        *temp_s0_7 = 0;
        actorUnlinkFromSurface(arg0);
        objectListInsert(arg0, *((s32 *) (((char *) (*((void **) (((char *) (&sProbeObjects)) + temp_s1_3)))) + 0x20)));
        *((s32 *) (((char *) arg0) + 0x3C)) = 0;
        *((f32 *) (((char *) arg0) + 0x40)) = 0.0f;
        *((s32 *) (((char *) arg0) + 0x44)) = 0;
        setActorStatusBits(*((s32 *) (((char *) (&sProbeActors)) + (temp_s0 * 4))));
        temp_a0_4 = *((void **) (((u8 *) (&sProbeStates)) + temp_s1_3));
        *((s32 *) (((char *) temp_a0_4) + 0x28)) = (s32) (((*((s32 *) (((char *) temp_a0_4) + 0x28))) & (~0xFC)) | 0x1C);
        return;
      }
      goto block_26;
    }
    var_a0 = -__repair_phase_storage.value;
    block_26:
    temp_s6_2 = lookupDataEntry((var_a0 & 0x6F) | 0x6E);

    temp_s0_8 = lookupDataEntry(0x28C);
    var_a0_4 = 0x290;
    temp_s3_4 = lookupDataEntry(((-(temp_s0 != 0)) & 0x6F) | 0x6E);
    if (gSceneType == sceneTwo)
    {
      var_a0_4 = 0x28F;
    }
    var_a2_3 = 0xC;
    temp_v1 = lookupDataEntry(var_a0_4);
    if (temp_s0 == 0)
    {
      var_a2_3 = 5;
    }
    sprintf((char *) (&D_8011F170), (char *) (&D_8011EFEC), var_a2_3, temp_s6_2, temp_s0_8, (temp_s0 == 0) ? ((s32) 0xC) : ((s32) 5), temp_s3_4, temp_v1);
    func_80073AF8(0, D_8010969C, &D_8011F170, -1, -1, 1, 0, 0, 6, 0, 0x3C);
    temp_a1_4 = var_s5 & 0xFFFF;
    *sp34 = requestSound(0x21E);
    *(((u8 *) (&sProbeActive)) + temp_s0) = 0;
    *sp3C = *((void **) (((u8 *) (&sBonusObjectTable)) + (temp_a1_4 * 4)));
    func_80064370(arg0, temp_a1_4);
    temp_a0_5 = *temp_s7;
    temp_s0_9 = temp_s0 * 0x24;
    *((s32 *) (((char *) temp_a0_5) + 0x28)) = (s32) (((*((s32 *) (((char *) temp_a0_5) + 0x28))) & (~0xFC)) | 0x10);
    unlinkNode(*temp_s7, ((void **) (&sTrackMarkerTable))[*((s16 *) (((char *) (&D_8011ED10)) + temp_s0_9))], ((void **) (&sTrackMarkerTable))[*((s8 *) (((char *) temp_s4) + 0x182))]);
    *((s16 *) (((char *) (&D_8011ED10)) + temp_s0_9)) = (s16) ((s8) ((u8) (*((s8 *) (((char *) temp_s4) + 0x182)))));
    return;
    next_object:
    var_s5++;

    var_v0 = var_s5 & 0xFFFF;
    if (((u32) var_v0) < 4U)
    {
      goto loop_6;
    }
    temp_s3_2 = temp_s6 & 0xFF;
    temp_s0_3 = temp_s3_2 * 4;
    if ((((*((void **) (((char *) (&sProbeOriginTable)) + temp_s0_3))) == 0) && ((*((u8 *) (((char *) (&sProbeActive)) + temp_s3_2))) == 0)) && (((u32) (timerGetTotalSeconds(&sProbeTimer) - (*((s32 *) (((char *) (&sProbeTimes)) + temp_s0_3))))) >= 0xAU))
    {
      if ((*((u8 *) (((char *) (&sProbeActive)) + temp_s3_2))) == 0)
      {
        temp_v1 = lookupDataEntry(((-(temp_s3_2 != 0)) & 0x6F) | 0x6E);
        var_a0_2 = 0x290;
        if (gSceneType == sceneTwo)
        {
          var_a0_2 = 0x28F;
        }
        temp_s0_3 = lookupDataEntry(var_a0_2);
        temp_s3_4 = lookupDataEntry(0x291);
        var_a2 = 5;
        if (temp_s3_2 == 0)
        {
          var_a2 = 0xC;
        }
        sprintf((char *) (&D_8011F170), (char *) (&D_8011EFE0), var_a2, temp_v1, temp_s0_3, temp_s3_4);
        func_80073AF8(0, D_8010969C, &D_8011F170, -1, -1, 1, 0, 0, 6, 0, 0x3C);
      }
      temp_s1 = temp_s6 & 0xFF;
      temp_v0_6 = (s32 *) inline_fn(&sProbePositions, temp_s1 * 0xC);
      *((ProbeTriple *) (((char *) arg0) + 0x24)) = *((ProbeTriple *) temp_v0_6);
      *((ProbeTriple *) (((char *) arg0) + 0x30)) = *((ProbeTriple *) temp_v0_6);
      *((u8 *) (((char *) (&sProbeActive)) + temp_s1)) = 1;
      temp_s1_2 = temp_s1 * 4;
      temp_s0_5 = (s32 *) inline_fn(&sProbeHandles, temp_s1_2);
      *((void **) (((char *) (&sProbeOriginTable)) + temp_s1_2)) = 0;
      listUnlinkFree(*temp_s0_5);
      *temp_s0_5 = 0;
      actorUnlinkFromSurface(arg0);
      objectListInsert(arg0, *((s32 *) (((char *) (*((void **) (((char *) (&sProbeObjects)) + temp_s1_2)))) + 0x20)));
      setActorStatusBits(*((s32 *) (((char *) (&sProbeActors)) + temp_s1_2)));
    }
  }
}
