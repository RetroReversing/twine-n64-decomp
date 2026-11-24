typedef struct {
    u8 pad[0x1e];
    s16 scale;
    u16 x, y, z;
    u8 pad26[2];
    u32 color:8; u32 mid:16; u32 kind:6; u32 low:2;
} Obj;
Obj *spawnTrackMarker(s32);
extern Obj *gTrackMarker;
extern u16 gTrackMarkerX, gTrackMarkerY, gTrackMarkerZ, gTrackMarkerColor;
/* Spawns the track marker if needed, then sets its scale, position, kind and color from the marker globals. */ void updateTrackMarker(s32 markerId) {
    Obj *marker;
    if (!gTrackMarker) {
        gTrackMarker = spawnTrackMarker(markerId & 0xff);
        if (!gTrackMarker) return;
    }
    marker = gTrackMarker;
    marker->scale = 0x1000;
    marker->x = gTrackMarkerX;
    marker->y = gTrackMarkerY;
    marker->z = gTrackMarkerZ;
    marker->kind = 7;
    marker->color = gTrackMarkerColor;
}
