/* identical to osEepromProbe in PENNY RACERS (local match library) (matched), with its names changed by decompdecomp */
/* identical to osEepromProbe in V-RALLY-PAL (local match library) (matched), with its names changed by decompdecomp */
s32 func_800A23E4();
s32 func_800A2450();
s32 __osEepStatus();

s32 osEepromProbe(s32 arg0) {
    u16 sp10;
    s32 s0;
    s32 r;
    u16 v;

    s0 = arg0;
    func_800A23E4(s0);
    r = __osEepStatus(s0, &sp10);
    v = sp10 & 0xC000;
    if (r == 0) {
        switch (v) {
        case 0x8000:
            s0 = 1;
            break;
        case 0xC000:
            s0 = 2;
            break;
        default:
            s0 = 0;
            break;
        }
    } else {
        s0 = 0;
    }
    func_800A2450();
    return s0;
}
