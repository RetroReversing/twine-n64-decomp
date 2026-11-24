/* identical to __osPiCreateAccessQueue in V-RALLY-PAL (local match library) (matched), with its names changed by decompdecomp */
s32 osCreateMesgQueue();
s32 osSendMesg();
extern s32 gPiAccessQueueInitialized;
extern char D_800F8340[];
extern char gOrderStateBase[];

/* Enables the PI access queue: creates the one-slot message queue at gOrderStateBase+0x87A8 (buffer at D_800F8340+0x6AF0) and posts an empty message to it. */
/* Creates the one-slot PI access message queue and posts an empty message so the first user can take it. */ void osPiInitAccessQueue(void) {
    void *accessQueue;

    accessQueue = gOrderStateBase + 0x87A8;
    gPiAccessQueueInitialized = 1;
    osCreateMesgQueue(accessQueue, D_800F8340 + 0x6AF0, 1);
    osSendMesg(accessQueue, 0, 0);
}
