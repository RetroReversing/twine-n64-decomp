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

extern EntSnd gSndEntities[];

static inline s32 find_snd(s32 id) {
    u32 i = 0;
    s32 key = id & 0x7FFFFFFF;
    s32 hi = id & 0x80000000;
    s32 off = 0;

    for (; i < 8; i++, off += sizeof(EntSnd)) {
        if (*((u8 *)&gSndEntities[0].busy + off) == 0 && *(s32 *)((u8 *)&gSndEntities[0].id + off) == key) {
            return i | hi;
        }
    }
    return -1;
}

void workerLockAcquire(void);
void workerLockRelease(void);
extern u8 gWorkerActive;

void func_8008F2A4(u8, s32);

void func_80091970(s32 arg0, s32 arg1, s32 arg2) {
    if (gWorkerActive != 0) {
        arg0 = find_snd(arg0);
        if (arg0 != -1) {
            gSndEntities[arg0].tbl528[(u8)arg1] = arg2;
            func_8008F2A4(arg2, 2);
        }
    }
}
