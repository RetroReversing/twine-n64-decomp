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

M2C_UNK spawnConfiguredEffect(void *, void *, M2C_UNK, M2C_UNK, f32, f32, s32, s32, s32, s32, s32); /* extern */

/* Applies gravity to the object's vertical velocity, integrates its height, and clamps it to the floor. */
void updateFallingObjectHeight(void *obj) {
    f32 velocityY;
    f32 velocityDelta;
    f32 newHeight;
    f32 minHeight;
    s16 hitFlag;
    void *state;
    void *parent;

    state = M2C_FIELD(obj, void **, 0x6C);
    velocityY = M2C_FIELD(state, f32 *, 8);
    parent = M2C_FIELD(obj, void **, 0x20);
    hitFlag = 0;
    if (velocityY > -6.533334f) {
        M2C_FIELD(state, f32 *, 8) = (f32) (velocityY - 0.32666668f);
    }
    newHeight = M2C_FIELD(obj, f32 *, 0x28) + (M2C_FIELD(state, f32 *, 8) * 0.033333335f);
    M2C_FIELD(obj, f32 *, 0x28) = newHeight;
    minHeight = M2C_FIELD(state, f32 *, 4);
    if (newHeight < minHeight) {
        M2C_FIELD(obj, f32 *, 0x28) = minHeight;
        hitFlag = 1;
    }
    if (parent != NULL) {
        velocityDelta = M2C_FIELD(M2C_FIELD(parent, void **, 0x20), f32 *, 0x5C);
        if (M2C_FIELD(obj, f32 *, 0x28) < velocityDelta) {
            M2C_FIELD(obj, f32 *, 0x28) = velocityDelta;
            hitFlag = 1;
        }
    } else {
        hitFlag = 1;
    }
    if (hitFlag != 0) {
        spawnConfiguredEffect(M2C_FIELD(obj, void **, 0x20), obj + 0x24, 0, 0, 0.25f, 1.05f, 0x1C, 0x1B, 0x2C, 0x40008080, 0x80808008);
        M2C_FIELD(obj, s32 *, 0x60) = (s32) (M2C_FIELD(obj, s32 *, 0x60) | 1);
    }
    if (parent == NULL) {
        M2C_FIELD(obj, s32 *, 0x60) = (s32) (M2C_FIELD(obj, s32 *, 0x60) | 1);
        return;
    }
    M2C_FIELD(obj, s32 *, 0x58) = (s32) (M2C_FIELD(obj, s32 *, 0x58) | 1);
}
