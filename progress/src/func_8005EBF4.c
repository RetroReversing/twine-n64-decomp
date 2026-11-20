typedef struct {
    u8 pad0[0xC];
    f32 f0C;
    f32 f10;
    f32 f14;
    s32 w18;
    u8 pad1C[0xA];
    u16 h26;
    u16 h28;
    u8 pad2A[3];
    u8 b2D;
    u8 b2E;
    u8 b2F;
    s16 h30;
} SubEBF4;

typedef struct {
    u8 pad0[0x24];
    f32 f24;
    f32 f28;
    f32 f2C;
    u8 pad30[0xC];
    f32 f3C;
    f32 f40;
    u8 pad44[0x1C];
    s32 w60;
    u8 pad64[8];
    SubEBF4 *sub;
    u8 pad70[0xA];
    s16 state;
    u8 pad7C[2];
    s8 b7E;
    u8 pad7F[3];
    u8 b82;
} ObjEBF4;

s32 func_80000A30(s32, s32);
s32 func_80045DB4(void *, f32, f32);
s8 func_8005E4C8(void *);
s32 func_8005E900(void *);
s32 func_800850E0(void *);
extern u8 D_801002A0;
extern u8 D_801002A3;
extern s32 gUpdateGateWord;

void func_8005EBF4(ObjEBF4 *arg0) {
    SubEBF4 *s = arg0->sub;

    if (s->b2E != 0) {
        arg0->f3C -= func_80000A30(0x400, (s32)arg0->f3C) * 0.1f;
        arg0->f40 -= func_80000A30(0, (s32)arg0->f40) * 0.1f;
        if (arg0->w60 & 2) {
            arg0->w60 &= ~2;
            func_80045DB4(&arg0->f3C, 512.0f, 256.0f);
            func_80045DB4(&s->f0C, 0.4f, 0.2f);
            s->f10 = 2.0f;
            func_800850E0(&arg0->f24);
            arg0->state = 0;
        }
    }
    switch (arg0->state) {
    case 0:
    case 1:
        s->f10 -= 0.32666668f;
        arg0->f28 += s->f10 * 0.033333335f;
        arg0->f24 += s->f0C;
        arg0->f2C += s->f14;
        s->f0C *= 0.75f;
        s->f14 *= 0.75f;
        func_8005E900(arg0);
        break;
    case 2:
        if (s->b2F == 0 && (arg0->w60 & 0x01000000)) {
            arg0->w60 &= ~0x01000000;
            s->f10 -= 0.32666668f;
            arg0->f28 += s->f10 * 0.033333335f;
            func_8005E900(arg0);
        }
        break;
    }
    if (func_8005E4C8(arg0) != 0) {
        if (s->b2D == 0) {
            arg0->w60 |= 1;
        } else {
            s->h30 = 0;
        }
    }
    if (s->b2E != 0 && (s->h26 == 0 || gUpdateGateWord != 0)) {
        if (s->w18 > 0) {
            if (--s->w18 == 0) {
                arg0->b7E = 0x10;
                arg0->b82 = 0xFF;
            }
        } else if (arg0->b82 != 0) {
            arg0->b82--;
        } else {
            if (D_801002A0 == 8) {
                switch (s->h28) {
                case 25:
                    D_801002A3 &= 0xFB;
                    break;
                case 24:
                    D_801002A3 &= 0xFD;
                    break;
                case 23:
                    D_801002A3 &= 0xFE;
                    break;
                }
            }
            arg0->w60 |= 1;
        }
    }
}
