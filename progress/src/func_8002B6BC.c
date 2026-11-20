typedef struct { u8 pad0[0x54]; f32 f54; s32 flags; } Obj2B6BC;
typedef struct { u8 pad0[0xF4]; void *fF4; } Def2B6BC;
extern Obj2B6BC * volatile D_800BF5BC;
extern f32 D_800BF5C4;
extern u16 D_800BF5C8;
extern u16 D_800BF5CA;
extern char D_800BF5CC[];
extern Def2B6BC *gAimAxisTable[];
s32 *func_8002B400(f32, s32, char *);
void func_80016718(void *);
void func_80016990(void *, void *);
void func_8002B7F8(void);

void func_8002B6BC(s32 arg0) {
    Obj2B6BC * volatile *pp;
    f32 *v;
    f32 progress;
    

    if (arg0 != 0) {
        pp = &D_800BF5BC;
        if (*pp == NULL) {
            return;
        }
        v = (f32 *)func_8002B400(D_800BF5C4, 0xE, D_800BF5CC);
        func_80016718(*pp);
        func_80016990(*pp, gAimAxisTable[D_800BF5CA]->fF4);
        D_800BF5BC->flags |= 0x1000;
        do { D_800BF5BC->f54 = *v; } while (0);
        switch (D_800BF5C8) {
        case 0:
            D_800BF5C4 = D_800BF5C4 + 0.02f;
            if (!(1.0f < D_800BF5C4))
                return;
            break;
        case 1:
            D_800BF5C4 = D_800BF5C4 - 0.02f;
            if (!(D_800BF5C4 < 0.0f))
                return;
            break;
        default:
            return;
        }
    }
    func_8002B7F8();
}
