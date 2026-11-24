/* adapted from similar verified C in playRandomTrackMarkerSound in TWINE (matched), with its names changed by decompdecomp */
s32 playDistanceSound(s32, f32, s32);
s32 updateSfxPanFromMarker(s32, s32, s32, s32);
u32 randomIntBelow(s32);
f32 findNearestTrackMarker(s32, s16 *);
extern u16 gMarkerVariantSoundIdsA[], gMarkerVariantSoundIdsB[];
extern s32 gTrackMarkerParents[];

/* Plays a random one of three sounds (table chosen by variant) scaled by distance to the object's nearest track marker, then pans it from that marker. */ void playMarkerVariantSound(s32 obj, u32 useAltTable) {
    s16 markerIndex;
    f32 distanceFactor = findNearestTrackMarker(obj, &markerIndex);
    s32 soundId;
    s32 voice;
    s32 *markerEntry;
    if (useAltTable << 24) {
        soundId = gMarkerVariantSoundIdsA[randomIntBelow(3)];
    
    voice = playDistanceSound(soundId, distanceFactor, 255);} else {
        soundId = gMarkerVariantSoundIdsB[randomIntBelow(3)];
    
    voice = playDistanceSound(soundId, distanceFactor, 255);}
    markerEntry = gTrackMarkerParents + (u16)markerIndex;
    updateSfxPanFromMarker(voice, *markerEntry, obj, 0);
}

