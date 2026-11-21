#ifndef M2C_DEFINES
#define M2C_DEFINES
typedef s32 M2C_UNK;
typedef s8 M2C_UNK8;
typedef s16 M2C_UNK16;
typedef s32 M2C_UNK32;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define M2C_CARRY 0
#define M2C_OVERFLOW(a) (0)
#endif
extern M2C_UNK gSinCosTable;
/* Spherical linear interpolation of two 4-float vectors/quaternions: out = from*wFrom + to*wTo, weights from t along the arc. Uses gSinCosTable (4096 entries) for sin. */
void vecSlerp(f32 t, f32 *from, f32 *to, f32 *out) {
    f32 dot, dotSq, dotCube, dotPow5, theta, invSinTheta, thetaT, thetaRest, weightFrom, weightTo;
    f32 outX, outY, outZ, outW;
    s32 negateFrom;

    dot = (from[0] * to[0]) + (from[1] * to[1]) + (from[2] * to[2]) + (from[3] * to[3]);
    negateFrom = 0;
    if (dot < 0.0f) {
        negateFrom = 1;
        dot = -dot;
    }
    weightTo = t;
    if ((1.0f - dot) > 0.01f) {
        /* Polynomial arccos(dot) gives theta; weights are sin(t*theta)/sin(theta) and sin((1-t)*theta)/sin(theta). */
        dotSq = dot * dot;
        dotCube = dotSq * dot;
        dotPow5 = dotSq * dotCube;
        theta = ((1.5708f - (dot * 1.01744f)) - (dotCube * 0.0207019f)) - (dotPow5 * 0.32649f);
        invSinTheta = 1.0f / *((f32 *)((s8 *)&gSinCosTable + ((((s32)(theta * 651.8986f) - 0x400) & 0xFFF) * 4)));
        thetaT = theta * t;
        thetaRest = (theta - thetaT) * 651.8986f;
        weightTo = *((f32 *)((s8 *)&gSinCosTable + ((((s32)(thetaT * 651.8986f) - 0x400) & 0xFFF) * 4))) * invSinTheta;
        weightFrom = *((f32 *)((s8 *)&gSinCosTable + ((((s32)thetaRest - 0x400) & 0xFFF) * 4))) * invSinTheta;
    } else {
        weightFrom = 1.0f - weightTo;
    }
    if (negateFrom != 0) {
        weightFrom = -weightFrom;
    }
    outX = (weightFrom * from[0]) + (weightTo * to[0]);
    outY = (weightFrom * from[1]) + (weightTo * to[1]);
    outZ = (weightFrom * from[2]) + (weightTo * to[2]);
    outW = (weightFrom * from[3]) + (weightTo * to[3]);
    out[0] = outX;
    out[1] = outY;
    out[2] = outZ;
    out[3] = outW;
}
