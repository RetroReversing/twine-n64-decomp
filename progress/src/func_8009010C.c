typedef struct { u32 start; u8 pad4[8]; u8 *ptr; u8 pad10[4]; u16 pitch; u8 pad16[2]; u32 time; u8 pad1C[4]; u8 chan; u8 pad21[7]; } Ent010C;
typedef struct { u8 pad0[0x120]; u32 now; u8 pad124[0x448]; Ent010C ents[64]; } Seq010C;
s32 func_80095A80(s32, u8, u8, s32);
extern u8 D_800EDA87;
extern Seq010C *gSeqPlayer;

void func_8009010C(void) {
    s32 i;
    u8 done;
    u8 *p;
    s32 b0;
    s32 b1;
    s32 delta;
    s32 n;
    u32 t;
    s32 v;

    for (i = 0; i < 64; i++) {
        if (gSeqPlayer->ents[i].ptr == NULL) {
            continue;
        }
        done = 0;
        do {
            b0 = gSeqPlayer->ents[i].ptr[0];
            b1 = gSeqPlayer->ents[i].ptr[1];
            if (b0 == 0x80 && b1 == 0) {
                gSeqPlayer->ents[i].ptr = NULL;
                done = 1;
            } else {
                if (b0 & 0x80) {
                    delta = b1 | ((b0 & 0x7F) << 8);
                    n = 2;
                } else {
                    delta = b0 & 0xFF;
                    n = 1;
                }
                t = delta + gSeqPlayer->ents[i].time;
                if (gSeqPlayer->ents[i].start + gSeqPlayer->now >= t) {
                    gSeqPlayer->ents[i].ptr += n;
                    gSeqPlayer->ents[i].time = t;
                    p = gSeqPlayer->ents[i].ptr;
                    b0 = p[0];
                    b1 = p[1];
                    if (b0 & 0x80) {
                        v = (s32)((b1 | ((b0 & 0x7F) << 8)) << 17) >> 17;
                        gSeqPlayer->ents[i].ptr = p + 2;
                    } else {
                        v = (s32)(b0 << 25) >> 25;
                        gSeqPlayer->ents[i].ptr = p + 1;
                    }
                    gSeqPlayer->ents[i].pitch += v;
                    func_80095A80(0x80, gSeqPlayer->ents[i].chan, D_800EDA87, (gSeqPlayer->ents[i].pitch >> 7) & 0xFF);
                    func_80095A80(0x81, gSeqPlayer->ents[i].chan, D_800EDA87, ((u8 *)&gSeqPlayer->ents[i].pitch)[1] & 0x7F);
                } else {
                    done = 1;
                }
            }
        } while (!done);
    }
}
