void *func_80047B44(s32, void *, f32 *, s32);
s32 func_8004AD30(s32, f32 *, s32 *, f32, s32, s32, s32, s32);
f32 sinTableLookup(f32);
f32 sinAngle(f32);
f32 cosAngle(f32);
f32 approximateAtan2(f32, f32);
extern u8 D_8011508C;

struct Vec3 { f32 x; f32 y; f32 z; };

/* Probes the track surface ahead of the actor; returns a steering angle (0 when no surface is hit). */
f32 probeTrackSteerAngle(s32 scene, void *actor) {
    struct Vec3 probePos;
    struct Vec3 steerPos;
    struct { s32 i; f32 f; s32 reserved[2]; } hit;
    void *trackState;
    s32 unusedActor;
    void *hitActor;
    f32 unusedF;
    f32 steerAngle;
    s32 hitFound;

    trackState = *(void **)((char *)actor + 0x6C);
    steerAngle = 0.0f;
    if (*((u8 *)((s8 *)&D_8011508C + (*(s8 *)((char *)trackState + 0x182)) * 0xA0)) != 0) {
        probePos = *(struct Vec3 *)((char *)actor + 0x24);
        probePos.x = probePos.x + sinAngle(*(f32 *)((char *)actor + 0x40)) * 1.5f;
        probePos.y += 0.5f;
        probePos.z += cosAngle(*(f32 *)((char *)actor + 0x40)) * 1.5f;
        hitActor = func_80047B44(scene, (char *)actor + 0x24, &probePos.x, 0);
        if (hitActor != NULL) {
            scene = *(s32 *)((char *)hitActor + 8);
        }
        hitFound = func_8004AD30(scene, &probePos.x, &hit.i, 4.0f, 0, 0, 0, 0xE);
        if ((hitFound << 24) != 0) {
            steerAngle = approximateAtan2(hit.f - *(f32 *)((char *)trackState + 0xE4), 1.5f);
            steerPos = probePos;
            steerPos.x += sinAngle(*(f32 *)((char *)actor + 0x40));
            steerPos.y += sinTableLookup(steerAngle);
            steerPos.z += cosAngle(*(f32 *)((char *)actor + 0x40));
            steerAngle *= 0.47746482f;
        }
    }
    return steerAngle;
}
