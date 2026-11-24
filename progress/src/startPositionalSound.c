s32 workerLockAcquire();
s32 workerLockRelease();
s32 computeSourceAttenuation(s32 *, f32 *, f32 *, s32 *, s32 *, f32 *);
s32 soundVoiceStart(s32 *, f32, s32, s32, f32, f32);
s32 startSound(u16, s32, s32);
extern u8 gWorkerThreadActive;
extern s32 gOneShotEmitter;
extern s32 *gActiveEmitterList;
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

/* Fills in a sound emitter and either starts a one-shot voice now (no emitter given) or links the emitter into the active list. Returns the voice id or -1. */
s32 startPositionalSound(s32 *emitter, void *position, void *velocity, f32 refDistance, f32 pitch, s32 flags, u16 soundId, u16 emitterKey, u8 volume, u8 pan)
{
  f32 gain;
  f32 pitchScale;
  s32 leftVol;
  s32 rightVol;
  f32 reverb;
  s32 *slot;
  s32 voiceId;
  s32 key;
  s32 *oldHead;
  s32 oldFlags;
  if (gWorkerThreadActive)
  {
    key = emitterKey;
    key = inline_fn((u16) key);
    workerLockAcquire();
    slot = emitter;
    if (slot == NULL)
    {
      slot = &gOneShotEmitter;
    }
    *((s32 *) (((char *) slot) + 8)) = flags;
    *((V3_93FE8 *) (((char *) slot) + 0xC)) = *((V3_93FE8 *) position);
    *((V3_93FE8 *) (((char *) slot) + 0x18)) = *((V3_93FE8 *) velocity);
    *((f32 *) (((char *) slot) + 0x24)) = refDistance;
    *((u16 *) (((char *) slot) + 0x3C)) = soundId;
    *((f32 *) (((char *) slot) + 0x30)) = pitch;
    *((s32 *) (((char *) slot) + 0x38)) = key;
    *((f32 *) (((char *) slot) + 0x28)) = ((f32) volume) * 0.007874016f;
    *((f32 *) (((char *) slot) + 0x2C)) = ((f32) pan) * 0.007874016f;
    if (emitter == NULL)
    {
      computeSourceAttenuation(slot, &gain, &pitchScale, &leftVol, &rightVol, &reverb);
      if (gain != 0.0f)
      {
        voiceId = startSound(*((u16 *) (((char *) slot) + 0x3C)), 0x7F, 0x40);
        *((s32 *) (((char *) slot) + 0x34)) = voiceId;
        if (voiceId != (-1))
        {
          soundVoiceStart(slot, gain, leftVol, rightVol, reverb, pitchScale);
          workerLockRelease();
          return *((s32 *) (((char *) slot) + 0x34));
        }
      }
    }
    else
    {
      oldHead = gActiveEmitterList;
      *((s32 *) (((char *) slot) + 0)) = (s32) oldHead;
      if (oldHead != NULL)
      {
        *((s32 **) (((char *) oldHead) + 4)) = slot;
      }
      oldFlags = *((s32 *) (((char *) slot) + 8));
      *((s32 *) (((char *) slot) + 0x34)) = -1;
      *((s32 *) (((char *) slot) + 4)) = 0;
      gActiveEmitterList = slot;
      *((s16 *) (((char *) slot) + 0x3E)) = 0;
      *((s32 *) (((char *) slot) + 8)) = oldFlags | 0x30000;
    }
    workerLockRelease();
  }
  return -1;
}
