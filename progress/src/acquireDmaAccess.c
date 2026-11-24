/* identical to pi_access_wait in V-RALLY-PAL (local match library) (matched), with its names changed by decompdecomp */
s32 osCreateMesgQueue();
s32 osRecvMesg();
s32 osSendMesg();
extern s32 gPiAccessQueueInitialised;
extern char D_800F82F0[];
extern char gOsBssBase[];
extern char D_80109A38[];

/* Blocks until the PI access queue (at gOsBssBase+0x87A8) receives a message. The first call
   creates that queue, with a one-message buffer, and posts the initial token. */
/* Blocks until the access semaphore queue yields a token; the first call creates the queue and posts the initial token. */ void acquireDmaAccess(void)
{
    s32 token;

    if (gPiAccessQueueInitialised == 0) {
        gPiAccessQueueInitialised = 1;
        osCreateMesgQueue(gOsBssBase + 0x87A8, D_800F82F0 + 0x6AF0, 1);
        osSendMesg(D_80109A38, 0, 0);
    }
    osRecvMesg(gOsBssBase + 0x87A8, &token, 1);
}
