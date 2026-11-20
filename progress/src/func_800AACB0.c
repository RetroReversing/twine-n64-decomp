extern long long f64ToFixed60(double);
extern double fixed60ToF64(long long);
extern long long D_800D1550[];
extern double D_800D6F70, D_800D6F78;
double func_800AACB0(double x) {
    long long result = 0;
    long long v = f64ToFixed60(x * D_800D6F70);
    long long t;
    int i;
    for (i = 1; i < 54; i++) {
        t = v + (v >> i);
        if (t <= 0x0FFFFFFFFFFFFFFFLL) {
            v = t;
            result -= D_800D1550[i];
        }
    }
    return fixed60ToF64(result) / D_800D6F78;
}
