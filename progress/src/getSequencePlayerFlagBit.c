extern s32 D_80107EDC;
extern s32 D_80107EE0;
extern s32 D_80107EE8;
/* Returns the top bit of a 40-byte-stride player entry's first word, or 0 if the entry's state is 4 or its pointer is null. */ u32 getSequencePlayerFlagBit(s32 playerIndex)
{
  s32 state = playerIndex & 0xff;
  s32 byteOffset = (state * 5) << 3;
  u32 dataPtr;
  u32 flags;
  state = *((u8 *) (((s8 *) (&D_80107EE8)) + byteOffset));
  dataPtr = 4;
  if (state == dataPtr)
  {
    goto __shared_return_0;
  }
  dataPtr = *((u32 *) (((s8 *) (&D_80107EE0)) + byteOffset));
  if (dataPtr == 0)
  {
    __shared_return_0:
    return 0;

  }
  if (dataPtr + dataPtr == 2)
  {
    flags = *((u32 *) (((s8 *) (&D_80107EDC)) + byteOffset));
    return flags >> 31;
  }
  else
  {
    flags = *((u32 *) (((s8 *) (&D_80107EDC)) + byteOffset));
    return flags >> 31;
  }
}

