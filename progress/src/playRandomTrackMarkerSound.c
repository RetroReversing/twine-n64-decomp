s32 playDistanceSound(s32, f32, s32);
s32 updateSfxPanFromMarker(s32, s32, s32, s32);
u32 randomIntBelow(s32);
f32 findNearestTrackMarker(s32, s16 *);
extern u16 gMarkerSoundIdsA[], gMarkerSoundIdsB[];
extern s32 gTrackMarkerParents[];

/* Plays a random sound (from set A if useSetA is non-zero, else set B) at the nearest track marker, then updates its pan. */ void playRandomTrackMarkerSound(s32 object, u32 useSetA) {
    s16 index;
    f32 distanceFactor = findNearestTrackMarker(object, &index);
    s32 soundId;
    s32 voice;
    s32 *markerEntry;
    if (useSetA << 24) {
        soundId = gMarkerSoundIdsA[randomIntBelow(4)];
    
    voice = playDistanceSound(soundId, distanceFactor, 255);} else {
        soundId = gMarkerSoundIdsB[randomIntBelow(4)];
    
    voice = playDistanceSound(soundId, distanceFactor, 255);}
    markerEntry = gTrackMarkerParents + (u16)index;
    updateSfxPanFromMarker(voice, *markerEntry, object, 0);
}

