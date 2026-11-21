s32 workerLockAcquire();
s32 workerLockRelease();
s32 computeSourceAttenuation(s32 *, f32 *, f32 *, s32 *, s32 *, f32 *);
s32 soundVoiceStart(s32 *, f32, s32, s32, f32, f32);
s32 func_8009CC3C(u16, s32, s32);
extern u8 gWorkerThreadActive;
extern s32 gStaticSoundSlot;
extern s32 *gActiveSoundList;
typedef struct 
{
  s32 x;
  s32 y;
  s32 z;
} V3_93FE8;
inline static u16 inline_fn(u16 arg0)
{
  return arg0;
}

s32 func_800941F8(s32 *arg0, void *arg1, void *arg2, f32 arg3, f32 arg4, s32 arg5, u16 arg6, u16 argK, u8 arg7, u8 arg8)
{
  f32 sp18;
  f32 sp1C;
  s32 sp20;
  s32 sp24;
  f32 sp28;
  s32 *var_s0;
  s32 temp_v0;
  s32 key;
  s32 *head;
  s32 fl;
  if (gWorkerThreadActive)
  {
    key = argK;
    key = inline_fn((u16) key);
    workerLockAcquire();
    var_s0 = arg0;
    if (var_s0 == NULL)
    {
      var_s0 = &gStaticSoundSlot;
    }
    *((s32 *) (((char *) var_s0) + 8)) = arg5;
    *((V3_93FE8 *) (((char *) var_s0) + 0xC)) = *((V3_93FE8 *) arg1);
    *((V3_93FE8 *) (((char *) var_s0) + 0x18)) = *((V3_93FE8 *) arg2);
    *((f32 *) (((char *) var_s0) + 0x24)) = arg3;
    *((u16 *) (((char *) var_s0) + 0x3C)) = arg6;
    *((f32 *) (((char *) var_s0) + 0x30)) = arg4;
    *((s32 *) (((char *) var_s0) + 0x38)) = key;
    *((f32 *) (((char *) var_s0) + 0x28)) = ((f32) arg7) * 0.007874016f;
    *((f32 *) (((char *) var_s0) + 0x2C)) = ((f32) arg8) * 0.007874016f;
    if (arg0 == NULL)
    {
      computeSourceAttenuation(var_s0, &sp18, &sp1C, &sp20, &sp24, &sp28);
      if (sp18 != 0.0f)
      {
        temp_v0 = func_8009CC3C(*((u16 *) (((char *) var_s0) + 0x3C)), 0x7F, 0x40);
        *((s32 *) (((char *) var_s0) + 0x34)) = temp_v0;
        if (temp_v0 != (-1))
        {
          soundVoiceStart(var_s0, sp18, sp20, sp24, sp28, sp1C);
          workerLockRelease();
          return *((s32 *) (((char *) var_s0) + 0x34));
        }
      }
    }
    else
    {
      head = gActiveSoundList;
      *((s32 *) (((char *) var_s0) + 0)) = (s32) head;
      if (head != NULL)
      {
        *((s32 **) (((char *) head) + 4)) = var_s0;
      }
      fl = *((s32 *) (((char *) var_s0) + 8));
      *((s32 *) (((char *) var_s0) + 0x34)) = -1;
      *((s32 *) (((char *) var_s0) + 4)) = 0;
      gActiveSoundList = var_s0;
      *((s16 *) (((char *) var_s0) + 0x3E)) = 0;
      *((s32 *) (((char *) var_s0) + 8)) = fl | 0x30000;
    }
    workerLockRelease();
  }
  return -1;
}

