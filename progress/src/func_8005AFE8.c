
typedef struct Pose5A { f32 x,y,z; } Pose5A;
typedef struct Placement5A { Pose5A position, rotation; } Placement5A;
typedef struct EffectState5A {
    s32 link;
    f32 minA,minB,nearRange,farRange;
    u16 distance;
    volatile u8 field16,field17,field18,field19,field1A;
    u8 pad1B;
    Placement5A *placement;
    s32 field20;
    f32 rate;
    s16 owner,field2A;
    f32 inverseLife;
    u8 field30,field31;
    volatile u8 field32,field33;
} EffectState5A;
typedef struct Effect5A {
    u8 pad[0x24];
    Pose5A previousPosition, position, previousRotation, rotation;
    u32 field54, flags58, flags5C;
    u8 pad60[0xC];
    EffectState5A *state;
    u8 pad70[8];
    s16 field78,field7A,field7C;
} Effect5A;
typedef struct EffectParams5A {
    u16 animation,field2,life;
    u8 pad6[0x22];
    s16 *frame;
    u16 field2C,field2E,distance,field32,field34,field36,field38;
} EffectParams5A;
extern Effect5A *spawnEffectObject();
extern void func_80076340();
extern void effectSetAnimFrame();
extern void actorLinkToSurface();
extern void **gProbeObjectList;
extern u8 sDistanceNearRange[], sDistanceFarRange[];
Effect5A *func_8005AFE8(EffectParams5A *params, Placement5A *placement, s32 owner) {
    Effect5A *effect = spawnEffectObject(0x34, 0, 0);
    if (effect) {
        EffectState5A *state = effect->state;
        f32 inverseLife;
        f32 farRange;
        u16 field33, distance;
        state->field30 = params->field2C;
        state->field31 = params->field38;
        if (!params->life)
            params->life = 240;
        inverseLife = 1.0f / params->life;
        state->placement = placement;
        state->owner = owner;
        state->field2A = 0;
        state->field20 = 0;
        state->rate = 0.01f;
        state->inverseLife = inverseLife;
        state->field32 = params->field2E;
        field33 = params->field32;
        state->field18 = 0;
        state->field33 = field33;
        distance = params->distance;
        state->field19 = 255;
        state->field16 = 0;
        state->field17 = 0;
        state->field1A = 1;
        state->distance = distance;
        state->nearRange = sDistanceNearRange[params->distance];
        farRange = sDistanceFarRange[params->distance];
        state->link = -1;
        state->minA = 1000.0f;
        state->minB = 1000.0f;
        state->farRange = farRange;
        func_80076340(&state->placement, 0, 0);
        effect->field78 = 63;
        effect->field7A = 0;
        effect->field7C = 0;
        effectSetAnimFrame(effect, params->animation, *params->frame);
        effect->position = state->placement->position;
        effect->previousPosition = effect->position;
        effect->rotation = state->placement->rotation;
        effect->previousRotation = effect->rotation;
        effect->flags5C |= 0x600;
        effect->flags58 |= 0x20000;
        actorLinkToSurface(*gProbeObjectList, effect, 0);
    }
    return effect;
}
