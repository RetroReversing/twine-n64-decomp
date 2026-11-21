/* identical to osRecvMesg in V-RALLY-PAL (local match library) (matched), with its names changed by decompdecomp */
typedef void *OSMesg;
typedef s32 OSPri;

typedef struct OSThread_s {
    struct OSThread_s *next;
    OSPri priority;
    struct OSThread_s **queue;
    struct OSThread_s *tlnext;
    u16 state;
} OSThread;

typedef struct OSMesgQueue_s {
    OSThread *mtqueue;
    OSThread *fullqueue;
    s32 validCount;
    s32 first;
    s32 msgCount;
    OSMesg *msg;
} OSMesgQueue;

extern OSThread *__osRunningThread;
extern u32 __osDisableInt(void);
extern void __osRestoreInt(u32);
extern void __osEnqueueAndYield(OSThread **);
extern OSThread *__osPopThread(OSThread **);
extern void osStartThread(OSThread *);

/* Receives the next message from a queue. If the queue is empty, flag 0 returns -1 at once; otherwise the thread blocks until a message arrives. Copies the message to *msg if msg is non-null, then wakes the first blocked sender. */
s32 osRecvMesg(OSMesgQueue *mq, OSMesg *msg, s32 flags) {
    register u32 saveMask;

    saveMask = __osDisableInt();

    while ((((mq)->validCount) == 0)) {
        if (flags == 0) {
            __osRestoreInt(saveMask);
            return -1;
        } else {
            __osRunningThread->state = (1 << 3);
            __osEnqueueAndYield(&mq->mtqueue);
        }
    }

    if (msg != 0) {
        *msg = mq->msg[mq->first];
    }

    mq->first = (mq->first + 1) % mq->msgCount;
    mq->validCount--;

    if (mq->fullqueue->next != 0) {
        osStartThread(__osPopThread(&mq->fullqueue));
    }

    __osRestoreInt(saveMask);
    return 0;
}
