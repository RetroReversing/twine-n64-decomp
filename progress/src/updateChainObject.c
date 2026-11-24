typedef struct { f32 x, y, z; } Vec3;
typedef struct { Vec3 *pts; f32 pad4; f32 y; u16 flags; u8 padE[0x2A]; f32 off; u8 pad3C[0x77]; s8 count; } Inner;
typedef struct { u8 pad[0xCC]; f32 vel; } Inner2;
typedef struct { u8 pad0[0x24]; Vec3 pos; u8 pad30[0x38]; Inner *in; Inner2 *in2; } Obj;
s32 func_80048F10(s32, Vec3 *, f32 *, u8 *, f32, u8 *, u8 *, s32);
s32 pushSphereOutOfSurfaces(s32, Vec3 *, char *, f32, s32, s32, s32, s32);

/* Updates a chain object: applies gravity, snaps it to the ground, then pushes its active links out of collision. */
void updateChainObject(s32 probeCtx, Obj *obj, s32 colArg2, s32 colArg3) {
    f32 pushOffset[3];
    char probeName[0x10];
    f32 groundPos[3];
    u8 probeOut1[0x10], probeOut2[0x10], probeOut3[0x10];
    Vec3 probeOrigin, linkPos, linkPosBase;
    Inner2 *in2 = obj->in2;
    s32 i;
    f32 t;
    in2->vel -= 0.32666668f;
    obj->pos.y += in2->vel * 0.033333335f;
    obj->in->flags &= 0xFF77;
    probeOrigin = obj->pos;
    probeOrigin.y += 1.0f;
    if ((func_80048F10(probeCtx, &obj->pos, groundPos, probeOut1, 250.0f, probeOut2, probeOut3, 0) << 24) == 0) {
        groundPos[0] = obj->pos.x;
        groundPos[1] = obj->in->y;
        groundPos[2] = obj->pos.z;
    }
    obj->in->y = groundPos[1];
    t = groundPos[1] + obj->in->off;
    if (obj->pos.y <= t) {
        obj->pos.y = t;
        in2->vel = 0.0f;
    }
    pushOffset[0] = 0.0f;
    pushOffset[1] = 0.0f;
    pushOffset[2] = 0.0f;
    for (i = 0; i < obj->in->count; i++) {
        switch (i) {
        case 0: case 1: case 2: case 3: case 4: case 5: case 6:
            break;
        case 8: case 9: case 10: case 11: case 12: case 13:
            break;
        case 7:
        case 14:
            linkPosBase.x = obj->in->pts[i].x + pushOffset[0];
            linkPos.x = linkPosBase.x;
            linkPosBase.y = obj->in->pts[i].y + pushOffset[1];
            linkPos.y = linkPosBase.y;
            linkPosBase.z = obj->in->pts[i].z + pushOffset[2];
            linkPos.z = linkPosBase.z;
            if ((pushSphereOutOfSurfaces(probeCtx, &linkPos, probeName, 0.2f, 0x10, colArg2, colArg3, 0) << 24) != 0) {
                pushOffset[0] += linkPos.x - linkPosBase.x;
                pushOffset[1] += linkPos.y - linkPosBase.y;
                pushOffset[2] += linkPos.z - linkPosBase.z;
            }
            break;
        }
    }
    obj->pos.x += pushOffset[0];
    obj->pos.y += pushOffset[1];
    obj->pos.z += pushOffset[2];
}

const u32 D_800D46E4 = 0xA0;
