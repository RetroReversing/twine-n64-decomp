typedef struct 
{
  u8 pad0[0x24];
  s32 f24;
  u8 pad28[8];
  s32 f30;
  u8 pad34[0x50];
  s32 f84;
  s32 f88;
  u8 pad8C[0x28];
  s32 fB4;
} VoiceA804;
typedef struct 
{
  u32 w0;
  u16 h4;
  u8 b6;
  u8 b7;
} NoteA804;
void shiftLeft8InPlace(s32 *, NoteA804 *);
void scaleValueByOutputRate(s32 *, VoiceA804 *);
s32 shiftRightByte(s32);
u8 *getCurveTable(s32);
/* Starts a linear ramp of a voice parameter from startValue to a target computed from the note (optionally mapped through a 127-entry curve), with a per-tick step over the note's duration. */ s32 startVoiceParamRamp(VoiceA804 *voice, NoteA804 *note, s32 startValue)
{
  s32 ticks;
  u32 scaled;
  u32 target;
  u8 *curve;
  u32 index;
  u32 frac;
  u16 curveId;
  u8 *entry;
  u32 word0;
  s32 unused[4];
  voice->fB4 = note->h4;
  if (((*((u32 *) (&note->h4))) >> 8) & 1)
  {
    shiftLeft8InPlace(&voice->fB4, note);
  }
  else
  {
    scaleValueByOutputRate(&voice->fB4, voice);
  }
  ticks = shiftRightByte(voice->fB4);
  if (ticks == 0)
  {
    ticks = 1;
  }
  {
      u32 __repair_shifted_byte = ((u8 *) note)[1] << 16;
      scaled = ((u32) (voice->f30 * ((u8 *) note)[2])) >> 7;
      scaled += __repair_shifted_byte;
      if (__repair_shifted_byte & 1) word0 = note->w0;
      else word0 = note->w0;
  }
  if (scaled > 0x7F0000)
  {
    scaled = 0x7F0000;
  }
  if (note->h4)
  {
    curveId = (word0 >> 24) | (note->b7 << 8);
    target = scaled;
  }
  else
  {
    curveId = (word0 >> 24) | (note->b7 << 8);
    target = scaled;
  }
  if (curveId != 0)
  {
    curve = getCurveTable(curveId);
    if (curve != NULL)
    {
      index = scaled >> 16;
      frac = scaled & 0xFFFF;
      if (index < 0x7F)
      {
        entry = (void *) (index + ((s32) curve));
        {
          u32 d = (entry[1] - entry[0]) * frac;
          target = (entry[0] << 16) + d;
        }
      }
      else
      {
        target = curve[index] << 16;
      }
    }
  }
  scaled = target;
  voice->f88 = scaled;
  voice->f30 = startValue;
  voice->f24 |= 0x20000;
  voice->f84 = ((s32) (scaled - startValue)) / ticks;
  return 0;
}


