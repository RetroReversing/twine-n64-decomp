extern s32 D_8010A4D4;
extern void *sDisplayListCursor;
void func_80034630(const void *arg0, const void *arg1)
{
  f32 temp_ft0;
  f32 temp_ft0_2;
  f32 temp_ft1;
  f32 temp_ft2;
  f32 temp_ft5;
  f32 temp_fv0;
  f32 temp_fv1;
  f32 temp_fv1_a;
  f32 temp_b;
  f32 var_fa0;
  f32 var_fa1;
  f32 var_ft3;
  f32 var_ft4;
  void *temp_a1;
  void *temp_v0;
  temp_ft1 = *((f32 *) (((char *) arg1) + 0x64));
  temp_v0 = *((void **) (((char *) arg0) + 0x20));
  temp_ft0 = *((f32 *) (((char *) arg1) + 0x60));
  var_fa0 = (*((f32 *) (((char *) temp_v0) + 0))) + temp_ft0;
  var_ft3 = (*((f32 *) (((char *) temp_v0) + 8))) + temp_ft1;
  var_fa1 = (*((f32 *) (((char *) temp_v0) + 4))) + temp_ft0;
  var_ft4 = (*((f32 *) (((char *) temp_v0) + 0xC))) + temp_ft1;
  var_fa0 -= 8.0f;
  var_ft3 -= 8.0f;
  var_fa1 += 8.0f;
  var_ft4 += 8.0f;
  temp_ft2 = *((f32 *) (((char *) arg1) + 0x70));
  temp_ft5 = ((*((f32 *) (((char *) arg1) + 0x50))) + temp_ft0) + temp_ft2;
  temp_ft0_2 = *((f32 *) (((char *) arg1) + 0x74));
  temp_fv1_a = (*((f32 *) (((char *) arg1) + 0x58))) + temp_ft1;
  temp_fv1 = temp_fv1_a + temp_ft0_2;
  temp_b = ((*((f32 *) (((char *) arg1) + 0x54))) + temp_ft0) - temp_ft2;
  temp_fv0 = ((*((f32 *) (((char *) arg1) + 0x5C))) + temp_ft1) - temp_ft0_2;
  if (var_fa0 < temp_ft5)
  {
    var_fa0 = temp_ft5;
  }
  if (temp_b < var_fa1)
  {
    var_fa1 = temp_b;
  }
  if (var_ft3 < temp_fv1)
  {
    var_ft3 = temp_fv1;
  }
  if (temp_fv0 < var_ft4)
  {
    var_ft4 = temp_fv0;
  }
  if (D_8010A4D4 != 0)
  {
    temp_a1 = sDisplayListCursor;
    sDisplayListCursor = temp_a1 + 8;
    {
      u32 x = (((s32) (var_fa0 * 4.0f)) & 0xFFF) << 12;
      u32 y = ((s32) (var_ft3 * 4.0f)) & 0xFFF;
      *((u32 *) temp_a1) = (0xED000000 | x) | y;
    }
    *((s32 *) (((char *) temp_a1) + 4)) = (s32) (((((s32) (var_fa1 * 4.0f)) & 0xFFF) << 0xC) | (((s32) (var_ft4 * 4.0f)) & 0xFFF));
  }
}
