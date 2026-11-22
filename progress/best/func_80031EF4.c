#define paramSlot_unused 0
s32 actorLinkToSurface();
s32 func_80016EA4();
s32 func_8003C710();
s32 func_800464B8();
s32 func_80048794();
s32 func_80084048();
void *spawnEffectObject();
extern f64 D_800D2DE8;
extern f64 D_800D2DF0;
extern void * volatile gWobbleParams;
extern u8 D_8010A4C3;
extern s32 gBorderSkipActive;
extern s32 gHiResScreen;
extern s32 *gProbeObjectList;
extern u8 gTrackMarkerActiveMask;
extern u8 gSceneFlagsB;
typedef struct 
{
  u32 x;
  u32 y;
  u32 z;
} VecCopy;
inline static f32 *inline_fn(char *arg0)
{
  return (f32 *) arg0;
}

inline static s32 *inline_fn2(char *arg0)
{
  return (s32 *) arg0;
}

void *func_80031EF4(void *arg0, void *arg1, s16 arg2)
{
  volatile char pad;
  void * volatile sp24;
  f32 temp_fv0;
  f32 temp_fv0_2;
  f32 temp_fv0_3;
  f64 var_ft0;
  f64 var_fv1;
  s32 var_s0;
  s32 var_s2;
  void *temp_v0;
  if (gBorderSkipActive == 0)
  {
    void **paramSlot = &gWobbleParams;
 do { if ((*paramSlot) != NULL) { func_80084048(*paramSlot, 0xE); *paramSlot = NULL; } } while (0);
    temp_v0 = spawnEffectObject(8, 0, 0);
    if (temp_v0 != NULL)
    {
      sp24 = *((void **) (((char *) temp_v0) + 0x6C));
      func_80048794(1, gProbeObjectList);
      var_s0 = 0x3C;
      var_s2 = 0x5A;
      func_8003C710(*paramSlot);
      if (gHiResScreen != ((short) 0))
      {
        if (arg0)
        {
          var_s0 = 0x78;
          var_s2 = 0xB4;
        }
        else
        {
          var_s0 = 0x78;
          var_s2 = 0xB4;
        }
      }
      {
        unsigned int height = 0x78;
        volatile s32 width = 0xE6;
        func_8004844C(*paramSlot, (f32) ((f64) width), (f32) ((f64) ((u32) var_s0)), (f32) ((f64) height), (f32) ((f64) ((u32) var_s2)), 0.0f, 0.0f);
      }
      *inline_fn2(((char *) gWobbleParams) + 0x100) |= 0x100;
      *((VecCopy *) (((char *) gWobbleParams) + 0x10)) = *((VecCopy *) (((char *) arg0) + 0));
      {
        u8 a = D_8010A4C3;
        u8 b = gSceneFlagsB;
        u8 c = gTrackMarkerActiveMask;
        void *params = gWobbleParams;
        D_8010A4C3 = a | 2;
        gSceneFlagsB = b | 2;
        gTrackMarkerActiveMask = c | 2;
        *inline_fn2(((char *) params) + 0x100) &= ~7;
      }
      *inline_fn2(((char *) gWobbleParams) + 0x100) |= 2;
      if (arg1 != NULL)
      {
        func_800464B8((*paramSlot) + 0x34, *((s32 *) (((char *) arg1) + 0)), *inline_fn2(((char *) arg1) + 4), *inline_fn2(((char *) arg1) + 8));
        *((f32 *) (((char *) gWobbleParams) + 0x34)) = (f32) (-(*inline_fn(((char *) gWobbleParams) + 0x34)));
        *((f32 *) (((char *) gWobbleParams) + 0x3C)) = 3.1415927f;
      }
      func_80016EA4(0x1D);
      func_80016EA4(0x1E);
      func_80016EA4(7);
      *((s16 *) (((char *) temp_v0) + 0x78)) = arg2;
      *((VecCopy *) (((char *) temp_v0) + 0x30)) = *((VecCopy *) (((char *) arg0) + 0));
      *((VecCopy *) (((char *) temp_v0) + 0x24)) = *((VecCopy *) (((char *) temp_v0) + 48));
      temp_fv0 = (*((f32 *) (0x34 + ((char *) gWobbleParams)))) * 651.8986f;
      *((f32 *) (((char *) temp_v0) + 0x3C)) = temp_fv0;
      *((f32 *) (((char *) temp_v0) + 0x48)) = temp_fv0;
      temp_fv0_2 = (*((f32 *) (((char *) gWobbleParams) + 0x38))) * 651.8986f;
      *((f32 *) (((char *) temp_v0) + 0x40)) = temp_fv0_2;
      *((f32 *) (((char *) temp_v0) + 0x4C)) = temp_fv0_2;
      temp_fv0_3 = (*((f32 *) (((char *) gWobbleParams) + 0x3C))) * 651.8986f;
      *((s16 *) (((char *) temp_v0) + 0x7A)) = 0;
      *((f32 *) (((char *) temp_v0) + 0x44)) = temp_fv0_3;
      *((f32 *) (((char *) temp_v0) + 0x50)) = temp_fv0_3;
      *((s8 *) (((char *) sp24) + 2)) = 0x1E;
      actorLinkToSurface(*gProbeObjectList, temp_v0, 1);
      return temp_v0;
    }
    goto block_13;
  }
  block_13:
  return NULL;

}
