typedef struct { u8 pad[0x24]; f32 pos[3]; u8 pad30[0xC]; s32 w3C; s32 w40; f32 f44; u8 pad48[0xC]; f32 f54; s32 flags; u8 pad5C[0x1C]; s16 h78; u8 pad7A[4]; s8 b7E; u8 pad7F[3]; u8 b82; } Obj;
typedef struct { u8 pad[0xF4]; s32 wF4; } Def;
Obj *spawnEffectObject(s32, s32, s32);
void objectListInsert(Obj *, s32);
void func_8002B6BC(Obj *);
void objectSetAnimFrame(Obj *, s32, s32);
void func_80064318(Obj *, u8);
extern Obj *volatile gEffectObject;
extern s32 gEffectTimer;
extern s16 gEffectMode;
extern s16 gEffectKind;
extern Def *gTrackMarkerTable[];

/* Spawns the singleton track-marker effect object for kind and mode, unless one already exists; returns it or NULL. */
Obj *spawnTrackMarkerEffect(u8 kind, u16 mode) {
    register Obj *effect;
    register f32 animScale;
    Obj *volatile *effectSlot;

    effectSlot = &gEffectObject;
    if (*effectSlot != NULL) {
        return NULL;
    }
    *effectSlot = spawnEffectObject(0, 0, 0);
    gEffectKind = (s32)kind;
    gEffectTimer = 0;
    switch (mode) {
    default:
    case 0:
        animScale = 0.00078125f;
        break;
    case 1:
        animScale = 0.0171875f;
        break;
    }
    effectSlot = &gEffectObject;
    effect = *effectSlot;
    if (effect != NULL) {
        objectSetAnimFrame(effect, 1, 0x2A);
        gEffectObject->b7E = 1;
        *(volatile s16 *)&gEffectObject->h78 = 0x56;
        *(volatile u8 *)&gEffectObject->b82 = 0xFF;
        {
            Obj *object = gEffectObject;
            *(volatile s32 *)&object->flags |= 0x1000;
        }
        *(volatile f32 *)&gEffectObject->pos[0] = 0.015f;
        *(volatile f32 *)&gEffectObject->pos[1] = 0.02f;
        *(volatile f32 *)&gEffectObject->pos[2] = 0.1f;
        *(volatile s32 *)&gEffectObject->w3C = 0;
        *(volatile s32 *)&gEffectObject->w40 = 0;
        *(volatile f32 *)&gEffectObject->f44 = 0.1f;
        gEffectObject->f54 = animScale;
        func_80064318(*effectSlot, kind);
        objectListInsert(*effectSlot, gTrackMarkerTable[kind]->wF4);
        effect = *effectSlot;
    }
    gEffectMode = mode;
    func_8002B6BC(effect);
    func_8002B6BC(*effectSlot);
    func_8002B6BC(*effectSlot);
    func_8002B6BC(*effectSlot);
    return *effectSlot;
}
