/* identical to osSetThreadPri in PENNY RACERS (local match library) (matched), with its names changed by decompdecomp */
/* adapted from similar verified C in osSetThreadPri in V-RALLY-PAL (matched), with its names changed by decompdecomp */
s32 __osEnqueueAndYield();
s32 func_800A7944();
s32 __osDisableInt();
s32 __osRestoreInt();
s32 __osDequeueThread();
extern void *D_800CFE78;
extern void *__osRunningThread;
static inline s32 *inline_fn(int arg0)
{
  return (s32 *) (((char *) D_800CFE78) + arg0);
}

void osSetThreadPri(void *arg0, s32 arg1)
{
  int new_var;
  s32 temp_s2;
  arg0 = arg0;
  temp_s2 = __osDisableInt();
  if (arg0 == NULL)
  {
    arg0 = __osRunningThread;
  }
  if ((*((s32 *) (((char *) arg0) + 4))) != arg1)
  {
    new_var = arg0 != __osRunningThread;
    *((s32 *) (((char *) arg0) + 4)) = arg1;
    if (new_var && ((*((u16 *) (((char *) arg0) + 0x10))) != 1))
    {
      __osDequeueThread(*((s32 *) (((char *) arg0) + 8)), arg0);
      func_800A7944(*((s32 *) (((char *) arg0) + 8)), arg0);
    }
    if ((*((s32 *) (((char *) __osRunningThread) + 4))) < (*inline_fn(4)))
    {
      *((s16 *) (((char *) __osRunningThread) + 0x10)) = 2;
      __osEnqueueAndYield(&D_800CFE78);
    }
  }
  __osRestoreInt(temp_s2);
}
