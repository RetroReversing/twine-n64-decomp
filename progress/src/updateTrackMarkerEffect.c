typedef struct { u8 pad0[0x54]; f32 f54; s32 flags; } Obj2B6BC;
typedef struct { u8 pad0[0xF4]; void *fF4; } Def2B6BC;
extern Obj2B6BC * volatile gTrackMarkerEffectObject;
extern f32 gTrackMarkerEffectTimer;
extern u16 gTrackMarkerEffectMode;
extern u16 gTrackMarkerEffectKind;
extern char D_800BF5CC[];
extern Def2B6BC *gTrackMarkers[];
s32 *func_8002B400(f32, s32, char *);
void actorUnlinkFromSurface(void *);
void objectListInsert(void *, void *);
void func_8002B7F8(void);

void updateTrackMarkerEffect(s32 arg0) {
    Obj2B6BC * volatile *pp;
    f32 *v;
    f32 progress;
    

    if (arg0 != 0) {
        pp = &gTrackMarkerEffectObject;
        if (*pp == NULL) {
            return;
        }
        v = (f32 *)func_8002B400(gTrackMarkerEffectTimer, 0xE, D_800BF5CC);
        actorUnlinkFromSurface(*pp);
        objectListInsert(*pp, gTrackMarkers[gTrackMarkerEffectKind]->fF4);
        gTrackMarkerEffectObject->flags |= 0x1000;
        do { gTrackMarkerEffectObject->f54 = *v; } while (0);
        switch (gTrackMarkerEffectMode) {
        case 0:
            gTrackMarkerEffectTimer = gTrackMarkerEffectTimer + 0.02f;
            if (!(1.0f < gTrackMarkerEffectTimer))
                return;
            break;
        case 1:
            gTrackMarkerEffectTimer = gTrackMarkerEffectTimer - 0.02f;
            if (!(gTrackMarkerEffectTimer < 0.0f))
                return;
            break;
        default:
            return;
        }
    }
    func_8002B7F8();
}
