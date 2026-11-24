extern s32 gSemitoneRatioTable;
inline static s16 inline_fn(int arg0)
{
  return (s16) arg0;
}

inline static u16 inline_fn2(u16 arg0)
{
  return arg0;
}

/* Computes the voice's pitch key (semitones) and cents fine-tune from the ratio of its
 * base frequency to the target frequency, using the semitone ratio table. */
s32 computeVoicePitchKey(void *voice, u32 *freqWord)
{
  s32 *__base_D_800CFD60;
  s32 *__base_b;
  u16 *var_v1_4;
  s32 temp_v1_2;
  s32 semitone;
  u16 *var_v1_2;
  s32 semitoneDown;
  s32 __repair_phase_temp_v1;
  u16 temp_a1_2;
  u16 temp_a1_3;
  u32 temp_a0;
  u32 targetFreq;
  u32 temp_a2;
  u32 ratio;
  u32 temp_lo_2;
  u32 temp_lo_3;
  u32 baseFreq;
  u32 octaves;
  u32 octavesDown;
  u32 var_v1;
  u32 __repair_phase_var_v1_3;
  __repair_phase_var_v1_3 = *((u32 *) (((char *) voice) + 0x5C));
  targetFreq = (((u32) (*freqWord)) >> 8) & 0xFFFF;
  baseFreq = __repair_phase_var_v1_3 & 0xFFFFFF;
  if (baseFreq == targetFreq)
  {
    *((s16 *) (((char *) voice) + 0x50)) = inline_fn(__repair_phase_var_v1_3 >> 0x18);
    *((s8 *) (((char *) voice) + 0xC0)) = 0;
  }
  else
    if (baseFreq < targetFreq)
  {
    s32 temp_v1_arm;
    ratio = ((u32) (targetFreq << 0xC)) / baseFreq;
    octaves = 0;
    do
    {
      u32 next = octaves + 1;
      if (((ratio >> 12) >> next) == 0)
      {
        break;
      }
      octaves = next;
    }
    while ((targetFreq = octaves) < 11);
    semitone = 0xB;
    __base_D_800CFD60 = &gSemitoneRatioTable;
    temp_lo_2 = ratio / ((u32) (1 << octaves));
    var_v1_2 = (u16 *) (((s8 *) __base_D_800CFD60) + 0x16); var_v1_4 = (u16 *) (((s8 *) __base_D_800CFD60) + 0x16);
    do {
    loop_9:
    if (((u16) (*var_v1_2)) >= temp_lo_2)
    {
      var_v1_2--;
      semitone = semitone - 1;
      goto loop_9;
    }
    } while (0);

    *((s16 *) (((char *) voice) + 0x50)) = (s16) (((*((u8 *) (((char *) voice) + 0x5C))) + (octaves * 0xC)) + semitone);
    temp_v1_arm = semitone * 2; temp_a1_2 = *((u16 *) (temp_v1_arm + ((int) __base_D_800CFD60)));
    *((s8 *) (((char *) voice) + 0xC0)) = (s8) (((u32) ((temp_lo_2 - temp_a1_2) * 0x64)) / ((u32) ((*((u16 *) ((((char *) __base_D_800CFD60) - (-temp_v1_arm)) + 2))) - temp_a1_2)));
  }
  else
  {
    baseFreq = ((u32) (baseFreq << 0xC)) / targetFreq; octavesDown = 0;
    do
    {
      u32 next = octavesDown + 1;
      if (((baseFreq >> 12) >> next) == 0)
      {
        break;
      }
      octavesDown = next;
    }
    while (octavesDown < 11);
    semitoneDown = 0xB; __base_b = &gSemitoneRatioTable; var_v1_4 = (u16 *) (((s8 *) __base_b) + 0x16); baseFreq = baseFreq / ((u32) (1 << octavesDown));
    do {
    loop_16:
    if (((u16) inline_fn2(*var_v1_4)) >= baseFreq)
    {
      var_v1_4--;
      semitoneDown -= 1;
      goto loop_16;
    }
    } while (0);

    *((s16 *) (((char *) voice) + 0x50)) = (s16) (((*((u8 *) (((char *) voice) + 0x5C))) - (octavesDown * 0xC)) - semitoneDown);
    temp_v1_2 = semitoneDown * 2; temp_a1_3 = *((u16 *) (temp_v1_2 + ((int) __base_b)));
    *((s8 *) (((char *) voice) + 0xC0)) = (s8) (-((s8) (((u32) ((baseFreq - temp_a1_3) * 0x64)) / ((u32) ((*((u16 *) ((((char *) __base_b) - (-temp_v1_2)) + 2))) - temp_a1_3)))));
  }
  *((s32 *) (((char *) voice) + 0x24)) = (s32) ((*((s32 *) (((char *) voice) + 0x24))) | 0x100);
  return 0;
}
