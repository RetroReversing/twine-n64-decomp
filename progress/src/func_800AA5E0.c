extern s64 D_800D1250[]; extern f64 D_800D6EC0; extern f64 func_800ABFA0(s64);
void func_800AA5E0(s64 xin, s64 yin, f64 *out) {
    s64 x = xin, z = 0, next;
    s32 i = 0;
    do {
        if (yin >= 0) {
            next = x + (yin >> i);
            yin -= x >> i;
            z += D_800D1250[i];
        } else {
            next = x - (yin >> i);
            yin += x >> i;
            z -= D_800D1250[i];
        }
        x = next;
        i++;
    } while (i < 52);
    *out = func_800ABFA0(z) / D_800D6EC0;
}
