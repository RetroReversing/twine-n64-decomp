typedef struct {
    s32 id;
    u8 pad4[0xFBC];
    u8 active;
    u8 busy;
    u8 padFC2[0x2C];
    u8 flags;
    u8 padFEF[9];
} Ent91254;

extern Ent91254 gSoundEntities[];

static inline s32 find_91254(s32 id) {
    u32 i = 0;
    s32 key = id & 0x7FFFFFFF;
    s32 off = 0;

    for (; i < 8; i++, off += sizeof(Ent91254)) {
        if (*((u8 *)&gSoundEntities[0].busy + off) == 0 && *(s32 *)((u8 *)&gSoundEntities[0].id + off) == key) {
            return i | (id & 0x80000000);
        }
    }
    return -1;
}

/* Finds a sound entity by handle; sets it active, or with the handle's top bit set clears flag 0x08 instead. */ void activateSoundEntity(s32 handle) {
    handle = find_91254(handle);
    if (handle != -1) {
        if (handle >= 0) {
            gSoundEntities[handle].active = 1;
        } else {
            gSoundEntities[handle & 0x7FFFFFFF].flags &= 0xF7;
        }
    }
}
