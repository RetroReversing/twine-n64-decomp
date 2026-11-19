/* Partial candidate from function #30064772362 in project #7; rechecked locally. */
s64 func_800ABE80(f64 arg0) {
int __repair_literal;

    u32 lo;
    register u32 e;
    f64 d;
    unsigned mh;
    unsigned int hi;
    u32 s;
    unsigned long r;

    hi = ((u32 *)&d)[0];
    lo = ((u32 *)&d)[1];
    d = arg0;
    e = (hi >> 20) & 0x7FF;
    if (0x3FF > e) {
        return 0;
    }
    e = e - 0x3FF;
    if (0x40 > e) {
        mh = (hi & 0xFFFFF) | 0x100000;
        if (e >= 0x34) {
            s = (unsigned short)e - 0x34;
            if (s != 0) {
                mh = (mh << (u32)s) | (lo >> (0x20 - s));do{do{do{
                lo = lo << s;}while(0);}while(0);}while(0);
            }
        } else {
            r = 0x34 - (unsigned short)e;
__repair_literal = 0x20;

            if (r >= __repair_literal) {
                register lo = mh >> (r - 0x20);
                mh = 0;
            } else {
                lo = (lo >> r) | (mh << (0x20 - r));
                mh = mh >> r;
            }
        }
        if (hi & 0x80000000) {
            lo = -lo;
            mh = ~mh + (!lo);
        }
        return ((u64)mh << 32) | lo;
    }
    return 0x8000000000000000ULL;
}
