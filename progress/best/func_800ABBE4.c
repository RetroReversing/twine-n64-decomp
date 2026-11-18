/* Partial candidate from function #30064772359 in project #7; rechecked locally. */
u64 func_800ABBE4(u32 arg0, u32 arg1, u32 arg2, u32 arg3)
{
  union _PermuterAnon1
  {
    u64 whole;
    struct 
    {
      u32 hi;
      int lo;
    } word;
  } product;
  u32 hi;
  u32 rem;
  union _PermuterAnon1 result;
  u32 qlo;
  u32 v0;
  register unsigned long v1;
  u32 t;
  u32 prodlo;
  u32 prodhi;
  u32 borrow;
 do { hi = arg0 / arg3; rem = arg0 % arg3; qlo = 0; loop: if (rem) { v1 = arg1; v0 = rem; t = arg3; do { v1 = (v1 >> 1) | (v0 << 31); v0 >>= 1; t >>= 1; } while (v0); ++t; v1 /= t;/*__repair_loop_weight*/do { qlo += v1;} while (0); hi += qlo < v1; product.whole = ((u64) v1) * arg3; v0 = product.word.lo; prodhi = product.word.hi; borrow = arg1 < v0; arg1 -= v0; rem = (rem - borrow) - (unsigned short)prodhi; goto loop; } v1 = arg1 / arg3; v1 += qlo; hi += v1 < qlo; } while (0);
  result.word.lo = v1;
  result.word.hi = hi;
  return result.whole;
}
