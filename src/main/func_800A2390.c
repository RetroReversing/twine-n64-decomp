#include "common_local_source_25769805624.h"

/* identical to __osPiCreateAccessQueue in V-RALLY-PAL (local match library) (matched), with its names changed by decompdecomp */
s32 osCreateMesgQueue();
s32 osSendMesg();
extern s32 D_800CFE60;
extern char D_800F8340[];
extern char D_8010EF68[];

/* Enables the PI access queue: creates the one-slot message queue at D_8010EF68+0x87A8 (buffer at D_800F8340+0x6AF0) and posts an empty message to it. */
void func_800A2390(void) {
    void *queue;

    queue = D_8010EF68 + 0x87A8;
    D_800CFE60 = 1;
    osCreateMesgQueue(queue, D_800F8340 + 0x6AF0, 1);
    osSendMesg(queue, 0, 0);
}
