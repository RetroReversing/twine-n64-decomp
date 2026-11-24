/* adapted from similar verified C in boot_start in V-RALLY-PAL (matched), with its names changed by decompdecomp */
s32 osCreateThread();
s32 osInitialize();
s32 osStartThread();
extern char D_800D7018[];
extern char D_800D04B0[];
extern s32 idleThreadEntry;

/* Boot-time start-up: runs the hardware setup in osInitialize, then creates
 * and starts the boot thread (priority 1, entry idleThreadEntry, stack in
 * D_800D04B0 at +0x7D50). The thread control block is at D_800D7018+0x38. */
/* Game entry: initializes the OS, then creates and starts the idle thread (priority 1). */ void main(void)
{
    void *idleThread;

    osInitialize();
    idleThread = D_800D7018 + 0x38;
    osCreateThread(idleThread, 1, &idleThreadEntry, 0, D_800D04B0 + 0x7D50, 8);
    osStartThread(idleThread);
}
