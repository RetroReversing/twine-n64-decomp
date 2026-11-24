extern f32 cosAngle(f32);
extern f32 sinAngle(f32);
extern void rotateVec3ByMat3(const void *, void *);
f32 vec3DistanceBetween();
s32 raycastThroughRooms();
s32 vec3NormalizeLength();
void directionToAngles(void *, f32, f32, f32);
s32 setObjectLayerFlag();
s32 clearObjectStateBits();
s32 setActorStatusBits();
extern f32 kRayNoHitDistance;
extern char D_800C46FC[];
extern f64 D_800D44F0;
extern f64 D_800D44F8;
extern char D_80109A98[];
extern char D_80109A9C[];
extern char D_80109AA0[];
extern s32 gBorderSkipActive;
extern u8 gPauseFlag;
extern s32 sEnemyDefTable;
extern void *gTrackMarkerParents[];
typedef struct 
{
  f32 x;
  f32 y;
  f32 z;
} CameraVec;
inline static void *inline_fn(void **arg0)
{
  return *arg0;
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
  u8 v;
} Field_u8;
/* Casts a ray from the track marker along the aim direction, then places the beam's start and end actors at the muzzle and the hit point. */
void updateAimRayBeam(void *obj)
{
  f32 sp28[3];
  f32 rayOrigin[3];
  f32 rayTarget[3];
  f32 hitPoint[3];
  volatile f32 sp68;
  volatile f32 sp6C;
  volatile f32 sp70;
  volatile s32 sp74;
  volatile f32 sp78;
  volatile f32 sp7C;
  volatile f32 sp80;
  volatile f32 sp84;
  volatile f32 sp88;
  volatile long long pad;
  f32 aimRot[2];
  volatile s32 framePad[2];
  volatile s32 hitKind;
  f32 muzzlePos[3];
  void *spD4;
  f32 beamDir[3];
  f32 cameraAim;
  f32 temp_a0;
  f32 temp_a1;
  f32 temp_a2;
  s32 markerIndex;
  f32 temp_fa0;
  f32 temp_fs0;
  f32 temp_fs0_2;
  f32 temp_fs0_3;
  f32 temp_fs0_4;
  f32 temp_fs0_5;
  f32 temp_ft0;
  f32 temp_ft0_2;
  f32 temp_ft1;
  f32 temp_ft1_2;
  f32 temp_fv0;
  f32 beamLength;
  f32 temp_fv0_3;
  f32 temp_fv1;
  s32 temp_v0_6;
  s32 var_v0;
  s8 temp_t0;
  void **markerSlot;
  void *enemyDef;
  void *beamEnd;
  void *player;
  void *beamStart;
  void *temp_v0;
  void *temp_v0_2;
  void *temp_v0_3;
  void *temp_v0_4;
  void *temp_v0_5;
  void *temp_v0_7;
  void *temp_v1;
  char *__base_D_80109A9C;
  spD4 = *((void **) (((char *) obj) + 0x6C)); player=(void *)spD4;
  beamStart = *((void **) (((char *) player) + 0xAC));
  beamEnd = inline_fn((void **) (((char *) player) + 0xB0));
  spD4 = *((void **) (((char *) player) + 0xA8));
  clearObjectStateBits(beamStart);
  clearObjectStateBits(beamEnd);
  if ((((*((s16 *) (((char *) (*((void **) (((char *) player) + 0xA8)))) + 0x7A))) == 0) && (((temp_t0 = ((Field_s8 *) (((char *) player) + 0x182))->v, markerIndex = (s32) temp_t0, markerSlot = &gTrackMarkerParents[temp_t0], enemyDef = ((*((s8 *) (((char *) (*((void **) (((char *) obj) + 0x68)))) + 0xE))) * 0xE8) + ((char *) (&sEnemyDefTable)), sp28[0] = *((f32 *) (((char *) inline_fn(markerSlot)) + 0x34)), sp28[1] = *((f32 *) (((char *) (*markerSlot)) + 0x38)), sp28[2] = 0, (((Field_s32 *) (((char *) enemyDef) + 0x60))->v & 0xC) != 0)) || ((((Field_s16 *) (((char *) obj) + 0x7C))->v == 5)))) && ((beamStart != NULL) && (beamEnd != NULL)))
  {
    temp_v0 = inline_fn(markerSlot);
    *((CameraVec *) rayOrigin) = *((CameraVec *) (((char *) temp_v0) + 0x10));
    temp_fa0 = sp28[1] * 651.8986f;
    aimRot[1] = temp_fa0;
    aimRot[0] = -(sp28[0] * 651.8986f);
    temp_v0_2 = *markerSlot;
    rayTarget[0] = (-((((Field_f32 *) (((char *) temp_v0_2) + 0x78))->v * ((Field_f32 *) (((char *) player) + 0x24))->v) / ((Field_f32 *) (((char *) temp_v0_2) + 0x4C))->v)) / ((Field_f32 *) (((char *) temp_v0_2) + 0x68))->v;
    temp_v0_3 = *markerSlot;
    cameraAim = ((((Field_f32 *) (((char *) temp_v0_3) + 0x7C))->v * ((Field_f32 *) (((char *) player) + 0x28))->v) / ((Field_f32 *) (((char *) temp_v0_3) + 0x4C))->v) / ((Field_f32 *) (((char *) temp_v0_3) + 0x6C))->v;
    rayTarget[2] = 1.0f;
    rayTarget[1] = cameraAim;
    sp68 = cosAngle(temp_fa0);
    temp_fs0 = sinAngle(aimRot[0]);
    sp6C = (-temp_fs0) * sinAngle(aimRot[1]);
    temp_fs0_2 = sinAngle(aimRot[1]);
    temp_fs0_3 = temp_fs0_2 * cosAngle(aimRot[0]);
    sp74 = 0;
    sp70 = temp_fs0_3;
    sp78 = cosAngle(aimRot[0]);
    sp7C = sinAngle(aimRot[0]);
    sp80 = -sinAngle(aimRot[1]);
    temp_fs0_4 = cosAngle(aimRot[1]);
    sp84 = -(temp_fs0_4 * sinAngle(aimRot[0]));
    temp_fs0_5 = cosAngle(aimRot[0]);
    sp88 = temp_fs0_5 * cosAngle(aimRot[1]);
    rotateVec3ByMat3((const void *) (&sp68), rayTarget);
    vec3NormalizeLength(rayTarget, rayTarget);
    temp_ft1 = rayTarget[0] * 256.0f;
    temp_ft0 = rayTarget[1] * 256.0f;
    temp_fv0 = rayTarget[2] * 256.0f;
    rayTarget[0] = temp_ft1;
    rayTarget[1] = temp_ft0;
    rayTarget[2] = temp_fv0;
    rayTarget[0] = temp_ft1 + rayOrigin[0];
    rayTarget[1] = temp_ft0 + rayOrigin[1];
    rayTarget[2] = temp_fv0 + rayOrigin[2];
    if (((Field_s16 *) (((char *) obj) + 0x7C))->v == 5)
    {
      temp_v0_4 = inline_fn((void **) (((char *) inline_fn((void **) (((char *) player) + 0xBC))) + 0x6C));
      *((CameraVec *) (((char *) temp_v0_4) + 0)) = *((CameraVec *) rayTarget);
    }
    if ((raycastThroughRooms(rayOrigin, rayTarget, *((s32 *) (((char *) inline_fn(markerSlot)) + 0xF4)), hitPoint, &hitKind, 0, ((Field_s32 *) (((char *) player) + 0))->v, 1, 0) << 0x18) != 0)
    {
      *((CameraVec *) hitPoint) = *((CameraVec *) rayTarget);
    }
    *((CameraVec *) muzzlePos) = *((CameraVec *) (void *)((((Field_u16 *) (((char *) enemyDef) + 0x90))->v * 0xC) + inline_fn((char **) (((char *) (*((void **) (((char *) spD4) + 0x68)))) + 4))));
    muzzlePos[1] = -muzzlePos[1];
    muzzlePos[0] = -muzzlePos[0];
    rotateVec3ByMat3((const void *) (&sp68), muzzlePos);
    muzzlePos[0] += *((f32 *) (((char *) gTrackMarkerParents[((Field_s8 *) (((char *) player) + 0x182))->v]) + 0x10));
    muzzlePos[1] += *((f32 *) (((char *) gTrackMarkerParents[((Field_s8 *) (((char *) player) + 0x182))->v]) + 0x14));
    muzzlePos[2] += *((f32 *) (((char *) gTrackMarkerParents[((Field_s8 *) (((char *) player) + 0x182))->v]) + 0x18));
    beamLength = vec3DistanceBetween(muzzlePos, hitPoint);
    ((Field_f32 *) (((char *) beamStart) + 0x54))->v = beamLength;
    *((CameraVec *) (((char *) beamStart) + 36)) = *((CameraVec *) muzzlePos);
    temp_ft1_2 = muzzlePos[0] - hitPoint[0];
    temp_ft0_2 = muzzlePos[1] - hitPoint[1];
    temp_fv1 = muzzlePos[2] - hitPoint[2];
    beamDir[0] = temp_ft1_2;
    beamDir[1] = temp_ft0_2;
    beamDir[2] = temp_fv1;
    directionToAngles(beamStart + 0x3C, temp_ft1_2, temp_ft0_2, temp_fv1);
    ((Field_s32 *) (((char *) beamStart) + 0x44))->v = 0;
    ((Field_s32 *) (((char *) beamStart) + 0x58))->v |= 0x10000;
    ((Field_f32 *) (((char *) beamStart) + 0x3C))->v = (f32) (-((Field_f32 *) (((char *) beamStart) + 0x3C))->v);
    ((Field_s32 *) (((char *) beamEnd) + 0x58))->v |= 0x10000;
    ((Field_f32 *) (((char *) beamEnd) + 0x24))->v = hitPoint[0];
    ((Field_f32 *) (((char *) beamEnd) + 0x28))->v = hitPoint[1];
    ((Field_f32 *) (((char *) beamEnd) + 0x2C))->v = hitPoint[2];
    if (hitKind == 1)
    {
      ((Field_s8 *) (((char *) beamEnd) + 0x7F))->v = 0x40;
      ((Field_s8 *) (((char *) beamEnd) + 0x80))->v = 0;
      ((Field_s8 *) (((char *) beamEnd) + 0x81))->v = 0;
    }
    else
    {
      ((Field_u8 *) (((char *) beamEnd) + 0x7F))->v = 0xFF;
      ((Field_u8 *) (((char *) beamEnd) + 0x80))->v = 0xFF;
      ((Field_u8 *) (((char *) beamEnd) + 0x81))->v = 0xFF;
    }
    if (muzzlePos)
    {
      temp_v1 = *((void **) (((char *) obj) + 0x68));
    }
    else
    {
      temp_v1 = *((void **) (((char *) obj) + 0x68));
    }
    if ((((Field_u16 *) (((char *) temp_v1) + 0xC))->v & 1) && ((*((s32 *) (D_800C46FC + (((Field_s8 *) (((char *) temp_v1) + 0xE))->v * 0xE8)))) & 8))
    {
      temp_v0_6 = markerIndex * 0xC;
      *((CameraVec *) (D_80109A98 + temp_v0_6)) = *((CameraVec *) hitPoint);
    }
    if (((Field_s16 *) (((char *) obj) + 0x7C))->v == 5)
    {
      do
      {
        temp_v0_7 = *((void **) (((char *) (*((void **) (((char *) player) + 0xBC)))) + 0x6C));
        *((CameraVec *) (((char *) temp_v0_7) + 0)) = *((CameraVec *) hitPoint);
      }
      while (0);
    }
    if (((Field_s32 *) (((char *) enemyDef) + 0x60))->v & 4)
    {
      temp_fv0_3 = (f32) (((f64) ((beamLength * beamLength) / kRayNoHitDistance)) + D_800D44F0);
      ((Field_f32 *) (((char *) beamEnd) + 0x54))->v = temp_fv0_3;
      if (D_800D44F8 < ((f64) temp_fv0_3))
      {
        ((Field_f32 *) (((char *) beamEnd) + 0x54))->v = 4.0f;
      }
      if (gBorderSkipActive != 0)
      {
        if (gPauseFlag != 0)
        {
          setActorStatusBits(beamStart);
        }
      }
      else
      {
        setObjectLayerFlag(beamStart, ((Field_s8 *) (((char *) player) + 0x182))->v);
      }
      setActorStatusBits(beamEnd);
    }
  }
}
