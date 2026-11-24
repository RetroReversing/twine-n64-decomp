typedef struct 
{
  u16 rate;
  u16 lens[8];
  u8 vol[8];
  u8 count;
  u8 pan;
  u8 mode;
  u8 pad;
  s16 env[4];
} S891A8;
typedef struct 
{
  void *buf;
  s32 size;
  s16 count;
  s16 pan;
  s32 lens[8];
  s16 vol[10];
  s16 env[4];
} D891A8;
void func_800A0FA0(void *, s32);
void osWritebackDCache(void *, s32);
void workerLockAcquire(void);
void workerLockRelease(void);
extern u32 gAudioSampleRate;
extern void *gAudioStreamInfo;
extern s32 gAudioStreamOffset;
extern void *gAudioStreamBuffer;
extern void *(*gDataBankHandler)(s32, s32);
/* Builds a 0x48-byte audio stream descriptor from params (sample counts scaled to the output rate, 192-aligned) and publishes it as the current stream under the worker lock. */ void setupAudioStream(S891A8 *params)
{
  u32 rate;
  u32 size;
  s32 bytes;
  D891A8 *desc;
  u32 i;
  if (gAudioStreamBuffer != NULL)
  {
    u32 scaled = params->rate * gAudioSampleRate;
    rate = scaled / 1000;
    rate = ((rate / 192) * 192) + 192;
    desc = gDataBankHandler(0x48, 0);
    bytes = rate * 2;
    desc->buf = gAudioStreamBuffer;
    func_800A0FA0(gAudioStreamBuffer, bytes);
    osWritebackDCache(desc->buf, bytes);
    desc->size = rate;
    desc->pan = params->pan << 8;
    desc->count = params->count;
    for (i = 0; i < params->count; i++)
    {
      desc->lens[i] = (rate = (short) (((gAudioSampleRate * params->lens[i]) / 1000) + 3)) & 0xFFFC;
      desc->vol[i] = params->vol[i] << 8;
    }

    if (params->mode == 1)
    {
      for (i = 0; i < 4; i++)
      {
        desc->env[i] = params->env[i];
      }

    }
    else
    {
      desc->env[0] = 0;
      desc->env[1] = 0;
      desc->env[2] = 0;
      desc->env[3] = 0x7FFF;
    }
    osWritebackDCache(desc, 0x48);
    workerLockAcquire();
    gAudioStreamOffset = 0;
    gAudioStreamInfo = desc;
    workerLockRelease();
  }
}

