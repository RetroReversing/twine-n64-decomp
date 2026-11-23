s32 func_800326BC();
s32 func_80032830();
extern s8 D_80109A94;
extern void *gGfxPtr;
typedef struct 
{
  unsigned char pad[12];
  int value;
} __repair_field_C;
void func_80032978(void *arg0, u32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 *arg5)
{
  unsigned short width_log;
  u8 sp17;
  s32 sp1C;
  s32 __repair_phase_sp1C;
  s32 temp_a0_3;
  s32 temp_a0_6;
  s32 temp_a2;
  s32 temp_a2_2;
  s32 temp_a2_3;
  register s32 temp_a3;
  s32 temp_s0;
  s32 temp_s0_2;
  s32 temp_s0_3;
  s32 temp_s0_4;
  s32 __repair_phase_temp_s0_4;
  s32 temp_s0_5;
  s32 temp_s0_6;
  s32 temp_s0_7;
  s32 temp_s6;
  s32 temp_s7;
  s32 temp_v0_2;
  s32 temp_v1_2;
  s32 temp_v1_3;
  s32 var_a2;
  s32 var_v0_2;
  s32 var_v0_4;
  unsigned var_v0_5;
  s32 var_v0_6;
  s32 var_v1_4;
  s32 __repair_phase_var_v1_4;
  u32 temp_a0;
  u32 temp_a0_4;
  u32 temp_a0_7;
  u32 temp_a0_9;
  u32 temp_s2;
  u32 temp_s3;
  u32 var_a0;
  u32 var_a3;
  u32 var_a3_2;
  u32 var_a3_3;
  u32 var_a3_4;
  u32 var_v1;
  u32 var_v1_2;
  u32 var_v1_5;
  long var_v1_6;
  u8 temp_v1;
  void *temp_a0_2;
  void *temp_a0_5;
  void *temp_a0_8;
  void *temp_a1;
  void *temp_a1_2;
  void *temp_a1_3;
  void *temp_s1;
  void *temp_s1_2;
  void *temp_s1_3;
  void *temp_s1_4;
  void *temp_s1_5;
  void *temp_s1_6;
  void *temp_v0;
  s32 var_a1;
  temp_v1_3 = ((*((u8 *) (((char *) arg0) + 1))) * 0xC); temp_a1 = temp_v1_3 + arg2;
  temp_v0_2 = (u8) (*((u8 *) (((char *) temp_a1) + 0)));
  sp17 = (u8) arg4;
  temp_s7 = (-((temp_v0_2 & 2) != 0)) & 3;
  temp_s6 = (-((temp_v0_2 & 4) != 0)) & 3;
  if (((arg4 << 0x18) != 0) && ((*((u8 *) (((char *) temp_a1) + 6))) != 1))
  {
    D_80109A94 = 1;
    func_800326BC(arg2 + ((*((u8 *) (((char *) arg0) + 1))) * 0xC));
  }
  temp_v0 = ((*((u8 *) (((char *) arg0) + 1))) * 0xC) + arg2;
  temp_s2 = (*((u16 *) (((char *) temp_v0) + 2))) + 1;
  temp_s3 = (*((u16 *) (((char *) temp_v0) + 4))) + 1;
  __repair_phase_sp1C = *((s32 *) (((char *) temp_v0) + 8));
  switch (arg1)
  {
    case 0:
      break;

    case 1:

    case 2:

    case 3:

    case 4:

    case 7:

    case 8:

    case 10:

    case 12:

    case 13:

    case 14:

    case 16:
      if ((*((u8 *) (((*((u8 *) (((char *) arg0) + 1))) * 0xC) + arg2))) & 1)
    {
      if ((sp17 << 0x18) != 0)
      {
        temp_s1 = gGfxPtr;
        gGfxPtr = temp_s1 + 8;
        *((s32 *) (((char *) temp_s1) + 0)) = 0xFD500000;
        *((s32 *) (((char *) temp_s1) + 4)) = (s32) (__repair_phase_sp1C & (~7));
        gGfxPtr = temp_s1 + 0x10;
        *((s32 *) (((char *) temp_s1) + 8)) = 0xF5500000;
        temp_s0 = func_80032830(temp_s3);
        width_log = func_80032830(temp_s2);
        var_a3 = 0x800;
        { u32 mask = (temp_s6 << 18); u32 height = ((temp_s0 & 15) << 14) | 0x07000000; u32 tile = (mask | height) | (temp_s7 << 8);
        ((__repair_field_C *) temp_s1)->value = tile | ((width_log & 15) << 4); }
        temp_a0 = temp_s2 >> 3;
        temp_a1_2 = gGfxPtr;
        gGfxPtr = temp_a1_2 + 8;
        *((s32 *) (((char *) temp_a1_2) + 0)) = 0xE6000000;
        gGfxPtr = temp_a1_2 + 0x10;
        *((s32 *) (((char *) temp_a1_2) + 4)) = 0;
        *((s32 *) (((char *) temp_a1_2) + 8)) = 0xF3000000;
        if (temp_a0 != 0)
        {
          var_a3 = temp_a0 + 0x7FF;
        }
        var_v1 = (((u32) ((temp_s2 * temp_s3) + 1)) >> 1) - 1;
        if (var_v1 >= 0x800U)
        {
          var_v1 = 0x7FF;
        }
        temp_a2 = ((var_v1 & 0xFFF) << 0xC) | 0x07000000;
        if (temp_a0 != 0)
        {
          s32 var_v0_a1;
          var_v0_a1 = (var_a3 / temp_a0) & 0xFFF;
          ((__repair_field_C *) temp_a1_2)->value = (s32) (temp_a2 | var_v0_a1);
        }
        else
        {
          s32 var_v0_a2;
          var_v0_a2 = var_a3 & 0xFFF;
          ((__repair_field_C *) temp_a1_2)->value = (s32) (temp_a2 | var_v0_a2);
        }
        temp_s1_2 = gGfxPtr;
        gGfxPtr = temp_s1_2 + 8;
        *((s32 *) (((char *) temp_s1_2) + 0)) = 0xE7000000;
        gGfxPtr = temp_s1_2 + 0x10;
        *((s32 *) (((char *) temp_s1_2) + 4)) = 0;
        *((s32 *) (((char *) temp_s1_2) + 8)) = (s32) ((((((u32) (temp_s2 + 7)) >> 3) & 0x1FF) << 9) | 0xF5480000);
        temp_s0_2 = func_80032830(temp_s3);
        width_log = func_80032830(temp_s2);
        ((__repair_field_C *) temp_s1_2)->value = (s32) ((((((unsigned) temp_s6) << 0x12) | ((temp_s0_2 & 0xF) << 0xE)) | (temp_s7 << 8)) | ((width_log & 0xF) * 0x10));
        temp_a0_2 = gGfxPtr;
        gGfxPtr = temp_a0_2 + 8;
        *((s32 *) (((char *) temp_a0_2) + 0)) = 0xF2000000;
        *((s32 *) (((char *) temp_a0_2) + 4)) = (s32) (((((temp_s2 - 1) * 4) & 0xFFF) << 0xC) | (((temp_s3 - 1) * 4) & 0xFFF));
      }
      else
      {
        *arg5 += 7;
      }
      if (!((*((u8 *) (((*((u8 *) (((char *) arg0) + 1))) * 0xC) + arg2))) & 1))
      {
        s32 temp_v0_2_a1;
        temp_v0_2_a1 = temp_s7 == 0; goto block_17;
      }
    }
    else
    {
      s32 temp_v0_2_a2;
      temp_v0_2_a2 = temp_s7 == 0;
block_17:

      if ((sp17 << 0x18) != 0)
      {
        var_a1 = 0;
        var_a2 = 0;
        if ((temp_s7 == 0) & (temp_s6 == 0))
        {
          if ((temp_s2 == 0x40) && (temp_s3 == 0x40))
          { var_a1 = 1; var_a2 = 5; }
          else if ((temp_s2 == 0x20) && (temp_s3 == 0x80))
          { var_a1 = 1; var_a2 = 4; }
          else if ((temp_s2 == 0x80) && (temp_s3 == 0x20))
          { var_a1 = 1; var_a2 = 3; }
          else if ((temp_s2 == 0x20) && (temp_s3 == 0x40))
          { var_a1 = 1; var_a2 = 2; }
          else if ((temp_s2 == 0x20) && (temp_s3 == 0x20))
          { var_a1 = 1; var_a2 = 1; }
        }
        temp_s1_3 = gGfxPtr;
        gGfxPtr = temp_s1_3 + 8;
        *((s32 *) (((char *) temp_s1_3) + 0)) = 0xFD500000;
        *((s32 *) (((char *) temp_s1_3) + 4)) = __repair_phase_sp1C;
        if (((s8) var_a1) != 0)
        {
          u32 var_a1_2_a1;
          s32 var_a2_2_a1;
          var_v1_2 = 0x800;
          gGfxPtr = temp_s1_3 + 0x10;
          *((s32 *) (((char *) temp_s1_3) + 8)) = 0xE6000000;
          gGfxPtr = temp_s1_3 + 0x18;
          var_a1_2_a1 = temp_s2 >> 4;
          ((__repair_field_C *) temp_s1_3)->value = 0;
          *((s32 *) (((char *) temp_s1_3) + 0x10)) = 0xF3000000;
          if (var_a1_2_a1)
          {
            var_v1_2 = var_a1_2_a1 + 0x7FF;
          }
          var_a0 = (((u32) ((temp_s2 * temp_s3) + 3)) >> 2) - 1;
          var_a2_2_a1 = var_a2 << 0x18;
          if (var_a0 >= 0x800U)
          {
            var_a0 = 0x7FF;
          }
          var_a0 = var_a2_2_a1 | ((var_a0 & 0xFFF) << 0xC);
          if (var_a1_2_a1)
          {
            var_v0_2 = (var_v1_2 / var_a1_2_a1) & 0xFFF;
          }
          else
          {
            var_v0_2 = var_v1_2 & 0xFFF;
          }
          *((s32 *) (((char *) temp_s1_3) + 0x14)) = var_a0 | var_v0_2;
        }
        else
        {
          u32 var_a1_2_a2;
          s32 var_a2_2_a2;
          gGfxPtr = temp_s1_3 + 0x10;
          *((s32 *) (((char *) temp_s1_3) + 8)) = 0xF5500000;
          temp_s0_3 = func_80032830(temp_s3);
          width_log = func_80032830(temp_s2);
          var_a3_2 = 0x800;
          { u32 mask = (temp_s6 << 18); u32 height = ((temp_s0_3 & 15) << 14) | 0x07000000; u32 tile = (mask | height) | (temp_s7 << 8);
          ((__repair_field_C *) temp_s1_3)->value = tile | ((width_log & 15) << 4);
          var_a1_2_a2 = (u32) gGfxPtr; }
          temp_a0_4 = temp_s2 >> 4;
          gGfxPtr = var_a1_2_a2 + 8;
          *((s32 *) (((char *) var_a1_2_a2) + 0)) = 0xE6000000;
          gGfxPtr = var_a1_2_a2 + 0x10;
          *((s32 *) (((char *) var_a1_2_a2) + 4)) = 0;
          *((s32 *) (((char *) var_a1_2_a2) + 8)) = 0xF3000000;
          if (temp_a0_4 != 0)
          {
            var_a3_2 = temp_a0_4 + 0x7FF;
          }
          var_v1_2 = (((u32) ((temp_s2 * temp_s3) + 3)) >> 2) - 1;
          if (var_v1_2 >= 0x800U)
          {
            var_v1_2 = 0x7FF;
          }
          var_a2_2_a2 = ((var_v1_2 & 0xFFF) << 0xC) | 0x07000000;
          if (temp_a0_4 != 0)
          {
            var_v0_2 = (var_a3_2 / temp_a0_4) & 0xFFF;
          }
          else
          {
            var_v0_2 = ((u32) var_a3_2) & 0xFFF;
          }
          ((__repair_field_C *) var_a1_2_a2)->value = (s32) (var_a2_2_a2 | var_v0_2);
        }
        var_v1_4 = 0xF5400000;
        temp_s1_3 = gGfxPtr;
        gGfxPtr = temp_s1_3 + 8;
        *((s32 *) (((char *) temp_s1_3) + 0)) = 0xE7000000;
        gGfxPtr = temp_s1_3 + 0x10;
        *((s32 *) (((char *) temp_s1_3) + 4)) = 0;
        *((s32 *) (((char *) temp_s1_3) + 8)) = (s32) ((((((u32) ((temp_s2 >> 1) + 7)) >> 3) & 0x1FF) << 9) | var_v1_4);
        temp_s0_4 = func_80032830(temp_s3);
        width_log = func_80032830(temp_s2);
        temp_a0_5 = gGfxPtr;
        ((__repair_field_C *) temp_s1_3)->value = (s32) ((((temp_s6 << 0x12) | ((temp_s0_4 & 0xF) << 0xE)) | (temp_s7 << 8)) | ((width_log & 0xF) * 0x10));
        gGfxPtr = temp_a0_5 + 8;
        *((s32 *) (((char *) temp_a0_5) + 0)) = 0xF2000000;
        *((s32 *) (((char *) temp_a0_5) + 4)) = (s32) (((((temp_s2 - 1) * 4) & 0xFFF) << 0xC) | (((temp_s3 - 1) * 4) & 0xFFF));
        return;
      }
      var_a1 = 0;
      if ((temp_s7 == 0) & (temp_s6 == 0))
      {
          if ((temp_s2 == 0x40) && (temp_s3 == 0x40))
          { var_a1 = 1; }
          else if ((temp_s2 == 0x20) && (temp_s3 == 0x80))
          { var_a1 = 1; }
          else if ((temp_s2 == 0x80) && (temp_s3 == 0x20))
          { var_a1 = 1; }
          else if ((temp_s2 == 0x20) && (temp_s3 == 0x40))
          { var_a1 = 1; }
          else if ((temp_s2 == 0x20) && (temp_s3 == 0x20))
          { var_a1 = 1; }
      }
      if (((s8) var_a1) == 0)
      {
        *arg5 += 1;
      }
      var_v0_5 = (*arg5) + 6;
      block_81:
      *arg5 = var_v0_5;

      default:
        return;

    }
      break;

    case 5:

    case 6:

    case 9:

    case 15:
      if ((*((u8 *) (((*((u8 *) (((char *) arg0) + 1))) * 0xC) + arg2))) & 1)
    {
      if ((sp17 << 0x18) != 0)
      {
        temp_s1_4 = gGfxPtr;
        gGfxPtr = temp_s1_4 + 8;
        *((s32 *) (((char *) temp_s1_4) + 0)) = 0xFD900000;
        *((s32 *) (((char *) temp_s1_4) + 4)) = (s32) (__repair_phase_sp1C & (~7));
        gGfxPtr = temp_s1_4 + 0x10;
        *((s32 *) (((char *) temp_s1_4) + 8)) = 0xF5900000;
        temp_s0_5 = func_80032830(temp_s3);
        width_log = func_80032830(temp_s2);
        var_a3_3 = 0x800;
        { u32 mask = (temp_s6 << 18); u32 height = ((temp_s0_5 & 15) << 14) | 0x07000000; u32 tile = (mask | height) | (temp_s7 << 8);
        ((__repair_field_C *) temp_s1_4)->value = tile | ((width_log & 15) << 4);
        temp_a1_3 = gGfxPtr; }
        temp_a0_7 = temp_s2 >> 3;
        gGfxPtr = temp_a1_3 + 8;
        *((s32 *) (((char *) temp_a1_3) + 0)) = 0xE6000000;
        gGfxPtr = temp_a1_3 + 0x10;
        *((s32 *) (((char *) temp_a1_3) + 4)) = 0;
        *((s32 *) (((char *) temp_a1_3) + 8)) = 0xF3000000;
        if (temp_a0_7 != 0)
        {
          var_a3_3 = temp_a0_7 + 0x7FF;
        }
        var_v1_5 = (((u32) ((temp_s2 * temp_s3) + 1)) >> 1) - 1;
        if (var_v1_5 >= 0x800U)
        {
          var_v1_5 = 0x7FF;
        }
        temp_a2_3 = ((var_v1_5 & 0xFFF) << 0xC) | 0x07000000;
        if (temp_a0_7 != 0)
        {
          var_v0_6 = (var_a3_3 / temp_a0_7) & 0xFFF;
        }
        else
        {
          var_v0_6 = var_a3_3 & 0xFFF;
        }
        ((__repair_field_C *) temp_a1_3)->value = (s32) (temp_a2_3 | var_v0_6);
        temp_s1_5 = gGfxPtr;
        gGfxPtr = temp_s1_5 + 8;
        *((s32 *) (((char *) temp_s1_5) + 0)) = 0xE7000000;
        gGfxPtr = temp_s1_5 + 0x10;
        *((s32 *) (((char *) temp_s1_5) + 4)) = 0;
        *((s32 *) (((char *) temp_s1_5) + 8)) = (s32) ((((((u32) (temp_s2 + 7)) >> 3) & 0x1FF) << 9) | 0xF5880000);
        width_log = func_80032830(temp_s2);
        temp_s0_6 = func_80032830(temp_s3);
        temp_a0_8 = gGfxPtr;
        gGfxPtr = temp_a0_8 + 8;
        ((__repair_field_C *) temp_s1_5)->value = (s32) ((((temp_s6 << 0x12) | ((temp_s0_6 & 0xF) << 0xE)) | (temp_s7 << 8)) | ((width_log & 0xF) * 0x10));
        *((s32 *) (((char *) temp_a0_8) + 0)) = 0xF2000000;
        *((s32 *) (((char *) temp_a0_8) + 4)) = (s32) (((((temp_s2 - 1) * 4) & 0xFFF) << 0xC) | (((temp_s3 - 1) * 4) & 0xFFF));
      }
      else
      {
        *arg5 += 7;
      }
      if (!((*((u8 *) (((*((u8 *) (((char *) arg0) + 1))) * 0xC) + arg2))) & 1))
      {
        goto block_70;
      }
    }
    else
    {
      block_70:
      if ((sp17 << 0x18) != 0)
      {
        u32 var_a1_2_a3;
        s32 var_a2_2_a3;
        temp_s1_6 = gGfxPtr;
        gGfxPtr = temp_s1_6 + 8;
        *((s32 *) (((char *) temp_s1_6) + 0)) = 0xFD900000;
        *((s32 *) (((char *) temp_s1_6) + 4)) = (s32) (__repair_phase_sp1C & (~7));
        gGfxPtr = temp_s1_6 + 0x10;
        *((s32 *) (((char *) temp_s1_6) + 8)) = 0xF5900000;
        temp_s0_7 = func_80032830(temp_s3);
        width_log = func_80032830(temp_s2);
        var_a3_4 = 0x800;
        { u32 mask = (temp_s6 << 18); u32 height = ((temp_s0_7 & 15) << 14) | 0x07000000; u32 tile = (mask | height) | (temp_s7 << 8);
        ((__repair_field_C *) temp_s1_6)->value = tile | ((width_log & 15) << 4);
        var_a1_2_a3 = (u32) gGfxPtr; }
        temp_a0_9 = temp_s2 >> 4;
        gGfxPtr = var_a1_2_a3 + 8;
        *((s32 *) (((char *) var_a1_2_a3) + 0)) = 0xE6000000;
        gGfxPtr = var_a1_2_a3 + 0x10;
        *((s32 *) (((char *) var_a1_2_a3) + 4)) = 0;
        *((s32 *) (((char *) var_a1_2_a3) + 8)) = 0xF3000000;
        if (temp_a0_9 != 0)
        {
          var_a3_4 = temp_a0_9 + 0x7FF;
        }
        var_v1_6 = (((u32) ((temp_s2 * temp_s3) + 3)) >> 2) - 1;
        if (var_v1_6 >= 0x800U)
        {
          var_v1_6 = 0x7FF;
        }
        var_a2_2_a3 = ((var_v1_6 & 0xFFF) << 0xC) | 0x07000000;
        if (temp_a0_9 != 0)
        {
          s32 var_v0_7_a1;
          var_v0_7_a1 = (var_a3_4 / temp_a0_9) & 0xFFF;
          ((__repair_field_C *) var_a1_2_a3)->value = (s32) (var_a2_2_a3 | var_v0_7_a1);
        }
        else
        {
          s32 var_v0_7_a2;
          var_v0_7_a2 = var_a3_4 & 0xFFF;
          ((__repair_field_C *) var_a1_2_a3)->value = (s32) (var_a2_2_a3 | var_v0_7_a2);
        }
        __repair_phase_var_v1_4 = 0xF5800000;
        temp_s1_3 = gGfxPtr;
        gGfxPtr = temp_s1_3 + 8;
        *((s32 *) (((char *) temp_s1_3) + 0)) = 0xE7000000;
        gGfxPtr = temp_s1_3 + 0x10;
        *((s32 *) (((char *) temp_s1_3) + 4)) = 0;
        *((s32 *) (((char *) temp_s1_3) + 8)) = (s32) ((((((u32) ((temp_s2 >> 1) + 7)) >> 3) & 0x1FF) << 9) | ((unsigned) __repair_phase_var_v1_4));
        __repair_phase_temp_s0_4 = func_80032830(temp_s3);
        width_log = func_80032830(temp_s2);
        temp_a0_5 = gGfxPtr;
        ((__repair_field_C *) temp_s1_3)->value = (s32) ((((temp_s6 << 0x12) | ((__repair_phase_temp_s0_4 & 0xF) << 0xE)) | (temp_s7 << 8)) | ((width_log & 0xF) * 0x10));
        gGfxPtr = temp_a0_5 + 8;
        *((s32 *) (((char *) temp_a0_5) + 0)) = 0xF2000000;
        *((s32 *) (((char *) temp_a0_5) + 4)) = (s32) (((((temp_s2 - 1) * 4) & 0xFFF) << 0xC) | (((temp_s3 - 1) * 4) & 0xFFF));
        return;
      }

      *(volatile s32 *) arg5 += 7;
      return;
    }
      break;

  }

}
