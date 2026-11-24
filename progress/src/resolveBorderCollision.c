/* machine draft (m2c) for gcc-2.7.2-kmc -G0 -mips3 -mgp32 -mfp32 -O2, tried by autopilot */
#ifndef M2C_DEFINES
#define M2C_DEFINES
typedef s32 M2C_UNK;
typedef s8 M2C_UNK8;
typedef s16 M2C_UNK16;
typedef s32 M2C_UNK32;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define M2C_CARRY 0
#define M2C_OVERFLOW(a) (0)
#endif

s32 raycastThroughRooms(void *, s32, s32, M2C_UNK *, s32, s32, s32, s32, s32); /* extern */
M2C_UNK scaleVec2(f32 *, f32, f32);             /* extern */
s32 getBindingAxisValueAlt(s8, M2C_UNK);                     /* extern */
f32 absFloat(f32);                             /* extern */
M2C_UNK multiplyMat3ByVec3(void *, M2C_UNK32 *, f32 *);  /* extern */
extern f32 D_800C7C98;
extern s32 gBorderSkipActive;
extern s32 gGameMode;

/* Checks whether an actor has crossed a track border and, if so, pushes its contact point and height back into the actor. */ void resolveBorderCollision(void *actor, void *other) {
    union { f32 f[3]; M2C_UNK32 w[3]; } in;
#define sp28 in.w[0]
#define sp2C in.f[1]
#define sp30 in.w[2]
    f32 out[3];
#define sp38 out[0]
#define sp3C out[1]
#define sp40 out[2]
    struct { M2C_UNK sp48; u32 padding[2]; } local;
#define sp48 local.sp48
    f32 newDist, height;
    s32 gameMode;
    f32 lateral;
    f32 lateralLimit;
    f32 lateralRef;
    f32 forwardLimit;
    s32 flags;
    s32 borderType;
    s32 var_v0;
    u16 state;
    u8 temp_a0_2;
    s32 borderIndex;
    void *trackData;
    void *borderData;
    void *track;
    void *temp_v0;
    void *borderObj;

    flags = M2C_FIELD(other, s32 *, 0x58);
    if ((flags & 0x400) && !(M2C_FIELD(other, s32 *, 0x58) & 0x1000) && (track = M2C_FIELD(actor, void **, 0x138), (track != NULL))) {
        forwardLimit = 2.0f;
        lateralLimit = 1.0f;
        trackData = M2C_FIELD(track, void **, 0x6C);
        borderObj = NULL;
        if (gGameMode == 0x19) {
            lateral = M2C_FIELD(actor, f32 *, 0x58) * M2C_FIELD(trackData, f32 *, 0x20);
            lateralLimit = 8.0f;
            forwardLimit = 8.0f;
            lateralRef = M2C_FIELD(actor, f32 *, 0x50) * -M2C_FIELD(trackData, f32 *, 0x1C);
            goto block_7;
        }
        if (!(M2C_FIELD(M2C_FIELD(track, void **, 0x68), u16 *, 0xC) & 1)) {
            lateral = 0.0f;
            lateralRef = 0.0f;
block_7:
            state = M2C_FIELD(other, u16 *, 0x78);
            if ((state == 1) || (state == 0x4C)) {
                borderObj = M2C_FIELD(other, void **, 0x6C);
                if ((getBindingAxisValueAlt(M2C_FIELD(trackData, s8 *, 0x182), 0xE) == 0) && (M2C_FIELD(other, u16 *, 0x78) == 0x4C)) {
                    M2C_FIELD(other, f32 *, 0x74) = -30.0f;
                }
                if (!(M2C_FIELD(other, f32 *, 0x74) <= -30.0f) && (M2C_FIELD(other, s16 *, 0x7A) != 0x75)) {
                    goto block_16;
                }
            } else if (state == 0x4D) { return; } else if (state == 0x61) { return; } else {
block_16:
                if ((borderObj == NULL) || (borderType = ((u32) M2C_FIELD(borderObj, u32 *, 0x88) >> 0x15) & 0xF, (borderType == 1)) || (borderType == 4)) {
                    if (gBorderSkipActive != 0) {
                        if (((u32) (M2C_FIELD(other, u16 *, 0x78) - 2) < 2U) && (temp_a0_2 = M2C_FIELD(M2C_FIELD(M2C_FIELD(track, void **, 0x6C), void **, 0xB4), u8 *, 0x12), borderData = M2C_FIELD(other, void **, 0x6C), (temp_a0_2 != 2))) {
                            if (temp_a0_2 != M2C_FIELD(M2C_FIELD(borderData, void **, 0xB4), u8 *, 0x12)) {
                                goto block_29;
                            }
                        } else {
                            goto block_29;
                        }
                    } else {
                        borderIndex = M2C_FIELD(M2C_FIELD(other, void **, 0x68), u8 *, 0xB1);
                        if ((s32) borderIndex < 0x3C) {
                            if ((s32) borderIndex >= 0x3A) {
                                return;
                            }
                            var_v0 = 6;
                            goto block_28;
                        } else {
                            var_v0 = 0x61;
block_28:
                            if (borderIndex != var_v0) {
block_29:
                                in.f[0] = M2C_FIELD(other, f32 *, 0x24);
                                temp_v0 = M2C_FIELD(M2C_FIELD(other, void **, 0x68), void **, 0);
                                sp2C = (M2C_FIELD(temp_v0, f32 *, 0x58) + M2C_FIELD(temp_v0, f32 *, 0xAC)) * 0.5f;
                                in.f[2] = M2C_FIELD(other, f32 *, 0x2C);
                                multiplyMat3ByVec3(actor + 0x88, &sp28, &sp38);
                                sp38 += M2C_FIELD(actor, f32 *, 0xAC);
                                sp3C += M2C_FIELD(actor, f32 *, 0xB0);
                                newDist = sp40 + M2C_FIELD(actor, f32 *, 0xB4);
                                sp40 = newDist;
                                if ((newDist > 0.0f) && (newDist < M2C_FIELD(actor, f32 *, 0x11C)) && (scaleVec2(&sp38, M2C_FIELD(actor, f32 *, 0x68) / newDist, M2C_FIELD(actor, f32 *, 0x6C) / newDist), (lateral = sp3C - lateral, absFloat(sp38 - lateralRef) < (M2C_FIELD(actor, f32 *, 0x54) / forwardLimit))) && (absFloat(lateral) < (M2C_FIELD(actor, f32 *, 0x5C) / lateralLimit)) && ((raycastThroughRooms(actor + 0x10, M2C_FIELD(M2C_FIELD(other, void **, 0x68), s32 *, 4) + 0xA8, M2C_FIELD(actor, s32 *, 0xF4), &sp48, 0, 0, 0, 1, 0) << 0x18) != 0)) {
                                    M2C_FIELD(actor, f32 *, 0x11C) = sp40;
                                    { struct vec { u32 x, y, z; }; *(struct vec *)((s8 *)actor + 0x104) = *(struct vec *)&in; }
                                    height = sp3C;
                                    gameMode = gGameMode;
                                    M2C_FIELD(actor, f32 *, 0x114) = height;
                                    if (gameMode == 0x19 || sp40 < D_800C7C98) {
                                        M2C_FIELD(actor, f32 *, 0x110) = sp38;
                                    } else {
                                        M2C_FIELD(actor, f32 *, 0x110) = 0.0f;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}


