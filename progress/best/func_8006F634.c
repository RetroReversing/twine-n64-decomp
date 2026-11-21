typedef struct { f32 x, y, z; } Vec3;
typedef struct { Vec3 *pts; f32 pad4; f32 y; u16 flags; u8 padE[0x2A]; f32 off; u8 pad3C[0x77]; s8 count; } Inner;
typedef struct { u8 pad[0xCC]; f32 vel; } Inner2;
typedef struct { u8 pad0[0x24]; Vec3 pos; u8 pad30[0x38]; Inner *in; Inner2 *in2; } Obj;
s32 func_80048F10(s32, Vec3 *, f32 *, u8 *, f32, u8 *, u8 *, s32);
s32 func_8004FF30(s32, Vec3 *, char *, f32, s32, s32, s32, s32);
void func_8006F634(s32 arg0, Obj *arg1, s32 arg2, s32 arg3) {
    f32 sp20[3];
    char sp30[0x10];
    f32 sp40[3];
    u8 sp50[0x10], sp60[0x10], sp70[0x10];
    Vec3 sp80, sp90, spA0;
    Inner2 *in2 = arg1->in2;
    s32 i;
    f32 t;
    in2->vel -= 0.32666668f;
    arg1->pos.y += in2->vel * 0.033333335f;
    arg1->in->flags &= 0xFF77;
    sp80 = arg1->pos;
    sp80.y += 1.0f;
    if ((func_80048F10(arg0, &arg1->pos, sp40, sp50, 250.0f, sp60, sp70, 0) << 24) == 0) {
        sp40[0] = arg1->pos.x;
        sp40[1] = arg1->in->y;
        sp40[2] = arg1->pos.z;
    }
    arg1->in->y = sp40[1];
    t = sp40[1] + arg1->in->off;
    if (arg1->pos.y <= t) {
        arg1->pos.y = t;
        in2->vel = 0.0f;
    }
    sp20[0] = 0.0f;
    sp20[1] = 0.0f;
    sp20[2] = 0.0f;
    for (i = 0; i < arg1->in->count; i++) {
        switch (i) {
        case 0: case 1: case 2: case 3: case 4: case 5: case 6:
            break;
        case 8: case 9: case 10: case 11: case 12: case 13:
            break;
        case 7:
        case 14:
            spA0.x = arg1->in->pts[i].x + sp20[0];
            sp90.x = spA0.x;
            spA0.y = arg1->in->pts[i].y + sp20[1];
            sp90.y = spA0.y;
            spA0.z = arg1->in->pts[i].z + sp20[2];
            sp90.z = spA0.z;
            if ((func_8004FF30(arg0, &sp90, sp30, 0.2f, 0x10, arg2, arg3, 0) << 24) != 0) {
                sp20[0] += sp90.x - spA0.x;
                sp20[1] += sp90.y - spA0.y;
                sp20[2] += sp90.z - spA0.z;
            }
            break;
        }
    }
    arg1->pos.x += sp20[0];
    arg1->pos.y += sp20[1];
    arg1->pos.z += sp20[2];
}
