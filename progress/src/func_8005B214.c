typedef struct {
    u8 pad0[0x14];
    u16 h14;
    u8 pad16[6];
    f32 vec1C[1];
    f32 f20;
    u8 pad24[4];
    s16 h28;
    s16 h2A;
    f32 f2C;
    u8 b30;
    u8 b31;
    u8 b32;
    u8 b33;
} Sub5B214;

typedef struct {
    u8 pad0[0x20];
    s32 w20;
    u8 pos24[0x34];
    s32 w58;
    u8 pad5C[4];
    s32 w60;
    u8 pad64[8];
    Sub5B214 *sub;
    u8 *w70;
    u8 pad74[6];
    s16 state;
} Obj5B214;

s32 func_80015D40(u8);
s32 func_800175C0(s32, s32, s32, void *, f32, s32);
s32 func_8007659C(void *, void *);
s32 func_80085E30(void *);
s32 func_80085E78(void *, void *);
extern u8 D_80109A60[];

void func_8005B214(Obj5B214 *arg0) {
    s16 state = arg0->state;
    Sub5B214 *s = arg0->sub;
    s32 v;
    s32 one = 1;

    switch (state) {
    case 0:
        v = s->b30;
        if (v != 0) {
            v = D_80109A60[v];
        } else {
            if (arg0->w60 & func_80015D40(s->b31)) {
                arg0->state = 1;
            }
            v = s->b32;
        }
        if (v == one) {
            arg0->state = 1;
        }
        break;
    case 1:
        if (s->h14 != 0) {
            func_80085E78(arg0, s);
        }
        s->f20 += s->f2C;
        func_8007659C(arg0, s->vec1C);
        func_800175C0(arg0->w20, 0, 0x01000000, arg0->pos24, *(f32 *)(arg0->w70 + 0x14) + 1.0f, state);
        if (s->h2A == s->h28 - 4) {
            if (s->b32 == state) {
                s->h2A = 0;
            } else {
                arg0->state = 3;
            }
        }
        arg0->w58 |= 1;
        break;
    case 3:
        if (s->b33 != 0) {
            if (s->h14 != 0) {
                func_80085E30(s);
            }
            arg0->w60 |= 1;
        }
        break;
    }
}
