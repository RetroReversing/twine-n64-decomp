#include "common_local_source_25769805643.h"

/* identical to osViSetMode in V-RALLY-PAL (local match library) (matched), with its names changed by decompdecomp */
s32 func_8009F640();
s32 func_8009F6B0();
extern void *D_800D1154;

/* Makes `mode` the current VI mode: stores it in the VI context (+8), flags the context for update
 * (+0), and copies the mode's control word (mode+4) into the context at +0xC. Restores the interrupt state. */
void osViSetMode(void *mode)
{
  void *modePtr;
  void **modeSlot;
  char *ctx;
  s32 savedInt;
  void *temp_a1;
  savedInt = func_8009F640();
  ctx = (char *) D_800D1154;
  *((void **) (((char *) D_800D1154) + 8)) = mode;
  ;
  modeSlot = (void **) (((char *) D_800D1154) + 8);
  *((s16 *) (ctx + 0)) = 1;
  modePtr = *modeSlot;
  *((s32 *) (ctx + 0xC)) = (s32) (*((s32 *) (((char *) (*modeSlot)) + 4)));
  func_8009F6B0(savedInt, modePtr);
}
