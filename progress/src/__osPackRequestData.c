/* identical to __osPackRequestData in V-RALLY-PAL (local match library) (matched), with its names changed by decompdecomp */
extern char D_800FF6D0[];
extern u8 __osMaxControllers;

typedef struct {
    u8 b[8];
} Pkt;

/* Clears the 15 slot words in the request buffer, then writes one 8-byte request
 * packet (0xFF, 1, 3, cmd, 0xFF x4) for each controller and ends the list with 0xFE. */
/* Builds the PIF request buffer: clears it, then writes one 8-byte request packet per controller and an 0xFE terminator. */ void __osPackRequestData(u8 cmd)
{
    Pkt request;
    s32 idx;
    s32 *word;
    Pkt *dst;

    idx = 0xE;
    word = (s32 *) (D_800FF6D0 + 0x1288);
    do {
        *word = 0;
        idx -= 1;
        word -= 1;
    } while (idx >= 0);
    *(s32 *) (D_800FF6D0 + 0x128C) = 1;
    dst = (Pkt *) (D_800FF6D0 + 0x128C - 0x3C);
    request.b[0] = 0xFF;
    request.b[1] = 1;
    request.b[2] = 3;
    request.b[3] = cmd;
    request.b[4] = 0xFF;
    request.b[5] = 0xFF;
    request.b[6] = 0xFF;
    request.b[7] = 0xFF;
    for (idx = 0; idx < __osMaxControllers; idx++) {
        *dst = request;
        dst += 1;
    }
    *(u8 *) dst = 0xFE;
}
