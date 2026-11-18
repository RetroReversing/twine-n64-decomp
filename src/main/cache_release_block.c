#include "common_local_source_25769804358.h"

/* identical to cache_release_block in V-RALLY-PAL (local match library) (matched), with its names changed by decompdecomp */
void func_80016314(s32 block);
extern s32 D_800B7D20;

/* Releases the cached heap block and clears the saved handle. */
void cache_release_block(void) {
    func_80016314(D_800B7D20);
    D_800B7D20 = 0;
}
