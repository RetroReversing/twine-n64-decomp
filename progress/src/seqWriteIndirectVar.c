s32 storeMidiControllerValue(s32, u8, u8, s32);
inline static int inline_fn(s32 arg0, int arg1)
{
  return arg0 & arg1;
}

/* Clamps value to 0..0x3FFF and, for non-reserved variable ids, writes it to the channel's MIDI controller. */
void seqWriteIndirectVar(void *channel, s32 varId, s32 value)
{
  s16 clampedValue;
  s32 varIdByte;
  s32 temp_v1;
  s32 mappedId;
  u8 targetIndex;
  {
    s32 original = value;
    s32 narrowed;
    if (mappedId)
    {
      value = (s32) (((u32) value) << 16);
      narrowed = value >> 16;
    }
    else
    {
      value = (s32) (((u32) value) << 16);
      narrowed = value >> 16;
    }
    if (narrowed >= 0)
    {
      value = original;
      if (narrowed >= 0x4000)
      {
        value = 0x3FFF;
      }
    }
    else
    {
      value = 0;
    }
    clampedValue = value;
  }
  varIdByte = inline_fn(varId, 0xFF);
  mappedId = varId;
  switch (varIdByte)
  {
    case 0x80:
      mappedId = 0x80;
      break;

    case 0x81:
      mappedId = 0x82;
      break;

    case 0x82:
      mappedId = 0xA0;
      break;

    case 0x83:
      mappedId = 0xA1;
      break;

    case 0x84:
      mappedId = 0x83;
      break;

    case 0x85:
      mappedId = 0x84;
      break;

  }

  if ((inline_fn((int) mappedId, 0xFF) >= 0xA2) || ((temp_v1 = mappedId & 0xFF) < 0xA0))
  {
    targetIndex = *((u8 *) (((char *) channel) + 0x4A));
    if (targetIndex != 0xFF)
    {
      storeMidiControllerValue(varId & 0xFF, targetIndex, *((u8 *) (((char *) channel) + 0x4B)), inline_fn(clampedValue, 0xFFFF));
    }
  }
}
