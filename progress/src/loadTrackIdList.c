void loadTrackDependencies(s32);
void loadTrackAssetSlot(s32, s32, s32);
typedef struct {
    s32 pad[2];
    volatile s32 value;
} IdTable;
extern IdTable *gTrackMarkerParents;
/* Loads dependencies and asset slots for each track id in a list terminated by a negative value. */
void loadTrackIdList(s16 *ids, s32 arg1) {
    if (*ids >= 0) {
        s16 *idPtr = ids;
        do {
            IdTable *markerTable;
            s32 trackId;
            s32 markerValue;

            loadTrackDependencies(*idPtr);
            markerTable = gTrackMarkerParents;
            trackId = *idPtr;
            markerValue = markerTable->value;
            idPtr++;
            loadTrackAssetSlot(markerValue, trackId, 1);
        } while (*idPtr >= 0);
    }
}
