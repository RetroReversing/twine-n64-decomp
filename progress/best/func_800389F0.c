void func_800344DC(void);
extern s16 D_80108F80;
extern volatile s16 D_8010D6F8;
extern void * volatile sDisplayListCursor;
inline static f32 inline_fn(void *arg0)
{
  return *((f32 *) (((char *) arg0) + 0x58));
}

inline static volatile int inline_fn2(s32 arg0)
{
  return ((((unsigned short) arg0) - 1) & 0x3FF) << 0xE;
}

void func_800389F0(void *arg0)
{
  f32 temp_fv1;
  f32 temp_fv1_2;
  f32 temp_fv1_3;
  f32 temp_fv1_4;
  f32 temp_fv1_5;
  f32 temp_fv1_6;
  s32 y;
  f32 position;
  f32 edge;
  s32 right;
  s32 bottom;
  s32 var_t8;
  s32 var_v0;
  s32 var_v0_4;
  void *temp_a0;
  void *temp_a0_2;
  void *temp_v0;
  void *temp_v1;
  void *temp_v1_2;
  void *temp_v1_3;
  if ((*((s32 *) (((char *) arg0) + 0x100))) & 0x10)
  {
    func_800344DC();
    temp_v0 = sDisplayListCursor;
    *((s32 *) (((char *) temp_v0) + 0)) = 0xE7000000;
    *((s32 *) (((char *) temp_v0) + 0xC)) = 0x300000;
    *((s32 *) (((char *) temp_v0) + 4)) = 0;
    *((s32 *) (((char *) temp_v0) + 8)) = 0xE3000A01;
    *((s32 *) (((char *) temp_v0) + 0x10)) = 0xE200001C;
    *((s32 *) (((char *) temp_v0) + 0x14)) = 0x0F0A4000;
    *((s32 *) (((char *) temp_v0) + 0x18)) = 0xF7000000;
    *((s32 *) (((char *) temp_v0) + 0x1C)) = 0;
    position = *((f32 *) (((char *) arg0) + 0x64));
 do { edge = *((f32 *) (((char *) arg0) + 0x58)); sDisplayListCursor = temp_v0 + 8; sDisplayListCursor = temp_v0 + 0x10; sDisplayListCursor = temp_v0 + 0x18; } while (0);
    temp_v1 = temp_v0 + 0x20;
    sDisplayListCursor = temp_v1 + 8;
    sDisplayListCursor = temp_v1;
    temp_fv1 = position + edge;
    y = ((D_8010D6F8 - 1) & 0x3FF) << 14;
    var_v0 = ((u32) temp_fv1) & 0x3FF;
    temp_a0 = sDisplayListCursor;
    bottom = D_8010D6F8;
    *((s32 *) (((char *) temp_v1) + 0)) = (s32) (((var_v0 * 4) | 0xF6000000) | y);
    right = D_80108F80;
    *((s32 *) (((char *) temp_v1) + 4)) = 0;
    *((s32 *) (((char *) temp_a0) + 0)) = (s32) (((((right - 1) & 0x3FF) * 4) | 0xF6000000) | inline_fn2(bottom));
    temp_fv1_2 = ((*((f32 *) (((char *) arg0) + 0x64))) + (*((f32 *) (((char *) arg0) + 0x5C)))) - 1.0f;
    sDisplayListCursor = temp_a0 + 8;
    var_t8 = (u32) temp_fv1_2;
    temp_v1_2 = sDisplayListCursor;
    *((s32 *) (((char *) temp_a0) + 4)) = (s32) ((var_t8 & 0x3FF) * 4);
    *((s32 *) (((char *) temp_v1_2) + 0x20)) = 0xFA000000;
    *((s32 *) (((char *) temp_v1_2) + 0)) = 0xE7000000;
    *((s32 *) (((char *) temp_v1_2) + 0x24)) = 0x80;
    *((s32 *) (((char *) temp_v1_2) + 4)) = 0;
    *((s32 *) (((char *) temp_v1_2) + 8)) = 0xE3000A01;
    *((s32 *) (((char *) temp_v1_2) + 0xC)) = 0;
    *((s32 *) (((char *) temp_v1_2) + 0x10)) = 0xFCFFFFFF;
    *((s32 *) (((char *) temp_v1_2) + 0x14)) = 0xFFFDF6FB;
    *((s32 *) (((char *) temp_v1_2) + 0x18)) = 0xE200001C;
    *((s32 *) (((char *) temp_v1_2) + 0x1C)) = 0x5040C0;
    *((s32 *) (((char *) temp_v1_2) + 0x28)) = 0xD9C0F9FA;
    *((s32 *) (((char *) temp_v1_2) + 0x2C)) = 0;
    *((s32 *) (((char *) temp_v1_2) + 0x30)) = 0xD9FFFFFF;
    *((s32 *) (((char *) temp_v1_2) + 0x34)) = 0x200004;
    *((s32 *) (((char *) temp_v1_2) + 0x38)) = 0xE7000000;
    *((s32 *) (((char *) temp_v1_2) + 0x3C)) = 0;
    *((s32 *) (((char *) temp_v1_2) + 0x40)) = 0xE3001001;
    *((s32 *) (((char *) temp_v1_2) + 0x44)) = 0x8000;
    *((s32 *) (((char *) temp_v1_2) + 0x48)) = 0xD7000002;
    *((s32 *) (((char *) temp_v1_2) + 0x4C)) = 0x80008000;
    temp_fv1_3 = (*((f32 *) (((char *) arg0) + 0x64))) + inline_fn(arg0);
    sDisplayListCursor = temp_v1_2 + 8;
    sDisplayListCursor = temp_v1_2 + 0x10;
    sDisplayListCursor = temp_v1_2 + 0x18;
    sDisplayListCursor = temp_v1_2 + 0x20;
    sDisplayListCursor = temp_v1_2 + 0x28;
    sDisplayListCursor = temp_v1_2 + 0x30;
    sDisplayListCursor = temp_v1_2 + 0x38;
    sDisplayListCursor = temp_v1_2 + 0x40;
    temp_a0_2 = temp_v1_2 + 0x50;
    sDisplayListCursor = temp_v1_2 + 0x48;
    sDisplayListCursor = temp_a0_2;
    y = *((volatile u16 *) (&D_8010D6F8));
    temp_fv1_3 += 2.0f;
    sDisplayListCursor = temp_v1_2 + 0x58;
    y = (y & 0x3FF) << 14;
    var_v0 = ((u32) temp_fv1_3) & 0x3FF;
    *((s32 *) (((char *) temp_a0_2) + 0)) = (s32) (((var_v0 * 4) | 0xF6000000) | y);
    temp_fv1_4 = (*((f32 *) (((char *) arg0) + 0x64))) + (*((f32 *) (((char *) arg0) + 0x58)));
    var_v0 = ((u32) temp_fv1_4) & 0x3FF;
    *((s32 *) (((char *) temp_a0_2) + 4)) = (s32) (var_v0 * 4);
    temp_v1_3 = sDisplayListCursor;
    temp_fv1_5 = (*((f32 *) (((char *) arg0) + 0x64))) + (*((f32 *) (((char *) arg0) + 0x5C)));
    sDisplayListCursor = temp_v1_3 + 8;
    y = (((u16) D_8010D6F8) & 0x3FF) << 14;
    var_v0_4 = ((u32) temp_fv1_5) & 0x3FF;
    *((s32 *) (((char *) temp_v1_3) + 0)) = (s32) (((var_v0_4 * 4) | 0xF6000000) | y);
    temp_fv1_6 = ((*((f32 *) (((char *) arg0) + 0x64))) + (*((f32 *) (((char *) arg0) + 0x5C)))) - 2.0f;
    var_v0_4 = ((u32) temp_fv1_6) & 0x3FF;
    *((s32 *) (((char *) temp_v1_3) + 4)) = (s32) (var_v0_4 * 4);
  }
}
