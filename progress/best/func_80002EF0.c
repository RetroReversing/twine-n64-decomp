typedef struct {
    u8 pad[0x11];
    u8 event;
    u8 pad12[2];
    u32 flags;
    u8 pad18[8];
    f32 speed, fraction, blend, blendStep, elapsed, elapsedStep;
    u8 pad38[0x28];
    u32 overrideSpeed;
    s16 *script;
    u16 *events;
    u8 pad6c[0x24];
    s16 start, animation, frame, previous;
    u8 pad98[4];
    s16 low, high;
    u8 pada0[0x14];
    u8 cooldown;
} AnimState;
typedef struct {
    u8 pad[0x18];
    void *parent;
    u8 pad1c[0x4c];
    AnimState *state;
} AnimObject;
extern s32 D_800D9418;
extern f32 D_800D9414;
extern s32 gGameMode;
extern f32 absFloat(f32);
extern void func_800061D0(AnimObject *, s32);
extern void func_800065BC(AnimObject *, s32);
extern void func_8008587C(AnimObject *);
extern void func_80084338(u16, void *);
extern void func_80085934(AnimObject *, void *);

s32 func_80002EF0(AnimObject *object) {
    AnimState *state = object->state;
    volatile u32 scratch[0x2ea];
    s32 changed = 0;
    state->elapsed += state->elapsedStep;
    D_800D9418 = state->frame;
    D_800D9414 = state->blend;
    if (!state->script || (state->flags & 0x10)) return changed;
    state->flags &= ~0x20;
    if (state->flags & 0x10000) {
        state->flags &= ~0x10000;
    } else {
        if (!state->overrideSpeed) {
            f32 speed = state->speed;
            if (!((speed <= 0.0002f) & (speed >= -0.0002f))) {
                f32 fraction = state->fraction + absFloat(speed);
                state->fraction = fraction;
                if (fraction >= 1.0f) {
                    s32 distance;
                    if (speed >= 0.0f) {
                        distance = state->frame + (s32)fraction - state->high;
                    } else {
                        distance = state->low - (state->frame - (s32)fraction);
                    }
                    if (distance <= 0) {
                        func_800061D0(object, state->animation);
                        fraction = state->fraction;
                        state->fraction = absFloat(fraction - (s32)fraction);
                    } else {
                        u32 flags = state->flags;
                        state->flags = flags | 0x20;
                        if (state->blend == 1.0f) state->flags = flags | 0x60;
                        state->fraction = 1.0f;
                    }
                    changed |= 1;
                }
            }
        } else {
            f32 speed = state->elapsedStep;
            state->speed = speed;
            if (speed < -1.0f) state->speed = -1.0f;
            else if (speed > 1.0f) state->speed = 1.0f;
        }
        if (state->flags & 0x40000) {
            state->blend += state->blendStep;
            if (state->blend >= 1.0f) {
                state->blend = 1.0f;
                state->flags = (state->flags | 0x40) & ~0x40000;
            }
            changed |= 2;
            D_800D9414 = state->blend;
        } else {
            D_800D9414 = state->fraction;
        }
    }
    if (state->events) {
        u16 *event = state->events;
        s32 frame = state->frame;
        s32 previous = state->previous;
        if (state->cooldown) state->cooldown--;
        if (frame != previous) {
            s32 forward = state->speed >= 0.0f;
            s32 start = state->start - (s32)((u32)previous >> 31);
            state->previous = frame;
            while (event[0]) {
                s32 mark = event[1];
                s32 active;
                if (forward) active = (start < mark) & (frame >= mark);
                else active = (mark < start) & (mark >= frame);
                switch (event[0]) {
                case 1:
                    if (active) func_800065BC(object, 0);
                    break;
                case 2:
                    if (active && state->cooldown == 0) {
                        state->cooldown = 4;
                        func_8008587C(object);
                    }
                    break;
                case 3:
                    if (active) {
                        object->state->event = gGameMode == 38 ? 7 : 4;
                        func_8008587C(object);
                    }
                    break;
                case 4:
                    if (active) {
                        u8 *parent = object->parent;
                        if (!parent) parent = (u8 *)object;
                        func_80084338(event[2], parent + 0x24);
                    }
                    event++;
                    break;
                case 5:
                    if (active) func_80085934(object, (u8 *)object + 0x24);
                    break;
                default:
                    continue;
                }
                event += 2;
            }
        }
    }
    return changed;
}
