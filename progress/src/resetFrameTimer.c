u64 osGetTime(void);
extern u64 gTimeAccumulator;
extern u64 gLastDeltaTime;
extern u64 gPrevTickTime;

/* Restarts frame timing: clears the last delta and accumulator and records the current time as the previous tick. */ void resetFrameTimer(void) {
    u64 now;
    gLastDeltaTime = 0;
    now = osGetTime();
    gPrevTickTime = now;
    gTimeAccumulator = 0;
}
