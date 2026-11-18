#include "common_local_source_25769805616.h"

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

extern OSThread *D_800CFE80;
extern u32 func_8009F640(void);
extern void func_8009F6B0(u32);
extern void func_800A783C(OSThread **);
extern OSThread *func_800A798C(OSThread **);
extern void osStartThread(OSThread *);

/* Receives the next message from a queue. If the queue is empty, flag 0 returns -1 at once; otherwise the thread blocks until a message arrives. Copies the message to *msg if msg is non-null, then wakes the first blocked sender. */
s32 osRecvMesg(OSMesgQueue *mq, OSMesg *msg, s32 flags) {
    register u32 saveMask;

    saveMask = func_8009F640();

    while ((((mq)->validCount) == 0)) {
        if (flags == 0) {
            func_8009F6B0(saveMask);
            return -1;
        } else {
            D_800CFE80->state = (1 << 3);
            func_800A783C(&mq->mtqueue);
        }
    }

    if (msg != 0) {
        *msg = mq->msg[mq->first];
    }

    mq->first = (mq->first + 1) % mq->msgCount;
    mq->validCount--;

    if (mq->fullqueue->next != 0) {
        osStartThread(func_800A798C(&mq->fullqueue));
    }

    func_8009F6B0(saveMask);
    return 0;
}
