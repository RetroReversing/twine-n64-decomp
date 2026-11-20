typedef struct { f32 period; s32 count; s32 unk8; f32 times[1]; } FrameTimes;
typedef struct { s32 flags; u8 pad4[0x18]; f32 time; u8 pad20[0x24]; s32 a44; u8 pad48[4]; FrameTimes *frames; u8 pad50[0x2E]; s16 h7E; } AnimSub;
typedef struct { u8 pad[0x14]; AnimSub anim; } AnimState;
typedef struct { u8 pad[0x68]; AnimState *state; } AnimObject;

extern f32 D_800D9414;
void func_80005C70(s32, s32, s32, s32, f32, s32);
void func_8000600C(void *, s32, s32, s32);

void func_80005310(AnimObject *obj) {
    AnimState *state = obj->state;
    FrameTimes *frames = state->anim.frames;
    AnimSub *anim = &state->anim;
    f32 *timePtr = &state->anim.time;
    f32 time = *timePtr;
    f32 period = frames->period;
    s32 count, index, next;
    f32 *times, *p;
    f32 numerator, denominator, previous, blend;

    while (period <= time) {
        time -= period;
    }
    if (time < 0.0f) {
        period = *(volatile f32 *)&frames->period;
        do {
            time += period;
        } while (time < 0.0f);
    }

    count = frames->count;
    index = (s32)((time * (f32)count) / *(volatile f32 *)&frames->period);
    times = frames->times;
    p = index + times;
    if (time < *p) {
    scanBack:
        next = index + 1;
        if (index != 0) {
            previous = p[-1];
            p--;
            if (time < previous) {
                index--;
                goto scanBack;
            }
        }
    } else {
        index++;
        p = index + times;
        next = index + 1;
        if (*p <= time) {
            do {
                p++;
                index++;
            } while (*p <= time);
            next = index + 1;
        }
    }
    next = next < count ? next : 0;

    p = index + times;
    denominator = *p;
    numerator = time;
    if (index > 0) {
        previous = p[-1];
        numerator = time - previous;
        denominator -= previous;
    }
    blend = numerator / denominator;
    if (!(anim->flags & 0x40000)) {
        D_800D9414 = blend;
        func_8000600C(obj, anim->h7E, index, next);
        *timePtr = time;
        return;
    }
    func_80005C70(anim->a44, anim->h7E, index, next, blend, anim->flags & 1);
    *timePtr = time;
}
