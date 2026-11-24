extern u32 gRandomStateLo;
extern u32 gRandomStateHi;

/* Advances the 64-bit random generator state by one step (lo += hi; hi += lo + sign bit of lo). */ void randomU32Next(void) {
    u32 lo = gRandomStateLo;
    u32 hi = gRandomStateHi;
    lo += hi;
    hi += (lo) + ((lo >> 31));
    gRandomStateLo = lo;
    gRandomStateHi = hi;
}
