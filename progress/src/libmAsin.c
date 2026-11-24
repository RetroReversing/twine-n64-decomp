double sqrt(double);
double libmAtan2(double, double);
double libmMathError(int, char *, double, double, double);
extern double kAsinUpperLimit, kAsinLowerLimit, kAsinOne;
extern char sAsinName[];
/* asin(x) = atan2(x, sqrt(1 - x*x)); reports a libm domain error if |x| > 1. */ double libmAsin(double x) {
    int aboveOne = x > kAsinUpperLimit;
    int belowMinusOne = x < kAsinLowerLimit;
    if (aboveOne | belowMinusOne)
        return libmMathError(1, sAsinName, x, 0.0, 0.0);
    return libmAtan2(x, sqrt(kAsinOne - x * x));
}
