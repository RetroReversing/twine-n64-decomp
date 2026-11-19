s32 func_800AB770(const u8 *str1, const u8 *str2)
{
  s32 diff;
  u32 c;
  u32 word0;
  u32 word1;

  if (((u32) str1 - (u32) str2) & 3)
  {
    for (;;)
    {
      c = *str1++;
      diff = c - *str2++;
      if (diff != 0 || c == 0)
        return diff;
    }
  }
  while ((u32) str1 & 3)
  {
    c = *str1++;
    diff = c - *str2++;
    if (diff != 0 || c == 0)
      return diff;
  }
  for (;;)
  {
    word0 = *(const u32 *) str1;
    str1 += 4;
    word1 = *(const u32 *) str2;
    diff = word0 - word1;
    str2 += 4;
    if (diff != 0)
    {
      if (!(word0 & 0xFF000000))
        diff = 0xFF000000;
      else if (!(word0 & 0xFF0000))
        diff = 0xFFFF0000;
      else if (!(word0 & 0xFF00))
        diff = 0xFFFFFF00;
      else
        return diff;
      return (word0 & diff) - (word1 & diff);
    }
    if ((word0 << 24) == 0 || !(word0 & 0xFF00) || !(word0 & 0xFF0000) || !(word0 & 0xFF000000))
      return diff;
  }
}
