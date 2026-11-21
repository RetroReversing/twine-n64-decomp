/* identical to __osInsertTimer in V-RALLY-PAL (local match library) (matched), with its names changed by decompdecomp */
typedef u64 OSTime;
typedef void *OSMesg;
typedef struct OSMesgQueue_s { void *mtqueue; void *fullqueue; s32 validCount; s32 first; s32 msgCount; OSMesg *msg; } OSMesgQueue;
typedef struct OSTimer_s { struct OSTimer_s *next; struct OSTimer_s *prev; OSTime interval; OSTime value; OSMesgQueue *mq; OSMesg msg; } OSTimer;
extern OSTimer *__osTimerList;
extern u32 __osDisableInt(void);
extern void __osRestoreInt(u32);

/* Inserts timer t into the sorted timer list __osTimerList (a circular list with a sentinel
 * head). Each entry's value is the delay after the previous one, so t->value is made
 * relative to the entries before it. Returns the relative delay stored in t. Interrupts
 * are masked around the list update. */
/* Inserts a timer into the sorted delta list __osTimerList with interrupts masked and returns its relative delay. */ OSTime __osInsertTimer(OSTimer* newTimer) {
    OSTimer* nextTimer;
    OSTime relativeDelay;
    u32 savedMask = __osDisableInt();

    nextTimer = __osTimerList->next;
    relativeDelay = newTimer->value;
    for (; nextTimer != __osTimerList && relativeDelay > nextTimer->value; nextTimer = nextTimer->next) {
        relativeDelay -= nextTimer->value;
    }

    newTimer->value = relativeDelay;

    if (nextTimer != __osTimerList) {
        nextTimer->value -= relativeDelay;
    }

    newTimer->next = nextTimer;
    newTimer->prev = nextTimer->prev;
    nextTimer->prev->next = newTimer;
    nextTimer->prev = newTimer;
    __osRestoreInt(savedMask);
    return relativeDelay;
}
