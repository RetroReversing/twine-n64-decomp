typedef struct { u8 id; u8 next; u8 pad[2]; u8 spl[4]; f32 t; f32 dt; s16 len; s16 pos; } Cursor;
typedef struct { u8 pad[0x58]; s32 f58; u8 p2[4]; s32 f60; u8 p3[8]; Cursor *cur; u8 p4[0xA]; s16 stage; } Obj;
extern void actorInitFromSpawn(void *, void *, void *);
extern void setRotationInterpolationMode(s32);
extern void resetSceneObjectState(void *);
extern void copyActorTransformToEffect(void *, void *);
extern void registerTrackMarkerParent(s32, s32);
extern s32 isBonusMarkerSelectable(void *);
extern void freeHeapBlock(void *, s32, u8 *);
extern void updateSplinePosition(void *, void *);
extern void setViewportRect(void *, f32, f32, f32, f32, f32, f32);
extern u8 gTrackMarkerGroup[];
extern u8 gTrackMarkerDone[];
extern s8 gBonusSequenceReady;
extern u8 *gSceneState;
extern void *sBonusObjectTable;
extern s32 gDefaultOrderObj;
extern u8 gSceneFlagsB;
extern u8 gTrackMarkerActiveMask;
extern u32 gTrackMarkerCount;
extern f32 gTrackMarkerPosTable[][3];
extern f32 gTrackMarkerRotTable[][3];
/* Stage machine for the bonus track-marker sequence: spawn the bonus object, run the spline cutscene, then clean up. */ void updateBonusMarkerSequence(Obj *obj)
{
    Cursor *cur = obj->cur;
    void *bonusObj;
    void *overlayRef;
    void *overlayRef2;
    void *pos;
    void *rot;
    u32 i;
    u8 *maskPtr;
    u8 a;
    u8 b;
    u8 *maskPtr1;
    u8 a1;
    u8 b1;

    switch (obj->stage) {
    case 0:
        if (!gTrackMarkerDone[cur->id]) {
            break;
        }
        if (gBonusSequenceReady == 0) {
            obj->f60 |= 1;
            break;
        }
        bonusObj = sBonusObjectTable;
        gBonusSequenceReady = 0;
        if (!isBonusMarkerSelectable(bonusObj)) {
            break;
        }
        pos = (u8 *)bonusObj + 0x24;
        rot = (u8 *)bonusObj + 0x3C;
        for (i = 0; i < gTrackMarkerCount; i++) {
            if (gTrackMarkerGroup[i] == cur->id) {
                pos = gTrackMarkerPosTable[i];
                rot = gTrackMarkerRotTable[i];
                break;
            }
        }
        actorInitFromSpawn(bonusObj, pos, rot);
        setRotationInterpolationMode(1);
        obj->stage = 1;
        break;
    case 1:
        registerTrackMarkerParent(2, gDefaultOrderObj);
        overlayRef = &gSceneState;
        resetSceneObjectState(*(u8 **)overlayRef);
        setViewportRect(*(u8 **)overlayRef, 160.0f, 120.0f, 320.0f, 180.0f, 0.0f, 0.0f);
        copyActorTransformToEffect(obj, *(u8 **)overlayRef);
        *(s32 *)(gSceneState + 0x100) |= 0x10;
        maskPtr1 = &gTrackMarkerActiveMask;
        b1 = gSceneFlagsB;
        a1 = (*maskPtr1 | 4) & ~1;
        b1 &= ~1;
        *maskPtr1 = a1;
        gSceneFlagsB = b1;
        *(s16 *)((u8 *)cur + 0x12) = -1;
        *(f32 *)((u8 *)cur + 8) = 0.01f;
        copyActorTransformToEffect(obj, *(u8 **)overlayRef);
        obj->stage = 2;
        break;
    case 2:
        obj->f58 |= 1;
        cur->t += cur->dt;
        updateSplinePosition(obj, cur->spl);
        copyActorTransformToEffect(obj, gSceneState);
        if (!gTrackMarkerDone[cur->id] || cur->pos >= cur->len - 4) {
            obj->stage = 3;
        }
        break;
    case 3:
        overlayRef2 = &gSceneState;
        gTrackMarkerDone[cur->next] = 1;
        maskPtr = &gTrackMarkerActiveMask;
        *maskPtr |= 1;
        gSceneFlagsB |= 1;
        freeHeapBlock(*(u8 **)overlayRef2, 14, maskPtr);
        *(u8 **)overlayRef2 = 0;
        setRotationInterpolationMode(0);
        gBonusSequenceReady = 1;
        obj->f60 |= 1;
        break;
    }
}
