typedef struct { u8 pad0[0x30]; s32 flags; } TrackMarkerDef;
typedef struct { u8 pad0[0x70]; TrackMarkerDef *def; u8 pad74[4]; s32 state78; s16 h7C_pad; } PlayerActorX;
typedef struct { u8 pad0[0x70]; TrackMarkerDef *def; u8 pad74[4]; s32 state78; } PlayerActor;

void requestSound(s32);
void func_8005B5A8(void);
void func_80073AF8(s32, s32, char *, s32, s32, s32, s32, s32, s32, s32, s32);
s32 lookupDataEntry(s32);
s32 sprintf(char *, const char *, ...);
extern u8 sMarkerMessageCount;
extern u8 D_801007D8;
extern PlayerActor *gPlayerActor;
extern s32 sTrackMarkerTable;
extern char D_800D4110[];

/* Shows the track-marker message once the player actor is in the trigger state; returns 1 when shown. */
static inline s32 showTrackMarkerMessage(void) {
    char buf[0x100];
    s32 shown = 0;
    s32 flags;
    s32 idA;
    s32 idB;
    TrackMarkerDef *def;
    s32 none;

    if (gPlayerActor == NULL) {
        goto out;
    }
    def = gPlayerActor->def;
    if (def == NULL) {
        goto out;
    }
    none = -1;
    if (gPlayerActor->state78 != 0x5A0000) {
        goto out;
    }
    flags = def->flags;
    if ((flags & 0xFFFF0) != 0x670) {
        goto out;
    }
    if ((flags & 0xFFF00000) != 0x02600000) {
        goto out;
    }
    sMarkerMessageCount++;
    idA = lookupDataEntry(0xF3);
    idB = lookupDataEntry(0xFF);
    sprintf(buf, D_800D4110, idA, sMarkerMessageCount, idB, D_801007D8, lookupDataEntry(0xFD));
    func_80073AF8(0, sTrackMarkerTable, buf, none, none, 1, 0, 0, 3, 0, 0);
    *(s16 *)((u8 *)gPlayerActor + 0x7A) = 1;
    requestSound(0x111);
    shown = 1;
out:
    return (s16)shown;
}

/* Checks for a track-marker trigger and falls back to func_8005B5A8 when no message was shown. */
void checkTrackMarkerTrigger(void) {
    s32 v = showTrackMarkerMessage();

    if (v == 0) {
        func_8005B5A8();
    }
}
