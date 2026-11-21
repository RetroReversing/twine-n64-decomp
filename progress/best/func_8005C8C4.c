extern s32 func_8005B5A8();
extern void requestSound(s32);
extern s32 lookupDataEntry(s32);
extern void func_80073AF8(s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32);
extern s32 sTrackMarkerTable[];
extern void *gPlayerActor;

void func_8005C8C4(void) {
    char *actor = gPlayerActor;
    s32 done = 0;
    s32 result;
    s32 type;
    char *info;
    u32 mask;

    if (!actor) goto finish;
    type = *(u16 *)(actor + 0x78);
    if (type >= 0x13) goto finish;
    if (type < 0x11) {
        result = done;
        goto check;
    }
    info = *(char **)(actor + 0x6C);
    done = 1;
    if (*(s16 *)(actor + 0x7C)) goto finish;
    *(s16 *)(actor + 0x7C) = 1;
    done = 0x08000000;
    mask = done;
    if (*(u32 *)(info + 0x2C) & mask) {
        s32 entry;
        *(u32 *)(actor + 0x60) |= mask;
        requestSound(0x12E);
        entry = lookupDataEntry(0x160);
        func_80073AF8(0, sTrackMarkerTable[0], entry, -1, -1, 1, 0, 0, 3, 0, 0);
    }
    done = 1;
finish:
    result = done;
check:
    if (!result) func_8005B5A8();
}
