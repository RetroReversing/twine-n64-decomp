/* identical to osSpTaskYielded in V-RALLY-PAL (local match library) (matched), with its names changed by decompdecomp */
u32 readSpStatus();

/* Reads the SP status register. If the task yielded (bit 0x80), copies the signal bit (bit 8)
 * into bit 0 of the task's flags at +4 and clears bit 1. Returns the signal bit. */
/* Reads the SP status register. If the task yielded (bit 0x80), copies the signal bit (bit 8) into bit 0 of the task's flags at +4 and clears bit 1. Returns the signal bit. */ s32 osSpTaskYielded(void *task)
{
  s32 signalBit;
  u32 spStatus;
  spStatus = readSpStatus();
  signalBit = spStatus >> 8;
  signalBit = signalBit & 1;
  if (spStatus & 0x80)
  {
    *((s32 *) (((s8 *) task) + 4)) = (s32) (((*((s32 *) (((s8 *) task) + 4))) | signalBit) & (~2));
  }
  return signalBit;
}
