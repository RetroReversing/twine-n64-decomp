/* adapted from similar verified C in poolAllocHeadNode in V-RALLY-PAL (matched), with its names changed by decompdecomp */
/* machine draft (m2c) for gcc-2.7.2-kmc -G0 -mips3 -mgp32 -mfp32 -O2, tried by autopilot */
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

s32 heapAllocTagged(M2C_UNK, M2C_UNK);                /* extern */
M2C_UNK resetSceneObjectState(s32);                         /* extern */

/* Allocates a 12-byte node from pool 1 and clears it. */
/* Allocates a 332-byte scene object from the tagged heap and resets its state. */ s32 allocSceneObject(void) {
    s32 obj;

    obj = heapAllocTagged(332, 14);
    resetSceneObjectState(obj);
    return obj;
}
