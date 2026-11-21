typedef struct { u8 pad0[0x54]; f32 f54; s32 flags; } Obj2B6BC;
typedef struct { u8 pad0[0xF4]; void *fF4; } Def2B6BC;
extern Obj2B6BC * volatile gEffectObject;
extern f32 gEffectTimer;
extern u16 gEffectMode;
extern u16 gEffectKind;
extern char D_800BF5CC[];
extern Def2B6BC *gTrackMarkerTable[];
s32 *func_8002B400(f32, s32, char *);
void actorUnlinkFromSurface(void *);
void objectListInsert(void *, void *);
void func_8002B7F8(void);

void func_8002B6BC(s32 arg0) {
    Obj2B6BC * volatile *pp;
    f32 *v;
    f32 progress;
    

    if (arg0 != 0) {
        pp = &gEffectObject;
        if (*pp == NULL) {
            return;
        }
        v = (f32 *)func_8002B400(gEffectTimer, 0xE, D_800BF5CC);
        actorUnlinkFromSurface(*pp);
        objectListInsert(*pp, gTrackMarkerTable[gEffectKind]->fF4);
        gEffectObject->flags |= 0x1000;
        do { gEffectObject->f54 = *v; } while (0);
        switch (gEffectMode) {
        case 0:
            gEffectTimer = gEffectTimer + 0.02f;
            if (!(1.0f < gEffectTimer))
                return;
            break;
        case 1:
            gEffectTimer = gEffectTimer - 0.02f;
            if (!(gEffectTimer < 0.0f))
                return;
            break;
        default:
            return;
        }
    }
    func_8002B7F8();
}
