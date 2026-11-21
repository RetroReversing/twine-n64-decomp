typedef struct { u8 pad0[0x14]; s32 flags; } Sub846A8;
typedef struct { u8 pad0[0x24]; u8 pos[0x44]; Sub846A8 *sub; } Obj846A8;

void playDistanceSound(u16, f32, s32);
u32 randomIntBelow(s32);
f32 findNearestTrackMarker(s32, s16 *);
extern u16 sCueSoundsAlt[];
extern u16 sCueSoundsDefault[];
extern u32 gGameMode;

/* Plays a mode-dependent cue sound at the volume of the nearest track marker. */ void playTrackCueSound(s32 unused0, Obj846A8 *actor) {
    s16 markerIndex;
    f32 volume;
    u16 soundId;

    volume = findNearestTrackMarker((s32)actor->pos, &markerIndex);
    switch (gGameMode) {
    case 2:
        soundId = 0x179;
        if (!(actor->sub->flags & 0x200000)) {
            goto rnd;
        }
        goto play;
    case 34:
        soundId = 0x13E;
        if (!(actor->sub->flags & 0x200000)) {
            soundId = sCueSoundsAlt[randomIntBelow(2)];
        }
        goto play;
    case 28:
        if (actor->sub->flags & 0x200000) {
            soundId = 0x179;
        } else {
            soundId = sCueSoundsDefault[randomIntBelow(2)];
        }
        goto play;
    case 29:
        soundId = 0x179;
        if (!(actor->sub->flags & 0x200000)) {
        rnd:
            soundId = sCueSoundsDefault[randomIntBelow(2)];
        }
    play:
        playDistanceSound(soundId, volume, 0xFF);
        break;
    }
}
