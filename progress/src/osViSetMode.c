/* identical to osViSetMode in V-RALLY-PAL (local match library) (matched), with its names changed by decompdecomp */
s32 __osDisableInt();
s32 __osRestoreInt();
extern void *gViCurrentContext;

/* Makes `mode` the current VI mode: stores it in the VI context (+8), flags the context for update
 * (+0), and copies the mode's control word (mode+4) into the context at +0xC. Restores the interrupt state. */
/* Makes `mode` the current VI mode: stores it in the VI context, flags the context for update, and copies the mode's control word into the context. Restores the interrupt state. */ void osViSetMode(void *mode)
{
  void *currentMode;
  void **modeField;
  char *viContext;
  s32 savedMask;
  void *temp_a1;
  savedMask = __osDisableInt();
  viContext = (char *) gViCurrentContext;
  *((void **) (((char *) gViCurrentContext) + 8)) = mode;
  ;
  modeField = (void **) (((char *) gViCurrentContext) + 8);
  *((s16 *) (viContext + 0)) = 1;
  currentMode = *modeField;
  *((s32 *) (viContext + 0xC)) = (s32) (*((s32 *) (((char *) (*modeField)) + 4)));
  __osRestoreInt(savedMask, currentMode);
}
