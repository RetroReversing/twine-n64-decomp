typedef struct { u8 active; u8 pad[7]; void *arg; s32 id; u8 tail[8]; } Record93410;
extern Record93410 gVoiceTable[];
extern u8 sVoiceCount;
void copyVoiceParamsAndWriteback(void *, s32);
/* Calls copyVoiceParamsAndWriteback for every voice table entry that is marked active. */ void updateActiveVoices(void) {
    s32 i;
    for (i = 0; i < sVoiceCount; i++) {
        if (gVoiceTable[i].active == 1)
            copyVoiceParamsAndWriteback(gVoiceTable[i].arg, gVoiceTable[i].id);
    }
}

void initMenuSlot(s32, s16);
void resetSlotState(s32);
extern s16 D_800E1A80[];
extern s8 gDemoSticks[], D_8010D436[], D_80115108[], D_8011510C[];
void resetMenuSlots(void) {
    s32 i = 0;
    s16 *slot = D_800E1A80;
    s32 src = 0;
    s32 dst = 0;
    do {
        s16 value;
        initMenuSlot((u16)i, 0);
        resetSlotState(i);
        *(s32 *)(D_80115108 + dst) = *(s16 *)(gDemoSticks + src);
        value = *(s16 *)(D_8010D436 + src);
        i++;
        src += 8;
        *(s32 *)(D_8011510C + dst) = value;
        *slot++ = 0;
        dst += 0xA0;
    } while (i < 4);
}

u64 osGetTime(void);
extern u64 gTimeAccumulator;
extern u64 gLastDeltaTime;
extern u64 gPrevTickTime;

void resetFrameTimer(void) {
    gLastDeltaTime = 0;
    gPrevTickTime = osGetTime();
    gTimeAccumulator = 0;
}

typedef struct { u16 id; u8 rest[0x26]; } Record26314;
typedef struct { Record26314 *records; u8 pad; u8 count; } List26314;
Record26314 *findNthRecordById(List26314 *list, u16 id, u8 occurrence) {
    u16 i, seen;
    u8 count;
    Record26314 *base, *entry;

    seen = 0;
    if (list == NULL)
        return NULL;
    count = list->count;
    i = 0;
    if (count) {
        base = list->records;
        do {
            entry = &base[i];
            i++;
            if (entry->id == id && ++seen == occurrence)
                return entry;
        } while (i < count);
    }
    return NULL;
}
