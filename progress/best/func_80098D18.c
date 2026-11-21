inline static s32 __repair_inline(s32 a)
{
  return a;
}

extern u8 D_801002EA;
extern u8 D_801005B0;
extern u8 D_801007C0;
extern u8 D_80102CE1[];
extern u8 D_8010957D[];
extern u16 D_80109B1C;
extern char D_8010A51A[];
extern u8 D_8010A930;
extern u8 D_8010D720;
extern char D_8010D748[];
extern char D_8010D74C[];
extern char D_8010D752[];
extern u8 sVoiceKeepFlags[];
extern char D_8010D7DE[];
extern u8 D_8010D7E1[];
extern u8 D_80110DB0;
extern u8 D_80112DC0;
extern char D_80117388[];
extern char D_80117389[];
extern char D_8011738A[];
extern u8 sVoiceCount;
inline static int inline_fn(s32 arg0)
{
  return arg0 * 0x1A0;
}

char func_80098D18(s32 arg0, s32 arg1, s32 arg2, s32 arg3)
{
  s32 temp_a0;
  s32 __repair_phase_temp_a0;
  s32 __repair_phase___repair_phase_temp_a0;
  s32 temp_t0;
  s32 var_t8;
  s32 temp_v1;
  s32 temp_v1_2;
  s32 temp_t0_2;
  s32 var_v0;
  s32 var_v0_10;
  s32 var_v0_11;
  s32 var_v0_12;
  s32 var_v0_13;
  s32 var_v0_2;
  s32 var_v0_3;
  s32 var_v0_4;
  s32 var_v0_5;
  register s32 var_v0_6;
  s32 var_v0_7;
  s32 var_v0_8;
  s32 var_v0_9;
  u16 var_t2;
  u16 var_t2_2;
  u32 temp_a1;
  u32 temp_a2;
  register unsigned short var_a1;
  register u32 var_t0;
  s32 temp_t0_3;
  s32 var_t0_2;
  u8 var_t0_3;
  u8 var_t0_4;
  s32 var_t1;
  u8 var_v1;
  void *temp_a0_2;
  arg2 &= 0xFFFF;
  if (D_80112DC0 == 0)
  {
    if (arg3 & 0xFF)
    {
      var_v1 = D_801007C0;
      var_v0 = ((u8) D_8010A930) < var_v1;
    }
    else
    {
      var_v1 = D_801005B0;
      var_v0 = ((u8) D_8010D720) < var_v1;
    }
    var_t8 = 0;
    if (var_v0 == 0)
    {
      var_t8 = var_v1 < ((u8) sVoiceCount);
    }
    temp_a0 = 0;
    if (((u32) (arg1 & 0xFF)) < var_v1)
    {
      var_t2 = D_80109B1C;
      var_t1 = -1U;
      if ((var_t2 & 0xFFFF) != 0xFFFF)
      {
        var_t0 = var_t2 & 0xFFFF;
        for (;;)
        {
          if ((((u32) (arg0 & 0xFF)) >= var_t0) & ((~var_t1) == 0))
          {
            var_t0_2 = *(D_8010957D + var_t0);
            var_v0_2 = var_t2 * 4;
            if (((s32) var_t0_2) != 0xFF)
            {
              {
                s32 __repair_value;
                __repair_value = var_t0_2 * 2; var_v0_3 = __repair_value;
              }
              do
              {
                temp_v1 = (((var_v0_3 + var_t0_2) * 4) + var_t0_2) << 5;
                var_v0_4 = var_t0_2 * 4;
                if ((*(D_8010D7E1 + temp_v1)) == 0)
                {
                  if ((*((u16 *) (D_8010D7DE + temp_v1))) == arg2)
                  {
                    temp_a0 += 1;
                    if ((!(var_t8 & 0xFF)) || ((var_v0_4 = var_t0_2 * 4, (*(sVoiceKeepFlags + temp_v1)) == (arg3 & 0xFF))))
                    {
                      if (!((*((u32 *) (D_8010D748 + temp_v1))) & 2))
                      {
                        if ((var_t1 == (-1U)) || ((var_v0_4 = var_t0_2 * 4, (((u32) (*((u32 *) (D_8010D74C + temp_v1)))) < ((u32) (*((u32 *) (D_8010D74C + inline_fn(var_t1)))))) != 0)))
                        {
                          var_t1 = var_t0_2;
                          goto block_20;
                        }
                      }
                      else
                      {
                        goto block_20;
                      }
                    }
                  }
                  else
                  {
                    block_20:
                    var_v0_4 = var_t0_2 * 4;

                  }
                }
                var_v0_3 = var_t0_2 * 2;
                var_t0_2 = __repair_inline(*(D_80102CE1 + var_v0_4));
              }
              while (var_t0_2 != 0xFF);
              var_v0_2 = var_t2 * 4;
            }
            var_t2 = *((u16 *) (D_8010A51A + var_v0_2));
            var_v0_8 = var_t2 & 0xFFFF;
            var_t0 = var_v0_8;
            if ((var_t2 & 0xFFFF) != 0xFFFF)
            {
              continue;
            }
          }
          break;
        }

      }
      temp_t0 = arg1 & 0xFF;
      if (temp_a0 < temp_t0)
      {
        __repair_phase_temp_a0 = arg1 & 0xFF;
        if ((var_t2 & 0xFFFF) != 0xFFFF)
        {
          var_v0_6 = ((unsigned) temp_a0) < temp_t0;
          for (;;)
          {
            if (var_v0_6)
            {
              var_v0_7 = var_t2 & 0xFFFF;
              var_t0_3 = *(D_8010957D + var_v0_7);
              var_v0_7 = var_t2 * 4;
              if (var_t0_3 != 0xFF)
              {
                var_v0_8 = var_t0_3 * 2;
                __repair_rows:
                {
                  temp_v1_2 = (((var_v0_8 + var_t0_3) * 4) + var_t0_3) << 5;
                  if ((*(D_8010D7E1 + temp_v1_2)) == 0)
                  {
                    temp_a0 += (*((u16 *) (D_8010D7DE + temp_v1_2))) == arg2;
                  }
                  var_v0_9 = var_t0_3 * 4;
                  var_v0_8 = var_t0_3 * 2;
                  var_t0_3 = *(D_80102CE1 + var_v0_9);
                }

                if (var_t0_3 != 0xFF)
                {
                  goto __repair_rows;
                }
                var_v0_7 = var_t2 * 4;
              }
              var_t2 = *((u16 *) (D_8010A51A + var_v0_7));
              var_v0_6 = temp_a0 < temp_t0;
              if (var_t2 == 0xFFFF)
              {
                var_v0_5 = arg1 & 0xFF;
                goto block_36;
              }
              continue;
            }
            break;
          }

          goto block_58;
        }
        block_36:
        if (temp_a0 < __repair_phase_temp_a0)
        {
          goto block_37;
        }

        goto block_59;
      }
      goto block_58;
    }
    block_37:
    var_t8 = var_t8 & 0xFF;

    var_t1 = -1U;
    if ((D_801002EA != 0xFF) & (!var_t8))
    {
      if (1)
      {
      }
      var_t1 = D_801002EA;
      goto block_57;
    }
    temp_a2 = arg0 & 0xFF;
    temp_a1 = D_80109B1C & 0xFFFF;
    if (temp_a2 >= temp_a1)
    {
      var_t2_2 = D_80109B1C;
      if (temp_a1 != 0xFFFF)
      {
        var_a1 = var_t2_2 & 0xFFFF;
        for (;;)
        {
          if ((temp_a2 >= var_a1) & ((~var_t1) == 0))
          {
            var_t0_4 = *(D_8010957D + var_a1);
            var_v0_10 = var_t2_2 * 4;
            if (var_t0_4 != 0xFF)
            {
              var_v0_11 = var_t0_4 * 2;
              do
              {
                temp_a0 = (((var_v0_11 + var_t0_4) * 4) + var_t0_4) << 5;
                if ((*(D_8010D7E1 + temp_a0)) == 0)
                {
                  if ((!var_t8) || ((var_v0_12 = var_t0_4 * 4, (*(sVoiceKeepFlags + temp_a0)) == (arg3 & 0xFF))))
                  {
                    if (!((*((u32 *) (D_8010D748 + temp_a0))) & 2))
                    {
                      if ((var_t1 == (-1U)) || ((var_v0_12 = var_t0_4 * 4, (((u32) (*((u32 *) (D_8010D74C + inline_fn(var_t1))))) > ((u32) (*((u32 *) (D_8010D74C + temp_a0))))) != 0)))
                      {
                        var_t1 = var_t0_4;
                        var_v0_12 = var_t0_4 * 4;
                      }
                    }
                    else
                      if (temp_t0_3)
                    {
                      var_v0_12 = var_t0_4 * 4;
                    }
                    else
                    {
                      var_v0_12 = var_t0_4 * 4;
                    }
                  }
                }
                else
                {
                  var_v0_12 = var_t0_4 * 4;
                }
                var_t0_4 = *(D_80102CE1 + var_v0_12);
                var_v0_11 = var_t0_4 * 2;
              }
              while (var_t0_4 != 0xFF);
              var_v0_10 = var_t2_2 * 4;
            }
            var_t2_2 = *((u16 *) (D_8010A51A + var_v0_10));
            var_a1 = var_t2_2 & 0xFFFF;
            if ((var_t2_2 & 0xFFFF) != 0xFFFF)
            {
              continue;
            }
          }
          break;
        }

      }
      if ((((var_t1 & 0xFFFFu) & 0xFFFFu) & 0xFFFFu) != (-1U))
      {
        block_57:
        if (((u32) (arg0 & 0xFF)) >= ((u8) (*(D_8010D752 + inline_fn(var_t1)))))
        {
          block_58:
          block_59:
          __repair_phase___repair_phase_temp_a0 = var_t1 * 4;


          if (var_t1 != (-1U))
          {
            if ((*((u16 *) (D_8011738A + __repair_phase___repair_phase_temp_a0))) == 1)
            {
              temp_a0_2 = __repair_phase___repair_phase_temp_a0 + D_80117388;
              temp_t0_3 = *((u8 *) (((char *) temp_a0_2) + 0));
              if (temp_t0_3 != 0xFF)
              {
                *(D_80117389 + (temp_t0_3 * 4)) = *((u8 *) (((char *) temp_a0_2) + 1));
              }
              else
              {
                D_801002EA = *((u8 *) (1 + ((char *) temp_a0_2)));
              }
              if (var_t8 || D_80112DC0)
              {
                temp_t0_3 = *((u8 *) (((char *) temp_a0_2) + 1));
              }
              else
              {
                temp_t0_3 = *((u8 *) (((char *) temp_a0_2) + 1));
              }
              if (temp_t0_3 != 0xFF)
              {
                *(D_80117388 + (temp_t0_3 * 4)) = *((u8 *) (((char *) temp_a0_2) + 0));
              }
              if (!(var_t1 != D_80110DB0))
              {
                D_80110DB0 = *((u8 *) (((char *) temp_a0_2) + 0));
                *((s16 *) (((char *) temp_a0_2) + 2)) = 0;
              }
              else
              {
                *((s16 *) (((char *) temp_a0_2) + 2)) = 0;
              }
              goto block_73;
            }
            if ((*(sVoiceKeepFlags + inline_fn(var_t1))) != 0)
            {
              do
              {
                D_8010A930 -= 1;
              }
              while (0);
              var_v0_13 = arg3 & 0xFF;
            }
            else
            {
              D_8010D720 -= 1;
              block_73:
              var_v0_13 = arg3 & 0xFF;

            }
            if (var_v0_13 != 0)
            {
              D_8010A930 += 1;
              return var_t1;
            }
            D_8010D720 += 1;
            return var_t1;
          }
          goto block_77;
        }

        return -1U;
      }
      return -1U;
    }
    return -1U;
  }
  block_77:
  return -1U;

}

