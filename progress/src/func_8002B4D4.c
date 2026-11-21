typedef struct { u8 pad[0x24]; f32 f24; f32 f28; f32 f2C; u8 pad30[0xC]; s32 w3C; s32 w40; f32 f44; u8 pad48[0xC]; f32 f54; s32 flags; u8 pad5C[0x1C]; s16 h78; u8 pad7A[4]; s8 b7E; u8 pad7F[3]; u8 b82; } Obj;
typedef struct { u8 pad[0xF4]; s32 wF4; } Def;
Obj *spawnEffectObject(s32, s32, s32);
void objectListInsert(Obj *, s32);
void func_8002B6BC(Obj *);
void objectSetAnimFrame(Obj *, s32, s32);
void func_80064318(Obj *, u8);
extern Obj *volatile D_800BF5BC;
extern s32 D_800BF5C4;
extern s16 D_800BF5C8;
extern s16 D_800BF5CA;
extern Def *gTrackMarkerTable[];

Obj *func_8002B4D4(u8 kind, u16 mode) {
    register Obj *o;
    register f32 scale;
    Obj *volatile *p;

    p = &D_800BF5BC;
    if (*p != NULL) {
        return NULL;
    }
    *p = spawnEffectObject(0, 0, 0);
    D_800BF5CA = (s32)kind;
    D_800BF5C4 = 0;
    switch (mode) {
    default:
    case 0:
        scale = 0.00078125f;
        break;
    case 1:
        scale = 0.0171875f;
        break;
    }
    p = &D_800BF5BC;
    o = *p;
    if (o != NULL) {
        objectSetAnimFrame(o, 1, 0x2A);
        D_800BF5BC->b7E = 1;
        *(volatile s16 *)&D_800BF5BC->h78 = 0x56;
        *(volatile u8 *)&D_800BF5BC->b82 = 0xFF;
        {
            Obj *object = D_800BF5BC;
            *(volatile s32 *)&object->flags |= 0x1000;
        }
        *(volatile f32 *)&D_800BF5BC->f24 = 0.015f;
        *(volatile f32 *)&D_800BF5BC->f28 = 0.02f;
        *(volatile f32 *)&D_800BF5BC->f2C = 0.1f;
        *(volatile s32 *)&D_800BF5BC->w3C = 0;
        *(volatile s32 *)&D_800BF5BC->w40 = 0;
        *(volatile f32 *)&D_800BF5BC->f44 = 0.1f;
        D_800BF5BC->f54 = scale;
        func_80064318(*p, kind);
        objectListInsert(*p, gTrackMarkerTable[kind]->wF4);
        o = *p;
    }
    D_800BF5C8 = mode;
    func_8002B6BC(o);
    func_8002B6BC(*p);
    func_8002B6BC(*p);
    func_8002B6BC(*p);
    return *p;
}

