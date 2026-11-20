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
extern s32 gBorderSkipFlag;

/* Per-frame update for an object with a sub-state: decays its motion, runs state-specific bounce/fall logic, and counts down the timer that sets the flag. */
void func_8005EBF4(ObjEBF4 *obj) {
    SubEBF4 *sub = obj->sub;

    if (sub->b2E != 0) {
        obj->f3C -= func_80000A30(0x400, (s32)obj->f3C) * 0.1f;
        obj->f40 -= func_80000A30(0, (s32)obj->f40) * 0.1f;
        if (obj->w60 & 2) {
            obj->w60 &= ~2;
            func_80045DB4(&obj->f3C, 512.0f, 256.0f);
            func_80045DB4(&sub->f0C, 0.4f, 0.2f);
            sub->f10 = 2.0f;
            func_800850E0(&obj->f24);
            obj->state = 0;
        }
    }
    switch (obj->state) {
    case 0:
    case 1:
        sub->f10 -= 0.32666668f;
        obj->f28 += sub->f10 * 0.033333335f;
        obj->f24 += sub->f0C;
        obj->f2C += sub->f14;
        sub->f0C *= 0.75f;
        sub->f14 *= 0.75f;
        func_8005E900(obj);
        break;
    case 2:
        if (sub->b2F == 0 && (obj->w60 & 0x01000000)) {
            obj->w60 &= ~0x01000000;
            sub->f10 -= 0.32666668f;
            obj->f28 += sub->f10 * 0.033333335f;
            func_8005E900(obj);
        }
        break;
    }
    if (func_8005E4C8(obj) != 0) {
        if (sub->b2D == 0) {
            obj->w60 |= 1;
        } else {
            sub->h30 = 0;
        }
    }
    if (sub->b2E != 0 && (sub->h26 == 0 || gBorderSkipFlag != 0)) {
        if (sub->w18 > 0) {
            if (--sub->w18 == 0) {
                obj->b7E = 0x10;
                obj->b82 = 0xFF;
            }
        } else if (obj->b82 != 0) {
            obj->b82--;
        } else {
            if (D_801002A0 == 8) {
                switch (sub->h28) {
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
            obj->w60 |= 1;
        }
    }
}
