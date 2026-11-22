s32 UpdateSlotList();
s32 __osDisableInt();
s32 __osRestoreInt(s32);
s32 func_8008AECC(s32, s32);
s32 func_8008B1C0(u16 *);
s32 func_8008C160();
s32 func_8008C188();
s32 func_8008E374();
s32 func_800923D0();
s32 func_80093410();
s32 func_800A0220(s16 *, s32, u16);
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
extern s16 *D_800E4218;
extern u16 *D_800E421C;
extern s32 D_800E4228;
extern u16 D_800E4268;
extern s32 (*D_80100164)(s32 *);
extern s32 (*D_80100168)(s16 *, u8);
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
extern u8 gWorkerActive;
extern s32 sMixBufferA;
extern u16 sMixBufferUnits;
extern void *sSlotActiveList;
extern s32 sSlotLog;
extern u16 sSlotLogCount;
extern u8 sVoiceAllocCursor;
extern u16 sWorkerAckCounter;
extern u8 sWorkerBusy;
extern u8 sWorkerPendingCallback;
inline static int inline_fn(u8 arg0, int arg1)
{
  return (arg0 != 0) && ((--D_800E41E8) == arg1);
}

inline static s32 inline_fn2()
{
  return (s32) (&func_800AC110);
}

inline static u16 inline_fn23(u32 arg0)
{
  return (u16) arg0;
}

void func_8008B25C(void)
{
  s16 *temp_a0_3;
  s16 *temp_v1;
  s16 *temp_v1_2;
  s32 temp_a0;
  s32 temp_a1;
  s32 temp_a1_2;
  s32 temp_a1_3;
  s32 temp_v0_3;
  s32 temp_v0_5;
  s32 temp_v0_7;
  s32 temp_v0_8;
  s32 var_s1;
  s32 var_s3;
  s32 var_v0_2;
  s32 var_v0_4;
  s32 var_v0_5;
  u16 *temp_a0_2;
  u16 temp_a2;
  u16 temp_s4;
  u16 temp_v0;
  u16 temp_v0_2;
  u16 temp_v0_4;
  u16 temp_v0_6;
  u32 var_s0;
  u32 var_s0_2;
  u16 var_v0;
  u32 temp_s2;
  u32 var_v0_3;
  void *var_v1;
  if (D_8010D428 != NULL)
  {
    do
    {
      D_8010D428();
    }
    while (0);
  }
  func_8008C160();
  temp_a0 = __osDisableInt();
  temp_s4 = ((gAudioBufferIndex == 0) ? (gAudioBufferCount) : (gAudioBufferIndex)) - 1;
  __osRestoreInt(temp_a0);
  if (gWorkerActive != 0)
  {
    UpdateSlotList();
  }
  if (D_800E4268 != 0xFFFF)
  {
    if (sWorkerBusy != 0)
    {
      osRecvMesg(&D_800E41F8, 0, 1);
      sWorkerBusy = 0;
      osYieldThread();
    }
    do
    {
      sSlotLogCount = 0; D_80109BA0 = sSlotLog & (~0xF); D_80109BF8 = sSlotLog;
      if (dmaHandlerInit != NULL)
      {
        ((void (*)(void)) dmaHandlerInit)();
      }
      var_v1 = sSlotActiveList;
      if (var_v1 != NULL)
      {
        do
        {
          temp_v0 = *((u16 *) (((char *) var_v1) + 0x10));
          if (temp_v0 != 0)
          {
            *((u16 *) (((char *) var_v1) + 0x10)) = inline_fn23(temp_v0 - 1);
          }
          var_v1 = *((void **) (((char *) var_v1) + 0));
        }
        while (var_v1 != NULL);
      }
      {
        u32 cursor = sVoiceAllocCursor;
        temp_a0_2 = &((u16 *) (&D_800E4228))[cursor]; temp_v1 = ((s16 **) (&sMixBufferA))[cursor];
      }
      D_800E421C = temp_a0_2; D_800E4218 = temp_v1; temp_v1_2 = temp_v1 + 8; D_8010D378 = ((s32) temp_v1_2) & (~0xF); D_8010D42C = (s32) temp_v1_2;
      *temp_a0_2 = 0; temp_s2 = temp_s4 & 0xFFFF;
      *D_800E4218 = 0;
      if (D_800E4268 != temp_s2)
      {
        if (var_s0)
        {
          var_s1 = 0;
          func_8008B1C0(temp_a0_2);
          var_s3 = 0;
          var_v0_3 = D_800E4268;
        }
        else
        {
          var_s1 = 0;
          func_8008B1C0(temp_a0_2);
          var_s3 = 0;
          var_v0_3 = D_800E4268;
        }
        if (var_v0_3 < temp_s2)
        {
          unsigned short limit = temp_s2;
          do
          {
            var_s0 = var_v0_3;
            do
            {
              s32 *buffers = &gAudioBufferPtrs;
              u32 index;
              if (inline_fn23(var_s3) >= sMixBufferUnits)
              {
                break;
              }
              index = var_s0++;
              if ((gWorkerActive != 0) && ((--D_800E41E8) == 0))
              {
                D_800E41E8 = D_800E41EC;
                func_800923D0();
                func_8008E374();
              }
              temp_a1 = inline_fn23(var_s1);
              var_s1 += 0xC0;
              ++var_s3;
              func_8008AECC(buffers[inline_fn23(index)], temp_a1);
            }
            while (inline_fn23(var_s0) < limit);
          }
          while (0);
        }
        else
        {
          var_s0 = D_800E4268;
          do
          {
            if (var_s0 < gAudioBufferCount)
            {
              s32 *buffers = &gAudioBufferPtrs;
              do
              {
                u32 index;
                if (inline_fn23(var_s3) >= sMixBufferUnits)
                {
                  break;
                }
                index = var_s0++;
                if ((gWorkerActive != 0) && (--D_800E41E8 == 0))
                {
                  D_800E41E8 = D_800E41EC;
                  func_800923D0();
                  func_8008E374();
                }
                temp_a1 = (u16) var_s1; var_s1 += 0xC0;
                func_8008AECC(buffers[inline_fn23(index)], temp_a1);
                ++var_s3;
              }
              while (inline_fn23(var_s0) < gAudioBufferCount);
            }
            if (temp_s4 || D_8010D428)
            {
              var_s0 = 0;
            }
            else
            {
              var_s0 = 0;
            }
            if (((u16) temp_s4) != 0)
            {
              s32 *buffers = &gAudioBufferPtrs;
              u32 limit = (u16) temp_s4;
              do
              {
                u32 index;
                if (((u16) var_s3) >= sMixBufferUnits)
                {
                  break;
                }
                index = var_s0++;
                if (inline_fn(gWorkerActive, 0))
                {
                  D_800E41E8 = D_800E41EC;
                  func_800923D0();
                  func_8008E374();
                }
                temp_a1 = inline_fn23(var_s1);
                var_s1 += 0xC0;
                ++var_s3;
                func_8008AECC(buffers[(u16) index], temp_a1);
              }
              while (inline_fn23(var_s0) < limit);
            }
          }
          while (0);
        }
        if (sSlotLogCount != 0)
        {
          sWorkerBusy = 1;
          D_80100174(sSlotLog, sSlotLogCount, &D_800E41F8);
        }
        D_800E4268 = var_s0; sWorkerAckCounter -= var_s3;
      }
      func_80093410();
      temp_v0_8 = sVoiceAllocCursor ^ 1;
    }
    while (0);
    {
      u16 *count = &((u16 *) (&D_800E4228))[temp_v0_8];
      temp_a0_3 = ((s16 **) (&sMixBufferA))[temp_v0_8];
      D_800E421C = count;
    }
    D_800E4218 = temp_a0_3;
    if (sWorkerPendingCallback != 0)
    {
      D_80100168(temp_a0_3, sWorkerPendingCallback);
      osYieldThread();
      sWorkerPendingCallback = 0;
    }
    temp_a2 = *D_800E421C;
    temp_a0_3 = D_800E4218;
    if (temp_a2 != 0)
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
      D_800E3F80 = temp_a0_3;
      D_800E3F84 = (s32) temp_a2;
      func_800A0220(temp_a0_3, temp_a2 * 0xA10, temp_a2);
      D_80100164(task);
      sWorkerPendingCallback = 1;
    }
    sVoiceAllocCursor ^= 1;
    if (gWorkerActive != 0)
    {
      updateVoiceRingBuffers();
    }
  }
  else
  {
    D_800E4268 = temp_s4;
  }
  func_8008C188();
}

