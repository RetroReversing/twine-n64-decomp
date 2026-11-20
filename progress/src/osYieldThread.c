/* identical to osYieldThread in PENNY RACERS (local match library) (matched), with its names changed by decompdecomp */
/* identical to osYieldThread in V-RALLY-PAL (matched), with its names changed by decompdecomp */
/* identical to osYieldThread in V-RALLY (matched), with its names changed by decompdecomp */
/* identical to func_80095C90 in V-RALLY (matched), with its names changed by decompdecomp */

s32 func_800A783C();
s32 func_8009F640();
s32 func_8009F6B0();
extern char D_800CFE78[];
extern void *D_800CFE80;
static inline char *inline_fn()
{
  return ((char *) D_800CFE80) + 0x10;
}

void osYieldThread(void)
{
  int new_var;
  s32 temp_s0;
  temp_s0 = func_8009F640();
  new_var = 2;
  *((s16 *) inline_fn()) = new_var;
  func_800A783C(&D_800CFE78, 2);
  func_8009F6B0(temp_s0);
}
