/* identical to order_write_request in V-RALLY-PAL (local match library) (matched), with its names changed by decompdecomp */
extern char gSiPifState[];

typedef struct {
    u8 b[12];
} Blk12;

/* Writes a 12-byte request (type 2, 8, 4, then arg) into the order state at +0x8660,
   after clearing the 4 bytes in front of it, and ends it with 0xFE. Sets the
   pending flag at +0x869C. */
/* Packs an EEPROM read command (2, 8, 4, address) into the PIF command buffer and flags it pending. */ void __osPackEepReadData(s8 address)
{
    Blk12 cmd;
    u8 *out;
    s32 count;

    out = (u8 *)gSiPifState + 0x8660;
    *(s32 *)(gSiPifState + 0x869C) = 1;
    cmd.b[0] = 2;
    cmd.b[1] = 8;
    cmd.b[2] = 4;
    cmd.b[3] = address;
    for (count = 3; count >= 0; count--) {
        *out++ = 0;
    }
    *(Blk12 *)out = cmd;
    out[12] = 0xFE;
}
