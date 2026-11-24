s32 angleDelta12(s32, s16);
f32 approxDistance(void *);
f32 approxHypot2D(f32, f32);
f32 absFloat(f32);
f32 approximateAtan2(f32, f32);
extern s32 gBorderSkipActive;

/* Returns 1 if the target is inside the actor's detection range and yaw window, writing its yaw (4096 units per turn) to *yawOut. */
s32 actorTargetInAngleRange(void *actor, void *targetPos, s32 *yawOut, f32 maxDist) {
    f32 deltaX, deltaY, deltaZ, horizDist;
    s32 angle;

    if (maxDist < approxDistance((s8 *)actor + 0x24)) {
        return 0;
    }
    do {
        deltaX = *(f32 *)((s8 *)targetPos) - *(f32 *)((s8 *)actor + 0x24);
    } while (0);
    {
        deltaZ = *(f32 *)((s8 *)targetPos + 8) - *(f32 *)((s8 *)actor + 0x2c);
    }
    {
        deltaY = *(f32 *)((s8 *)targetPos + 4) - *(f32 *)((s8 *)actor + 0x28);
    }
    horizDist = approxHypot2D(deltaX, deltaZ);
    if (gBorderSkipActive == 0) {
        angle = (s32)(approximateAtan2(deltaY, horizDist) * 651.8986f);
        if (absFloat((f32)angle) > 512.0f) {
            return 0;
        }
    }
    angle = (s32)(approximateAtan2(deltaX, deltaZ) * 651.8986f);
    *yawOut = angle;
    angle = angleDelta12(angle, *(s16 *)((s8 *)*(void **)((s8 *)actor + 0x68) + 0x8c));
    /* deltaX is dead here; the compiler reuses its register for the yaw window limit. */
    deltaX = gBorderSkipActive != 0 ? 682.0f : 910.0f;
    if (deltaX < absFloat((f32)angle)) {
        return 0;
    }
    return 1;
}
