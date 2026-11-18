/* identical to osStartThread in V-RALLY-PAL (local match library) (matched), with its names changed by decompdecomp */
typedef s32 OSPri;
typedef s32 OSId;

typedef struct OSThread_s {
    struct OSThread_s    *next;
    OSPri                 priority;
    struct OSThread_s   **queue;
    struct OSThread_s    *tlnext;
    u16                   state;
    u16                   flags;
    OSId                  id;
    int                   fp;
    void                 *thprof;
    u8                    context[0x1A0];
} OSThread;

extern OSThread *D_800CFE80;
extern OSThread *D_800A2518;
u32 func_8009F640(void);
void func_8009F6B0(u32);
void func_800A783C(OSThread **);
void func_800A7944(OSThread **, OSThread *);
OSThread *func_800A798C(OSThread **);
void func_800A79A4(void);

/* Makes a thread runnable. A stopped thread goes straight onto the run queue; a
   thread that is waiting on a queue is moved to the run queue. If the running
   thread has lower priority than the new head of the run queue, it is preempted.
   Runs with interrupts disabled. */
void osStartThread(OSThread *thread) {
    register u32 saved_int_mask = func_8009F640();

    switch (thread->state) {
        case (1 << 3):
            thread->state = (1 << 1);
            func_800A7944(&D_800A2518, thread);
            break;
        case (1 << 0):
            if (thread->queue == 0 || thread->queue == &D_800A2518) {
                thread->state = (1 << 1);
                func_800A7944(&D_800A2518, thread);
            } else {
                thread->state = (1 << 3);
                func_800A7944(thread->queue, thread);
                func_800A7944(&D_800A2518, func_800A798C(thread->queue));
            }
            break;
    }

    if (D_800CFE80 == 0) {
        func_800A79A4();
    } else if (D_800CFE80->priority < D_800A2518->priority) {
        D_800CFE80->state = (1 << 1);
        func_800A783C(&D_800A2518);
    }

    func_8009F6B0(saved_int_mask);
}
