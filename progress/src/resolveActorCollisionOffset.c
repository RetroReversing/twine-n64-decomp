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

typedef struct { s32 x,y,z; } Words3;
s32 func_8004FF30(s32, void *, void *, f32, s32, s32, s32, s32);

/* Probes around the actor's position and pushes the actor by the resulting correction offset. */ void resolveActorCollisionOffset(s32 arg0, void *actor, s32 arg2, s32 arg3) {
    f32 sp20[3];
    char sp30[0x10];
    f32 sp40[3];
    f32 sp50[3];
    f32 sp60[3];
    f32 temp_fv0;
    f32 temp_fv0_2;
    f32 temp_fv0_3;

    *(Words3 *)sp40 = *(Words3 *)((s8 *)actor + 0x24);
    sp20[0] = 0.0f;
    sp20[1] = 0.0f;
    sp20[2] = 0.0f;
    sp40[1] += 1.0f;
    temp_fv0 = M2C_FIELD(actor, f32 *, 0x24);
    sp60[0] = temp_fv0;
    sp50[0] = temp_fv0;
    temp_fv0_2 = M2C_FIELD(actor, f32 *, 0x28);
    sp60[1] = temp_fv0_2;
    sp50[1] = temp_fv0_2;
    temp_fv0_3 = M2C_FIELD(actor, f32 *, 0x2C);
    sp60[2] = temp_fv0_3;
    sp50[2] = temp_fv0_3;
    if ((func_8004FF30(arg0, sp50, sp30, 0.75f, 0x10, arg2, arg3, 0) << 0x18) != 0) {
        sp20[0] += sp50[0] - sp60[0];
        sp20[1] += sp50[1] - sp60[1];
        sp20[2] += sp50[2] - sp60[2];
    }
    M2C_FIELD(actor, f32 *, 0x24) += sp20[0];
    M2C_FIELD(actor, f32 *, 0x28) += sp20[1];
    M2C_FIELD(actor, f32 *, 0x2C) += sp20[2];
}
