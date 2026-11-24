/* identical to osViBlack in V-RALLY-PAL (local match library) (matched), with its names changed by decompdecomp */
s32 __osDisableInt(s32 a0);
void __osRestoreInt(s32 a0);
extern u16 *gViCurrentContext;

/* Turns the VI blank bit (0x20 in the VI control word at gViCurrentContext) on when
 * active is non-zero, off otherwise. Interrupts are disabled around the update. */
/* Sets or clears the VI blank bit (0x20) in the current VI context's control word, with interrupts disabled. */ void osViBlack(s32 active)
{
    s32 savedMask;
    u16 *viCtrl;

    savedMask = __osDisableInt(active);
    if (active & 0xFF) {
        viCtrl = gViCurrentContext;
        *viCtrl = *viCtrl | 0x20;
    } else {
        viCtrl = gViCurrentContext;
        *viCtrl = *viCtrl & 0xFFDF;
    }
    __osRestoreInt(savedMask);
}
