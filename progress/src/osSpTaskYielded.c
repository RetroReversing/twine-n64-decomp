/* identical to osSpTaskYielded in V-RALLY-PAL (local match library) (matched), with its names changed by decompdecomp */
u32 read_sp_status();

/* Reads the SP status register. If the task yielded (bit 0x80), copies the signal bit (bit 8)
 * into bit 0 of the task's flags at +4 and clears bit 1. Returns the signal bit. */
s32 osSpTaskYielded(void *task)
{
  s32 signal;
  u32 status;
  status = read_sp_status();
  signal = status >> 8;
  signal = signal & 1;
  if (status & 0x80)
  {
    *((s32 *) (((s8 *) task) + 4)) = (s32) (((*((s32 *) (((s8 *) task) + 4))) | signal) & (~2));
  }
  return signal;
}
