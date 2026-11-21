/* identical to osYieldThread in PENNY RACERS (local match library) (matched), with its names changed by decompdecomp */
/* identical to osYieldThread in V-RALLY-PAL (matched), with its names changed by decompdecomp */
/* identical to osYieldThread in V-RALLY (matched), with its names changed by decompdecomp */
/* identical to func_80095C90 in V-RALLY (matched), with its names changed by decompdecomp */

s32 __osEnqueueAndYield();
s32 __osDisableInt();
s32 __osRestoreInt();
extern char D_800CFE78[];
extern void *__osRunningThread;
static inline char *inline_fn()
{
  return ((char *) __osRunningThread) + 0x10;
}

void osYieldThread(void)
{
  int new_var;
  s32 temp_s0;
  temp_s0 = __osDisableInt();
  new_var = 2;
  *((s16 *) inline_fn()) = new_var;
  __osEnqueueAndYield(&D_800CFE78, 2);
  __osRestoreInt(temp_s0);
}
