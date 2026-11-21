f32 __cosf(f32);
typedef struct { f32 m[4][4]; } Mtx;
extern f32 D_800D1040;
void guNormalize(f32 *,f32 *,f32 *);
void guMtxIdentF(f32 [4][4]);
void guMtxF2L(f32 [4][4],Mtx *);
f32 sinApprox(f32); f32 __cosf(f32);

/* Builds a rotation matrix of angle (in degrees) about the axis (x, y, z) and stores it in m. */
void guRotate(Mtx *m, f32 angleDeg, f32 axisX, f32 axisY, f32 axisZ) {
    f32 rot[4][4];
    f32 pad[2];
    f32 axisXn;
    f32 axisYn;
    f32 axisZn;
    f32 sine;
    f32 cosine;
    f32 xyOneMinusCos;
    f32 yzOneMinusCos;
    f32 zxOneMinusCos;
    f32 t;
    f32 (*r)[4];

    axisXn = axisX;
    axisYn = axisY;
    axisZn = axisZ;
    guNormalize(&axisXn, &axisYn, &axisZn);
    angleDeg = angleDeg * D_800D1040;
    sine = sinApprox(angleDeg);
    cosine = __cosf(angleDeg);
    t = 1.0f - cosine;
    xyOneMinusCos = (axisXn * axisYn) * t;
    yzOneMinusCos = (axisYn * axisZn) * t;
    zxOneMinusCos = (axisZn * axisXn) * t;
    r = rot;
    guMtxIdentF(r);
    t = axisXn * axisXn;
    r[0][0] = t + (cosine * (1.0f - t));
    r[2][1] = yzOneMinusCos - (axisXn * sine);
    r[1][2] = yzOneMinusCos + (axisXn * sine);
    t = axisYn * axisYn;
    r[1][1] = t + (cosine * (1.0f - t));
    r[2][0] = zxOneMinusCos + (axisYn * sine);
    r[0][2] = zxOneMinusCos - (axisYn * sine);
    t = axisZn * axisZn;
    r[2][2] = t + (cosine * (1.0f - t));
    r[1][0] = xyOneMinusCos - (axisZn * sine);
    r[0][1] = xyOneMinusCos + (axisZn * sine);
    guMtxF2L(r, m);
}
