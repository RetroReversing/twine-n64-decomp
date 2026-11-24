s32 getEntryKind(s16, u16);
s32 formatTrackMarkerLabel(s16, s32);
s32 lookupEntryDataById(s16, s32);
void setEntryTableSubtype(s32,s32,s32);
void refreshEntryLabel(s16);
void spawnCaptionMessage(s32,s32,s32,s32,s32,s32,s32,s32,s32,s32,s32);
void spawnTrackMarkerText(void);
s32 lookupDataEntry(s32);
extern s32 gTrackMarkerSerial, gTrackMarkerParents;

/* Shows the track marker for markerId: 0-9 and 10-19 are two banks of
   entries (with their own state checks), 20+ are the special markers. */
void showTrackMarker(u32 markerId) {
    if (!markerId) return;
    if (markerId < 10) {
        s16 entryId = markerId;
        s32 label, *markerTable;
        if (getEntryKind(entryId,0)==3 || getEntryKind(entryId,0)==1) return;
        setEntryTableSubtype(entryId,1,0);
        gTrackMarkerSerial++;
        label = formatTrackMarkerLabel(entryId,0);
        markerTable = &gTrackMarkerParents;
        spawnCaptionMessage(0,*markerTable,label,-1,-1,0,0,0,3,0,0);
        label = lookupEntryDataById(entryId,0);
        spawnCaptionMessage(0,*markerTable,label,-1,-1,1,0,0,3,0,0);
    } else if (markerId < 20) {
        s16 entryId;
        s32 label, *markerTable;
        markerId -= 10;
        entryId = markerId;
        if (getEntryKind(entryId,0)==3 || getEntryKind(entryId,0)==2) return;
        spawnTrackMarkerText();
        setEntryTableSubtype(entryId,2,0);
        gTrackMarkerSerial++;
        label = formatTrackMarkerLabel(entryId,0);
        markerTable = &gTrackMarkerParents;
        spawnCaptionMessage(0,*markerTable,label,-1,-1,0,0,0,3,0,0);
        label = lookupEntryDataById(entryId,0);
        spawnCaptionMessage(0,*markerTable,label,-1,-1,1,0,0,3,0,0);
    } else {
        s16 entryId;
        s32 label, *markerTable;
        markerId -= 20;
        entryId = markerId;
        refreshEntryLabel(entryId);
        gTrackMarkerSerial++;
        label = lookupDataEntry(0xA3);
        markerTable = &gTrackMarkerParents;
        spawnCaptionMessage(0,*markerTable,label,-1,-1,0,0,0,3,0,0);
        label = lookupEntryDataById(entryId,0);
        spawnCaptionMessage(0,*markerTable,label,-1,-1,1,0,0,3,0,0);
    }
}
