void MatMul3x3InPlace(void *, void *);
void func_800839F0(void *, void *, void *);
extern s32 (*D_800D9420)(s16 *, void *);
inline static f32 inline_fn(s16 *arg0)
{
  return *((f32 *) (((char *) arg0) + 8));
}

void func_80005868(s16 *arg0, void *arg1, void *arg2, s32 arg3)
{
  f32 vec[3];
  struct 
  {
    s16 rot[3];
    s16 pad;
    u8 matrices[0x930];
  } local;
  f32 var_ft0;
  f32 var_fv0;
  f32 var_fv1;
  s16 *var_s2;
  s32 var_s6;
  u32 temp_v1;
  void *temp_s0;
  void *temp_s1;
  void *var_s3;
  void *var_s5;
  var_s6 = 0; var_s5 = arg1;
  {
    u8 *base = local.matrices;
    if ((*arg0) >= 0)
    {
      var_s2 = arg0; var_s3 = arg2;
      __repair_rows:
      {
        s32 index = *var_s2;
 do { temp_v1 = *((u32 *) (((char *) var_s5) + 0x14)); temp_s1 = base + ((index * 3) * 16); local.rot[0] = (temp_v1 >> 22) * 4; local.rot[1] = (temp_v1 >> 10) & 0xffe; local.rot[2] = (temp_v1 * 2) & 0xffe; D_800D9420(&local.rot[0], temp_s1); if (var_s6 == 0) { f32 x; f32 y; f32 z; x = *((f32 *) (((char *) arg1) + 8)); y = *((f32 *) (((char *) arg1) + 0xc)); z = *((f32 *) (((char *) arg1) + 0x10)); if (arg3 == 0) { z = 0.0f; y = 0.0f; x = 0.0f; } *((f32 *) (((char *) temp_s1) + 0x24)) = x; *((f32 *) (((char *) temp_s1) + 0x28)) = y; *((f32 *) (((char *) temp_s1) + 0x2c)) = z; } else { temp_s0 = base + ((*((s16 *) (((char *) var_s2) + 2))) * 0x30); var_fv0 = *((f32 *) (((char *) var_s2) + 4)); var_fv1 = inline_fn(var_s2); var_ft0 = *((f32 *) (((char *) var_s2) + 0xc)); vec[0] = var_fv0; vec[1] = var_fv1; vec[2] = var_ft0; func_800839F0(temp_s0, &vec[0], temp_s1 + 0x24); *((f32 *) (((char *) temp_s1) + 0x24)) += *((f32 *) (((char *) temp_s0) + 0x24)); *((f32 *) (((char *) temp_s1) + 0x28)) += *((f32 *) (((char *) temp_s0) + 0x28)); *((f32 *) (((char *) temp_s1) + 0x2c)) += *((f32 *) (((char *) temp_s0) + 0x2c)); MatMul3x3InPlace(temp_s0, temp_s1); } { s32 next; f32 x = *((f32 *) (((char *) temp_s1) + 0x24)); var_s2 += 16; __repair_rows_: { do { do { next = *var_s2; } while (0); } while (0); } if (0) { goto __repair_rows_; } *((f32 *) (((char *) var_s3) + 0)) = x; *((f32 *) (((char *) var_s3) + 4)) = *((f32 *) (((char *) temp_s1) + 0x28)); var_s5 += 4; var_s6++; *((f32 *) (((char *) var_s3) + 8)) = *((f32 *) (((char *) temp_s1) + 0x2c)); var_s3 += 0xc; if (next >= 0) { goto __repair_rows; } } } while (0);
      }

    }
  }
}

