typedef struct { u8 pad0[0x120]; f32 f120; f32 f124; } Func80073508Obj;
extern Func80073508Obj *gTrackMarkers[];
extern u8 gTrackMarkerActiveMask;
f32 approxDistance(s32, void *);

void updateTrackMarkerProximity(s32 arg0, f32 arg1) {
    u32 i;
    u32 bit;
    f32 t;
    Func80073508Obj *obj;
    for (i = 0; i < 4; i++) {
        obj = gTrackMarkers[i];
        if (obj != NULL) {
            t = (100.0f - approxDistance(arg0, (u8 *)obj + 0x10));
            t = t * arg1;
            if (t > 0.0f) {
                gTrackMarkers[i]->f120 = t;
            }
            bit = 1 << i;
            if (gTrackMarkerActiveMask & bit) {
                gTrackMarkers[i]->f124 = gTrackMarkers[i]->f124 + 2.0f * t;
            }
            if (gTrackMarkers[i]->f124 > 1.0f) {
                gTrackMarkers[i]->f124 = 1.0f;
            }
            if (gTrackMarkers[i]->f124 < 0.0f) {
                gTrackMarkers[i]->f124 = 0.0f;
            }
        }
    }
}
