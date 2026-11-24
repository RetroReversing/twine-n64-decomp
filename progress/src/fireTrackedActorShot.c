s32 UpdateActorTargetEffect();
f32 vec3DistanceBetween();
f32 cosAngle(f32);
s32 raycastThroughRooms();
s32 vec3NormalizeLength();
void directionToAngles(void *, f32, f32, f32);
s32 spawnEnemyShotEffect();
s32 setObjectChannelMask();
s32 setEffectPairAnimFrames();
s32 resetActorProbeState();
s32 listUnlinkFree();
s32 rotateVec3ByMat3();
f32 sinAngle(f32);
void *spawnActorEffect(s16, void *, void *, s32, s32, void *, s32);
extern char D_800C46FC[];
extern f32 D_800C683C;
extern s16 D_800C6858;
extern u16 D_800C68BA;
extern char D_80109A98[];
extern char D_80109A9C[];
extern char D_80109AA0[];
extern s32 D_801176D8;
extern s32 gBorderSkipActive;
extern void *gSweepHitActor;
extern void *gTrackMarkerParents[];
typedef struct 
{
  f32 x;
  f32 y;
  f32 z;
} VecTrack;
/* Aims from a track marker toward the target, raycasts through rooms, spawns the shot effects and advances the target state. */ void fireTrackedActorShot(void *arg0, f32 *arg1)
{
  volatile f32 sp28[4];
  f32 sp38[4];
  f32 sp48[4];
  f32 sp58[4];
  f32 sp68[4];
  f32 sp78[4];
  f32 sp88[12];
  f32 spB8[4];
  f32 framePad[4];
  void (*temp_a1_2)(void *);
  f32 temp_a0;
  f32 temp_a1;
  f32 cameraAim;
  f32 temp_fa0;
  f32 temp_fs0;
  f32 temp_fs0_2;
  f32 temp_fs0_3;
  register f32 temp_fs0_4;
  f32 temp_fs0_5;
  f32 temp_ft0;
  f32 temp_ft1;
  f32 temp_fv0;
  s32 temp_a0_2;
  s32 temp_v0_4;
  void *temp_v0_5;
  u32 var_s0;
  void *temp_v0_6;
  s32 temp_s7;
  u32 var_s0_2;
  void * volatile *temp_s4;
  void *temp_s2;
  register void *temp_v0;
  void *temp_v0_2;
  register void *temp_v0_3;
  temp_s2 = *((void **) (((char *) arg0) + 0x6C));
  temp_s7 = *((s8 *) (((char *) temp_s2) + 0x182));
  { char *base = (char *) gTrackMarkerParents; s32 offset = temp_s7 * 4; temp_s4 = (void * volatile *) (offset + base); }
  sp28[0] = *((f32 *) (((char *) (*temp_s4)) + 0x34));
  temp_a1 = *((f32 *) (((char *) (*temp_s4)) + 0x38));
  sp28[2] = 0;
  sp28[1] = temp_a1;
  if ((*((u8 *) (((char *) temp_s2) + 0x184))) == 0)
  {
    temp_v0 = *temp_s4;
    *((VecTrack *) sp48) = *((VecTrack *) (((char *) temp_v0) + 0x10));
    temp_a0 = -(sp28[0] * 651.8986f);
    temp_fa0 = sp28[1] * 651.8986f;
    sp38[1] = temp_fa0;
    sp38[0] = temp_a0;
    temp_v0_2 = *temp_s4;
    sp58[0] = (-(((*((f32 *) (((char *) temp_v0_2) + 0x78))) * (*((f32 *) (((char *) temp_s2) + 0x24)))) / (*((f32 *) (((char *) temp_v0_2) + 0x4C))))) / (*((f32 *) (((char *) temp_v0_2) + 0x68)));
    temp_v0_3 = *temp_s4;
    cameraAim = (((*((f32 *) (((char *) temp_v0_3) + 0x7C))) * (*((f32 *) (((char *) temp_s2) + 0x28)))) / (*((f32 *) (((char *) temp_v0_3) + 0x4C)))) / (*((f32 *) (((char *) temp_v0_3) + 0x6C)));
    sp58[2] = 1.0f;
    sp58[1] = cameraAim;
    sp88[0] = cosAngle(temp_fa0);
    temp_fs0 = sinAngle(sp38[0]);
    sp88[1] = (-temp_fs0) * sinAngle(sp38[1]);
    temp_fs0_2 = sinAngle(sp38[1]);
    temp_fs0_3 = temp_fs0_2 * cosAngle(sp38[0]);
    sp88[3] = 0;
    sp88[2] = temp_fs0_3;
    sp88[4] = cosAngle(sp38[0]);
    sp88[5] = sinAngle(sp38[0]);
    sp88[6] = -sinAngle(sp38[1]);
    temp_fs0_4 = cosAngle(sp38[1]);
    sp88[7] = -(temp_fs0_4 * sinAngle(sp38[0]));
    temp_fs0_5 = cosAngle(sp38[0]);
    sp88[8] = temp_fs0_5 * cosAngle(sp38[1]);
    rotateVec3ByMat3(sp88, sp58);
    vec3NormalizeLength(sp58, sp58);
    temp_ft1 = sp58[0] * 256.0f;
    temp_ft0 = sp58[1] * 256.0f;
    temp_fv0 = sp58[2] * 256.0f;
    sp58[0] = temp_ft1;
    sp58[1] = temp_ft0;
    sp58[2] = temp_fv0;
    sp58[0] = temp_ft1 + sp48[0];
    sp58[1] = temp_ft0 + sp48[1];
    sp58[2] = temp_fv0 + sp48[2];
    if ((*((s32 *) (D_800C46FC + ((*((s8 *) (((char *) (*((void **) (((char *) arg0) + 0x68)))) + 0xE))) * 0xE8)))) & 8)
    {
      temp_v0_4 = temp_s7 * 0xC;
      *((VecTrack *) (D_80109A98 + temp_v0_4)) = *((VecTrack *) sp58);
    }
    if ((raycastThroughRooms(sp48, sp58, *((s32 *) (((char *) (*temp_s4)) + 0xF4)), sp68, 0, 0, *((s32 *) (((char *) temp_s2) + 0)), 0, 0) << 0x18) == 0)
    {
      if (((((*((s16 *) (((char *) (*((void **) (((char *) temp_s2) + 0xA8)))) + 0x7A))) == 0) && ((*((s8 *) (((char *) (*((void **) (((char *) arg0) + 0x68)))) + 0xE))) == 0x21)) && (gSweepHitActor != NULL)) && ((*((s16 *) (((char *) gSweepHitActor) + 0x7A))) == 0x72))
      {
        f32 distance = vec3DistanceBetween(sp48, sp68);
        volatile f32 *threshold = &D_800C683C;
        if (distance < (*threshold))
        {
          temp_a0_2 = *((s32 *) (((char *) temp_s2) + 8));
          if (temp_a0_2 != (-1))
          {
            listUnlinkFree(temp_a0_2);
            *((s32 *) (((char *) temp_s2) + 8)) = -1;
          }
          *((s32 *) (((char *) temp_s2) + 0x10)) = D_800C6858;
          arg1 = (f32 *) (((char *) threshold) - 0x18);
          resetActorProbeState(temp_s2, *((void **) (((char *) temp_s2) + 0xA8)), D_800C68BA);
        }
      }
      UpdateActorTargetEffect(arg0, sp68);
      sp68[0] -= sp48[0];
      sp68[1] -= sp48[1];
      sp68[2] -= sp48[2];
      vec3NormalizeLength(sp78, sp68);
      directionToAngles(spB8, sp68[0], sp68[1], sp68[2]);
      spB8[2] = 0;
      spB8[0] = -spB8[0];
      setEffectPairAnimFrames(arg0);
      if (((*((s32 *) (((char *) arg1) + 0x64))) & 0x201) == 1)
      {
        volatile s32 *counter = &D_801176D8;
        *counter += 1;
      }
      var_s0 = 0;
      if ((*((u8 *) (((char *) arg1) + 0x14))) != 0)
      {
        do
        {
          temp_v0_5 = spawnActorEffect((s16) temp_s7, arg0, arg1, (s32) sp48, (s32) spB8, sp78, *((s32 *) (((char *) temp_s2) + 0)));
          if (temp_v0_5 != 0)
          {
            setObjectChannelMask(temp_v0_5, temp_s7);
          }
          ++var_s0;
        }
        while (var_s0 < ((u8) (*((u8 *) (((char *) arg1) + 0x14)))));
      }
    }
    else
    {
      sp68[0] = sp58[0] - sp48[0];
      sp68[1] = sp58[1] - sp48[1];
      sp68[2] = sp58[2] - sp48[2];
      vec3NormalizeLength(sp78, sp68);
      directionToAngles(sp38, sp68[0], sp68[1], sp68[2]);
      sp38[2] = 0;
      sp38[0] = -sp38[0];
      setEffectPairAnimFrames(arg0);
      if (((*((s32 *) (((char *) arg1) - -0x64))) & 0x201) == 1)
      {
        volatile s32 *counter = &D_801176D8;
        *counter += 1;
      }
      var_s0_2 = 0;
      if ((*((u8 *) (((char *) arg1) + 0x14))) != 0)
      {
        do
        {
          temp_v0_6 = spawnActorEffect((s16) temp_s7, arg0, arg1, (s32) sp48, (s32) sp38, sp78, *((s32 *) (((char *) temp_s2) + 0)));
          if (temp_v0_6 != 0)
          {
            if (arg0)
            {
              setObjectChannelMask(temp_v0_6, temp_s7);
            }
            else
            {
              setObjectChannelMask(temp_v0_6, temp_s7);
            }
          }
          var_s0_2 += 1;
        }
        while (var_s0_2 < ((u8) (*((u8 *) (((char *) arg1) + 0x14)))));
      }
      UpdateActorTargetEffect(arg0, sp58);
    }
    if ((((*((u8 *) (((char *) arg1) + 0x9E))) != 0xFF) && ((*((s32 *) (((char *) arg1) + 0x60))) & 0x100)) && (((unsigned) gBorderSkipActive) == 0))
    {
      spawnEnemyShotEffect(arg0, (*((s32 *) (((char *) (*((void **) (((char *) (*((void **) (((char *) temp_s2) + 0xA8)))) + 0x68)))) + 4))) + ((6 * (*((u16 *) (((char *) arg1) + 0x90)))) * 2));
    }
    *((f32 *) (((char *) temp_s2) + 0x70)) -= *((f32 *) (((char *) arg1) + 0x88));
    *((f32 *) (((char *) temp_s2) + 0x74)) += *((f32 *) (((char *) arg1) + 0x8C));
    if ((*((u8 *) (((char *) arg1) + 0x80))) == 0)
    {
      temp_a1_2 = *((void (**)(void *)) (((char *) arg1) + 0xD0));
      if (temp_a1_2 != ((s32) NULL))
      {
        temp_a1_2(arg0);
      }
    }
  }
}

