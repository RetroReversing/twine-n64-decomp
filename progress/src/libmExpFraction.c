extern s64 sExpLogTable[];
extern f64 kFixed60Scale, kFixed60One;
s64 f64ToFixed60(f64);
f64 fixed60ToF64(s64);
f64 libmExpFraction(f64 x) {
    s64 result = 0x1000000000000000LL;
    s64 value = f64ToFixed60(x * kFixed60Scale);
    s32 i;
    for (i = 1; i < 0x36; i++) {
        s64 diff = sExpLogTable[i] - value;
        if (diff <= 0) {
            value = -diff;
            result += result >> i;
        }
    }
    return fixed60ToF64(result) / kFixed60One;
}
