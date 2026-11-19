typedef struct S {
    u8 pad0[4];
    unsigned long tbl;
    f32 t;
    f32 f0C;
    f32 f10;
    f32 f14;
    f32 f18;
    f32 f1C;
    f32 f20;
    f32 f24;
    u8 pad28[0x4B - 0x28];
    u8 cnt;
    s8 max;
} S;

extern s32 func_8005916C(s32, f32, void *);
extern s32 func_80059590(void *);

s32 func_80059754(void *arg0, s32 arg1, s32 arg2, s32 arg3) {
    S *s;
    f32 fa0;
    f32 fa1;
    unsigned int ret;
    s32 n;
    f32 t;
    u8 tmp;

    s = *(S **)((u8 *)arg0 + 0x6C);
    fa0 = 0.0f;
    fa1 = 0.0f;
    s->t = s->t - 1.0f;
    n = arg2;
    ret = 0;
    if (!n) {
        n = 0xF0;
    }
    if (s->t <= 0.0f) {
        if (s->tbl != 0) {
            tmp = s->cnt + (u8) arg1;
            s->cnt = tmp;
            if (((u32)(tmp << 24) >> 31) & ((u32) arg1 >> 31)) {
                s->cnt = 0;
                ret = 1;
            }
            if ((s8) s->max < (s8) s->cnt && arg1 > 0) {
                s->cnt = (u8) s->max;
                ret = 1;
            }
            func_8005916C(s->tbl + (s->cnt * 0x18), 1.0f, arg0);
            if ((s32)arg3 != 0) {
                s->f10 = -s->f10;
                s->f14 = -s->f14;
                s->f18 = -s->f18;
                s->f1C = -s->f1C;
                s->f20 = -s->f20;
                s->f24 = -s->f24;
            }
            t = (f32) (int)n;
            s->t = t;
            s->f0C = t;
            s->f10 = s->f10 * (1.5707964f / t);
            s->f14 = s->f14 * (1.5707964f / s->t);
            s->f18 = s->f18 * (1.5707964f / s->t);
            s->f1C = s->f1C * (1.5707964f / s->t);
            s->f20 = s->f20 * (1.5707964f / s->t);
            s->f24 = s->f24 * (1.5707964f / s->t);
        }
    }
    func_80059590(arg0);
    return ret;
}
