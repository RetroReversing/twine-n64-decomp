typedef struct { u32 start; u8 pad4[8]; u8 *ptr; u8 pad10[4]; u16 pitch; u8 pad16[2]; u32 time; u8 pad1C[4]; u8 chan; u8 pad21[7]; } Ent010C;
typedef struct { u8 pad0[0x120]; u32 now; u8 pad124[0x448]; Ent010C ents[64]; } Seq010C;
s32 func_80095A80(s32, u8, u8, s32);
extern u8 D_800EDA87;
extern Seq010C *D_800EDA8C;

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
        if (D_800EDA8C->ents[i].ptr == NULL) {
            continue;
        }
        done = 0;
        do {
            b0 = D_800EDA8C->ents[i].ptr[0];
            b1 = D_800EDA8C->ents[i].ptr[1];
            if (b0 == 0x80 && b1 == 0) {
                D_800EDA8C->ents[i].ptr = NULL;
                done = 1;
            } else {
                if (b0 & 0x80) {
                    delta = b1 | ((b0 & 0x7F) << 8);
                    n = 2;
                } else {
                    delta = b0 & 0xFF;
                    n = 1;
                }
                t = delta + D_800EDA8C->ents[i].time;
                if (D_800EDA8C->ents[i].start + D_800EDA8C->now >= t) {
                    D_800EDA8C->ents[i].ptr += n;
                    D_800EDA8C->ents[i].time = t;
                    p = D_800EDA8C->ents[i].ptr;
                    b0 = p[0];
                    b1 = p[1];
                    if (b0 & 0x80) {
                        v = (s32)((b1 | ((b0 & 0x7F) << 8)) << 17) >> 17;
                        D_800EDA8C->ents[i].ptr = p + 2;
                    } else {
                        v = (s32)(b0 << 25) >> 25;
                        D_800EDA8C->ents[i].ptr = p + 1;
                    }
                    D_800EDA8C->ents[i].pitch += v;
                    func_80095A80(0x80, D_800EDA8C->ents[i].chan, D_800EDA87, (D_800EDA8C->ents[i].pitch >> 7) & 0xFF);
                    func_80095A80(0x81, D_800EDA8C->ents[i].chan, D_800EDA87, ((u8 *)&D_800EDA8C->ents[i].pitch)[1] & 0x7F);
                } else {
                    done = 1;
                }
            }
        } while (!done);
    }
}
