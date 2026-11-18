#include "common_local_source_25769805704.h"

/* identical to __osResetGlobalIntMask in V-RALLY-PAL (local match library) (matched), with its names changed by decompdecomp */
s32 func_8009F640();
s32 func_8009F6B0(s32);
extern s32 D_800D1080;

/* Clears the given interrupt bits in the global interrupt mask (keeping bits
 * 0x401 set), with interrupts disabled while the mask is changed. */
void __osResetGlobalIntMask(s32 mask) {
    s32 saved;

    saved = func_8009F640();
    D_800D1080 &= ~mask | 0x401;
    func_8009F6B0(saved);
}
