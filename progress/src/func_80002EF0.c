typedef struct { f32 x, y, z; } AV3;
typedef struct { f32 x, y, z, w; } AQ4;
typedef struct { f32 m[3][3]; AV3 t; } AM3;
typedef struct { s16 idx; s16 parent; AV3 a; AV3 b; s32 pad; } ABone;
typedef struct AFrame { u32 w[2]; AV3 pos[1]; } AFrame;
typedef struct AAnim {
    u32 flags; f32 speed; f32 blendSpeed; f32 rate; f32 acc; f32 blend; f32 blendRate; f32 f1C; f32 f20; f32 f24;
    AV3 pos; u8 pad34[0xC];
    u32 *prev; u32 *cur; u32 *out; s32 f4C; s16 *cmd; u16 *events; u8 pad58[0x10]; void (*cb)(void *); AV3 scale;
    s16 h78; s16 h7A; s16 h7C; s16 h7E; s16 frame; s16 lastFrame; s16 h84; s16 h86; s16 h88; s16 h8A; s16 h8C; s16 h8E; s16 h90;
    u8 pad92[0xB]; u8 b9D; u8 b9E; s8 b9F; u8 bA0;
} AAnim;
typedef struct ANode { AV3 *f0; AV3 *f4; u8 pad8[4]; u16 hC; s8 bE; u8 padF; u8 b10; u8 b11; u8 pad12[2]; AAnim anim; } ANode;
typedef struct APart {
    u8 pad0[0x34]; f32 f34; u8 pad38[0x44]; f32 f7C; u8 pad80[0xC]; f32 f8C; u8 pad90[0x28]; struct APart *fB8;
    u8 padBC[0xD4]; s8 b190; s8 b191; s8 b192; u8 b193; u8 b194; u8 b195;
} APart;
typedef struct AObj {
    u8 pad0[0x18]; struct AObj *f18; u8 pad1C[8]; AV3 pos; AV3 pos2; AV3 rot; u8 pad48[0xC]; f32 scale; s32 flags;
    u8 pad5C[0xC]; ANode *node; APart *part; u8 pad70[8]; u16 type; u8 pad7A[2]; s16 h7C;
} AObj;
typedef struct { u8 b; u8 pad[0xE7]; } ATblE8;
typedef struct { s16 h; u8 pad[6]; } ATbl8;
typedef struct { s16 *p; u8 pad[8]; } ATblC;

extern s32 D_800D9418;
extern f32 D_800D9414;
extern void (*D_800D941C)(f32, void *, void *, void *);
extern void (*D_800D9420)(s16 *, AM3 *);
extern void (*D_800D9424)(AV3 *, void *);
extern s32 gGameMode;
extern u16 D_800AE4C0[];
extern u16 D_800AE4CC[];
extern f32 D_800AE4D8;
extern s16 *sCommandSlotTable[];
extern u32 **D_800B17D4[];
extern u16 *D_800B1828[];
extern s16 *sCommandSecondaryTable[];
extern ATbl8 D_800C392A[];
extern ATblC D_800C3CF8[];
extern ATblE8 D_800C470A[];

f32 absFloat(f32);
void func_800061D0(AObj *, s32, s32);
void func_800065BC(AObj *, s32);
void func_8008587C(AObj *);
void func_80084338(s32, AV3 *);
void func_80085934(AObj *, AV3 *);
u16 *func_8000182C(s32);
void func_800060B0(AObj *, s32, s32);
void func_80006130(AObj *, s32, s32);
u32 func_80045CF8(s32);
void func_8000A894(s32);
void func_80002D30(AObj *, s32);
void func_800054D8(AObj *);
void func_80005310(AObj *);
ABone *func_80001928(s32);
void func_800468E4(void *, AM3 *);
AM3 *func_8000DA08(AObj *);
void func_80083560(AM3 *, AM3 *);
void func_800839F0(AM3 *, AV3 *, AV3 *);
f32 func_80082A70(f32, f32);
f32 func_80046140(f32, f32);
void func_80083A6C(AM3 *, AV3 *);
void func_80005B90(u32 *, s32, f32, s32);
void func_80005D04(u32 *, u32 *, u32 *, f32);
void func_80001624(AObj *, s32);
void func_80046648(AV3 *, AQ4 *);
void func_80046538(void *, AQ4 *, AQ4 *);


#define VADD(d, a_, b_) { (d).x = (a_).x + (b_).x; (d).y = (a_).y + (b_).y; (d).z = (a_).z + (b_).z; }
static inline void tail(AObj *o, AM3 *mm, AV3 *p, AV3 *v, ABone *b) {
    p->x = mm->t.x + o->pos.x; p->y = mm->t.y + o->pos.y; p->z = mm->t.z + o->pos.z;
    v->x = b->b.x; v->y = b->b.y; v->z = b->b.z;
    func_80083A6C(mm, v);
}
static inline void xf(AM3 *mm, AV3 *v, f32 x, f32 y, f32 z) { v->x = x; v->y = y; v->z = z; func_80083A6C(mm, v); }
static inline void xf2(AObj *o, AM3 *mm, AV3 *p, AV3 *v, f32 x, f32 y, f32 z) {
    p->x = mm->t.x + o->pos.x; p->y = mm->t.y + o->pos.y; p->z = mm->t.z + o->pos.z;
    v->x = x; v->y = y; v->z = z; func_80083A6C(mm, v); }
static inline void vadd(AV3 *d, AV3 *a_, AV3 *b_) { d->x = a_->x + b_->x; d->y = a_->y + b_->y; d->z = a_->z + b_->z; }

#define VSET(v, a_, b_, c_) { f32 x_ = (a_); f32 y_ = (b_); f32 z_ = (c_); (v).x = x_; (v).y = y_; (v).z = z_; }

s32 func_80002EF0(AObj *obj) {
    AV3 sp10;
    AV3 sp20;
    AV3 sp30;
    AV3 sp40;
    AV3 sp50;
    AV3 sp60;
    s16 sp70[3];
    s16 sp78[3];
    AM3 sp80;
    AM3 spB0;
    AM3 mats[49];
    u32 spA10[20];
    u32 spA60[20];
    AQ4 spAB0;
    AQ4 spAC0;
    AAnim *a = &obj->node->anim;
    u32 *cur;
    u32 *prev;
    const ABone *bones;
    APart *part2;
    AM3 *root;
    s32 first;
    s32 base;
    s32 qbase;
    s32 noYaw;
    s32 blendPart;
    s32 flag4;
    s32 lerp;
    s32 mode2;
    s32 ret;
    s32 again;
    s32 d;
    s32 op;
    s32 tmp;
    s32 frame;
    u16 *ev;
    u16 *hdr;
    u16 *hdr1;
    u16 *hdr2;
    s32 fwd;
    s32 prevF;
    s32 curF;
    f32 v;
    APart *part;
    s32 isPart;
    f32 t;
    u32 i;
    u32 j;
    u32 *fr;
    s32 k;
    AM3 *m;
    AM3 *pm;
    AM3 *mm;
    AQ4 *dst;
    AQ4 *qp;
    AQ4 *qc;
    u32 w;

    ret = 0;
    first = 1;
    again = 1;
    a->f1C += a->f20;
    D_800D9418 = a->frame;
    D_800D9414 = a->blend;
    flag4 = obj->flags & 4;

    while (again) {
        if (a->cmd == NULL) break;
        if (a->flags & 0x10) break;
        d = 1;
        if (first) {
            first = 0;
            a->flags &= ~0x20;
            if (!(a->flags & 0x10000)) {
                if (a->f4C == 0) {
                    v = a->rate;
                    if (!(v <= 0.0002f) | !(-0.0002f <= v)) {
                        a->acc += absFloat(v);
                        if (a->acc >= 1.0f) {
                            if (v >= 0.0f) {
                                frame = a->frame + (s32)a->acc;
                                d = frame - a->h8A;
                            } else {
                                frame = a->frame - (s32)a->acc;
                                d = a->h88 - frame;
                            }
                            if (d <= 0) {
                                func_800061D0(obj, a->h7E, frame);
                                a->acc = absFloat(a->acc - (s32)a->acc);
                            } else {
                                a->flags |= 0x20;
                                if (a->blend == 1.0f) a->flags |= 0x40;
                                a->acc = 1.0f;
                            }
                            ret |= 1;
                        }
                    }
                } else {
                    a->rate = a->f20;
                    if (a->rate < -1.0f) a->rate = -1.0f;
                    else if (a->rate > 1.0f) a->rate = 1.0f;
                }
                if (a->flags & 0x40000) {
                    a->blend += a->blendRate;
                    if (a->blend >= 1.0f) {
                        a->blend = 1.0f;
                        a->flags = (a->flags | 0x40) & ~0x40000;
                    }
                    ret |= 2;
                    D_800D9414 = a->blend;
                } else {
                    D_800D9414 = a->acc;
                }
            } else {
                a->flags &= ~0x10000;
            }
            ev = a->events;
            if (ev != NULL) {
                if (a->bA0 != 0) a->bA0--;
                if (a->frame != a->lastFrame) {
                    fwd = a->rate >= 0.0f;
                    prevF = a->h7C;
                    curF = a->frame;
                    if (a->lastFrame < 0) prevF--;
                    a->lastFrame = a->frame;
                    for (;;) {
                        s32 hit;
                        s32 ge;
                        s32 lt;
                        op = ev[0];
                        if (op == 0) break;
                        frame = ev[1];
                        lt = prevF < frame;
                        if (fwd) {
                            ge = curF >= frame;
                        } else {
                            ge = frame >= curF;
                            lt = frame < prevF;
                        }
                        hit = ge & lt;
                        switch (op) {
                            case 3:
                                if (hit) func_800065BC(obj, 0);
                                ev += 2;
                                break;
                            case 1:
                                if (hit && a->bA0 == 0) {
                                    a->bA0 = 4;
                                    func_8008587C(obj);
                                }
                                ev += 2;
                                break;
                            case 2:
                                if (hit) {
                                    op = (gGameMode == 0x26) ? 7 : 4;
                                    obj->node->b11 = op;
                                    func_8008587C(obj);
                                }
                                ev += 2;
                                break;
                            case 5:
                                if (hit) {
                                    AObj *o = obj->f18;
                                    if (o == NULL) o = obj;
                                    func_80084338(ev[2], &o->pos);
                                }
                                ev += 3;
                                break;
                            case 4:
                                if (hit) func_80085934(obj, &obj->pos);
                                ev += 2;
                                break;
                        }
                    }
                }
            }
        }
        op = *a->cmd++;
        switch (op & 0x1F) {
            case 0:
            case 1:
            case 2:
            case 3:
                a->cmd = sCommandSlotTable[op & 0x1F];
                *a->cmd = (*a->cmd & 0x1F) + ((u16)op & 0xFFE0);
                break;
            case 23:
                a->flags |= 0x2000;
            case 21:
            do21:
                tmp = (a->flags >> 2) & 3;
                a->flags &= ~0xC;
                if (tmp == 1 || tmp == 3) goto do22;
                op = (u16)op >> 5;
                a->flags |= 0x4000;
                hdr1 = func_8000182C(op);
                a->h88 = 0;
                if (a->h86 >= 0) {
                    a->h8A = a->h86;
                    a->h86 = -1;
                } else {
                    a->h8A = *hdr1 - 1;
                }
                if (!(a->flags & 0x2000)) {
                    a->rate = a->speed;
                    frame = a->h88;
                } else {
                    a->rate = -a->speed;
                    frame = a->h8A;
                }
                if (a->h84 >= 0) {
                    frame = a->h84;
                    a->h84 = -1;
                }
                func_800060B0(obj, op, frame);
                *(s32 *)&a->acc = 0;
                D_800D9414 = a->acc;
                a->lastFrame = -1;
                a->events = NULL;
                a->f4C = 0;
                a->blend = 1.0f;
                a->flags = (a->flags | 0x13C0) & ~0x42000;
                if ((u32)(*D_800C3CF8[a->b9D].p - 0x1DF) < 0x1C) a->flags &= ~0x1000;
                ret |= 4;
                break;
            case 22:
            do22:
                tmp = (a->flags >> 2) & 3;
                a->flags &= ~0xC;
                if (tmp == 1 || tmp == 2) goto do21;
                op = (u16)op >> 5;
                a->flags |= 0x4000;
                hdr2 = func_8000182C(op);
                a->h88 = 0;
                if (a->h86 >= 0) {
                    a->h8A = a->h86;
                    a->h86 = -1;
                } else {
                    a->h8A = *hdr2 - 1;
                }
                if (!(a->flags & 0x2000)) {
                    a->rate = a->speed;
                    frame = a->h88;
                } else {
                    a->rate = -a->speed;
                    frame = a->h8A;
                }
                if (a->h84 >= 0) {
                    frame = a->h84;
                    a->h84 = -1;
                }
                func_80006130(obj, op, frame);
                a->lastFrame = -1;
                a->events = NULL;
                a->f4C = 0;
                a->acc = 0.0f;
                a->blend = 0.0f;
                D_800D9414 = a->blend;
                a->blendRate = a->blendSpeed;
                a->flags = (a->flags | 0x41380) & ~0x2040;
                ret |= 8;
                break;
            case 5:
                if (a->h8C != 0) {
                    func_80002D30(obj, a->h8C);
                } else {
                    a->flags |= 0x10;
                    obj->node->hC &= ~0x40;
                    if (a->cb != NULL) a->cb(obj);
                }
                break;
            case 6:
                if (flag4) {
                    if (!(a->flags & 0x2000)) {
                        frame = a->h88 + d - 1;
                        a->rate = a->speed;
                    } else {
                        frame = a->h8A - d - 1;
                        a->rate = -a->speed;
                    }
                    func_800061D0(obj, a->h7E, frame);
                } else {
                    again = 0;
                    a->rate = 0.0f;
                    a->cmd--;
                }
                break;
            case 7:
                if (a->rate >= 0.0f) {
                    frame = a->h8A - d - 1;
                } else {
                    frame = a->h88 + d - 1;
                }
                a->rate = -a->rate;
                func_800061D0(obj, a->h7E, frame);
                break;
            case 10:
                a->cmd += *a->cmd + 1;
                break;
            case 11:
                op = *a->cmd++;
                tmp = *a->cmd++;
                if (func_80045CF8(100) < op) a->cmd += tmp;
                break;
            case 12:
                func_8000A894(*a->cmd++);
                break;
            case 13:
                func_80084338((u16)*a->cmd++, &obj->pos);
                break;
            case 26:
                a->events = D_800B1828[*a->cmd++];
                break;
            case 14:
                a->h88 = *a->cmd++;
                break;
            case 15:
                a->h8A = *a->cmd++;
                break;
            case 27:
                func_80002D30(obj, *a->cmd);
                break;
            case 28:
                a->cmd = sCommandSecondaryTable[*a->cmd];
                break;
            case 16:
                a->acc = 0.0f;
                a->speed = *a->cmd++ * 0.00390625f;
                break;
            case 17:
                a->acc = 0.0f;
                a->blendSpeed = *a->cmd++ * 0.00390625f;
                break;
            case 18:
                a->acc = 0.0f;
                a->rate = *a->cmd++ * 0.00390625f;
                break;
            case 29:
                hdr = (u16 *)*D_800B17D4[*a->cmd++];
                a->flags = (a->flags & ~0x280) | 0x100;
                a->f4C = (s32)hdr;
                func_800054D8(obj);
                break;
            case 25:
                tmp = *a->cmd++;
                a->flags &= ~tmp;
                break;
            case 24:
                tmp = *a->cmd++;
                a->flags |= tmp;
                break;
            case 8:
                again = 0;
                break;
            case 9:
                break;
            case 4:
                if (a->f4C == 0) {
                    if ((a->flags & 0x60) == 0x60) {
                        a->flags &= ~0x60;
                        break;
                    }
                } else if (!(a->f20 <= 0.0002f) || !(-0.0002f <= a->f20)) {
                    func_80005310(obj);
                    ret |= 0x10;
                }
                again = 0;
                a->cmd--;
                break;
            case 19:
                a->h84 = *a->cmd++;
                break;
            case 20:
                op = *a->cmd++;
                if (a->h90 == 0) a->h90 = op;
                if (--a->h90 > 0) {
                    again = 0;
                    a->cmd -= 2;
                } else {
                    a->flags &= ~0x60;
                }
                break;
        }
    }

    a->h78 = obj->rot.y;
    a->h7A = 0;
    if (a->h7E < 0) return 0;

    isPart = (obj->type == 2 || obj->type == 3);
    if (isPart) {
        part = obj->part;
        part2 = part->fB8;
    } else {
        part = NULL;
        if (obj->type == 1) {
            part2 = *(APart **)((u8 *)obj->part + 0x6C);
        } else {
            part2 = NULL;
        }
    }
    noYaw = D_800C392A[a->b9E].h == 0;
    blendPart = 0;
    if (isPart && part2 == NULL) {
        if (absFloat(part->f34) >= 0.1f || (obj->node->hC & 1) || part->b190 != 0) blendPart = 1;
    }
    if (blendPart) {
        if (obj->h7C == 5 || obj->h7C == 1) blendPart = 0;
    }
    lerp = a->flags & 0x1000;
    if (flag4 == 0) {
        if (obj->pos.x != obj->pos2.x || obj->pos.y != obj->pos2.y || obj->pos.z != obj->pos2.z) ret |= 0x20;
    }
    if (a->flags & 0x400000) {
        a->flags &= ~0x400000;
        ret |= 0x40;
    }
    if (ret == 0 && blendPart == 0) return 0;

    mode2 = 0;
    switch (a->flags & 3) {
        default:
        case 0:
            base = 5;
            qbase = 0;
            break;
        case 1:
            base = 5;
            qbase = a->b9F + 5;
            break;
        case 2:
            qbase = 0;
            mode2 = 1;
            base = a->b9F * 3 + 2;
            break;
        case 3:
            mode2 = 1;
            base = a->b9F * 3 + 2;
            qbase = base + a->b9F;
            break;
    }
    cur = a->cur;
    prev = a->prev;
    sp70[0] = obj->rot.x;
    sp70[1] = obj->rot.y;
    sp70[2] = obj->rot.z;
    t = D_800D9414;
    D_800D9420(sp70, &sp80);
    if (obj->scale != 1.0f) {
        for (i = 0; i < 3; i++) {
            for (j = 0; j < 3; j++) {
                sp80.m[i][j] *= obj->scale;
            }
        }
    }
    bones = func_80001928(a->b9E);
    root = &sp80;
    if (mode2 == 0) {
        switch (obj->type) {
            case 2:
            case 3:
                goto slow;
        }
        fr = NULL;
        if (D_800D9414 == 0.0f) fr = prev;
        else if (D_800D9414 == 1.0f) fr = cur;
        if (fr != NULL) {
            const ABone *bone;
            for (k = 0; k < a->b9F; k++) {
                bone = &bones[k];
                m = &mats[bone->idx];
                if (qbase == 0) {
                    a->out[base + k] = fr[base + k];
                    if (flag4) continue;
                    w = fr[base + k];
                    sp78[0] = (w >> 22) << 2;
                    sp78[1] = (w >> 10) & 0xFFE;
                    sp78[2] = (w << 1) & 0xFFE;
                    D_800D9420(sp78, m);
                } else {
                    qp = (AQ4 *)&fr[qbase + k * 4];
                    dst = (AQ4 *)&a->out[qbase + k * 4];
                    *dst = *qp;
                    if (flag4) continue;
                    func_800468E4(dst, m);
                }
                if (flag4) continue;
                VSET(sp40, bone->a.x, bone->a.y, bone->a.z);
                if (k == 0) {
                    m->t.x = sp40.x;
                    m->t.y = sp40.y;
                    m->t.z = sp40.z;
                    if (obj->flags & 0x40000) func_80083560(func_8000DA08(obj), m); else func_80083560(root, m);
                } else {
                    pm = &mats[bone->parent];
                    func_800839F0(pm, &sp40, &m->t);
                    VSET(m->t, m->t.x + pm->t.x, m->t.y + pm->t.y, m->t.z + pm->t.z);
                    func_80083560(pm, m);
                    if (noYaw) if (k == 0xE) {
                        sp10.x = 0.0f;
                        sp10.z = 0.0f;
                        sp10.y = 1.0f;
                        func_800839F0(m, &sp10, &sp20);
                        a->h78 = func_80082A70(sp20.x, sp20.z) * 651.8986f;
                        a->h7A = func_80082A70(sp20.x, func_80046140(sp20.x, sp20.z)) * 651.8986f;
                    }
                }
                sp50.x = m->t.x + obj->pos.x;
                sp50.y = m->t.y + obj->pos.y;
                mm = m;
                sp50.z = mm->t.z + obj->pos.z;
                VSET(sp40, bone->b.x, bone->b.y, bone->b.z);
                func_80083A6C(mm, (AV3 *)&sp40);
                obj->node->f0[k].x = sp50.x;
                obj->node->f0[k].y = sp50.y;
                obj->node->f0[k].z = sp50.z;
                obj->node->f4[k].x = sp50.x + sp40.x;
                obj->node->f4[k].y = sp50.y + sp40.y;
                obj->node->f4[k].z = sp50.z + sp40.z;
            }
        } else {
            s32 rx, ry, rz;
            s32 px, py, pz;
            u16 *tbl;
            f32 half;
            const ABone *bone;
slow:
            if (blendPart) {
                tbl = D_800AE4C0;
                if (isPart && obj->h7C == 6) tbl = D_800AE4CC;
                switch (part->b190) {
                    default:
                    case 0:
                        func_80005B90(spA10, tbl[D_800C470A[part->b191].b], 0.5f - part->f34 * 0.5f, 0);
                        break;
                    case 1:
                        part->f7C = 0.0f;
                        part->b190 = 2;
                    case 2:
                    case 3:
                        func_80005B90(spA10, tbl[D_800C470A[part->b191].b], 0.5f - part->f34 * 0.5f, 0);
                        func_80005B90(spA60, tbl[0], 0.5f, 0);
                        func_80005D04(spA10, spA10, spA60, part->f7C);
                        if (part->b190 == 2) {
                            part->f7C += 0.1;
                            if (part->f7C > 1.0f) {
                                part->f7C = 1.0f;
                                part->b190 = 3;
                                if (part->b193 == 0) func_80001624(obj, 0);
                            }
                        } else if (part->b193 != 0) {
                            part->b193--;
                            if (part->b193 == 0) {
                                part->b190 = 5;
                                part->b192 = obj->node->bE;
                            }
                        }
                        break;
                    case 4:
                        part->b190 = 5;
                        func_80001624(obj, part->b192);
                    case 5:
                    case 6:
                        half = 0.5f;
                        func_80005B90(spA60, tbl[0], half, 0);
                        half = half - part->f34 * half;
                        func_80005B90(spA10, tbl[D_800C470A[part->b192].b], half, 0);
                        func_80005D04(spA10, spA10, spA60, part->f7C);
                        if (part->b190 == 6) {
                            part->b190 = 0;
                        } else {
                            part->f7C -= 0.1;
                            if (part->f7C < 0.0f) {
                                part->f7C = 0.0f;
                                part->b190 = 6;
                                part->b191 = part->b192;
                                if (isPart) {
                                    if (part->b192 == 0 || part->b194 == 0) {
                                        part->b194 = 1;
                                        part->b195 = 0x63;
                                        part->f8C = 9999.0f;
                                    }
                                }
                            }
                        }
                        break;
                }
            }
            for (k = 0; bones[k].idx >= 0; k++) {
                bone = &bones[k];
                m = &mats[bone->idx];
                if (qbase == 0) {
                    w = cur[base + k];
                    rx = (w >> 22) << 2;
                    ry = (w >> 10) & 0xFFE;
                    rz = (w << 1) & 0xFFE;
                    if (lerp) {
                        w = prev[base + k];
                        px = (w >> 22) << 2;
                        py = (w >> 10) & 0xFFE;
                        pz = (w << 1) & 0xFFE;
                        rx = (s32)((((rx - px) << 20) >> 20) * t) + px;
                        ry = (s32)((((ry - py) << 20) >> 20) * t) + py;
                        rz = (s32)((((rz - pz) << 20) >> 20) * t) + pz;
                    }
                    tmp = 1;
                    if (blendPart) {
                        switch (k) {
                            case 7:
                            case 8:
                            case 9:
                            case 11:
                            case 12:
                            case 13:
                                if (D_800C470A[obj->node->bE].b == 0 && part != NULL) {
                                    if (part->b190 == 0) tmp = 0;
                                }
                            case 10:
                            case 14:
                                if (tmp) {
                                    w = spA10[5 + k];
                                    rx = (w >> 22) << 2;
                                    ry = (w >> 10) & 0xFFE;
                                    rz = (w << 1) & 0xFFE;
                                }
                                break;
                        }
                    }
                    a->out[base + k] = ((rz & 0xFFE) >> 1) | ((ry & 0xFFE) << 10) | ((rx >> 2) << 22);
                    if (flag4) continue;
                    sp78[0] = rx;
                    sp78[1] = ry;
                    sp78[2] = rz;
                    D_800D9420(sp78, m);
                } else {
                    dst = (AQ4 *)&a->out[qbase + k * 4];
                    qp = (AQ4 *)&prev[qbase + k * 4];
                    qc = (AQ4 *)&cur[qbase + k * 4];
                    tmp = 1;
                    switch (k) {
                        case 8:
                        case 9:
                        case 10:
                        case 11:
                        case 12:
                        case 13:
                            if (D_800C470A[obj->node->bE].b == 0 && part != NULL) {
                                tmp = part->b190 != 0;
                            }
                        case 7:
                        case 14:
                            if (blendPart && tmp) {
                                w = spA10[5 + k];
                                sp30.x = (w >> 22) << 2;
                                sp30.y = (w >> 10) & 0xFFE;
                                sp30.z = (w << 1) & 0xFFE;
                                D_800D9424(&sp30, dst);
                                break;
                            }
                        default:
                            D_800D941C(t, qp, qc, dst);
                            break;
                    }
                    if (part2 != NULL && gGameMode == 0x19 && (k == 3 || k == 6)) {
                        sp30.z = *(f32 *)((u8 *)part2 + 0x58) - 1024.0f;
                        sp30.x = 0.0f;
                        sp30.y = 0.0f;
                        func_80046648(&sp30, &spAB0);
                        func_80046538(dst, &spAB0, &spAC0);
                        *dst = spAC0;
                    }
                    if (flag4) continue;
                    func_800468E4(dst, m);
                }
                if (flag4) continue;
                if (mode2 == 0) {
                    VSET(spAC0, bone->a.x, bone->a.y, bone->a.z);
                } else {
                    spAC0.x = ((AFrame *)cur)->pos[k].x;
                    spAC0.y = ((AFrame *)cur)->pos[k].y;
                    spAC0.z = ((AFrame *)cur)->pos[k].z;
                }
                if (k == 0) {
                    m->t.x = spAC0.x;
                    m->t.y = spAC0.y;
                    m->t.z = spAC0.z;
                    if (obj->flags & 0x40000) func_80083560(func_8000DA08(obj), m); else func_80083560(root, m);
                } else {
                    pm = &mats[bone->parent];
                    func_800839F0(pm, (AV3 *)&spAC0, &m->t);
                    VSET(m->t, m->t.x + pm->t.x, m->t.y + pm->t.y, m->t.z + pm->t.z);
                    func_80083560(pm, m);
                    if (noYaw) if (k == 0xE) {
                        sp10.x = 0.0f;
                        sp10.z = 0.0f;
                        sp10.y = 1.0f;
                        func_800839F0(m, &sp10, &sp20);
                        a->h78 = func_80082A70(sp20.x, sp20.z) * 651.8986f;
                        a->h7A = func_80082A70(sp20.x, func_80046140(sp20.x, sp20.z)) * 651.8986f;
                    }
                }
                sp50.x = m->t.x + obj->pos.x;
                sp50.y = m->t.y + obj->pos.y;
                mm = m;
                sp50.z = mm->t.z + obj->pos.z;
                VSET(spAC0, bone->b.x, bone->b.y, bone->b.z);
                func_80083A6C(mm, (AV3 *)&spAC0);
                obj->node->f0[k].x = sp50.x;
                obj->node->f0[k].y = sp50.y;
                obj->node->f0[k].z = sp50.z;
                obj->node->f4[k].x = sp50.x + spAC0.x;
                obj->node->f4[k].y = sp50.y + spAC0.y;
                obj->node->f4[k].z = sp50.z + spAC0.z;
            }
        }
        if (mode2 == 0) {
            f32 x, y, z;
            f32 ox, oy, oz;
            f32 nx, ny, nz;
            x = ((AFrame *)cur)->pos[0].x;
            y = ((AFrame *)cur)->pos[0].y;
            z = ((AFrame *)cur)->pos[0].z;
            if (a->flags & 0x1000) {
                x = (x - ((AFrame *)prev)->pos[0].x) * t + ((AFrame *)prev)->pos[0].x;
                y = (y - ((AFrame *)prev)->pos[0].y) * t + ((AFrame *)prev)->pos[0].y;
                z = (z - ((AFrame *)prev)->pos[0].z) * t + ((AFrame *)prev)->pos[0].z;
            }
            if (a->flags & 0x8000) {
                a->flags &= ~0x8000;
                a->pos.x = x;
                a->pos.y = y;
                a->pos.z = z;
            }
            nx = x; ny = y; nz = z;
            a->f24 = y + D_800AE4D8;
            x -= a->pos.x; y -= a->pos.y; z -= a->pos.z;
            a->pos.x = nx; a->pos.y = ny; a->pos.z = nz;
            ((AFrame *)a->out)->pos[0].x = nx; ((AFrame *)a->out)->pos[0].y = ny; ((AFrame *)a->out)->pos[0].z = nz;
            if (!(a->flags & 0x80)) x = 0.0f;
            if (!(a->flags & 0x100)) y = 0.0f;
            if (!(a->flags & 0x200)) z = 0.0f;
            sp60.x = x;
            sp60.y = y;
            sp60.z = z;
            func_800839F0(&sp80, &sp60, &sp50);
            { f32 px = sp50.x * a->scale.x; f32 py = sp50.y * a->scale.y; f32 pz = sp50.z * a->scale.z;
            VSET(obj->pos, obj->pos.x + px, obj->pos.y + py, obj->pos.z + pz); }
        }
    } else {
        const ABone *bone;
        for (k = 0; k < a->b9F; k++) {
            bone = &bones[k];
            sp40.x = ((AV3 *)(a->cur + 2))[k].x;
            sp40.y = ((AV3 *)(a->cur + 2))[k].y;
            sp40.z = ((AV3 *)(a->cur + 2))[k].z;
            ((AV3 *)(a->out + 2))[k].x = sp40.x;
            ((AV3 *)(a->out + 2))[k].y = sp40.y;
            ((AV3 *)(a->out + 2))[k].z = sp40.z;
            a->out[base + k] = a->cur[base + k];
            if (flag4) continue;
            m = &mats[bone->idx];
            w = a->cur[base + k];
            sp78[0] = (w >> 22) << 2;
            sp78[1] = (w >> 10) & 0xFFE;
            sp78[2] = (w << 1) & 0xFFE;
            D_800D9420(sp78, m);
            if (k == 0) {
                m->t.x = sp40.x;
                m->t.y = sp40.y;
                m->t.z = sp40.z;
                if (obj->flags & 0x40000) func_80083560(func_8000DA08(obj), m); else func_80083560(root, m);
            } else {
                pm = &mats[bone->parent];
                func_800839F0(pm, &sp40, &m->t);
                VSET(m->t, m->t.x + pm->t.x, m->t.y + pm->t.y, m->t.z + pm->t.z);
                func_80083560(pm, m);
            }
            sp50.x = m->t.x + obj->pos.x;
            sp50.y = m->t.y + obj->pos.y;
            mm = m;
            sp50.z = mm->t.z + obj->pos.z;
            VSET(sp40, bone->b.x, bone->b.y, bone->b.z);
            func_80083A6C(mm, (AV3 *)&sp40);
            obj->node->f0[k].x = sp50.x;
            obj->node->f0[k].y = sp50.y;
            obj->node->f0[k].z = sp50.z;
            obj->node->f4[k].x = sp50.x + sp40.x;
            obj->node->f4[k].y = sp50.y + sp40.y;
            obj->node->f4[k].z = sp50.z + sp40.z;
        }
    }
    return ret;
}
