/* identical to list_unlink_free in V-RALLY-PAL (local match library) (matched), with its names changed by decompdecomp */
s32 removeSoundRequest(s32);
void stopSoundLocked();

/* Unlinks the current node from its list, then frees the memory block it sits in. */
/* Stops the locked sound, then removes the given node from its request list. */ void listUnlinkFree(s32 node) {
    stopSoundLocked();
    removeSoundRequest(node);
}
