extern s32 D_80107EDC;
extern s32 D_80107EE0;
extern s32 D_80107EE8;
u32 func_8008EF18(s32 arg0)
{
  s32 index = arg0 & 0xff;
  s32 scaled = (index * 5) << 3;
  u32 result;
  u32 __repair_result_2;
  result = *((u8 *) (((s8 *) (&D_80107EE8)) + scaled));
  if (result == 4)
  {
    goto __shared_return_0;
  }
  result = *((u32 *) (((s8 *) (&D_80107EE0)) + scaled));
  if (result == 0)
  {
    __shared_return_0:
    return 0;

  }
  if (index)
  {
    __repair_result_2 = *((u32 *) (((s8 *) (&D_80107EDC)) + scaled));
    return __repair_result_2 >> 31;
  }
  else
  {
    __repair_result_2 = *((u32 *) (((s8 *) (&D_80107EDC)) + scaled));
    return __repair_result_2 >> 31;
  }
}

