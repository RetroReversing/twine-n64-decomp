extern s32 gColorUpdateStamp;
extern u8 gSkipActorSpawns;
extern s64 gTimeAccumulator, sFrameTime, gLastDeltaTime, gUpdateLoopStartTime, gPrevTickTime;
extern s32 D_8010A4E0;
u64 osGetTime(void);
void clearFlagAndRunUpdate();
void updateTransitionState();
void updateActorsFrame();
void clearActorFlag4();
void advanceFixedTimestepClocks();
/* Accumulates elapsed time, clamps it, then runs fixed-length game updates (2 frame times each) until caught up or out of time budget. */
void runFixedTimestepUpdates(void) {
    u32 stepCount;
    union { s64 value; struct { s32 high; u32 low; } words; } maxAccum;
    s32 accumHigh;
    gLastDeltaTime = osGetTime() - gPrevTickTime;
    gPrevTickTime = osGetTime();
    gTimeAccumulator += gLastDeltaTime;
    if (D_8010A4E0) {
        maxAccum.value = sFrameTime * 8;
        accumHigh = *(volatile s32 *)&gTimeAccumulator;
    } else {
        maxAccum.value = sFrameTime * 2;
        accumHigh = *(volatile s32 *)&gTimeAccumulator;
    }
    if (accumHigh > maxAccum.words.high ||
        (accumHigh == maxAccum.words.high && ((u32 *)&gTimeAccumulator)[1] > maxAccum.words.low))
        gTimeAccumulator = maxAccum.value;
    stepCount = 0;
    gUpdateLoopStartTime = osGetTime();
    while (gTimeAccumulator >= sFrameTime * 2) {
        gTimeAccumulator -= sFrameTime * 2;
        clearFlagAndRunUpdate();
        if (gSkipActorSpawns == 1) updateTransitionState();
        updateActorsFrame(stepCount != 0);
        stepCount++;
        if ((s64)(osGetTime() - gUpdateLoopStartTime) > stepCount * sFrameTime * 2) break;
        gColorUpdateStamp++;
    }
    clearActorFlag4();
    advanceFixedTimestepClocks();
}
