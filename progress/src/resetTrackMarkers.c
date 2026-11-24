s32 resetTargetSearch();
extern char gTrackMarkerDone[];
extern s8 gTrackMarkerActiveCount;

/* Clears the done flag of all 47 track markers, resets the target search, and zeroes the active marker value. */
void resetTrackMarkers(void) {
    u32 i;

    i = 0;
    do {
        *(gTrackMarkerDone + i) = 0;
        i += 1;
    } while (i < 0x2FU);
    resetTargetSearch();
    gTrackMarkerActiveCount = 0;
}
