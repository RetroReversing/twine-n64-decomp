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
/* machine draft (m2c) for gcc-2.7.2-kmc -G0 -mips3 -mgp32 -mfp32 -O2, tried by autopilot */

f32 absFloat(f32);

/* Approximates the length of a 3D vector by sorting the absolute components and applying fixed weights (0.9398, 0.3893, 0.2987). */ f32 approxVectorLength(f32 x, f32 y, f32 z) {
    f32 swapA;
    f32 swapB;
    f32 swapC;
    f32 middle;
    f32 largest;
    f32 smallest;

    largest = absFloat(x);
    middle = absFloat(y);
    smallest = absFloat(z);
    if (largest < middle) {
        swapA = largest;
        largest = middle;
        middle = swapA;
    }
    swapB = smallest;
    if (largest < smallest) {
        smallest = largest;
        largest = swapB;
    }
    swapC = middle;
    if (middle < smallest) {
        middle = smallest;
        smallest = swapC;
    }
    return (largest * 0.9398f) + (middle * 0.3893f) + (smallest * 0.2987f);
}
