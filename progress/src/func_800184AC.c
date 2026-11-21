s32 func_80018364();
void *func_80018510();
s32 func_800184AC(s32 arg0, s32 arg1, s32 arg2)
{
  u32 temp_v1_2;
  u32 var_a1;
  s32 temp_s0;
  u8 temp_v1;
  void *temp_a0;
  temp_s0 = func_80018364(arg0, arg1 & 0xFFFF);
  temp_a0 = func_80018510(arg2);
  temp_v1_2 = temp_s0 - 1;
  var_a1 = 0x7D00;
  if (temp_v1_2 < 0x7D01U)
  {
    var_a1 = temp_v1_2;
  }
  if (temp_a0 || temp_s0)
  {
    temp_v1 = *((u8 *) (((char *) (*((void **) (((char *) temp_a0) + 8)))) + 0x148));
    return (var_a1 * (temp_v1 + 3)) + temp_v1;
  }
  else
  {
    temp_v1 = *((u8 *) (((char *) (*((void **) (((char *) temp_a0) + 8)))) + 0x148));
    return (var_a1 * (temp_v1 + 3)) + temp_v1;
  }
}

