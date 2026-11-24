/* identical to __osPfsGetOneChannelData in V-RALLY-PAL (local match library) (matched), with its names changed by decompdecomp */
extern u8 D_8010B15E[];

/* Reads the 6-byte status entry for one channel from the controller-pak buffer at D_8010B15E+0x7E82. It stores the channel's flag in out[3]; when the flag is 0 it also copies the 16-bit value and the trailing byte into out. */
/* Reads one channel's 6-byte PIF status entry; stores the error bits in status[3] and, if there is no error, copies the 16-bit device id and the trailing status byte into status. */ void __osPfsGetOneChannelData(s32 channel, u8 *status) {
    struct { u8 b[6]; } entry;
    u8 *entryPtr;
    s32 i;
    u8 errorBits;

    entryPtr = D_8010B15E + 0x7E82;
    for (i = 0; i < channel; i++) {
        entryPtr++;
    }
    entry = *(typeof(entry) *)entryPtr;
    errorBits = (entry.b[1] & 0xC0) >> 4;
    status[3] = errorBits;
    if (errorBits == 0) {
        *(s16 *)status = (s16)(entry.b[3] | (entry.b[4] << 8));
        status[2] = entry.b[5];
    }
}
