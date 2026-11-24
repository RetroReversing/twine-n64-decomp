extern f32 kRayNoHitDistance, kRayRangeMultiplier, gRayRangeScaleTable;
extern u8 gSlotMarkerActive;
extern s32 gGameMode;
extern void *gTrackMarkerParents[];
#define F(p,o) (*(f32 *)((char *)(p)+(o)))
#define P(p,o) (*(void **)((char *)(p)+(o)))
/* Eases the reticle's current position toward its target (or steers it by track marker offsets) each frame. */ void updateAimReticle(void *actor)
{
    void *reticle = P(actor, 0x6c);
    s32 playerSlot = *(s8 *)((char *)reticle+0x182);
    f32 targetLimit = F(&gRayRangeScaleTable, *(s8 *)((char *)P(actor,0x68)+0xe)*0xe8)*kRayRangeMultiplier;
    f32 curX;
    f32 curY;
    f32 dx;
    f32 dy;
    f32 targetX;
f32 __repair_phase_tx;
    f32 targetY;
    f32 rate;
    f32 fx;
f32 __repair_phase_fx;
    f32 fy;
f32 __repair_phase_fy;
    f32 fdx;
    f32 fdy;
f32 __repair_phase_fdy;
    void *trackMarker;
    if (gGameMode == 0x19)
        targetLimit = kRayNoHitDistance;
    if (*(&gSlotMarkerActive + playerSlot*0xa0)) {
        trackMarker = gTrackMarkerParents[playerSlot];
        if (F(trackMarker,0x11c) != targetLimit) {
            f32 __repair_clamped_float = F(trackMarker,0x110)/F(trackMarker,0x78);
            targetY = -F(trackMarker,0x114)/F(trackMarker,0x7c);
            if (__repair_clamped_float < -1.0f) __repair_clamped_float = -1.0f;
            else if (__repair_clamped_float > 1.0f) __repair_clamped_float = 1.0f;
            if (targetY < -1.0f) targetY = -1.0f;
            else if (targetY > 1.0f) targetY = 1.0f;
            rate = 0.5f;
            if (gGameMode == 0x19) rate = 1.01f;
            curX = F(reticle,0x24);
            dx = __repair_clamped_float-curX;
            curY = F(reticle,0x28);
            dx *= rate;
            goto steer;
        }
    }
    if (*(u16 *)((char *)P(actor,0x68)+0xc)&1) {
        f32 temp;
        targetX = F(reticle,0x1c);
        fx = F(reticle,0x24);
        temp = (targetX-fx)*0.5f;
        targetX = temp;
        fy = F(reticle,0x28);
        fdy = (F(reticle,0x20)-0.05f-fy)*0.5f;
        {
F(reticle,0x24) = fx + targetX;
F(reticle,0x28) = fy + fdy;
return;
}
    }
    if (gGameMode == 0x19) {
        __repair_phase_tx = F(reticle,0x1c);
        __repair_phase_fx = F(reticle,0x24);
        __repair_phase_tx -= __repair_phase_fx;
        __repair_phase_fdy = F(reticle,0x20);
        __repair_phase_fy = F(reticle,0x28);
        __repair_phase_tx *= 0.5f;
        __repair_phase_fdy -= __repair_phase_fy;
        __repair_phase_fdy *= 0.5f;

        F(reticle,0x24) = __repair_phase_fx + __repair_phase_tx;
        F(reticle,0x28) = __repair_phase_fy + __repair_phase_fdy;
        return;
    }
    curX = F(reticle,0x24);
    rate = 0.5f;
    curY = F(reticle,0x28);
    targetY = -0.05f;
    dx = -curX;
    dx *= rate;
steer:
    dy = (targetY-curY)*rate;
    curX += dx;
    curY += dy;
    F(reticle,0x24) = curX;
    F(reticle,0x28) = curY;
}
#undef F
#undef P

