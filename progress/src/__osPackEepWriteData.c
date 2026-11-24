/* identical to pfs_build_write_cmd in V-RALLY-PAL (local match library) (matched), with its names changed by decompdecomp */
extern char gSiPifState[];

typedef struct {
    u8 b[12];
} Blk12;

/* Offsets inside gSiPifState: the PIF command buffer, and the flag set when a command is queued. */
#define PFS_PIF_BUF_OFF 0x8660
#define PFS_CMD_READY_OFF 0x869C

/* Builds a controller pak write-block command in the PIF buffer: four zero bytes, a 12-byte
 * header (0x0A, 0x01, 0x05, page, then the 8 data bytes), and an 0xFE end marker. */
/* Builds an EEPROM write command in the PIF buffer: four zero bytes, a 12-byte packet (0x0A, 0x01, 0x05, block index, 8 data bytes), then the 0xFE end marker. */ void __osPackEepWriteData(u8 blockIndex, u8 *writeData)
{
    Blk12 packet;
    u8 *pifCursor;
    s32 i;
    u8 *dataCursor;

    pifCursor = (u8 *)gSiPifState + PFS_PIF_BUF_OFF;
    *(s32 *)(gSiPifState + PFS_CMD_READY_OFF) = 1;
    packet.b[0] = 10;
    packet.b[1] = 1;
    packet.b[2] = 5;
    packet.b[3] = blockIndex;
    dataCursor = writeData;
    for (i = 4; i < 12; i++) {
        packet.b[i] = *dataCursor++;
    }
    for (i = 3; i >= 0; i--) {
        *pifCursor++ = 0;
    }
    *(Blk12 *)pifCursor = packet;
    pifCursor[12] = 0xFE;
}
