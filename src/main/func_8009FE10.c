#include "common_local_source_25769805583.h"

/* identical to __osPiCreateAccessQueue in V-RALLY-PAL (local match library) (matched), with its names changed by decompdecomp */
s32 osCreateMesgQueue();
s32 osSendMesg();
extern s32 D_800CFDB0;
extern char D_800F82F0[];
extern char D_80101290[];

/* Enables the PI access queue: creates the one-slot message queue at D_80101290+0x87A8 (buffer at D_800F82F0+0x6AF0) and posts an empty message to it. */
void func_8009FE10(void) {
    void *queue;

    queue = D_80101290 + 0x87A8;
    D_800CFDB0 = 1;
    osCreateMesgQueue(queue, D_800F82F0 + 0x6AF0, 1);
    osSendMesg(queue, 0, 0);
}
