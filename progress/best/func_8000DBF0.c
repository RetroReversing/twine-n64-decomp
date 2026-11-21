typedef struct { f32 x, y, z; } Vec3;
typedef union { u32 u; s32 i; f32 f; u16 *p; u8 b[4]; } Cmd;

typedef struct { u8 pad0[0x47]; u8 unk47; } ObjDef3C;
typedef struct { u8 pad0[0x3C]; ObjDef3C *unk3C; } ObjDef;
typedef struct { u8 pad0[0x48]; u8 unk48; } ObjInfo;
typedef struct {
    u8 pad0[0x50];
    Vec3 unk50;
    u8 pad5C[4];
    s32 unk60[3];
    u8 pad6C[0x1C];
    u32 unk88_0 : 11;
    u32 unk88_11 : 4;
    u32 unk88_15 : 17;
} ObjExtra;
typedef struct {
    u8 pad0[0xC];
    u16 unkC;
    u8 padE[3];
    u8 unk11;
    u8 pad12[2];
    u32 unk14_0 : 15;
    u32 unk14_15 : 1;
    u32 unk14_16 : 12;
    u32 unk14_28 : 2;
    u32 unk14_30 : 2;
    u8 pad18[0x18];
    f32 unk30;
    f32 unk34;
    u8 pad38[0x38];
    s32 unk70;
    u8 pad74[0x24];
    s16 unk98;
    s16 unk9A;
    u8 pad9C[0x15];
    u8 unkB1;
} ObjModel;
typedef struct Obj {
    u8 pad0[0x20];
    ObjDef *unk20;
    Vec3 pos;
    Vec3 unk30;
    Vec3 rot;
    u8 pad48[0xC];
    f32 scale;
    s32 flags;
    u8 pad5C[4];
    s32 unk60;
    u8 pad64[4];
    ObjModel *model;
    ObjExtra *extra;
    ObjInfo *info;
    u8 pad74[4];
    s16 unk78;
    s16 unk7A;
    u8 pad7C[2];
    u8 unk7E;
    u8 unk7F;
    u8 unk80;
    u8 unk81;
    u8 unk82;
} Obj;

typedef struct {
    s32 unk0;
    f32 unk4;
    f32 unk8;
    f32 unkC;
    f32 unk10;
    u16 unk14;
    u32 unk16 : 8;
    u32 unk17 : 8;
    u32 unk18 : 8;
    u32 unk19 : 8;
    u32 unk1A : 8;
} TrackSound;

typedef struct {
    Vec3 pos;
    Vec3 from;
    Vec3 to;
    f32 mode;
    u8 pad28[8];
    u8 unk30[0xC];
    Vec3 rotFrom;
    Vec3 rotTo;
    Obj *obj;
    f32 scaleFrom;
    f32 scaleTo;
    f32 alphaFrom;
    f32 alphaTo;
    s32 sound;
    s16 moveT;
    s16 moveLen;
    s16 rotT;
    s16 rotLen;
    s16 scaleT;
    s16 scaleLen;
    s16 alphaT;
    s16 alphaLen;
    s16 animFrame;
    s16 animEnd;
    s16 animMode;
    u8 pad82[2];
    u8 attach;
    u8 lookAt;
    u8 unk86;
    u8 unk87;
    u8 pad88[0x30];
    TrackSound snd;
} Track;

typedef struct {
    Cmd *pc;
    s32 unk4;
    s32 frame;
    s32 count;
    s16 unk10;
    s16 status;
    Track tracks[56];
} Cine;

typedef struct {
    u8 pad0[0x10];
    Vec3 unk10;
    u8 pad1C[0x18];
    f32 unk34;
    f32 unk38;
    f32 unk3C;
    u8 pad40[0xB4];
    s32 unkF4;
} Camera;

typedef struct { void *unk0; } ProbeList;

extern Cine *D_800B2710;
extern u8 D_800B1FE0[];
extern u8 D_800B2230[];
extern ProbeList *D_800CA31C;
extern s8 D_800E0742;
extern u8 D_800E0744;
extern u8 D_800E0746;
extern s8 D_800E0747;
extern Obj *D_800E0748;
extern Obj *D_800E074C;
extern u8 D_800E0758;
extern u8 D_80102EE8;
extern Camera *D_80109690[2];
extern s16 D_80109A58;
extern u8 D_80109A60[];
extern void *D_8010A500[4];

Obj *func_80016410(s32, Vec3 *, s32);
void func_80044670(Obj *, s32, s32);
void func_8000D6A0(s32);
void func_8003E6EC(void *, Obj *, s32);
void func_801181EC(Obj *);
void func_8000DA3C(Obj *);
void func_8000D3AC(s32, s32);
void func_8000D59C(s32, s32);
void func_8000CC1C(Obj *, s32);
void func_8000237C(Obj *, s32, s32, s32);
void func_800015AC(Obj *, s32);
f32 func_8000550C(Obj *, s32, s32);
void func_80074BC4(s32, s32);
s32 func_8000A830(s32, s32, s32);
void func_8000A270(s32);
void func_80085E30(TrackSound *);
void func_80074B5C(s32, s32);
void func_8000A5D0(s32);
void func_8000A29C(void);
void func_80084338(s32, Vec3 *);
void func_80073508(Vec3 *, f32);
void func_800656C0(void *, Vec3 *, Vec3 *);
Obj *func_8000CCE4(s32, s32, s32, s32);
s32 func_8000C860(s32);
void func_80002E80(Obj *);
void func_8000DBBC(s32);
void func_80045130(s32);
void func_80031700(s32);
void func_8007089C(void *, s32, s32);
void func_8005C508(Obj *, Vec3 *);
s32 func_8004478C(s32, s32);
f32 func_80045590(Vec3 *, Vec3 *);
void func_8000628C(Obj *, Vec3 *, s32, s32);
void func_80046EB8(f32 *, Vec3 *, Vec3 *, void *, f32, Vec3 *);
void func_800617D8(ObjDef *, Vec3 *, Vec3 *, s32, f32, f32, s32, s32, s32, s32, s32);
void func_80085E78(Obj *, TrackSound *);
void func_800464B8(Vec3 *, f32, f32, f32);
void func_8004830C(Camera *);
void func_8002B4D4(s32, s32);
void func_80048734(f32);
void func_8000CC38(s32);
void func_8011842C(Obj *);
void func_8000DAF4(void);

#define G D_800B2710
#define READF() (G->pc++->f)
#define READVEC(v) v.x = READF(); v.y = READF(); v.z = -READF()
#define ANG 11.377778f
#define LIN 999.0f
#define LERP(a, b, f) (((b) - (a)) * (f) + (a))
#define ALERP(a, b, f) (ia = (s32)(a), ib = (s32)(b), (f32)ia + (f32)(((ib - ia) << 20) >> 20) * (f))

s32 func_8000DBF0(s32 arg0) {
    Vec3 v;
    Vec3 v2;
    Vec3 v3;
    Vec3 v4;
    Vec3 unused[2];
    Obj *obj;
    u32 idx;
    u32 i;
    u32 attach;
    u32 model;
    u32 type;
    u32 type2;
    s32 special;
    s32 running;
    u32 opcode;
    u32 arg;
    u8 *bytes_1C;
    u8 *bytes_D;
    u32 len_10;
    u32 len_11;
    u32 par;
    u32 len_1B;
    u32 len_D;
    u32 len_E;
    u32 p2_1C;
    u32 p2_E;
    u32 tr_1C;
    f32 f;
    s32 ia, ib;

    if (G->count > 0) {
        G->count--;
    } else {
        running = 1;
        do {
            opcode = G->pc++->u;
            arg = opcode >> 8;
            switch (opcode & 0x3F) {
            case 0x22:
                running = 0;
                G->count = arg - 1;
                break;
            case 0x23:
                running = 0;
                G->status = 0;
                break;
            case 0x9:
                v.x = READF();
                v.y = 0.0f;
                v.z = 0.0f;
                G->tracks[55].from = v;
                G->tracks[55].to = v;
                break;
            case 0xA:
                G->tracks[55].moveT = 0;
                G->tracks[55].moveLen = arg;
                v.x = READF();
                v.y = 0.0f;
                v.z = 0.0f;
                G->tracks[55].to = v;
                break;
            case 0x1:
                READVEC(v);
                G->tracks[53].from = v;
                G->tracks[53].to = v;
                break;
            case 0x2:
                G->tracks[53].moveT = 0;
                G->tracks[53].moveLen = arg;
                READVEC(v);
                G->tracks[53].from = G->tracks[53].to;
                G->tracks[53].to = v;
                G->tracks[53].mode = LIN;
                break;
            case 0x5:
                READVEC(v);
                G->tracks[54].from = v;
                G->tracks[54].to = v;
                break;
            case 0x6:
                G->tracks[54].moveT = 0;
                G->tracks[54].moveLen = arg;
                READVEC(v);
                G->tracks[54].from = G->tracks[54].to;
                G->tracks[54].to = v;
                G->tracks[54].mode = LIN;
                break;
            case 0x3:
                func_8000D3AC(0x35, arg);
                break;
            case 0x4:
                func_8000D59C(0x35, arg);
                break;
            case 0x7:
                func_8000D3AC(0x36, arg);
                break;
            case 0x8:
                func_8000D59C(0x36, arg);
                break;
            case 0x0:
                G->pc++;
                break;
            case 0x12:
            case 0x13:
                attach = arg >> 18;
                model = (arg >> 8) & 0x3FF;
                idx = arg & 0xFF;
                if (attach == 0x3F) {
                    attach = 0xFF;
                }
                type = *G->pc++->p;
                READVEC(v);
                v2 = v;
                READVEC(v);
                obj = G->tracks[idx].obj;
                if (obj == NULL) {
                    special = (model == 0 && type == 0x160);
                    obj = func_80016410(special ? 0x50 : 0, &v2, 0);
                    if (obj != NULL) {
                        G->tracks[idx].obj = obj;
                        obj->unk7A = 0;
                        obj->unk78 = 0x1F;
                        obj->rot.x = v.x * ANG;
                        obj->rot.y = v.y * ANG;
                        obj->rot.z = v.z * ANG;
                        func_80044670(obj, model, type);
                        if (obj->info->unk48 & 0x10) {
                            obj->scale = 0.015625f;
                        }
                        G->tracks[idx].scaleFrom = G->tracks[idx].scaleTo = obj->scale;
                        G->tracks[idx].attach = attach;
                        G->tracks[idx].from = obj->pos;
                        func_8000D6A0(idx);
                        func_8003E6EC(D_800CA31C->unk0, obj, 0);
                        if (special) {
                            D_800E0748 = obj;
                            func_801181EC(obj);
                        }
                        if (model == 1 && type == 0x167) {
                            D_800E074C = obj;
                            func_8000DA3C(obj);
                        }
                        if (model == 3 && type == 0x167) {
                            D_800E074C = obj;
                            func_8000DA3C(obj);
                        }
                        G->tracks[idx].pos = G->tracks[idx].to = G->tracks[idx].from;
                        G->tracks[idx].rotFrom = G->tracks[idx].rotTo = obj->rot;
                    }
                } else {
                    obj->pos = obj->unk30 = v2;
                    obj->rot.x = v.x * ANG;
                    obj->rot.y = v.y * ANG;
                    obj->rot.z = v.z * ANG;
                    func_80044670(obj, model, type);
                    if (obj->info->unk48 & 0x10) {
                        obj->scale = 0.015625f;
                    }
                    G->tracks[idx].attach = attach;
                    if (attach == 0xFF) {
                        G->tracks[idx].to = obj->pos;
                    }
                    G->tracks[idx].pos = G->tracks[idx].from = G->tracks[idx].to;
                    G->tracks[idx].rotFrom = G->tracks[idx].rotTo = obj->rot;
                }
                obj->flags = (obj->flags | 1) & ~0x40000;
                break;
            case 0x14:
                idx = arg & 0xFF;
                G->tracks[idx].moveT = 0;
                G->tracks[idx].moveLen = arg >> 8;
                obj = G->tracks[idx].obj;
                READVEC(v);
                obj->pos = G->tracks[idx].to;
                G->tracks[idx].from = obj->pos;
                G->tracks[idx].to = v;
                G->tracks[idx].pos = G->tracks[idx].from;
                G->tracks[idx].mode = LIN;
                break;
            case 0x18:
                func_8000D3AC(arg & 0xFF, arg);
                break;
            case 0x19:
                func_8000D59C(arg & 0xFF, arg);
                break;
            case 0x15:
                idx = arg & 0xFF;
                G->tracks[idx].rotT = 0;
                G->tracks[idx].rotLen = arg >> 8;
                obj = G->tracks[idx].obj;
                READVEC(v);
                obj->rot = G->tracks[idx].rotTo;
                G->tracks[idx].rotFrom = obj->rot;
                G->tracks[idx].rotTo.x = v.x * ANG;
                G->tracks[idx].rotTo.y = v.y * ANG;
                G->tracks[idx].rotTo.z = v.z * ANG;
                break;
            case 0x16:
                idx = arg & 0xFF;
                par = arg >> 8;
                obj = G->tracks[idx].obj;
                if (par == 0) {
                    obj->scale = G->tracks[idx].scaleTo = READF();
                } else {
                    G->tracks[idx].scaleT = 0;
                    G->tracks[idx].scaleLen = par;
                    G->tracks[idx].scaleFrom = obj->scale = G->tracks[idx].scaleTo;
                    G->tracks[idx].scaleTo = READF();
                }
                break;
            case 0x17:
                idx = arg & 0xFF;
                obj = G->tracks[idx].obj;
                par = arg >> 8;
                opcode = G->pc++->u;
                if (par == 0) {
                    obj->unk80 = opcode >> 8;
                    obj->unk7F = opcode;
                    obj->unk81 = opcode >> 16;
                    G->tracks[idx].alphaTo = opcode >> 24;
                    obj->unk82 = G->tracks[idx].alphaTo;
                } else {
                    G->tracks[idx].alphaT = 0;
                    G->tracks[idx].alphaLen = par;
                    obj->unk80 = opcode >> 8;
                    obj->unk7F = opcode;
                    obj->unk81 = opcode >> 16;
                    obj->unk82 = G->tracks[idx].alphaTo;
                    G->tracks[idx].alphaFrom = obj->unk82;
                    G->tracks[idx].alphaTo = opcode >> 24;
                }
                break;
            case 0xB:
            case 0xC:
            case 0xD:
                bytes_D = (u8 *)G->pc++;
                attach = bytes_D[2];
                model = bytes_D[3];
                READVEC(v);
                v2 = v;
                v.x = READF();
                v.y = READF();
                v.z = READF();
                v.y += 180.0f;
                idx = arg & 0xFF;
                obj = G->tracks[idx].obj;
                type2 = arg >> 8;
                len_D = opcode & 0x80;
                if (obj == NULL) {
                    obj = func_80016410(0, &v2, 0);
                    if (obj != NULL) {
                        G->tracks[idx].obj = obj;
                        obj->unk7A = 0;
                        obj->unk78 = 0x46;
                        obj->rot.x = v.x * ANG;
                        obj->rot.y = v.y * ANG;
                        obj->rot.z = v.z * ANG;
                        G->tracks[idx].attach = attach;
                        G->tracks[idx].from = G->tracks[idx].to = G->tracks[idx].pos = obj->pos;
                        func_8000D6A0(idx);
                        func_8003E6EC(D_800CA31C->unk0, obj, 0);
                        func_8000237C(obj, model, 1, 0);
                        func_800015AC(obj, 0);
                        obj->unk7E = 1;
                        G->tracks[idx].pos = G->tracks[idx].to = G->tracks[idx].from;
                        G->tracks[idx].rotFrom = G->tracks[idx].rotTo = obj->rot;
                    }
                } else {
                    obj->pos.x = v2.x;
                    if (len_D) {
                        obj->pos.y = v2.y;
                    }
                    obj->pos.z = v2.z;
                    obj->rot.x = v.x * ANG;
                    obj->rot.y = v.y * ANG;
                    obj->rot.z = v.z * ANG;
                    G->tracks[idx].attach = attach;
                    if (attach == 0xFF) {
                        G->tracks[idx].to = obj->pos;
                    }
                    G->tracks[idx].pos = G->tracks[idx].from = G->tracks[idx].to;
                    G->tracks[idx].rotFrom = G->tracks[idx].rotTo = obj->rot;
                }
                func_8000CC1C(obj, type2);
                obj->flags = (obj->flags | 0x2401) & ~0x40000;
                break;
            case 0x11:
                idx = arg & 0xFF;
                obj = G->tracks[idx].obj;
                len_11 = arg >> 8;
                G->tracks[idx].rotT = 0;
                G->tracks[idx].rotLen = len_11;
                if (len_11 == 0) {
                    G->tracks[idx].rotLen = 1;
                }
                v.x = READF();
                v.y = READF();
                v.z = READF();
                v.y += 180.0f;
                v2 = v;
                READVEC(v);
                obj->pos.x = G->tracks[idx].to.x;
                obj->pos.z = G->tracks[idx].to.z;
                obj->rot = G->tracks[idx].rotTo;
                G->tracks[idx].rotFrom = obj->rot;
                G->tracks[idx].rotTo.x = v2.x * ANG;
                G->tracks[idx].rotTo.y = v2.y * ANG;
                G->tracks[idx].rotTo.z = v2.z * ANG;
                G->tracks[idx].moveT = 0;
                G->tracks[idx].moveLen = G->tracks[idx].rotLen;
                G->tracks[idx].from = obj->pos;
                G->tracks[idx].to.x = v.x;
                G->tracks[idx].to.y = obj->pos.y;
                G->tracks[idx].to.z = v.z;
                G->tracks[idx].pos = G->tracks[idx].from;
                break;
            case 0x10:
                idx = arg & 0xFF;
                obj = G->tracks[idx].obj;
                len_10 = arg >> 8;
                G->tracks[idx].rotT = 0;
                G->tracks[idx].rotLen = len_10;
                if (len_10 == 0) {
                    G->tracks[idx].rotLen = 1;
                }
                v.x = READF();
                v.y = READF();
                v.z = READF();
                v.y += 180.0f;
                obj->rot = G->tracks[idx].rotTo;
                G->tracks[idx].rotFrom = obj->rot;
                G->tracks[idx].rotTo.x = v.x * ANG;
                G->tracks[idx].rotTo.y = v.y * ANG;
                G->tracks[idx].rotTo.z = v.z * ANG;
                break;
            case 0xE:
                idx = (opcode >> 9) & 0x7F;
                obj = G->tracks[idx].obj;
                len_E = G->pc++->u;
                p2_E = (opcode >> 6) & 3;
                par = len_E & 0xFFFF;
                len_E >>= 16;
                type2 = opcode >> 16;
                if (len_E == 1 && par == 2) {
                    par = len_E;
                }
                G->tracks[idx].animFrame = len_E - 1;
                G->tracks[idx].animMode = type2;
                G->tracks[idx].animEnd = par - 1;
                obj->model->unk98 = G->tracks[idx].animFrame;
                obj->model->unk9A = G->tracks[idx].animEnd;
                obj->model->unk14_28 = p2_E;
                obj->model->unk30 = func_8000550C(obj, G->tracks[idx].animFrame, G->tracks[idx].animMode);
                break;
            case 0xF:
                idx = arg & 0xFF;
                G->tracks[idx].moveT = 0;
                G->tracks[idx].moveLen = arg >> 8;
                obj = G->tracks[idx].obj;
                READVEC(v);
                obj->pos = G->tracks[idx].to;
                G->tracks[idx].from = obj->pos;
                G->tracks[idx].to = v;
                G->tracks[idx].pos = G->tracks[idx].from;
                break;
            case 0x1A:
                G->tracks[52].moveT = 0;
                G->tracks[52].moveLen = arg;
                v.x = (f32)G->pc++->i * (1.0f / 255.0f);
                v.y = 0.0f;
                v.z = 0.0f;
                G->tracks[52].from = v;
                v.x = (f32)G->pc++->i * (1.0f / 255.0f);
                G->tracks[52].to = v;
                break;
            case 0x1B:
                par = (opcode >> 6) & 0x7FF;
                len_1B = opcode >> 17;
                if (arg0 == 0) {
                    func_80074BC4(len_1B, par);
                }
                break;
            case 0x1C:
                bytes_1C = (u8 *)G->pc++;
                par = arg & 0xFF;
                attach = bytes_1C[1];
                p2_1C = bytes_1C[2];
                tr_1C = bytes_1C[3];
                idx = arg >> 8;
                if (arg0 == 0) {
                    if (attach == 0xFF) {
                        G->tracks[tr_1C].sound = func_8000A830(idx, par, p2_1C);
                    } else {
                        G->tracks[tr_1C].snd.unk18 = 0;
                        G->tracks[tr_1C].snd.unk14 = idx;
                        G->tracks[tr_1C].snd.unk16 = 0;
                        G->tracks[tr_1C].snd.unk17 = 0;
                        G->tracks[tr_1C].snd.unk19 = par;
                        G->tracks[tr_1C].snd.unk1A = 1;
                        G->tracks[tr_1C].snd.unkC = D_800B1FE0[idx];
                        G->tracks[tr_1C].snd.unk10 = D_800B2230[idx];
                        G->tracks[tr_1C].snd.unk0 = -1;
                        G->tracks[tr_1C].snd.unk4 = 1000.0f;
                        G->tracks[tr_1C].snd.unk8 = 1000.0f;
                        G->tracks[tr_1C].unk87 = attach;
                    }
                } else {
                    G->tracks[tr_1C].sound = -1;
                }
                break;
            case 0x1D:
                if (G->tracks[arg].sound != -1) {
                    func_8000A270(G->tracks[arg].sound);
                    G->tracks[arg].sound = -1;
                }
                if (G->tracks[arg].snd.unk14 != 0) {
                    func_80085E30(&G->tracks[arg].snd);
                    G->tracks[arg].snd.unk14 = 0;
                }
                break;
            case 0x1E:
                par = arg & 0xFF;
                idx = arg >> 8;
                if (arg0 == 0) {
                    func_80074B5C(idx, par);
                }
                break;
            case 0x1F:
                func_8000A5D0(arg >> 8);
                break;
            case 0x20:
                func_8000A29C();
                break;
            case 0x21:
                switch (arg & 0xFF) {
                case 1: case 2: case 3: case 4: case 5: case 6: case 7: case 8: case 9: case 10:
                case 11: case 12: case 13: case 14: case 15: case 16: case 17: case 18: case 19: case 20:
                case 21: case 22: case 23: case 24: case 25: case 26: case 27: case 28: case 29: case 30:
                case 31: case 32: case 33: case 34: case 35: case 36: case 37: case 38: case 39: case 40:
                case 41: case 42: case 43: case 44: case 45: case 46:
                    D_80109A60[arg] = 1;
                    break;
                case 100:
                    if (arg0 == 0) {
                        func_80084338(0xF6, &D_80109690[0]->unk10);
                        func_80073508(&D_80109690[0]->unk10, 0.005f);
                    }
                    break;
                case 102:
                    if (D_800E0742) {
                        for (i = 0; i < 56; i++) {
                            obj = G->tracks[i].obj;
                            if (obj != NULL && obj->model != NULL) {
                                switch (obj->model->unkB1) {
                                case 11: case 12: case 13: case 14: case 15: case 16: case 17: case 18:
                                    obj->rot.x = obj->rot.z = 0.0f;
                                    func_800656C0(D_8010A500[0], &obj->pos, &obj->rot);
                                    break;
                                }
                            }
                        }
                    }
                    break;
                case 103:
                    if (D_800E0742) {
                        func_8000CCE4((arg >> 8) & 0xFF, 1, 4, 0);
                    }
                    break;
                case 104:
                    if (D_800E0742) {
                        func_8000CCE4(2, 0xC, 0, 2);
                    }
                    break;
                case 116:
                    if (D_800E0742) {
                        obj = func_8000CCE4((arg >> 8) & 0xFF, 1, 4, 0);
                        if (obj != NULL) {
                            ObjExtra *extra = obj->extra;
                            obj->unk60 = 0x4000000;
                            extra->unk88_11 = 7;
                            extra->unk50 = obj->pos;
                            extra->unk60[0] = 0;
                            extra->unk60[1] = 0;
                            extra->unk60[2] = 0;
                            extra->unk60[1] = 0x2A;
                        }
                    }
                    break;
                case 101:
                    if (arg0 == 0) {
                        D_800E0744 = 1;
                    }
                    break;
                case 105:
                    obj = G->tracks[arg >> 16].obj;
                    if (obj != NULL && obj->model != NULL) {
                        func_800015AC(obj, func_8000C860((arg >> 8) & 0xFF));
                        if (obj->model->unk14_15) {
                            func_80002E80(obj);
                        }
                    }
                    break;
                case 106:
                    if (G->unk10 != 0x23) {
                        func_8000DBBC(8);
                    } else {
                        func_80045130(0x24);
                    }
                    break;
                case 114:
                    func_8000DBBC(4);
                    break;
                case 107:
                    if (!D_800E0746) {
                        func_80031700(0x1A);
                        switch (D_80102EE8) {
                        case 0:
                            break;
                        case 1:
                        case 2:
                            func_80031700(0x17);
                            break;
                        }
                        func_8007089C(D_8010A500[0], 0, 4);
                    }
                    break;
                case 110:
                    if (!D_800E0746) {
                        func_80031700(2);
                    }
                    break;
                case 111:
                    if (!D_800E0746) {
                        func_80031700(0x17);
                        func_80031700(1);
                        func_80031700(0x18);
                    }
                    break;
                case 108:
                    G->tracks[(arg >> 8) & 0xFF].lookAt = arg >> 16;
                    break;
                case 109:
                    G->tracks[(arg >> 8) & 0xFF].lookAt = 0xFE;
                    break;
                case 112:
                    i = (arg >> 8) & 0xFF;
                    G->tracks[i].unk86 = 1;
                    D_800E0747 = 0;
                    break;
                case 113:
                    i = (arg >> 8) & 0xFF;
                    G->tracks[i].unk86 = 0;
                    break;
                case 115:
                    if (arg0 == 0) {
                        obj = G->tracks[10].obj;
                        func_8005C508(obj, &obj->pos);
                    }
                    break;
                case 117:
                    obj = G->tracks[(arg >> 8) & 0xFF].obj;
                    switch (arg >> 16) {
                    case 0:
                        obj->model->unk70 = func_8004478C(0, 0xF7);
                        break;
                    case 1:
                        obj->model->unk70 = func_8004478C(1, 0xD5);
                        break;
                    }
                    break;
                case 118:
                    D_800E0758 = 1;
                    break;
                }
                break;
            case 0x24:
                break;
            }
        } while (running);
    }

    for (i = 0; i < 56; i++) {
        f = (f32)G->tracks[i].moveT / (f32)G->tracks[i].moveLen;
        switch (i) {
        default:
            obj = G->tracks[i].obj;
            if (obj != NULL) {
                if (G->tracks[i].mode == LIN) {
                    v3.x = LERP(G->tracks[i].from.x, G->tracks[i].to.x, f);
                    v3.y = LERP(G->tracks[i].from.y, G->tracks[i].to.y, f);
                    v3.z = LERP(G->tracks[i].from.z, G->tracks[i].to.z, f);
                    if (G->tracks[i].attach == 0xFF) {
                        if (obj->model != NULL) {
                            Vec3 *look;
                            obj->pos.x += v3.x - G->tracks[i].pos.x;
                            obj->pos.y += v3.y - G->tracks[i].pos.y;
                            obj->pos.z += v3.z - G->tracks[i].pos.z;
                            obj->model->unk34 = func_80045590(&v3, &G->tracks[i].pos);
                            G->tracks[i].pos = v3;
                            if (obj->unk20 != NULL) {
                                obj->model->unk11 = obj->unk20->unk3C->unk47;
                                if (arg0 == 0) {
                                    obj->model->unkC |= 8;
                                } else {
                                    obj->model->unkC &= ~8;
                                }
                            }
                            if (G->tracks[i].lookAt != 0xFF) {
                                look = NULL;
                                if (G->tracks[i].lookAt != 0xFE) {
                                    v = G->tracks[G->tracks[i].lookAt].obj->pos;
                                    v.y += 0.5f;
                                    look = &v;
                                }
                                func_8000628C(obj, look, 1, 0x40);
                                func_8000628C(obj, look, 0, 0xFA);
                            }
                        } else {
                            obj->pos = v3;
                        }
                    } else {
                        G->tracks[i].pos = v3;
                        func_8000D6A0(i);
                    }
                } else {
                    func_80046EB8(&G->tracks[i].mode, &G->tracks[i].from, &G->tracks[i].to, G->tracks[i].unk30, f, &obj->pos);
                }
                obj->flags |= 1;
                f = (f32)G->tracks[i].scaleT / (f32)G->tracks[i].scaleLen;
                obj->scale = LERP(G->tracks[i].scaleFrom, G->tracks[i].scaleTo, f);
                if (G->tracks[i].scaleT < G->tracks[i].scaleLen) {
                    G->tracks[i].scaleT++;
                }
                f = (f32)G->tracks[i].alphaT / (f32)G->tracks[i].alphaLen;
                obj->unk82 = LERP(G->tracks[i].alphaFrom, G->tracks[i].alphaTo, f);
                if (G->tracks[i].alphaT < G->tracks[i].alphaLen) {
                    G->tracks[i].alphaT++;
                }
                f = (f32)G->tracks[i].rotT / (f32)G->tracks[i].rotLen;
                obj->rot.x = ALERP(G->tracks[i].rotFrom.x, G->tracks[i].rotTo.x, f);
                obj->rot.y = ALERP(G->tracks[i].rotFrom.y, G->tracks[i].rotTo.y, f);
                obj->rot.z = ALERP(G->tracks[i].rotFrom.z, G->tracks[i].rotTo.z, f);
                if (G->tracks[i].rotT < G->tracks[i].rotLen) {
                    G->tracks[i].rotT++;
                }
                if (G->tracks[i].animFrame >= 0) {
                    G->tracks[i].animFrame++;
                    if (G->tracks[i].animEnd < G->tracks[i].animFrame) {
                        G->tracks[i].animFrame = -1;
                    }
                }
                if (G->tracks[i].unk86 != 0) {
                    if (D_800E0747 <= 0) {
                        if (arg0 == 0) {
                            func_800617D8(obj->unk20, &obj->pos, &obj->rot, 0, 0.2f, 1.02f, 0x1B, 0xFB, 0x17, 0xD2, 0x80808002);
                        }
                    }
                }
            }
            if (G->tracks[i].snd.unk14 != 0) {
                func_80085E78(G->tracks[G->tracks[i].unk87].obj, &G->tracks[i].snd);
            }
            break;
        case 53:
            if (G->tracks[53].mode == LIN) {
                D_80109690[0]->unk10.x = LERP(G->tracks[53].from.x, G->tracks[53].to.x, f);
                D_80109690[0]->unk10.y = LERP(G->tracks[53].from.y, G->tracks[53].to.y, f);
                D_80109690[0]->unk10.z = LERP(G->tracks[53].from.z, G->tracks[53].to.z, f);
            } else {
                func_80046EB8(&G->tracks[53].mode, &G->tracks[53].from, &G->tracks[53].to, G->tracks[53].unk30, f, &D_80109690[0]->unk10);
            }
            D_80109690[0]->unkF4 = 0;
            break;
        case 54:
            if (G->tracks[54].mode == LIN) {
                v4.x = LERP(G->tracks[54].from.x, G->tracks[54].to.x, f);
                v4.y = LERP(G->tracks[54].from.y, G->tracks[54].to.y, f);
                v4.z = LERP(G->tracks[54].from.z, G->tracks[54].to.z, f);
            } else {
                func_80046EB8(&G->tracks[54].mode, &G->tracks[54].from, &G->tracks[54].to, G->tracks[54].unk30, f, &v4);
            }
            v3.x = v4.x - D_80109690[0]->unk10.x;
            v3.y = v4.y - D_80109690[0]->unk10.y;
            v3.z = v4.z - D_80109690[0]->unk10.z;
            func_800464B8(&v4, v3.x, v3.y, v3.z);
            D_80109690[0]->unk34 = -v4.x;
            D_80109690[0]->unk38 = v4.y;
            D_80109690[0]->unk3C = 3.1415927f;
            if (D_800E0744) {
                D_800E0744 = 0;
                func_8004830C(D_80109690[0]);
                func_8002B4D4(0, 0);
            }
            break;
        case 55:
            func_80048734(LERP(G->tracks[55].from.x, G->tracks[55].to.x, f));
            break;
        case 52:
            if (arg0 == 0) {
                func_8000CC38(52);
            }
            break;
        }
        if (G->tracks[i].moveT < G->tracks[i].moveLen) {
            G->tracks[i].moveT++;
        }
    }
    if (D_800E0748 != NULL) {
        func_8011842C(D_800E0748);
    }
    if (D_800E074C != NULL) {
        func_8000DAF4();
    }
    if (D_800E0747-- == 0) {
        D_800E0747 = 7;
    }
    if (D_800E0758) {
        D_80109A58 -= 3;
        if (D_80109A58 < 0) {
            D_80109A58 = 0;
        }
    }
    G->frame++;
    return G->status;
}
