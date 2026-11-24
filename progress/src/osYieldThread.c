/* identical to osYieldThread in PENNY RACERS (local match library) (matched), with its names changed by decompdecomp */
/* identical to osYieldThread in V-RALLY-PAL (matched), with its names changed by decompdecomp */
/* identical to osYieldThread in V-RALLY (matched), with its names changed by decompdecomp */
/* identical to func_80095C90 in V-RALLY (matched), with its names changed by decompdecomp */

s32 __osEnqueueAndYield();
s32 __osDisableInt();
s32 __osRestoreInt();
extern char __osRunQueue[];
extern void *__osRunningThread;
static inline char *inline_fn()
{
  return ((char *) __osRunningThread) + 0x10;
}

/* Marks the running thread as runnable (state 2) and yields to the scheduler with interrupts disabled. */ void osYieldThread(void)
{
  int stateRunnable;
  s32 savedMask;
  savedMask = __osDisableInt();
  stateRunnable = 2;
  *((s16 *) inline_fn()) = stateRunnable;
  __osEnqueueAndYield(&__osRunQueue, 2);
  __osRestoreInt(savedMask);
}
