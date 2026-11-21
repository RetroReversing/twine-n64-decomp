typedef struct { u8 pad[0x10]; u8 pos[0xF0]; s32 flags; } O84270;
f32 approxDistance(void *, s32);
extern O84270 *gTrackMarkers[];

f32 findNearestTrackMarker(s32 arg0, s16 *arg1) {
    f32 best = 65536.0f;
    s16 i;
    f32 d;

    *arg1 = 0;
    for (i = 0; i < 6; i++) {
        if (gTrackMarkers[i] != NULL && !(gTrackMarkers[i]->flags & 0x100)) {
            d = approxDistance(gTrackMarkers[i]->pos, arg0);
            if (d < best) {
                best = d;
                *arg1 = i;
            }
        }
    }
    return best;
}
