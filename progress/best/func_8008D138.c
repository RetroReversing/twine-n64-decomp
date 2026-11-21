s32 func_8008CEB0(s32, s32, s32);
s32 func_80096970(s32, s32);
void *func_8009852C(u32, u16 *);
s32 func_800988D8(void *);
s32 func_8009C420(volatile unsigned char, u16, s32, s32, s32, s32, s32, s32, s32, s32, s32);
extern u8 D_8010D738[];
extern u8 gVoiceChannelTable[];
extern u8 sVoiceTable[];
void func_8008D138(u32 arg0, u16 arg1, u8 arg2, volatile int arg3, u8 arg4, u8 arg5, u8 arg6, u16 arg7, u16 arg8, u8 arg9)
{
  int __repair_literal;
  u8 sp57;
  u16 sp30;
  u32 sp3C;
  u16 sp46;
  u8 sp4F;
  u16 sp66;
  u8 sp6F;
  u16 sp5E;
  short temp_a3;
  s32 temp_s0;
  s32 temp_s3;
  s32 temp_s4;
  s32 temp_v0_2;
  unsigned long var_s2;
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
  union 
  {
    void *pointer;
    s32 value;
  } __repair_phase_storage;
  void *var_s1;
  sp57 = arg4;
  sp5E = arg7;
  sp66 = arg8;
  var_s6 = -1;
  sp3C = arg0;
  sp46 = arg1;
  sp6F = arg9;
  __repair_phase_storage.pointer = func_8009852C(arg0 >> 0x10, &sp30);
  sp4F = arg2;
  __repair_literal = 0;
  if ((__repair_phase_storage.pointer != NULL) && ((var_s5 = 0, sp30 > __repair_literal)))
  {
    temp_s3 = arg5 & 0xFF;
    temp_fp = arg2 & 0x7F;
    temp_s4 = arg6 & 0xFF;
    var_s1 = __repair_phase_storage.pointer;
    loop_3:
    if ((((*((u16 *) (((char *) var_s1) + 0))) != 0xFFFF) && (temp_fp >= ((u8) (*((u8 *) (((char *) var_s1) + 2)))))) && (((u8) (*((u8 *) (((char *) var_s1) + 3)))) >= temp_fp))
    {
      temp_s0 = temp_fp + (*((s8 *) (((char *) var_s1) + 4)));
      if (0x80 > temp_s0)
      {
        var_v0_2 = temp_s0 & (((s32) (~temp_s0)) >> 0x1F);
      }
      else
      {
        u32 unused[2];
        var_v0_2 = 0x7F;
      }
      if (((temp_s3 == 0xFF) || (!(func_80096970(temp_s3, temp_s4) & 0xFF))) || ((var_v0 = func_8008CEB0(var_v0_2 & 0x7F, temp_s3, temp_s4), var_v0 == (-1))))
      {
        var_v0 = -1;
      }
      if ((var_v0 & 0xFFFF) == (-1))
      {
        temp_v1_2 = *((u8 *) (((char *) var_s1) + 8));
        var_t0 = 0x80;
        if (!(temp_v1_2 & 0x80))
        {
          temp_s0 = sp57 + (temp_v1_2 - 0x40);
          if (temp_s0 >= 0)
          {
            var_v1 = 0x7F;
            if (temp_s0 < 0x80)
            {
              var_v1 = temp_s0;
            }
          }
          else
          {
            var_v1 = 0;
          }
          var_t0 = var_v1;
        }
        temp_s0 = ((arg0 >> 8) & 0xFF) + (*((s16 *) (((char *) var_s1) + 6)));
        temp_a3 = (((*((u8 *) (((char *) var_s1) + 5))) * (arg3 & 0xFF)) / 127) & 0xFF;
        if (temp_s0 < 0x100)
        {
          var_v1_2 = temp_s0 & (((s32) (~temp_s0)) >> 0x1F);
        }
        else
        {
          var_v1_2 = 0xFF;
        }
        temp_v0 = *((u16 *) (((char *) var_s1) + 0));
        __repair_phase_storage.value = ((arg0 & 0xFF) | (var_v1_2 << 8)) | (temp_v0 << 0x10);
        if (!(temp_v0 & 0xC000))
        {
          if (var_s6 == (-1))
          {
            temp_s0 = func_8009C420(__repair_phase_storage.value, sp46, (var_v0_2 | (arg2 & 0x80)) & 0xFF, temp_a3, var_t0 & 0xFF, temp_s3, temp_s4, (s32) sp5E, (s32) sp66, 0, (s32) sp6F);
            if (temp_s0 != var_s6)
            {
              if (1)
              {
              }
              do
              {
                do
                {
                  var_s6 = func_800988D8(((temp_s0 & 0xFF) * 0x1A0) + sVoiceTable);
                }
                while (0);
              }
              while (0);
            }
          }
          else
          {
            do
            {
              temp_v0_2 = func_8009C420(__repair_phase_storage.value, sp46, (var_v0_2 | (arg2 & 0x80)) & 0xFF, temp_a3, var_t0 & 0xFF, temp_s3, temp_s4, (s32) sp5E, (s32) sp66, 0, (s32) sp6F);
            }
            while (0);
            if (temp_v0_2 != (-1))
            {
              *((s32 *) (gVoiceChannelTable + ((temp_s0 & 0xFF) * 0x1A0))) = temp_v0_2;
              *((s32 *) (D_8010D738 + ((temp_v0_2 & 0xFF) * 0x1A0))) = temp_s0;
              var_s2 = temp_v0_2;
            }
          }
        }
        goto block_29;
      }
    }
    else
    {
      block_29:
      var_s5 += 1;

      var_s1 += 0xC;
      if (var_s5 >= ((s32) sp30))
      {
        goto block_30;
      }
      goto loop_3;
    }

  }
  else
  {
    block_30:
    var_v0 = var_s6;

  }
  return var_s6;
}

