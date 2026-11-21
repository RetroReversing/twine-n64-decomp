typedef struct {
    u8 pad0[0x14];
    u16 sfxId;
    u8 pad16[6];
    f32 splineCursor[1];
    f32 playPos;
    u8 pad24[4];
    s16 pathLength;
    s16 pathIndex;
    f32 playSpeed;
    u8 triggerFlagIndex;
    u8 triggerType;
    u8 loopMode;
    u8 releaseOnEnd;
} TrackState;

typedef struct {
    u8 pad0[0x20];
    s32 listHead;
    u8 pos24[0x34];
    s32 flags58;
    u8 pad5C[4];
    s32 flags60;
    u8 pad64[8];
    TrackState *track;
    u8 *model;
    u8 pad74[6];
    s16 state;
} TrackObject;

s32 getTrackTriggerMask(s32);
s32 markObjectsNearPos(s32, s32, s32, void *, f32, s32);
s32 updateSplinePosition(void *, void *);
s32 releaseTrackRecord(void *);
s32 updateActorTrackingState(void *, void *);
extern u8 gTrackDoneFlags[];

/* Runs a track object's state machine: waits for its trigger, plays the spline path while marking nearby objects, then releases the track record. */
void updateTrackObject(TrackObject *obj) {
    s16 state = obj->state;
    TrackState *track = obj->track;
    s32 v;
    s32 one = 1;

    switch (state) {
    case 0:
        v = track->triggerFlagIndex;
        if (v != 0) {
            v = gTrackDoneFlags[v];
        } else {
            if (obj->flags60 & getTrackTriggerMask(track->triggerType)) {
                obj->state = 1;
            }
            v = track->loopMode;
        }
        if (v == one) {
            obj->state = 1;
        }
        break;
    case 1:
        if (track->sfxId != 0) {
            updateActorTrackingState(obj, track);
        }
        track->playPos += track->playSpeed;
        updateSplinePosition(obj, track->splineCursor);
        markObjectsNearPos(obj->listHead, 0, 0x01000000, obj->pos24, *(f32 *)(obj->model + 0x14) + 1.0f, state);
        if (track->pathIndex == track->pathLength - 4) {
            if (track->loopMode == state) {
                track->pathIndex = 0;
            } else {
                obj->state = 3;
            }
        }
        obj->flags58 |= 1;
        break;
    case 3:
        if (track->releaseOnEnd != 0) {
            if (track->sfxId != 0) {
                releaseTrackRecord(track);
            }
            obj->flags60 |= 1;
        }
        break;
    }
}
