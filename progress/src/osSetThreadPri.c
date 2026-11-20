/* identical to osSetThreadPri in PENNY RACERS (local match library) (matched), with its names changed by decompdecomp */
/* adapted from similar verified C in osSetThreadPri in V-RALLY-PAL (matched), with its names changed by decompdecomp */
s32 func_800A783C();
s32 func_800A7944();
s32 func_8009F640();
s32 func_8009F6B0();
s32 __osDequeueThread();
extern void *D_800CFE78;
extern void *D_800CFE80;
static inline s32 *inline_fn(int arg0)
{
  return (s32 *) (((char *) D_800CFE78) + arg0);
}

void osSetThreadPri(void *arg0, s32 arg1)
{
  int new_var;
  s32 temp_s2;
  arg0 = arg0;
  temp_s2 = func_8009F640();
  if (arg0 == NULL)
  {
    arg0 = D_800CFE80;
  }
  if ((*((s32 *) (((char *) arg0) + 4))) != arg1)
  {
    new_var = arg0 != D_800CFE80;
    *((s32 *) (((char *) arg0) + 4)) = arg1;
    if (new_var && ((*((u16 *) (((char *) arg0) + 0x10))) != 1))
    {
      __osDequeueThread(*((s32 *) (((char *) arg0) + 8)), arg0);
      func_800A7944(*((s32 *) (((char *) arg0) + 8)), arg0);
    }
    if ((*((s32 *) (((char *) D_800CFE80) + 4))) < (*inline_fn(4)))
    {
      *((s16 *) (((char *) D_800CFE80) + 0x10)) = 2;
      func_800A783C(&D_800CFE78);
    }
  }
  func_8009F6B0(temp_s2);
}
