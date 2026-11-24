s32 motionApplyStep(s32, f32, void *, s32);
s32 applyMotionDeltas(void *);

typedef struct MotionState {
    u8 pad0[4];
    s32 track;          /* 0x04: non-zero when the actor has a motion track */
    f32 frameTimer;     /* 0x08: counts down one unit per step */
    u8 pad1[0x44 - 0x0C];
    u16 speed;          /* 0x44 */
    u8 pad2[0x4B - 0x46];
    u8 frameIndex;      /* 0x4B */
    s8 lastFrame;       /* 0x4C */
} MotionState;

typedef struct MotionActor {
    u8 pad[0x6C];
    MotionState *motion;    /* 0x6C */
} MotionActor;

/* Advances an actor's motion timer by steps; when the timer runs out, moves to the next frame and applies it. */
s32 advanceActorMotion(MotionActor *arg0, u32 steps) {
    f32 temp_fv0;
    s32 temp_a3;
    s32 var_s0;
    s8 temp_v0_2;
    u8 temp_v0;
    MotionState *temp_a2;

    temp_a2 = arg0->motion;
    temp_a3 = temp_a2->track;
    var_s0 = 0;
    if (temp_a3 != 0) {
        temp_fv0 = temp_a2->frameTimer - 1.0f;
        temp_a2->frameTimer = temp_fv0;
        if (temp_fv0 <= 0.0f) {
            temp_v0 = temp_a2->frameIndex + steps;
            temp_a2->frameIndex = temp_v0;
            if (((u32) (temp_v0 << 0x18) >> 0x1F) & (steps >> 0x1F)) {
                temp_a2->frameIndex = 0U;
                var_s0 = 1;
            }
            temp_v0_2 = temp_a2->lastFrame;
            if ((temp_v0_2 < (s8) temp_a2->frameIndex) & ((s32) steps > 0)) {
                temp_a2->frameIndex = (u8) temp_v0_2;
                var_s0 = 1;
            }
            motionApplyStep(temp_a3 + ((s8) temp_a2->frameIndex * 0x18), (f32) temp_a2->speed, arg0, temp_a3);
        }
        applyMotionDeltas(arg0);
    }
    return var_s0;
}
