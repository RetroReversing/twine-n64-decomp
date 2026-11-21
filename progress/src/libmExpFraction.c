extern s64 sExpLogTable[];
extern f64 kFixed60Scale, kFixed60One;
s64 f64ToFixed60(f64);
f64 fixed60ToF64(s64);
/* Computes exp(x) for fractional x in fixed point with a shift-and-add table walk, returning a double. */ f64 libmExpFraction(f64 x) {
    s64 expAccum = 0x1000000000000000LL;
    s64 remainder = f64ToFixed60(x * kFixed60Scale);
    s32 shift;
    for (shift = 1; shift < 0x36; shift++) {
        s64 delta = sExpLogTable[shift] - remainder;
        if (delta <= 0) {
            remainder = -delta;
            expAccum += expAccum >> shift;
        }
    }
    return fixed60ToF64(expAccum) / kFixed60One;
}
