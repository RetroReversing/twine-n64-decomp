/* identical to pi_access_wait in V-RALLY-PAL (local match library) (matched), with its names changed by decompdecomp */
s32 osCreateMesgQueue();
s32 osRecvMesg();
s32 osSendMesg();
extern s32 D_800CFDB0;
extern char D_800F82F0[];
extern char D_80101290[];
extern char D_80109A38[];

/* Blocks until the PI access queue (at D_80101290+0x87A8) receives a message. The first call
   creates that queue, with a one-message buffer, and posts the initial token. */
void func_8009FE64(void)
{
    s32 msg;

    if (D_800CFDB0 == 0) {
        D_800CFDB0 = 1;
        osCreateMesgQueue(D_80101290 + 0x87A8, D_800F82F0 + 0x6AF0, 1);
        osSendMesg(D_80109A38, 0, 0);
    }
    osRecvMesg(D_80101290 + 0x87A8, &msg, 1);
}
