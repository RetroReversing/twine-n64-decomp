/* identical to osEepromProbe in PENNY RACERS (local match library) (matched), with its names changed by decompdecomp */
/* identical to osEepromProbe in V-RALLY-PAL (local match library) (matched), with its names changed by decompdecomp */
s32 osPiAccessWait();
s32 postWakeupMessage();
s32 __osEepStatus();

/* Probes for EEPROM: returns 0 if none, 1 for 4Kbit, 2 for 16Kbit. */ s32 osEepromProbe(s32 mq) {
    u16 status;
    s32 result;
    s32 err;
    u16 type;

    result = mq;
    osPiAccessWait(result);
    err = __osEepStatus(result, &status);
    type = status & 0xC000;
    if (err == 0) {
        switch (type) {
        case 0x8000:
            result = 1;
            break;
        case 0xC000:
            result = 2;
            break;
        default:
            result = 0;
            break;
        }
    } else {
        result = 0;
    }
    postWakeupMessage();
    return result;
}
