s32 func_8008EB80();
extern unsigned char gSoundEntities[];
extern unsigned char D_800E5FEC[];
extern unsigned char D_800E6A85[];
extern unsigned char D_800E6A88[];
extern unsigned char D_800E6AA4[];
extern unsigned char D_800E6AB2[];
extern unsigned char D_800E6AB4[];
void func_80091654(s32 arg0, s32 arg1, s32 arg2, s32 arg3)
{
  s32 temp_a2_2;
  s32 __repair_phase_temp_a2_2;
  s32 __repair_phase_temp_a3;
  s32 var_a2;
  s32 var_v0;
  s32 __repair_phase_var_v0;
  s8 var_v1_2;
  u32 var_s0;
  u8 temp_a2;
  void *temp_s2;
  s32 scanOffset = 0;
  temp_a2_2 = arg2 & 0x7FFFFFFF;
  var_s0 = 0;
  do
  {
    if ((D_800E6A85[scanOffset] == 0) && ((*((s32 *) (gSoundEntities + scanOffset))) == temp_a2_2))
    {
      var_a2 = var_s0 | (arg2 & 0x80000000);
      goto found;
    }
    var_s0++;
    scanOffset += 0xFF8;
  }
  while (var_s0 < 8U);
  var_a2 = -1;
  found:
  if (var_a2 != (-1))
  {
    if (var_a2 >= 0)
    {
      var_s0 = var_a2 * 0xFF8;
      func_8008EB80(arg0 & 0xFF, arg1 & 0xFFFF, *(D_800E6A88 + var_s0), arg3 & 0xFF, arg2);
      do
      {
 do { __repair_phase_temp_a2_2 = var_s0; var_s0 += (u32) D_800E5FEC; } while (0);
        temp_s2 = (void *) (var_s0 + 0x40);
      }
      while (0);
      do
      {
        temp_a2 = *((u8 *) var_s0);
        if (temp_a2 != (*(D_800E6A88 + __repair_phase_temp_a2_2)))
        {
          func_8008EB80(arg0 & 0xFF, arg1 & 0xFFFF, temp_a2, 0, 0);
        }
        var_s0 += 1;
      }
      while (((u32) var_s0) < ((u32) temp_s2));
    }
    else
    {
      temp_a2_2 = var_a2 & 0x7FFFFFFF;
      __repair_phase_temp_a3 = arg3 & 0xF;
      switch (__repair_phase_temp_a3)
      {
        case 0:
          *(D_800E6AA4 + (temp_a2_2 * 0xFF8)) = arg0;
          return;

        case 1:
          *((s32 *) (D_800E6AB4 + (temp_a2_2 * 0xFF8))) = 0;
          return;

        case 2:
          var_v0 = temp_a2_2 * 0xFF8;
          *(D_800E6AA4 + var_v0) = arg0;
          var_v1_2 = (*(D_800E6AB2 + var_v0)) | 8;
          *(D_800E6AB2 + var_v0) = var_v1_2;
          break;

        case 3:
          __repair_phase_var_v0 = temp_a2_2 * 0xFF8;
          *(D_800E6AA4 + __repair_phase_var_v0) = arg0;
          var_v1_2 = (*(D_800E6AB2 + __repair_phase_var_v0)) | 0x80;
          *(D_800E6AB2 + __repair_phase_var_v0) = var_v1_2;
          break;

      }

    }
  }

}
