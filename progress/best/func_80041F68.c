s32 func_8000B9B8(u16 *, void *, u32);
s32 func_8000BE00(u32, s32, s32);
u32 func_8001499C(u16 *);
s32 func_80014A0C(u16 *, u16 *);
s32 func_80083E24();
s32 func_80083E44(s32);
u16 *func_80083E90(u32, s32);
s32 func_80084048(u16 *, s32);
s32 memcpy(u16 *, u16 *, u32);
extern s32 D_54D910;
extern u8 D_8010A4FC;
void func_80041F68(void *arg0)
{
  u32 imageWidth;
  u32 unusedScratch[8];
  s32 sp14;
  s32 var_a0_2;
  long temp_a0;
  union { u16 * pointer; s32 value; } __repair_phase_storage;
  
  s32 var_t0;
  u16 *temp_fp;
  u16 *sp1C;
  u16 *var_s2;
  u16 *var_s5;
  u16 *var_s7;
  u16 temp_s0;
  u32 temp_a2;
  u32 temp_v0;
  int temp_v1;
  u32 temp_v1_4;
  u32 var_a0;
  u32 __repair_phase_var_a0;
  u32 var_s0;
  u32 var_s1;
  u32 var_s1_2;
  u32 var_s1_4;
  u8 *temp_a3;
  u8 *var_a0_4;
  u8 temp_a1;
  u8 temp_v0_4;
  void *temp_a0_2;
  void *temp_v0_3;
  void *temp_v1_2;
  sp14 = func_80083E24();
  sp1C = func_80083E90((*((u32 *) (((char *) arg0) + 0x14))) * 8, 0x18);
  temp_fp = func_80083E90((*((u32 *) (((char *) arg0) + 0x1C))) * 0xC, 0x19);
  var_a0 = *((u32 *) (((char *) arg0) + 0x2C));
  temp_v1 = *((u32 *) (((char *) arg0) + 0x24));
  if (var_a0 < temp_v1)
  {
    var_a0 = temp_v1;
  }
  __repair_phase_storage.pointer = func_80083E90(var_a0, 0x2D);
  func_8000B9B8(sp1C, (*((u32 *) (((char *) arg0) + 0x10))) + ((u8 *) (&D_54D910)), (*((u32 *) (((char *) arg0) + 0x14))) * 8);
  func_8000B9B8(temp_fp, (*((u32 *) (((char *) arg0) + 0x18))) + ((u8 *) (&D_54D910)), (*((u32 *) (((char *) arg0) + 0x1C))) * 0xC);
  func_8000B9B8(__repair_phase_storage.pointer, (*((s32 *) (((char *) arg0) + 0x28))) + ((u8 *) (&D_54D910)), *((u32 *) (((char *) arg0) + 0x2C)));
  var_s0 = func_8001499C(__repair_phase_storage.pointer);
  if (var_s0 != 0)
  {
    var_s7 = func_80083E90(var_s0, 0x1A);
    func_80014A0C(var_s7, __repair_phase_storage.pointer);
  }
  else
  {
    var_s7 = func_80083E90(*((u32 *) (((char *) arg0) + 0x2C)), 0x1A);
    memcpy(var_s7, __repair_phase_storage.pointer, *((u32 *) (((char *) arg0) + 0x2C)));
  }
  func_8000B9B8(__repair_phase_storage.pointer, (*((s32 *) (((char *) arg0) + 0x20))) + ((u8 *) (&D_54D910)), *((u32 *) (((char *) arg0) + 0x24)));
  var_s0 = func_8001499C(__repair_phase_storage.pointer);
  if (var_s0 != 0)
  {
    var_s5 = func_80083E90(var_s0, 0x1B);
    func_80014A0C(var_s5, __repair_phase_storage.pointer);
  }
  else
  {
    var_s0 = *((u32 *) (((char *) arg0) + 0x24));
    var_s5 = func_80083E90(var_s0, 0x1B);
    memcpy(var_s5, __repair_phase_storage.pointer, *((u32 *) (((char *) arg0) + 0x24)));
  }
  if (D_8010A4FC != 0)
  {
    __repair_phase_var_a0 = var_s0 >> 1;
    var_s1 = 0;
    if (__repair_phase_var_a0 != 0)
    {
      var_s2 = var_s5;
      do
      {
        temp_s0 = *var_s2;
        var_s1 += 1;
        var_s1_2 = temp_s0 & 0xFFFF;
        temp_s0 &= 1;
        *var_s2 = func_8000BE00(var_s1_2 >> 0xB, (var_s1_2 >> 6) & 0x1F, (var_s1_2 >> 1) & 0x1F) + temp_s0;
        var_s2 += 1;
      }
      while (var_s1 < (var_s0 >> 1));
    }
  }
  func_80084048(__repair_phase_storage.pointer, 0x2D);
  var_s1 = 0;
  *((u16 **) (((char *) arg0) + 0x10)) = sp1C;
  *((u16 **) (((char *) arg0) + 0x18)) = temp_fp;
  if ((*((u32 *) (((char *) arg0) + 0x14))) != 0)
  {
    do
    {
      *((s32 *) (((char *) ((var_s1 * 8) + (*((u8 **) (((char *) arg0) + 0x10))))) + 4)) = (s32) ((*((s32 *) (((char *) ((var_s1 * 8) + (*((u8 **) (((char *) arg0) + 0x10))))) + 4))) * 2);
      var_t0 = (var_s1 * 8); temp_a0_2 = var_t0 + (*((u8 **) (((char *) arg0) + 0x10)));
      *((void **) (((char *) temp_a0_2) + 4)) = (void *) ((*((u32 *) (((char *) temp_a0_2) + 4))) + ((u8 *) var_s5));
      var_s1 += 1;
    }
    while (var_s1 < ((u32) (*((u32 *) (((char *) arg0) + 0x14)))));
  }
  var_s1 = 0;
  if ((*((u32 *) (((char *) arg0) + 0x1C))) != 0)
  {
    var_a0_2 = 0;
    do
    {
      temp_a0 = (*((u8 **) (((char *) arg0) + 0x18))); temp_v0_3 = var_a0_2 + temp_a0;
      *((void **) (((char *) temp_v0_3) + 8)) = (void *) ((*((u32 *) (((char *) temp_v0_3) + 8))) + ((u8 *) var_s7));
      var_s1 += 1;
      var_a0_2 += 0xC;
    }
    while (var_s1 < ((u32) (*((u32 *) (((char *) arg0) + 0x1C)))));
  }
  var_s1_4 = 0;
  if ((*((u32 *) (((char *) arg0) + 0x1C))) != 0)
  {
    var_t0 = 0;
    do
    {
      temp_a0_2 = var_t0 + (*((u8 **) (((char *) arg0) + 0x18)));
      __repair_phase_storage.value = (*((u16 *) (((char *) temp_a0_2) + 4))) + 1;
      temp_a1 = *((u8 *) (((char *) temp_a0_2) + 6));
      temp_a3 = *((u8 **) (((char *) temp_a0_2) + 8));
      imageWidth = (*((u16 *) (((char *) temp_a0_2) + 2))) + 1;
      if (temp_a1 >= 2U)
      {
        __repair_phase_storage.value *= temp_a1;
      }
      temp_v1_4 = ((u32) (__repair_phase_storage.value * imageWidth)) >> 1;
      if (!((*((u8 *) (((char *) temp_a0_2) + 0))) & 1))
      {
        if (((int) (((u32) (__repair_phase_storage.value * imageWidth)) >> 1)) != 0)
        {
          var_a0_4 = temp_a3;
          do
          {
            temp_v0_4 = *var_a0_4;
            *var_a0_4 = (temp_v0_4 >> 4) | ((temp_v0_4 & 0xF) * 0x10);
            ++var_a0_4;
          }
          while (((u32) var_a0_4) < ((u32) ((((u32) (__repair_phase_storage.value * imageWidth)) >> 1) + temp_a3)));
        }
      }
      var_s1_4 += 1;
      var_t0 += 0xC;
    }
    while (var_s1_4 < ((u32) (*((u32 *) (((char *) arg0) + 0x1C)))));
  }
  func_80083E44(sp14);
}

