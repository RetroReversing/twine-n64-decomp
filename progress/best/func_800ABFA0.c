/* Partial candidate from function #30064772363 in project #7; rechecked locally. */
f64 func_800ABFA0(u32 arg0, u32 arg1) {
    u32 sign;
    register unsigned exp;
    unsigned int lo;
    unsigned long hi;
    u32 w[2];

    hi = arg0;
    lo = arg1;
    if ((hi | lo) == 0) {
        w[0] = hi;
        w[1] = lo;
        return *(f64 *)w;
    }
    sign = 0;
    if (hi & 0x80000000u) {
        register lo = -lo;
        register hi = -hi - (lo);
        sign = 0x80000000u;
    }
    exp = 0;
    if (hi & 0xFFE00000) {
        __repair_rows: {
            lo = (lo >> 1) | (hi << 31);
            hi = hi >> 1;
            ++exp;
        }
if (hi & 0xFFE00000) goto __repair_rows;
    } else {
        while (!(hi & 0x100000)) {
            register hi = (hi << 1) | (lo >> 31);
            register lo = lo << 1;
            exp -= 1;
        }
    }
    w[1] = lo;
    w[0] = (hi & 0xFFFFF) | sign | (((int)exp + 0x433) << 20);
    return *(f64 *)w;
}
