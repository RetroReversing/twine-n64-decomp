typedef struct 
{
  u32 offsetAndFlags;
} AudioFile;
typedef struct 
{
  u8 state[0x11DE];
  u8 volume;
  u8 pad11DF;
  u32 queue[6];
  void *messages[2];
  u8 active;
  u8 arg3;
  u8 arg4;
  u8 arg5;
  u8 arg2;
  u32 rate;
  s32 handle;
  void *buffer;
  u32 length;
  u8 pad1218;
  u8 arg6;
  u8 pad121A[14];
} AudioSlot;
extern s32 assignDataBankSerial(s32);
extern s32 offsetToDoubledIndex(void);
extern void initAudioStreamState(void *, u32, void *, u32, void (*)(void));
extern void func_800A0170(void *, s32);
extern void osCreateMesgQueue(void *, void **, s32);
extern s32 osRecvMesg(void *, void **, s32);
extern s32 osSendMesg(void *, void *, s32);
extern void requestDmaAndNotify(void);
extern unsigned char D_800CEEC0;
extern AudioSlot D_800E1AC0[];
extern u8 D_800E2CC0[];
extern u32 D_800E3F18;
extern AudioFile *D_800E3F1C;
extern u32 D_800E3F20;
extern void *D_800E3F24[];
extern u32 D_800E3F2C;
extern u32 D_800E3F30[6];
extern void *(*D_8010017C)(s32, s32);
extern u8 D_8010086C;
/* Starts streaming an audio file into a free audio slot (max 2), setting up its message queue, sample rate and buffer; returns the handle or -1 on failure. */ s32 startAudioStream(u32 fileIndex, u32 rate, s32 arg2, u8 arg3, u8 arg4, u8 arg5, u8 arg6)
{
  s32 slotIndex;
  s32 slotByteOffset;
  u32 saved3 = arg3;
  u32 saved2 = arg2;
  AudioSlot *slot;
  u32 length;
  s32 allocationSize;
  void *buffer;
  if (D_800CEEC0 && (fileIndex < (*((s32 *) (&D_800E3F20)))))
  {
    for (slotIndex = 0, slotByteOffset = 0; slotIndex < 2; slotByteOffset += sizeof(AudioSlot))
    {
      if (!D_800E2CC0[slotByteOffset])
      {
        break;
      }
      slotIndex++;
    }

    if (slotIndex != 2)
    {
      slot = &D_800E1AC0[slotIndex];
      osCreateMesgQueue(slot->queue, slot->messages, 2);
      if (rate == 0)
      {
        rate = (!(*((u8 *) (&D_800E3F1C[fileIndex])))) ? (8000) : (16000);
      }
      slot->arg2 = arg2;
      slot->arg3 = arg3;
      slot->arg4 = arg4;
      slot->arg5 = arg5;
      slot->arg6 = arg6;
      slot->rate = rate;
      length = (((rate * 8) / 30) + 159) / 160; length = (length * 5) << 5; slot->length = length;
      if ((*((s32 *) (&D_800E3F2C))) & 1)
      {
        slot->buffer = D_800E3F24[slotIndex];
      }
      else
      {
        allocationSize = offsetToDoubledIndex();
        buffer = D_8010017C(allocationSize, 0);
        slot->buffer = buffer;
        func_800A0170(buffer, allocationSize);
      }
      if (slot->buffer != NULL)
      {
        osRecvMesg(D_800E3F30, NULL, 1);
        initAudioStreamState(slot, (D_800E3F1C[fileIndex].offsetAndFlags & 0xFFFFFF) + (*((s32 *) (&D_800E3F18))), slot->buffer, slot->length, requestDmaAndNotify);
        if (D_8010086C)
        {
          if (arg4)
          {
            slot->volume *= 2;
          }
          else
          {
            slot->volume *= 2;
          }
        }
        slot->handle = -1;
        *((volatile u8 *) (&slot->active)) = 1;
        osSendMesg(&D_800E3F24[3], NULL, 0);
        return assignDataBankSerial(slotIndex);
      }
    }
  }
  return -1;
}

