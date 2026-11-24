typedef struct { s32 x, y, z; } EffectVec;
extern void prepareCameraPathKeys(void *, s32, f32);
extern void initBurstParticles(void *);
extern void effectSetAnimFrame(void *, s32, s32);
extern void *spawnEffectObject(s32, s32, s32);
extern u8 D_800B21CF, D_800B241F;
#define FIELD(type, ptr, off) (*(type *)((ptr) + (off)))
/* Spawns an effect object with six child segment objects, positioned either from a path or from pos/rot, and initialises its state. */ void *spawnChainedEffect(EffectVec *pos, EffectVec *rot, char *params, char *pathData, s32 pathId)
{
    char *effect = spawnEffectObject(0x4C, 0, 0);
    char *effectState;
    s16 segmentType;
    char *segment;
    unsigned i;
    if (effect != NULL) {
        effectState = FIELD(char *, effect, 0x6C);
        FIELD(u8, effectState, 0x44) = FIELD(u16, params, 0x2C);
        FIELD(u8, effectState, 0x45) = FIELD(u16, params, 0x2E);
        FIELD(u8, effectState, 0x46) = FIELD(u16, params, 0x30);
        FIELD(u8, effectState, 0x47) = FIELD(u16, params, 0x32);
        FIELD(u8, effectState, 0x48) = FIELD(u16, params, 0x34);
        FIELD(u8, effectState, 0x49) = FIELD(u16, params, 0x36);
        FIELD(u8, effectState, 0x4A) = FIELD(u16, params, 0x38);
        FIELD(char *, effectState, 0x1C) = pathData;
        FIELD(u8, effectState, 0x4B) = FIELD(u16, params, 0x40);
        if (pathData != NULL) {
            FIELD(s16, effectState, 0x28) = pathId;
            FIELD(s16, effectState, 0x2A) = 0;
            FIELD(s32, effectState, 0x20) = 0;
            FIELD(f32, effectState, 0x24) = 0.01f;
            prepareCameraPathKeys(effectState + 0x1C, 1, 2.1f);
            FIELD(EffectVec, effect, 0x30) = FIELD(EffectVec, FIELD(char *, effectState, 0x1C), 0);
            FIELD(EffectVec, effect, 0x24) = FIELD(EffectVec, effect, 0x30);
            FIELD(EffectVec, effect, 0x48) = FIELD(EffectVec, FIELD(char *, effectState, 0x1C), 0xC);
        } else {
            FIELD(EffectVec, effect, 0x30) = *pos;
            FIELD(EffectVec, effect, 0x24) = FIELD(EffectVec, effect, 0x30);
            FIELD(EffectVec, effect, 0x48) = *rot;
        }
        FIELD(EffectVec, effect, 0x3C) = FIELD(EffectVec, effect, 0x48);
        FIELD(s16, effect, 0x78) = 0x3B;
        FIELD(s16, effect, 0x7A) = 0;
        FIELD(s16, effect, 0x7C) = 0;
        effectSetAnimFrame(effect, FIELD(u16, params, 0), *FIELD(s16 *, params, 0x28));
        i = 0;
        segmentType = 0x30;
        FIELD(s32, effect, 0x5C) |= 0x600;
        FIELD(s32, effect, 0x58) |= 0x20000;
        pathData = effectState;
        do {
            segment = spawnEffectObject(0, 0, 0);
            FIELD(char *, pathData, 0x2C) = segment;
            if (segment != NULL) {
                FIELD(char *, segment, 0x18) = effect;
                FIELD(s16, segment, 0x78) = segmentType;
                FIELD(s32, segment, 0x5C) |= 0x600;
                effectSetAnimFrame(segment, 3, *FIELD(s16 *, params, 0x28));
            }
            i++;
            pathData += 4;
        } while (i < 6);
        initBurstParticles(effect);
        FIELD(s16, effectState, 0x14) = 0x1EF;
        FIELD(u8, effectState, 0x19) = 0xFF;
        FIELD(u8, effectState, 0x18) = 0;
        FIELD(u8, effectState, 0x16) = 0;
        FIELD(u8, effectState, 0x17) = 0;
        FIELD(u8, effectState, 0x1A) = 1;
        FIELD(f32, effectState, 0xC) = D_800B21CF;
        FIELD(f32, effectState, 0x10) = D_800B241F;
        FIELD(s32, effectState, 0) = -1;
        FIELD(f32, effectState, 4) = 1000.0f;
        FIELD(f32, effectState, 8) = 1000.0f;
    }
    return effect;
}
