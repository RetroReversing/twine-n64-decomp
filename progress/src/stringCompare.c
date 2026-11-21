/* Compares two NUL-terminated strings like strcmp, scanning a word at a time once aligned. */ s32 stringCompare(const u8 *lhs, const u8 *rhs)
{
  s32 diff;
  u32 ch;
  u32 lhsWord;
  u32 rhsWord;

  if (((u32) lhs - (u32) rhs) & 3)
  {
    for (;;)
    {
      ch = *lhs++;
      diff = ch - *rhs++;
      if (diff != 0 || ch == 0)
        return diff;
    }
  }
  while ((u32) lhs & 3)
  {
    ch = *lhs++;
    diff = ch - *rhs++;
    if (diff != 0 || ch == 0)
      return diff;
  }
  for (;;)
  {
    lhsWord = *(const u32 *) lhs;
    lhs += 4;
    rhsWord = *(const u32 *) rhs;
    diff = lhsWord - rhsWord;
    rhs += 4;
    if (diff != 0)
    {
      if (!(lhsWord & 0xFF000000))
        diff = 0xFF000000;
      else if (!(lhsWord & 0xFF0000))
        diff = 0xFFFF0000;
      else if (!(lhsWord & 0xFF00))
        diff = 0xFFFFFF00;
      else
        return diff;
      return (lhsWord & diff) - (rhsWord & diff);
    }
    if ((lhsWord << 24) == 0 || !(lhsWord & 0xFF00) || !(lhsWord & 0xFF0000) || !(lhsWord & 0xFF000000))
      return diff;
  }
}
