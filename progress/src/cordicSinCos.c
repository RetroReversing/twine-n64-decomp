extern s64 f64ToFixed60(f64);
extern f64 fixed60ToF64(s64);
extern s64 gCordicAtanTable[];
extern f64 gCordicAngleScale, gCordicOutScale;

// CORDIC sin/cos: angle is in radians; writes sin to *sinOut and cos to *cosOut.
/* CORDIC sin/cos: rotates a fixed-point vector by atan steps; writes sin and cos as doubles. */ void cordicSinCos(f64 angle, f64 *sinOut, f64 *cosOut) {
    s64 cosFix = 0x09B74EDA8435E580LL;
    s64 sinFix = 0;
    s64 angleLeft = f64ToFixed60(angle * gCordicAngleScale);
    s64 nextCos;
    int i;
    for (i = 0; i < 52; i++) {
        if (angleLeft >= 0) {
            nextCos = cosFix - (sinFix >> i);
            sinFix += cosFix >> i;
            angleLeft -= gCordicAtanTable[i];
        } else {
            nextCos = cosFix + (sinFix >> i);
            sinFix -= cosFix >> i;
            angleLeft += gCordicAtanTable[i];
        }
        cosFix = nextCos;
    }
    { f64 sinValue = fixed60ToF64(sinFix);
    f64 outScale = gCordicOutScale;
    *sinOut = sinValue / outScale;
    *cosOut = fixed60ToF64(cosFix) / outScale; }
}
