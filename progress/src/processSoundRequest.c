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
    u8 padFEF;
    s32 *ptrFF0;       /* 0xFF0 */
    u8 bFF4;           /* 0xFF4 */
    u8 padFF5[3];
} EntSnd;

extern EntSnd gSoundEntities[];

typedef struct { s32 words[10]; } SoundRequest;

s32 rampSoundPlayerChannels(u8, u16, s32, s32);
s32 startSceneGroupSound(u16, u16, s32, s32 *, s32);
s32 runSceneGroupEntry(u16, u16, s32, s32 *);
s32 setSoundEntityParams(s32, s32, s32);
void stopEntitySound(s32);
void workerLockAcquire(void);
void workerLockRelease(void);
extern u8 gSoundWorkerActive;

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

static inline void stop_snd(s32 arg0) {
    arg0 = find_snd(arg0);
    if (arg0 != -1) {
        if (arg0 >= 0) {
            gSoundEntities[arg0].active = 1;
        } else {
            gSoundEntities[arg0 & 0x7FFFFFFF].flags &= 0xF7;
        }
    }
}

static inline void set_snd(s32 arg0, s32 arg1, s32 arg2) {
    arg0 = find_snd(arg0);
    if (arg0 != -1) {
        if (arg0 >= 0) {
            gSoundEntities[arg0].w110 = arg1;
            gSoundEntities[arg0].w114 = arg2;
        } else {
            arg0 &= 0x7FFFFFFF;
            gSoundEntities[arg0].wFE4 = arg1;
            gSoundEntities[arg0].wFE8 = arg2;
            gSoundEntities[arg0].flags |= 0x10;
        }
    }
}

static inline void set_snd_param(s32 arg0, s16 arg1) {
    arg0 = find_snd(arg0);
    if (arg0 != -1) {
        if (arg0 >= 0) {
            gSoundEntities[arg0].hFC2 = arg1;
        } else {
            arg0 &= 0x7FFFFFFF;
            gSoundEntities[arg0].hFEC = arg1;
            gSoundEntities[arg0].flags |= 0x20;
        }
    }
}

/* Handles a sound request: updates or stops an existing sound entity, or starts a new scene-group sound and returns its handle via outHandle. */
void processSoundRequest(void *request, s32 *outHandle, s32 immediate) {
    struct {
        s32 flags;
        s32 param1;
        s32 param2;
        u16 param3;
        u16 index;
        u8 channel;
        u8 pad[7];
        s8 mode;
    } options;
    s32 entityIdx;
    s32 targetIdx;
    u8 requestFlags;
    u16 temp_s1;
    s32 temp_s2;
    u8 temp_s3;
    u16 temp_s1_4;
    s32 temp_s2_4;
    s32 temp_s1_5;
    u16 temp_s2_5;
    s32 temp_v0;
    s32 temp_v0_7;

    entityIdx = find_snd(*(s32 *)((char *)(request) + 0));
    if (entityIdx != -1) {
        requestFlags = (*(u8 *)((char *)(request) + 0x26));
        if (requestFlags & 4) {
            { SoundRequest *dest = (SoundRequest *)(entityIdx * sizeof(EntSnd) + (u8 *)gSoundEntities + 0xFC8); *dest = *(SoundRequest *)request; }
            gSoundEntities[entityIdx].bFF4 = 1;
            gSoundEntities[entityIdx].ptrFF0 = outHandle;
            gSoundEntities[entityIdx].flags = gSoundEntities[entityIdx].flags & 0xFB;
            *outHandle = (*(s32 *)((char *)(request) + 0)) | 0x80000000;
            return;
        }
        if (immediate & 0xFF) {
            if ((requestFlags & 1) != 0) {
                rampSoundPlayerChannels(0U, (*(u16 *)((char *)(request) + 4)), (*(s32 *)((char *)(request) + 0)), 2);
            } else if (requestFlags & 0x40) {
                rampSoundPlayerChannels(0U, (*(u16 *)((char *)(request) + 4)), (*(s32 *)((char *)(request) + 0)), 3);
            } else {
                rampSoundPlayerChannels(0U, (*(u16 *)((char *)(request) + 4)), (*(s32 *)((char *)(request) + 0)), 1);
            }
        } else if ((requestFlags & 1) != 0) {
            temp_s1 = (*(u16 *)((char *)(request) + 4));
            temp_s2 = (*(s32 *)((char *)(request) + 0));
            if (gSoundWorkerActive != 0) {
                workerLockAcquire();
                rampSoundPlayerChannels(0U, temp_s1, temp_s2, 2);
                workerLockRelease();
            }
        } else if (requestFlags & 0x40) {
            temp_s1 = (*(u16 *)((char *)(request) + 4));
            temp_s2 = (*(s32 *)((char *)(request) + 0));
            if (gSoundWorkerActive != 0) {
                workerLockAcquire();
                rampSoundPlayerChannels(0U, temp_s1, temp_s2, 3);
                workerLockRelease();
            }
        } else {
            temp_s1 = (*(u16 *)((char *)(request) + 4));
            temp_s2 = (*(s32 *)((char *)(request) + 0));
            if (gSoundWorkerActive != 0) {
                workerLockAcquire();
                rampSoundPlayerChannels(0U, temp_s1, temp_s2, 1);
                workerLockRelease();
            }
        }
        if (outHandle != NULL) {
            if ((*(u8 *)((char *)(request) + 0x26)) & 2) {
                targetIdx = find_snd(*(s32 *)((char *)(request) + 8));
                if (targetIdx != -1) {
                    if (immediate & 0xFF) {
                        stop_snd(*(s32 *)((char *)(request) + 8));
                        rampSoundPlayerChannels((*(u8 *)((char *)(request) + 0x18)), (*(u16 *)((char *)(request) + 0xC)), (*(s32 *)((char *)(request) + 8)), 0);
                        if ((*(u8 *)((char *)(request) + 0x26)) & 0x10) {
                            set_snd(*(s32 *)((char *)(request) + 8), (*(s32 *)((char *)(request) + 0x1C)), (*(s32 *)((char *)(request) + 0x20)));
                        }
                        if ((*(u8 *)((char *)(request) + 0x26)) & 0x20) {
                            set_snd_param(*(s32 *)((char *)(request) + 8), (*(u16 *)((char *)(request) + 0x24)));
                        }
                    } else {
                        stopEntitySound((*(s32 *)((char *)(request) + 8)));
                        temp_s3 = (*(u8 *)((char *)(request) + 0x18));
                        temp_s1_4 = (*(u16 *)((char *)(request) + 0xC));
                        temp_s2_4 = (*(s32 *)((char *)(request) + 8));
                        if (gSoundWorkerActive != 0) {
                            workerLockAcquire();
                            rampSoundPlayerChannels(temp_s3, temp_s1_4, temp_s2_4, 0);
                            workerLockRelease();
                        }
                        if ((*(u8 *)((char *)(request) + 0x26)) & 0x10) {
                            setSoundEntityParams((*(s32 *)((char *)(request) + 8)), (*(s32 *)((char *)(request) + 0x1C)), (*(s32 *)((char *)(request) + 0x20)));
                        }
                        if ((*(u8 *)((char *)(request) + 0x26)) & 0x20) {
                            temp_s1_5 = (*(s32 *)((char *)(request) + 8));
                            temp_s2_5 = (*(u16 *)((char *)(request) + 0x24));
                            if (gSoundWorkerActive != 0) {
                                workerLockAcquire();
                                set_snd_param(temp_s1_5, temp_s2_5);
                                workerLockRelease();
                            }
                        }
                    }
                    *outHandle = (*(s32 *)((char *)(request) + 8));
                    return;
                }
                *outHandle = targetIdx;
                return;
            }
            options.flags = 4;
            if ((*(u8 *)((char *)(request) + 0x26)) & 8) {
                options.flags = 0x14;
            }
            if ((*(u8 *)((char *)(request) + 0x26)) & 0x20) {
                options.flags |= 2;
                options.param3 = (*(u16 *)((char *)(request) + 0x24));
            }
            if ((*(u8 *)((char *)(request) + 0x26)) & 0x10) {
                options.flags |= 1;
                options.param1 = (*(s32 *)((char *)(request) + 0x1C));
                options.param2 = (*(s32 *)((char *)(request) + 0x20));
            }
            options.index = (*(u16 *)((char *)(request) + 0xC));
            options.channel = (*(u8 *)((char *)(request) + 0x18));
            options.mode = 0;
            if (immediate & 0xFF) {
                temp_v0_7 = startSceneGroupSound((*(u16 *)((char *)(request) + 0x14)), (*(u16 *)((char *)(request) + 0x16)), (*(s32 *)((char *)(request) + 0x10)), &options.flags, 1);
                *outHandle = temp_v0_7;
                if ((temp_v0_7 != -1) && ((*(u8 *)((char *)(request) + 0x26)) & 0x80)) {
                    set_snd(temp_v0_7, 0, 0);
                }
            } else {
                temp_v0 = runSceneGroupEntry((*(u16 *)((char *)(request) + 0x14)), (*(u16 *)((char *)(request) + 0x16)), (*(s32 *)((char *)(request) + 0x10)), &options.flags);
                *outHandle = temp_v0;
                if ((temp_v0 != -1) && ((*(u8 *)((char *)(request) + 0x26)) & 0x80)) {
                    setSoundEntityParams(temp_v0, 0, 0);
                }
            }
        }
    }
}
