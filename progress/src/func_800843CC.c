s32 func_8000A8B4(s32, f32, s32);
s32 updateSfxPanFromMarker(s32, s32, s32, s32);
u32 randomIntBelow(s32);
f32 findNearestTrackMarker(s32, s16 *);
extern u16 D_800CE5D0[], D_800CE5D8[];
extern s32 gTrackMarkerTable[];

void func_800843CC(s32 object, u32 variant) {
    s16 index;
    f32 factor = findNearestTrackMarker(object, &index);
    s32 item;
    s32 result;
    s32 *entry;
    if (variant << 24) {
        item = D_800CE5D0[randomIntBelow(4)];
    
    result = func_8000A8B4(item, factor, 255);} else {
        item = D_800CE5D8[randomIntBelow(4)];
    
    result = func_8000A8B4(item, factor, 255);}
    entry = gTrackMarkerTable + (u16)index;
    updateSfxPanFromMarker(result, *entry, object, 0);
}

