extern char D_800C471C[];
extern char gStatThresholdTable[];
inline static void *inline_fn(void *arg0, u16 arg1)
{
  return arg0 + (arg1 * 2);
}

/* Returns 1 if the stat selected by the action is below its threshold (half the table value, or 75 for action 26). */
int isStatBelowThreshold(void *owner, void *action)
{
  char *__repair_addr;

  s32 var_v0;
  s32 actionId;
  u16 actionKind;
  u16 statIndex;
  u8 tableStatIndex;
  void *actionData;
  if ((*((u8 *) (((char *) (*((void **) (((char *) owner) + 0xB4)))) + 0x10))) == 7)
  {
    return 0;
  }
  actionData = *((void **) (((char *) action) - -0x6C));
  actionKind = *((u16 *) (((char *) actionData) + 0x3C));
  if (actionKind == 2)
  {
    f32 limit;
    statIndex = *((u16 *) (((char *) actionData) + 0x3E));
    limit = ((f32) (*((s16 *) (gStatThresholdTable + (statIndex * 4))))) * 0.5f;
    if (((f32) (*((s16 *) (((char *) inline_fn(owner, statIndex)) + 0x1BC)))) < limit) goto __repair_fp_yes; else goto __repair_fp_no;
  }
  else
    if (actionKind == 0)
  {
    f32 limit;
    tableStatIndex = *((u8 *) (D_800C471C + ((*((u16 *) (((char *) actionData) + 0x3E))) * 0xE8)));
    limit = ((f32) (*((s16 *) (gStatThresholdTable + (tableStatIndex * 4))))) * 0.5f;
    if (((f32) (*((s16 *) (((char *) (owner - (-(tableStatIndex * 2)))) + 0x1BC)))) < limit) goto __repair_fp_yes; else goto __repair_fp_no;
  }
  actionId = *((u16 *) (((char *) actionData) + 0x3E));
  if (actionId < 23)
  {
    return 0;
  }
  if (actionId < 26)
  {
    return 1;
  }
  if (actionId != 26)
  {
    return 0;
  }
    if ((*((f32 *) (((char *) owner) + 0x60))) < 75.0f) goto __repair_fp_yes; else goto __repair_fp_no;

__repair_fp_no: return 0;
__repair_fp_yes: return 1;
}
