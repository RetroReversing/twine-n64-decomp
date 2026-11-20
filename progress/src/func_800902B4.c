/* adapted from similar verified C in func_8009010C in TWINE (matched), with its names changed by decompdecomp */
typedef struct { u8 pad0[4]; u32 start; u8 pad8[0xC]; u8 *ptr; u8 pad18[2]; u16 pitch; u8 pad1C[4]; u32 time; u8 chan; u8 pad25[3]; } Ent010C;
typedef struct { u8 pad0[0x120]; u32 now; u8 pad124[0x444]; Ent010C ents[64]; } Seq010C;
s32 func_80095A80(s32, u8, u8, s32);
extern u8 D_800EDA87;
extern Seq010C *D_800EDA8C;

void func_800902B4(void) {
    s32 i;
    u8 done;
    u8 *p;
    s32 b0;
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
            v = D_800EDA8C->ents[i].ptr[1];
            if (b0 == 0x80 && v == 0) {
                D_800EDA8C->ents[i].ptr = NULL;
                done = 1;
            } else {
                if (b0 & 0x80) {
                    v |= ((b0 & 0x7F) << 8);
                    n = 2;
                } else {
                    v = b0 & 0xFF;
                    n = 1;
                }
                t = D_800EDA8C->ents[i].time + (s16)v;
                if (D_800EDA8C->ents[i].start + D_800EDA8C->now >= t) {
                    D_800EDA8C->ents[i].ptr += n;
                    D_800EDA8C->ents[i].time = t;
                    p = D_800EDA8C->ents[i].ptr;
                    b0 = p[0];
                    v = p[1];
                    if (b0 & 0x80) {
                        v = (s32)((v | ((b0 & 0x7F) << 8)) << 17) >> 17;
                        D_800EDA8C->ents[i].ptr = p + 2;
                    } else {
                        v = (s8)b0;
                        D_800EDA8C->ents[i].ptr = p + 1;
                    }
                    D_800EDA8C->ents[i].pitch += v;
                    func_80095A80(1, D_800EDA8C->ents[i].chan, D_800EDA87, (D_800EDA8C->ents[i].pitch >> 7) & 0xFF);
                    func_80095A80(0x21, D_800EDA8C->ents[i].chan, D_800EDA87, ((u8 *)&D_800EDA8C->ents[i].pitch)[1] & 0x7F);
                } else {
                    done = 1;
                }
            }
        } while (!done);
    }
}
