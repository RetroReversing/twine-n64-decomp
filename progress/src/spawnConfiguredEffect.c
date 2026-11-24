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

typedef struct { f32 x, y, z; } Point3;

void *spawnEffectObject();
s32 objectListInsert();
s32 actorLinkToSurface();
s32 effectSetAnimFrame();
s32 clearVec3();
extern s32 *gDefaultOrderObj;

/* Spawns an effect object, copies its position and colour/alpha parameters, and links it into the object list (arg0 != 0) or the probe list. */
void *spawnConfiguredEffect(s32 listIndex, s32 arg1, s32 arg2, Point3 *pos, f32 scale, f32 arg5, s32 animArg6, s32 animArg7, s32 arg8, u32 colorRgba, u32 colorTint) {
    Point3 *effectState;
    void *effect;

    if (listIndex == 0) {
        return NULL;
    }
    effect = spawnEffectObject(0x2C, arg1, arg2);
    if (effect != NULL) {
        effectState = M2C_FIELD(effect, Point3 **, 0x6C);
        if (pos == NULL) {
            clearVec3(effectState);
        } else {
            *effectState = *pos;
        }
        M2C_FIELD(effect, s16 *, 0x78) = (s16) arg8;
        M2C_FIELD(effect, f32 *, 0x54) = scale;
        M2C_FIELD(effectState, f32 *, 0x14) = arg5;
        M2C_FIELD(effect, s8 *, 0x7F) = (s8) (colorRgba >> 0x18);
        M2C_FIELD(effect, s8 *, 0x80) = (s8) (colorRgba >> 0x10);
        M2C_FIELD(effect, s8 *, 0x81) = (s8) (colorRgba >> 8);
        M2C_FIELD(effect, s8 *, 0x82) = (s8) colorRgba;
        M2C_FIELD(effectState, s8 *, 0x23) = (s8) ((colorTint >> 0x18) + 0x80);
        M2C_FIELD(effectState, s8 *, 0x24) = (s8) ((colorTint >> 0x10) + 0x80);
        M2C_FIELD(effectState, s8 *, 0x25) = (s8) ((colorTint >> 8) + 0x80);
        M2C_FIELD(effectState, s8 *, 0x26) = (s8) colorTint;
        effectSetAnimFrame(effect, animArg6, animArg7);
        if (listIndex != 0) {
            objectListInsert(effect, listIndex);
            return effect;
        }
        actorLinkToSurface(*gDefaultOrderObj, effect, 1);
        goto block_9;
    }
block_9:
    return effect;
}
