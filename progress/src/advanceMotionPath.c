typedef struct {
    f32 position[3];
    f32 rotation[3];
} MotionStep;

typedef struct {
    u8 pad0[4];
    MotionStep *table;
    f32 remaining;
    f32 duration;
    f32 dx, dy, dz;
    f32 rx, ry, rz;
    u8 pad28[0x4B - 0x28];
    s8 index;
    s8 last;
} MotionState;

extern void motionApplyStep(void *, f32, void *);
extern void motionUpdateObject(void *);

/* Advances an object one step along its motion path (step is +1 or -1), optionally reverses the per-frame deltas, and re-arms the step timer. Returns 1 when the path end is reached. */
s32 advanceMotionPath(void *object, s32 step, s32 frames, s32 reverse) {
    MotionState *motion = *(MotionState **)((u8 *)object + 0x6C);
    MotionStep *path;
    f32 timeLeft = motion->remaining - 1.0f;
    s32 reachedEnd = 0;
    s8 stepIndex;
    f32 stepDuration;

    motion->remaining = timeLeft;
    if (frames == 0) {
        frames = 240;
    }
    if (timeLeft <= 0.0f && (path = motion->table) != NULL) {
        stepIndex = motion->index + step;
        motion->index = stepIndex;
        if ((stepIndex < 0) & (step < 0)) {
            motion->index = 0;
            reachedEnd = 1;
        }
        if ((motion->last < motion->index) & (step > 0)) {
            motion->index = motion->last;
            reachedEnd = 1;
        }
        motionApplyStep(&path[motion->index], 1.0f, object);
        if (reverse) {
            motion->dx = -motion->dx;
            motion->dy = -motion->dy;
            motion->dz = -motion->dz;
            motion->rx = -motion->rx;
            motion->ry = -motion->ry;
            motion->rz = -motion->rz;
        }
        stepDuration = (f32) frames;
        motion->remaining = stepDuration;
        motion->duration = stepDuration;
        motion->dx *= 1.5707964f / stepDuration;
        motion->dy *= 1.5707964f / motion->remaining;
        motion->dz *= 1.5707964f / motion->remaining;
        motion->rx *= 1.5707964f / motion->remaining;
        motion->ry *= 1.5707964f / motion->remaining;
        motion->rz *= 1.5707964f / motion->remaining;
    }
    motionUpdateObject(object);
    return reachedEnd;
}
