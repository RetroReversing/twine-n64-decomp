#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
s32 randomU32Next();
s32 func_80054FEC(s32, f32, f32, void *, void *, s32, s32);
s32 func_8005FBB8(void *);
s32 func_8005FD28(void *);
s32 func_80060968(void *);
s32 func_80060AA8(void *);
s32 func_800624A8(void *, void *, f32, s32);
s32 func_800643C8(void *);
s32 func_800643D8(void *);
s32 func_80073508(void *, f32);
s32 func_800853D4(void *);
/* Per-frame state machine for one falling object: counts down a timer, falls, bounces or launches, and resets when finished. */
void updateObjectFallState(void *obj) {
    f32 newPosY, fallVelY, floorY, posY;
    s16 state;
    s32 flags;
    void *fallState, *launchRec, *bounceRec;

    state = M2C_FIELD(obj, s16 *, 0x7A);
    fallState = M2C_FIELD(obj, void **, 0x6C);
    switch (state) {
    case 0:
        M2C_FIELD(obj, s32 *, 0x60) = M2C_FIELD(obj, s32 *, 0x60) & ~2;
        M2C_FIELD(fallState, s32 *, 0) = M2C_FIELD(fallState, s32 *, 0) + 1;
        func_800643D8(obj);
        if (M2C_FIELD(fallState, s32 *, 0) >= 0x384) {
            func_80060AA8(obj);
            func_800643C8(obj);
            func_8005FBB8(fallState);
            M2C_FIELD(fallState, f32 *, 0x2C) = -4.0f;
            M2C_FIELD(fallState, s32 *, 0) = (u32)randomU32Next() % 450;
            M2C_FIELD(obj, s16 *, 0x7A) = 1;
            return;
        }
    default:
        return;
    case 1:
        M2C_FIELD(obj, f32 *, 0x40) = M2C_FIELD(obj, f32 *, 0x40) + 16.0f;
        newPosY = M2C_FIELD(obj, f32 *, 0x28) + (M2C_FIELD(fallState, f32 *, 0x2C) * 0.033333335f);
        M2C_FIELD(obj, f32 *, 0x28) = newPosY;
        floorY = M2C_FIELD(fallState, f32 *, 0x34);
        if (newPosY < floorY) {
            M2C_FIELD(obj, f32 *, 0x28) = floorY;
            M2C_FIELD(obj, s16 *, 0x7A) = 3;
            func_80060AA8(obj);
        }
        if (M2C_FIELD(obj, s32 *, 0x60) & 2) {
            M2C_FIELD(obj, s16 *, 0x7A) = 2;
            func_80060AA8(obj);
            return;
        }
        break;
    case 2:
        M2C_FIELD(obj, f32 *, 0x40) = M2C_FIELD(obj, f32 *, 0x40) + 32.0f;
        fallVelY = M2C_FIELD(fallState, f32 *, 0x2C) - 0.32666668f;
        M2C_FIELD(fallState, f32 *, 0x2C) = fallVelY;
        M2C_FIELD(obj, f32 *, 0x28) = M2C_FIELD(obj, f32 *, 0x28) + (fallVelY * 0.033333335f);
        if (M2C_FIELD(fallState, f32 *, 0x2C) > 50.0f) {
            M2C_FIELD(fallState, f32 *, 0x2C) = 50.0f;
        }
        posY = M2C_FIELD(obj, f32 *, 0x28);
        if (posY < M2C_FIELD(fallState, f32 *, 0x34)) {
            M2C_FIELD(obj, f32 *, 0x28) = M2C_FIELD(fallState, f32 *, 0x34);
            if (M2C_FIELD(fallState, f32 *, 0x2C) < -10.0f) {
                launchRec = (u8 *)obj + 0x24;
                func_80054FEC(0, 250.0f, 5.0f, obj, launchRec, 0x20, 0);
                func_800624A8(obj, launchRec, 1.0f, 1);
                func_80073508(launchRec, 0.001f);
                func_800853D4(launchRec);
                M2C_FIELD(obj, s16 *, 0x7A) = 4;
                return;
            }
            M2C_FIELD(obj, s16 *, 0x7A) = 3;
            func_80060AA8(obj);
            return;
        }
        break;
    case 3:
        flags = M2C_FIELD(obj, s32 *, 0x60);
        if (flags & 2) {
            bounceRec = (u8 *)obj + 0x24;
            M2C_FIELD(obj, s32 *, 0x60) = flags & ~2;
            func_80054FEC(0, 250.0f, 5.0f, obj, bounceRec, 0x20, 0);
            func_800624A8(obj, bounceRec, 1.0f, 1);
            func_80073508(bounceRec, 0.001f);
            func_800853D4(bounceRec);
            func_80060968(obj);
            break;
        }
        if ((func_8005FD28(obj) << 0x18) != 0) {
    case 4:
            func_80060968(obj);
        }
        break;
    }
}
