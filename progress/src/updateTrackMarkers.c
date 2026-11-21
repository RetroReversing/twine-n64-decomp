void *getObjectListHead();
s32 markObjectsNearPos();
s32 func_8005B5A8();
s32 func_8005C508();
s32 func_8007092C();
extern u8 gTrackMarkerDone[];

/* Finds ready track-marker objects (type 0x24) whose marker record has state 1 and mode 3, marks them and nearby objects, and falls back to func_8005B5A8 when none fired. */
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
                    func_8005C508(obj, posRecord);
                    found = 1;
                    (*(s32 *)((char *)(obj) + 0x60)) |= 1;
                    if (arg0 != 0) {
                        func_8007092C(arg0, 1);
                    }
                }
            }
            obj = (*(void **)((char *)(obj) + 0x10));
        } while (obj != NULL);
    }
    if ((short)found == 0) {
        func_8005B5A8();
    }
}
