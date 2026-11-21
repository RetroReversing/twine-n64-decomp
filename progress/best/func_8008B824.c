void audioInitVoices(u16, u32);
void audioSetupRateBuffer(u16, u32, u8);
extern const char D_800D6780[];
extern f64 D_800D6798;
extern s32 D_800E41E8;
extern s32 D_800E41EC;
extern s32 D_800E4230;
extern s32 D_800E4238;
extern s32 D_800E423C;
extern u16 D_800E4268;
extern s32 (*D_8010016C)(s32 *);
extern s32 D_801002D8;
extern s32 D_80103098;
extern s8 D_8010309C;
extern s8 D_8010309D;
extern u8 D_8010319E[];
extern s32 D_8010D428;
extern s32 dmaHandlerInit;
extern s32 func_8008B25C;
extern s32 (*gDataBankAlloc)(s32, s32, s32);
extern s8 sWorkerPendingCallback;
inline static u32 *inline_fn(u32 *arg0)
{
  return arg0;
}

void func_8008B824(u32 *arg0, s32 arg1, s32 arg2, s32 arg3)
{
  f32 temp_fv1;
  f64 var_ft0;
  s32 temp_a2;
  s32 temp_a2_2;
  s32 temp_s0;
  s32 temp_v0;
  s32 __repair_temp_v0_1;
  s32 var_a1;
  u32 rate;
  s32 first;
  s32 var_s0;
  s32 var_v0;
  s32 var_v0_2;
  s32 var_v1;
  var_s0 = arg1;
  if (((u32) (var_s0 & 0xFFFF)) >= 0x21U)
  {
    var_s0 = 0x20;
  }
  sWorkerPendingCallback = 0;
  temp_s0 = var_s0 & 0xFFFF;
  audioInitVoices(temp_s0, *inline_fn(arg0));
  var_a1 = (u16) temp_s0;
  audioSetupRateBuffer(var_a1, *arg0, arg3 & 0xFF);
  temp_v0 = *arg0;
  temp_a2 = arg2 & 0xFFFF;
  if (temp_a2 != 0)
  {
    temp_a2_2 = (((((((u32) temp_v0) * temp_a2) / 1000) >> 6) / 3) * 0xC0) + 0xC0;
    D_800E4230 = 0;
    D_800E423C = temp_a2_2;
    D_800E4238 = gDataBankAlloc(temp_a2_2 * 2, 0, temp_a2_2);
  }
  else
  {
    D_800E4238 = 0;
  }
  D_800E4268 = 0xFFFF;
  dmaHandlerInit = 0;
  D_8010D428 = 0;
  D_8010016C(&func_8008B25C);
  __repair_temp_v0_1 = *arg0;
  var_ft0 = (f64) __repair_temp_v0_1;
  if (__repair_temp_v0_1 < 0)
  {
    var_ft0 += D_800D6798;
  }
  temp_fv1 = ((((f32) var_ft0) * 0.016666668f) * 0.0052083335f) + 0.5f;
  var_v1 = (u32) temp_fv1;
  var_v0 = var_v1 * 2;
  D_800E41EC = var_v1;
  D_800E41E8 = var_v1;
  D_801002D8 = (var_v0 + var_v1) << 6;
  rate = *arg0;
  first = D_800D6780[0];
  D_8010309D = 0x10;
  D_8010309C = 1;
  D_80103098 = rate;
  var_a1 = 0;
  if (first != 0)
  {
    var_v0_2 = var_a1 & 0xFF;
    do
    {
      if (var_v1)
      {
        var_a1 += 1;
        D_8010319E[var_v0_2] = (u8) D_800D6780[var_v0_2];
        var_v0_2 = var_a1 & 0xFF;
      }
      else
      {
        var_a1 += 1;
        D_8010319E[var_v0_2] = (u8) D_800D6780[var_v0_2];
        var_v0_2 = var_a1 & 0xFF;
      }
    }
    while (D_800D6780[var_a1 & 0xFF] != 0);
  }
  D_8010319E[var_a1 & 0xFF] = 0;
}

