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

void *spawnEffectObject();
s32 actorLinkToSurface();
s32 effectSetAnimFrame();
s8 randomIntBelow();
extern s32 *gDefaultOrderObj;

/* Spawns a probe effect object (kind 0xC) from the descriptor in desc: fills its parameter block, resets its animation state, sets the anim frame and links it to the probe surface. */
void *spawnProbeEffectObject(s32 spawnArg, s32 position, void *desc) {
    u16 descFlags;
    void *paramBlock;
    void *effect;

    effect = spawnEffectObject(0xC, spawnArg, position);
    if (effect != NULL) {
        paramBlock = M2C_FIELD(effect, void **, 0x6C);
        M2C_FIELD(effect, s16 *, 0x78) = 0x53;
        M2C_FIELD(paramBlock, s32 *, 0) = (s32) ((M2C_FIELD(paramBlock, s32 *, 0) & 0xFFFFF) | (*M2C_FIELD(desc, s16 **, 0x28) << 0x14));
        M2C_FIELD(paramBlock, s8 *, 4) = (s8) M2C_FIELD(desc, u16 *, 0x2C);
        M2C_FIELD(paramBlock, s8 *, 5) = (s8) M2C_FIELD(desc, u16 *, 0x2E);
        if (M2C_FIELD(desc, u16 *, 0x30) == 1) {
            M2C_FIELD(paramBlock, s8 *, 8) = 1;
        } else {
            M2C_FIELD(paramBlock, s8 *, 8) = 0;
        }
        descFlags = M2C_FIELD(desc, u16 *, 0);
        M2C_FIELD(paramBlock, s8 *, 7) = (s8) descFlags;
        M2C_FIELD(paramBlock, s8 *, 6) = randomIntBelow(descFlags & 0xFF);
        M2C_FIELD(effect, s16 *, 0x7A) = 0;
        M2C_FIELD(effect, s16 *, 0x7C) = 0;
        M2C_FIELD(effect, u8 *, 0x7F) = 0xFF;
        M2C_FIELD(effect, s8 *, 0x80) = 0;
        M2C_FIELD(effect, s8 *, 0x81) = 0;
        M2C_FIELD(effect, u8 *, 0x82) = 0xFF;
        effectSetAnimFrame(effect, M2C_FIELD(desc, u16 *, 0), *M2C_FIELD(desc, s16 **, 0x28));
        actorLinkToSurface(*gDefaultOrderObj, effect, 1);
    }
    return effect;
}
