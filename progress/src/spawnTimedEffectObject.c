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
s32 setObjectLayerFlag();

/* Spawns an effect object, initialises its fields (0x30 at +0x78, owner, flag 0x80) and passes it to setObjectLayerFlag. Returns NULL if spawn fails. */ void *spawnTimedEffectObject(s32 owner, s32 param) {
    void *effect;

    effect = spawnEffectObject(0, 0, 0);
    if (effect != NULL) {
        M2C_FIELD(effect, s16 *, 0x78) = 0x30;
        M2C_FIELD(effect, s32 *, 0x18) = owner;
        M2C_FIELD(effect, u8 *, 0x7F) = 0x80;
        M2C_FIELD(effect, s8 *, 0x80) = 0;
        M2C_FIELD(effect, s8 *, 0x81) = 0;
        setObjectLayerFlag(effect, param);
    }
    return effect;
}
