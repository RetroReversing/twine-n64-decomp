typedef struct { u32 base; u32 pc; u8 pad[0x178]; s16 regs[16]; } Seq;
typedef struct { u32 w0; u32 w1; } Cmd;
s32 func_80096E7C();
extern s16 D_80112E9E[];

s32 func_8009AE24(Seq *s, Cmd *c, u8 op) {
    s32 a;
    s32 b;
    u8 r;
    volatile u32 frame[2];
    u32 w;
    u32 v;
    u32 __repair_v_1;

    w = c->w0;
    v = w >> 16;
    {
        s32 value;
        u8 code = v;
        if ((w >> 8) & 0xFF) {
            value = func_80096E7C(s, code & 0xFF);
        } else {
            v &= 0x1F;
            if (v < 16) {
                value = s->regs[v];
            } else {
                value = D_80112E9E[v];
            }
        }
        a = value;
    }
    __repair_v_1 = c->w1;
    if ((c->w0 >> 24) != 0) {
        b = func_80096E7C(s, __repair_v_1 & 0xFF);
    } else {
        __repair_v_1 &= 0x1F;
        if (__repair_v_1 < 16) {
            b = s->regs[__repair_v_1];
        } else {
            b = D_80112E9E[__repair_v_1];
        }
    }
    switch (op) {
    case 0:
        r = (s16)b == (s16)a;
        break;
    case 1:
        r = (s16)a < (s16)b;
        break;
    }
    {
        u8 invert = ((u8 *)c)[6];
        u32 dest = c->w1;
        if (invert) {
            r = !r;
        }
        if (r) {
            s->pc = s->base + (dest >> 16) * 8;
        }
    }
    return 0;
}
