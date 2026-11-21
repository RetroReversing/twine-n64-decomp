void *findOrLoadCacheBlock(s32);
void romDmaRead(s32, s32, u32);
extern s16 D_800C3928[];
extern f64 D_800D2008;
extern s32 (*D_800D9424)(f32 *, void *);
extern char D_000F8D70[];
inline static int inline_fn(s32 arg0, int arg1)
{
  return arg0 > arg1;
}

void func_800055CC(s32 *arg0, u32 arg1, u32 arg2, s32 arg3)
{
  volatile f32 sp10[3];
  volatile u32 frame_reserve[6];
  f32 temp_fv1;
  f64 temp_fs0;
  f64 var_fv0;
  f64 var_fv0_2;
  f64 var_fv0_3;
  s16 temp_a0;
  int temp_s4;
  s32 var_s5;
  s32 temp_a0_2;
  s32 temp_fp;
  s32 temp_s0;
  s32 temp_v0_3;
  s32 temp_v0_4;
  s32 var_s0;
  s32 var_s1;
  s32 var_s1_2;
  s32 var_s6;
  s32 var_v0;
  s32 var_v1;
  s32 __repair_var_v1_1;
  u32 temp_v0_2;
  u32 temp_v1;
  u32 var_a0;
  void *temp_a1;
  void *temp_s3;
  void *temp_v0;
  register void *var_a0_2;
  void *var_v1_2;
  var_a0 = arg1;
  if (var_a0 >= 0x40b)
  {
    var_a0 = 0x71;
  }
  temp_v0 = findOrLoadCacheBlock(var_a0); arg2 &= -(arg2 < ((u32) (*((s16 *) ((char *) temp_v0))))); var_v1 = (s16) (*((s16 *) (((char *) temp_v0) + 2))); temp_s4 = *((s16 *) (((char *) D_800C3928) + ((var_v1 & 0x7fff) * 8))); var_s1_2 = var_v1 & 0x8000; __repair_var_v1_1 = temp_s4 << 16;
  if (var_s1_2)
  {
    var_s6 = temp_s4 * 3;
    if (arg3)
    {
      __repair_var_v1_1 |= 3;
    }
    else
    {
      __repair_var_v1_1 |= 2;
    }
  }
  else
  {
    var_s6 = 3;
    if (arg3)
    {
      __repair_var_v1_1 |= 1;
    }
  }
  *arg0 = __repair_var_v1_1; temp_s3 = ((s8 *) arg0) + 8; var_s5 = 1; temp_fp = var_s6 + temp_s4;
  if (var_s1_2)
  {
    var_s5 = temp_s4;
  }
  temp_s0 = var_s5 * 6; var_s1 = 0; temp_a0_2 = arg2 & (-(arg2 < ((u32) (*((s16 *) ((char *) temp_v0))))));
  romDmaRead((s32) (((s8 *) arg0) + 8), (((*((s32 *) (((char *) temp_v0) + 4))) + ((((var_s5 * 3) + (temp_s4 * 2)) * temp_a0_2) * 2)) - temp_s0) + ((s32) D_000F8D70), temp_fp * 4);
  if (inline_fn(var_s5, 0))
  {
    var_a0_2 = temp_s3; var_v1_2 = temp_s3 + temp_s0;
    do
    {
      do
      {
        do
        {
          *((f32 *) ((char *) var_a0_2)) = (((f32) (*((u16 *) ((char *) var_v1_2)))) * (*((f32 *) (((char *) temp_v0) + 8)))) + (*((f32 *) (((char *) temp_v0) + 0x14)));
          *((f32 *) (((char *) var_a0_2) + 4)) = (((f32) (*((u16 *) (((char *) var_v1_2) + 2)))) * (*((f32 *) (((char *) temp_v0) + 0xc)))) + (*((f32 *) (((char *) temp_v0) + 0x18))); temp_fv1 = (((f32) (*((u16 *) (((char *) var_v1_2) + 4)))) * (*((f32 *) (((char *) temp_v0) + 0x10)))) + (*((f32 *) (((char *) temp_v0) + 0x1c)));
          var_s1++;
          var_v1_2 += 6;
          *((f32 *) (((char *) var_a0_2) + 8)) = temp_fv1; var_a0_2 += 0xc;
        }
        while (var_s1 < var_s5);
      }
      while (0);
    }
    while (0);
  }
  if (arg3)
  {
    var_s1_2 = 0;
    if (temp_s4 > 0)
    {
      temp_fs0 = D_800D2008; var_s0 = var_s6 + temp_s4; var_v0 = var_s6;
      do
      {
        temp_v1 = *((u32 *) ((var_v0 * 4) + temp_s3)); temp_v0_2 = (temp_v1 >> 22) * 4U; var_fv0 = (f64) ((s32) temp_v0_2);
        if (((s32) temp_v0_2) < 0)
        {
          var_fv0 += temp_fs0;
        }
        sp10[0] = (f32) var_fv0; temp_v0_2 = (temp_v1 >> 10) & 0xffeU; var_fv0_2 = (f64) ((s32) temp_v0_2);
        if (((s32) temp_v0_2) < 0)
        {
          var_fv0_2 += temp_fs0;
        }
        sp10[1] = (f32) var_fv0_2; temp_v0_2 = (temp_v1 * 2U) & 0xffeU; var_fv0_3 = (f64) ((s32) temp_v0_2);
        if (((s32) temp_v0_2) < 0)
        {
          var_fv0_3 += temp_fs0;
        }
        temp_a1 = temp_s3 + (var_s0 * 4); var_s0 += 4;
        var_s1_2++;
        sp10[2] = (f32) var_fv0_3;
        D_800D9424(sp10, temp_a1);
        var_v0 = var_s6 + var_s1_2;
      }
      while (var_s1_2 < temp_s4);
    }
  }
}

