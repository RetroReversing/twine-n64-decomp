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

s32 angleDelta12();
s32 computeYawToPosition();
f32 absFloat(f32);

/* Returns 1 if the actor's current yaw is within tolerance of the yaw toward targetPos. */ s8 isFacingPosition(u8 * actor, u8 * targetPos, s32 * outYaw, f32 tolerance) {

    computeYawToPosition(actor, targetPos, outYaw);
    if (absFloat((f32) angleDelta12(*outYaw, M2C_FIELD(M2C_FIELD(actor, void **, 0x68), s16 *, 0x8C))) < tolerance) {
        return 1;
    }
    return 0;
}
