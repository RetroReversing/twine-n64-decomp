extern f64 kDoubleOne;
inline static char *inline_fn(void *arg0)
{
  return (char *) arg0;
}

/* Moller-Trumbore ray/triangle test; returns 1 and writes hit distance to outT on hit. */
s8 rayTriangleIntersect(void * rayOrigin, f32 * rayDir, s32 v0, s32 v1, s32 v2, f32 * outT)
{
  f64 invDet;
  f32 edge1[3];
  f32 edge2[3];
  f32 toOrigin[3];
  f32 pvec[3];
  f32 qvec[3];
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
  temp_fs3 = (*((f32 *) (((char *) v1) + 0))) - (*((f32 *) (inline_fn(v0) + 0)));
  edge1[0] = temp_fs3;
  temp_fs1 = (*((f32 *) (((char *) v1) + 4))) - (*((f32 *) (((char *) v0) + 4)));
  edge1[1] = temp_fs1;
  temp_ft5 = (*((f32 *) (((char *) v1) + 8))) - (*((f32 *) (((char *) v0) + 8)));
  edge1[2] = temp_ft5;
  temp_fv1 = (*((f32 *) (((char *) v2) + 0))) - (*((f32 *) (((char *) v0) + 0)));
  edge2[0] = temp_fv1;
  temp_fv1_2 = (*((f32 *) (((char *) v2) + 4))) - (*((f32 *) (((char *) v0) + 4)));
  edge2[1] = temp_fv1_2;
  temp_fs5 = *((const volatile f32 *) (((char *) rayDir) + 8));
  temp_fs2 = (*((f32 *) (((char *) v2) + 8))) - (*((f32 *) (((char *) v0) + 8)));
  temp_t3 = *((f32 *) (((char *) rayDir) + 4));
  temp_t2 = *((f32 *) (((char *) rayDir) + 0));
  temp_fa1 = (temp_t3 * temp_fs2) - (temp_fs5 * temp_fv1_2);
  temp_ft2 = (temp_fs5 * temp_fv1) - (temp_t2 * temp_fs2);
  temp_ft4 = (temp_t2 * temp_fv1_2) - (temp_t3 * temp_fv1);
  var_v0_2 = 1;
  temp_ft0 = ((temp_fs3 * temp_fa1) + (temp_fs1 * temp_ft2)) + (temp_ft5 * temp_ft4);
  edge2[2] = temp_fs2;
  pvec[0] = temp_fa1;
  pvec[1] = temp_ft2;
  pvec[2] = temp_ft4;
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
    invDet = kDoubleOne / ((f64) temp_ft0);
    temp_ft3 = (*((f32 *) (((char *) rayOrigin) + 0))) - (*((f32 *) (((char *) v0) + 0)));
    toOrigin[0] = temp_ft3;
    temp_fa0 = (*((f32 *) (((char *) rayOrigin) + 4))) - (*((f32 *) (((char *) v0) + 4)));
    toOrigin[1] = temp_fa0;
    temp_ft1 = (*((f32 *) (((char *) rayOrigin) + 8))) - (*((f32 *) (((char *) v0) + 8)));
    temp_ft4_2 = (f32) invDet;
    temp_fa1_2 = (((temp_ft3 * temp_fa1) + (temp_fa0 * temp_ft2)) + (temp_ft1 * temp_ft4)) * temp_ft4_2;
    var_v0_3 = 1;
    toOrigin[2] = temp_ft1;
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
    qvec[0] = temp_fa0_2;
    qvec[1] = temp_ft2_2;
    qvec[2] = temp_ft3_2;
    if (temp_fv0 < 0.0f)
    {
      goto __shared_return_0;
    }
    if ((temp_fa1_2 + temp_fv0) > 1.0f)
    {
      __shared_return_0:
    return 0;
    }
    *outT = (((temp_fv1 * temp_fa0_2) + (temp_fv1_2 * temp_ft2_2)) + (temp_fs2 * temp_ft3_2)) * temp_ft4_2;
    return 1;
  }
}
