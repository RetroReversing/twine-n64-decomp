/* adapted from similar verified C in func_8009010C in TWINE (matched), with its names changed by decompdecomp */
typedef struct { u8 pad0[4]; u32 start; u8 pad8[0xC]; u8 *ptr; u8 pad18[2]; u16 pitch; u8 pad1C[4]; u32 time; u8 chan; u8 pad25[3]; } Ent010C;
typedef struct { u8 pad0[0x120]; u32 now; u8 pad124[0x444]; Ent010C ents[64]; } Seq010C;
s32 func_80095A80(s32, u8, u8, s32);
extern u8 D_800EDA87;
extern Seq010C *gSeqPlayer;

/* Advances each active sequence channel's delta-time event stream and sends pitch-bend updates when events are due. */ void updateSeqChannels(void) {
    s32 ch;
    u8 finished;
    u8 *next;
    s32 status;
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
            value = gSeqPlayer->ents[ch].ptr[1];
            if (status == 0x80 && value == 0) {
                gSeqPlayer->ents[ch].ptr = NULL;
                finished = 1;
            } else {
                if (status & 0x80) {
                    value |= ((status & 0x7F) << 8);
                    len = 2;
                } else {
                    value = status & 0xFF;
                    len = 1;
                }
                newTime = gSeqPlayer->ents[ch].time + (s16)value;
                if (gSeqPlayer->ents[ch].start + gSeqPlayer->now >= newTime) {
                    gSeqPlayer->ents[ch].ptr += len;
                    gSeqPlayer->ents[ch].time = newTime;
                    next = gSeqPlayer->ents[ch].ptr;
                    status = next[0];
                    value = next[1];
                    if (status & 0x80) {
                        value = (s32)((value | ((status & 0x7F) << 8)) << 17) >> 17;
                        gSeqPlayer->ents[ch].ptr = next + 2;
                    } else {
                        value = (s8)status;
                        gSeqPlayer->ents[ch].ptr = next + 1;
                    }
                    gSeqPlayer->ents[ch].pitch += value;
                    func_80095A80(1, gSeqPlayer->ents[ch].chan, D_800EDA87, (gSeqPlayer->ents[ch].pitch >> 7) & 0xFF);
                    func_80095A80(0x21, gSeqPlayer->ents[ch].chan, D_800EDA87, ((u8 *)&gSeqPlayer->ents[ch].pitch)[1] & 0x7F);
                } else {
                    finished = 1;
                }
            }
        } while (!finished);
    }
}
