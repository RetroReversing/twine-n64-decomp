s32 func_8008CEB0(s32, s32, s32);
s32 func_80096970(s32, s32);
void *func_8009852C(u32, u16 *);
s32 func_800988D8(void *);
s32 func_8009C420(u32, u16, s32, s32, s32, s32, s32, s32, s32, s32, s32);
extern u8 D_8010D738[];
extern u8 gVoiceChannelTable[];
extern u8 sVoiceTable[];
s32 func_8008D138(u32 arg0, u16 arg1, u8 arg2, int arg3, u8 arg4, u8 arg5, u8 arg6, u16 arg7, u16 arg8, u8 arg9)
{
  u16 sp30;
  u8 temp_a3;
  s32 temp_s0;
  s32 neg1;
  s32 neg2;
  s32 temp_s3;
  s32 temp_s4;
  s32 temp_s7;
  s32 temp_v0_2;
  s32 var_s2;
  s32 var_s5;
  s32 var_s6;
  s32 var_t0;
  s32 var_v0;
  s32 var_v0_2;
  s32 var_v1;
  s32 var_v1_2;
  u16 temp_v0;
  u32 temp_fp;
  u8 temp_v1_2;
  void *phase_ptr;
  s32 temp_cnt;
  s32 phase_val;
  u8 b5;
  s32 pan_ok;
  void *var_s1;
  var_s6 = -1;
  neg1 = -1;
  neg2 = -1;
  phase_ptr = func_8009852C(arg0 >> 0x10, &sp30);
  if ((phase_ptr != NULL) && ((var_s5 = 0, (s32) (temp_cnt = sp30) > 0)))
  {
    temp_fp = arg2 & 0x7F;
    temp_s3 = arg5 & 0xFF;
    temp_s4 = arg6 & 0xFF;
    temp_s7 = arg3 & 0xFF;
    var_s1 = phase_ptr;
    loop_3:
    if ((((*((u16 *) (((char *) var_s1) + 0))) != 0xFFFF) && (temp_fp >= ((u8) (*((u8 *) (((char *) var_s1) + 2)))))) && (((u8) (*((u8 *) (((char *) var_s1) + 3)))) >= temp_fp))
    {
do {
      var_v0_2 = temp_fp + (*((s8 *) (((char *) var_s1) + 4)));
} while (0);
      var_v0_2 = (var_v0_2 < 0x80) ? (var_v0_2 & (((s32) (~var_v0_2)) >> 0x1F)) : 0x7F;
do {
do {
      if (((temp_s3 == 0xFF) || (!(func_80096970(temp_s3, temp_s4) & 0xFF))) || ((var_v0 = func_8008CEB0(var_v0_2 & 0x7F, temp_s3, temp_s4), var_v0 == neg1)))
      {
        var_v0 = -1;
      }
} while (0);
} while (0);
      if (var_v0 == neg2)
      {
        temp_v1_2 = *((u8 *) (((char *) var_s1) + 8));
        var_t0 = 0x80;
        if (!(temp_v1_2 & 0x80))
        {
          var_t0 = temp_v1_2 - 0x40;
          var_t0 = arg4 + var_t0;
          if (var_t0 >= 0)
          {
            var_v1 = 0x7F;
            if (var_t0 < 0x80)
            {
              var_v1 = var_t0;
            }
          }
          else
          {
            var_v1 = 0;
          }
          var_t0 = var_v1;
        }
        b5 = (*((u8 *) (((char *) var_s1) + 5)));
do {
        temp_a3 = (temp_s7 * b5)/127;
        temp_s0 = (arg0 >> 8) & 0xFF;
        temp_s0 += (*((s16 *) (((char *) var_s1) + 6)));
        pan_ok = temp_s0 < 0x100;
} while (0);
        if (pan_ok)
        {
          var_v1_2 = temp_s0 & (((s32) (~temp_s0)) >> 0x1F);
        }
        else
        {
          var_v1_2 = 0xFF;
        }
        temp_v0 = *((u16 *) (((char *) var_s1) + 0));
        phase_val = arg0 & 0xFF;
        phase_val |= var_v1_2 << 8;
        phase_val |= temp_v0 << 0x10;
        if (!(temp_v0 & 0xC000))
        {
          if (var_s6 == neg1)
          {
            var_s2 = func_8009C420(phase_val, arg1, (var_v0_2 | (arg2 & 0x80)) & 0xFF, temp_a3, var_t0 & 0xFF, temp_s3, temp_s4, (s32) arg7, (s32) arg8, 0, (s32) arg9);
do {
            if (var_s2 != var_s6)
            {
              var_s6 = func_800988D8(((var_s2 & 0xFF) * 0x1A0) + sVoiceTable);
            }
} while (0);
          }
          else
          {
do {
            temp_v0_2 = func_8009C420(phase_val, arg1, (var_v0_2 | (arg2 & 0x80)) & 0xFF, temp_a3, var_t0 & 0xFF, temp_s3, temp_s4, (s32) arg7, (s32) arg8, 0, (s32) arg9);
} while (0);
do {
            if (temp_v0_2 != neg1)
            {
do {
              *((s32 *) (gVoiceChannelTable + ((var_s2 & 0xFF) * 0x1A0))) = temp_v0_2;
              *((s32 *) (gVoiceChannelTable + 4 + ((temp_v0_2 & 0xFF) * 0x1A0))) = var_s2;
              var_s2 = temp_v0_2;
} while (0);
            }
} while (0);
          }
        }
        goto block_29;
      }
    }
    else
    {
      block_29:
do {
do {
      var_s5 += 1;

      var_s1 += 0xC;
      if (var_s5 >= ((s32) sp30))
      {
        goto block_30;
      }
      goto loop_3;
} while (0);
} while (0);
    }

  }
  else
  {
    block_30:
do {
    var_v0 = var_s6;
} while (0);

  }
  return var_v0;
}


