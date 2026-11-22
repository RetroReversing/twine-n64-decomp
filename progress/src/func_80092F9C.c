extern u8 gWorkerThreadActive;
extern s16 sSceneGroupStackCount;
extern char *sSceneGroupStack[];
void workerLockAcquire(void);
void workerLockRelease(void);
s32 func_8008F520();
s32 func_80092F9C(u16 id, u16 sub, s32 arg2, s32 arg3, u8 flag)
{
  s32 i;
  s32 result;
  char *p;
  char *a;
  char *b;
  char *c;
  u16 n;
  if (gWorkerThreadActive)
  {
    {
      for (i = 0; i < sSceneGroupStackCount; i++)
      {
        p = *((char **) (((char *) sSceneGroupStack) + (i << 2)));
        if ((*((u16 *) (p + 4))) == id)
        {
          if (*((u16 *) (p + 6)))
          {
            return -1;
          }
          c = p + ((*((s32 *) (p + 0x24))) + 8);
          n = *((u16 *) c);
          a = p + ((*((s32 *) (p + 0x1c))) + 8);
          b = p + ((*((s32 *) (p + 0x20))) + 8);
          while (n != 0xffff)
          {
            if (n == sub)
            {
if (flag) { result = func_8008F520(a, b, c, arg2, arg3); } else { workerLockAcquire(); result = func_8008F520(a, b, c, arg2, arg3); workerLockRelease(); } return result;
            }
            c += 0x84;
            n = *((u16 *) c);
          }

          return -1;
        }
      }

    }
  }
  return -1;
}
