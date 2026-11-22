extern s32 D_800B269F;
extern s32 D_800B26BF;
extern s32 D_800B27E0;
extern s32 D_800B281C;
extern u32 D_800B283C;
extern s32 D_800B2CB8;
extern s32 D_800B3134;
extern u16 D_801032B0;
extern u16 D_80108970;
extern u8 D_80108FA0;
extern u32 D_80112EE0;
void func_800134D0(void *arg0)
{
    u32 *hoist_D_80112EE0;
  u16 *spC;
  register void *sp4;
  u32 sp1C;
  volatile s32 sp2C;
  s32 *var_a0_5;
  s32 temp_a1_3;
  s32 temp_s2;
  s32 temp_t5;
  s32 temp_v0_2;
  s32 temp_v0_3;
  s32 temp_v0_4;
  register s32 temp_v1_2;
  s32 temp_v1_3;
  s32 var_a2;
  s32 var_a2_10;
  s32 var_a2_8;
  s32 var_t1;
  s32 var_t1_2;
  s32 var_t1_8;
  s32 var_t3;
  s32 var_t3_3;
  s32 __repair_phase_var_t3_3;
  s32 __repair_phase_var_t3_4;
  unsigned var_t3_5;
  s32 var_t4;
  s32 var_t5_2;
  s32 var_t6;
  s32 var_t7;
  s32 var_t9;
  s32 var_v0;
  s32 var_v0_2;
  s32 var_v0_3;
  s8 temp_v1_7;
  u16 *var_a1_4;
  u16 *var_v1_5;
  u16 temp_v1_5;
  u16 var_a1_6;
  u16 var_t1_7;
  u32 *temp_v1;
  u32 *var_a0;
  u32 *var_a0_3;
  u32 *var_a0_4;
  u32 *var_s1;
  u32 *var_s2;
  u32 *var_t0;
  u32 *var_t0_2;
  u32 *var_t5;
  u32 *var_t5_3;
  u32 *var_t6_2;
  u32 *var_t6_3;
  u32 *var_t8;
  u32 *var_v1;
  u32 *var_v1_2;
  u32 *var_v1_3;
  u32 temp_a1;
  u32 temp_a1_2;
  u32 temp_a2;
  u32 temp_t1;
  u32 temp_t2;
  u32 temp_t2_10;
  u32 temp_t2_11;
  u32 temp_t2_2;
  u32 temp_t2_3;
  u32 temp_t2_4;
  u32 temp_t2_5;
  u32 temp_t2_6;
  u32 temp_t2_7;
  unsigned int temp_t2_8;
  u32 temp_t2_9;
  u32 var_a1;
  u32 var_a1_2;
  u32 var_a1_5;
  u32 var_a2_3;
  u32 var_a2_6;
  u32 var_a2_7;
  u32 var_a3;
  u32 var_a3_2;
  u32 var_a3_3;
  u32 var_a3_4;
  u32 var_a3_5;
  u32 var_a3_6;
  u32 var_a3_7;
  u32 var_a3_8;
  u32 var_a3_9;
  u32 var_s3;
  u32 __repair_phase_var_s3;
  u32 var_s4;
  u32 var_t1_3;
  u32 var_t1_4;
  u32 var_t1_5;
  unsigned var_t1_6;
  u32 var_t2;
  u32 var_v1_6;
  u32 var_v1_7;
  u8 *var_a0_6;
  u8 *var_fp;
  u8 *var_v1_4;
  u8 *var_v1_8;
  u8 temp_v0_6;
  u8 temp_v1_4;
  u8 temp_v1_6;
  u8 var_a2_2;
  union 
  {
    void *pointer;
    s32 value;
  } __repair_phase_storage;
  void *temp_v0_5;
  sp4 = arg0;
  var_fp = *((u8 **) (((char *) arg0) + 0));
  sp1C = 0;
  __repair_phase_storage.pointer = *((void **) (((char *) arg0) + 4));
  var_t2 = *((s32 *) (((char *) __repair_phase_storage.pointer) + 0xC));
  var_s4 = *((s32 *) (((char *) __repair_phase_storage.pointer) + 0x10));
  var_s1 = __repair_phase_storage.pointer + 0x14;
  var_t4 = 0x20;
  hoist_D_80112EE0 = &D_80112EE0;
  loop_1:
  --var_t4;

  var_a2 = var_t2 & 1;
  if (var_t4 < 0)
  {
    u32 temp_t2_arm;
    s32 temp_v0_2_arm;
    temp_t2_arm = var_t2;
    var_t2 = var_s4;
    var_s4 = *(var_s1++);
    temp_v0_2_arm = temp_t2_arm + (var_t2 << (var_t4 + 1)); var_a2 = temp_v0_2_arm & 1;
    var_t2 >>= -var_t4;
    var_t4 += 0x20;
  }
  else
  {
    var_t2 = var_t2 >> 1;
  }
  if (((s32) var_a2) == 0)
  {
    var_t4 -= 0xF;
    if (var_t4 >= 0)
    {
      var_t1 = var_t2 & 0x7FFF;
      var_t2 = var_t2 >> 0xF;
    }
    else
    {
      var_s3 = var_s4;
      do
      {
        do
        {
          do
          {
            var_s4 = *var_s1;
          }
          while (0);
        }
        while (0);
      }
      while (0);
      var_s1++;
      temp_s2 = var_t2 + (var_s3 << (var_t4 + 0xF)); var_t1 = temp_s2 & 0x7FFF;
      var_t2 = var_s3 >> (-var_t4);
      var_t4 += 0x20;
    }
    var_t1_2 = var_t1 - 1;
    if (var_t1)
    {
      do
      {
        var_t4 -= 8;
        var_a2_2 = var_t2 & 0xFF;
        if (var_t4 < 0)
        {
          temp_t2 = var_t2;
          var_t2 = var_s4;
          var_s4 = *(var_s1++);
          var_a2_2 = (temp_t2 + (var_t2 << (var_t4 + 8))) & 0xFF;
          var_t2 >>= -var_t4;
          var_t4 += 0x20;
        }
        else
        {
          var_t2 = var_t2 >> 8;
        }
        *var_fp = var_a2_2;
        ++var_fp;
        var_t1_2 -= 1;
      }
      while (var_t1_2 != 0);
      --var_t4;
    }
    else
    {
      goto block_123;
    }
    goto block_124;
  }
  __repair_phase_storage.value = 1;
  loop_17:
  spC = &D_80108970;

  var_s3 = 8;
  if ((__repair_phase_storage.value--) != 0)
  {
    spC = &D_801032B0;
    var_s3 = 0xA;
  }
  var_t4 -= 9;
  var_a2_3 = var_t2 & 0x1FF;
  if (var_t4 < 0)
  {
    temp_t2 = var_t2;
    var_t2 = var_s4;
    var_s4 = *(var_s1++);
    var_a2_3 = (temp_t2 + (var_t2 << (var_t4 + 9))) & 0x1FF;
    var_t2 >>= -var_t4;
    var_t4 += 0x20;
  }
  else
  {
    var_t2 = var_t2 >> 9;
  }
  if (var_a2_3 != 0)
  {
    s32 temp_a1_3_arm;
    var_a3 = 1;
    var_v1 = (hoist_D_80112EE0) + 1;
    do
    {
      *var_v1 = 0;
      ++var_a3;
      var_v1++;
    }
    while (0x21U > var_a3);
    var_a3_2 = 0;
    var_a0 = &D_800B283C;
    do
    {
      var_t4--;
      var_a2 = var_t2 & 1;
      if (var_t4 < 0)
      {
        temp_t2 = var_t2;
        var_t2 = var_s4;
        var_s4 = *(var_s1++);
        var_a2 = (temp_t2 + (var_t2 << (var_t4 + 1))) & 1;
        var_t2 >>= -var_t4;
        var_t4 += 0x20;
      }
      else
      {
        var_t2 = var_t2 >> 1;
      }
      if (var_a2 == 1)
      {
        var_t4 -= 4;
        if (var_t4 < 0)
        {
          sp1C = var_t2;
          temp_t2 = var_t2;
          var_t2 = var_s4;
          var_s4 = *(var_s1++);
          sp1C = (sp1C + (var_t2 << (var_t4 + 4))) & 0xF;
          var_t2 >>= -var_t4;
          var_t4 += 0x20;
        }
        else
        {
          sp1C = var_t2 & 0xF;
          var_t2 = var_t2 >> 4;
        }
      }
      *var_a0 = sp1C;
      temp_v1 = &(hoist_D_80112EE0)[sp1C];
      *temp_v1 += 1;
      var_a3_2 += 1;
      var_a0++;
    }
    while (var_a2_3 > var_a3_2);
    *((s32 *) (hoist_D_80112EE0)) = 0;
    var_t3 = 0;
    var_a3_3 = 1;
    do
    {
      if (var_a2_3 != 0)
      {
        var_a1 = 0;
        temp_v1 = &D_800B283C;
        var_v1_2 = (s32 *) (((s8 *) (&D_800B3134)) + (var_t3 * 4));
        do
        {
          if ((*temp_v1) == var_a3_3)
          {
            *var_v1_2 = var_a1;
            var_v1_2++;
            var_t3 += 1;
          }
          var_a1 += 1;
          temp_v1++;
        }
        while (var_a1 < var_a2_3);
      }
      var_a3_3 += 1;
      var_t1_3 = 1;
    }
    while (var_a3_3 < 0x10U);
    var_t3 = 0;
    var_a0_3 = (hoist_D_80112EE0) + 1;
    do
    {
      do {
          var_a3_4 = 1;
      } while (0);
      if ((*var_a0_3) != 0)
      {
        var_v1_3 = &(&D_800B283C)[var_t3];
        do
        {
          *var_v1_3 = var_t1_3;
          var_v1_3++;
          var_a3_4 += 1;
          var_t3 += 1;
        }
        while (((u32) (*var_a0_3)) >= var_a3_4);
      }
      var_t1_3 += 1;
      var_a0_3++;
    }
    while (var_t1_3 < 0x10U);
    (&D_800B283C)[var_t3] = 0;
    var_t1_4 = *((s32 *) (&D_800B283C));
    var_a3_5 = 0;
    var_t3_3 = 0;
    if (var_t1_4 != 0)
    {
      var_t6 = 0;
      var_t5 = &D_800B283C;
      do
      {
        if ((*var_t5) == var_t1_4)
        {
          var_t0 = &(&D_800B283C)[var_t3_3];
          var_a0_5 = (s32 *) (((s8 *) (&D_800B2CB8)) + (var_t3_3 * 4));
          do
          {
            var_a1_2 = var_a3_5 | (1 << var_t1_4);
            var_a3_5 += 1;
            *var_a0_5 = 0;
            loop_51:
            temp_v1_2 = var_a1_2 & 1;

            var_a1_2 = var_a1_2 >> 1;
            *var_a0_5 = ((*var_a0_5) * 2) + ((s32) temp_v1_2);
            if (var_a1_2 != 1)
            {
              goto loop_51;
            }
            var_t0 += 1;
            var_a0_5++;
            var_t6 += 4;
            var_t5++;
            var_t3_3 += 1;
          }
          while ((*var_t0) == var_t1_4);
        }
        var_a3_5 *= 2;
        ++var_t1_4;
      }
      while ((*((u32 *) (((s8 *) (&D_800B283C)) + var_t6))) != 0);
      var_a3_5 = 0;
    }
    var_v1_4 = &D_80108FA0;
    do
    {
      *var_v1_4 = 0;
      var_a3_5 += 1;
      ++var_v1_4;
    }
    while ((var_a3_5 >> var_s3) == 0);
    var_t3_3 = 0;
    var_t1_5 = 1;
    if (1U < var_s3)
    {
      if (var_s1)
      {
        var_t7 = 4;
        var_t6_2 = (hoist_D_80112EE0) + 1;
      }
      else
      {
        var_t7 = 4;
        var_t6_2 = (hoist_D_80112EE0) + 1;
      }
      do
      {
        var_a3_6 = 1;
        if ((*var_t6_2) != 0)
        {
          do
          {
            temp_t5 = 1 << var_t1_5;
          }
          while (0);
          temp_v0_2 = var_t3_3 * 4;
          var_a0_5 = (s32 *) (((s8 *) (&D_800B3134)) + temp_v0_2);
          var_a0_4 = (s32 *) (((s8 *) (&D_800B2CB8)) + temp_v0_2);
          do
          {
            var_a2_6 = *var_a0_4;
            var_v1_5 = &spC[var_a2_6];
            loop_62:
            var_a2_6 += temp_t5;

            *var_v1_5 = ((*var_a0_5) << 7) + var_t1_5;
            var_v1_5 = &var_v1_5[temp_t5];
            if ((var_a2_6 >> var_s3) == 0)
            {
              goto loop_62;
            }
            var_a3_6 += 1;
            var_a0_5++;
            var_a0_4++;
            ++var_t3_3;
          }
          while (((u32) (*((u32 *) (((s8 *) (hoist_D_80112EE0)) + var_t7)))) >= var_a3_6);
        }
        var_t7 += 4;
        var_t1_5 += 1;
        var_t6_2++;
      }
      while (var_t1_5 < var_s3);
    }
    temp_s2 = var_t3_3;
    if (var_t1_5 < 0x10U)
    {
      var_t5_2 = var_t1_5 * 4;
      var_t6_3 = &(hoist_D_80112EE0)[var_t1_5];
      do
      {
        var_a3_7 = 1;
        if ((*var_t6_3) != 0)
        {
          var_a0_5 = (s32 *) (((s8 *) (&D_800B2CB8)) + (var_t3_3 * 4));
          var_t0_2 = &(&D_800B283C)[var_t3_3];
          do
          {
            temp_a1 = *var_t0_2;
            temp_v1_3 = (*var_a0_5) & ((1 << var_s3) - 1);
            var_a3_7 += 1;
            if (((u8) (&D_80108FA0)[temp_v1_3]) < temp_a1)
            {
              (&D_80108FA0)[temp_v1_3] = (u8) temp_a1;
            }
            var_t0_2++;
            var_a0_5++;
            var_t3_3 += 1;
          }
          while (((u32) (*((u32 *) (((s8 *) (hoist_D_80112EE0)) + var_t5_2)))) >= var_a3_7);
        }
        var_t5_2 += 4;
        var_t1_5 += 1;
        var_t6_3++;
      }
      while (0x10U > var_t1_5);
    }
    var_a2_7 = 0;
    var_a3_8 = 0;
    var_a0_6 = &D_80108FA0;
    var_a1_4 = spC;
    loop_74:
    __repair_phase_var_t3_3 = (u8) (*var_a0_6);

    temp_v0_3 = __repair_phase_var_t3_3 & 0xFF;
    if (temp_v0_3 != 0)
    {
      if (((u32) (temp_v0_3 - var_s3)) >= 8U)
      {
        *((s32 *) (((char *) sp4) + 0x1C)) = -8;
        return;
      }
      *var_a1_4 = (var_a2_7 << 7) + ((__repair_phase_var_t3_3 - var_s3) * 0x10);
      var_a2_7 += 1 << ((*var_a0_6) - var_s3);
      goto block_78;
    }
    block_78:
    var_a0_6 += 1;

    var_a3_8 += 1;
    var_a1_4++;
    if ((var_a3_8 >> var_s3) != 0)
    {
      var_t1_6 = var_s3;
      if (var_a2_7 >= 0x200U)
      {
        *((s32 *) (((char *) sp4) + 0x1C)) = -9;
        return;
      }
      var_t3_5 = temp_s2;
      if (var_t1_6 < 0x10U)
      {
        temp_a1_3_arm = 1 << var_t1_6;
        sp2C = temp_a1_3_arm - 1;
        var_t9 = var_t1_6 * 4;
        var_s2 = &(hoist_D_80112EE0)[var_t1_6];
        do
        {
          var_a3_9 = 1;
          if ((*var_s2) != 0)
          {
            temp_v0_4 = var_t3_5 * 4;
            var_t8 = &(&D_800B283C)[var_t3_5];
            var_a0_5 = (s32 *) (((s8 *) (&D_800B3134)) + temp_v0_4);
            var_t5_3 = (s32 *) (((s8 *) (&D_800B2CB8)) + temp_v0_4);
            do
            {
              temp_v1_5 = spC[temp_a2 & sp2C];
              temp_a2 = *var_t5_3;
              var_a1_5 = temp_a2 >> var_s3;
              do
              {
                (&spC[(temp_v1_5 >> 7) + temp_a1_3_arm])[var_a1_5] = ((*var_a0_5) << 7) + (*var_t8);
                var_a1_5 += 1 << ((*var_t8) - var_s3);
              }
              while ((var_a1_5 >> ((temp_v1_5 >> 4) & 7)) == 0);
              var_a3_9 += 1;
              var_t8 += 1;
              var_a0_5++;
              var_t5_3 += 1;
              var_t3_5 += 1;
            }
            while (((u32) (*((u32 *) (((s8 *) (hoist_D_80112EE0)) + var_t9)))) >= var_a3_9);
          }
          var_t9 += 4;
          var_t1_6 += 1;
          var_s2++;
        }
        while (var_t1_6 < 0x10U);
      }
      goto block_89;
    }
    goto loop_74;
  }
  block_89:
  if (__repair_phase_storage.value < 0)
  {
    loop_91:
    var_v0 = var_t4 < 0xF;

    loop_92:
    if (((unsigned) var_v0) != 0)
    {
      var_v1_6 = var_t2 + (var_s4 << var_t4);
    }
    else
    {
      var_v1_6 = var_t2;
    }

    var_t1_7 = (&D_801032B0)[var_v1_6 & 0x3FF];
    var_v0_2 = var_t1_7 & 0xF;
    if (var_v0_2 == 0)
    {
      var_t1_7 = ((&D_801032B0) + 0x400)[((var_v1_6 >> 0xA) & ((1 << ((var_t1_7 >> 4) & 7)) - 1)) + ((var_t1_7 >> 4) >> 3)];
      var_v0_2 = var_t1_7 & 0xF;
    }
    var_t4 -= var_v0_2;
    var_t2 = var_t2 >> var_v0_2;
    if (var_t4 < 0)
    {
      temp_t2_7 = var_s4;
      var_s4 = *var_s1;
      var_s1++;
      var_t2 = temp_t2_7 >> (-var_t4);
      var_t4 += 0x20;
    }
    temp_t1 = var_t1_7 >> 7;
    if (temp_t1 < 0x100U)
    {
      *var_fp = (u8) temp_t1;
      var_fp += 1;
      goto loop_91;
    }
    if (temp_t1 != 0x100)
    {
      temp_v1_6 = *((u8 *) (((s8 *) (&D_800B26BF)) + temp_t1));
      var_a2_8 = 0;
      if (temp_v1_6 != 0)
      {
        var_t4 -= temp_v1_6;
        if (var_t4 < 0)
        {
          temp_t2 = var_t2;
          var_t2 = var_s4;
          var_s4 = *(var_s1++);
          var_a2_8 = (temp_t2 + (var_t2 << (var_t4 + temp_v1_6))) & ((1 << temp_v1_6) - 1);
          var_t2 >>= -var_t4;
          var_t4 += 0x20;
        }
        else
        {
          var_a2_8 = var_t2 & ((1 << temp_v1_6) - 1);
          var_t2 = var_t2 >> temp_v1_6;
        }
      }
      var_t1_8 = ((*((u8 *) (((s8 *) (&D_800B269F)) + temp_t1))) + var_a2_8) + 3;
      if (var_t4 < 0xF)
      {
        var_v1_7 = var_t2 + (var_s4 << var_t4);
      }
      else
      {
        var_v1_7 = var_t2;
      }
      var_a1_6 = (&D_80108970)[var_v1_7 & 0xFF];
      var_v0_3 = var_a1_6 & 0xF;
      if (var_v0_3 == 0)
      {
        var_a1_6 = ((&D_80108970) + 0x100)[((var_v1_7 >> 8) & ((1 << ((var_a1_6 >> 4) & 7)) - 1)) + (var_a1_6 >> 7)];
        var_v0_3 = var_a1_6 & 0xF;
      }
      var_t4 -= var_v0_3;
      var_t2 = var_t2 >> var_v0_3;
      if (var_t4 < 0)
      {
        temp_t2_9 = var_s4;
        var_s4 = *var_s1;
        var_s1++;
        var_t2 = ((unsigned) temp_t2_9) >> (-var_t4);
        var_t4 += 0x20;
      }
      temp_a1_2 = var_a1_6 >> 7;
      temp_v1_7 = *((s8 *) (((s8 *) (&D_800B281C)) + temp_a1_2));
      var_a2_8 = 0;
      if (temp_v1_7 != 0)
      {
        var_t4 -= temp_v1_7;
        if (var_t4 < 0)
        {
          temp_t2 = var_t2;
          var_t2 = var_s4;
          var_s4 = *(var_s1++);
          var_a2_8 = (temp_t2 + (var_t2 << (var_t4 + temp_v1_7))) & ((1 << temp_v1_7) - 1);
          var_t2 >>= -var_t4;
          var_t4 += 0x20;
        }
        else
        {
          var_a2_8 = var_t2 & ((1 << temp_v1_7) - 1);
          var_t2 = var_t2 >> temp_v1_7;
        }
      }
      temp_a1_3 = ((u16 *) (&D_800B27E0))[temp_a1_2] + var_a2_8;
      temp_v0_5 = var_fp - temp_a1_3;
      var_v1_8 = temp_v0_5 - 1;
      if (temp_a1_3 == 0)
      {
        do
        {
          *var_fp = *((u8 *) (((char *) temp_v0_5) + (-1)));
          var_t1_8--;
          var_fp += 1;
        }
        while (var_t1_8 != 0);
        var_v0 = var_t4 < 0xF;
      }
      else
      {
        do
        {
          var_t3_3 = (u8) (*var_v1_8);
          var_v1_8 += 1;
          var_t1_8--;
          *var_fp = var_t3_3;
          var_fp += 1;
        }
        while (var_t1_8);
        var_v0 = var_t4 < 0xF;
      }
      goto loop_92;
    }
    block_123:
    var_t4 = var_t4 - 1;

    block_124:
    var_a2_10 = var_t2 & 1;

    if (var_t4 < 0)
    {
      temp_t2 = var_t2;
      var_t2 = var_s4;
      var_s4 = *(var_s1++);
      var_a2_10 = (temp_t2 + (var_t2 << (var_t4 + 1))) & 1;
      var_t2 >>= -var_t4;
      var_t4 += 0x20;
    }
    else
    {
      var_t2 = var_t2 >> 1;
    }
    if (var_a2_10 != 0)
    {
      return;
    }
    goto loop_1;
  }

  goto loop_17;
}

