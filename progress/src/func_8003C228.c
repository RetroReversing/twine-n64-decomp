s32 emitScissorFromWindow();
s32 func_80034928();
s32 func_800399D0(void);
s32 func_8003A4C0();
s32 func_8003AF20();
s32 func_8003B954();
s32 SetScissorRect();
extern s8 D_800C0738;
extern s8 D_800E176C;
extern s32 D_8010A4D8;
extern s32 gHiResScreen;
extern void *sDisplayListCursor;
typedef struct 
{
  unsigned char pad[40];
  int value;
} __repair_field_28;
typedef struct 
{
  int value;
} __repair_field_0;
typedef struct 
{
  unsigned char pad[8];
  int value;
} __repair_field_8;
typedef struct 
{
  unsigned char pad[20];
  int value;
} __repair_field_14;
typedef struct 
{
  unsigned char pad[16];
  int value;
} __repair_field_10;
typedef struct { s32 w0; s32 w1; } Gfx_;
#define GFX(a, b) { Gfx_ *_g = (Gfx_ *) sDisplayListCursor; sDisplayListCursor = _g + 1; _g->w0 = (a); _g->w1 = (b); }
inline static int inline_fn(__repair_field_28 *arg0)
{
  return arg0->value;
}

inline static unsigned inline_fn2(unsigned arg0)
{
  return (arg0 >> 0x18) << 0x18;
}

void func_8003C228(void *arg0, s32 arg1, s32 arg2)
{
  s8 *__base_D_800C0738;
  s32 sp14;
  u8 sp1F;
  register f32 temp_fs1;
  f32 temp_fs0;
  void *temp_v1_4;
  void *temp_v1_3;
  u16 var_a1;
  unsigned int temp_s1;
  unsigned temp_s2;
  u32 var_a3;
  void *var_s0;
  unsigned char var_v0;
  u16 temp_v1;
  void *temp_v1_2;
  void *temp_a3_2;
  void *temp_a3;
  sp14 = arg2;
  var_s0 = *((void **) (((char *) arg0) + 4));
  temp_fs1 = (*((f32 *) (((char *) arg0) + 0x50))) + (*((f32 *) (((char *) arg0) + 0x60)));
  sp1F = 1;
  temp_fs0 = (*((f32 *) (((char *) arg0) + 0x58))) + (*((f32 *) (((char *) arg0) + 0x64)));
  if (var_s0 != NULL)
  {
    do
    {
      if (((((u32) inline_fn((__repair_field_28 *) var_s0)) >> 2) & 0x3F) == sp14)
      {
        temp_s1 = ((volatile __repair_field_10 *) var_s0)->value;
        var_v0 = (u8)temp_s1;
        temp_v1 = *((u16 *) (((char *) var_s0) + 0x1E));
        do
        {
          temp_s2 = ((__repair_field_14 *) var_s0)->value;
        }
        while (0);
        if (temp_v1 & 0x1000)
        {
          u16 top = *(volatile u16 *) ((char *) var_s0 + 0x22);
          u32 bottom = *(u8 *) ((char *) var_s0 + 0x28);
          int hiRes = *(int *) &gHiResScreen;
          u32 left = *(u16 *) ((char *) var_s0 + 0x20);
          u32 right = *(u16 *) ((char *) var_s0 + 0x24);
          if (hiRes)
          {
            bottom <<= 1;
            top <<= 1;
          }
          SetScissorRect(left, top & 0xFFFF, right, bottom);
        }
        else
          if (temp_v1 & 0x2000)
        {
          emitScissorFromWindow(arg0);
        }
        else
          if (var_v0 >= 5U)
        {
          if (sp1F == 1)
          {
            func_800399D0();
            sp1F = 0;
            func_80034928(arg0, D_8010A4D8);
          }
          if (temp_s1 & 0xFF)
          {
            if ((*((u16 *) (((char *) var_s0) + 0x1E))) & 0x400)
            {
              if (!D_800E176C)
              {
                temp_v1_2 = sDisplayListCursor;
                D_800E176C = 1;
                sDisplayListCursor = temp_v1_2 + 8;
                ((__repair_field_0 *) temp_v1_2)->value = 0xE3001201;
                *((s32 *) (((char *) temp_v1_2) + 4)) = 0x2000;
              }
            }
            else
              if (D_800E176C)
            {
              void *temp_a0;
              temp_a0 = sDisplayListCursor;
D_800E176C = 0;
sDisplayListCursor = temp_a0 + 8;
((__repair_field_0 *) temp_a0)->value = 0xE3001201;
*((s32 *) (((char *) temp_a0) + 4)) = 0;
}
if ((*((s32 *) (((char *) var_s0) + 0x18))) != 0)
{
if ((*((u16 *) (((char *) var_s0) + 0x1E))) & 0x20)
{
                __base_D_800C0738 = &D_800C0738;
                *__base_D_800C0738 = 1;
                GFX(0xFA000000, var_v0);
                GFX(0xFB000000, 0);
                func_8003B954((s32) (temp_fs1 + 1.0f), (s32) (temp_fs0 + 1.0f), var_s0);
              }
              D_800C0738 = 0;
              GFX(0xFA000000, (((((temp_s1 >> 0x18) << 0x18) | ((((temp_s1) >> 0x10) & 0xFF) << 0x10)) | (temp_s1 & 0xFF00)) | var_v0));
              GFX(0xFB000000, (((temp_s2 >> 0x18) << 0x18) | ((((temp_s2) >> 0x10) & 0xFF) << 0x10) | (temp_s2 & 0xFF00)));
func_8003B954(((s32) temp_fs1), ((s32) temp_fs0), var_s0);
            }
            else
            {
              void *temp_a0;
              if ((*((u16 *) (((char *) var_s0) + 0x1E))) & 0x20)
              {
                temp_a3_2 = sDisplayListCursor;
                sDisplayListCursor = temp_a3_2 + 8;
                ((Gfx_ *) temp_a3_2)->w0 = 0xFA000000;
                ((Gfx_ *) temp_a3_2)->w1 = var_v0;
                GFX(0xFB000000, 0);
                if ((inline_fn((__repair_field_28 *) var_s0) & 3) == 1)
                {
                  GFX(0xFC119623, 0xFF2FFFFF);
                  GFX(0xE3001001, 0x8000);
                  func_8003AF20((s32) (temp_fs1 + 1.0f), (s32) (temp_fs0 + 1.0f), var_s0, temp_a3_2);
                }
                else
                {
                  func_8003A4C0((s32) (temp_fs1 + 1.0f), (s32) (temp_fs0 + 1.0f), var_s0, temp_a3_2);
                }
              }
              GFX(0xFA000000, (((((temp_s1 >> 0x18) << 0x18) | ((((temp_s1) >> 0x10) & 0xFF) << 0x10)) | (temp_s1 & 0xFF00)) | var_v0));
              GFX(0xFB000000, (((temp_s2 >> 0x18) << 0x18) | ((((temp_s2) >> 0x10) & 0xFF) << 0x10) | (temp_s2 & 0xFF00)));
              if ((inline_fn((__repair_field_28 *) var_s0) & 3) == 1)
              {
                func_8003AF20(((s32) temp_fs1), ((s32) temp_fs0), var_s0);
              }
              else
              {
                func_8003A4C0(((s32) temp_fs1), ((s32) temp_fs0), var_s0);
              }
            }
          }
        }
      }
      if (1)
      {
      }
      var_s0 = *((void **) (((char *) var_s0) + 4));
    }
    while (var_s0 != NULL);
  }
  if (!D_800E176C)
  {
    temp_v1_4 = sDisplayListCursor;
    sDisplayListCursor = temp_v1_4 + 8;
    ((__repair_field_0 *) temp_v1_4)->value = 0xE3001201;
    *((s32 *) (((char *) temp_v1_4) + 4)) = 0x2000;
  }
}

