typedef struct { u8 pad[0x24]; f32 pos[3]; u8 pad30[0xC]; s32 w3C; s32 w40; f32 f44; u8 pad48[0xC]; f32 f54; s32 flags; u8 pad5C[0x1C]; s16 h78; u8 pad7A[4]; s8 b7E; u8 pad7F[3]; u8 b82; } Obj;
typedef struct { u8 pad[0xF4]; s32 wF4; } Def;
Obj *spawnEffectObject(s32, s32, s32);
void objectListInsert(Obj *, s32);
void updateTrackMarkerEffect(Obj *);
void effectSetAnimFrame(Obj *, s32, s32);
void func_80064318(Obj *, u8);
extern Obj *volatile gTrackMarkerEffectObject;
extern s32 gTrackMarkerEffectTimer;
extern s16 gTrackMarkerEffectMode;
extern s16 gTrackMarkerEffectKind;
extern Def *sTrackMarkerTable[];

/* Spawns the singleton track-marker effect object for kind and mode, unless one already exists; returns it or NULL. */
Obj *spawnTrackMarkerEffect(u8 kind, u16 mode) {
    register Obj *effect;
    register f32 animScale;
    Obj *volatile *effectSlot;

    effectSlot = &gTrackMarkerEffectObject;
    if (*effectSlot != NULL) {
        return NULL;
    }
    *effectSlot = spawnEffectObject(0, 0, 0);
    gTrackMarkerEffectKind = (s32)kind;
    gTrackMarkerEffectTimer = 0;
    switch (mode) {
    default:
    case 0:
        animScale = 0.00078125f;
        break;
    case 1:
        animScale = 0.0171875f;
        break;
    }
    effectSlot = &gTrackMarkerEffectObject;
    effect = *effectSlot;
    if (effect != NULL) {
        effectSetAnimFrame(effect, 1, 0x2A);
        gTrackMarkerEffectObject->b7E = 1;
        *(volatile s16 *)&gTrackMarkerEffectObject->h78 = 0x56;
        *(volatile u8 *)&gTrackMarkerEffectObject->b82 = 0xFF;
        {
            Obj *object = gTrackMarkerEffectObject;
            *(volatile s32 *)&object->flags |= 0x1000;
        }
        *(volatile f32 *)&gTrackMarkerEffectObject->pos[0] = 0.015f;
        *(volatile f32 *)&gTrackMarkerEffectObject->pos[1] = 0.02f;
        *(volatile f32 *)&gTrackMarkerEffectObject->pos[2] = 0.1f;
        *(volatile s32 *)&gTrackMarkerEffectObject->w3C = 0;
        *(volatile s32 *)&gTrackMarkerEffectObject->w40 = 0;
        *(volatile f32 *)&gTrackMarkerEffectObject->f44 = 0.1f;
        gTrackMarkerEffectObject->f54 = animScale;
        func_80064318(*effectSlot, kind);
        objectListInsert(*effectSlot, sTrackMarkerTable[kind]->wF4);
        effect = *effectSlot;
    }
    gTrackMarkerEffectMode = mode;
    updateTrackMarkerEffect(effect);
    updateTrackMarkerEffect(*effectSlot);
    updateTrackMarkerEffect(*effectSlot);
    updateTrackMarkerEffect(*effectSlot);
    return *effectSlot;
}
