#define paramSlot_unused 0
s32 actorLinkToSurface();
s32 flagActorsWithState();
s32 resetSceneObjectState();
s32 directionToPitchYawRoll();
s32 registerTrackMarkerParent();
s32 freeHeapBlock();
void *spawnEffectObject();
extern f64 D_800D2DE8;
extern f64 D_800D2DF0;
extern void * volatile gWobbleParamsBlock;
extern u8 D_8010A4C3;
extern s32 gBorderSkipActive;
extern s32 gHiResScreen;
extern s32 *gDefaultOrderObj;
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

/* Spawns a wobble effect object at position, replacing any previous wobble sprite, optionally oriented by direction, and links it to the probe surface; returns the effect or NULL. */
void *spawnWobbleEffect(void *position, void *direction, s16 effectType)
{
  
  void *effectData;
  f32 temp_fv0;
  f32 temp_fv0_2;
  f32 temp_fv0_3;
  f64 var_ft0;
  f64 var_fv1;
  u32 var_s0;
  u32 var_s2;
  s32 width, height;
  void *effect;
  if (gBorderSkipActive == 0)
  {
    void * volatile *paramSlot = &gWobbleParamsBlock;
    void *previous = *paramSlot;
    if (previous != NULL) {
      freeHeapBlock(previous, 0xE);
      *paramSlot = NULL;
    }
    effect = spawnEffectObject(8, 0, 0);
    if (effect != NULL)
    {
      effectData = *((void **) (((char *) effect) + 0x6C));
      registerTrackMarkerParent(1, gDefaultOrderObj);
      var_s0 = 0x3C;
      var_s2 = 0x5A;
      width = 0xE6;
      height = 0x78;
      resetSceneObjectState(*paramSlot);
      if (gHiResScreen != 0)
      {
        var_s0 = 0x78;
        var_s2 = 0xB4;
      }
      {
        setViewportRect(*paramSlot, (f32) ((f64) width), (f32) ((f64) ((u32) var_s0)), (f32) ((f64) height), (f32) ((f64) ((u32) var_s2)), 0.0f, 0.0f);
      }
      *inline_fn2(((char *) gWobbleParamsBlock) + 0x100) |= 0x100;
      *((VecCopy *) (((char *) gWobbleParamsBlock) + 0x10)) = *((VecCopy *) (((char *) position) + 0));
      {
        u8 a = D_8010A4C3;
        u8 b = gSceneFlagsB;
        u8 c = gTrackMarkerActiveMask;
        void *params = gWobbleParamsBlock;
        D_8010A4C3 = a | 2;
        gSceneFlagsB = b | 2;
        gTrackMarkerActiveMask = c | 2;
        *inline_fn2(((char *) params) + 0x100) &= ~7;
      }
      *inline_fn2(((char *) gWobbleParamsBlock) + 0x100) |= 2;
      if (direction != NULL)
      {
        directionToPitchYawRoll((*paramSlot) + 0x34, *((s32 *) (((char *) direction) + 0)), *inline_fn2(((char *) direction) + 4), *inline_fn2(((char *) direction) + 8));
        {
          f32 *angle = inline_fn(((char *) gWobbleParamsBlock) + 0x34);
          *angle = -*angle;
        }
        *((f32 *) (((char *) gWobbleParamsBlock) + 0x3C)) = 3.1415927f;
      }
      flagActorsWithState(0x1D);
      flagActorsWithState(0x1E);
      flagActorsWithState(7);
      *((s16 *) (((char *) effect) + 0x78)) = effectType;
      *((VecCopy *) (((char *) effect) + 0x30)) = *((VecCopy *) (((char *) position) + 0));
      *((VecCopy *) (((char *) effect) + 0x24)) = *((VecCopy *) (((char *) effect) + 48));
      temp_fv0 = (*((f32 *) (0x34 + ((char *) gWobbleParamsBlock)))) * 651.8986f;
      *((f32 *) (((char *) effect) + 0x3C)) = temp_fv0;
      *((f32 *) (((char *) effect) + 0x48)) = temp_fv0;
      temp_fv0_2 = (*((f32 *) (((char *) gWobbleParamsBlock) + 0x38))) * 651.8986f;
      *((f32 *) (((char *) effect) + 0x40)) = temp_fv0_2;
      *((f32 *) (((char *) effect) + 0x4C)) = temp_fv0_2;
      temp_fv0_3 = (*((f32 *) (((char *) gWobbleParamsBlock) + 0x3C))) * 651.8986f;
      *((s16 *) (((char *) effect) + 0x7A)) = 0;
      *((f32 *) (((char *) effect) + 0x44)) = temp_fv0_3;
      *((f32 *) (((char *) effect) + 0x50)) = temp_fv0_3;
      *((s8 *) (((char *) effectData) + 2)) = 0x1E;
      actorLinkToSurface(*gDefaultOrderObj, effect, 1);
      return effect;
    }
    goto block_13;
  }
  block_13:
  return NULL;

}
