s32 effectSetAnimFrame();
s32 randomIntBelow();
s32 addRandomJitterVec3(f32 *, f32, f32);
s32 updateNearestTargets();
s32 spawnConfiguredEffect(s32, void *, s32, f32 *, f32, f32, s32, s32, s32, s32, s32);
s32 func_80062450();
extern s32 gBorderSkipActive;

typedef struct { u8 pad_0[0x20]; s32 field_20; u8 pad_24[0x3C]; s32 field_60; u8 pad_64[0x16]; s16 field_7A; } Obj62F34;

void actorUpdateSparkEmitter(Obj62F34 *arg0) {
    f32 v[3];
    s16 t;

    t = ++arg0->field_7A;
    if (t >= 0x2C) {
        if (t >= randomIntBelow(0x1E) + 0x1E) {
            updateNearestTargets(arg0, (u8 *)arg0 + 0x24);
            arg0->field_60 |= 1;
        }
    } else {
        effectSetAnimFrame(arg0, t >> 1, 0xFB);
    }
    if (gBorderSkipActive == 0) {
        if (!(arg0->field_7A & 1) && arg0->field_7A < 0x16) {
            f32 zero = 0.0f;
            v[2] = zero;
            v[1] = zero;
            v[0] = zero;
            addRandomJitterVec3(v, 0.4f, 0.2f);
            if (v[1] < zero) {
                v[1] = -v[1];
            }
            func_80062450(spawnConfiguredEffect(arg0->field_20, (u8 *)arg0 + 0x24, 0, v, 1.0f, zero, randomIntBelow(1) + 0x17, 0xFB, 0x33, 0xFF0000FF, 6), v);
        }
    }
}
