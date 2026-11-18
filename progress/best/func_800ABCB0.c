/* Partial candidate from function #30064772360 in project #7; rechecked locally. */
u64 func_800ABAE8(u64 a, u64 b);
u64 func_800ABBE4(u64 a, u64 b);

s64 func_800ABCB0(s64 a, s64 b) {
    s64 neg;
    s64 r;

    neg = a ^ b;
    if (a < 0) {
        a = ~a + 1;
    }
    if (b < 0) {
        b = ~b + 1;
    }
    if (neg < 0) {
        if (b >> 32) {
            r = func_800ABAE8(a, b);
        } else {
            r = func_800ABBE4(a, b);
        }
        r = ~r + 1;
    } else {
        if (b >> 32) {
            r = func_800ABAE8(a, b);
        } else {
            r = func_800ABBE4(a, b);
        }
    }
    return r;
}
