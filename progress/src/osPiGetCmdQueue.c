/* identical to osPiGetCommandQueuePtr in V-RALLY-PAL (local match library) (matched), with its names changed by decompdecomp */
extern s32 D_800CFD80;
extern s32 D_800CFD88;

/* Returns the PI command queue, or NULL (0) if the PI manager has not been initialised. */ s32 osPiGetCmdQueue(void)
{
  s32 initialized;

  initialized = D_800CFD80;
  if (initialized == 0)
  {
    return 0;
  }
  return D_800CFD88;
}
