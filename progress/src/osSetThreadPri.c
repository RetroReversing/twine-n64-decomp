s32 __osEnqueueAndYield();
s32 __osEnqueueThread();
s32 __osDisableInt();
s32 __osRestoreInt();
s32 __osDequeueThread();
extern void *D_800CFE78;
extern void *__osRunningThread;
static inline s32 *inline_fn(int arg0)
{
  return (s32 *) (((char *) D_800CFE78) + arg0);
}

/* Sets a thread's priority (NULL = current thread), requeues it, and yields if a higher-priority thread is now ready. */
void osSetThreadPri(void *thread, s32 priority)
{
  int isNotRunning;
  s32 savedMask;
  thread = thread;
  savedMask = __osDisableInt();
  if (thread == NULL)
  {
    thread = __osRunningThread;
  }
  if ((*((s32 *) (((char *) thread) + 4))) != priority)
  {
    isNotRunning = thread != __osRunningThread;
    *((s32 *) (((char *) thread) + 4)) = priority;
    if (isNotRunning && ((*((u16 *) (((char *) thread) + 0x10))) != 1))
    {
      __osDequeueThread(*((s32 *) (((char *) thread) + 8)), thread);
      __osEnqueueThread(*((s32 *) (((char *) thread) + 8)), thread);
    }
    if ((*((s32 *) (((char *) __osRunningThread) + 4))) < (*inline_fn(4)))
    {
      *((s16 *) (((char *) __osRunningThread) + 0x10)) = 2;
      __osEnqueueAndYield(&D_800CFE78);
    }
  }
  __osRestoreInt(savedMask);
}
