typedef struct { f32 x, y, z; } Vec3f;
typedef struct { u8 pad0[0x18]; Vec3f pos; } Obj81568;
typedef struct { u8 pad0[0x24]; Vec3f pos; } Cam81568;
typedef struct { u8 pad0[0x60]; s32 flags; u8 pad64[8]; Obj81568 *obj; } Ent81568;

extern Cam81568 *D_8010A500;
s8 func_8007C72C(Ent81568 *, Cam81568 *, s32);
s8 func_8007AA40(Ent81568 *, Vec3f *, s32 *);
void func_8007AABC(Ent81568 *, s32, f32);

s32 func_80081568(Ent81568 *arg0) {
    Obj81568 *obj;
    s32 sp10;

    if (arg0->flags & 0x3000) {
        obj = arg0->obj;
        if (func_8007C72C(arg0, D_8010A500, 0)) {
            return 1;
        }
        obj->pos = D_8010A500->pos;
        if (func_8007AA40(arg0, &obj->pos, &sp10)) {
            return 1;
        }
        func_8007AABC(arg0, sp10, 0.1f);
    }
    return 0;
}
