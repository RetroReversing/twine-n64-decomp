/* Intersects segment aStart-aEnd with bStart-bEnd in the XZ plane; returns 0 for no hit, 1 if parallel/collinear, 2 if they cross (point stored in outPoint). */ s32 intersectSegmentsXZ(void *aStart, void *aEnd, void *bStart, void *bEnd, void *outPoint)
{
  f32 aDeltaZ;
  f32 temp_fa1;
  f32 temp_ft1;
  f32 bDeltaZ;
  f32 temp_ft2;
  f32 cross;
  f32 bDeltaX;
  f32 aDeltaX;
  f32 temp_fv1;
  f32 temp_fv1_2;
  f32 var_ft0;
  f32 var_ft0_2;
  f32 var_fv1;
  f32 var_fv1_2;
  s32 var_condition_bit;
  s32 __repair_phase_var_condition_bit;
  s32 var_condition_bit_2;
  f32 temp_ft1_3;
  s32 __repair_phase_var_v0;
  s32 var_v0_2;
  s32 var_v0_3;
  s32 var_v1;
  s32 var_v1_2;
  s32 var_v1_3;
  var_ft0 = *((f32 *) (((char *) aEnd) + 0));
  temp_ft1 = *((f32 *) (((char *) aStart) + 0));
  aDeltaX = var_ft0 - temp_ft1;
  bDeltaX = (*((f32 *) (((char *) bStart) + 0))) - (*((f32 *) (((char *) bEnd) + 0)));
  if (aDeltaX < 0.0f)
  {
    var_fv1 = temp_ft1;
  }
  else
  {
    do
    {
      var_fv1 = var_ft0; var_ft0 = temp_ft1;
    }
    while (0);
  }
  if (bDeltaX > 0.0f)
  {
    var_condition_bit = 0;
    if (!(var_fv1 < (*((f32 *) (((char *) bEnd) + 0)))))
    {
      if (!((*((f32 *) (((char *) bStart) + 0))) < var_ft0)) goto block_9;
      goto Z;
    }
    return var_condition_bit;
  }
  __repair_phase_var_condition_bit = 0;
  if ((!(var_fv1 < (*((f32 *) (((char *) bStart) + 0))))) && (!((*((f32 *) (((char *) bEnd) + 0))) < var_ft0)))
  {
    block_9:
    var_ft0_2 = *((f32 *) (((char *) aEnd) + 8));

    temp_ft2 = *((f32 *) (((char *) aStart) + 8));
    aDeltaZ = var_ft0_2 - temp_ft2;
    bDeltaZ = (*((f32 *) (((char *) bStart) + 8))) - (*((f32 *) (((char *) bEnd) + 8)));
    if (aDeltaZ < 0.0f)
    {
      var_fv1_2 = temp_ft2;
    }
    else
      if (bStart)
    {
      var_fv1_2 = var_ft0_2;
      var_ft0_2 = temp_ft2;
    }
    else
    {
      var_fv1_2 = var_ft0_2;
      var_ft0_2 = temp_ft2;
    }
    if (bDeltaZ > 0.0f)
    {
      var_condition_bit = 0;
      if (!(var_fv1_2 < (*((f32 *) (((char *) bEnd) + 8)))))
      {
        if (!((*((f32 *) (((char *) bStart) + 8))) < var_ft0_2)) goto block_18;
        goto Z;
      }
      return 0;
    }
    __repair_phase_var_v0 = 0;
    if ((!(var_fv1_2 < (*((f32 *) (((char *) bStart) + 8))))) && (!((*((f32 *) (((char *) bEnd) + 8))) < var_ft0_2)))
    {
      block_18:
      temp_fa1 = (*((f32 *) (((char *) aStart) + 0))) - (*((f32 *) (((char *) bStart) + 0)));

      temp_fv1 = (*((f32 *) (((char *) aStart) + 8))) - (*((f32 *) (((char *) bStart) + 8)));
      cross = (aDeltaZ * bDeltaX) - (aDeltaX * bDeltaZ);
      temp_ft1_3 = (bDeltaZ * temp_fa1) - (bDeltaX * temp_fv1);
      if (cross > 0.0f)
      {
        var_v0_2 = 1;
        if (!(temp_ft1_3 < 0.0f))
        {
          var_v0_2 = 0;
        }
        var_condition_bit = cross < temp_ft1_3;
      }
      else
      {
        var_v0_2 = 1;
        if (!(temp_ft1_3 > 0.0f))
        {
          var_v0_2 = 0;
        }
        var_condition_bit = temp_ft1_3 < cross;
      }
      var_v1 = var_condition_bit;
      if ((var_v0_2 | var_v1) != 0)
      {
        return 0;
      }
      temp_fv1_2 = (aDeltaX * temp_fv1) - (aDeltaZ * temp_fa1);
      if (cross > 0.0f)
      {
        var_v0_3 = 1;
        if (!(temp_fv1_2 < 0.0f))
        {
          var_v0_3 = 0;
        }
        var_condition_bit_2 = cross < temp_fv1_2;
      }
      else
      {
        var_v0_3 = 1;
        if (!(temp_fv1_2 > 0.0f))
        {
          var_v0_3 = 0;
        }
        var_condition_bit_2 = temp_fv1_2 < cross;
      }
      var_v1_2 = 1;
      if (!var_condition_bit_2)
      {
        var_v1_2 = 0;
      }
      if (!(var_v0_3 | var_v1_2))
        goto check_epsilon;
      Z:
      return 0;
      check_epsilon:;
      var_v0_3 = 1;
      if (!(cross <= 0.0002f))
      {
        var_v0_3 = 0;
      }
      var_v1_3 = 1;
      if (!(cross >= (-0.0002f)))
      {
        var_v1_3 = 0;
      }
      var_condition_bit = 1;
      if (var_v0_3 & var_v1_3)
      {
        return 1;
      }
      {
        f32 dx = (temp_ft1_3 * aDeltaX) / cross;
        f32 dz;
        f32 x = (*((f32 *) aStart)) + dx;
        f32 z = (*((f32 *) (((char *) aStart) + 8))) + ((temp_ft1_3 * aDeltaZ) / cross);
        *((f32 *) outPoint) = x;
        *((f32 *) (((char *) outPoint) + 8)) = z;
        var_condition_bit = 2;
      }
      return var_condition_bit;
    }
    goto Z;
  }
  goto Z;
}


