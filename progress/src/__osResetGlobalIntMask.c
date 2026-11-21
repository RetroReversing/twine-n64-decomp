/* identical to __osResetGlobalIntMask in V-RALLY-PAL (local match library) (matched), with its names changed by decompdecomp */
s32 __osDisableInt();
s32 __osRestoreInt(s32);
extern s32 D_800D1080;

/* Clears the given interrupt bits in the global interrupt mask (keeping bits
 * 0x401 set), with interrupts disabled while the mask is changed. */
void __osResetGlobalIntMask(s32 mask) {
    s32 saved;

    saved = __osDisableInt();
    D_800D1080 &= ~mask | 0x401;
    __osRestoreInt(saved);
}
