/* identical to cache_release_block in V-RALLY-PAL (local match library) (matched), with its names changed by decompdecomp */
void freeMenuItemRecord(s32 block);
extern s32 D_800B7D20;

/* Releases the cached heap block and clears the saved handle. */
void cache_release_block(void) {
    freeMenuItemRecord(D_800B7D20);
    D_800B7D20 = 0;
}
