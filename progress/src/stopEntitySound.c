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

extern EntSnd gSoundEntities[];

/* Finds the index of a free sound entity matching id (top bit kept as a flag); returns -1 if none */
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

static inline void stopSoundEntity(s32 soundId) {
    soundId = findSoundEntity(soundId);
    if (soundId != -1) {
        if (soundId >= 0) {
            gSoundEntities[soundId].active = 1;
        } else {
            gSoundEntities[soundId & 0x7FFFFFFF].flags &= 0xF7;
        }
    }
}

/* Stops the sound entity for soundId, if the sound worker is active */
void stopEntitySound(s32 soundId) {
    if (gWorkerActive != 0) {
        workerLockAcquire();
        stopSoundEntity(soundId);
        workerLockRelease();
    }
}
