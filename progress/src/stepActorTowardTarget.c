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

M2C_UNK setActorCommandState(void *, s32);
s32 getSpeedPercentForType(u8);
f32 approxDistanceXZ(void *, void *);
M2C_UNK resetActorActionState(void *);
M2C_UNK easeActorAngle(void *, s32, f32);
f32 func_800828D0(f32);
f32 func_800829A0(f32);
f32 func_800829C8(f32);
f32 func_80082A70(f32, f32);

/* Moves an actor one step toward a target position using a step length chosen by moveMode, plays the matching sound, turns the actor to face the direction of travel, and consumes the step from the remaining distance budget. */ f32 stepActorTowardTarget(void *actor, void *target, f32 *remainingDist, u32 moveMode) {
    f32 stepScale;
    f32 temp_fv0;
    f32 temp_fv1;
    f32 stepLength;
    f32 var_fv0;
    s16 temp_v1;
    s32 soundId;
    
    s32 var_v1;
    void *actorExtra;
    s32 phase_value;
    f32 temp_fa0;
    f32 temp_fa1;

    actorExtra = M2C_FIELD(actor, void **, 0x6C);
    stepScale = (f32) (getSpeedPercentForType(M2C_FIELD(M2C_FIELD(actor, void **, 0x68), u8 *, 0xB1)) & 0xFF) * 0.01f;
    temp_fv0 = approxDistanceXZ(actor + 0x24, target);
    if (temp_fv0 < *remainingDist) {
        *remainingDist = temp_fv0;
    }
    temp_v1 = M2C_FIELD(actor, s16 *, 0x7C);
    if (temp_v1 < 0) goto invalid;
    if (temp_v1 < 2) goto valid;
    if (temp_v1 == 3) goto valid;
invalid:
    resetActorActionState(actor);
    return 0.0f;
valid:;
    switch (moveMode) {
    case 0:
    case 3:
    default:
        var_fv0 = 0.12061068f;
        soundId = 7;
        break;
    case 1:
        var_fv0 = 0.12061068f;
        soundId = 0x165;
        break;
    case 4:
        var_fv0 = 0.15752044f;
        soundId = 0x16B;
        break;
    case 5:
        var_fv0 = 0.15752044f;
        soundId = 0x1FD;
        break;
    case 2:
        goto play;
    case 6:
        var_fv0 = 0.047853343f;
        soundId = 2;
        break;
    }
    stepLength = stepScale * var_fv0;
play:;
    setActorCommandState(actor, (u16)soundId);
    M2C_FIELD(actor, s16 *, 0x7C) = 3;
    M2C_FIELD(actorExtra, s8 *, 0x7F) = 3;
    temp_fv1 = *remainingDist - stepLength;
    temp_fa0 = M2C_FIELD(target, f32 *, 0) - M2C_FIELD(actor, f32 *, 0x24);
    temp_fa1 = M2C_FIELD(target, f32 *, 8) - M2C_FIELD(actor, f32 *, 0x2C);
    *remainingDist = temp_fv1;
    if ((temp_fv1 * 4.0f) < stepLength) {
        *remainingDist = 0.0f;
    } else {
        phase_value = 1;
        if (temp_fa0 != 0.0f) {
            phase_value = 0;
        }
        var_v1 = 1;
        if (temp_fa1 != 0.0f) {
            var_v1 = 0;
        }
        easeActorAngle(actor, (s32) (phase_value & var_v1) ? (f32) (M2C_FIELD(actor, f32 *, 0x40)) : (f32) (func_80082A70(temp_fa0, temp_fa1) * 651.8986f), 0.2f);
    }
    stepScale = func_800829A0(M2C_FIELD(actor, f32 *, 0x40));
    M2C_FIELD(actor, f32 *, 0x24) += stepLength * stepScale;
    M2C_FIELD(actor, f32 *, 0x2C) = (f32) (M2C_FIELD(actor, f32 *, 0x2C) + (stepLength * func_800829C8(M2C_FIELD(actor, f32 *, 0x40))));
    M2C_FIELD(M2C_FIELD(actor, void **, 0x68), f32 *, 0x34) = stepLength;
    return func_800828D0(stepLength);
}
