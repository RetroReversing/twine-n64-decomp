extern s64 gCordicAtanTable[]; extern f64 D_800D6EC0; extern f64 fixed60ToF64(s64);
void func_800AA5E0(s64 xin, s64 yin, f64 *out) {
    s64 x = xin, z = 0, next;
    s32 i = 0;
    do {
        if (yin >= 0) {
            next = x + (yin >> i);
            yin -= x >> i;
            z += gCordicAtanTable[i];
        } else {
            next = x - (yin >> i);
            yin += x >> i;
            z -= gCordicAtanTable[i];
        }
        x = next;
        i++;
    } while (i < 52);
    *out = fixed60ToF64(z) / D_800D6EC0;
}
