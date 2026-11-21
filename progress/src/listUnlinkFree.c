/* identical to list_unlink_free in V-RALLY-PAL (local match library) (matched), with its names changed by decompdecomp */
s32 func_8000A790(s32);
void func_8009C8DC();

/* Unlinks the current node from its list, then frees the memory block it sits in. */
void listUnlinkFree(s32 block) {
    func_8009C8DC();
    func_8000A790(block);
}
