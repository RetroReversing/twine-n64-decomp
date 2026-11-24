typedef struct { u8 pad[0x10]; u8 pos[0xF0]; s32 flags; } O84270;
f32 approxDistance(void *, s32);
extern O84270 *gTrackMarkerParents[];

/* Returns the distance to the nearest active track marker (of 6) and stores its index in outIndex. */ f32 findNearestTrackMarker(s32 position, s16 *outIndex) {
    f32 bestDistance = 65536.0f;
    s16 index;
    f32 distance;

    *outIndex = 0;
    for (index = 0; index < 6; index++) {
        if (gTrackMarkerParents[index] != NULL && !(gTrackMarkerParents[index]->flags & 0x100)) {
            distance = approxDistance(gTrackMarkerParents[index]->pos, position);
            if (distance < bestDistance) {
                bestDistance = distance;
                *outIndex = index;
            }
        }
    }
    return bestDistance;
}
