typedef struct TrackMarkerAnimState {
    u32 packed;       /* 0x00: animation bank in the top bits, frame data below */
    u8 doneIndex;     /* 0x04 index into gTrackMarkerDone, 0 = no dependency */
    u8 doneState;     /* 0x05 state gTrackMarkerDone must hold */
    u8 frame;         /* 0x06 current animation frame */
    u8 frameLimit;    /* 0x07 frame wraps to 0 after this */
    s8 farMode;       /* 0x08 nonzero: larger impact radius and sparkle burst */
} TrackMarkerAnimState;

void applyNearbyActorImpact(void *actor, f32 radius, f32 impulse);
void effectSetAnimFrame(void *actor, s32 frame, s32 bank);
s32 randomIntBelow(s32 limit);
void spawnTrackMarkerBurst(void *actor);
extern u8 gTrackMarkerDone[];

/* Per-frame update of a track marker: waits for its dependency, pushes nearby actors,
   advances the animation frame and occasionally spawns a sparkle burst. */
void updateTrackMarkerAnim(TrackMarker *marker) {
    TrackMarkerAnimState *anim;
    f32 impulse;
    u8 nextFrame;

    anim = (TrackMarkerAnimState *)marker->trigger;
    if ((anim->doneIndex != 0) && (gTrackMarkerDone[anim->doneIndex] != anim->doneState)) {
        goto waitForDependency;
    }
animate:
    impulse = 10.0f;
    if (anim->farMode != 0) {
        impulse = 200.0f;
    }
    applyNearbyActorImpact(marker, 2.0f, impulse);
    nextFrame = anim->frame + 1;
    anim->frame = nextFrame;
    if (anim->frameLimit < (u32)(nextFrame & 0xFF)) {
        anim->frame = 0;
    }
    effectSetAnimFrame(marker, anim->frame, anim->packed >> 0x14);
    *(s8 *)((u8 *)marker + 0x7E) = 5;
    if ((marker->flags & 0x7000) && (anim->farMode != 0) && (randomIntBelow(0x1E) == 0)) {
        spawnTrackMarkerBurst(marker);
        marker->flags = 0;
        return;
    }
    goto clearFlags;
waitForDependency:
    *(void **)((u8 *)marker + 0x70) = NULL;
clearFlags:
    marker->flags = 0;
}
