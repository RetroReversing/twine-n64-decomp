s32 func_800312F4(s16, u16);
s32 formatTrackMarkerLabel(s16, s32);
s32 func_800314E0(s16, s32);
void func_80031548(s32,s32,s32);
void func_800315E0(s16);
void func_80073AF8(s32,s32,s32,s32,s32,s32,s32,s32,s32,s32,s32);
void func_80074F04(void);
s32 lookupDataEntry(s32);
extern s32 gTrackMarkerSerial, sTrackMarkerTable;

/* Shows the track marker for markerId: 0-9 and 10-19 are two banks of
   entries (with their own state checks), 20+ are the special markers. */
void showTrackMarker(u32 markerId) {
    if (!markerId) return;
    if (markerId < 10) {
        s16 entryId = markerId;
        s32 label, *markerTable;
        if (func_800312F4(entryId,0)==3 || func_800312F4(entryId,0)==1) return;
        func_80031548(entryId,1,0);
        gTrackMarkerSerial++;
        label = formatTrackMarkerLabel(entryId,0);
        markerTable = &sTrackMarkerTable;
        func_80073AF8(0,*markerTable,label,-1,-1,0,0,0,3,0,0);
        label = func_800314E0(entryId,0);
        func_80073AF8(0,*markerTable,label,-1,-1,1,0,0,3,0,0);
    } else if (markerId < 20) {
        s16 entryId;
        s32 label, *markerTable;
        markerId -= 10;
        entryId = markerId;
        if (func_800312F4(entryId,0)==3 || func_800312F4(entryId,0)==2) return;
        func_80074F04();
        func_80031548(entryId,2,0);
        gTrackMarkerSerial++;
        label = formatTrackMarkerLabel(entryId,0);
        markerTable = &sTrackMarkerTable;
        func_80073AF8(0,*markerTable,label,-1,-1,0,0,0,3,0,0);
        label = func_800314E0(entryId,0);
        func_80073AF8(0,*markerTable,label,-1,-1,1,0,0,3,0,0);
    } else {
        s16 entryId;
        s32 label, *markerTable;
        markerId -= 20;
        entryId = markerId;
        func_800315E0(entryId);
        gTrackMarkerSerial++;
        label = lookupDataEntry(0xA3);
        markerTable = &sTrackMarkerTable;
        func_80073AF8(0,*markerTable,label,-1,-1,0,0,0,3,0,0);
        label = func_800314E0(entryId,0);
        func_80073AF8(0,*markerTable,label,-1,-1,1,0,0,3,0,0);
    }
}
