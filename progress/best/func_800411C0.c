s32 buildTriangleGridMasks();
s32 computeMeshBounds();
s32 computeVertexBounds();
s32 func_800328B8();
s32 func_800336FC(s32, s32, s32, s32, s32, f32, s32, s32, s32, s32, s32);
void *func_8003C860();
s32 func_8003C94C();
s32 func_8003FCF4();
s32 func_8003FDE0();
s32 func_8003FF3C();
s32 func_800404F0();
s32 func_800410E8();
s32 func_80041114();
s32 func_80045278();
s32 func_80045290();
s32 heapAllocTagged();
s32 vec3Add();
extern s32 D_800C0784[];
extern s32 D_800C0788[];
extern f32 D_800E19E0;
extern f32 D_800E19E4;
extern f32 D_800E19E8;
extern s8 D_80109A94;
typedef struct 
{
  s32 w[4];
} __repair_words4;
inline static s32 inline_fn(s32 arg0)
{
  return (s32) arg0;
}

void func_800411C0(void **arg0, void *arg1, s32 arg2)
{
  s32 *__repair_hoisted;
  s32 __repair_store_0;
  s32 __repair_store_1;
  s32 __repair_store_2;
  s32 sp30;
  volatile long sp34;
  register s32 sp38;
  int sp3C;
  s32 sp40;
  s32 sp44;
  s32 sp48;
  register s32 sp4C;
  s32 sp50;
  s32 var_a1;
  unsigned var_a1_2;
  f32 var_fs1;
  register s32 *temp_a1;
  s32 *temp_a3_3;
  s32 *temp_a3_4;
  s32 *temp_v0_16;
  s32 *temp_v1_7;
  s32 *temp_v1_8;
  unsigned int temp_a1_3;
  s32 temp_a1_4;
  s32 temp_a2;
  s32 temp_a2_2;
  s32 temp_a2_3;
  u32 temp_a3_2;
  unsigned int temp_s1;
  register unsigned int temp_s1_2;
  int temp_s2;
  s32 temp_s2_2;
  s32 temp_s5;
  s32 temp_s7;
  unsigned int temp_v0_10;
  s32 temp_v0_13;
  s32 temp_v0_18;
  s32 var_a0;
  register s32 var_a0_2;
  s32 var_s0;
  register s32 var_s0_2;
  s32 var_s0_3;
  register s32 var_s1;
  register s32 var_s1_2;
  register u16 temp_a0;
  register u16 temp_v1_4;
  u32 temp_v1;
  u8 temp_v0_15;
  u8 temp_v0_3;
  u8 temp_v0_4;
  u8 var_v0;
  u8 var_v0_2;
  void *temp_a0_2;
  void *temp_a1_2;
  void *temp_a3;
  void *temp_a3_5;
  register void *temp_s4;
  register void *temp_s4_2;
  void *temp_v0;
  void *temp_v0_11;
  volatile char scratch[8];
  void *temp_v0_12;
  void *temp_v0_14;
  void *temp_v0_17;
  void *temp_v0_2;
  void *temp_v0_5;
  void *temp_v0_6;
  void *temp_v0_7;
  void *temp_v0_8;
  void *temp_v0_9;
  register void *temp_v1_2;
  void *temp_v1_3;
  void *temp_v1_5;
  volatile int pad;
  void *temp_v1_6;
  void *temp_v1_9;
  register void *var_a2;
  void *var_t0;
  sp30 = 1;
  sp34 = 1;
  temp_a0 = *((u16 *) (((char *) arg1) + 0));
  temp_s7 = *(D_800C0788 + ((*(*((s16 **) (((char *) arg1) + 0x28)))) * 4));
  temp_v0 = (temp_a0 * 0x4C) + temp_s7;
  *((s32 *) (((char *) ((temp_a0 * 0x4C) + temp_s7)) + 0x30)) = (s32) (((*((s32 *) (((char *) temp_v0) + 0x30))) & 0xFFF0000F) | (temp_a0 * 0x10));
  temp_v0_2 = ((*((u16 *) (((char *) arg1) + 0))) * 0x4C) + temp_s7;
  *((s32 *) (((char *) temp_v0_2) + 0x30)) = inline_fn(((*((s32 *) (((char *) temp_v0_2) + 0x30))) & 0xFFFFF) | ((*(*((s16 **) (((char *) arg1) + 0x28)))) << 0x14));
  *((s8 *) (((char *) (((*((u16 *) (((char *) arg1) + 0))) * 0x4C) + temp_s7)) + 0x47)) = (s8) (*((u16 *) (((char *) arg1) + 0x3A)));
  temp_v0_3 = *((u8 *) (((char *) (*((s32 **) (((char *) arg1) + 0x24)))) + 0x1E));
  var_fs1 = 1.0f;
  switch (temp_v0_3)
  {
    case 0x14:

    case 0x15:

    case 0x18:

    case 0x19:

    case 0x1A:

    case 0x1B:

    case 0x1E:

    case 0x1F:

    case 0x21:

    case 0x22:

    case 0x27:

    case 0x3C:

    case 0x3D:

    case 0x3E:

    case 0x40:

    case 0x42:

    case 0x43:

    case 0x44:

    case 0x45:

    case 0x46:

    case 0x47:

    case 0x48:

    case 0x49:

    case 0x4D:

    case 0x4F:

    case 0x50:

    case 0x52:

    case 0x53:

    case 0x68:

    case 0x84:

    case 0x85:

    case 0x86:

    case 0x87:

    case 0x88:

    case 0x89:

    case 0x8A:

    case 0x8B:

    case 0x8C:

    case 0x99:

    case 0x9A:

    case 0x9B:

    case 0x9C:

    case 0x9D:

    case 0x9E:

    case 0xC8:
      __repair_hoisted = *((s32 **) (((char *) arg1) + 0x24));
      if ((arg2 << 0x18) != 0)
    {
      temp_v0_4 = *((u8 *) (((char *) __repair_hoisted) + 0x1E));
      switch (temp_v0_4)
      {
        case 0x22:

        case 0x42:

        case 0x43:

        case 0x44:

        case 0x45:

        case 0x46:

        case 0x47:

        case 0x48:

        case 0x49:

        case 0x4F:

        case 0x50:
          temp_v0_5 = func_8003C860(*arg0, 1);
          *arg0 = temp_v0_5;
          *((s32 *) (((char *) temp_v0_5) + 0x3C)) = inline_fn(temp_s7 + ((*((u16 *) (((char *) arg1) + 0))) * 0x4C));
          *((f32 *) (((char *) (*arg0)) + 0x24)) = (f32) (*((f32 *) (((char *) arg1) + 0xC)));
          *((f32 *) (((char *) (*arg0)) + 0x28)) = (f32) (*((f32 *) (((char *) arg1) + 0x10)));
          *((f32 *) (((char *) (*arg0)) + 0x2C)) = (f32) (*((f32 *) (((char *) arg1) + 0x14)));
          D_800E19E0 = *((f32 *) (((char *) (*arg0)) + 0x24));
          D_800E19E4 = *((f32 *) (((char *) (*arg0)) + 0x28));
          D_800E19E8 = *((f32 *) (((char *) (*arg0)) + 0x2C));
          break;

        default:
          temp_v0_6 = func_8003C860(*arg0, 0);
          *arg0 = temp_v0_6;
          *((s32 *) (((char *) temp_v0_6) + 0x3C)) = inline_fn(temp_s7 + ((*((u16 *) (((char *) arg1) + 0))) * 0x4C));
          break;

      }

      temp_s4 = *((void **) (((char *) (*arg0)) + 0x3C));
      sp30 = 1;
      func_80045278(&D_800E19E0);
      *((f32 *) (((char *) (*arg0)) + 0x24)) = (f32) (*((f32 *) (((char *) arg1) + 0xC)));
      *((f32 *) (((char *) (*arg0)) + 0x28)) = (f32) (*((f32 *) (((char *) arg1) + 0x10)));
      *((f32 *) (((char *) (*arg0)) + 0x2C)) = (f32) (*((f32 *) (((char *) arg1) + 0x14)));
      *((f32 *) (((char *) (*arg0)) + 0x30)) = (f32) ((*((f32 *) (((char *) arg1) + 0x18))) * 0.000004261058f);
      *((f32 *) (((char *) (*arg0)) + 0x34)) = (f32) ((*((f32 *) (((char *) arg1) + 0x1C))) * 0.000004261058f);
      *((f32 *) (((char *) (*arg0)) + 0x38)) = (f32) ((*((f32 *) (((char *) arg1) + 0x20))) * 0.000004261058f);
      *((s32 *) (((char *) (*arg0)) + 0x50)) = func_8003FCF4(arg1);
      *((f32 *) (((char *) (*arg0)) + 0x54)) = 0.0f;
      if ((*((s32 *) (((char *) arg1) + 0x3C))) & 0x10000)
      {
        temp_v0_7 = *arg0;
        *((f32 *) (((char *) temp_v0_7) + 0x54)) += 5.0f;
      }
      if ((*((s32 *) (((char *) arg1) + 0x3C))) & 0x20000)
      {
        temp_v0_8 = *arg0;
        *((f32 *) (((char *) temp_v0_8) + 0x54)) += 10.0f;
      }
      func_800404F0(arg1, *arg0, &sp30, &sp34);
      if ((*((s32 *) (((char *) arg1) + 0x3C))) & 0x2000)
      {
        temp_v0_9 = *arg0;
        temp_v1 = *((u32 *) (((char *) temp_v0_9) + 0x5C));
        *((u32 *) (((char *) temp_v0_9) + 0x5C)) = (u32) ((temp_v1 & 0x7FFFFF) | (((temp_v1 >> 0x17) | 0x10) << 0x17));
      }
      temp_a3 = ((*((u16 *) (((char *) arg1) + 0))) * 0x4C) + temp_s7;
      if ((*((u8 *) (((char *) temp_a3) + 0x45))) == 0)
      {
        func_8003FDE0(*((s32 *) (((char *) (*((s32 **) (((char *) arg1) + 0x24)))) + 0x18)), &sp38, &sp3C, &sp40);
        *((u16 *) (((char *) temp_s4) + 0x40)) = (u16) sp3C;
        *((u16 *) (((char *) temp_s4) + 0x42)) = (u16) (*((u16 *) (((char *) (*((s32 **) (((char *) arg1) + 0x24)))) + 4)));
        *((s8 *) (((char *) (((*((u16 *) (((char *) arg1) + 0))) * 0x4C) + temp_s7)) + 0x45)) = 1;
        *((s32 *) (((char *) temp_s4) + 0x34)) = heapAllocTagged((*((u16 *) (((char *) (*((s32 **) (((char *) arg1) + 0x24)))) + 4))) * 0xC, 2);
        if (((u32) (sp40 - 1)) < 2U)
        {
          var_a1 = 4;
          var_a0 = (*((u16 *) (((char *) temp_s4) + 0x40))) * 6;
          var_v0 = (*((u8 *) (((char *) temp_s4) + 0x48))) | 4;
        }
        else
        {
          var_a1 = 3;
          var_a0 = (*((u16 *) (((char *) temp_s4) + 0x40))) * 3;
          var_v0 = (*((u8 *) (((char *) temp_s4) + 0x48))) | 8;
        }
        *((u8 *) (((char *) temp_s4) + 0x48)) = var_v0;
        *((s32 *) (((char *) temp_s4) + 0x3C)) = heapAllocTagged(var_a0, var_a1);
        do
        {
          temp_v0_10 = heapAllocTagged((*((u16 *) (((char *) temp_s4) + 0x40))) * 2, 5);
          *((s32 *) (((char *) temp_s4) + 0x38)) = temp_v0_10; temp_a1 = *((s32 **) (((char *) arg1) + 0x24)); var_s1 = 0; temp_s5 = *((s32 *) (((char *) temp_a1) + 0x18));
          if (inline_fn(*((u16 *) (((char *) temp_a1) + 4))) > 0)
          {
            var_s0 = 0;
            do
            {
              vec3Add(&D_800E19E0, (*((s32 *) (((char *) (*((s32 **) (((char *) arg1) + 0x24)))) + 0))) + var_s0, (*((s32 *) (((char *) temp_s4) + 0x34))) + var_s0);
              ++var_s1;
              var_s0 += 0xC;
            }
            while (var_s1 < ((s32) (*((u16 *) (((char *) (*((s32 **) (((char *) arg1) + 0x24)))) + 4)))));
          }
          func_8003FF3C(temp_s4, temp_s5, temp_v0_10);
          *((void **) (((char *) (*arg0)) + 0x3C)) = (void *) (temp_s7 + ((*((u16 *) (((char *) arg1) + 0))) * 0x4C));
          *((u16 *) (((char *) (*((void **) (((char *) (*arg0)) + 0x3C)))) + 0x42)) = (u16) (*((u16 *) (((char *) (*((s32 **) (((char *) arg1) + 0x24)))) + 4))); temp_a1_2 = *arg0; temp_a0_2 = *((void **) (((char *) temp_a1_2) + 0x3C));
          func_8003C94C(temp_a0_2, temp_a1_2 + 0x40, temp_a0_2 + 0x18);
          temp_v1_2 = *arg0; temp_v0_11 = ((*((u16 *) (((char *) arg1) + 0))) * 0x4C) + temp_s7; temp_a1_3 = *((s32 *) (((char *) temp_v1_2) + 0x44)); temp_a2 = *((s32 *) (((char *) temp_v1_2) + 0x48)); temp_a3_2 = *((s32 *) (((char *) temp_v1_2) + 0x4C));
          *((s32 *) (((char *) temp_v0_11) + 8)) = inline_fn(*((s32 *) (((char *) temp_v1_2) + 0x40)));
          *((s32 *) (((char *) temp_v0_11) + 0xC)) = temp_a1_3;
          *((s32 *) (((char *) temp_v0_11) + 0x10)) = inline_fn(temp_a2);
          *((s32 *) (((char *) temp_v0_11) + 0x14)) = temp_a3_2;
          buildTriangleGridMasks(*((void **) (((char *) (*arg0)) + 0x3C)), temp_a1_3, temp_a2, temp_a3_2);
          func_80041114(*arg0);
          if (1.0f != 1.0f)
          {
            temp_v1_3 = ((*((u16 *) (((char *) arg1) + 0))) * 0x4C) + temp_s7;
            *((u8 *) (((char *) temp_v1_3) + 0x48)) |= 0x10;
          }
          *((s8 *) (((char *) (((*((u16 *) (((char *) arg1) + 0))) * 0x4C) + temp_s7)) + 0x45)) = (s8) sp30; temp_v1_4 = *((u16 *) (((char *) arg1) + 0));
          if (((*((u8 *) (((char *) ((temp_v1_4 * 0x4C) + temp_s7)) + 0x46))) & 0x80) && (((u32) sp34) != 0))
          {
            temp_v0_12 = *(D_800C0784 + ((*(*((s16 **) (((char *) arg1) + 0x28)))) * 4));
            if (temp_v0_12 != NULL)
            {
              temp_s2 = *((s32 *) (((char *) temp_v0_12) + 0x10)); temp_s1 = *((s32 *) (((char *) temp_v0_12) + 0x18)); temp_a3_3 = *((s32 **) (((char *) arg1) + 0x24)); sp44 = 0; sp48 = 0;
              func_800336FC(*((s32 *) (((char *) temp_a3_3) + 0x18)), *((s32 *) (((char *) ((temp_v1_4 * 0x4C) + temp_s7)) + 0x34)), *((s32 *) (((char *) temp_a3_3) + 8)), *((s32 *) (((char *) temp_a3_3) + 0x10)), sp30, 1.0f, temp_s1, temp_s2, 0, &sp44, &sp48);
              temp_v0_13 = heapAllocTagged((sp44 * 0x10) + (sp48 * 8), 0x2E);
              func_800328B8(temp_v0_13 + (sp48 * 8), temp_v0_13);
              *((s32 *) (((*((u16 *) (((char *) arg1) + 0))) * 0x4C) + temp_s7)) = temp_v0_13;
              *((s32 *) (((char *) temp_s4) + 0)) = temp_v0_13; temp_a3_4 = *((s32 **) (((char *) arg1) + 0x24));
              func_800336FC(*((s32 *) (((char *) temp_a3_4) + 0x18)), *((s32 *) (((char *) (((*((u16 *) (((char *) arg1) + 0))) * 0x4C) + temp_s7)) + 0x34)), *((s32 *) (((char *) temp_a3_4) + 8)), *((s32 *) (((char *) temp_a3_4) + 0x10)), sp30, 1.0f, temp_s1, temp_s2, 1, NULL, NULL);
              if (D_80109A94)
              {
                temp_v1_5 = ((*((u16 *) (((char *) arg1) + 0))) * 0x4C) + temp_s7;
                *((u8 *) (((char *) temp_v1_5) + 0x46)) |= 0x80;
              }
            }
          }
          func_800410E8(*arg0);
          var_a2 = temp_s4; temp_a3_5 = var_a2 + 0x40; var_t0 = ((*((u16 *) (((char *) arg1) + 0))) * 0x4C) + temp_s7;
        }
        while (0);
        do
        {
          *((__repair_words4 *) (((char *) var_t0) + 0x0)) = *((__repair_words4 *) (((s8 *) var_a2) + 0x0));
          var_a2 += 0x10;
          var_t0 = var_t0 + 0x10;
        }
        while (var_a2 != temp_a3_5);
        __repair_store_0 = inline_fn(*((s32 *) (((char *) var_a2) + 0)));
        __repair_store_1 = inline_fn(*((s32 *) (((char *) var_a2) + 4)));
        __repair_store_2 = inline_fn(*((s32 *) (((char *) var_a2) + 8)));
        *((s32 *) (((char *) var_t0) + 0)) = __repair_store_0;
        *((s32 *) (((char *) var_t0) + 4)) = __repair_store_1;
        *((s32 *) (((char *) var_t0) + 8)) = __repair_store_2;
        return;
      }
      temp_v0_14 = *arg0;
      temp_a1_4 = *((s32 *) (((char *) temp_a3) + 0x10));
      *((s32 *) (((char *) temp_v0_14) + 0x40)) = inline_fn(*((s32 *) (((char *) temp_a3) + 8)));
      temp_a2_2 = *((s32 *) (((char *) temp_a3) + 0x14));
      *((s32 *) (((char *) temp_v0_14) + 0x44)) = inline_fn(*((s32 *) (((char *) temp_a3) + 0xC)));
      *((s32 *) (((char *) temp_v0_14) + 0x48)) = temp_a1_4;
      *((s32 *) (((char *) temp_v0_14) + 0x4C)) = temp_a2_2;
      *((void **) (((char *) (*arg0)) + 0x3C)) = (void *) (temp_s7 + ((*((u16 *) (((char *) arg1) + 0))) * 0x4C));
      *((f32 *) (((char *) (*arg0)) + 0x24)) = (f32) (*((f32 *) (((char *) arg1) + 0xC)));
      *((f32 *) (((char *) (*arg0)) + 0x28)) = (f32) (*((f32 *) (((char *) arg1) + 0x10)));
      *((f32 *) (((char *) (*arg0)) + 0x2C)) = (f32) (*((f32 *) (((char *) arg1) + 0x14)));
      *((f32 *) (((char *) (*arg0)) + 0x30)) = (f32) ((*((f32 *) (((char *) arg1) + 0x18))) * 0.000004261058f);
      *((f32 *) (((char *) (*arg0)) + 0x34)) = (f32) ((*((f32 *) (((char *) arg1) + 0x1C))) * 0.000004261058f);
      *((f32 *) (((char *) (*arg0)) + 0x38)) = (f32) ((*((f32 *) (((char *) arg1) + 0x20))) * 0.000004261058f);
      func_80041114(*arg0, temp_a1_4, temp_a2_2, temp_a3);
      func_800410E8(*arg0);
      return;
    }
      return;

    default:
      if ((*((u8 *) (((char *) (((*((u16 *) (((char *) arg1) + 0))) * 0x4C) + temp_s7)) + 0x45))) == 0)
    {
      func_8003FDE0(*((s32 *) (((char *) (*((s32 **) (((char *) arg1) + 0x24)))) + 0x18)), &sp38, &sp3C, &sp40);
      *((s8 *) (((char *) (((*((u16 *) (((char *) arg1) + 0))) * 0x4C) + temp_s7)) + 0x45)) = 1;
      sp30 = 1;
      temp_v0_15 = *((u8 *) (((char *) (*((s32 **) (((char *) arg1) + 0x24)))) + 0x1E));
      var_s0_2 = 0;
      switch (temp_v0_15)
      {
        case 0x73:
          *((s32 *) (((char *) arg1) + 0x3C)) |= 0x1000;

        case 0x30:

        case 0x54:

        case 0x56:

        case 0xC9:
          block_52:
        var_s0_2 = 1;

          break;

        case 0x74:
          *((s32 *) (((char *) arg1) + 0x3C)) |= 0x1000;

        case 0x31:
          sp30 = 1;
          break;

        case 0x34:

        case 0x51:

        case 0x7A:

        case 0x7D:
          block_37:
        sp30 = 5;

          goto block_52;

        case 0x29:

        case 0x2A:

        case 0x2B:
          sp30 = 1;
          goto block_52;

        case 0x79:
          sp30 = 3;
          goto block_52;

        case 0x75:
          *((s32 *) (((char *) arg1) + 0x3C)) |= 0x1000;

        case 0x32:
          sp30 = 0xC;
          goto block_52;

        case 0x97:
          if (temp_s1)
        {
          if (arg0)
          {
            sp30 = 0xA;
            goto block_52;
          }
          else
          {
            sp30 = 0xA;
            goto block_52;
          }
        }
        else
        {
          sp30 = 0xA;
          goto block_52;
        }

        case 0x76:
          *((s32 *) (((char *) arg1) + 0x3C)) |= 0x1000;

        case 0x33:
          sp30 = 4;
          goto block_52;

        case 0x77:
          *((s32 *) (((char *) arg1) + 0x3C)) |= 0x1000;
          goto block_37;

        case 0xC7:
          sp30 = 0xF;
          goto block_52;

        case 0x80:
          sp30 = 5;
          break;

        case 0x78:
          *((s32 *) (((char *) arg1) + 0x3C)) |= 0x1000;

        case 0x35:
          sp30 = 6;
          goto block_52;

        case 0x55:
          sp30 = 9;
          goto block_52;

        case 0x5D:
          *((s32 *) (((char *) arg1) + 0x3C)) |= 0x1000;
          break;

      }

      if ((*((s32 *) (((char *) arg1) + 0x3C))) & 0x1000)
      {
        var_fs1 = 64.0f;
      }
      *((u16 *) (((char *) (((*((u16 *) (((char *) arg1) + 0))) * 0x4C) + temp_s7)) + 0x42)) = (u16) (*((u16 *) (((char *) (*((s32 **) (((char *) arg1) + 0x24)))) + 4)));
      *((s16 *) (((char *) (((*((u16 *) (((char *) arg1) + 0))) * 0x4C) + temp_s7)) + 0x40)) = (s16) sp3C;
      temp_s4_2 = temp_s7 + ((*((u16 *) (((char *) arg1) + 0))) * 0x4C);
      temp_a2_3 = temp_s4_2 + 8;
      if (var_s0_2 == 0)
      {
        *((s32 *) (((char *) temp_s4_2) + 0x34)) = heapAllocTagged((*((u16 *) (((char *) (*((s32 **) (((char *) arg1) + 0x24)))) + 4))) * 0xC, 2, temp_a2_3);
        if (((u32) (sp40 - 1)) < 2U)
        {
          var_a1_2 = 4;
          var_a0_2 = (*((u16 *) (((char *) temp_s4_2) + 0x40))) * 6;
          var_v0_2 = (*((u8 *) (((char *) temp_s4_2) + 0x48))) | 4;
        }
        else
        {
          var_a1_2 = 3;
          var_a0_2 = (*((u16 *) (((char *) temp_s4_2) + 0x40))) * 3;
          var_v0_2 = (*((u8 *) (((char *) temp_s4_2) + 0x48))) | 8;
        }
        *((u8 *) (((char *) temp_s4_2) + 0x48)) = var_v0_2;
        *((s32 *) (((char *) temp_s4_2) + 0x3C)) = heapAllocTagged(var_a0_2, var_a1_2);
        *((s32 *) (((char *) temp_s4_2) + 0x38)) = heapAllocTagged((*((u16 *) (((char *) temp_s4_2) + 0x40))) * 2, 5);
        var_s1_2 = 0;
        if (inline_fn(*((u16 *) (((char *) (*((s32 **) (((char *) arg1) + 0x24)))) + 4))) > 0)
        {
          var_s0_3 = 0;
          do
          {
            do
            {
              func_80045290((*((s32 *) (((char *) (*((s32 **) (((char *) arg1) + 0x24)))) + 0))) + var_s0_3, (*((s32 *) (((char *) temp_s4_2) + 0x34))) + var_s0_3);
              ++var_s1_2;
              var_s0_3 += 0xC;
            }
            while (var_s1_2 < ((s32) (*((u16 *) (((char *) (*((s32 **) (((char *) arg1) + 0x24)))) + 4)))));
          }
          while (0);
        }
        func_8003FF3C(temp_s4_2, *((s32 *) (((char *) (*((s32 **) (((char *) arg1) + 0x24)))) + 0x18)), *((s32 *) (((char *) temp_s4_2) + 0x38)));
        computeMeshBounds(temp_s4_2, temp_s4_2 + 8, temp_s4_2 + 0x18);
        buildTriangleGridMasks(temp_s4_2);
      }
      else
      {
        temp_v0_16 = *((s32 **) (((char *) arg1) + 0x24));
        computeVertexBounds(*((u16 *) (((char *) temp_v0_16) + 4)), *((s32 *) (((char *) temp_v0_16) + 0)), temp_a2_3, temp_s4_2 + 0x18);
      }
      if (var_fs1 != 1.0f)
      {
        temp_v1_6 = ((*((u16 *) (((char *) arg1) + 0))) * 0x4C) + temp_s7;
        *((u8 *) (((char *) temp_v1_6) + 0x48)) |= 0x10;
      }
      *((s8 *) (((char *) (((*((u16 *) (((char *) arg1) + 0))) * 0x4C) + temp_s7)) + 0x45)) = (s8) sp30;
      if ((*((u8 *) (((char *) (((*((u16 *) (((char *) arg1) + 0))) * 0x4C) + temp_s7)) + 0x46))) & 0x80)
      {
        temp_v0_17 = *(D_800C0784 + ((*(*((s16 **) (((char *) arg1) + 0x28)))) * 4));
        if (temp_v0_17 != NULL)
        {
          temp_s2_2 = *((s32 *) (((char *) temp_v0_17) + 0x10));
          temp_s1_2 = *((s32 *) (((char *) temp_v0_17) + 0x18));
          temp_v1_7 = *((s32 **) (((char *) arg1) + 0x24));
          sp4C = 0;
          sp50 = 0;
          func_800336FC(*((s32 *) (((char *) temp_v1_7) + 0x18)), *((s32 *) (((char *) temp_v1_7) + 0)), *((s32 *) (((char *) temp_v1_7) + 8)), *((s32 *) (((char *) temp_v1_7) + 0x10)), sp30, var_fs1, temp_s1_2, temp_s2_2, 0, &sp4C, &sp50);
          temp_v0_18 = heapAllocTagged((sp4C * 0x10) + (sp50 * 8), 0x2E);
          func_800328B8(temp_v0_18 + (sp50 * 8), temp_v0_18);
          *((s32 *) (((*((u16 *) (((char *) arg1) + 0))) * 0x4C) + temp_s7)) = temp_v0_18;
          temp_v1_8 = *((s32 **) (((char *) arg1) + 0x24));
          func_800336FC(*((s32 *) (((char *) temp_v1_8) + 0x18)), *((s32 *) (((char *) temp_v1_8) + 0)), *((s32 *) (((char *) temp_v1_8) + 8)), *((s32 *) (((char *) temp_v1_8) + 0x10)), sp30, var_fs1, temp_s1_2, temp_s2_2, 1, NULL, NULL);
          if (D_80109A94)
          {
            temp_v1_9 = ((*((u16 *) (((char *) arg1) + 0))) * 0x4C) + temp_s7;
            *((u8 *) (((char *) temp_v1_9) + 0x46)) |= 0x80;
          }
        }
      }
    }
      break;

  }

}

