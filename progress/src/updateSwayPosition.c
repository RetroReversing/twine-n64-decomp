extern f64 D_800D4480;
extern f64 D_800D4488;
extern f64 D_800D4490;
extern char gTrackMarkerParents[];

/* Writes the sway's output position (fields 0x3C..0x44 of its output block) from the current track marker. */
void updateSwayPosition(void * obj, f32 * arg1) {
    f32 offset[3];
    register void *sway;
    void **markerSlot;
    register void *marker;

    sway = (*(void **)((char *)(obj) + 0x6C));
    markerSlot = ((*(s8 *)((char *)(sway) + 0x182)) * 4) + gTrackMarkerParents;
    offset[0] = (*(f32 *)((char *)(*markerSlot) + 0x34));
    offset[1] = (*(f32 *)((char *)(*markerSlot) + 0x38));
    offset[2] = 0;
    (*(f32 *)((char *)((*(void **)((char *)(sway) + 0xA8))) + 0x3C)) = (f32) ((f64) ((*(f32 *)((char *)(sway) + 0x74)) * 651.8986f) + ((((f64) (*(f32 *)((char *)(sway) + 0x28)) * D_800D4480) / (f64) (*(f32 *)((char *)(*markerSlot) + 0x4C))) * D_800D4488));
    marker = *markerSlot;
    (*(f32 *)((char *)((*(void **)((char *)(sway) + 0xA8))) + 0x40)) = (f32) (D_800D4490 - ((f64) (*(f32 *)((char *)(marker) + 0x80)) * D_800D4488 * (((f64) (*(f32 *)((char *)(sway) + 0x24)) * D_800D4480) / (f64) (*(f32 *)((char *)(marker) + 0x4C)))));
    (*(f32 *)((char *)((*(void **)((char *)(sway) + 0xA8))) + 0x44)) = -2048.0f;
}
