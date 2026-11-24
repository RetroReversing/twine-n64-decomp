/* adapted from similar verified C in setVoiceChainParam14 in TWINE (matched), with its names changed by decompdecomp */
void func_80095A80(u8, u8, u8, u8);
s32 func_800989B8(void);
extern char D_8010D734[];
extern char D_8010D748[];
extern char D_8010D784[];
extern unsigned char D_8010D76F[];
extern unsigned char D_8010D779[];
/* Walks a chain of linked voices and stores a 14-bit value on each as two 7-bit halves (high then low). Returns 0 if any voice was updated, -1 otherwise. */ s32 setVoiceChainParam14Alt(s32 byteOffset, s32 value)
{
  s32 status = -1;
  s32 voiceHandle;
  s32 voiceIndex;
  s32 nextOffset;
  voiceHandle = func_800989B8();
  if (voiceHandle != -1)
  {
    while (voiceHandle != -1) {
    voiceIndex = voiceHandle & 0xff;
    byteOffset = voiceIndex * 0x1a0;
    if ((*((s32 *) (D_8010D784 + byteOffset))) != voiceHandle)
    {
      return status;
    }
    if ((*((s32 *) (D_8010D748 + byteOffset))) & 2)
    {
      func_80095A80(128, voiceIndex, D_8010D779[byteOffset], ((u32)(value & 0xffff)) >> 7);
      func_80095A80(129, voiceIndex, D_8010D779[byteOffset], value & 0x7f);
    }
    else
    {
      func_80095A80(128, voiceIndex, D_8010D76F[byteOffset], ((u32)(value & 0xffff)) >> 7);
      func_80095A80(129, voiceIndex, D_8010D76F[byteOffset], value & 0x7f);
    }
    nextOffset = voiceIndex * 0x1a0;
    voiceHandle = *((s32 *) (D_8010D734 + nextOffset));
    status = 0;
    }
  }
  return status;
}
