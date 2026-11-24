u32 playDistanceSound(u16, f32, s32);
s32 updateSfxPanFromMarker(s32, s32, s32, s32);
u32 randomIntBelow(s32);
f32 findNearestTrackMarker(s32, s16 *);
extern u16 sGroundSoundsType357[], sGroundSoundsDefault[], sGroundSoundsType2[], sGroundSoundsType48[];
extern s32 gTrackMarkerParents[];

/* Plays a random ground-contact sound for the surface type at the actor's distance from the nearest track marker, panned toward that marker. */
void playGroundContactSound(s32 actor, s32 surfaceType) {
    u16 markerIndex;
    u16 *soundIds;
    s32 soundCount;
    f32 distance;

    switch (surfaceType & 255) {
    default:
        soundIds = sGroundSoundsDefault;
        soundCount = 2;
        break;
    case 2:
        soundIds = sGroundSoundsType2;
        soundCount = 2;
        break;
    case 3:
    case 5:
    case 7:
        soundIds = sGroundSoundsType357;
        soundCount = 1;
        break;
    case 4:
    case 8:
        soundIds = sGroundSoundsType48;
        soundCount = 1;
        break;
    }
    distance = findNearestTrackMarker(actor, (s16 *)&markerIndex);
    updateSfxPanFromMarker(playDistanceSound(soundIds[randomIntBelow(soundCount)], distance, 255), gTrackMarkerParents[markerIndex], actor, 0);
}
