s32 angleDelta12(s32, s32);
s32 vec3Subtract(void *, void *, f32 *);
f32 approxHypot2D(f32, f32);
f32 approximateAtan2(f32, f32);
extern f64 gTrackMarkerEaseRate;

/* Aims a track marker actor at its track point: computes yaw and pitch from the offset, eases the marker's angles toward them and clamps the result. */
void aimTrackMarkerAngles(void *actor) {
    union {
        unsigned char bytes[32];
        struct { f32 value; } pitchAngle;
        struct { unsigned char pad[4]; f32 value; } yawAngle;
        struct { unsigned char pad[16]; f32 value; } offsetX;
        struct { unsigned char pad[20]; f32 value; } offsetY;
        struct { unsigned char pad[24]; f32 value; } offsetZ;
    } scratch;

    f32 sp28;
    f32 temp_fv0;
    f32 temp_fv0_2;
    f32 temp_fv0_3;
    f32 temp_fv1;
    f32 var_fv0;
    f32 var_fv1;
    void *trackData;

    trackData = (*(void **)((char *)(actor) + 0x6C));
    vec3Subtract(trackData, actor + 0x24, &scratch.offsetX.value);
    var_fv0 = approxHypot2D(scratch.offsetX.value, scratch.offsetZ.value);
    if (var_fv0 < 4.0f) {
        var_fv0 = 4.0f;
    }
    scratch.pitchAngle.value = -(approximateAtan2(scratch.offsetY.value, var_fv0) * 651.8986f);
    temp_fv0_2 = approximateAtan2(scratch.offsetX.value, scratch.offsetZ.value) * 651.8986f;
    scratch.yawAngle.value = temp_fv0_2;
    scratch.offsetX.value = (f32) angleDelta12((s32) scratch.pitchAngle.value, (s32) (*(f32 *)((char *)(trackData) + 0xC)));
    scratch.offsetY.value = (f32) angleDelta12((s32) scratch.yawAngle.value, (s32) (*(f32 *)((char *)(trackData) + 0x10)));
    if (scratch.offsetX.value < -56.88889f) {
        scratch.offsetX.value = -56.88889f;
    } else if (scratch.offsetX.value > 739.5556f) {
        scratch.offsetX.value = 739.5556f;
    }
    if (scratch.offsetY.value < -739.5556f) {
        scratch.offsetY.value = -739.5556f;
    } else if (scratch.offsetY.value > 739.5556f) {
        scratch.offsetY.value = 739.5556f;
    }
    temp_fv0_3 = (*(f32 *)((char *)(actor) + 0x3C));
    (*(f32 *)((char *)(actor) + 0x3C)) = (f32) ((f64) temp_fv0_3 + ((f64) (((*(f32 *)((char *)(trackData) + 0xC)) - scratch.offsetX.value) - temp_fv0_3) * gTrackMarkerEaseRate));
    temp_fv1 = (*(f32 *)((char *)(actor) + 0x40));
    (*(f32 *)((char *)(actor) + 0x40)) = (f32) ((f64) temp_fv1 + ((f64) (((*(f32 *)((char *)(trackData) + 0x10)) - scratch.offsetY.value) - temp_fv1) * gTrackMarkerEaseRate));
    (*(s32 *)((char *)(actor) + 0x44)) = 0;
}
