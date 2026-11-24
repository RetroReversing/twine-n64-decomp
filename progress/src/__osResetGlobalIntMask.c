/* identical to __osResetGlobalIntMask in V-RALLY-PAL (local match library) (matched), with its names changed by decompdecomp */
s32 __osDisableInt();
s32 __osRestoreInt(s32);
extern s32 __OSGlobalIntMask;

/* Clears the given interrupt bits in the global interrupt mask (keeping bits
 * 0x401 set), with interrupts disabled while the mask is changed. */
/* Clears the given interrupt bits in the global interrupt mask (keeping bits 0x401 set), with interrupts disabled. */ void __osResetGlobalIntMask(s32 mask) {
    s32 savedMask;

    savedMask = __osDisableInt();
    __OSGlobalIntMask &= ~mask | 0x401;
    __osRestoreInt(savedMask);
}
