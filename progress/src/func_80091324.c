typedef struct {
    s32 id;            /* 0x000 */
    u8 pad4[0x10C];
    s32 w110;          /* 0x110 */
    s32 w114;          /* 0x114 */
    u8 pad118[0xEA8];
    u8 active;         /* 0xFC0 */
    u8 busy;           /* 0xFC1 */
    s16 hFC2;          /* 0xFC2 */
    u8 bFC4;           /* 0xFC4 */
    u8 bFC5;           /* 0xFC5 */
    u8 padFC6[0x1E];
    s32 wFE4;          /* 0xFE4 */
    s32 wFE8;          /* 0xFE8 */
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

void func_8008C0D4(void);
void func_8008C11C(void);
extern u8 D_800CF540;

static inline void stop_snd_91324(s32 arg0) {
    arg0 = find_snd(arg0);
    if (arg0 != -1) {
        if (arg0 >= 0) {
            gSndEntities[arg0].active = 1;
        } else {
            gSndEntities[arg0 & 0x7FFFFFFF].flags &= 0xF7;
        }
    }
}

void func_80091324(s32 arg0) {
    if (D_800CF540 != 0) {
        func_8008C0D4();
        stop_snd_91324(arg0);
        func_8008C11C();
    }
}
