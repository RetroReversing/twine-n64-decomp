extern f32 cosAngle(f32);
extern f32 sinAngle(f32);
extern void rotateVec3ByMat3(const void *, void *);
f32 Vec3_DistanceSq();
s32 func_800158A4();
s32 func_80045764();
void func_80046384(void *, f32, f32, f32);
s32 func_80064318();
s32 func_800643D8();
s32 setActorStatusBits();
extern f32 D_800C0740;
extern char D_800C46FC[];
extern f64 D_800D44F0;
extern f64 D_800D44F8;
extern char D_80109A98[];
extern char D_80109A9C[];
extern char D_80109AA0[];
extern s32 gBorderSkipActive;
extern u8 gPauseFlag;
extern s32 sEnemyDefTable;
extern void *sTrackMarkerTable[];
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

typedef struct { f32 v; } Field_f32;
typedef struct { s16 v; } Field_s16;
typedef struct { s32 v; } Field_s32;
typedef struct { s8 v; } Field_s8;
typedef struct { u16 v; } Field_u16;
typedef struct { u8 v; } Field_u8;
void func_80069250(void *arg0)
{
  f32 sp28[3];
  f32 sp38[3];
  f32 sp48[3];
  f32 sp58[3];
  volatile f32 sp68;
  volatile f32 sp6C;
  volatile f32 sp70;
  volatile s32 sp74;
  volatile f32 sp78;
  volatile f32 sp7C;
  volatile f32 sp80;
  volatile f32 sp84;
  volatile f32 sp88;
  f32 sp98[2];
  s32 spA8;
  f32 spB0[3];
  f32 spC0[3];
  void *spD4;
  s32 spDC;
  f32 cameraAim;
  f32 temp_a0;
  f32 temp_a1;
  f32 temp_a2;
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
  f32 temp_fv0_2;
  f32 temp_fv0_3;
  f32 temp_fv1;
  s32 temp_v0_6;
  s32 var_v0;
  s8 temp_t0;
  void **temp_s5;
  void *temp_fp;
  void *temp_s2;
  void *temp_s3;
  void *temp_s4;
  void *temp_v0;
  void *temp_v0_2;
  void *temp_v0_3;
  void *temp_v0_4;
  void *temp_v0_5;
  void *temp_v0_7;
  void *temp_v1;
  char *__base_D_80109A9C;
  temp_s3 = *((void **) (((char *) arg0) + 0x6C));
  temp_s4 = *((void **) (((char *) temp_s3) + 0xAC));
  temp_s2 = inline_fn((void **) (((char *) temp_s3) + 0xB0));
  spD4 = *((void **) (((char *) temp_s3) + 0xA8));
  func_800643D8(temp_s4);
  func_800643D8(temp_s2);
  if ((((*((s16 *) (((char *) (*((void **) (((char *) temp_s3) + 0xA8)))) + 0x7A))) == 0) && (((temp_t0 = (((Field_s8 *) (((char *) temp_s3) + 0x182))->v), spDC = (s32) temp_t0, temp_s5 = &sTrackMarkerTable[temp_t0], sp28[0] = *((f32 *) (((char *) inline_fn(temp_s5)) + 0x34)), temp_fp = ((*((s8 *) (((char *) (*((void **) (((char *) arg0) + 0x68)))) + 0xE))) * 0xE8) + ((char *) (&sEnemyDefTable)), sp28[2] = 0, sp28[1] = *((f32 *) (((char *) (*temp_s5)) + 0x38)), var_v0 = temp_s4 != NULL, (((((Field_s32 *) (((char *) temp_fp) + 0x60))->v)) & 0xC) != 0)) || ((var_v0 = temp_s4 != NULL, ((((Field_s16 *) (((char *) arg0) + 0x7C))->v)) == 5)))) && (var_v0 & (temp_s2 != NULL)))
  {
    temp_v0 = inline_fn(temp_s5);
    *((CameraVec *) sp38) = *((CameraVec *) (((char *) temp_v0) + 0x10));
    temp_fa0 = sp28[1] * 651.8986f;
    sp98[1] = temp_fa0;
    sp98[0] = -(sp28[0] * 651.8986f);
    temp_v0_2 = *temp_s5;
    sp48[0] = (-((((((Field_f32 *) (((char *) temp_v0_2) + 0x78))->v)) * ((((Field_f32 *) (((char *) temp_s3) + 0x24))->v))) / ((((Field_f32 *) (((char *) temp_v0_2) + 0x4C))->v)))) / ((((Field_f32 *) (((char *) temp_v0_2) + 0x68))->v));
    temp_v0_3 = *temp_s5;
    cameraAim = ((((((Field_f32 *) (((char *) temp_v0_3) + 0x7C))->v)) * ((((Field_f32 *) (((char *) temp_s3) + 0x28))->v))) / ((((Field_f32 *) (((char *) temp_v0_3) + 0x4C))->v))) / ((((Field_f32 *) (((char *) temp_v0_3) + 0x6C))->v));
    sp48[2] = 1.0f;
    sp48[1] = cameraAim;
    sp68 = cosAngle(temp_fa0);
    temp_fs0 = sinAngle(sp98[0]);
    sp6C = (-temp_fs0) * sinAngle(sp98[1]);
    temp_fs0_2 = sinAngle(sp98[1]);
    temp_fs0_3 = temp_fs0_2 * cosAngle(sp98[0]);
    sp74 = 0;
    sp70 = temp_fs0_3;
    sp78 = cosAngle(sp98[0]);
    sp7C = sinAngle(sp98[0]);
    sp80 = -sinAngle(sp98[1]);
    temp_fs0_4 = cosAngle(sp98[1]);
    sp84 = -(temp_fs0_4 * sinAngle(sp98[0]));
    temp_fs0_5 = cosAngle(sp98[0]);
    sp88 = temp_fs0_5 * cosAngle(sp98[1]);
    rotateVec3ByMat3((const void *) (&sp68), sp48);
    func_80045764(sp48, sp48);
    temp_ft1 = sp48[0] * 256.0f;
    temp_ft0 = sp48[1] * 256.0f;
    temp_fv0 = sp48[2] * 256.0f;
    sp48[0] = temp_ft1;
    sp48[1] = temp_ft0;
    sp48[2] = temp_fv0;
    sp48[0] = temp_ft1 + sp38[0];
    sp48[1] = temp_ft0 + sp38[1];
    sp48[2] = temp_fv0 + sp38[2];
    if (((((Field_s16 *) (((char *) arg0) + 0x7C))->v)) == 5)
    {
      temp_v0_4 = inline_fn((void **) (((char *) inline_fn((void **) (((char *) temp_s3) + 0xBC))) + 0x6C));
      *((CameraVec *) (((char *) temp_v0_4) + 0)) = *((CameraVec *) sp48);
    }
    if ((func_800158A4(sp38, sp48, *((s32 *) (((char *) inline_fn(temp_s5)) + 0xF4)), sp58, &spA8, 0, (((Field_s32 *) (((char *) temp_s3) + 0))->v), 1, 0) << 0x18) != 0)
    {
      *((CameraVec *) sp58) = *((CameraVec *) sp48);
    }
    temp_v0_5 = (((((Field_u16 *) (((char *) temp_fp) + 0x90))->v)) * 0xC) + inline_fn((char **) (((char *) (*((void **) (((char *) spD4) + 0x68)))) + 4));
    *((CameraVec *) spB0) = *((CameraVec *) temp_v0_5);
    spB0[1] = -spB0[1];
    spB0[0] = -spB0[0];
    rotateVec3ByMat3((const void *) (&sp68), spB0);
    spB0[0] += *((f32 *) (((char *) sTrackMarkerTable[(((Field_s8 *) (((char *) temp_s3) + 0x182))->v)]) + 0x10));
    spB0[1] += *((f32 *) (((char *) sTrackMarkerTable[(((Field_s8 *) (((char *) temp_s3) + 0x182))->v)]) + 0x14));
    spB0[2] += *((f32 *) (((char *) sTrackMarkerTable[(((Field_s8 *) (((char *) temp_s3) + 0x182))->v)]) + 0x18));
    temp_fv0_2 = Vec3_DistanceSq(spB0, sp58);
    (((Field_f32 *) (((char *) temp_s4) + 0x54))->v) = temp_fv0_2;
    *((CameraVec *) (((char *) temp_s4) + 36)) = *((CameraVec *) spB0);
    temp_ft1_2 = spB0[0] - sp58[0];
    temp_ft0_2 = spB0[1] - sp58[1];
    temp_fv1 = spB0[2] - sp58[2];
    spC0[0] = temp_ft1_2;
    spC0[1] = temp_ft0_2;
    spC0[2] = temp_fv1;
    func_80046384(temp_s4 + 0x3C, temp_ft1_2, temp_ft0_2, temp_fv1);
    (((Field_s32 *) (((char *) temp_s4) + 0x44))->v) = 0;
    (((Field_s32 *) (((char *) temp_s4) + 0x58))->v) |= 0x10000;
    (((Field_f32 *) (((char *) temp_s4) + 0x3C))->v) = (f32) (-((((Field_f32 *) (((char *) temp_s4) + 0x3C))->v)));
    (((Field_s32 *) (((char *) temp_s2) + 0x58))->v) |= 0x10000;
    (((Field_f32 *) (((char *) temp_s2) + 0x24))->v) = sp58[0];
    (((Field_f32 *) (((char *) temp_s2) + 0x28))->v) = sp58[1];
    (((Field_f32 *) (((char *) temp_s2) + 0x2C))->v) = sp58[2];
    if (spA8 == 1)
    {
      (((Field_s8 *) (((char *) temp_s2) + 0x7F))->v) = 0x40;
      (((Field_s8 *) (((char *) temp_s2) + 0x80))->v) = 0;
      (((Field_s8 *) (((char *) temp_s2) + 0x81))->v) = 0;
    }
    else
    {
      (((Field_u8 *) (((char *) temp_s2) + 0x7F))->v) = 0xFF;
      (((Field_u8 *) (((char *) temp_s2) + 0x80))->v) = 0xFF;
      (((Field_u8 *) (((char *) temp_s2) + 0x81))->v) = 0xFF;
    }
    if (spB0)
    {
      temp_v1 = *((void **) (((char *) arg0) + 0x68));
    }
    else
    {
      temp_v1 = *((void **) (((char *) arg0) + 0x68));
    }
    if ((((((Field_u16 *) (((char *) temp_v1) + 0xC))->v)) & 1) && ((*((s32 *) (D_800C46FC + (((((Field_s8 *) (((char *) temp_v1) + 0xE))->v)) * 0xE8)))) & 8))
    {
      temp_v0_6 = spDC * 0xC;
      *((CameraVec *) (D_80109A98 + temp_v0_6)) = *((CameraVec *) sp58);
    }
    if (((((Field_s16 *) (((char *) arg0) + 0x7C))->v)) == 5)
    {
      temp_v0_7 = *((void **) (((char *) (*((void **) (((char *) temp_s3) + 0xBC)))) + 0x6C));
      *((CameraVec *) (((char *) temp_v0_7) + 0)) = *((CameraVec *) sp58);
    }
    if (((((Field_s32 *) (((char *) temp_fp) + 0x60))->v)) & 4)
    {
      temp_fv0_3 = (f32) (((f64) ((temp_fv0_2 * temp_fv0_2) / D_800C0740)) + D_800D44F0);
      (((Field_f32 *) (((char *) temp_s2) + 0x54))->v) = temp_fv0_3;
      if (D_800D44F8 < ((f64) temp_fv0_3))
      {
        (((Field_f32 *) (((char *) temp_s2) + 0x54))->v) = 4.0f;
      }
      if (gBorderSkipActive != 0)
      {
        if (gPauseFlag != 0)
        {
          setActorStatusBits(temp_s4);
        }
      }
      else
      {
        func_80064318(temp_s4, (((Field_s8 *) (((char *) temp_s3) + 0x182))->v));
      }
      setActorStatusBits(temp_s2);
    }
  }
}

