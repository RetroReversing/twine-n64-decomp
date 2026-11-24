/* identical to __osPackReadData in PENNY RACERS (local match library) (matched), with its names changed by decompdecomp */
/* identical to __osPackReadData in V-RALLY-PAL (local match library) (matched), with its names changed by decompdecomp */
extern char D_800FF6D0[];
extern u8 __osMaxControllers;

typedef struct {
    u8 b[6];
    s8 tail[2];
} Buf8;

/* Clears the 15 slot words at the request buffer, then writes one 8-byte read-request
 * packet (0xFF, 1, 4, 1, 0xFFFF, 0xFF, 0xFF) for each controller and ends the list with 0xFE. */
/* Clears the 15 slot words of the SI request buffer, then writes one 8-byte read-request packet per controller and ends the list with 0xFE. */ void __osPackReadData(void)
{
    Buf8 readRequest;
    register s32 i;
    s32 unused;
    s32 *clearPtr;
    u8 *cmd;
    u8 count;

    cmd = (u8 *)(D_800FF6D0 + 0x1250);
    i = 0xE;
    clearPtr = (s32 *)(cmd + 0x38);
    do {
        *clearPtr = 0;
        i -= 1;
        clearPtr -= 1;
    } while (i >= 0);

    count = __osMaxControllers;
    unused = 0;
    *(s32 *)(D_800FF6D0 + 0x128C) = 1;

    readRequest.b[0] = 0xFF;
    readRequest.b[1] = 1;
    readRequest.b[2] = 4;
    *(u16 *)&readRequest.b[4] = 0xFFFF;
    readRequest.b[3] = 1;
    readRequest.tail[0] = -1;
    readRequest.tail[1] = -1;

    for (i = 0; i < __osMaxControllers; i++) {
        *(Buf8 *)cmd = readRequest;
        cmd += 8;
    }
    *cmd = 0xFE;
}
