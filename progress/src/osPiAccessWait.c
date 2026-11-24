/* identical to pi_access_wait in V-RALLY-PAL (local match library) (matched), with its names changed by decompdecomp */
s32 osCreateMesgQueue();
s32 osRecvMesg();
s32 osSendMesg();
extern s32 gPiAccessQueueInitialized;
extern char D_800F8340[];
extern char gOrderStateBase[];
extern char D_80117710[];

/* Blocks until the PI access queue (at gOrderStateBase+0x87A8) receives a message. The first call
   creates that queue, with a one-message buffer, and posts the initial token. */
/* Blocks until the PI access queue yields a message; the first call creates the queue and posts the initial token. */ void osPiAccessWait(void)
{
    s32 dummyMsg;

    if (gPiAccessQueueInitialized == 0) {
        gPiAccessQueueInitialized = 1;
        osCreateMesgQueue(gOrderStateBase + 0x87A8, D_800F8340 + 0x6AF0, 1);
        osSendMesg(D_80117710, 0, 0);
    }
    osRecvMesg(gOrderStateBase + 0x87A8, &dummyMsg, 1);
}
