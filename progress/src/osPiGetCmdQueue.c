extern s32 gPiManagerInitialized;
extern s32 gPiCmdQueue;

/* Returns the PI command queue, or NULL (0) if the PI manager has not been initialised. */ s32 osPiGetCmdQueue(void)
{
  s32 initialized;

  initialized = gPiManagerInitialized;
  if (initialized == 0)
  {
    return 0;
  }
  return gPiCmdQueue;
}
