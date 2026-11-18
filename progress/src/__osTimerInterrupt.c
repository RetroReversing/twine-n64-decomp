/* identical to __osTimerInterrupt in V-RALLY-PAL (local match library) (matched), with its names changed by decompdecomp */
typedef u64 OSTime;
typedef void *OSMesg;
typedef struct OSMesgQueue_s OSMesgQueue;
typedef struct OSTimer_s {
    struct OSTimer_s *next;
    struct OSTimer_s *prev;
    OSTime interval;
    OSTime value;
    OSMesgQueue *mq;
    OSMesg msg;
} OSTimer;
extern OSTimer *D_800CFE90;
extern u32 D_8010A3FC;
extern u32 func_800A91F0(void);
extern void func_800A9210(u32);
extern void __osSetTimerIntr(OSTime);
extern OSTime __osInsertTimer(OSTimer *);
extern void osSendMesg(OSMesgQueue *, OSMesg, s32);

/* Runs on the compare interrupt. Fires every timer whose time has come and reprograms the compare register for the next one. Periodic timers are re-inserted. */
void __osTimerInterrupt(void) {
    OSTimer *timer;
    u32 count;
    u32 elapsed;

    if (D_800CFE90->next == D_800CFE90) {
        return;
    }
    for (;;) {
        timer = D_800CFE90->next;

        if (timer == D_800CFE90) {
            func_800A9210(0);
            D_8010A3FC = 0;
            break;
        }

        count = func_800A91F0();
        elapsed = count - D_8010A3FC;
        D_8010A3FC = count;

        if (elapsed < timer->value) {
            timer->value -= elapsed;
            __osSetTimerIntr(timer->value);
            break;
        }

        timer->prev->next = timer->next;
        timer->next->prev = timer->prev;
        timer->next = 0;
        timer->prev = 0;

        if (timer->mq != 0) {
            osSendMesg(timer->mq, timer->msg, 0);
        }

        if (timer->interval != 0) {
            timer->value = timer->interval;
            __osInsertTimer(timer);
        }
    }
}
