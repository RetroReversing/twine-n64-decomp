/* identical to osSendMesg in V-RALLY-PAL (local match library) (matched), with its names changed by decompdecomp */
typedef void *OSMesg;
typedef struct OSThread_s OSThread;
struct OSThread_s { struct OSThread_s *next; s32 priority; struct OSThread_s **queue; struct OSThread_s *tlnext; u16 state; };
typedef struct OSMesgQueue_s {
    OSThread    *mtqueue;
    OSThread    *fullqueue;
    s32          validCount;
    s32          first;
    s32          msgCount;
    OSMesg      *msg;
} OSMesgQueue;

extern OSThread *D_800CFE80;
extern u32 __osDisableInt(void);
extern void __osRestoreInt(u32);
extern void func_800A783C(OSThread **);
extern OSThread *func_800A798C(OSThread **);
extern void osStartThread(OSThread *);

/* Sends msg to mq. If the queue is full, OS_MESG_BLOCK (flags == 1) sleeps the
 * running thread until there is room; otherwise returns -1. Wakes a thread
 * waiting to receive. Returns 0 on success. */
s32 osSendMesg(OSMesgQueue* mq, OSMesg msg, s32 flags) {
    register u32 saveMask;
    register s32 last;

    saveMask = __osDisableInt();

    while ((((  mq  )->validCount)  >= ( mq )->msgCount) ) {
        if (flags == 1 ) {
            D_800CFE80->state = (1 << 3) ;
            func_800A783C(&mq->fullqueue);
        } else {
            __osRestoreInt(saveMask);
            return -1;
        }
    }

    last = (mq->first + mq->validCount) % mq->msgCount;
    mq->msg[last] = msg;
    mq->validCount++;

    if (mq->mtqueue->next != 0 ) {
        osStartThread(func_800A798C(&mq->mtqueue));
    }

    __osRestoreInt(saveMask);
    return 0;
}
