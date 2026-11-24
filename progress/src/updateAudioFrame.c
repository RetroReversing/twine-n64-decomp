s32 UpdateSlotList();
s32 __osDisableInt();
s32 __osRestoreInt(s32);
s32 mixAudioBuffer(s32, s32);
s32 latchAudioVoiceTimes(u16 *);
s32 waitWorkerLock();
s32 signalWorkerLock();
s32 updateAudioTickStep();
s32 updateSequencePlayers();
s32 updateActiveVoices();
s32 osWritebackDCache(s16 *, s32, u16);
s32 osRecvMesg(s32 *, s32, s32);
s32 osYieldThread();
s32 updateVoiceRingBuffers();
extern s32 D_800AC1E0;
extern s32 D_800AD570;
extern s32 D_800D1B30;
extern s32 D_800E3F50;
extern s32 D_800E3F54;
extern s32 *D_800E3F58;
extern s32 D_800E3F5C;
extern s32 *D_800E3F60;
extern s32 D_800E3F64;
extern s32 *D_800E3F68;
extern s32 D_800E3F6C;
extern s16 *D_800E3F80;
extern s32 D_800E3F84;
extern s32 D_800E41E8;
extern s32 D_800E41EC;
extern s32 D_800E41F8;
extern s16 *gAudioFrameBuffers;
extern u16 *gAudioFrameIndexPtr;
extern s32 D_800E4228;
extern u16 sAudioReadIndex;
extern s32 (*gGraphicsConfig)(s32 *);
extern s32 (*gWorkerFlushCallback)(s16 *, u8);
extern s32 (*D_80100174)(s32, u16, s32 *);
extern s32 D_80109BA0;
extern s32 D_80109BF8;
extern s32 D_8010D378;
extern s32 (*D_8010D428)();
extern s32 D_8010D42C;
extern s32 (*dmaHandlerInit)(s32);
extern s32 func_800AC110;
extern u16 gAudioBufferCount;
extern volatile u8 gAudioBufferIndex;
extern s32 gAudioBufferPtrs;
extern u8 gSoundWorkerActive;
extern s32 sMixBufferA;
extern u16 sMixBufferUnits;
extern void *sSlotActiveList;
extern s32 sSlotLog;
extern u16 sSlotLogCount;
extern u8 sVoiceAllocCursor;
extern u16 sWorkerAckCounter;
extern u8 sWorkerBusy;
extern u8 sWorkerPendingCallback;
typedef struct { s16 first; } MixHead;
inline static s32 inline_fn2()
{
  return (s32) (&func_800AC110);
}

inline static u16 inline_fn23(u32 arg0)
{
  return (u16) arg0;
}

/* Per-frame audio update: mixes pending audio buffers, builds and submits the RSP audio task. */
void updateAudioFrame(void)
{
  s16 *nextBuf;
  s16 *cmdBuf;
  s16 *mixBuf;
  s32 savedInt;
  s32 mixOffset;
  s32 unitsMixed;
  s32 nextCursor;
  s32 prevOffset;
  u16 *countPtr;
  u16 taskCount;
  u16 targetIndex;
  u16 oldValue;
  u32 bufferIndex;
  u32 targetWide;
  u32 pendingCallback;
  u32 startIndex;
  void *slot;
  if (D_8010D428 != NULL)
  {
    D_8010D428();
  }
  waitWorkerLock();
  savedInt = __osDisableInt();
  targetIndex = ((gAudioBufferIndex == 0) ? (gAudioBufferCount) : (gAudioBufferIndex)) - 1;
  __osRestoreInt(savedInt);
  if (gSoundWorkerActive != 0)
  {
    UpdateSlotList();
  }
  if (sAudioReadIndex != 0xFFFF)
  {
    if (sWorkerBusy != 0)
    {
      osRecvMesg(&D_800E41F8, 0, 1);
      sWorkerBusy = 0;
      osYieldThread();
    }
    {
      sSlotLogCount = 0; D_80109BA0 = sSlotLog & (~0xF); D_80109BF8 = sSlotLog;
      if (dmaHandlerInit != NULL)
      {
        ((void (*)(void)) dmaHandlerInit)();
      }
      slot = sSlotActiveList;
      if (slot != NULL)
      {
        do
        {
          oldValue = *((u16 *) (((char *) slot) + 0x10));
          if (oldValue != 0)
          {
            *((u16 *) (((char *) slot) + 0x10)) = inline_fn23(oldValue - 1);
          }
          slot = *((void **) (((char *) slot) + 0));
        }
        while (slot != NULL);
      }
      {
        u32 cursor = sVoiceAllocCursor;
        countPtr = &((u16 *) (&D_800E4228))[cursor]; cmdBuf = ((s16 **) (&sMixBufferA))[cursor];
      }
      gAudioFrameIndexPtr = countPtr; gAudioFrameBuffers = cmdBuf; mixBuf = cmdBuf + 8; D_8010D378 = ((s32) mixBuf) & (~0xF); D_8010D42C = (s32) mixBuf;
      *countPtr = 0; targetWide = targetIndex & 0xFFFF;
      ((MixHead *) gAudioFrameBuffers)->first = 0;
      if (sAudioReadIndex != targetWide)
      {
        if (gSoundWorkerActive)
        {
          latchAudioVoiceTimes(countPtr);
          mixOffset = 0;
          unitsMixed = 0;
          startIndex = sAudioReadIndex;
        }
        else
        {
          latchAudioVoiceTimes(countPtr);
          mixOffset = 0;
          unitsMixed = 0;
          startIndex = sAudioReadIndex;
        }
        if (startIndex < targetWide)
        {
          unsigned short limit = targetWide;
          bufferIndex = startIndex;
          {
            do
            {
              s32 *buffers = &gAudioBufferPtrs;
              u32 index; u32 tmpi;
              if (inline_fn23(unitsMixed) >= sMixBufferUnits)
              {
                break;
              }
              tmpi = bufferIndex++; index = tmpi;
              if ((gSoundWorkerActive != 0) && ((--D_800E41E8) == 0))
              {
                D_800E41E8 = D_800E41EC;
                updateSequencePlayers();
                updateAudioTickStep();
              }
              mixAudioBuffer(buffers[inline_fn23(index)], inline_fn23(mixOffset));
              mixOffset += 0xC0;
              ++unitsMixed;
            }
            while (inline_fn23(bufferIndex) < limit);
          }
        }
        else
        {
          bufferIndex = sAudioReadIndex;
          {
            if (bufferIndex < gAudioBufferCount)
            {
              s32 *buffers = &gAudioBufferPtrs;
              do
              {
                u32 index; u32 tmpi;
                if (inline_fn23(unitsMixed) >= sMixBufferUnits)
                {
                  break;
                }
                tmpi = bufferIndex++; index = tmpi;
                if ((gSoundWorkerActive != 0) && (--D_800E41E8 == 0))
                {
                  D_800E41E8 = D_800E41EC;
                  updateSequencePlayers();
                  updateAudioTickStep();
                }
                prevOffset = (u16) mixOffset; mixOffset += 0xC0;
                mixAudioBuffer(buffers[inline_fn23(index)], prevOffset);
                ++unitsMixed;
              }
              while (inline_fn23(bufferIndex) < gAudioBufferCount);
            }
            bufferIndex = 0;
            if (((u16) targetIndex) != 0)
            {
              s32 *buffers = &gAudioBufferPtrs;
              u32 limit = (u16) targetIndex;
              do
              {
                u32 index; u32 tmpi;
                if (((u16) unitsMixed) >= sMixBufferUnits)
                {
                  break;
                }
                tmpi = bufferIndex++; index = tmpi;
                if ((gSoundWorkerActive != 0) && (--D_800E41E8 == 0))
                {
                  D_800E41E8 = D_800E41EC;
                  updateSequencePlayers();
                  updateAudioTickStep();
                }
                mixAudioBuffer(buffers[(u16) index], inline_fn23(mixOffset));
                mixOffset += 0xC0;
                ++unitsMixed;
              }
              while (inline_fn23(bufferIndex) < limit);
            }
          }
        }
        if (sSlotLogCount != 0)
        {
          sWorkerBusy = 1;
          D_80100174(sSlotLog, sSlotLogCount, &D_800E41F8);
        }
        sAudioReadIndex = bufferIndex; sWorkerAckCounter -= unitsMixed;
      }
      updateActiveVoices();
      do { nextCursor = sVoiceAllocCursor ^ 1; pendingCallback = sWorkerPendingCallback; } while (0);
    }
    {
      u16 *count = &((u16 *) (&D_800E4228))[nextCursor];
      nextBuf = ((s16 **) (&sMixBufferA))[nextCursor];
      gAudioFrameIndexPtr = count;
    }
    gAudioFrameBuffers = nextBuf;
    if (pendingCallback != 0)
    {
      gWorkerFlushCallback(nextBuf, pendingCallback);
      osYieldThread();
      sWorkerPendingCallback = 0;
    }
    taskCount = *gAudioFrameIndexPtr;
    nextBuf = gAudioFrameBuffers;
    if (taskCount != 0)
    {
      s32 *task = &D_800E3F50;
      *task = 2;
      D_800E3F5C = ((s32) (&D_800AC1E0)) - inline_fn2();
      D_800E3F60 = &D_800AD570;
      D_800E3F64 = 0x1000;
      D_800E3F68 = &D_800D1B30;
      D_800E3F54 = 0;
      D_800E3F58 = &func_800AC110;
      D_800E3F6C = 0x800;
      D_800E3F80 = nextBuf;
      D_800E3F84 = (s32) taskCount;
      osWritebackDCache(nextBuf, taskCount * 0xA10, taskCount);
      gGraphicsConfig(task);
      sWorkerPendingCallback = 1;
    }
    sVoiceAllocCursor ^= 1;
    if (gSoundWorkerActive != 0)
    {
      updateVoiceRingBuffers();
    }
  }
  else
  {
    sAudioReadIndex = targetIndex;
  }
  signalWorkerLock();
  return;
}
