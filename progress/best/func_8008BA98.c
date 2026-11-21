s32 func_8008B824(s32 *, s32, s32, s32);
unsigned int func_8008C08C();
s32 osAiSetFrequency(s32);
s32 osCreateMesgQueue(s32 *, s32 *, s32);
s32 osCreateThread(s32 *, s32, s32 *, s32, s32, s32);
s32 osSetEventMesg(s32, s32 *, s8 *);
s32 osStartThread(s32 *);
extern s32 D_800E3F90;
extern s32 D_800E4140;
extern s32 gWorkerMsgQueue;
extern s32 D_800E415C;
extern s8 D_800E416C;
extern s32 D_800E41D4;
extern s8 D_800E41D8;
extern s32 (*gDataBankAlloc)(s32, s32);
extern s8 D_8010086C;
extern s32 audioSilenceThread;
unsigned long long func_8008BA98(s32 *arg0, u16 arg1, u16 arg2, u32 arg3)
{
  s32 temp_v0;
  s32 temp_v0_2;
  s32 var_v0;
  s8 *message = &D_800E416C;
  D_800E41D8 = 0;
  func_8008C08C();
  D_8010086C = (arg3 >> 0x14) & 1;
  *message = 1;
  osCreateMesgQueue((s32 *) (((u32) (&D_800E41D4)) - 0x90), &D_800E415C, 4);
  osSetEventMesg(6, &gWorkerMsgQueue, message);
  temp_v0 = osAiSetFrequency(*arg0);
  D_800E41D4 = temp_v0;
  *arg0 = temp_v0;
  temp_v0_2 = gDataBankAlloc(0x400, 0x80);
  D_800E4140 = temp_v0_2;
  osCreateThread(&D_800E3F90, 0, &audioSilenceThread, 0, temp_v0_2 + 0x400, 0x7A);
  osStartThread((s32 *) (((u32) (&D_800E41D8)) - 0x248));
  var_v0 = 2;
  if (!(arg3 & 0x10000))
  {
    var_v0 = 3;
    if (!(arg3 & 0x20000))
    {
      var_v0 = 4;
      if (!(arg3 & 0x40000))
      {
        var_v0 = 0;
 do { if (!(arg3 & 0x80000)) { var_v0 = 1; } } while (0);
      }
    }
  }
  func_8008B824(arg0, arg1 & 0xFFFF, arg2 & 0xFFFF, var_v0);
  return 0;
}
