void *func_80016410(s32, s32, s32);
s32 func_80016990(void *, s32);
s32 func_80044670(void *, s16, s32);
s32 func_80045278(void *);
s32 func_80045CF8(s32);
f32 func_80045D2C(f32);
f32 func_80045D8C(f32, f32);
s32 func_80045DB4(f32 *, f32, f32);
s32 func_800617D8(s32, s32, void *, f32 *, f32, f32, s32, s32, s32, s32, s32);
s32 func_80062450(s32, f32 *);
s32 func_80073508(s32, f32);
s32 func_800853D4(s32);
extern s8 D_800B2715;
extern f64 D_800D4270;
extern f64 D_800D4278;
extern f64 D_800D4280;
extern f64 D_800D4288;
extern f64 D_800D4290;
extern s32 D_80102ED8;
inline static char *inline_fn(void *arg0, int arg1)
{
  return ((char *) arg0) + arg1;
}

void func_800624A8(void *arg0, s32 arg1, f32 arg2, s32 arg3)
{
  f32 sp30[7];
  f32 temp_fs0;
  f32 temp_fs1;
  f32 temp_fs2;
  f32 temp_fs2_2;
  f32 temp_fs4;
  f64 temp_fs1_2;
  f64 temp_fs5;
  f64 temp_fv1;
  s16 temp_v0_2;
  u32 var_fp;
  u32 var_s1;
  u32 var_s6;
  union 
  {
    void *pointer;
    u32 value;
  } __repair_phase_storage;
  if (D_80102ED8 != 0)
  {
    var_fp = 2;
    do
    {
      var_s6 = 0;
    }
    while (0);
  }
  else
  {
    var_fp = 3; var_s6 = 4;
  }
  func_800617D8(*((s32 *) (((char *) arg0) + 0x20)), arg0 + 0x24, arg0 + 0x3C, NULL, 0.75f, 1.05f, 0x1D, 0xFB, 0x22, 0xFFFF00FF, 0x7F7F8110);
  func_80073508(arg1, arg2 * 0.001f);
 do { if ((arg3 & 0xFF) && (D_800B2715 == 0)) { func_800853D4(arg1); } for (var_s1 = 0; var_s1 < 2U; ++var_s1) { __repair_phase_storage.pointer = func_80016410(0, arg1, 0); if (__repair_phase_storage.pointer != NULL) { temp_fs2 = arg2 * 0.5f; *((s32 *) (((char *) __repair_phase_storage.pointer) + 0x3C)) = 0; *((s32 *) (((char *) __repair_phase_storage.pointer) + 0x40)) = 0; temp_fs1 = arg2 * 0.25f; temp_fs0 = func_80045D2C(2048.0f); *((f32 *) (((char *) __repair_phase_storage.pointer) + 0x44)) = (f32) ((temp_fs0 + 2048.0f) - func_80045D2C(1024.0f)); *((f32 *) (((char *) __repair_phase_storage.pointer) + 0x24)) = (f32) ((*((f32 *) (((char *) __repair_phase_storage.pointer) + 0x24))) + func_80045D8C(temp_fs2, temp_fs1)); *((f32 *) (((char *) __repair_phase_storage.pointer) + 0x28)) = (f32) ((*((f32 *) (((char *) __repair_phase_storage.pointer) + 0x28))) + func_80045D8C(temp_fs2, temp_fs1)); *((f32 *) (((char *) __repair_phase_storage.pointer) + 0x2C)) = (f32) ((*((f32 *) (((char *) __repair_phase_storage.pointer) + 0x2C))) + func_80045D8C(temp_fs2, temp_fs1)); func_80045278(arg0 + 0x3C); temp_v0_2 = func_80045CF8(0x10); *((u16 *) (((char *) __repair_phase_storage.pointer) + 0x7A)) = temp_v0_2; func_80044670(__repair_phase_storage.pointer, temp_v0_2, 0xFB); *((u8 *) (((char *) __repair_phase_storage.pointer) + 0x7F)) = 0xFF; *((u8 *) inline_fn(__repair_phase_storage.pointer, 0x80)) = 0; *((u8 *) (((char *) __repair_phase_storage.pointer) + 0x81)) = 0; temp_fv1 = ((f64) (arg2 * 1.5f)) + (((f64) func_80045D2C(arg2)) * D_800D4270); *((u16 *) (((char *) __repair_phase_storage.pointer) + 0x78)) = 0x32; *((volatile f32 *) (((char *) __repair_phase_storage.pointer) + 0x54)) = (f32) temp_fv1; *((volatile f32 *) (((char *) __repair_phase_storage.pointer) + 0x54)) = arg2; func_80016990(__repair_phase_storage.pointer, *((s32 *) (((char *) arg0) + 0x20))); } } var_s1 = 0; if (var_fp != 0) { temp_fs1_2 = (f64) arg2; temp_fs5 = temp_fs1_2 * D_800D4278; temp_fs4 = arg2 * 0.2f; do { f32 __repair_loop_fzero = 0.0f; if (temp_fs1_2) { sp30[2] = 0.0f; sp30[1] = 0.0f; sp30[0] = 0.0f; func_80045DB4(sp30, (f32) temp_fs5, temp_fs4); } else { sp30[2] = 0.0f; sp30[1] = 0.0f; sp30[0] = 0.0f; func_80045DB4(sp30, (f32) temp_fs5, temp_fs4); } if (sp30[1] < 0.0f) { sp30[1] = -sp30[1]; } temp_fs2_2 = (f32) (temp_fs1_2 * D_800D4280); func_80062450(func_800617D8(*((s32 *) (((char *) arg0) + 0x20)), arg1, NULL, sp30, temp_fs2_2, (f32) (temp_fs1_2 * D_800D4288), 0x19, 0xFB, 0x33, 0x80, 0x80808001), sp30); sp30[2] = 0.0f; sp30[1] = 0.0f; sp30[0] = __repair_loop_fzero; func_80045DB4(sp30, temp_fs4, arg2 * 0.1f); if (sp30[1] < 0.0f) { sp30[1] = -sp30[1]; } if (D_80102ED8 == 0) { func_80062450(func_800617D8(*((s32 *) (((char *) arg0) + 0x20)), arg1, NULL, sp30, temp_fs2_2, (f32) (temp_fs1_2 * D_800D4290), 0x1A, 0xFB, 0x33, 0xFF, 0x80808004), sp30); __repair_phase_storage.value = 0; if (var_s6) { do { sp30[2] = __repair_loop_fzero; sp30[1] = __repair_loop_fzero; sp30[0] = __repair_loop_fzero; func_80045DB4(sp30, arg2 * 0.6f, arg2 * 0.3f); if (sp30[1] < 0.0f) { sp30[1] = -sp30[1]; } func_80062450(func_800617D8(*((s32 *) (((char *) arg0) + 0x20)), arg1, NULL, sp30, 1.0f, 0.0f, func_80045CF8(2) + 0x17, 0xFB, 0x68, 0xFF0000FF, 4), sp30); __repair_phase_storage.value += 1; } while (__repair_phase_storage.value < var_s6); } } var_s1 += 1; } while (var_s1 < var_fp); } } while (0);
}
