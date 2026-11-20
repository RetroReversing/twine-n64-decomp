typedef struct { f32 x, y, z; } Vec3_60968;
typedef struct { s32 pad0; Vec3_60968 v[2]; s32 pad1C[3]; s32 f28; s32 f2C; s32 f30; f32 f34; } Sub60968;
typedef struct { u8 pad0[0x20]; s32 f20; Vec3_60968 pos; u8 pad30[0x28]; s32 f58; u8 pad5C[0x10]; Sub60968 *sub; u8 pad70[8]; s16 f78; s16 f7A; } Obj60968;
s32 func_80016718(Obj60968 *);
s32 actorLinkToSurface(s32, Obj60968 *, s32);
s32 func_80045CC4(void);
s32 func_80048F10(s32, Vec3_60968 *, Vec3_60968 *, Vec3_60968 *, f32, s32, s32, s32);
s32 func_80060AA8(Obj60968 *);
s32 func_800643D8(Obj60968 *);
f32 func_800828D0(f32);
extern s32 *D_800CA31C;

void func_80060968(Obj60968 *arg0) {
    Sub60968 *sub = arg0->sub;
    Sub60968 *e;
    Vec3_60968 v;
    Vec3_60968 out;

    e = (Sub60968 *)((func_80045CC4() & 1) * 0xC + (s32)sub);
    arg0->pos = e->v[0];
    v = e->v[0];
    func_80016718(arg0);
    actorLinkToSurface(*D_800CA31C, arg0, 1);
    func_80048F10(arg0->f20, &arg0->pos, &v, &out, 250.0f, 0, 0, 0);
    sub->f34 = v.y;
    if (func_800828D0(v.y - arg0->pos.y) > 1.0f) {
        arg0->f7A = 0;
        arg0->f78 = 0x28;
        arg0->f58 |= 1;
        func_80060AA8(arg0);
    } else {
        arg0->f7A = 0;
        arg0->f78 = 0x55;
        func_80060AA8(arg0);
    }
    func_800643D8(arg0);
    sub->f28 = 0;
    sub->f2C = 0;
    sub->f30 = 0;
}
