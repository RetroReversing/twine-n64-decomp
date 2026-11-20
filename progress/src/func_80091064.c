typedef struct {
    s32 id;            /* 0x000 */
    u8 pad4[0xFBC];
    u8 active;         /* 0xFC0 */
    u8 busy;           /* 0xFC1 */
    s16 hFC2;          /* 0xFC2 */
    u8 bFC4;           /* 0xFC4 */
    u8 bFC5;           /* 0xFC5 */
    u8 padFC6[0x26];
    s16 hFEC;          /* 0xFEC */
    u8 flags;          /* 0xFEE */
    u8 padFEF[9];
} EntSnd;

extern EntSnd gSndEntities[];

static inline s32 find_snd(s32 id) {
    u32 i = 0;
    s32 key = id & 0x7FFFFFFF;
    s32 off = 0;

    for (; i < 8; i++, off += sizeof(EntSnd)) {
        if (*((u8 *)&gSndEntities[0].busy + off) == 0 && *(s32 *)((u8 *)&gSndEntities[0].id + off) == key) {
            return i | (id & 0x80000000);
        }
    }
    return -1;
}

void func_80091064(s32 arg0, s16 arg1) {
    arg0 = find_snd(arg0);
    if (arg0 != -1) {
        if (arg0 >= 0) {
            gSndEntities[arg0].hFC2 = arg1;
        } else {
            arg0 &= 0x7FFFFFFF;
            gSndEntities[arg0].hFEC = arg1;
            gSndEntities[arg0].flags |= 0x20;
        }
    }
}
