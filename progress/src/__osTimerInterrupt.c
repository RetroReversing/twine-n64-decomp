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
extern u32 __osGetCount(void);
extern void func_800A9210(u32);
extern void __osSetTimerIntr(OSTime);
extern OSTime __osInsertTimer(OSTimer *);
extern void osSendMesg(OSMesgQueue *, OSMesg, s32);

/* Runs on the compare interrupt. Fires every timer whose time has come and reprograms the compare register for the next one. Periodic timers are re-inserted. */
/* Runs on the compare interrupt: fires expired timers and reprograms the compare register for the next one. */ void __osTimerInterrupt(void) {
    OSTimer *nextTimer;
    u32 now;
    u32 delta;

    if (D_800CFE90->next == D_800CFE90) {
        return;
    }
    for (;;) {
        nextTimer = D_800CFE90->next;

        if (nextTimer == D_800CFE90) {
            func_800A9210(0);
            D_8010A3FC = 0;
            break;
        }

        now = __osGetCount();
        delta = now - D_8010A3FC;
        D_8010A3FC = now;

        if (delta < nextTimer->value) {
            nextTimer->value -= delta;
            __osSetTimerIntr(nextTimer->value);
            break;
        }

        nextTimer->prev->next = nextTimer->next;
        nextTimer->next->prev = nextTimer->prev;
        nextTimer->next = 0;
        nextTimer->prev = 0;

        if (nextTimer->mq != 0) {
            osSendMesg(nextTimer->mq, nextTimer->msg, 0);
        }

        if (nextTimer->interval != 0) {
            nextTimer->value = nextTimer->interval;
            __osInsertTimer(nextTimer);
        }
    }
}
