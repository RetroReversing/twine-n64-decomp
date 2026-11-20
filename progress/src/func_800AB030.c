extern s64 func_800ABE80(f64);
extern f64 func_800ABFA0(s64);
extern s64 D_800D1250[];
extern f64 D_800D6FA0, D_800D6FA8;
void func_800AB030(f64 angle, f64 *out1, f64 *out2) {
    s64 x = 0x09B74EDA8435E580LL;
    s64 y = 0;
    s64 z = func_800ABE80(angle * D_800D6FA0);
    s64 t;
    int i;
    for (i = 0; i < 52; i++) {
        if (z >= 0) {
            t = x - (y >> i);
            y += x >> i;
            z -= D_800D1250[i];
        } else {
            t = x + (y >> i);
            y -= x >> i;
            z += D_800D1250[i];
        }
        x = t;
    }
    { f64 val = func_800ABFA0(y);
    f64 scale = D_800D6FA8;
    *out1 = val / scale;
    *out2 = func_800ABFA0(x) / scale; }
}
