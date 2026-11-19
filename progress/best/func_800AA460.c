double sqrt(double);
double func_800AA8B0(double, double);
double func_800ABA40(int, char *, double, double, double);
extern double D_800D6E88;
extern double D_800D6E90;
extern double D_800D6E98;
extern char D_800D6E80[];

double func_800AA460(double x) {
    if ((x > D_800D6E88) | (x < D_800D6E90)) {
        return func_800ABA40(1, D_800D6E80, x, 0.0, 0.0);
    }
    return func_800AA8B0(x, sqrt(D_800D6E98 - x * x));
}
