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

s32 actorTickTimedState();
s32 tickTimedObject();
extern void *gSweepHitActor;
extern void *gSweepHitObject;

/* Ticks the timed state of the target object, else the player actor, if its flags have bits 0x300000 set. Returns 1 if one was ticked. */ s32 tickTargetOrPlayerTimedState(s32 param0, void *owner, s32 param2) {
    if ((gSweepHitObject != NULL) && (M2C_FIELD(gSweepHitObject, s32 *, 0x50) & 0x300000)) {
        actorTickTimedState(param0, gSweepHitObject, param2, M2C_FIELD(M2C_FIELD(owner, void **, 0x2C), s32 *, 0xC), M2C_FIELD(owner, s32 *, 0x24));
        return 1;
    }
    if ((gSweepHitActor != NULL) && (M2C_FIELD(gSweepHitActor, s32 *, 0x5C) & 0x300000)) {
        tickTimedObject(gSweepHitActor, param2, M2C_FIELD(M2C_FIELD(owner, void **, 0x2C), s32 *, 0xC), M2C_FIELD(owner, s32 *, 0x24));
        return 1;
    }
    return 0;
}
