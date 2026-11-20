typedef struct { u8 active; u8 pad[7]; void *arg; s32 id; u8 tail[8]; } Record93410;
extern Record93410 D_801096E8[];
extern u8 D_801176E8;
void func_8008C710(void *, s32);
void func_80093410(void) {
    s32 i;
    for (i = 0; i < D_801176E8; i++) {
        if (D_801096E8[i].active == 1)
            func_8008C710(D_801096E8[i].arg, D_801096E8[i].id);
    }
}

void func_80011938(s32, s16);
void func_80081758(s32);
extern s16 D_800E1A80[];
extern s8 D_8010D434[], D_8010D436[], D_80115108[], D_8011510C[];
void func_800820BC(void) {
    s32 i = 0;
    s16 *slot = D_800E1A80;
    s32 src = 0;
    s32 dst = 0;
    do {
        s16 value;
        func_80011938((u16)i, 0);
        func_80081758(i);
        *(s32 *)(D_80115108 + dst) = *(s16 *)(D_8010D434 + src);
        value = *(s16 *)(D_8010D436 + src);
        i++;
        src += 8;
        *(s32 *)(D_8011510C + dst) = value;
        *slot++ = 0;
        dst += 0xA0;
    } while (i < 4);
}

u64 osGetTime(void);
extern u64 D_80102CC8;
extern u64 D_80109DD8;
extern u64 D_80115320;

void func_800070A4(void) {
    D_80109DD8 = 0;
    D_80115320 = osGetTime();
    D_80102CC8 = 0;
}

typedef struct { u16 id; u8 rest[0x26]; } Record26314;
typedef struct { Record26314 *records; u8 pad; u8 count; } List26314;
Record26314 *func_80026314(List26314 *list, u16 id, u8 occurrence) {
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
