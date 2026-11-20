extern s64 D_800D1550[];
extern f64 D_800D6F20, D_800D6F28;
s64 func_800ABE80(f64);
f64 func_800ABFA0(s64);
f64 func_800AAA20(f64 x) {
    s64 result = 0x1000000000000000LL;
    s64 value = func_800ABE80(x * D_800D6F20);
    s32 i;
    for (i = 1; i < 0x36; i++) {
        s64 diff = D_800D1550[i] - value;
        if (diff <= 0) {
            value = -diff;
            result += result >> i;
        }
    }
    return func_800ABFA0(result) / D_800D6F28;
}
