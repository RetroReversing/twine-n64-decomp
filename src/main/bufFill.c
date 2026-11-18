#include "common_local_source_25769805760.h"

/* identical to bufFill in V-RALLY-PAL (local match library) (matched), with its names changed by decompdecomp */
void memset(void *dst, s32 value, s32 size);

/* Fill size bytes at dst with the low byte of value. */
void bufFill(void *dst, s32 size, s32 value) { memset(dst, value, size); }
