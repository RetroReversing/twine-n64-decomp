/* identical to rspSetPcIfHalted in V-RALLY-PAL (local match library) (matched), with its names changed by decompdecomp */
/* Sets the RSP program counter (SP_PC) to pc, but only while the RSP is halted (SP_STATUS bit 0); returns -1 otherwise. */
/* Sets the RSP program counter (SP_PC) to pc only while the RSP is halted (SP_STATUS bit 0); returns 0 on success, -1 otherwise. */ s32 rspSetPcIfHalted(s32 pc) {
    s32 result;

    if (*(vu32 *)0xA4040010 & 1) {
        *(vs32 *)0xA4080000 = pc;
        result = 0;
    } else {
        result = -1;
    }
    return result;
}
