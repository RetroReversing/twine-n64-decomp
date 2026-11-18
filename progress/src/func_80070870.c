/* identical to list_unlink_free in V-RALLY-PAL (local match library) (matched), with its names changed by decompdecomp */
s32 func_800643EC(s32);
void func_80067AE8();

/* Unlinks the current node from its list, then frees the memory block it sits in. */
void func_80070870(s32 block) {
    func_80067AE8();
    func_800643EC(block);
}
