#include "common.h"

/* identical to osEepromProbe in V-RALLY-PAL (local match library) (matched), with its names changed by decompdecomp */
s32 func_800A23E4();
s32 func_800A2450();
s32 __osEepStatus();

/* Probes the controller pak on the given channel and returns its kind: 1 for the 0x8000 status class, 2 for 0xC000, 0 for anything else or on error. The PIF is locked for the query. */
s32 osEepromProbe(s32 channel) {
    u16 status;
    s32 kind;
    s32 r;
    u16 v;

    kind = channel;
    func_800A23E4(kind);
    r = __osEepStatus(kind, &status);
    v = status & 0xC000;
    if (r == 0) {
        switch (v) {
        case 0x8000:
            kind = 1;
            break;
        case 0xC000:
            kind = 2;
            break;
        default:
            kind = 0;
            break;
        }
    } else {
        kind = 0;
    }
    func_800A2450();
    return kind;
}
