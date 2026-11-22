void func_8003FDE0(u8 *arg0, s32 *arg1, s32 *arg2, s32 *arg3)
{
  u8 *p = arg0;
  long raw;
  long raw_arm;
  s32 __repair_phase_raw;
  u32 opcode;
  unsigned int count;
  *arg1 = 0;
  *arg2 = 0;
  raw = *p;
  if (((u8) raw) != 12)
  {
    if (__repair_phase_raw || arg3)
    {
      opcode = raw & 255;
    }
    else
    {
      opcode = raw & 255;
    }
    do
    {
      switch (opcode)
      {
        case 9:
          p += 4;
          break;

        case 0:
          *arg1 = (*arg1) + p[1];
          p++;
          raw_arm = *p;
          *arg3 = 0;
          raw_arm *= 3;
          p += raw_arm + 1;
          break;

 do { case 1: { long long phantom_wide = raw_arm; } *arg1 = (*arg1) + p[1]; p++; raw_arm = *p; *arg3 = 1; raw_arm *= 3; goto double_size; case 3: *arg1 = (*arg1) + p[1]; p++; raw_arm = *p; *arg3 = 3; p += raw_arm - (-1); break; case 2: *arg1 = (*arg1) + p[1]; p++; raw_arm = *p; *arg3 = 2; double_size: raw_arm *= 2; p += raw_arm + 1; break; case 6: p += 2; goto extra; case 7: p += 1; goto extra; case 8: p += 3; case 5: extra: count = p[1]; p += 2; *arg2 += count; p += count * 3; break; case 4: p += 4; *arg2 += 1; break; case 10: case 11: p += 2; break; } while (0);
      }

      __repair_phase_raw = *p;
      opcode = __repair_phase_raw & 255;
    }
    while (__repair_phase_raw != 12);
  }
}
