s32 func_80018318(void *);
void func_80022B60(s32);
extern s32 D_800BD660;
extern u8 gMenuUseTextList;
extern void *gSaveMenuState;
extern s32 sSaveMenuColorIdle;
inline static int inline_fn(void *arg0)
{
  return -((((s32) arg0) & 0xFF) == 0);
}

inline static char *inline_fn2(void *arg0)
{
  return (char *) arg0;
}

void func_8002255C(void *arg0, void *arg1)
{
  void **__base_gSaveMenuState;
  s32 var_a0;
  s32 var_v0_2;
  s32 var_v0_4;
  s32 var_v0_5;
  s32 var_v1;
  s32 var_v1_2;
  u16 var_v0;
  u16 var_v0_3;
  u8 temp_a0;
  u8 temp_a0_4;
  void *temp_a0_2;
  void *temp_s0;
  void *temp_s2;
  void *temp_v1;
  void *var_a1;
  s32 f1, f2; void *f3, *f4;
  temp_s0 = *((void **) (((char *) arg0) + 0));
  temp_s2 = arg1;
  if (temp_s0 != NULL)
  {
    if (1)
    {
      void *child1 = *((void **) (inline_fn2(temp_s0) + 4));
      if (child1 != NULL)
      {
        temp_a0 = *((u8 *) (inline_fn2(arg0) + 8));
        if (temp_a0 == 0xFE)
        {
          *((u16 *) (((char *) child1) + 0x22)) = *((u16 *) (((char *) arg0) + 6));
          var_v0 = *((u16 *) (((char *) arg0) + 4));
          child1 = *((void **) (((char *) temp_s0) + 4));
          var_v0 += 0xD0;
        }
        else
        {
          if (temp_a0 == 0xFF)
          {
            *((u16 *) (((char *) child1) + 0x22)) = *((u16 *) (((char *) arg0) + 6));
          }
          else
          {
            s32 count = func_80018318(*((void **) temp_s0));
            var_a1 = *((void **) (((char *) temp_s0) + 4));
            *((u16 *) (((char *) var_a1) + 0x22)) = (*((u16 *) (((char *) arg0) + 6))) + (count * 11);
          }
          child1 = *((void **) (((char *) temp_s0) + 4));
          var_v0 = *((u16 *) (((char *) arg0) + 4));
        }
        temp_v1 = child1;
        *((u16 *) (((char *) temp_v1) + 0x20)) = var_v0;
        {
          void *child;
          short mask = ~0xFC;
          if (gMenuUseTextList != 0)
          {
            child = *((void * volatile *) (((char *) temp_s0) + 4));
            var_v1 = *((s32 *) (((char *) child) + 0x28));
            do
            {
              var_v1 &= mask; var_v0_2 = inline_fn(temp_s2) & 0x1C;
            }
            while (0);
          }
          else
          {
            child = *((void * volatile *) (((char *) temp_s0) + 4));
            do
            {
              var_v1 = *((s32 *) (((char *) child) + 0x28)); var_v1 = var_v1 & mask;
            }
            while (0);
            var_v0_2 = inline_fn(temp_s2);
            var_v0_2 &= 7;
            var_v0_2 |= 2;
            var_v0_2 <<= 2;
          }
          var_v1 |= var_v0_2;
          *((s32 *) (((char *) child) + 0x28)) = var_v1;
        }
        {
          void *state = gSaveMenuState;
          if (state != NULL)
          {
            temp_a0_2 = *((void **) (((char *) state) + 0x1C));
            var_a1 = (void *) (-0x100);
            if (temp_a0_2 != NULL)
            {
              temp_v1 = *((void **) (((char *) temp_s0) + 4));
              var_v0_5 = sSaveMenuColorIdle;
              var_v0_5 &= ~0xFF;
              var_v1 = *(((u8 *) state) + 0x30); var_v0_5 |= var_v1;
              var_v0_5 &= ~0xFF;
              var_a0 = *(((u8 *) temp_a0_2) + 0x13); var_v0_5 |= var_a0;
              *((s32 *) (((char *) temp_v1) + 0x10)) = var_v0_5;
            }
          }
        }
      }
      temp_a0_2 = *((void **) (inline_fn2(temp_s0) + 0));
      if (temp_a0_2 != NULL)
      {
        if ((*((u8 *) (((char *) arg0) + 8))) == 0xFF) { var_v0_3 = 0xA0; } else { var_v0_3 = *((u16 *) (((char *) arg0) + 4)); }
        *((u16 *) (((char *) temp_a0_2) + 0x20)) = var_v0_3;
        *((u16 *) (inline_fn2(*((void **) (inline_fn2(temp_s0) + 0))) + 0x22)) = (u16) (*((u16 *) (((char *) arg0) + 6)));
        {
          void *child;
          short mask = ~0xFC;
 do { if (gMenuUseTextList != 0) { child = *((void * volatile *) (((char *) temp_s0) + 0)); var_v1_2 = *((s32 *) (((char *) child) + 0x28)); var_v1_2 &= mask; do { var_v0_4 = inline_fn(temp_s2) & 0x1C; } while (0); } else { child = *((void * volatile *) (((char *) temp_s0) + 0)); var_v1_2 = *((s32 *) (((char *) child) + 0x28)); do { var_v1_2 &= mask; var_v0_4 = inline_fn(temp_s2); var_v0_4 &= 7; var_v0_4 |= 2; var_v0_4 <<= 2; } while (0); } } while (0);
          var_v1_2 |= var_v0_4;
          *((s32 *) (((char *) child) + 0x28)) = var_v1_2;
        }
        temp_a0_4 = *((u8 *) (inline_fn2(arg0) + 8));
        if (temp_a0_4 == 0x80)
        {
          void *st = gSaveMenuState;
          s32 i = sSaveMenuColorIdle;
          temp_v1 = *((void **) temp_s0);
          *((s32 *) (((char *) temp_v1) + 0x10)) = (((i & (~0xFF)) | (*((u8 *) (((char *) st) + 0x30)))) & (~0xFF)) | (*((u8 *) (((char *) (*((void **) (((char *) st) + 0x1C)))) + 0x13)));
        }
        else if (temp_a0_4 == 0x81)
        {
          void *st = gSaveMenuState;
          s32 i = D_800BD660;
          temp_v1 = *((void **) temp_s0);
          *((s32 *) (((char *) temp_v1) + 0x10)) = (((i & (~0xFF)) | (*((u8 *) (((char *) st) + 0x30)))) & (~0xFF)) | (*((u8 *) (((char *) (*((void **) (((char *) st) + 0x1C)))) + 0x13)));
        }
        else
        {
          void *c = *((void **) temp_s0);
          void *st = gSaveMenuState;
          s32 i = sSaveMenuColorIdle;
          *((s32 *) (((char *) c) + 0x10)) = (i & (~0xFF)) | (*((u8 *) (((char *) st) + 0x30)));
        }
      }
      var_a0 = 2;
      if (gMenuUseTextList != 0)
      {
        if (temp_s0 || sSaveMenuColorIdle)
        {
          var_a0 = 0;
        }
        else
        {
          var_a0 = 0;
        }
      }
      func_80022B60(var_a0);
    }
  }
}

