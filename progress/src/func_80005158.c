s16 *findOrLoadCacheBlock(void);
s32 func_800055CC(s32 *, s32, s32, s32);
s32 func_80005A7C(s32, s32 *);
f32 func_80082908(f32);
void *heapAllocTagged(s32, s32);
void *func_80005158(s32 arg0, s32 arg1, s32 arg2)
{
  union 
  {
    u8 bytes[3168];
    struct 
    {
      s32 value;
    } view_sp10;
    struct 
    {
      u8 pad[4];
      f32 value;
    } view_sp14;
    struct 
    {
      u8 pad[16];
      s32 value;
    } view_sp20;
    struct 
    {
      u8 pad[24];
      f32 value;
    } view_sp28;
    struct 
    {
      u8 pad[28];
      f32 value;
    } view_sp2C;
    struct 
    {
      u8 pad[32];
      f32 value;
    } view_sp30;
    struct 
    {
      u8 pad[1592];
      s32 value;
    } view_sp648;
    struct 
    {
      u8 pad[1600];
      f32 value;
    } view_sp650;
    struct 
    {
      u8 pad[1604];
      f32 value;
    } view_sp654;
    struct 
    {
      u8 pad[1608];
      f32 value;
    } view_sp658;
  } m2c_initial_frame;
  s32 var_a2; s32 lim; s32 flag; int zero;
  f32 var_fv0;
  void *var_s3;
  long temp_s2;
  f32 var_fv1;
  register f32 var_fa0;
  f32 var_fs3;
  int var_s1;
  void *temp_v0;
  temp_s2 = (*findOrLoadCacheBlock()) - (arg2 != 0); temp_v0 = heapAllocTagged((temp_s2 + 3) * 4, 0x1C);
  if (temp_v0 != NULL)
  {
    var_fs3 = 0.0f; var_s1 = 0;
    zero = 0;
    if (temp_s2 > zero)
    {
      lim = temp_s2 - 1;
      flag = arg1 & 1;

      do
      {
        var_a2 = var_s1 + 1;
        if (arg2 == 0)
        {
          if (var_s1 == lim)
          {
            var_a2 = 1;
          }
        }
        {
          f32 ax;
          f32 ay;
          f32 az;
          f32 bx;
          f32 by;
          f32 bz;
          unsigned index = var_a2 - 1;
          func_800055CC(&m2c_initial_frame.view_sp20.value, arg0, var_a2, 0);
          ax = m2c_initial_frame.view_sp28.value;
          ay = m2c_initial_frame.view_sp2C.value;
          az = m2c_initial_frame.view_sp30.value;
          func_800055CC(&m2c_initial_frame.view_sp648.value, arg0, index, 0);
          bx = m2c_initial_frame.view_sp650.value;
          by = m2c_initial_frame.view_sp654.value;
          bz = m2c_initial_frame.view_sp658.value;
          var_fa0 = (var_fv0 = (var_fv1 = 0.0f));
          if (flag)
          {
            var_fa0 = ax - bx;
          }
          if (arg1 & 2)
          {
            var_fv0 = ay - by;
          }
          if (arg1 & 4)
          {
            var_fv1 = az - bz;
          }
        }
        var_fs3 += func_80082908(((var_fa0 * var_fa0) + (var_fv0 * var_fv0)) + (var_fv1 * var_fv1)); ((f32 *) temp_v0)[var_s1 + 3] = var_fs3; var_s1 += 1;
      }
      while (temp_s2 > var_s1);
    }
    *((f32 *) (((char *) temp_v0) + 0)) = var_fs3;
    *((s32 *) (((char *) temp_v0) + 4)) = temp_s2;
    func_80005A7C(arg0, &m2c_initial_frame.view_sp10.value);
    *((f32 *) (((char *) temp_v0) + 8)) = m2c_initial_frame.view_sp14.value;
  }
  return temp_v0;
}

