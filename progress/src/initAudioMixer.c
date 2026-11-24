void audioInitVoices(u16, u32);
void audioSetupRateBuffer(u16, u32, u8);
extern const char sMixerVersionString[];
extern f64 D_800D6798;
extern s32 D_800E41E8;
extern s32 D_800E41EC;
extern s32 gAudioStreamInfo;
extern s32 gAudioStreamBuffer;
extern s32 gAudioStreamBufferSize;
extern u16 sAudioReadIndex;
extern s32 (*D_8010016C)(s32 *);
extern s32 gAudioUpdateRate;
extern s32 gWorkerBuffer;
extern s8 D_8010309C;
extern volatile char D_8010309D;
extern u8 gMixerVersionCopy[];
extern s32 D_8010D428;
extern s32 dmaHandlerInit;
extern s32 updateAudioFrame;
extern s32 (*gDataBankHandler)(s32, s32, s32);
extern s8 sWorkerPendingCallback;
inline static u32 *inline_fn(u32 *arg0)
{
  return arg0;
}

/* Initializes the audio mixer: voices, rate buffer, optional stream buffer, frame timing and the mixer version string copy. */
void initAudioMixer(u32 *sampleRatePtr, s32 maxVoices, s32 streamBufferMs, s32 rateBufferMode)
{
  f32 temp_fv1;
  f64 var_ft0;
  s32 streamSamples;
  s32 temp_a2_2;
  s32 temp_s0;
  s32 temp_v0;
  s32 __repair_temp_v0_1;
  s32 var_a1;
  s32 i;
  u32 rate;
  s32 first;
  s32 voiceCount;
  s32 var_v0;
  s32 var_v0_2;
  s32 framesPerTick;
  voiceCount = maxVoices;
  if (((u32) (voiceCount & 0xFFFF)) >= 0x21U)
  {
    voiceCount = 0x20;
  }
  sWorkerPendingCallback = 0;
  temp_s0 = voiceCount & 0xFFFF;
  audioInitVoices(temp_s0, *inline_fn(sampleRatePtr));
  var_a1 = (u16) temp_s0;
  audioSetupRateBuffer(var_a1, *sampleRatePtr, rateBufferMode & 0xFF);
  temp_v0 = *sampleRatePtr;
  streamSamples = streamBufferMs & 0xFFFF;
  if (streamSamples != 0)
  {
    {s32 n; u32 s; u32 p; 
    streamSamples = ((u32) temp_v0 * streamSamples) / 1000;
    gAudioStreamInfo = 0;
    temp_v0 = (u32) streamSamples / 192;
    var_v0 = temp_v0 * 192;
    temp_v0 = (s32) gDataBankHandler;
    s = var_v0 + 192;
    gAudioStreamBufferSize = s;
    gAudioStreamBuffer = ((s32 (*)(s32, s32, s32)) temp_v0)(s * 2, 0, s);
    }
  }
  else
  {
    gAudioStreamBuffer = 0;
  }
  sAudioReadIndex = 0xFFFF;
  dmaHandlerInit = 0;
  D_8010D428 = 0;
  D_8010016C(&updateAudioFrame);
  __repair_temp_v0_1 = *sampleRatePtr;
  var_ft0 = (f64) __repair_temp_v0_1;
  if (__repair_temp_v0_1 < 0)
  {
    var_ft0 += D_800D6798;
  }
  temp_fv1 = ((((f32) var_ft0) * 0.016666668f) * 0.0052083335f) + 0.5f;
  framesPerTick = (u32) temp_fv1;
  var_v0 = framesPerTick * 2;
  D_800E41EC = framesPerTick;
  D_800E41E8 = framesPerTick;
  gAudioUpdateRate = (var_v0 + framesPerTick) << 6;
  rate = *sampleRatePtr;
  first = sMixerVersionString[0];
  D_8010309D = 0x10;
  D_8010309C = 1;
  gWorkerBuffer = rate;
  /*__repair_loop_weight*/do { i = 0; } while (0);
  if (first != 0) {
    do {
      if (gAudioStreamBuffer) {
        gMixerVersionCopy[i & 0xFF] = (u8) sMixerVersionString[i & 0xFF];
        i += 1;
      } else {
        gMixerVersionCopy[i & 0xFF] = (u8) sMixerVersionString[i & 0xFF];
        i += 1;
      }
    } while (sMixerVersionString[i & 0xFF] != 0);
  }
  gMixerVersionCopy[i & 0xFF] = 0;
}
