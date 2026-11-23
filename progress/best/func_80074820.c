inline static s8 __repair_inline(s8 a)
{
  return a;
}

s32 func_80073AF8(s32, s32, s8 *, s32, s32, s32, s32, s32, s32, s32, s32);
s32 func_80074788(s8 *, s32);
volatile unsigned int func_800AB6C0(s8 *, s8 *);
volatile unsigned int memcpy(s8 *, s8 *, s32);
extern s8 D_800D4870;
extern void *D_80100B20;
extern u16 D_80112EBC;
extern s32 gTrackMarkerSerial;
inline static s8 inline_fn(char arg0)
{
  return (s8) arg0;
}

inline static int inline_fn2(s32 arg0, s32 arg1)
{
  return arg0 | (arg1 == '\n');
}

inline static s8 inline_fn23(u8 arg0)
{
  return inline_fn(arg0);
}

inline static int inline_fn234(s32 arg0, s32 arg1)
{
  return arg0 >= arg1;
}

void func_80074820(s32 arg0, u8 *arg1, s32 arg2, s32 arg3, f32 arg4, s32 arg5)
{
  char sp30[0x200];
  s8 sp230[0x208];
  f32 var_fv1;
  s16 count;
  union 
  {
    s32 *pointer;
    s32 value;
  } __repair_phase_storage;
  s32 temp_s0;
  s32 temp_v0_3;
  s32 var_a2;
  s32 var_a0_2;
  s32 var_a3;
  s32 var_t1;
  s8 *temp_a1;
  s8 *var_s1;
  s8 *var_t0;
  s8 temp_v0;
  s32 temp_v0_2;
  s32 var_v0;
  u8 *var_s0;
  u8 var_a0;
  char var_v1;
  char current;
  void **var_a0_3;
  void *temp_v0_4;
  void *temp_v0_5;
  var_s0 = arg1;
  sp230[0] = 0;
  var_a0 = *var_s0;
  if (inline_fn23(*var_s0) != 0)
  {
    do
    {
      var_t0 = sp30;
      var_t1 = 0;
      var_a3 = 0;
      var_v1 = var_a0;
      if (var_a0 != 0)
      {
        for (;;)
        {
          current = var_v1;
          if (current != 0)
          {
            var_a2 = 0;
            if ((((inline_fn(var_v1) == 0x2E) | (inline_fn23(var_v1) == 0x21)) != 0) || (((s8) var_v1) == 0x3F))
            {
              var_a2 = 1;
            }
            if (var_t1 != 0)
            {
              var_s0 += 1;
              if (var_a2 != 0)
              {
                goto block_14;
              }
              else
              {
              }
            }
            else
            {
              if (var_a2 != 0)
              {
                if (var_a3 < (arg2 / 2))
                {
                  goto copy_next;
                }
                var_t1 = 1;
              }
              copy_next:
              var_s0 += 1;

              block_14:
              *var_t0 = current;

              var_v1 = *var_s0;
              var_t0 += 1;
              var_a3 += 1;
              if (var_v1 != 0)
              {
                continue;
              }
            }
          }
          break;
        }

      }
      *var_t0 = 0;
      func_80074788(sp30, arg2);
      if (sp230[0] != 0)
      {
        func_800AB6C0(sp230, &D_800D4870);
      }
      func_800AB6C0(sp230, sp30);
      var_a0 = (u8) (*var_s0);
    }
    while ((*((s8 *) var_s0)) != 0);
  }
  D_80112EBC = 0;
  var_s1 = sp230;
  if (sp230[0] != 0)
  {
    s8 *buffer = sp30;
    while (*var_s1 != 0)
    {
      var_a0_2 = 0;
      var_v0 = *var_s1;
      temp_a1 = var_s1;
      if (inline_fn2(var_v0 == 0, var_v0) == 0)
      {
        goto scan;
      }
      goto advance;
      emit:
      temp_s0 = var_s1 - temp_a1;

      memcpy(buffer, temp_a1, temp_s0);
      buffer[temp_s0] = 0;
      gTrackMarkerSerial++;
      temp_v0_3 = func_80073AF8(0, arg0, buffer, -1, -1, 1, 0, 0, arg5 & 0xFF, 0, 0x1E);
      {
        u16 index = D_80112EBC;
        s32 *entries = (s32 *) (&D_80100B20);
        u16 next = index + 1;
        __repair_phase_storage.pointer = (s32 *) ((((s32) (index << 16)) >> 14) + ((s8 *) entries));
        D_80112EBC = next;
        *__repair_phase_storage.pointer = temp_v0_3;
      }
      goto advance;
      while (var_s1 != temp_a1)
      {
        ++var_a0_2;
        if (var_a2 | inline_fn234(var_a0_2, arg3))
        {
          goto emit;
        }
        scan:
        ++var_s1;

        scan_byte:
        temp_v0_2 = *var_s1;

        var_a2 = temp_v0_2 == 0;
        if (inline_fn2(var_a2, temp_v0_2) == 0)
        {
          ++var_s1;
          goto scan_byte;
        }
      }

      advance:
      var_s1 += (*var_s1) != 0;

    }
  }
  count = D_80112EBC;
  if (count != 0)
  {
    var_fv1 = arg4 / ((f32) count);
    var_fv1 = var_fv1 * 30.0f;
    var_fv1 = var_fv1 - 15.0f;
    if (var_fv1 < 1.0f)
    {
      var_fv1 = 1.0f;
    }
    __repair_phase_storage.value = 0;
    if (count > 0)
    {
      do
      {
        temp_v0_4 = ((void **) &D_80100B20)[__repair_phase_storage.value];
        if (temp_v0_4 != NULL)
        {
          temp_v0_5 = *((void **) (((char *) temp_v0_4) + 0x6C));
          *((s16 *) (((char *) temp_v0_5) + 0x30)) = (s16) ((s32) var_fv1);
          *((f32 *) (((char *) temp_v0_5) + 0x14)) = (f32) (4096.0f / var_fv1);
        }
        __repair_phase_storage.value += 1;
      }
      while (__repair_phase_storage.value < count);
    }
  }
}
