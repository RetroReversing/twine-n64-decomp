typedef struct {
    s32 id;            /* 0x000 */
    u8 pad4[0x10C];
    s32 w110;          /* 0x110 */
    s32 w114;          /* 0x114 */
    u8 pad118[0x410];
    u8 tbl528[0x80];   /* 0x528 */
    u8 pad5A8[0xA18];
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

extern EntSnd D_800E5AC4[];

static inline s32 find_snd(s32 id) {
    u32 i = 0;
    s32 key = id & 0x7FFFFFFF;
    s32 off = 0;

    for (; i < 8; i++, off += sizeof(EntSnd)) {
        if (*((u8 *)&D_800E5AC4[0].busy + off) == 0 && *(s32 *)((u8 *)&D_800E5AC4[0].id + off) == key) {
            return i | (id & 0x80000000);
        }
    }
    return -1;
}

void func_8008C0D4(void);
void func_8008C11C(void);
extern u8 D_800CF540;

void func_8008F2A4(u8, s32);

void func_80091970(s32 arg0, s32 arg1, s32 arg2) {
    if (D_800CF540 != 0) {
        arg0 = find_snd(arg0);
        if (arg0 != -1) {
            D_800E5AC4[arg0].tbl528[(u8)arg1] = arg2;
            func_8008F2A4(arg2, 2);
        }
    }
}
