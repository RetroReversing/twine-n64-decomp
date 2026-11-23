typedef struct { s16 id; u8 pad[0x1E]; } SlotQ;
typedef struct { s16 key, b, c; } RuleQ;
typedef struct { f32 x, y, z; } V3Q;
typedef struct { V3Q *a; V3Q *b; } SubQ;
#define SUBP(o) (*(SubQ **) ((char *) (o) + 0x68))
#define F32AT(o, off) (*(f32 *) ((char *) (o) + (off)))
inline static int __repair_inline(s32 a, s32 b)
{
  return a > b;
}

s16 *findOrLoadStreamSlot(s32);
s32 func_80002098(s32 *, s32 *, s32, void *);
s32 func_800060B0(void *, s32, s32);
void *func_8002BC4C();
s32 func_8003FA78(s32);
s32 func_8004478C(s32, s32);
f32 func_80082908(f32);
s32 func_80084180(void *, s32, s16);
void *heapAllocTagged(s32, s32);
s32 memset(void *, s32, s32);
s32 randomIntBelow(s32);
extern f32 D_800AE4D8;
extern s16 *D_800AE4DC;
extern s16 D_800AE53C;
extern s32 D_800C3928;
extern s32 D_800C392A;
extern s32 D_800C3CF4;
extern s32 D_800C3CF8;
extern s32 D_800C3CFC;
extern u8 D_800CA338;
extern s32 gBootState;
typedef struct 
{
  unsigned int value;
} __repair_field_0;
inline static u32 inline_fn(s16 arg0)
{
  return (u32) arg0;
}

typedef struct 
{
  f32 v;
} Field_f32;
typedef struct 
{
  s16 v;
} Field_s16;
typedef struct 
{
  s32 v;
} Field_s32;
typedef struct 
{
  s8 v;
} Field_s8;
typedef struct 
{
  u8 v;
} Field_u8;
s32 func_8000237C(void *arg0, s32 arg1, s32 arg2, s32 arg3)
{
  int sp10;
  s32 sp14;
  void *temp_s0;
  s32 sp24;
  f32 temp_fv0_4;
  f32 temp_fv0;
  f32 temp_fv0_2;
  f32 temp_fv0_3;
  f32 temp_fv1;
  s16 **var_s5;
  s16 *temp_s1_2;
  s16 *temp_v0_8;
  s16 *temp_v0_9;
  void *temp_v0_6;
  s16 *var_s0_2;
  s16 *var_s2_2;
  RuleQ *var_r;
  RuleQ *temp_r;
  s32 var_v0;
  s32 temp_s1;
  int temp_s4;
  void *temp_s0_4;
  register s32 temp_v0;
  s32 var_s1_2;
  s32 var_s2;
  unsigned long sp2C;
  s32 temp_s2;
  f32 c_one;
  f32 temp_fp0;
  f32 c_eighth;
  s32 tq;
  s32 temp_s6;
  s32 temp_s3;
  s32 temp_s5;
  s32 temp_s7;
  s32 var_a0;
  int var_a0_2;
  s32 var_a0_3;
  register s32 var_a1;
  s32 var_s0;
  int var_s1;
  u32 var_v0_2;
  s32 var_v0_3;
  s32 var_v1;
  s32 var_v1_3;
  void *temp_s0_2;
  void *temp_s0_3;
  s32 temp_s5_2;
  void *temp_s0_5;
  void *temp_v0_2;
  void *temp_v0_3;
  void *temp_v0_4;
  void *temp_v0_5;
  s16 *var_a0_4;
  void *temp_v0_7;
  void *temp_v1;
  void *temp_v1_2;
  void *var_s3;
  void *var_v1_2;
  sp2C = 0;
  if (arg0 != NULL)
  {
    temp_v0 = *((s16 *) (((char *) (&D_800C3CF4)) + (arg1 * 0xC)));
    sp24 = inline_fn(temp_v0);
    temp_v1 = *((void **) (((char *) arg0) + 0x68));
    temp_s1 = *((s16 *) (((char *) (&D_800C3928)) + (temp_v0 * 8)));
    var_s3 = temp_v1 + 0x14;
    if (temp_v1 == NULL)
    {
      var_s0 = 0xB8;
      switch (arg2)
      {
        case 0:
        default:
          var_v0 = temp_s1 + 5;
          break;
        case 1:
          var_v0 = temp_s1 * 4 + 5; var_v0 = temp_s1 + var_v0;
          break;
        case 2:
          var_v0 = temp_s1 * 3; tq = temp_s1 + 2; var_v0 += tq;
          break;
        case 3:
          var_v0 = temp_s1 * 3; tq = temp_s1 + 2; var_v0 += tq; tq = temp_s1 * 4; var_v0 += tq;
          break;
      }
      var_s2 = var_v0 * 4;
      var_s3 = (void *) ((var_s2 + 7) & (~7));
      var_s0 += (s32) var_s3;
      var_s0 += (s32) var_s3;
      var_s0 += var_s2;
      temp_s7 = temp_s1 * 4;
      var_s0 += temp_s7;
      temp_s5 = temp_s1 * 0xC;
      var_s0 += temp_s5;
      var_s0 = (s32) heapAllocTagged(var_s0 + temp_s5, 0x21);
      if (var_s0 != 0)
      {
        *((s32 *) (((char *) arg0) + 0x68)) = var_s0;
        memset((void *) var_s0, 0, 0xB8);
        temp_v0_3 = *((void **) (((char *) arg0) + 0x68));
        var_s0 += 0xB8;
        *((s32 *) (((char *) temp_v0_3) + 0x54)) = var_s0;
        var_s0 += (s32) var_s3;
        *((s32 *) (((char *) temp_v0_3) + 0x58)) = var_s0;
        var_s0 += (s32) var_s3;
        *((s32 *) (((char *) temp_v0_3) + 0x5C)) = var_s0;
        var_s0 += var_s2;
        ((Field_s32 *) (((char *) temp_v0_3) + 0x14))->v = arg2;
        ((Field_s16 *) (((char *) temp_v0_3) + 0xA6))->v = var_s2;
        *((s32 *) (((char *) temp_v0_3) + 0x6C)) = var_s0;
        var_s0 += temp_s7;
        *((s32 *) (((char *) (*((void **) (((char *) arg0) + 0x68)))) + 0)) = var_s0;
        var_s3 = temp_v0_3 + 0x14;
        var_s0 += temp_s5;
        *((s32 *) (((char *) (*((void **) (((char *) arg0) + 0x68)))) + 4)) = var_s0;
        goto block_14;
      }
    }
    else
    {
      block_14:
      ((Field_s8 *) (((char *) var_s3) + 0x9F))->v = (s8) temp_s1;

      var_a1 = 0;
      if (temp_s1 > 0)
      {
        do
        {
          SUBP(arg0)->a[var_a1].x = SUBP(arg0)->b[var_a1].x = F32AT(arg0, 0x24);
          SUBP(arg0)->a[var_a1].y = SUBP(arg0)->b[var_a1].y = F32AT(arg0, 0x28);
          SUBP(arg0)->a[var_a1].z = SUBP(arg0)->b[var_a1].z = F32AT(arg0, 0x2C);
          var_a1 += 1;
        }
        while (var_a1 < temp_s1);
      }
      temp_fp0 = func_80082908(3.0f);
      c_one = 1.0f;
      c_eighth = 0.125f;
      var_a1 = 0;
      ((Field_f32 *) (((char *) arg0) + 0x64))->v = temp_fp0;
      ((Field_f32 *) (((char *) var_s3) + 0xC))->v = 0;
      temp_fv0_4 = ((Field_f32 *) (((char *) var_s3) + 0xC))->v;
      var_v1_2 = var_s3;
      ((Field_s16 *) (((char *) var_s3) + 0x8E))->v = -1;
      ((Field_s16 *) (((char *) var_s3) + 0x8C))->v = 0;
      ((Field_s16 *) (((char *) var_s3) + 0x82))->v = -1;
      ((Field_s16 *) (((char *) var_s3) + 0x84))->v = -1;
      ((Field_s16 *) (((char *) var_s3) + 0x86))->v = -1;
      ((Field_s8 *) (((char *) var_s3) + 0xA0))->v = 0;
      ((Field_s32 *) (((char *) var_s3) + 0x1C))->v = 0;
      ((Field_s32 *) (((char *) var_s3) + 0x4C))->v = 0;
      ((Field_s32 *) (((char *) var_s3) + 0x54))->v = 0;
      ((Field_s32 *) (((char *) var_s3) + 0x20))->v = 0;
      ((Field_f32 *) (((char *) var_s3) + 4))->v = c_one;
      ((Field_f32 *) (((char *) var_s3) + 8))->v = c_eighth;
      ((Field_f32 *) (((char *) var_s3) + 0x14))->v = temp_fv0_4;
      ((Field_f32 *) (((char *) var_s3) + 0x10))->v = temp_fv0_4;
      ((Field_f32 *) (((char *) var_s3) + 0x18))->v = temp_fv0_4;
      ((Field_f32 *) (((char *) var_s3) + 0x6C))->v = c_one;
      ((Field_f32 *) (((char *) var_s3) + 0x70))->v = c_one;
      ((Field_f32 *) (((char *) var_s3) + 0x74))->v = c_one;
      do
      {
        ((Field_s16 *) (((char *) var_v1_2) + 0x94))->v = 0;
        var_a1 += 1;
        var_v1_2 += 2;
      }
      while (((u32) var_a1) < 4U);
      ((Field_s16 *) (((char *) var_s3) + 0x78))->v = (s16) ((s32) ((Field_f32 *) (((char *) arg0) + 0x40))->v);
      ((Field_s16 *) (((char *) var_s3) + 0x7A))->v = 0;
      ((__repair_field_0 *) var_s3)->value = (s32) ((((__repair_field_0 *) var_s3)->value & 3) | 0x8010);
      if ((*((s16 *) (((char *) (&D_800C392A)) + (sp24 * 8)))) == 0)
      {
        func_800060B0(arg0, 0x71, 0);
      }
      else
        if (((s32) (inline_fn((s32) ((Field_s16 *) (((char *) var_s3) + 0x92))->v) >> 2)) > 0)
      {
        var_a1 = 0;
        do
        {
          *((s32 *) (((char *) (*((void **) (((char *) var_s3) + 0x40)))) + (var_a1 * 4))) = 0;
          var_a1 += 1;
        }
        while (var_a1 < ((s32) (inline_fn(((Field_s16 *) (((char *) var_s3) + 0x92))->v) >> 2)));
      }
      func_80084180(*((void **) (((char *) var_s3) + 0x44)), ((Field_s32 *) (((char *) var_s3) + 0x40))->v, ((Field_s16 *) (((char *) var_s3) + 0x92))->v);
      func_80084180(*((void **) (((char *) var_s3) + 0x48)), ((Field_s32 *) (((char *) var_s3) + 0x40))->v, ((Field_s16 *) (((char *) var_s3) + 0x92))->v);
      temp_fv1 = *((f32 *) (((char *) (*((void **) (((char *) var_s3) + 0x44)))) + 0xC));
      ((Field_s32 *) (((char *) var_s3) + 0x28))->v = 0;
      ((Field_s32 *) (((char *) var_s3) + 0x2C))->v = 0;
      ((Field_s32 *) (((char *) var_s3) + 0x30))->v = 0;
((Field_f32 *) (((char *) var_s3) + 0x24))->v = temp_fv1; ((Field_f32 *) (((char *) var_s3) + 0x24))->v = (f32) (temp_fv1 + D_800AE4D8);
      ((Field_u8 *) (((char *) var_s3) + 0x9D))->v = (u8) arg1;
      ((Field_u8 *) (((char *) var_s3) + 0x9E))->v = (u8) sp24;
      if ((*((u16 *) (((char *) func_8002BC4C(arg1)) + 6))) & 0x40)
      {
        ((__repair_field_0 *) var_s3)->value = (s32) (((__repair_field_0 *) var_s3)->value | 0x200000);
      }
      temp_s1_2 = findOrLoadStreamSlot(sp24);
      temp_s2 = arg1 * 0xC;
      temp_s5_2 = *(*((s16 **) (((char *) (&D_800C3CF8)) + temp_s2)));
      if ((func_8003FA78(temp_s5_2) << 0x18) != 0)
      {
        temp_s6 = temp_s2;
        if (((SlotQ *) temp_s1_2)[0].id >= 0)
        {
          var_s0 = 0;
          do
          {
            sp10 = (s32) temp_s5_2;
            sp14 = (s32) (*((u8 *) (((char *) (*((void **) (((char *) (&D_800C3CFC)) + temp_s6)))) + var_s0)));
            func_80002098(&sp10, &sp14, var_s0, arg0);
            if (sp10 != (-1))
            {
              ((s32 *) (*((void **) (((char *) var_s3) + 0x58))))[var_s0] = func_8004478C(sp14, sp10);
            }
            else
            {
              ((s32 *) (*((void **) (((char *) var_s3) + 0x58))))[var_s0] = 0;
            }
            var_s0 += 1;
          }
          while (((SlotQ *) temp_s1_2)[var_s0].id >= 0);
        }
        arg3 &= (-(D_800CA338 == 0));
        if ((arg3 != 0) && ((u32)(temp_s5_2 - 0x2B) < 0x5EU))
        {
          sp10 = (s32) temp_s5_2;
          var_s5 = &D_800AE4DC;
          var_r = (RuleQ *) &D_800AE53C;
          var_a0_2 = 0;
          for (;;)
          {
            s16 *temp_v0_8;
            if (var_a0_2)
              break;
            temp_v0_8 = *var_s5;
            if (temp_v0_8 == NULL)
              break;
            var_s5 += 1;
            if ((*temp_v0_8) == sp10)
            {
              var_r += 1;
              var_a0_3 = 1;
              while (var_r->key == 0xE)
              {
                var_r += 1;
                var_a0_3 += 1;
              }
              if (arg3 < 0)
              {
                var_v1_3 = randomIntBelow(var_a0_3 + 1);
                if (var_v1_3 == 0)
                  break;
              }
              else
                var_v1_3 = arg3;
              temp_r = var_r - var_v1_3;
              temp_s4 = temp_r->b;
              *((s32 *) (((char *) (*((void **) (((char *) var_s3) + 0x58)))) + 0x38)) = func_8004478C(temp_r->c, sp10);
              var_s1_2 = var_r->key;
              if (var_s1_2 >= 0)
              {
                do
                {
                  if (var_r->b == temp_s4)
                  {
                    *((s32 *) (((char *) (*((void **) (((char *) var_s3) + 0x58)))) + (var_s1_2 * 4))) = func_8004478C(var_r->c, sp10);
                  }
                  var_r += 1;
                  var_s1_2 = var_r->key;
                }
                while (var_s1_2 >= 0);
              }
              var_a0_2 = 1;
            }
            else
            {
              while (var_r->key >= 0)
                var_r += 1;
              var_r = (RuleQ *) (((char *) var_r) + 2);
            }
          }
        }
      }
      else
      {
        for (var_s0 = 0; ((SlotQ *) temp_s1_2)[var_s0].id >= 0; var_s0 += 1)
        {
          ((s32 *) (*((void **) (((char *) var_s3) + 0x58))))[var_s0] = 0;
        }
      }
      sp2C = 1;
    }
  }
  gBootState = 0;
  return sp2C;
}

