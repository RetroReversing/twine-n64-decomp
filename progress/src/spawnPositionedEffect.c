extern int sLastEffectPos;
void *spawnEffectObject();
s32 actorLinkToSurface();
s32 effectSetAnimFrame();
extern s32 *gDefaultOrderObj;
extern u8 gSceneType;

typedef struct { s32 v[3]; } EffectPos;
typedef struct { u8 pad_0[84]; f32 scale; u8 pad_58[4]; s32 flags; u8 pad_60[24]; s16 field_78; s16 field_7A; u8 pad_7C[2]; s8 field_7E; s8 field_7F; s8 field_80; s8 field_81; u8 field_82; } EffectObj;

/* Spawns an effect at pos, remembers pos in sLastEffectPos, and if it spawned, sets its animation, scale and flags. */
void *spawnPositionedEffect(f32 * pos, f32 * effectType, u16 scale) {
    void *effect;

    if ((u32) (gSceneType - 4) >= 2U) {
        return NULL;
    }
    effect = spawnEffectObject(0, pos, effectType);
    *(EffectPos *) &sLastEffectPos = *(EffectPos *) pos;
    if ((s32)effect != NULL) {
        effectSetAnimFrame(effect, 0, 0xF4);
        ((EffectObj*)effect)->scale = (f32) (scale & 0xFFFF);
        ((EffectObj*)effect)->field_78 = 0x29;
        ((EffectObj*)effect)->field_7F = 0;
        ((EffectObj*)effect)->field_7E = 3;
        ((EffectObj*)effect)->field_82 = 0x80;
        ((EffectObj*)effect)->field_80 = 0;
        ((EffectObj*)effect)->field_81 = 0;
        ((EffectObj*)effect)->field_7A = 0;
        ((EffectObj*)effect)->flags &= ~0x200;
        actorLinkToSurface(*gDefaultOrderObj, effect, 1);
    }
    return effect;
}
