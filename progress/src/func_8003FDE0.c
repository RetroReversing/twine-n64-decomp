void func_8003FDE0(u8 *arg0, s32 *arg1, s32 *arg2, s32 *arg3)
{
  u8 *p = arg0;
  unsigned int count;
  long m;
  u8 op;
  *arg1 = 0;
  *arg2 = 0;
  op = *p;
  while (op != 12) {
    switch (op) {

        case 9: p += 4; break;
        case 0: *arg1 = *arg1 + p[1]; p++; m = *p * 3; *arg3 = 0; p += m + 1; break;
        case 1: *arg1 = *arg1 + p[1]; p++; m = *p * 3; *arg3 = 1; goto double_size;
        case 3: *arg1 = *arg1 + p[1]; p++; m = *p; *arg3 = 3; p += m + 1; break;
        case 2: *arg1 = *arg1 + p[1]; p++; m = *p; *arg3 = 2; double_size: m *= 2; p += m + 1; break;
        case 6: p += 2; goto extra;
        case 7: p += 1; goto extra;
        case 8: p += 3;
        case 5: extra: count = p[1]; p += 2; *arg2 += count; p += count * 3; break;
        case 4: p += 4; *arg2 += 1; break;
        case 10: case 11: p += 2; break;
    }
    op = *p;
  }
}
