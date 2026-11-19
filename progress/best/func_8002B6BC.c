typedef struct { u8 pad0[0x54]; f32 f54; s32 flags; } Obj2B6BC;
typedef struct { u8 pad0[0xF4]; s32 fF4; } Def2B6BC;
extern Obj2B6BC *D_800BF5BC;
extern f32 D_800BF5C4;
extern u16 D_800BF5C8;
extern u16 D_800BF5CA;
extern s32 D_800BF5CC;
extern Def2B6BC *D_80109688[];
f32 *func_8002B400(f32, s32, s32 *);
void func_80016718(Obj2B6BC *);
void func_80016990(Obj2B6BC *, s32);
void func_8002B7F8(void);

void func_8002B6BC(s32 arg0) {
    Obj2B6BC **pp;
    f32 *v;

    if (arg0 != 0) {
        pp = &D_800BF5BC;
        if (*pp == NULL) {
            return;
        }
        v = func_8002B400(D_800BF5C4, 0xE, &D_800BF5CC);
        func_80016718(*pp);
        func_80016990(*pp, D_80109688[D_800BF5CA]->fF4);
        D_800BF5BC->flags |= 0x1000;
        D_800BF5BC->f54 = *v;
        switch (D_800BF5C8) {
        case 0:
            if ((D_800BF5C4 += 0.02f) > 1.0f) {
                break;
            }
            return;
        case 1:
            if ((D_800BF5C4 -= 0.02f) < 0.0f) {
                break;
            }
            return;
        default:
            return;
        }
    }
    func_8002B7F8();
}
