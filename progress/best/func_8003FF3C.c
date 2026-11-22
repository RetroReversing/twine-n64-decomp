#define FLD(p, t, o) (*(t *)((u8 *)(p) + (o)))
#define BE16(p) ((u16)(((p)[0] << 8) | (p)[1]))
void buildPlaneFromPoints(void *, s32, s32, s32);
inline static int inline_fn(u8 *arg0, u8 arg1)
{
  return arg0[arg1] & 0xFF;
}

inline static int inline_fn2()
{
  return -1;
}

void func_8003FF3C(void *arg0, u8 *arg1, s16 *arg2)
{
  register u8 *var_s0 = arg1;
  register s16 *var_t0 = arg2;
  register unsigned long var_s7 = 3;
  u8 *var_s1 = NULL;
  s16 *var_s6 = NULL;
  u8 *var_s5 = NULL;
  register u8 *var_s2;
  s16 *var_s4;
  register u8 var_t2;
  u32 var_fp;
  u8 *var_s3;
  s32 a3_2;
  s32 v1_2;
  s32 a2;
  s32 a2_c;
  s32 __repair_result_a2;
  s32 __repair_phase_v1;
  s32 __repair_phase___repair_phase_v1;
  unsigned int base;
  unsigned int __repair_phase_base;
  u32 sp10[3];
  u32 unused[2];
  register unsigned long tmp8;
  u16 t16_2;
  u16 t16_default;
  long t16_arm;
  u16 __repair_result_t16;
  u16 t16b_2;
  u16 t16b_default;
  u16 t16b_arm;
  u16 __repair_result_t16b;
  u16 t16c;
  if ((*((u8 *) (((u8 *) arg0) + 0x48))) & 4)
  {
    var_s6 = *((s16 **) (((u8 *) arg0) + 0x3C));
  }
  else
  {
    var_s5 = *((u8 **) (((u8 *) arg0) + 0x3C));
  }
  goto loop_48;
  dispatch:
  switch (var_s0[0])
  {
    do
    {
      case 9:
        var_s0 += 4;

      goto loop_48;
      case 0:
        var_s1 = var_s0 + 2;

      ++var_s0;
      var_s7 = 0; var_s0 += 1 + (var_s0[0] * 3);
      goto loop_48;
      do
      {
        case 1:
          var_s1 = var_s0 + 2;

        ++var_s0;
        var_s7 = 1; var_s0 += 1 + (var_s0[0] * 6);
        goto loop_48;
        case 3:
          var_s1 = var_s0 + 2;

        ++var_s0;
        var_s7 = 3; var_s0 += 1 + (var_s0[0] * 1);
        goto loop_48;
        case 2:
          if (var_s1)
        {
          var_s1 = var_s0 + 2;
          ++var_s0;
          var_s7 = 2;
          var_s0 += 1 + (var_s0[0] * 2);
          goto loop_48;
        }
        else
        {
          var_s1 = var_s0 + 2;
          ++var_s0;
          var_s7 = 2;
          var_s0 += 1 + (var_s0[0] * 2);
          goto loop_48;
        }

        case 6:
        {
          u8 value = var_s0[1];
          if ((var_s0 || var_s1) != 0.0f)
          {
            var_s0 += 2;
            *((u8 *) (((u8 *) arg0) + 0x44)) = value;
          }
          else
          {
            var_s0 += 2;
            *((u8 *) (((u8 *) arg0) + 0x44)) = value;
          }
        }

        goto block_15;
        case 7:
        {
          u8 value = var_s0[1];
          ++var_s0;
          *((u8 *) (((u8 *) arg0) + 0x44)) = value;
          goto block_15;
        }

        case 8:
          var_s0 += 3;

        case 5:
          block_15:
        var_t2 = var_s0[1];


        var_s0 += 2; var_fp = 0;
        if (var_t2)
        {
          var_s2 = var_s0 + 2; var_s4 = var_s6 + 2; var_s3 = var_s5 + 2;
          do
          {
            if (1)
            {
              switch (var_s7)
              {
                case 3:
                {
                  u8 first = var_s1[var_s0[0]];
                  u8 second;
                  *var_s5 = first; second = var_s1[var_s2[((s32) (var_fp * 3)) - 1]];
                  var_s3[inline_fn2()] = second;
                  tmp8 = var_s1[var_s2[var_fp * 3]]; a2 = first & 0xFF;
                  var_s5 += 3;
                  a2_c = second & 0xFF;
                  v1_2 = tmp8 & 0xFF;
                  var_s3[0] = tmp8;
                  var_s3 += 3;
                  goto after;
                }

                case 2:
                  t16_2 = BE16(var_s1 + (var_s0[0] * 2));
                  *var_s6 = t16_2;
                  t16b_2 = BE16(var_s1 + (var_s2[((s32) (var_fp * 3)) - 1] * 2));
                  var_s4[inline_fn2()] = t16b_2;
                  a2 = t16_2 & 0xFFFF;
                  var_s6 += 3;
                  tmp8 = var_s2[var_fp * 3];
                  t16c = BE16(var_s1 + (tmp8 * 2));
                  v1_2 = t16c & 0xFFFF;
                  a2_c = t16b_2 & 0xFFFF;
                  var_s4[0] = t16c;
                  var_s4 += 3;
                  break;

                case 0:
                {
                  u8 first = var_s1[var_s0[0] * 3];
                  u8 second;
                  *var_s5 = first; second = var_s1[var_s2[((s32) (var_fp * 3)) - 1] * 3];
                  var_s3[inline_fn2()] = second;
                  tmp8 = var_s1[var_s2[var_fp * 3] * 3]; a2 = first & 0xFF;
                  var_s5 += 3;
                  a2_c = second & 0xFF;
                  v1_2 = tmp8 & 0xFF;
                  var_s3[0] = tmp8;
                  var_s3 += 3;
                  goto after;
                }

                default:
                  t16_default = BE16(var_s1 + (var_s0[0] * 6));
                  *var_s6 = t16_default;
                  t16b_default = BE16(var_s1 + (var_s2[((s32) (var_fp * 3)) - 1] * 6));
                  var_s4[inline_fn2()] = t16b_default;
                  a2 = t16_default & 0xFFFF;
                  var_s6 += 3;
                  tmp8 = var_s2[var_fp * 3] * 3;
                  t16c = BE16(var_s1 + (tmp8 * 2));
                  a2_c = t16b_default & 0xFFFF;
                  v1_2 = t16c & 0xFFFF;
                  var_s4[0] = t16c;
                  var_s4 += 3;
                  break;

              }

              after:
              base = *((s32 *) (((u8 *) arg0) + 0x34));

              buildPlaneFromPoints(&sp10, base + (a2 * 12), base + (a2_c * 12), base + (v1_2 * 12));
              var_s0 += 3; var_fp += 1;
              *var_t0 = 0;
              var_t0++;
            }
          }
          while (var_fp < var_t2);
        }
        goto loop_48;
        case 4:
          do
        {
          switch (var_s7)
          {
            case 3:
              tmp8 = var_s1[var_s0[1]];
              var_s5[0] = tmp8;
              v1_2 = var_s1[var_s0[2]];
              var_s5[1] = (u8) v1_2;
              tmp8 = var_s1[var_s0[3]];
              a2_c = inline_fn(var_s1, var_s0[1]);
              a2_c = (u8) tmp8;
              a3_2 = v1_2 & 0xFF;
              v1_2 = tmp8 & 0xFF;
              var_s5[2] = tmp8;
              var_s5 += 3;
              break;

            case 2:
              __repair_phase_v1 = (u16) BE16(var_s1 + (var_s0[1] * 2));
              var_s6[0] = __repair_phase_v1;
              __repair_result_t16b = BE16(var_s1 + (var_s0[2] * 2));
              var_s6[1] = __repair_result_t16b;
              tmp8 = var_s0[3];
              a2_c = __repair_phase_v1 & 0xFFFF;
              t16c = BE16(var_s1 + (tmp8 * 2));
              a3_2 = __repair_result_t16b & 0xFFFF;
              v1_2 = t16c & 0xFFFF;
              var_s6[2] = t16c;
              var_s6 += 3;
              break;

            case 0:
            {
              u8 first = var_s1[var_s0[1] * 3];
              var_s5[0] = first; a2_c = first;
            }
              __repair_phase___repair_phase_v1 = var_s1[var_s0[2] * 3];
              var_s5[1] = (u8) __repair_phase___repair_phase_v1;
              tmp8 = var_s1[var_s0[3] * 3];
              __repair_result_a2 = inline_fn(var_s1, var_s0[1] * 3);
              a3_2 = __repair_phase___repair_phase_v1 & 0xFF;
              v1_2 = tmp8 & 0xFF;
              var_s5[2] = tmp8;
              var_s5 += 3;
              break;

            default:
            {
              t16_arm = BE16(var_s1 + (var_s0[1] * 6)); var_s6[0] = t16_arm; t16b_arm = BE16(var_s1 + (var_s0[2] * 6)); var_s6[1] = t16b_arm; tmp8 = var_s0[3] * 3; a2_c = t16_arm & 0xFFFF; t16c = BE16(var_s1 + (tmp8 * 2)); v1_2 = t16c & 0xFFFF; a3_2 = t16b_arm & 0xFFFF; var_s6[2] = t16c; var_s6 += 3;
            }
              break;

          }

          __repair_phase_base = *((s32 *) (((u8 *) arg0) + 0x34));
          buildPlaneFromPoints(&sp10, __repair_phase_base + (a2_c * 12), __repair_phase_base + (a3_2 * 12), __repair_phase_base + (v1_2 * 12));
          var_s0 += 4;
          *var_t0 = 0;
        }
        while (0);

        var_t0++;
        goto loop_48;
        case 10:
          *((u8 *) (((u8 *) arg0) + 0x44)) = var_s0[1];

        var_s0 += 2;
        goto loop_48;
        case 11:
          var_s0 += 2;

        goto loop_48;
        default:
          goto loop_48;

      }
      while (0);
    }
    while (0);
  }


  loop_48:
  if (var_s0[0] != 12)
  {
    {
      long long phantom_wide = var_s7;
    }
    goto dispatch;
  }

}

