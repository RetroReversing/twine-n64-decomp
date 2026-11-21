typedef struct { u8 pad[0x10]; u8 pos[0xF0]; s32 flags; } O84270;
f32 approxDistance(void *, s32);
extern O84270 *sTrackMarkerTable[];

f32 findNearestTrackMarker(s32 arg0, s16 *arg1) {
    f32 best = 65536.0f;
    s16 i;
    f32 d;

    *arg1 = 0;
    for (i = 0; i < 6; i++) {
        if (sTrackMarkerTable[i] != NULL && !(sTrackMarkerTable[i]->flags & 0x100)) {
            d = approxDistance(sTrackMarkerTable[i]->pos, arg0);
            if (d < best) {
                best = d;
                *arg1 = i;
            }
        }
    }
    return best;
}
