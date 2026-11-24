/* identical to __osPiCreateAccessQueue in V-RALLY-PAL (local match library) (matched), with its names changed by decompdecomp */
s32 osCreateMesgQueue();
s32 osSendMesg();
extern s32 gPiAccessQueueInitialised;
extern char D_800F82F0[];
extern char gOsBssBase[];

/* Enables the PI access queue: creates the one-slot message queue at gOsBssBase+0x87A8 (buffer at D_800F82F0+0x6AF0) and posts an empty message to it. */
/* Enables the PI access queue: creates a one-slot message queue and posts an empty message so the first PI user can take it. */ void osPiCreateAccessQueue(void) {
    void *accessQueue;

    accessQueue = gOsBssBase + 0x87A8;
    gPiAccessQueueInitialised = 1;
    osCreateMesgQueue(accessQueue, D_800F82F0 + 0x6AF0, 1);
    osSendMesg(accessQueue, 0, 0);
}
