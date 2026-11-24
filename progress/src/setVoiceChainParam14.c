void func_80095A80(u8, u8, u8, u8);
s32 func_800989B8(void);
extern char D_8010D734[];
extern char D_8010D748[];
extern char D_8010D784[];
extern unsigned char D_8010D76F[];
extern unsigned char D_8010D779[];
/* Writes a 14-bit value as high/low 7-bit parameters to every voice in a handle chain; returns -1 if the handle is stale or missing. */ s32 setVoiceChainParam14(s32 arg0, s32 value)
{
  s32 status = -1;
  s32 voiceHandle;
  s32 idx;
  s32 t;
  voiceHandle = func_800989B8();
  if (voiceHandle != -1)
  {
    while (voiceHandle != -1) {
    idx = voiceHandle & 0xff;
    arg0 = idx * 0x1a0;
    if ((*((s32 *) (D_8010D784 + arg0))) != voiceHandle)
    {
      return status;
    }
    if ((*((s32 *) (D_8010D748 + arg0))) & 2)
    {
      func_80095A80(0x84, idx, D_8010D779[arg0], ((u32)(value & 0xffff)) >> 7);
      func_80095A80(0x85, idx, D_8010D779[arg0], value & 0x7f);
    }
    else
    {
      func_80095A80(0x84, idx, D_8010D76F[arg0], ((u32)(value & 0xffff)) >> 7);
      func_80095A80(0x85, idx, D_8010D76F[arg0], value & 0x7f);
    }
    t = idx * 0x1a0;
    voiceHandle = *((s32 *) (D_8010D734 + t));
    status = 0;
    }
  }
  return status;
}
