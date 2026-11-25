s32 angleDelta12(s32, s32);

/* Starts a motion step: stores the per-frame position and rotation deltas from the object towards the step target, spread over the step duration (240 frames when zero). */
void motionApplyStep(void * step, f32 duration, void * object) {
    f32 stepRot[3];
    f32 rotDeltaZ;
    f32 frames;
    void *motion;

    frames = duration;
    motion = *(void **)((u8 *)object + 0x6C);
    if (frames == 0.0f) {
        frames = 240.0f;
    }
    stepRot[0] = *(f32 *)((u8 *)step + 0xC) * 0.0027777778f;
    stepRot[1] = *(f32 *)((u8 *)step + 0x10) * 0.0027777778f;
    stepRot[2] = *(f32 *)((u8 *)step + 0x14) * 0.0027777778f;
    *(f32 *)((u8 *)motion + 0x10) = (*(f32 *)step - *(f32 *)((u8 *)object + 0x24)) / frames;
    *(f32 *)((u8 *)motion + 0x14) = (*(f32 *)((u8 *)step + 4) - *(f32 *)((u8 *)object + 0x28)) / frames;
    *(f32 *)((u8 *)motion + 0x18) = (*(f32 *)((u8 *)step + 8) - *(f32 *)((u8 *)object + 0x2C)) / frames;
    *(f32 *)((u8 *)motion + 0x1C) = (f32) angleDelta12((s32) *(f32 *)((u8 *)object + 0x3C), (s32) stepRot[0]) / frames;
    *(f32 *)((u8 *)motion + 0x20) = (f32) angleDelta12((s32) *(f32 *)((u8 *)object + 0x40), (s32) stepRot[1]) / frames;
    rotDeltaZ = (f32) angleDelta12((s32) *(f32 *)((u8 *)object + 0x44), (s32) stepRot[2]) / frames;
    *(f32 *)((u8 *)motion + 0xC) = frames;
    *(f32 *)((u8 *)motion + 8) = frames;
    *(f32 *)((u8 *)motion + 0x24) = rotDeltaZ;
}
