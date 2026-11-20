typedef struct TwineMover76B30 {
    u8 pad0[0x24];
    f32 pos[3];
    u8 pad30[0x38];
    u8 *ptr68;
    u8 *ptr6C;
    u8 pad70[0xA];
    s16 state7A;
    s16 state7C;
} TwineMover76B30;

s32 func_80002BD0(void *, s32);
f32 Vec3_DistanceSq(void *, void *);
s32 func_80045CF8(s32);
s32 func_80077960(void *, s32);
s32 func_80077A94(void *);

void func_80076B30(TwineMover76B30 *arg0) {
    f32 dist;
    s32 var_s0;
    u8 *s2;
    s16 st;

    s2 = arg0->ptr6C;
    st = arg0->state7A;
    if (st == 4) {
        goto block5;
    }
    if (st < 5) {
        if (st == 1) {
            goto block5;
        }
        return;
    }
    if (st != 0x81) {
        return;
    }
block5:
    if (!(*(s32 *)(s2 + 0x88) & 0x40000000)) {
        var_s0 = -1;
        func_80077A94(arg0);
        switch (arg0->state7C) {
        case 2:
        case 4:
        case 5:
        case 6:
        case 7:
        case 8:
        case 9:
        case 10:
        case 11:
        case 12:
            break;
        case 1:
            dist = Vec3_DistanceSq(s2 + 0x50, arg0->pos);
            if (dist < 5.0f) {
                var_s0 = 0x14D;
            } else {
                var_s0 = 0x1DE;
                if (dist < 15.0f) {
                    var_s0 = 0x1DF;
                }
            }
            break;
        case 0:
        case 3:
            if (((s8 *)arg0->ptr68)[0xE] == 0) {
                var_s0 = func_80045CF8(2) + 0x2E9;
            } else {
                var_s0 = func_80045CF8(2) + 0x2ED;
            }
            break;
        }
        if (var_s0 != -1) {
            func_80002BD0(arg0, var_s0);
            func_80077960(arg0, 0xE);
        }
    }
}
