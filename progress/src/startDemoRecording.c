extern u32 D_80107EDC, D_80107EE0;
extern u8 D_80107EE8;

u32 getSequencePlayerFlagBit(u8 index) {
    s32 offset = index * 0x28;
    if (*(u8 *)((u8 *)&D_80107EE8 + offset) == 4)
        return 0;
    if (*(u32 *)((u8 *)&D_80107EE0 + offset) == 0)
        return 0;
    return *(u32 *)((u8 *)&D_80107EDC + offset) >> 31;
}

void resetDefaultGameSettings(void);
void resetRandomSeed(void);
extern s8 gDemoRecordingActive, gMenuOutcome;
extern u64 gTimeAccumulator;
extern s32 gDemoFrame, gDemoFadeTimer;
extern u8 gMenuBackdropBuffer[];
extern u8 *gDemoInputData;

/* Begins demo recording: points input data at the backdrop buffer, resets timers and frame counters, applies default settings and sets the menu outcome to 2. */ void startDemoRecording(void) {
    gDemoInputData = gMenuBackdropBuffer;
    gDemoRecordingActive = 1;
    gTimeAccumulator = 0;
    gDemoFrame = 0;
    gDemoFadeTimer = -1;
    resetRandomSeed();
    resetDefaultGameSettings();
    gMenuOutcome = 2;
}

extern f32 D_80102E6C, D_80102E70, D_80102E74[], D_80102E78;
extern f32 D_80102E80, D_80102E84, D_80102E88, D_80102E8C, gSurfaceQueryPosX;

void transformGlobalVec3(void) {
    f32 *out = D_80102E74;
    f32 ax = D_80102E80 * out[-3];
    f32 ay = D_80102E84 * D_80102E6C;
    f32 az = D_80102E88 * D_80102E70;
    f32 bx = D_80102E8C * out[-3];
    f32 by = out[7] * D_80102E6C;
    f32 bz = out[8] * D_80102E70;
    f32 cx = out[9] * out[-3];
    f32 cy = out[10] * D_80102E6C;
    f32 cz = out[11] * D_80102E70;
    f32 x = ax + ay + az + gSurfaceQueryPosX;
    f32 y = bx + by + bz + out[13];
    f32 z = cx + cy + cz + out[14];

    out[0] = x;
    D_80102E78 = y;
    out[2] = z;
}

u64 osGetTime(void);
extern u64 gLastDeltaTime, gPrevTickTime;

void resetFrameTimer(void) {
    gLastDeltaTime = 0;
    gPrevTickTime = osGetTime();
    gTimeAccumulator = 0;
}
