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

s32 applyNearbyActorImpact(void *, f32, f32);
s32 spawnDriftEffect();
s32 releaseTrackRecord();
s32 updateActorTrackingState();

/* Per-frame update of a drift trail actor: tracks state, spawns drift effects, applies impact when expiring, and releases its track record when finished. */ void updateDriftTrailActor(void *actor) {
    s32 trackRecord;
    s32 framesLeft;
    void *trail;

    trail = M2C_FIELD(actor, void **, 0x6C);
    trackRecord = trail + 0x2C;
    updateActorTrackingState(actor, trackRecord);
    if (!(M2C_FIELD(trail, s32 *, 0xC) & 3)) {
        spawnDriftEffect(actor, actor + 0x24);
    }
    framesLeft = M2C_FIELD(trail, s32 *, 0xC) - 1;
    M2C_FIELD(trail, s32 *, 0xC) = framesLeft;
    if (framesLeft < 0xF0) {
        applyNearbyActorImpact(actor, 1.5f, 10.0f);
    }
    if ((M2C_FIELD(trail, s32 *, 0xC) == 0) || !(M2C_FIELD(actor, s32 *, 0x60) & 0x3000)) {
        releaseTrackRecord(trackRecord);
        M2C_FIELD(actor, s32 *, 0x60) |= 1;
    }
}
