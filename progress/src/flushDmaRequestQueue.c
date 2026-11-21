typedef struct { s32 a, b, c; } T9D100;
s32 func_800CEEE0(s32, s32);
s32 osSendMesg(void *, s32, s32);
extern volatile u8 D_800FDBB0;
extern T9D100 D_800FDBB4[];
extern u8 D_800FDBE4;
extern char D_800FDBE8[];
extern T9D100 *D_80103EB4;
extern u16 D_80108F70;
extern s32 D_80109BA0;
extern s32 D_80109BF8;

void func_8009D100(void) {
    u8 i;
    T9D100 *o;

    if (D_800FDBE4 != 0) {
        osSendMesg(D_800FDBE8, 0, 0);
    }
    if (D_800FDBB0 != 0) {
        for (i = 0; i < D_800FDBB0; i++) {
            D_80109BF8 += 0xC;
            D_80109BA0 = func_800CEEE0(D_80109BA0, D_80109BF8);
            o = (T9D100 *)(D_80108F70 * (s32)sizeof(*o) + (u32)D_80103EB4);
            o->b = D_800FDBB4[i].b;
            o->a = D_800FDBB4[i].c;
            o->c = D_800FDBB4[i].a;
            D_80108F70++;
        }
        D_800FDBB0 = 0;
        D_800FDBE4 = 1;
    } else {
        D_800FDBE4 = 0;
    }
}
