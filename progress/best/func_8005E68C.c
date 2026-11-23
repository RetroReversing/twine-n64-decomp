s32 actorLinkToSurface(s32, void *, s32);
s32 effectSetAnimFrame(void *, unsigned short, int);
u8 func_80017490(u16, u16, u16);
s32 func_8001751C(s32, u8, void *, s32);
void *spawnEffectObject(s32, void *, s32);
extern s16 D_800C4478;
extern short D_800C447A;
extern s16 D_800C4706;
extern s16 D_800C4708;
extern s32 *gProbeObjectList;
typedef struct 
{
  s32 w[3];
} __repair_words3;
typedef struct 
{
  unsigned char pad_0[12];
  int field_C;
  int field_10;
  int field_14;
  unsigned char pad_18[4];
  float field_1C;
  unsigned char pad_20[4];
  unsigned short field_24;
  unsigned short field_26;
  unsigned short field_28;
  unsigned short field_2A;
  unsigned char pad_2C[1];
  signed char field_2D;
  signed char field_2E;
  signed char field_2F;
  short field_30;
} __repair_record_temp_s0;
void *func_8005E68C(void *arg0, s32 arg1, u16 arg2, u16 arg3, u16 arg4, u16 arg5, u16 arg6, u16 arg7, u16 arg8, u16 arg9, short arg10, u16 arg11, s32 arg12, u8 arg13)
{
  u16 sp16;
  u16 sp1E;
  u16 sp26;
  int var_a1;
  unsigned int var_a2;
  s32 temp_v0_2;
  s32 temp_v0_3;
  void *temp_s0;
  void *temp_v0;
  sp16 = arg2;
  sp26 = arg6;
  func_8001751C(arg12, arg13, arg0, arg1);
  if ((func_80017490(arg7, arg8, arg9) << 0x18) != 0)
  {
    temp_v0 = spawnEffectObject(0x34, arg0, arg1);
    if (temp_v0 != NULL)
    {
      temp_s0 = *((void **) (((char *) temp_v0) + 0x6C));
      *((s16 *) (((char *) temp_v0) + 0x78)) = 0x24;
      *((s16 *) (((char *) temp_v0) + 0x7A)) = 0;
      *((__repair_words3 *) (((char *) temp_s0) + 0x0)) = *((__repair_words3 *) (((s8 *) arg0) + 0x0));
      ((__repair_record_temp_s0 *) temp_s0)->field_C = 0;
      ((__repair_record_temp_s0 *) temp_s0)->field_10 = 0;
      ((__repair_record_temp_s0 *) temp_s0)->field_14 = 0;
      ((__repair_record_temp_s0 *) temp_s0)->field_24 = arg11;
      ((__repair_record_temp_s0 *) temp_s0)->field_2F = 1;
      if (arg10 & 2)
      {
        ((__repair_record_temp_s0 *) temp_s0)->field_2D = 1;
      }
      else
      {
        ((__repair_record_temp_s0 *) temp_s0)->field_2D = 0;
      }
      if (arg10 & 1)
      {
        switch (arg4)
        {
          do
          {
            case 0:
              temp_v0_2 = (arg5 & 0xFFFF) * 0xE8;

            var_a1 = *((s16 *) (((u8 *) (&D_800C4706)) + temp_v0_2)); var_a2 = *((s16 *) (((u8 *) (&D_800C4708)) + temp_v0_2));
            goto block_17;
          }
          while (0);
          case 1:
            temp_v0_3 = arg5 * 0x10;
            var_a1 = *((s16 *) (((u8 *) (&D_800C4478)) + temp_v0_3));
            var_a2 = *((s16 *) (((u8 *) (&D_800C447A)) + temp_v0_3));
            goto block_17;

          case 2:
            goto direct;

        }

      }
      else
      {
        direct:
        var_a1 = arg2;

        var_a2 = arg3 & 0xFFFF;
        block_17:
        effectSetAnimFrame(temp_v0, var_a1, var_a2);

      }
      ((__repair_record_temp_s0 *) temp_s0)->field_26 = sp1E;
      ((__repair_record_temp_s0 *) temp_s0)->field_28 = arg5;
      ((__repair_record_temp_s0 *) temp_s0)->field_2A = arg6;
      ((__repair_record_temp_s0 *) temp_s0)->field_30 = 0;
      actorLinkToSurface(*gProbeObjectList, temp_v0, 1);
 *((s32 *) (((char *) temp_v0) - (-0x5C))) = (s32) ((*((s32 *) (((char *) temp_v0) + 0x5C))) | 0x400); *((f32 *) (((char *) temp_v0) + 0x54)) = 0.015625f; ((__repair_record_temp_s0 *) temp_s0)->field_1C = (f32) ((*((f32 *) (((char *) temp_v0) + 0x28))) - 1.0f);
      if (((((u32) ((short) (arg5 - 0x18))) < 2U) | (arg5 == 0x17)) != 0)
      {
        ((__repair_record_temp_s0 *) temp_s0)->field_2E = 1;
      }
      else
        if (arg4)
      {
        ((__repair_record_temp_s0 *) temp_s0)->field_2E = 0;
      }
      else
      {
        ((__repair_record_temp_s0 *) temp_s0)->field_2E = 0;
      }
      *((s16 *) (((char *) temp_v0) + 0x7A)) = 2;
    }
    return temp_v0;
  }
  return NULL;
}
