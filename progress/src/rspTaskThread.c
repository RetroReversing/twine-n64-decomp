extern unsigned char taskDonePending;
extern unsigned char yieldState;
s32 rspStartTask();
s32 func_800A2270();
s32 osCreateMesgQueue();
s32 osRecvMesg();
s32 osSendMesg();
s32 osSetEventMesg();
s32 osSpTaskStartGo();
u32 osSpTaskYielded();
extern u8 spEventMsg[];
extern s32 queuedTask;
extern s32 queuedYieldTask;
extern s32 curRspTask;
extern u8 gfxTaskPending;
extern char D_8010090C[];
extern char spEventQueue[];
extern char D_8010A3A8[];
extern char D_8010A4AC[];
extern char D_8010A938[];
extern char D_80112E60[];
extern u8 rspBusy;

/* RSP scheduler thread: starts queued RSP tasks, handles yield requests and reports completion to the game threads. */
void rspTaskThread(void) {
    s8 *spEventBase;
    void *msg;
    s32 task;
    s32 queued;
    u32 yieldResult;
    s32 msgType;

    spEventBase = spEventMsg;
    (*spEventMsg) = 0x81;
    osCreateMesgQueue(spEventQueue, D_80112E60, 8);
    osSetEventMesg(4, spEventQueue, spEventBase);
    osCreateMesgQueue(D_8010A3A8, D_8010A4AC, 1);
    osCreateMesgQueue(D_8010A938, D_8010090C, 1);
    queuedTask = 0;
    taskDonePending = 0U;
    queuedYieldTask = 0;
    gfxTaskPending = 0;
    rspBusy = 0;
    for (;;) {
        osRecvMesg(spEventQueue, &msg, 1);
        msgType = ((RspMsg *)msg)->type;
        switch (msgType) {
        case 1:
            if ((rspBusy == 0) && (gfxTaskPending == 0)) {
                task = ((RspMsg *)msg)->task;
                taskDonePending = 1U;
                rspBusy = 1;
                curRspTask = task;
                rspStartTask(task);
                osSpTaskStartGo(curRspTask);
            } else {
                queuedTask = ((RspMsg *)msg)->task;
            }
            continue;
        case 2:
            if (gfxTaskPending == 0) {
                gfxTaskPending = 1;
                if (rspBusy != 0) {
                    func_800A2270(msg);
                    queuedYieldTask = ((RspMsg *)msg)->task;
                } else {
                    yieldState = 1U;
                    rspBusy = 1;
                    rspStartTask(((RspMsg *)msg)->task);
                    osSpTaskStartGo(((RspMsg *)msg)->task);
                }
            }
            continue;
        case 0x81:
            break;
        default:
            continue;
        }
        if (queuedYieldTask != 0) {
            do {
                yieldResult = osSpTaskYielded(curRspTask);
            } while (yieldResult >= 2U);
            rspStartTask(queuedYieldTask);
            osSpTaskStartGo(queuedYieldTask);
            queuedYieldTask = 0;
            if (yieldResult == 0) {
                yieldState = 0U;
            } else {
                yieldState = 2U;
            }
            continue;
        }
        if (yieldState == 2) {
            gfxTaskPending = 0;
            osSendMesg(D_8010A938, 0, 1);
            rspStartTask(curRspTask);
            osSpTaskStartGo(curRspTask);
            yieldState = 0U;
            continue;
        }
        if (yieldState == 0) {
            if (taskDonePending != 0) {
                taskDonePending = 0U;
                osSendMesg(D_8010A3A8, 0, 0);
            }
            if (gfxTaskPending != 0) {
                gfxTaskPending = 0;
                osSendMesg(D_8010A938, 0, 0);
            }
        } else {
            gfxTaskPending = 0;
            osSendMesg(D_8010A938, 0, 0);
            yieldState = 0U;
        }
        queued = queuedTask;
        if (queued == 0) {
            rspBusy = 0;
            continue;
        }
        curRspTask = queued;
        queuedTask = 0;
        rspStartTask(queued);
        osSpTaskStartGo(curRspTask);
        taskDonePending = 1U;
        continue;
        break;
    }
}
