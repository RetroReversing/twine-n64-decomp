extern f64 D_800D3E48;
inline static char *inline_fn(void *arg0)
{
  return (char *) arg0;
}

s32 Ray_TriangleIntersect(void *arg0, void *arg1, void *arg2, void *arg3, void *arg4, f32 *arg5)
{
  f64 inv;
  f32 sp0[3];
  f32 sp10[3];
  f32 sp20[3];
  f32 sp30[3];
  f32 sp40[3];
  f32 temp_fa0;
  f32 temp_fa0_2;
  f32 temp_fa1;
  f32 temp_fa1_2;
  f32 temp_t2;
  f32 temp_fs2;
  f32 temp_fs3;
  f32 temp_ft2;
  f32 temp_ft0;
  f32 temp_ft1;
  f32 temp_fv1;
  f32 temp_ft2_2;
  f32 temp_ft3;
  f32 temp_ft3_2;
  s32 var_v0;
  f32 temp_ft4_2;
  f32 temp_fv1_2;
  f32 temp_fv0;
  f32 temp_ft5;
  f32 temp_fs1;
  f32 temp_t3;
  register f32 temp_ft4;
  s32 var_v0_2;
  register s32 var_v0_3;
  f32 temp_fs5;
  s32 var_v1;
  s32 var_v1_2;
  temp_fs3 = (*((f32 *) (((char *) arg3) + 0))) - (*((f32 *) (inline_fn(arg2) + 0)));
  sp0[0] = temp_fs3;
  temp_fs1 = (*((f32 *) (((char *) arg3) + 4))) - (*((f32 *) (((char *) arg2) + 4)));
  sp0[1] = temp_fs1;
  temp_ft5 = (*((f32 *) (((char *) arg3) + 8))) - (*((f32 *) (((char *) arg2) + 8)));
  sp0[2] = temp_ft5;
  temp_fv1 = (*((f32 *) (((char *) arg4) + 0))) - (*((f32 *) (((char *) arg2) + 0)));
  sp10[0] = temp_fv1;
  temp_fv1_2 = (*((f32 *) (((char *) arg4) + 4))) - (*((f32 *) (((char *) arg2) + 4)));
  sp10[1] = temp_fv1_2;
  temp_fs5 = *((const volatile f32 *) (((char *) arg1) + 8));
  temp_fs2 = (*((f32 *) (((char *) arg4) + 8))) - (*((f32 *) (((char *) arg2) + 8)));
  temp_t3 = *((f32 *) (((char *) arg1) + 4));
  temp_t2 = *((f32 *) (((char *) arg1) + 0));
  temp_fa1 = (temp_t3 * temp_fs2) - (temp_fs5 * temp_fv1_2);
  temp_ft2 = (temp_fs5 * temp_fv1) - (temp_t2 * temp_fs2);
  temp_ft4 = (temp_t2 * temp_fv1_2) - (temp_t3 * temp_fv1);
  var_v0_2 = 1;
  temp_ft0 = ((temp_fs3 * temp_fa1) + (temp_fs1 * temp_ft2)) + (temp_ft5 * temp_ft4);
  sp10[2] = temp_fs2;
  sp30[0] = temp_fa1;
  sp30[1] = temp_ft2;
  sp30[2] = temp_ft4;
  if (!(temp_ft0 > (-1e-10f)))
  {
    var_v0_2 = 0;
  }
  var_v1 = 1;
  if (!(temp_ft0 < 1e-10f))
  {
 do { var_v1 = 0; } while (0);
  }
  if (var_v0_2 & var_v1)
    return 0;
  {
    inv = D_800D3E48 / ((f64) temp_ft0);
    temp_ft3 = (*((f32 *) (((char *) arg0) + 0))) - (*((f32 *) (((char *) arg2) + 0)));
    sp20[0] = temp_ft3;
    temp_fa0 = (*((f32 *) (((char *) arg0) + 4))) - (*((f32 *) (((char *) arg2) + 4)));
    sp20[1] = temp_fa0;
    temp_ft1 = (*((f32 *) (((char *) arg0) + 8))) - (*((f32 *) (((char *) arg2) + 8)));
    temp_ft4_2 = (f32) inv;
    temp_fa1_2 = (((temp_ft3 * temp_fa1) + (temp_fa0 * temp_ft2)) + (temp_ft1 * temp_ft4)) * temp_ft4_2;
    var_v0_3 = 1;
    sp20[2] = temp_ft1;
    if (!(temp_fa1_2 < 0.0f))
    {
      var_v0_3 = 0;
    }
    var_v1_2 = 1;
    if (!(temp_fa1_2 > 1.0f))
    {
      var_v1_2 = 0;
    }
    if ((var_v0_3 | var_v1_2) != 0)
    {
      goto __shared_return_0;
    }
    temp_fa0_2 = (temp_fa0 * temp_ft5) - (temp_ft1 * temp_fs1);
    temp_ft2_2 = (temp_ft1 * temp_fs3) - (temp_ft3 * temp_ft5);
    temp_ft3_2 = (temp_ft3 * temp_fs1) - (temp_fa0 * temp_fs3);
    temp_fv0 = (((temp_t2 * temp_fa0_2) + (temp_t3 * temp_ft2_2)) + (temp_fs5 * temp_ft3_2)) * temp_ft4_2;
    sp40[0] = temp_fa0_2;
    sp40[1] = temp_ft2_2;
    sp40[2] = temp_ft3_2;
    if (temp_fv0 < 0.0f)
    {
      goto __shared_return_0;
    }
    if ((temp_fa1_2 + temp_fv0) > 1.0f)
    {
      __shared_return_0:
    return 0;
    }
    *arg5 = (((temp_fv1 * temp_fa0_2) + (temp_fv1_2 * temp_ft2_2)) + (temp_fs2 * temp_ft3_2)) * temp_ft4_2;
    return 1;
  }
}


