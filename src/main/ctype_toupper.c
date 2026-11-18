#include "common_local_source_25769805772.h"

/* identical to ctype_toupper in V-RALLY-PAL (local match library) (matched), with its names changed by decompdecomp */
extern char D_800D1450[];

s32 ctype_toupper(s32 c) {
    s32 ch;

    ch = c;
    if (*(D_800D1450 + (ch & 0xFF)) & 4) {
        ch -= 0x20;
    }
    return ch;
}
