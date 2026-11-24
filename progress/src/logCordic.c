extern long long f64ToFixed60(double);
extern double fixed60ToF64(long long);
extern long long sExpLogTable[];
extern double kLogScaleIn, kLogScaleOut;
/* Computes a logarithm of x with a shift-and-add (CORDIC-style) loop in 4.60 fixed point, using a table of per-step log constants. */ double logCordic(double x) {
    long long logSum = 0;
    long long remaining = f64ToFixed60(x * kLogScaleIn);
    long long trial;
    int step;
    for (step = 1; step < 54; step++) {
        trial = remaining + (remaining >> step);
        if (trial <= 0x0FFFFFFFFFFFFFFFLL) {
            remaining = trial;
            logSum -= sExpLogTable[step];
        }
    }
    return fixed60ToF64(logSum) / kLogScaleOut;
}
