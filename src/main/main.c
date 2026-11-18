#include "common.h"

/* adapted from similar verified C in boot_start in V-RALLY-PAL (matched), with its names changed by decompdecomp */
s32 osCreateThread();
s32 func_800A6908();
s32 osStartThread();
extern char D_800D7018[];
extern char D_800D04B0[];
extern s32 func_800009A4;

/* Boot-time start-up: runs the hardware setup in func_800A6908, then creates
 * and starts the boot thread (priority 1, entry func_800009A4, stack in
 * D_800D04B0 at +0x7D50). The thread control block is at D_800D7018+0x38. */
void main(void)
{
    void *boot_thread;

    func_800A6908();
    boot_thread = D_800D7018 + 0x38;
    osCreateThread(boot_thread, 1, &func_800009A4, 0, D_800D04B0 + 0x7D50, 8);
    osStartThread(boot_thread);
}
