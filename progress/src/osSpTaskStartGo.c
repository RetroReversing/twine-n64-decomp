/* identical to osSpTaskStartGo in V-RALLY-PAL (local match library) (matched), with its names changed by decompdecomp */
s32 func_800A9250(void);
void func_800A9280(u32 value);

/* Starts the RSP: waits until it is no longer halted or busy, then writes 0x125 to SP_STATUS. */
void osSpTaskStartGo(void) {
    do {

    } while (func_800A9250() != 0);
    func_800A9280(0x125);
}
