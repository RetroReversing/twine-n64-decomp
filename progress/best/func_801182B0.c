extern char D_800C471C[];
extern char D_800C7C16[];
inline static void *inline_fn(void *arg0, u16 arg1)
{
  return arg0 + (arg1 * 2);
}

int func_801182B0(void *arg0, void *arg1)
{
  char *__repair_addr;
  s32 var_condition_bit;
  s32 var_v0;
  s32 temp_a1_2;
  u16 temp_v1;
  u16 temp_v1_2;
  u8 temp_v1_3;
  void *temp_a1;
  if ((*((u8 *) (((char *) (*((void **) (((char *) arg0) + 0xB4)))) + 0x10))) == 7)
  {
    return 0;
  }
  temp_a1 = *((void **) (((char *) arg1) - -0x6C));
  temp_v1 = *((u16 *) (((char *) temp_a1) + 0x3C));
  if (temp_v1 == 2)
  {
    f32 limit;
    temp_v1_2 = *((u16 *) (((char *) temp_a1) + 0x3E));
    limit = ((f32) (*((s16 *) (D_800C7C16 + (temp_v1_2 * 4))))) * 0.5f;
    var_condition_bit = ((f32) (*((s16 *) (((char *) inline_fn(arg0, temp_v1_2)) + 0x1BC)))) < limit;
    goto compare;
  }
  else
    if (temp_v1 == 0)
  {
    f32 limit;
    temp_v1_3 = *((u8 *) (D_800C471C + ((*((u16 *) (((char *) temp_a1) + 0x3E))) * 0xE8)));
    limit = ((f32) (*((s16 *) (D_800C7C16 + (temp_v1_3 * 4))))) * 0.5f;
    var_condition_bit = ((f32) (*((s16 *) (((char *) (arg0 - (-(temp_v1_3 * 2)))) + 0x1BC)))) < limit;
    goto compare;
  }
  temp_a1_2 = *((u16 *) (((char *) temp_a1) + 0x3E));
  if (temp_a1_2 < 23)
  {
    return 0;
  }
  if (temp_a1_2 < 26)
  {
    return 1;
  }
  if (temp_a1_2 != 26)
  {
    return 0;
  }
  var_condition_bit = (*((f32 *) (((char *) arg0) + 0x60))) < 75.0f;
  compare:
  return (var_condition_bit) ? (1) : (0);

}

