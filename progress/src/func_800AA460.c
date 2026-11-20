double sqrt(double);
double func_800AA8B0(double, double);
double func_800ABA40(int, char *, double, double, double);
extern double D_800D6E88, D_800D6E90, D_800D6E98;
extern char D_800D6E80[];
double func_800AA460(double x) {
    int a = x > D_800D6E88;
    int b = x < D_800D6E90;
    if (a | b)
        return func_800ABA40(1, D_800D6E80, x, 0.0, 0.0);
    return func_800AA8B0(x, sqrt(D_800D6E98 - x * x));
}
