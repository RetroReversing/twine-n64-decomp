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

extern EntSnd gSoundEntities[];

/* Finds the sound entity whose id matches; returns its index, with the high bit kept from the input flag, or -1. */
static inline s32 findSoundEntity(s32 id) {
    u32 i = 0;
    s32 key = id & 0x7FFFFFFF;
    s32 off = 0;

    for (; i < 8; i++, off += sizeof(EntSnd)) {
        if (*((u8 *)&gSoundEntities[0].busy + off) == 0 && *(s32 *)((u8 *)&gSoundEntities[0].id + off) == key) {
            return i | (id & 0x80000000);
        }
    }
    return -1;
}

void workerLockAcquire(void);
void workerLockRelease(void);
extern u8 gWorkerActive;

/* Stores two values into the matching sound entity; a negative index selects the second slot set and sets flag 0x10. */
void setSoundEntityValues(s32 id, s32 value1, s32 value2) {
    id = findSoundEntity(id);
    if (id != -1) {
        if (id >= 0) {
            gSoundEntities[id].w110 = value1;
            gSoundEntities[id].w114 = value2;
        } else {
            id &= 0x7FFFFFFF;
            {
                s32 off = id * sizeof(EntSnd);
                u8 flags = *((u8 *)&gSoundEntities[0].flags + off);
                *(s32 *)((u8 *)&gSoundEntities[0].wFE4 + off) = value1;
                *(s32 *)((u8 *)&gSoundEntities[0].wFE8 + off) = value2;
                *((u8 *)&gSoundEntities[0].flags + off) = flags | 0x10;
            }
        }
    }
}
