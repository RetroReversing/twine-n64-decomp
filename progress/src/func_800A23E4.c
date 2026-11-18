/* identical to pi_access_wait in V-RALLY-PAL (local match library) (matched), with its names changed by decompdecomp */
s32 osCreateMesgQueue();
s32 osRecvMesg();
s32 osSendMesg();
extern s32 D_800CFE60;
extern char D_800F8340[];
extern char D_8010EF68[];
extern char D_80117710[];

/* Blocks until the PI access queue (at D_8010EF68+0x87A8) receives a message. The first call
   creates that queue, with a one-message buffer, and posts the initial token. */
void func_800A23E4(void)
{
    s32 msg;

    if (D_800CFE60 == 0) {
        D_800CFE60 = 1;
        osCreateMesgQueue(D_8010EF68 + 0x87A8, D_800F8340 + 0x6AF0, 1);
        osSendMesg(D_80117710, 0, 0);
    }
    osRecvMesg(D_8010EF68 + 0x87A8, &msg, 1);
}
