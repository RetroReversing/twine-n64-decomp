s32 func_80044670();
s32 func_80045CF8();
s32 func_80045DB4(f32 *, f32, f32);
s32 func_80055568();
s32 func_800617D8(s32, void *, s32, f32 *, f32, f32, s32, s32, s32, s32, s32);
s32 func_80062450();
extern s32 gBorderSkipFlag;

typedef struct { u8 pad_0[0x20]; s32 field_20; u8 pad_24[0x3C]; s32 field_60; u8 pad_64[0x16]; s16 field_7A; } Obj62F34;

void func_80062F34(Obj62F34 *arg0) {
    f32 v[3];
    s16 t;

    t = ++arg0->field_7A;
    if (t >= 0x2C) {
        if (t >= func_80045CF8(0x1E) + 0x1E) {
            func_80055568(arg0, (u8 *)arg0 + 0x24);
            arg0->field_60 |= 1;
        }
    } else {
        func_80044670(arg0, t >> 1, 0xFB);
    }
    if (gBorderSkipFlag == 0) {
        if (!(arg0->field_7A & 1) && arg0->field_7A < 0x16) {
            f32 zero = 0.0f;
            v[2] = zero;
            v[1] = zero;
            v[0] = zero;
            func_80045DB4(v, 0.4f, 0.2f);
            if (v[1] < zero) {
                v[1] = -v[1];
            }
            func_80062450(func_800617D8(arg0->field_20, (u8 *)arg0 + 0x24, 0, v, 1.0f, zero, func_80045CF8(1) + 0x17, 0xFB, 0x33, 0xFF0000FF, 6), v);
        }
    }
}
