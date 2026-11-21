typedef struct { u32 start; u8 pad4[8]; u8 *ptr; u8 pad10[4]; u16 pitch; u8 pad16[2]; u32 time; u8 pad1C[4]; u8 chan; u8 pad21[7]; } Ent010C;
typedef struct { u8 pad0[0x120]; u32 now; u8 pad124[0x448]; Ent010C ents[64]; } Seq010C;
s32 func_80095A80(s32, u8, u8, s32);
extern u8 D_800EDA87;
extern Seq010C *gSeqPlayer;

/* Sibling of updateSeqChannels: advances each sequence channel's event stream and sends 0x80/0x81 pitch-bend messages when due. */ void updateSeqChannelsAlt(void) {
    s32 ch;
    u8 finished;
    u8 *next;
    s32 status;
    s32 data;
    s32 delta;
    s32 len;
    u32 newTime;
    s32 value;

    for (ch = 0; ch < 64; ch++) {
        if (gSeqPlayer->ents[ch].ptr == NULL) {
            continue;
        }
        finished = 0;
        do {
            status = gSeqPlayer->ents[ch].ptr[0];
            data = gSeqPlayer->ents[ch].ptr[1];
            if (status == 0x80 && data == 0) {
                gSeqPlayer->ents[ch].ptr = NULL;
                finished = 1;
            } else {
                if (status & 0x80) {
                    delta = data | ((status & 0x7F) << 8);
                    len = 2;
                } else {
                    delta = status & 0xFF;
                    len = 1;
                }
                newTime = delta + gSeqPlayer->ents[ch].time;
                if (gSeqPlayer->ents[ch].start + gSeqPlayer->now >= newTime) {
                    gSeqPlayer->ents[ch].ptr += len;
                    gSeqPlayer->ents[ch].time = newTime;
                    next = gSeqPlayer->ents[ch].ptr;
                    status = next[0];
                    data = next[1];
                    if (status & 0x80) {
                        value = (s32)((data | ((status & 0x7F) << 8)) << 17) >> 17;
                        gSeqPlayer->ents[ch].ptr = next + 2;
                    } else {
                        value = (s32)(status << 25) >> 25;
                        gSeqPlayer->ents[ch].ptr = next + 1;
                    }
                    gSeqPlayer->ents[ch].pitch += value;
                    func_80095A80(0x80, gSeqPlayer->ents[ch].chan, D_800EDA87, (gSeqPlayer->ents[ch].pitch >> 7) & 0xFF);
                    func_80095A80(0x81, gSeqPlayer->ents[ch].chan, D_800EDA87, ((u8 *)&gSeqPlayer->ents[ch].pitch)[1] & 0x7F);
                } else {
                    finished = 1;
                }
            }
        } while (!finished);
    }
}
