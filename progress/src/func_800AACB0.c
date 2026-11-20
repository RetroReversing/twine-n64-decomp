extern long long func_800ABE80(double);
extern double func_800ABFA0(long long);
extern long long D_800D1550[];
extern double D_800D6F70, D_800D6F78;
double func_800AACB0(double x) {
    long long result = 0;
    long long v = func_800ABE80(x * D_800D6F70);
    long long t;
    int i;
    for (i = 1; i < 54; i++) {
        t = v + (v >> i);
        if (t <= 0x0FFFFFFFFFFFFFFFLL) {
            v = t;
            result -= D_800D1550[i];
        }
    }
    return func_800ABFA0(result) / D_800D6F78;
}
