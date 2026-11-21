typedef struct { s32 minutes; u16 subTicks; u8 seconds; u8 ticksPerSecond; } TimerRecord;

/* Advances a min:sec:tick timer by delta ticks; negative deltas count down, borrowing from seconds and minutes. */
void advanceTimerRecord(TimerRecord *timer, s32 delta) {
    register unsigned long minutes;
    s32 minuteCarry;
    s32 tickCarry;
    u16 newSubTicks;
    unsigned long ticks;
    u8 seconds;

    tickCarry = 0;
    minuteCarry = 0;
    if ((timer != NULL) && (timer->ticksPerSecond != 0)) {
        if ((s16)delta >= 0) {
            u8 limit = *(volatile u8 *)&timer->ticksPerSecond;
            ticks = timer->subTicks + delta;
            for (;;) {
                timer->subTicks = ticks;
                if ((s16)ticks < limit) {
                    break;
                }
                tickCarry++;
                ticks = *(volatile u16 *)&timer->subTicks - limit;
                limit = timer->ticksPerSecond;
            }
            seconds = timer->seconds + tickCarry;
            for (;;) {
                timer->seconds = seconds;
                if ((s8)seconds < 0x3C) {
                    break;
                }
                minuteCarry += 1;
                seconds = timer->seconds - 0x3C;
            }
            timer->minutes = (s32)(timer->minutes + (minuteCarry & 0xFF));
            return;
        }
        newSubTicks = timer->subTicks + delta;
        timer->subTicks = newSubTicks;
        if ((s16)newSubTicks < 0) {
            if ((s8)timer->seconds != 0) {
                timer->subTicks = (u16)timer->ticksPerSecond;
                timer->seconds = (u8)(timer->seconds - 1);
                return;
            }
            minutes = timer->minutes;
            if (minutes) {
                timer->minutes = (s32)(minutes - 1);
                timer->seconds = 0x3BU;
                timer->subTicks = (u16)timer->ticksPerSecond;
                return;
            }
            timer->subTicks = 0U;
        }
    }
}
