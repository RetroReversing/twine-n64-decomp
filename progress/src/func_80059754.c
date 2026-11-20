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

extern void func_8005916C(void *, f32, void *);
extern void func_80059590(void *);

s32 func_80059754(void *object, s32 step, s32 frames, s32 reverse) {
    MotionState *state = *(MotionState **)((u8 *)object + 0x6C);
    MotionStep *table;
    f32 time = state->remaining - 1.0f;
    s32 finished = 0;
    s8 index;
    f32 duration;

    state->remaining = time;
    if (frames == 0) {
        frames = 240;
    }
    if (time <= 0.0f && (table = state->table) != NULL) {
        index = state->index + step;
        state->index = index;
        if ((index < 0) & (step < 0)) {
            state->index = 0;
            finished = 1;
        }
        if ((state->last < state->index) & (step > 0)) {
            state->index = state->last;
            finished = 1;
        }
        func_8005916C(&table[state->index], 1.0f, object);
        if (reverse) {
            state->dx = -state->dx;
            state->dy = -state->dy;
            state->dz = -state->dz;
            state->rx = -state->rx;
            state->ry = -state->ry;
            state->rz = -state->rz;
        }
        duration = (f32) frames;
        state->remaining = duration;
        state->duration = duration;
        state->dx *= 1.5707964f / duration;
        state->dy *= 1.5707964f / state->remaining;
        state->dz *= 1.5707964f / state->remaining;
        state->rx *= 1.5707964f / state->remaining;
        state->ry *= 1.5707964f / state->remaining;
        state->rz *= 1.5707964f / state->remaining;
    }
    func_80059590(object);
    return finished;
}
