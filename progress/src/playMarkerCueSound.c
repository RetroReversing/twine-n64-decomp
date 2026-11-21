typedef struct { u8 pad0[0x14]; s32 flags; } Sub847D4;
typedef struct { u8 pad0[0x24]; u8 pos[0x44]; Sub847D4 *sub; } Obj847D4;

void playDistanceSound(u16, f32, s32);
s32 randomIntBelow(s32);
f32 findNearestTrackMarker(void *, s32 *);
extern u16 D_800CE63C[];
extern u16 D_800CE640[];
extern s32 gGameMode;

/* Plays a track cue sound for an object, chosen by game mode and its flag 0x200000, scaled by the nearest track marker distance. */ void playMarkerCueSound(s32 unused, Obj847D4 *obj) {
    s32 markerIndex;
    f32 distance;
    u16 soundId;

    distance = findNearestTrackMarker(obj->pos, &markerIndex);
    switch (gGameMode) {
    case 2:
        soundId = 0x176;
        if (!(obj->sub->flags & 0x200000)) {
            goto rnd;
        }
        goto play;
    case 20:
    case 34:
        soundId = 0x139;
        if (!(obj->sub->flags & 0x200000)) {
            soundId = D_800CE63C[randomIntBelow(2)];
        }
        goto play;
    case 28:
        if (obj->sub->flags & 0x200000) {
            soundId = 0x176;
        } else {
            soundId = D_800CE640[randomIntBelow(2)];
        }
        goto play;
    case 29:
        soundId = 0x176;
        if (!(obj->sub->flags & 0x200000)) {
        rnd:
            soundId = D_800CE640[randomIntBelow(2)];
        }
    play:
        playDistanceSound(soundId, distance, 0xFF);
        break;
    }
}
