/* Sets sTrackMarkerScale to 0.75 of the larger extent of the track marker bounds. */

extern void *gTrackMarkers;
extern f32 sTrackMarkerScale;

void computeTrackMarkerScale(void) {
    f32 maxA, maxB, minA, minB;
    void *marker; void *point; f32 extentA, extentB;
    minA = minB = 99999.0f; maxA = maxB = -99999.0f;
    for (marker = **(void ***)((char *)gTrackMarkers + 8); marker != NULL; marker = *(void **)((char *)marker + 0x10)) {
        if (*(u16 *)((char *)marker + 0x58) == 0x46) {
            point = *(void **)((char *)marker + 0x3C);
            if (maxA < *(f32 *)((char *)point + 0x1C)) maxA = *(f32 *)((char *)point + 0x1C);
            if (maxB < *(f32 *)((char *)point + 0x2C)) maxB = *(f32 *)((char *)point + 0x2C);
            if (minA > *(f32 *)((char *)point + 0x18)) minA = *(f32 *)((char *)point + 0x18);
            if (minB > *(f32 *)((char *)point + 0x28)) minB = *(f32 *)((char *)point + 0x28);
        }
    }
    maxA -= minA;
    maxB -= minB;
    if (maxB < maxA) sTrackMarkerScale = maxA; else sTrackMarkerScale = maxB;
    sTrackMarkerScale *= 0.75f;
}
