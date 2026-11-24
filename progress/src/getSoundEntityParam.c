/* adapted from similar verified C in setSoundEntityInactiveFlag in TWINE (matched), with its names changed by decompdecomp */
typedef struct {
    s32 id;            /* 0x000 */
    u8 pad4[0xFBC];
    u8 active;         /* 0xFC0 */
    u8 busy;           /* 0xFC1 */
    s16 hFC2;          /* 0xFC2 */
    u8 bFC4;           /* 0xFC4 */
    u8 bFC5;           /* 0xFC5 */
    u16 hFC6;          /* 0xFC6 */
    u8 padFC8[0x24];
    s16 hFEC;          /* 0xFEC */
    u8 flags;          /* 0xFEE */
    u8 padFEF[9];
} EntSnd;

extern EntSnd gSoundEntities[];

static inline s32 find_snd(s32 id) {
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

extern u8 gSoundWorkerActive;

/* Looks up a sound entity by handle and returns its 16-bit parameter at 0xFC6, or 0 if the sound system is off or the handle is invalid. */ s32 getSoundEntityParam(s32 handle) {
    if (gSoundWorkerActive != 0) {
        handle = find_snd(handle);
        if (handle != -1) {
            if (handle >= 0) {
                return gSoundEntities[handle].hFC6;
            }
        }
    }
    return 0;
}
