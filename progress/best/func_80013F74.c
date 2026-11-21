void func_80013F74(void *arg0)
{
  s32 temp_v1;
  s32 temp_v0_2;
  s32 var_a2;
  int temp_v1_2;
  s32 var_a3;
  s32 var_a3_4;
  s32 var_a3_6;
  s32 var_t2_2;
  s32 var_t2_3;
  s32 var_t2_4;
  s32 var_t2_5;
  s32 var_t2_6;
  s32 var_t2_7;
  s32 var_t2_8;
  s32 var_v1;
  char *var_t0;
  u32 temp_a1;
  register u32 temp_a1_11;
  u32 temp_a1_12;
  u32 temp_a1_13;
  u32 temp_a1_14;
  u32 temp_a1_15;
  u32 temp_a1_16;
  u32 temp_a1_17;
  u32 __repair_phase_temp_a1_17;
  u32 temp_a1_19;
  u32 temp_a1_20;
  unsigned temp_a1_22;
  u32 temp_a1_23;
  u32 temp_a1_25;
  u32 temp_a1_26;
  u32 temp_a1_27;
  u32 temp_a1_28;
  u32 temp_a1_3;
  u32 temp_a1_5;
  u32 temp_a1_7;
  u32 temp_a1_8;
  u32 temp_a1_9;
  u32 var_a1;
  u32 var_t1;
  char *var_a0;
  char *var_a3_2;
  u8 temp_v0_3;
  u8 temp_v0_4;
  void *temp_v0;
  temp_v0 = *((void **) (((char *) arg0) + 4));
  var_a2 = 0x20;
  var_a0 = *((u8 **) (((char *) arg0) + 0));
  var_a1 = *((u32 *) (((char *) temp_v0) + 0xC));
  var_t1 = *((u32 *) (((char *) temp_v0) + 0x10));
  var_t0 = (void *) temp_v0; var_t0 = (void *) (((char *) var_t0) + ((s32) 0x14));
  loop_1:
  var_a2 = var_a2 - 1;

  loop_2:
  var_v1 = var_a1 & 1;

  if (0 > var_a2)
  {
    temp_a1 = var_t1;
    var_t1 = *((u32 *) var_t0);
    var_t0 += 4;
    var_v1 = (var_a1 + (temp_a1 << (var_a2 + 1))) & 1;
    var_a1 = temp_a1 >> (-var_a2);
    var_a2 += 0x20;
  }
  else
  {
    var_a1 = var_a1 >> 1;
  }
  if (var_v1 == 0)
  {
    var_a2 = var_a2 - 8;
    var_v1 = var_a1 & 0xFF;
    if (var_a2 < 0)
    {
      temp_a1 = var_t1;
      var_t1 = *((u32 *) var_t0);
      var_t0 += 4;
      var_v1 = (var_a1 + (temp_a1 << (var_a2 + 8))) & 0xFF;
      var_a1 = temp_a1 >> (-var_a2);
      var_a2 += 0x20;
    }
    else
    {
      var_a1 = var_a1 >> 8;
    }
    *((u8 *) var_a0) = var_v1;
    var_a0 += 1;
    goto loop_1;
  }
  var_a2 = var_a2 - 1;
  var_v1 = var_a1 & 1;
  if (var_a2 < 0)
  {
    temp_a1_3 = var_t1;
    var_t1 = *((u32 *) var_t0);
    var_t0 += 4;
    var_v1 = (var_a1 + (temp_a1_3 << (var_a2 + 1))) & 1;
    var_a1 = temp_a1_3 >> (-var_a2);
    var_a2 += 0x20;
  }
  else
  {
    var_a1 = var_a1 >> 1;
  }
  var_a2 = var_a2 - 1;
  if (var_v1 == 0)
  {
    temp_v1 = var_a1 & 1;
    if (var_a2 < 0)
    {
      temp_a1_3 = var_t1;
      var_t1 = *((u32 *) var_t0);
      var_t0 += 4;
      var_a1 = temp_a1_3 >> (-var_a2);
      temp_v1 = (var_a1 + (temp_a1_3 << (var_a2 + 1))) & 1;
      var_a2 += 0x20;
    }
    else
    {
      var_a1 = var_a1 >> 1;
    }
    var_a2 = var_a2 - 1;
    do
    {
      do
      {
        do
        {
          do
          {
            do
            {
              do
              {
                do
                {
                  var_t2_2 = temp_v1 + 4;
                }
                while (0);
              }
              while (0);
            }
            while (0);
          }
          while (0);
        }
        while (0);
      }
      while (0);
    }
    while (0);
    if (var_a2 < 0)
    {
      temp_a1_5 = var_t1;
      var_t1 = *((u32 *) var_t0);
      var_t0 += 4;
      var_v1 = (var_a1 + (temp_a1_5 << (var_a2 + 1))) & 1;
      var_a1 = temp_a1_5 >> (-var_a2);
      var_a2 += 0x20;
    }
    else
    {
      var_v1 = var_a1 & 1;
      var_a1 = var_a1 >> 1;
    }
    if (var_v1 != 0)
    {
      var_a2 -= 1;
      var_v1 = var_a1 & 1;
      if (var_a2 < 0)
      {
        temp_a1_5 = var_t1;
        var_t1 = *((u32 *) var_t0);
        var_t0 += 4;
        var_v1 = (var_a1 + (temp_a1_5 << (var_a2 + 1))) & 1;
        var_a2 += 0x20;
        var_a1 = temp_a1_5 >> (-var_a2);
      }
      else
      {
        var_a1 = var_a1 >> 1;
      }
      var_t2_2 = ((var_t2_2 - 1) * 2) + var_v1;
    }
    if (var_t2_2 == 9)
    {
      var_a2 = var_a2 - 4;
      var_t2_3 = var_a1 & 0xF;
      if (var_a2 < 0)
      {
        temp_a1_7 = var_t1;
        var_t1 = *((u32 *) var_t0);
        var_t0 += 4;
        var_t2_3 = (var_a1 + (temp_a1_7 << (var_a2 + 4))) & 0xF;
        var_a1 = temp_a1_7 >> (-var_a2);
        var_a2 += 0x20;
      }
      else
      {
        var_a1 = var_a1 >> 4;
      }
      temp_v0_2 = var_t2_3 * 4;
      var_t2_4 = temp_v0_2 + 0xB;
      if ((temp_v0_2 + 0xC) != 0)
      {
        do
        {
          var_a2 -= 8;
          var_v1 = var_a1 & 0xFF;
          if (var_a2 < 0)
          {
            temp_a1_8 = var_t1;
            var_t1 = *((u32 *) var_t0);
            var_t0 += 4;
            var_v1 = (var_a1 + (temp_a1_8 << (var_a2 + 8))) & 0xFF;
            var_a1 = temp_a1_8 >> (-var_a2);
            var_a2 += 0x20;
          }
          else
          {
            var_a1 = var_a1 >> 8;
          }
          *((u8 *) var_a0) = var_v1;
          var_a0 += 1;
          var_t2_4 -= 1;
        }
        while ((var_t2_4 + 1) != 0);
        var_a2 = var_a2 - 1;
      }
      else
      {
        goto loop_1;
      }
    }
    else
    {
      var_a2 = var_a2 - 1;
      var_a3 = 0;
      if (var_a2 < 0)
      {
        temp_a1_9 = var_t1;
        var_t1 = *((u32 *) var_t0);
        var_t0 += 4;
        var_v1 = (var_a1 + (temp_a1_9 << (var_a2 + 1))) & 1;
        var_a1 = temp_a1_9 >> (-var_a2);
        var_a2 += 0x20;
      }
      else
      {
        var_v1 = var_a1 & 1;
        var_a1 = var_a1 >> 1;
      }
      if (var_v1 != 0)
      {
        var_a2 = var_a2 - 1;
        var_a3 = var_a1 & 1;
        if (var_a2 < 0)
        {
          temp_a1 = var_t1;
          var_t1 = *((u32 *) var_t0);
          var_t0 += 4;
          var_a3 = (var_a1 + (temp_a1 << (var_a2 + 1))) & 1;
          var_a1 = temp_a1 >> (-var_a2);
          var_a2 += 0x20;
        }
        else
        {
          var_a1 = var_a1 >> 1;
        }
        var_a2 = ((u32) var_a2) - 1;
        var_v1 = var_a1 & 1;
        if (var_a2 < 0)
        {
          temp_a1_11 = var_t1;
          var_t1 = *((u32 *) var_t0);
          var_t0 += 4;
          var_v1 = (var_a1 + (temp_a1_11 << (var_a2 + 1))) & 1;
          var_a1 = temp_a1_11 >> (-var_a2);
          var_a2 += 0x20;
        }
        else
        {
          var_a1 = var_a1 >> 1;
        }
        if (var_v1 != 0)
        {
          var_a2 = var_a2 - 1;
          var_v1 = var_a1 & 1;
          if (var_a2 < 0)
          {
            temp_a1_12 = var_t1;
            var_t1 = *((u32 *) var_t0);
            var_t0 += 4;
            var_v1 = (var_a1 + (temp_a1_12 << (var_a2 + 1))) & 1;
            var_a1 = temp_a1_12 >> (-var_a2);
            var_a2 += 0x20;
          }
          else
          {
            var_a1 = var_a1 >> 1;
          }
          var_a3 = ((var_a3 * 2) + var_v1) + 4;
          var_a2 = var_a2 - 1;
          if (var_a2 < 0)
          {
            temp_a1_13 = var_t1;
            var_t1 = *((u32 *) var_t0);
            var_t0 += 4;
            var_v1 = (var_a1 + (temp_a1_13 << (var_a2 + 1))) & 1;
            var_a1 = temp_a1_13 >> (-var_a2);
            var_a2 += 0x20;
          }
          else
          {
            var_v1 = var_a1 & 1;
            var_a1 = var_a1 >> 1;
          }
          if (!var_v1)
          {
            var_a2 -= 1;
            var_v1 = var_a1 & 1;
            if (var_a2 < 0)
            {
              temp_a1_14 = (int) var_t1;
              var_t1 = *((u32 *) var_t0);
              var_t0 += 4;
              var_v1 = (var_a1 + (temp_a1_14 << (var_a2 + 1))) & 1;
              var_a1 = temp_a1_14 >> (-var_a2);
              var_a2 += 0x20;
            }
            else
            {
              var_a1 = var_a1 >> 1;
            }
            var_a3 = (var_a3 * 2) + var_v1;
          }
        }
        else
          if (var_a3 == 0)
        {
          var_a2 -= 1;
          var_v1 = var_a1 & 1;
          if (var_a2 < 0)
          {
            temp_a1_15 = var_t1;
            var_t1 = *((u32 *) var_t0);
            var_t0 += 4;
            if (1)
            {
              var_v1 = (var_a1 + (temp_a1_15 << (var_a2 + 1))) & 1;
              var_a1 = temp_a1_15 >> (-var_a2);
            }
            var_a2 += 0x20;
          }
          else
          {
            var_a1 = var_a1 >> 1;
          }
          var_a3 = var_v1 + 2;
        }
      }
      var_a2 = var_a2 - 8;
      var_v1 = var_a1 & 0xFF;
      if (var_a2 < 0)
      {
        temp_a1_16 = var_t1;
        var_t1 = *((u32 *) var_t0);
        var_t0 += 4;
        var_v1 = (var_a1 + (temp_a1_16 << (var_a2 + 8))) & 0xFF;
        var_a1 = temp_a1_16 >> (-var_a2);
        var_a2 += 0x20;
      }
      else
      {
        var_a1 = var_a1 >> 8;
      }
      var_a3_2 = var_a0 - (((var_a3 << 8) + var_v1) + 1);
      var_t2_5 = var_t2_2 - 1;
      if (var_t2_2 != 0)
      {
        do
        {
          temp_v0_3 = *((u8 *) var_a3_2);
          var_a3_2 += 1;
          temp_v1 = var_t2_5;
          var_t2_5 -= 1;
          *((u8 *) var_a0) = temp_v0_3;
          var_a0 += 1;
        }
        while (temp_v1 != 0);
        var_a2 = var_a2 - 1;
      }
      else
      {
        goto loop_1;
      }
    }
    goto loop_2;
  }
  var_v1 = var_a1 & 1;
  if (var_a2 < 0)
  {
    temp_a1_17 = var_t1;
    var_t1 = *((u32 *) var_t0);
    var_t0 += 4;
    var_v1 = (var_a1 + (temp_a1_17 << (var_a2 + 1))) & 1;
    var_a1 = temp_a1_17 >> (-var_a2);
    var_a2 += 0x20;
  }
  else
  {
    var_a1 = var_a1 >> 1;
  }
  if (var_v1 == 0)
  {
    var_a2 = var_a2 - 8;
    var_t2_6 = 2;
    if (0 > var_a2)
    {
      __repair_phase_temp_a1_17 = var_t1;
      var_t1 = *((u32 *) var_t0);
      var_t0 += 4;
      temp_v1 = (var_a1 + (__repair_phase_temp_a1_17 << (var_a2 + 8))) & 0xFF;
      var_a1 = __repair_phase_temp_a1_17 >> (-var_a2);
      var_a2 += 0x20;
    }
    else
    {
      temp_v1 = var_a1 & 0xFF;
      var_a1 = var_a1 >> 8;
    }
    var_a3_4 = temp_v1 + 1;
    block_68:
    var_t2_7 = var_t2_6 - 1;

    var_a3_2 = var_a0 - var_a3_4;
    if (var_t2_6 != 0)
    {
      do
      {
        temp_v0_4 = *((u8 *) var_a3_2);
        ++var_a3_2;
        temp_v1_2 = var_t2_7;
        var_t2_7 -= 1;
        *((u8 *) var_a0) = temp_v0_4;
        var_a0 += 1;
      }
      while (temp_v1_2);
      var_a2 = var_a2 - 1;
    }
    else
    {
      goto loop_1;
    }
    goto loop_2;
  }
  var_a2 = var_a2 - 1;
  var_v1 = var_a1 & 1;
  if (var_a2 < 0)
  {
    temp_a1_19 = var_t1;
    var_t1 = *((u32 *) var_t0);
    var_t0 += 4;
    var_v1 = (var_a1 + (temp_a1_19 << (var_a2 + 1))) & 1;
    var_a1 = temp_a1_19 >> (-var_a2);
    var_a2 += 0x20;
  }
  else
  {
    var_a1 = var_a1 >> 1;
  }
  if (var_v1 == 0)
  {
    var_t2_6 = 3;
    block_37:
    var_a2 = var_a2 - 1;

    var_a3_6 = 0;
    if (var_a2 < 0)
    {
      temp_a1_20 = var_t1;
      var_t1 = *((u32 *) var_t0);
      var_t0 += 4;
      var_v1 = (var_a1 + (temp_a1_20 << (var_a2 + 1))) & 1;
      var_a1 = temp_a1_20 >> (-var_a2);
      var_a2 += 0x20;
    }
    else
    {
      var_v1 = var_a1 & 1;
      var_a1 = var_a1 >> 1;
    }
    if (var_v1 != 0)
    {
      var_a2 = var_a2 - 1;
      var_a3_6 = var_a1 & 1;
      if (0 > var_a2)
      {
        temp_a1_20 = var_t1;
        var_t1 = *((u32 *) var_t0);
        var_t0 += 4;
        var_a3_6 = (var_a1 + (temp_a1_20 << (var_a2 + 1))) & 1;
        var_a1 = temp_a1_20 >> (-var_a2);
        var_a2 += 0x20;
      }
      else
      {
        var_a1 = var_a1 >> 1;
      }
      var_a2 = var_a2 - 1;
      var_v1 = var_a1 & 1;
      if (var_a2 < 0)
      {
        temp_a1_22 = var_t1;
        var_t1 = *((u32 *) var_t0);
        var_t0 += 4;
        var_v1 = (var_a1 + (temp_a1_22 << (var_a2 + 1))) & 1;
        var_a1 = temp_a1_22 >> (-var_a2);
        var_a2 += 0x20;
      }
      else
      {
        var_a1 = var_a1 >> 1;
      }
      if (var_v1)
      {
        var_v1 = var_a1 & 1;
        var_a2 = var_a2 - 1;
        if (var_a2 < 0)
        {
          temp_a1_23 = var_t1;
          var_t1 = *((u32 *) var_t0);
          var_t0 += 4;
          var_v1 = (var_a1 + (temp_a1_23 << (var_a2 + 1))) & 1;
          var_a1 = temp_a1_23 >> (-var_a2);
          var_a2 += 0x20;
        }
        else
        {
          var_a1 = var_a1 >> 1;
        }
        var_a3_6 = ((var_a3_6 * 2) + var_v1) + 4;
        var_a2 = var_a2 - 1;
        if (var_a2 < 0)
        {
          temp_a1_23 = var_t1;
          var_t1 = *((u32 *) var_t0);
          var_t0 += 4;
          var_v1 = (var_a1 + (((u32) temp_a1_23) << (var_a2 + 1))) & 1;
          var_a1 = temp_a1_23 >> (-var_a2);
          var_a2 += 0x20;
        }
        else
          if (var_a2 || temp_a1_13)
        {
          var_v1 = var_a1 & 1;
          var_a1 = var_a1 >> 1;
        }
        else
        {
          var_v1 = var_a1 & 1;
          var_a1 = var_a1 >> 1;
        }
        if (var_v1 == 0)
        {
          var_a2 -= 1;
          var_v1 = var_a1 & 1;
          if (var_a2 < 0)
          {
            temp_a1_25 = var_t1;
            var_t1 = *((u32 *) var_t0);
            var_t0 += 4;
            var_v1 = (var_a1 + (temp_a1_25 << (var_a2 + 1))) & 1;
            var_a1 = temp_a1_25 >> (-var_a2);
            var_a2 += 0x20;
          }
          else
          {
            var_a1 = var_a1 >> 1;
          }
          var_a3_6 = (var_a3_6 * 2) + var_v1;
        }
      }
      else
        if (var_a3_6 == 0)
      {
        var_a2 -= 1;
        var_v1 = var_a1 & 1;
        if (0 > var_a2)
        {
          temp_a1_26 = var_t1;
          var_t1 = *((u32 *) var_t0);
          var_t0 += 4;
          var_v1 = (var_a1 + (temp_a1_26 << (var_a2 + 1))) & 1;
          var_a1 = temp_a1_26 >> (-var_a2);
          var_a2 += 0x20;
        }
        else
        {
          var_a1 = var_a1 >> 1;
        }
        var_a3_6 = var_v1 + 2;
      }
    }
    var_a2 = var_a2 - 8;
    var_v1 = var_a1 & 0xFF;
    if (var_a2 < 0)
    {
      temp_a1_27 = var_t1;
      var_t1 = *((u32 *) var_t0);
      var_t0 += 4;
      var_v1 = (var_a1 + (temp_a1_27 << (var_a2 + 8))) & 0xFF;
      var_a1 = temp_a1_27 >> (-var_a2);
      var_a2 += 0x20;
    }
    else
    {
      var_a1 = var_a1 >> 8;
    }
    var_a3_4 = ((var_a3_6 << 8) + var_v1) + 1;
    goto block_68;
  }
  var_a2 -= 8;
  var_t2_8 = var_a1 & 0xFF;
  if (var_a2 < (temp_a1_8 * 0))
  {
    temp_a1_28 = var_t1;
    var_t1 = *((u32 *) var_t0);
    var_t0 += 4;
    var_t2_8 = (var_a1 + (temp_a1_28 << (var_a2 + 8))) & 0xFF;
    var_a1 = temp_a1_28 >> (-var_a2);
    var_a2 += 0x20;
  }
  else
  {
    var_a1 = var_a1 >> 8;
  }
  var_t2_6 = var_t2_8 + 8;
  if (var_t2_8)
  {
    goto block_37;
  }
}

