s32 actorLinkToSurface();
s32 actorStartKindState();
s32 func_800015AC();
s32 func_8000237C();
s32 func_80002BD0();
s32 func_80002EAC();
void *func_800164F8();
s32 func_80017490();
s32 func_8001751C();
s32 func_8002BA9C();
s32 func_800312F4();
s32 func_80077960();
s32 func_800779C4();
s32 func_80077C00();
volatile short randomIntBelow();
extern u8 D_800CA338;
extern u16 D_80108F72;
extern u16 D_80113020;
extern u8 D_80117734;
extern s32 actorTickStateMachine;
extern s32 gGameMode;
extern s32 *gProbeObjectList;
extern s32 gTrackMarkerDone;
typedef struct 
{
  unsigned char pad[136];
  int value;
} __repair_field_88;
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
  u16 v;
} Field_u16;
typedef struct 
{
  u8 v;
} Field_u8;
void *func_80079CB4(void *arg0, void *arg1, s32 arg2, u8 arg3, s32 arg4, s32 arg5, s32 arg6, s32 arg7, u32 arg8, s32 arg9, s32 arg10, s32 arg11, s32 arg12, u8 arg13, s32 arg14, s32 arg15)
{
  unsigned long var_a0;
  u8 var_v0_4;
  u8 var_v0_2;
  u32 kind_mask;
  s32 temp_s2;
  s32 temp_v0;
  s32 temp_v1_2;
  int var_a1;
  unsigned long var_s2;
  s32 var_s5;
  u32 var_v1;
  u8 var_v0_6;
  s8 temp_a0;
  u8 temp_v0_2;
  s32 var_a1_3;
  s32 var_a1_2;
  u8 var_v0_5;
  register s32 var_v0_3;
  void *temp_s0;
  void *temp_v1;
  void *temp_v1_3;
  void *var_s1;
  var_s1 = (u32) NULL;
  if ((func_80017490(arg5, arg6, arg7) << 0x18) != 0)
  {
    var_s1 = func_800164F8(0x8C, 0, 0);
    if (var_s1 != NULL)
    {
      temp_s0 = *((void **) (((char *) var_s1) + 0x6C));
      if ((arg15 << 0x18) != 0)
      {
        ((__repair_field_88 *) temp_s0)->value = ((__repair_field_88 *) temp_s0)->value | 0x10000000;
      }
      else
      {
        ((__repair_field_88 *) temp_s0)->value = ((__repair_field_88 *) temp_s0)->value & 0xEFFFFFFF;
      }
      ((Field_s32 *) (((char *) temp_s0) + 0x60))->v = 0;
      ((Field_s8 *) (((char *) temp_s0) + 0x83))->v = (s8) arg14;
      ((struct 
      {
        unsigned a : 1;
        unsigned b : 1;
        unsigned c : 1;
        unsigned gap : 3;
        unsigned d : 1;
      } *) (((u8 *) temp_s0) + 0x88))->a = 0;
      ((struct 
      {
        unsigned a : 1;
        unsigned b : 1;
        unsigned c : 1;
        unsigned gap : 3;
        unsigned d : 1;
      } *) (((u8 *) temp_s0) + 0x88))->b = 0;
      ((struct 
      {
        unsigned a : 1;
        unsigned b : 1;
        unsigned c : 1;
        unsigned gap : 3;
        unsigned d : 1;
      } *) (((u8 *) temp_s0) + 0x88))->c = 0;
      ((struct 
      {
        unsigned a : 1;
        unsigned b : 1;
        unsigned c : 1;
        unsigned gap : 3;
        unsigned d : 1;
      } *) (((u8 *) temp_s0) + 0x88))->d = (double) 0;
      ((Field_s16 *) (((char *) var_s1) + 0x78))->v = 1;
      ((Field_u8 *) (((char *) temp_s0) + 0x84))->v = arg13;
      ((Field_s8 *) (((char *) temp_s0) + 0x86))->v = 1;
      ((Field_s8 *) (((char *) temp_s0) + 0x87))->v = (s8) (arg3 - 1);
      {
        s32 mode_flag;
        s32 asset;
        ((Field_u8 *) (((char *) temp_s0) + 0x80))->v = arg4;
        ((Field_u8 *) (((char *) temp_s0) + 0x81))->v = arg9;
        mode_flag = D_800CA338;
        asset = arg10;
        ((Field_s32 *) (((char *) temp_s0) + 0x70))->v = 0;
        ((Field_s32 *) (((char *) temp_s0) + 0x40))->v = 0;
        ((Field_s32 *) (((char *) temp_s0) + 0x44))->v = arg2;
        ((Field_s32 *) (((char *) temp_s0) + 0x48))->v = 0;
        ((Field_s32 *) (((char *) temp_s0) + 0x4C))->v = -1;
        ((Field_s16 *) (((char *) temp_s0) + 0x7C))->v = 0;
        ((Field_s16 *) (((char *) temp_s0) + 0x7A))->v = 0;
        ((Field_s16 *) (((char *) temp_s0) + 0x78))->v = 0;
        func_8000237C(var_s1, asset, 1, -(mode_flag == 0));
      }
      if ((*((void **) (((char *) var_s1) + 0x68))) == NULL)
      {
        goto block_112;
      }
      {
        func_800015AC(var_s1, arg11);
        func_80002EAC(var_s1, &actorTickStateMachine);
        ((Field_f32 *) (((char *) var_s1) + 0x74))->v = (f32) (func_8002BA9C(arg10) & 0xFFFF);
        ((Field_s32 *) (((char *) var_s1) + 0x58))->v |= 0x2400;
        ((Field_u8 *) (((char *) temp_s0) + 0x82))->v = arg12;
        ((__repair_field_88 *) temp_s0)->value = (s32) ((((__repair_field_88 *) temp_s0)->value & 0xFE1FFFFF) | 0x200000);
        {
          s32 mode;
          ((Field_u8 *) (((char *) temp_s0) + 0x85))->v = ((u8 *) (&gTrackMarkerDone))[((Field_u8 *) (((char *) temp_s0) + 0x84))->v];
          mode = gGameMode;
          ((Field_s16 *) (((char *) temp_s0) + 0x76))->v = 0;
          ((Field_s16 *) (((char *) temp_s0) + 0x74))->v = 0;
          if (mode == 0x19)
          {
            D_80117734 = 1;
          }
        }
        var_s5 = 0x14D;
        if (D_80117734 == 0)
        {
          var_s5 = 0x129;
        }
        switch (arg8)
        {
          case 39:
            ((Field_u8 *) (((char *) temp_s0) + 0x82))->v = 0x28U;
            break;

          case 46:
            var_v1 = ((__repair_field_88 *) temp_s0)->value;
            kind_mask = 0xFE1FFFFF;
            var_v0_2 = 0x2F;
            goto set_kind_flags;

          case 45:
            ((Field_u8 *) (((char *) temp_s0) + 0x82))->v = 0x2EU;
            break;

          case 38:
            ((Field_u8 *) (((char *) temp_s0) + 0x82))->v = 0x27U;

          case 0:
            temp_s2 = ((Field_s32 *) (((char *) temp_s0) + 0x44))->v;
            if (temp_s2 != 0)
          {
            temp_a0 = ((Field_s8 *) (((char *) temp_s0) + 0x87))->v;
            if (3 < (temp_a0 + 1))
            {
              temp_v0 = randomIntBelow(temp_a0 - 1);
              ((Field_s8 *) (((char *) temp_s0) + 0x86))->v = (s8) (temp_v0 + 1);
              var_v1 = temp_v0 * 0x18; temp_v1 = var_v1 + ((int) temp_s2);
              {
                typedef struct 
                {
                  s32 x;
                  s32 y;
                  s32 z;
                } Position;
                *((Position *) arg0) = *((Position *) temp_v1);
                *((Position *) arg1) = *((Position *) (((u8 *) temp_v1) + 0xC));
              }
            }
          }
            break;

          case 44:
            var_v1 = ((__repair_field_88 *) temp_s0)->value;
            kind_mask = 0xFE1FFFFF;
            var_v0_2 = 0x2C;
            goto set_kind_flags;

          case 47:
            var_v1 = ((__repair_field_88 *) temp_s0)->value;
            kind_mask = 0xFE1FFFFF;
            var_v0_2 = 0x30;
            goto set_kind_flags;

          case 12:
            var_v1 = ((__repair_field_88 *) temp_s0)->value;
            kind_mask = 0xFE1FFFFF;
            var_v0_2 = 0x10;
            goto set_kind_flags;

          case 11:
            ((Field_u8 *) (((char *) temp_s0) + 0x82))->v = 1U;
            break;

          case 6:
            ((Field_u8 *) (((char *) temp_s0) + 0x82))->v = 0xAU;
            break;

          case 9:
            ((Field_u8 *) (((char *) temp_s0) + 0x82))->v = 0xDU;
            break;

          case 24:
            ((Field_u8 *) (((char *) temp_s0) + 0x82))->v = 0xEU;
            break;

          case 37:
            ((Field_u8 *) (((char *) temp_s0) + 0x82))->v = 0x26U;
            break;

          case 8:
            ((Field_u8 *) (((char *) temp_s0) + 0x82))->v = 0xBU;
            break;

          case 7:
            ((Field_u8 *) (((char *) temp_s0) + 0x82))->v = 5U;
            break;

          case 5:
            ((Field_u8 *) (((char *) temp_s0) + 0x82))->v = 9U;
            ((Field_s32 *) (((char *) temp_s0) + 0x44))->v = 0;
            break;

          case 1:
            ((__repair_field_88 *) temp_s0)->value |= 0x40000000;
            break;

          case 25:
            var_v1 = ((__repair_field_88 *) temp_s0)->value;
            kind_mask = 0xFE1FFFFF;
            var_a1 = arg3 & 0xFF;
            var_v0_4 = 0x10;
            goto setup_path_kind;

          case 4:
            ((Field_u8 *) (((char *) temp_s0) + 0x82))->v = 9U;

          case 2:
            var_a1 = arg3 & 0xFF;
            ((Field_u8 *) (((char *) temp_s0) + 0x85))->v = 0U;
            func_8001751C(arg2, var_a1, arg0, arg1);
            ((Field_s32 *) (((char *) temp_s0) + 0x44))->v = 0;
            break;

          case 3:
            var_v1 = ((__repair_field_88 *) temp_s0)->value;
            var_v0_3 = 0x40000000;
            ((Field_u8 *) (((char *) temp_s0) + 0x85))->v = 0U;
            ((Field_s32 *) (((char *) temp_s0) + 0x44))->v = 0;
            goto block_76;

          case 10:
            ((Field_u8 *) (((char *) temp_s0) + 0x82))->v = 0xFU;
            break;

          case 34:
            ((Field_u8 *) (((char *) temp_s0) + 0x82))->v = 0x23U;
            break;

          case 35:
            ((Field_u8 *) (((char *) temp_s0) + 0x82))->v = 0x24U;
            break;

          case 36:
            var_v1 = ((__repair_field_88 *) temp_s0)->value;
            kind_mask = 0xFE1FFFFF;
            var_v0_2 = 0x25;
            goto set_kind_flags;

          case 16:
            var_v1 = ((__repair_field_88 *) temp_s0)->value;
            kind_mask = 0xFE1FFFFF;
            D_80117734 = 1;
            var_v0_5 = 0x13;
            ((Field_u8 *) (((char *) temp_s0) + 0x82))->v = var_v0_5;
            temp_s2 = var_v1 & kind_mask;
            ((__repair_field_88 *) temp_s0)->value = temp_s2 | 0x400000;
            D_80108F72 += 1;
            break;

          case 17:
            var_v1 = ((__repair_field_88 *) temp_s0)->value;
            kind_mask = 0xFE1FFFFF;
            D_80117734 = 1;
            ;
            ((Field_u8 *) (((char *) temp_s0) + 0x82))->v = 0x14;
            temp_s2 = var_v1 & kind_mask;
            ((__repair_field_88 *) temp_s0)->value = temp_s2 | 0x400000;
            D_80108F72 += 1;
            break;

          case 14:
            if (((Field_u8 *) (((char *) temp_s0) + 0x81))->v == 7)
          {
            ((__repair_field_88 *) temp_s0)->value = (s32) ((((__repair_field_88 *) temp_s0)->value & 0xFE1FFFFF) | 0x600000);
            case 13:
              ;

            ;
            ;
            ;
            ;
            ;
          }
          else
          {
            ((__repair_field_88 *) temp_s0)->value = (s32) ((((__repair_field_88 *) temp_s0)->value & 0xFE1FFFFF) | 0x400000);
            D_80108F72 += 1;
          }
            ((Field_u8 *) (((char *) temp_s0) + 0x82))->v = 0x15U;
            break;

          case 28:
            ((Field_u8 *) (((char *) temp_s0) + 0x85))->v = 0U;
            var_a0 = 1;
            if (func_800312F4(var_a0, 0) == 1)
          {
            ((Field_s32 *) (((char *) var_s1) + 0x60))->v |= 1;
          }
            ((Field_u8 *) (((char *) temp_s0) + 0x82))->v = 0x15U;
            break;

          case 29:
            ((Field_u8 *) (((char *) temp_s0) + 0x85))->v = 0U;
            if (func_800312F4(2, 0) == 1)
          {
            ((Field_s32 *) (((char *) var_s1) + 0x60))->v |= 1;
          }

          case 50:
            ((Field_u8 *) (((char *) temp_s0) + 0x85))->v = 0U;

          case 15:
            ((Field_u8 *) (((char *) temp_s0) + 0x82))->v = 0x16U;
            break;

          case 30:
            ((Field_u8 *) (((char *) temp_s0) + 0x85))->v = 0U;
            var_a0 = 2;
            if (func_800312F4(var_a0, 0) == 1)
          {
            ((Field_s32 *) (((char *) var_s1) + 0x60))->v |= 1;
          }
            ((Field_u8 *) (((char *) temp_s0) + 0x82))->v = 0x15U;
            break;

          case 18:
            var_v1 = ((__repair_field_88 *) temp_s0)->value;
            kind_mask = 0xFE1FFFFF;
            var_v0_2 = 0x17;
            goto set_kind_flags;

          case 19:
            var_v1 = ((__repair_field_88 *) temp_s0)->value;
            kind_mask = 0xFE1FFFFF;
            var_v0_2 = 0x18;
            goto set_kind_flags;

          case 20:
            var_v1 = ((__repair_field_88 *) temp_s0)->value;
            kind_mask = 0xFE1FFFFF;
            var_v0_2 = 0x19;
            goto set_kind_flags;

          case 21:
            var_v1 = ((__repair_field_88 *) temp_s0)->value;
            kind_mask = 0xFE1FFFFF;
            var_v0_2 = 0x1A;
            goto set_kind_flags;

          case 26:
            ((Field_u8 *) (((char *) temp_s0) + 0x82))->v = 0x1CU;
            break;

          case 42:
            ((Field_u8 *) (((char *) temp_s0) + 0x82))->v = 0x2BU;
            break;

          case 22:
            ((Field_u8 *) (((char *) temp_s0) + 0x82))->v = 0x1BU;
            break;

          case 27:
            var_v1 = ((__repair_field_88 *) temp_s0)->value;
            kind_mask = 0xFE1FFFFF;
            var_s5 = 0x14D;
            ((Field_u8 *) (((char *) temp_s0) + 0x82))->v = 0x1EU;
            var_v0_3 = 0x800000;
            goto block_75;

          case 31:
            D_80113020 += 1;
            do
          {
            ((__repair_field_88 *) temp_s0)->value = (s32) ((((__repair_field_88 *) temp_s0)->value & 0xFE1FFFFF) | 0x600000);
            ((Field_u8 *) (((char *) temp_s0) + 0x82))->v = 0x1FU;
          }
          while (0);
            break;

          case 32:
            var_v0_6 = 0x20;
            ((Field_u8 *) (((char *) temp_s0) + 0x82))->v = var_v0_6;
            var_s5 = 0x14D;
            break;

          case 33:
            var_v0_6 = 0x21;
            ((Field_u8 *) (((char *) temp_s0) + 0x82))->v = var_v0_6;
            var_s5 = 0x14D;
            break;

          case 40:
            var_v1 = ((__repair_field_88 *) temp_s0)->value;
            kind_mask = 0xFE1FFFFF;
            var_a1 = arg3 & 0xFF;
            var_v0_4 = 0x29;
            setup_path_kind:
          ((Field_u8 *) (((char *) temp_s0) + 0x82))->v = var_v0_4;

            var_v0_3 = var_v1 & kind_mask;
            ((__repair_field_88 *) temp_s0)->value = var_v0_3 | 0x600000;
            func_8001751C(arg2, var_a1, arg0, arg1);
            ((Field_s32 *) (((char *) temp_s0) + 0x44))->v = 0;
            break;

          case 41:
            var_v1 = ((__repair_field_88 *) temp_s0)->value;
            kind_mask = 0xFE1FFFFF;
            var_v0_2 = 0x2A;
            goto set_kind_flags;

          case 43:
            var_v1 = ((__repair_field_88 *) temp_s0)->value;
            kind_mask = 0xFE1FFFFF;
            var_v0_2 = 0x2D;
            goto set_kind_flags;

          case 48:
            var_v1 = ((__repair_field_88 *) temp_s0)->value;
            kind_mask = 0xFE1FFFFF;
            var_v0_2 = 0x31;
            goto set_kind_flags;

          case 49:
            var_v1 = ((__repair_field_88 *) temp_s0)->value;
            kind_mask = 0xFE1FFFFF;
            var_v0_2 = 0x32;
            set_kind_flags:
          ((Field_u8 *) (((char *) temp_s0) + 0x82))->v = var_v0_2;

            var_v0_3 = 0x600000;
            block_75:
          var_v1 &= kind_mask;

            block_76:
          var_v1 |= var_v0_3;

            ((__repair_field_88 *) temp_s0)->value = var_v1;
            break;

        }

        {
          typedef struct 
          {
            s32 x;
            s32 y;
            s32 z;
          } Position;
          *((Position *) (((u8 *) var_s1) + 0x24)) = *((Position *) arg0);
          *((Position *) (((u8 *) var_s1) + 0x30)) = *((Position *) (((u8 *) var_s1) + 0x24));
          *((Position *) (((u8 *) var_s1) + 0x3C)) = *((Position *) arg1);
          *((Position *) (((u8 *) var_s1) + 0x48)) = *((Position *) (((u8 *) var_s1) + 0x3C));
          *((Position *) temp_s0) = *((Position *) (((u8 *) var_s1) + 0x24));
          *((Position *) (((u8 *) temp_s0) + 0xC)) = *((Position *) (((u8 *) var_s1) + 0x3C));
        }
        temp_v1_2 = ((__repair_field_88 *) temp_s0)->value & 0x01E00000;
        if ((temp_v1_2 == 0x400000) | (temp_v1_2 == 0x600000))
        {
          *((volatile s32 *) (((char *) var_s1) + 0x5C)) |= 0x5E600;
        }
        else
        {
          *((volatile s32 *) (((char *) var_s1) + 0x5C)) |= 0x20600;
        }
        ((Field_s32 *) (((char *) temp_s0) + 0x6C))->v = 0;
        if (var_s5 == 0x129)
        {
          ((Field_s16 *) (((char *) var_s1) + 0x7C))->v = 1;
          ((Field_s8 *) (((char *) temp_s0) + 0x7F))->v = 1;
          func_80002BD0(var_s1, 0x129);
        }
        else
          if (var_s5 == 0x14D)
        {
          ((Field_s16 *) (((char *) var_s1) + 0x7C))->v = 0;
          ((Field_s8 *) (((char *) temp_s0) + 0x7F))->v = 0;
          if (((Field_u8 *) (((char *) temp_s0) + 0x82))->v == 0x1E)
          {
            ((__repair_field_88 *) temp_s0)->value &= 0xBFFFFFFF;
          }
        }
        func_80002BD0(var_s1, var_s5);
        ((Field_s16 *) (((char *) var_s1) + 0x7A))->v = 0;
        ((Field_s8 *) (((char *) temp_s0) + 0x7E))->v = 0;
        func_80077960(var_s1, 0);
        ((Field_u8 *) (((char *) var_s1) + 0x7F))->v = 0x80;
        ((Field_u8 *) (((char *) var_s1) + 0x80))->v = 0x80;
        ((Field_u8 *) (((char *) var_s1) + 0x81))->v = 0x80;
        ((Field_u8 *) (((char *) var_s1) + 0x82))->v = 0xFF;
        ((Field_s8 *) (((char *) var_s1) + 0x7E))->v = 1;
        ((Field_s32 *) (((char *) temp_s0) + 0x38))->v = 0;
        ((Field_s32 *) (((char *) temp_s0) + 0x3C))->v = 0;
        ((Field_s32 *) (((char *) temp_s0) + 0x4C))->v = -1;
        ((Field_s32 *) (((char *) temp_s0) + 0x38))->v = 0;
        ((Field_s32 *) (((char *) temp_s0) + 0x3C))->v = 0;
        ((Field_s32 *) (((char *) temp_s0) + 0x30))->v = 0;
        if (((Field_u8 *) (((char *) temp_s0) + 0x84))->v != 0)
        {
          func_80077960(var_s1, 0x27);
          return var_s1;
        }
        actorLinkToSurface(*gProbeObjectList, var_s1, 1);
        func_80077960(var_s1, 0x26);
        temp_v0_2 = ((Field_u8 *) (((char *) temp_s0) + 0x82))->v;
        var_s2 = 1;
        switch (temp_v0_2)
        {
          case 2:

          case 3:

          case 4:

          case 5:

          case 44:

          case 0:
          case 1:
          case 45:
          case 46:
          case 47:
          case 48:
          case 49:
          case 50:
          default:
            var_a1_2 = 1;
            func_80077960(var_s1, var_a1_2);
            break;

          case 15:
            var_a1_2 = 0x42;
            func_80077960(var_s1, var_a1_2);
            break;

          case 6:

          case 8:
            func_80002BD0(var_s1, 0x2C4);
            var_a1_3 = 0x28;
            func_80077960(var_s1, var_a1_3);
            var_s2 = 0;
            ((Field_s32 *) (((char *) var_s1) + 0x58))->v |= 0x80000;
            break;

          case 7:
            func_80002BD0(var_s1, 0x2C5);
            var_a1_3 = 0x29;
            var_s2 = 0;
            func_80077960(var_s1, var_a1_3);
            ((Field_s32 *) (((char *) var_s1) + 0x58))->v |= 0x80000;
            break;

          case 18:
            func_80002BD0(var_s1, 0x215);
            var_a1_3 = 0x2B;
            var_s2 = 0;
            func_80077960(var_s1, var_a1_3);
            ((Field_s32 *) (((char *) var_s1) + 0x58))->v |= 0x80000;
            break;

          case 34:
            var_a1_2 = 3;
            ((Field_s16 *) (((char *) var_s1) + 0x7C))->v = 0xA;
            ((Field_s8 *) (((char *) temp_s0) + 0x7F))->v = 0xA;
            func_80077960(var_s1, var_a1_2);
            break;

          case 21:
            var_s2 = 0;
            if (((Field_u8 *) (((char *) temp_s0) + 0x84))->v == 0)
          {
            actorStartKindState(var_s1);
          }
            break;

          case 22:
            func_80002BD0(var_s1, 0x20E);
            func_80077960(var_s1, 0x47);
            var_s2 = 0;
            break;

          case 42:
            var_s2 = 0;
            func_80002BD0(var_s1, 0x330);
            var_a1_2 = 0x89;
            func_80077960(var_s1, var_a1_2);
            break;

          case 28:
            if (func_800312F4(1, 0) == 2)
          {
            ((Field_s32 *) (((char *) var_s1) + 0x60))->v |= 1;
          }

          case 27:

          case 43:
            func_800779C4(var_s1);
            var_a1_2 = 0x3E;
            func_80077960(var_s1, var_a1_2);
            break;

          case 31:
            func_80002BD0(var_s1, 0x1FE);
            var_a1_2 = 0x77;
            func_80077960(var_s1, var_a1_2);
            break;

          case 23:
            var_a1_2 = 0x58;
            func_80077960(var_s1, var_a1_2);
            break;

          case 26:
            var_a1_2 = 0x65;
            func_80077960(var_s1, var_a1_2);
            break;

          case 24:
            var_a1_2 = 0x4C;
            func_80077960(var_s1, var_a1_2);
            break;

          case 25:
            var_a1_2 = 0x59;
            func_80077960(var_s1, var_a1_2);
            break;

          case 41:
            var_a1_2 = 0x66;
            func_80077960(var_s1, var_a1_2);
            break;

          case 37:
            var_a1_2 = 0x7E;
            func_80077960(var_s1, var_a1_2);
            break;

        }

        if ((*((void **) (((char *) var_s1) + 0x20))) == NULL)
        {
          block_112:
          ((Field_s32 *) (((char *) var_s1) + 0x60))->v |= 1;

          return NULL;
        }
        temp_v1_3 = *((void **) (((char *) var_s1) + 0x68));
        ((Field_u16 *) (((char *) temp_v1_3) + 0xC))->v &= 0xFFF7;
        if ((var_s2 != 0) && (((Field_u8 *) (((char *) temp_s0) + 0x80))->v == 0))
        {
          func_80077C00(var_s1);
          return var_s1;
        }
        *((f32 *) (((char *) (*((void **) (((char *) var_s1) + 0x68)))) + 8)) = (f32) (*((f32 *) (((char *) (*((void **) (((char *) (*((void **) (((char *) var_s1) + 0x20)))) + 0x3C)))) + 0x20)));
        goto block_117;
      }
    }
  }
  block_117:
  return var_s1;

}

