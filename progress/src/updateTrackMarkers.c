void *getObjectListHead();
s32 markObjectsNearPos();
s32 spawnTrackMarkerCaption();
s32 detonateTrackMarker();
s32 selectNextEnemyDef();
extern u8 gTrackMarkerDone[];

/* Finds ready track-marker objects (type 0x24) whose marker record has state 1 and mode 3, marks them and nearby objects, and falls back to spawnTrackMarkerCaption when none fired. */
void updateTrackMarkers(s32 arg0) {
    s32 found;
    u16 markerId;
    u16 markerState;
    void *posRecord;
    void *marker;
    void *obj;

    obj = getObjectListHead();
    found = 0;
    if (obj != NULL) {
        do {
            if (((*(u16 *)((char *)(obj) + 0x78)) == 0x24) && ((marker = (*(void **)((char *)(obj) + 0x6C)), markerId = (*(u16 *)((char *)(marker) + 0x24)), (markerId == 0)) || (*(gTrackMarkerDone + markerId) != 0))) {
                markerState = (*(u16 *)((char *)(marker) + 0x26));
                if ((markerState == 1) && ((*(u16 *)((char *)(marker) + 0x28)) == 3)) {
                    posRecord = obj + 0x24;
                    markObjectsNearPos((*(s32 *)((char *)(obj) + 0x20)), 2, 0x10000, posRecord, 0, (s32) markerState);
                    detonateTrackMarker(obj, posRecord);
                    found = 1;
                    (*(s32 *)((char *)(obj) + 0x60)) |= 1;
                    if (arg0 != 0) {
                        selectNextEnemyDef(arg0, 1);
                    }
                }
            }
            obj = (*(void **)((char *)(obj) + 0x10));
        } while (obj != NULL);
    }
    if ((short)found == 0) {
        spawnTrackMarkerCaption();
    }
}
