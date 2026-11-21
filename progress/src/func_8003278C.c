typedef struct { u32 *dst; u32 src; u8 idx; u8 cnt; u8 cur; u8 lim; u16 sz; } Anim;
extern u32 D_80107ED0;
extern Anim *D_80109EA0[];

void func_8003278C(void) {
    u8 __repair_frame[1];
    u32 i;
    for (i = 0; i < D_80107ED0; i++) {
        Anim *a = D_80109EA0[i];
        a->cur++;
        if (a->lim < a->cur) {
            a->cur = 0;
            a->idx++;
            if (a->idx == a->cnt) a->idx = 0;
            *a->dst = a->src + a->idx * a->sz;
        }
    }
}
