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
s32 randomIntBelow();
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
typedef struct { s32 x; s32 y; s32 z; } Position;
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
  s32 flag15;
  var_s1 = (u32) NULL;
  if ((func_80017490(arg5, arg6, arg7) << 0x18) != 0)
  {
    var_s1 = func_800164F8(0x8C, 0, 0);
    if (var_s1 != NULL)
    {
      temp_s0 = *((void **) (((char *) var_s1) + 0x6C));
      do { flag15 = arg15 << 0x18; } while (0);
      if (flag15 != 0)
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
            ((Field_u8 *) (((char *) temp_s0) + 0x82))->v = 0x28;
            break;

          case 46:
            { s32 v = ((__repair_field_88 *) temp_s0)->value;
              v &= 0xFE1FFFFF;
              v |= 0x600000;
              ((Field_u8 *) (((char *) temp_s0) + 0x82))->v = 0x2f;
              ((__repair_field_88 *) temp_s0)->value = v; }
            break;

          case 45:
            ((Field_u8 *) (((char *) temp_s0) + 0x82))->v = 0x2E;
            break;

          case 38:
            ((Field_u8 *) (((char *) temp_s0) + 0x82))->v = 0x27;

          case 0:
            temp_s2 = ((Field_s32 *) (((char *) temp_s0) + 0x44))->v;
            if (temp_s2 != 0)
            {
              temp_a0 = ((Field_s8 *) (((char *) temp_s0) + 0x87))->v;
              if (temp_a0 >= 3)
              {
                temp_v0 = randomIntBelow(temp_a0 - 1);
                ((Field_s8 *) (((char *) temp_s0) + 0x86))->v = (s8) (temp_v0 + 1);
                var_v1 = temp_v0 * 0x18; temp_v1 = var_v1 + ((int) temp_s2);
                *((Position *) arg0) = *((Position *) temp_v1);
                *((Position *) arg1) = *((Position *) (((u8 *) temp_v1) + 0xC));
              }
            }
            break;

          case 44:
            { s32 v = ((__repair_field_88 *) temp_s0)->value;
              v &= 0xFE1FFFFF;
              v |= 0x600000;
              ((Field_u8 *) (((char *) temp_s0) + 0x82))->v = 0x2c;
              ((__repair_field_88 *) temp_s0)->value = v; }
            break;

          case 47:
            { s32 v = ((__repair_field_88 *) temp_s0)->value;
              v &= 0xFE1FFFFF;
              v |= 0x600000;
              ((Field_u8 *) (((char *) temp_s0) + 0x82))->v = 0x30;
              ((__repair_field_88 *) temp_s0)->value = v; }
            break;

          case 12:
            { s32 v = ((__repair_field_88 *) temp_s0)->value;
              v &= 0xFE1FFFFF;
              v |= 0x600000;
              ((Field_u8 *) (((char *) temp_s0) + 0x82))->v = 0x10;
              ((__repair_field_88 *) temp_s0)->value = v; }
            break;

          case 11:
            ((Field_u8 *) (((char *) temp_s0) + 0x82))->v = 1;
            break;

          case 6:
            ((Field_u8 *) (((char *) temp_s0) + 0x82))->v = 0xA;
            break;

          case 9:
            ((Field_u8 *) (((char *) temp_s0) + 0x82))->v = 0xD;
            break;

          case 24:
            ((Field_u8 *) (((char *) temp_s0) + 0x82))->v = 0xE;
            break;

          case 37:
            ((Field_u8 *) (((char *) temp_s0) + 0x82))->v = 0x26;
            break;

          case 8:
            ((Field_u8 *) (((char *) temp_s0) + 0x82))->v = 0xB;
            break;

          case 7:
            ((Field_u8 *) (((char *) temp_s0) + 0x82))->v = 5;
            break;

          case 5:
            ((Field_u8 *) (((char *) temp_s0) + 0x82))->v = 9;
            ((Field_s32 *) (((char *) temp_s0) + 0x44))->v = 0;
            break;

          case 1:
            ((__repair_field_88 *) temp_s0)->value |= 0x40000000;
            break;

          case 25:
            { s32 v = ((__repair_field_88 *) temp_s0)->value;
              v &= 0xFE1FFFFF;
              v |= 0x600000;
              ((Field_u8 *) (((char *) temp_s0) + 0x82))->v = 0x10;
              ((__repair_field_88 *) temp_s0)->value = v; }
            func_8001751C(arg2, arg3 & 0xFF, arg0, arg1);
            ((Field_s32 *) (((char *) temp_s0) + 0x44))->v = 0;
            break;

          case 4:
            ((Field_u8 *) (((char *) temp_s0) + 0x82))->v = 9;

          case 2:
            ((Field_u8 *) (((char *) temp_s0) + 0x85))->v = 0;
            func_8001751C(arg2, arg3 & 0xFF, arg0, arg1);
            ((Field_s32 *) (((char *) temp_s0) + 0x44))->v = 0;
            break;

          case 3:
            ((Field_u8 *) (((char *) temp_s0) + 0x85))->v = 0;
            ((Field_s32 *) (((char *) temp_s0) + 0x44))->v = 0;
            ((__repair_field_88 *) temp_s0)->value |= 0x40000000;
            break;

          case 10:
            ((Field_u8 *) (((char *) temp_s0) + 0x82))->v = 0xF;
            break;

          case 34:
            ((Field_u8 *) (((char *) temp_s0) + 0x82))->v = 0x23;
            break;

          case 35:
            ((Field_u8 *) (((char *) temp_s0) + 0x82))->v = 0x24;
            break;

          case 36:
            { s32 v = ((__repair_field_88 *) temp_s0)->value;
              v &= 0xFE1FFFFF;
              v |= 0x600000;
              ((Field_u8 *) (((char *) temp_s0) + 0x82))->v = 0x25;
              ((__repair_field_88 *) temp_s0)->value = v; }
            break;

          case 16:
            { s32 v = ((__repair_field_88 *) temp_s0)->value;
              v &= 0xFE1FFFFF;
              v |= 0x400000;
              D_80117734 = 1;
              ((Field_u8 *) (((char *) temp_s0) + 0x82))->v = 0x13;
              ((__repair_field_88 *) temp_s0)->value = v; }
            D_80108F72 += 1;
            break;

          case 17:
            { s32 v = ((__repair_field_88 *) temp_s0)->value;
              v &= 0xFE1FFFFF;
              v |= 0x400000;
              D_80117734 = 1;
              ((Field_u8 *) (((char *) temp_s0) + 0x82))->v = 0x14;
              ((__repair_field_88 *) temp_s0)->value = v; }
            D_80108F72 += 1;
            break;

          case 14:
            if (((Field_u8 *) (((char *) temp_s0) + 0x81))->v == 7)
            {
              ((__repair_field_88 *) temp_s0)->value = (s32) ((((__repair_field_88 *) temp_s0)->value & 0xFE1FFFFF) | 0x600000);
              case 13:
                ;
            }
            else
            {
              ((__repair_field_88 *) temp_s0)->value = (s32) ((((__repair_field_88 *) temp_s0)->value & 0xFE1FFFFF) | 0x400000);
              D_80108F72 += 1;
            }
            ((Field_u8 *) (((char *) temp_s0) + 0x82))->v = 0x15;
            break;

          case 28:
            ((Field_u8 *) (((char *) temp_s0) + 0x85))->v = 0;
            if (func_800312F4(1, 0) == 1)
            {
              ((Field_s32 *) (((char *) var_s1) + 0x60))->v |= 1;
            }
            ((Field_u8 *) (((char *) temp_s0) + 0x82))->v = 0x15;
            break;

          case 29:
            ((Field_u8 *) (((char *) temp_s0) + 0x85))->v = 0;
            if (func_800312F4(2, 0) == 1)
            {
              ((Field_s32 *) (((char *) var_s1) + 0x60))->v |= 1;
            }

          case 50:
            ((Field_u8 *) (((char *) temp_s0) + 0x85))->v = 0;

          case 15:
            ((Field_u8 *) (((char *) temp_s0) + 0x82))->v = 0x16;
            break;

          case 30:
            ((Field_u8 *) (((char *) temp_s0) + 0x85))->v = 0;
            if (func_800312F4(2, 0) == 1)
            {
              ((Field_s32 *) (((char *) var_s1) + 0x60))->v |= 1;
            }
            ((Field_u8 *) (((char *) temp_s0) + 0x82))->v = 0x15;
            break;

          case 18:
            { s32 v = ((__repair_field_88 *) temp_s0)->value;
              v &= 0xFE1FFFFF;
              v |= 0x600000;
              ((Field_u8 *) (((char *) temp_s0) + 0x82))->v = 0x17;
              ((__repair_field_88 *) temp_s0)->value = v; }
            break;

          case 19:
            { s32 v = ((__repair_field_88 *) temp_s0)->value;
              v &= 0xFE1FFFFF;
              v |= 0x600000;
              ((Field_u8 *) (((char *) temp_s0) + 0x82))->v = 0x18;
              ((__repair_field_88 *) temp_s0)->value = v; }
            break;

          case 20:
            { s32 v = ((__repair_field_88 *) temp_s0)->value;
              v &= 0xFE1FFFFF;
              v |= 0x600000;
              ((Field_u8 *) (((char *) temp_s0) + 0x82))->v = 0x19;
              ((__repair_field_88 *) temp_s0)->value = v; }
            break;

          case 21:
            { s32 v = ((__repair_field_88 *) temp_s0)->value;
              v &= 0xFE1FFFFF;
              v |= 0x600000;
              ((Field_u8 *) (((char *) temp_s0) + 0x82))->v = 0x1a;
              ((__repair_field_88 *) temp_s0)->value = v; }
            break;

          case 26:
            ((Field_u8 *) (((char *) temp_s0) + 0x82))->v = 0x1C;
            break;

          case 42:
            ((Field_u8 *) (((char *) temp_s0) + 0x82))->v = 0x2B;
            break;

          case 22:
            ((Field_u8 *) (((char *) temp_s0) + 0x82))->v = 0x1B;
            break;

          case 27:
            { s32 v = ((__repair_field_88 *) temp_s0)->value;
              v &= 0xFE1FFFFF;
              v |= 0x800000;
              var_s5 = 0x14D;
              ((Field_u8 *) (((char *) temp_s0) + 0x82))->v = 0x1E;
              ((__repair_field_88 *) temp_s0)->value = v; }
            break;

          case 31:
            { s32 v = ((__repair_field_88 *) temp_s0)->value;
              v &= 0xFE1FFFFF;
              v |= 0x600000;
              D_80113020 += 1;
              ((Field_u8 *) (((char *) temp_s0) + 0x82))->v = 0x1F;
              ((__repair_field_88 *) temp_s0)->value = v; }
            break;

          case 32:
            ((Field_u8 *) (((char *) temp_s0) + 0x82))->v = 0x20;
            var_s5 = 0x14D;
            break;

          case 33:
            ((Field_u8 *) (((char *) temp_s0) + 0x82))->v = 0x21;
            var_s5 = 0x14D;
            break;

          case 40:
            { s32 v = ((__repair_field_88 *) temp_s0)->value;
              v &= 0xFE1FFFFF;
              v |= 0x600000;
              ((Field_u8 *) (((char *) temp_s0) + 0x82))->v = 0x29;
              ((__repair_field_88 *) temp_s0)->value = v; }
            func_8001751C(arg2, arg3 & 0xFF, arg0, arg1);
            ((Field_s32 *) (((char *) temp_s0) + 0x44))->v = 0;
            break;

          case 41:
            { s32 v = ((__repair_field_88 *) temp_s0)->value;
              v &= 0xFE1FFFFF;
              v |= 0x600000;
              ((Field_u8 *) (((char *) temp_s0) + 0x82))->v = 0x2a;
              ((__repair_field_88 *) temp_s0)->value = v; }
            break;

          case 43:
            { s32 v = ((__repair_field_88 *) temp_s0)->value;
              v &= 0xFE1FFFFF;
              v |= 0x600000;
              ((Field_u8 *) (((char *) temp_s0) + 0x82))->v = 0x2d;
              ((__repair_field_88 *) temp_s0)->value = v; }
            break;

          case 48:
            { s32 v = ((__repair_field_88 *) temp_s0)->value;
              v &= 0xFE1FFFFF;
              v |= 0x600000;
              ((Field_u8 *) (((char *) temp_s0) + 0x82))->v = 0x31;
              ((__repair_field_88 *) temp_s0)->value = v; }
            break;

          case 49:
            { s32 v = ((__repair_field_88 *) temp_s0)->value;
              v &= 0xFE1FFFFF;
              v |= 0x600000;
              ((Field_u8 *) (((char *) temp_s0) + 0x82))->v = 0x32;
              ((__repair_field_88 *) temp_s0)->value = v; }
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
          ((Field_s32 *) (((char *) var_s1) + 0x5C))->v |= 0x5E600;
        }
        else
        {
          ((Field_s32 *) (((char *) var_s1) + 0x5C))->v |= 0x20600;
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
