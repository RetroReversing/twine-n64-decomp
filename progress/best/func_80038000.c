s32 func_8000BBB4(s32 *, f32, f32, s32);
s32 func_80014E30(void *);
s32 func_80014EB0(s32, f32 *);
s32 func_800156F4();
s32 func_80015BA8(void *, s32, f32 *);
s32 func_800325E4(void *, void *, f32, s32, f32, f32, f32);
s32 func_80034928(void *, s32);
s32 func_800349B4(void *);
s32 func_80034EAC(s32);
s32 func_800355BC(void *);
f32 func_800357C8(f32);
s32 func_80035854(void *, f32, f32);
s32 func_800358D4(void *);
s32 func_80036108(void *);
s32 func_800362B4(void *);
s32 func_80036820(void *);
s32 func_800369B8(void *);
s32 func_80036B38(void *);
s32 func_80036BBC(void *);
s32 func_800371E0(void *);
s32 func_800374BC(void *);
s32 func_80037A7C(void *);
s32 func_80037BDC(void *);
s32 func_80037C84(void *);
s32 func_80037DC0(void *);
s32 func_80045180(void *, void *, void *, f32);
s32 func_8006F90C(void *);
s32 func_80082C8C(void *);
s32 func_80082CFC(void *);
s32 func_800839F0(void *, void *, void *);
s32 func_800A3840(s32 *, s32 *, f32 *);
s32 guMtxF2L(f32 *, void *);
s32 guTranslateF(s32 *, f32, f32, f32);
s32 renderObjectList(void *);
s32 updateObjectColor(void *);
extern u16 D_800B35B0;
extern f32 D_800C0740;
extern s8 D_800C43A0[];
extern s32 D_800E1710;
extern s32 D_800E1714;
extern s32 D_801007B8;
extern void *D_80107E9C;
extern s32 D_80109E28;
extern s32 D_8010A4D8;
extern u8 D_8010D2B0;
extern f32 gCullFarDistance;
extern s32 gObjectList;
extern s32 sCurrentMatrixSlot;
extern void *sDisplayListCursor;
extern u32 sMatrixPoolLimit;
extern u32 sMatrixPoolUsed;
extern s32 sObjectMatrixF;
extern f32 sParentMatrixF;
extern void *sRenderState;
typedef struct 
{
  unsigned char pad[244];
  int value;
} __repair_field_F4;
typedef struct 
{
  int value;
} __repair_field_0;
inline static s32 inline_fn(f32 arg0, float arg1)
{
  return (s32) (2.0f * (arg0 * arg1));
}

inline static char *inline_fn2(void *arg0)
{
  return (char *) arg0;
}

void func_80038000(void *arg0, s32 arg1)
{
  typedef struct 
  {
    u32 words[3];
  } ThreeWords;
  typedef union 
  {
    f32 values[4];
    u32 words[4];
  } ClipBounds;
  unsigned short temp_v0;
  f32 *var_s0;
  register f32 *var_v1;
  f32 temp_fs3;
  f32 temp_fv0;
  void *var_s0_2;
  f32 temp_fv1_2;
  int temp_s0_2;
  short temp_s1;
  unsigned char temp_s3;
  register void *temp_v1_3;
  ClipBounds clipBounds;
  s32 var_a0;
  u32 var_a1;
  void *temp_v1_2;
  do
  {
    void *temp_a1_2;
    void *temp_s0;
    void *temp_s0_3;
    void *temp_v1;
    void *temp_a1;
    int temp_s7;
    f32 temp_fv1;
    temp_fs3 = *((f32 *) (((char *) arg0) + 0x4C));
    if ((*((s32 *) (((char *) arg0) + 0x100))) & 4)
    {
      gCullFarDistance = 15.0f;
      if (D_8010D2B0 != 0)
      {
        gCullFarDistance = 7.5f;
      }
    }
    else
    {
      gCullFarDistance = D_800C0740;
      *((f32 *) (((char *) arg0) + 0x148)) = 2.0f;
    }
    *((ThreeWords *) (((char *) arg0) + 0x1C)) = *((ThreeWords *) (((char *) arg0) + 0x10));
    *((ThreeWords *) (((char *) arg0) + 0x40)) = *((ThreeWords *) (((char *) arg0) + 0x34)); temp_fv1 = *((f32 *) (((char *) arg0) + 0x120));
    if (temp_fv1 > 0.0f)
    {
      f32 horizontal = temp_fv1 * 0.4f;
      f32 vertical = temp_fv1 * 0.2f;
      temp_fv0 = 2.0f * temp_fv1;
      func_80035854(arg0 + 0x1C, temp_fv0, temp_fv0);
      func_80035854(arg0 + 0x40, horizontal, vertical);
      temp_fv1_2 = (*((f32 *) (((char *) arg0) + 0x120))) - func_800357C8((*((f32 *) (((char *) arg0) + 0x120))) * 0.25f);
      *((f32 *) (((char *) arg0) + 0x120)) = temp_fv1_2;
      if (temp_fv1_2 < 0.0f)
      {
        *((f32 *) (((char *) arg0) + 0x120)) = 0.0f;
      }
    }
    func_8006F90C(arg0);
    D_800E1714 = func_80034EAC((s32) arg1); D_800E1710 = (int) arg1; D_80107E9C = NULL; gObjectList = 0; D_800B35B0 += 1;
    if (((__repair_field_F4 *) arg0)->value != 0)
    {
      clipBounds = *((ClipBounds *) (((u8 *) arg0) + 0x50)); temp_s7 = ((__repair_field_F4 *) arg0)->value;
      cameraUpdateProjection(arg0, *((f32 *) (((char *) arg0) + 0x84)));
      temp_s0 = arg0 + 0x88;
      func_80045180(arg0 + 0x40, arg0 + 0xB8, temp_s0, temp_fs3);
      func_800839F0(temp_s0, arg0 + 0x1C, arg0 + 0xE8);
      temp_s0_2 = ((s32) arg1) * 0x10; temp_a1 = sRenderState + temp_s0_2;
      *((f32 *) (((char *) arg0) + 0xB0)) = (f32) (-(*((f32 *) (((char *) arg0) + 0xEC))));
      *((f32 *) (((char *) arg0) + 0xAC)) = (f32) (-(*((f32 *) (((char *) arg0) + 0xE8))));
      *((f32 *) (((char *) arg0) + 0xB4)) = (f32) (-(*((f32 *) (((char *) arg0) + 0xF0))));
      *((s16 *) (((char *) temp_a1) + 0x300)) = (s16) inline_fn(temp_fs3, (*((f32 *) (((char *) arg0) + 0x54))) - (*((f32 *) (((char *) arg0) + 0x50))));
      *((s16 *) (((char *) temp_a1) + 0x304)) = 0x2FF;
      *((s16 *) (((char *) temp_a1) + 0x306)) = 0;
      *((s16 *) (((char *) temp_a1) + 0x302)) = (s16) ((s32) (2.0f * (temp_fs3 * ((*((f32 *) (((char *) arg0) + 0x5C))) - (*((f32 *) (((char *) arg0) + 0x58)))))));
      if ((*((s32 *) (((char *) arg0) + 0x100))) & 8)
      {
        *((s16 *) (((char *) temp_a1) + 0x300)) = (s16) ((s32) (((f32) (*((s16 *) (((char *) temp_a1) + 0x300)))) + (((f32) ((*(D_800C43A0 + (D_801007B8 & 0x7F))) + 0x80)) * 0.078125f)));
        *((s16 *) (((char *) temp_a1) + 0x302)) = (s16) ((s32) (((f32) (*((s16 *) (((char *) temp_a1) + 0x302)))) + (((f32) ((*(D_800C43A0 + ((D_801007B8 + 0x2AB) & 0x7F))) + 0x80)) * 0.0390625f)));
      }
      temp_s3 = arg1 << 6; temp_v1 = sRenderState + temp_s0_2;
      *((s16 *) (((char *) temp_v1) + 0x308)) = (s16) ((s32) ((*((f32 *) (((char *) arg0) + 0x60))) * 4.0f)); temp_s1 = arg1 * 2;
      *((s16 *) (((char *) temp_v1) + 0x30C)) = 0xFF;
      *((s16 *) (((char *) temp_v1) + 0x30E)) = 0;
      do
      {
        *((s16 *) (((char *) temp_v1) + 0x30A)) = (s16) ((s32) ((*((f32 *) (((char *) arg0) + 0x64))) * 4.0f));
 do { ((__repair_field_0 *) sDisplayListCursor)->value = 0xDC080008; *((void **) (((char *) sDisplayListCursor) + 4)) = (void *) (sRenderState + (((unsigned) (((s32) arg1) * 0x10)) + 0x300)); sDisplayListCursor += 8; func_800325E4(sRenderState + temp_s3, sRenderState + (temp_s1 + 0x360), *((f32 *) (((char *) arg0) + 0x84)), *((s32 *) (((char *) arg0) + 0x80)), 12.8f, gCullFarDistance * 64.0f, 1.0f); } while (0);
        temp_a1_2 = sRenderState + ((unsigned) temp_s0_2);
        *((s16 *) (inline_fn2(temp_a1_2) + 0x4F0)) = (s16) inline_fn(temp_fs3, (*((f32 *) (((char *) arg0) + 0x54))) - (*((f32 *) (((char *) arg0) + 0x50))));
        *((s16 *) (((char *) temp_a1_2) + 0x4F4)) = 0x2EF;
        *((s16 *) (((char *) temp_a1_2) + 0x4F2)) = (s16) ((s32) (2.0f * (temp_fs3 * ((*((f32 *) (((char *) arg0) + 0x5C))) - (*((f32 *) (((char *) arg0) + 0x58)))))));
        *((s16 *) (((char *) temp_a1_2) + 0x4F6)) = 0;
        if ((*((s32 *) (((char *) arg0) + 0x100))) & 8)
        {
          *((s16 *) (((char *) temp_a1_2) + 0x4F0)) = (s16) ((s32) (((f32) (*((s16 *) (((char *) temp_a1_2) + 0x4F0)))) + (((f32) ((*(D_800C43A0 + (D_801007B8 & 0x7F))) + 0x80)) * 0.078125f)));
          *((s16 *) (((char *) temp_a1_2) + 0x4F2)) = (s16) ((s32) (((f32) (*((s16 *) (((char *) temp_a1_2) + 0x4F2)))) + (((f32) ((*(D_800C43A0 + ((D_801007B8 + 0x2AB) & 0x7F))) + 0x80)) * 0.0390625f)));
        }
        temp_v1_2 = sRenderState + temp_s0_2;
        *((s16 *) (((char *) temp_v1_2) + 0x4F8)) = (s16) ((s32) ((*((f32 *) (((char *) arg0) + 0x60))) * 4.0f));
        *((s16 *) (((char *) temp_v1_2) + 0x4FC)) = 0xFF;
      }
      while (0);
      *((s16 *) (((char *) temp_v1_2) + 0x4FE)) = 0;
      *((s16 *) (((char *) temp_v1_2) + 0x4FA)) = (s16) ((s32) ((*((f32 *) (((char *) arg0) + 0x64))) * 4.0f));
      ((__repair_field_0 *) sDisplayListCursor)->value = 0xDC080008;
      *((void **) (((char *) sDisplayListCursor) + 4)) = (void *) (sRenderState + (temp_s0_2 + 0x4F0)); sDisplayListCursor += 8;
      func_800325E4(sRenderState + (temp_s3 + 0x370), sRenderState + (temp_s1 + 0x550), *((f32 *) (((char *) arg0) + 0x84)), *((s32 *) (((char *) arg0) + 0x80)), 12.8f, gCullFarDistance * 64.0f, 1.0f);
      temp_v1_3 = sRenderState + temp_s0_2;
      *((s16 *) (((char *) temp_v1_3) + 0x6E0)) = (s16) inline_fn(*((f32 *) (((char *) arg0) + 0x4C)), (*((f32 *) (((char *) arg0) + 0x54))) - (*((f32 *) (((char *) arg0) + 0x50))));
      *((s16 *) (((char *) temp_v1_3) + 0x6E4)) = 0xFF;
      *((s16 *) (((char *) temp_v1_3) + 0x6E6)) = 0;
      *((s16 *) (((char *) temp_v1_3) + 0x6E2)) = (s16) inline_fn(temp_fs3, (*((f32 *) (((char *) arg0) + 0x5C))) - (*((f32 *) (((char *) arg0) + 0x58))));
      *((s16 *) (((char *) temp_v1_3) + 0x6E8)) = (s16) ((s32) ((*((f32 *) (((char *) arg0) + 0x60))) * 4.0f));
      *((s16 *) (((char *) temp_v1_3) + 0x6EC)) = 0;
      *((s16 *) (((char *) temp_v1_3) + 0x6EE)) = 0;
      ((__repair_field_0 *) sDisplayListCursor)->value = 0xDC080008;
      *((s16 *) (((char *) temp_v1_3) + 0x6EA)) = (s16) ((s32) ((*((f32 *) (((char *) arg0) + 0x64))) * 4.0f)); sDisplayListCursor += 8;
      *((void **) (((char *) sDisplayListCursor) + 4)) = (void *) (sRenderState + ((((s32) arg1) * 0x10) + 0x6E0));
      func_800325E4(sRenderState + (temp_s3 + 0x560), sRenderState + (temp_s1 + 0x740), *((f32 *) (((char *) arg0) + 0x84)), *((s32 *) (((char *) arg0) + 0x80)), 0.64f, 64.0f, 1.0f);
      temp_v0 = sMatrixPoolUsed + 1;
      if (sMatrixPoolUsed < ((sMatrixPoolLimit - 1) + 1))
      {
        f32 yaw = (*((f32 *) (((char *) arg0) + 0x48))) + 3.1415927f;
        f32 pitch = -((*((f32 *) (((char *) arg0) + 0x44))) + 3.1415927f);
        s32 roll = *((s32 *) (((char *) arg0) + 0x40));
        sMatrixPoolUsed = temp_v0; sCurrentMatrixSlot = (temp_v0 << 6) + (*((s32 *) (((char *) sRenderState) + 0x74C)));
        func_8000BBB4(&sObjectMatrixF, yaw, pitch, roll);
        guTranslateF(&D_80109E28, (-(*((f32 *) (((char *) arg0) + 0x1C)))) * 64.0f, (-(*((f32 *) (((char *) arg0) + 0x20)))) * 64.0f, (-(*((f32 *) (((char *) arg0) + 0x24)))) * 64.0f);
        func_800A3840(&D_80109E28, &sObjectMatrixF, &sParentMatrixF);
        var_s0 = &sParentMatrixF; var_a1 = 0;
        do
        {
          var_a0 = 0; var_v1 = var_s0;
          loop_15:
          var_a0 += 1;

          *var_v1 *= 0.8f; var_v1 += 1;
          if (var_a0 < 4U)
          {
            goto loop_15;
          }
          ++var_a1;
          var_s0 += 4;
        }
        while (var_a1 < 4U);
        guMtxF2L(&sParentMatrixF, sRenderState + ((arg1 << 6) + 0x180));
        func_80014E30(arg0);
        if ((*((s32 *) (((char *) arg0) + 0x100))) & 3)
        {
          func_80014EB0(temp_s7, clipBounds.values);
          func_800156F4();
        }
        if ((*((s32 *) (((char *) arg0) + 0x100))) & 4)
        {
          func_80015BA8(arg0 + 0x10, temp_s7, clipBounds.values);
        }
        temp_s0_3 = arg0 + 0x88; D_800B35B0 += 1;
        func_80082C8C(temp_s0_3);
        func_80082CFC(temp_s0_3);
        func_800349B4(arg0);
        var_s0_2 = D_80107E9C;
        if (var_s0_2 != NULL)
        {
          do
          {
            updateObjectColor(var_s0_2);
            do
            {
              var_s0_2 = *((void **) (((char *) var_s0_2) + 0x1C));
            }
            while (0);
          }
          while (var_s0_2 != NULL);
        }
        {
          volatile s32 *renderSelector = &D_8010A4D8;
          func_80034928(arg0, *renderSelector);
          func_80036108(arg0);
          func_80034928(arg0, *renderSelector);
          func_800362B4(arg0);
          func_80034928(arg0, *renderSelector);
          func_800374BC(arg0);
          func_80034928(arg0, *renderSelector);
          func_80036BBC(arg0);
          func_80034928(arg0, *renderSelector);
          func_80036820(arg0);
          func_80034928(arg0, *renderSelector);
          renderObjectList(arg0);
          func_80034928(arg0, *renderSelector);
          func_800371E0(arg0);
          func_80034928(arg0, *renderSelector);
          func_80037A7C(arg0);
          func_80034928(arg0, *renderSelector);
          func_800369B8(arg0);
          func_80034928(arg0, *renderSelector);
          func_80037BDC(arg0);
          func_80034928(arg0, *renderSelector);
          func_800358D4(arg0);
          func_80034928(arg0, *renderSelector);
          func_800355BC(arg0);
        }
        func_80036B38(arg0);
        func_80037C84(arg0);
        func_80037DC0(arg0);
      }
    }
  }
  while (0);
}
