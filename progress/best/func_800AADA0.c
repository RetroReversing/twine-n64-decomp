extern double func_800AACB0(double);
extern double func_800ABA40(int, char *, double, double, double);
extern double func_800AC0A0(double, int *);
extern char D_800D6F80[];
extern double D_800D6F88, D_800D6F90;
double func_800AADA0(double x) {
    volatile union { double d; unsigned int w[2]; unsigned long long bits; } u;
    int n;
    double y;
    if (x < 0.0) return func_800ABA40(1,D_800D6F80,x,0.0,0.0);
    if (x == 0.0) { u.bits=0xfff0000000000000ULL; return func_800ABA40(3,D_800D6F80,x,0.0,u.d); }
    if (x == D_800D6F88) return 0.0;
    y=func_800AACB0(func_800AC0A0(x,&n));
    u.d = y;
    y = (double)n * D_800D6F90 + y;
    u.d = y;
    return y;
}
