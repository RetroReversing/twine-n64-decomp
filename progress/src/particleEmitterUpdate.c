/* Updates one particle-emitter instance each frame: ages it, respawns it when its timer runs out, and otherwise moves it and spawns trail effects. */

s32 vec3Add();
s32 randomIntBelow();
f32 randomFloatScaled(f32);
s32 func_8005D444(void *, void *, f32, s32, s32, s32);
void *spawnConfiguredEffect(void *, void*, void*, void *, f32, f32, s32, s32, s32, u32, u32);
extern f64 D_800D4150;
extern f64 D_800D4158;
extern f64 D_800D4160;

typedef struct { unsigned char pad_0[4]; float field_4; float field_8; float field_C; unsigned char pad_10[12]; short field_1C; } ParticleState;
typedef struct { unsigned char pad_0[32]; void * field_20; float field_24; float field_28; float field_2C; unsigned char pad_30[36]; float field_54; unsigned char pad_58[8]; int field_60; unsigned char pad_64[8]; void * field_6C; unsigned char pad_70[16]; unsigned char field_80; unsigned char field_81; } ParticleEmitter;
void particleEmitterUpdate(void *emitter) {
char *ownerPosAddr;

    void *pos;
    s16 timer;
    void *effectPos;
    register void *owner;
    unsigned ttl;
    f32 ownerY;
    void *state;

    state = (((ParticleEmitter*)emitter)->field_6C);
    ttl = (((ParticleEmitter*)emitter)->field_81) - 1;
    (*(u8 *)((char *)(emitter) + (unsigned short)0x7F)) += 1;
    (((ParticleEmitter*)emitter)->field_80) += 1;
    (((ParticleEmitter*)emitter)->field_81) = ttl;
    timer = (((ParticleState*)state)->field_1C);
    owner = (((ParticleEmitter*)emitter)->field_20);
    if (timer > 0) {
        (((ParticleState*)state)->field_1C) = (s16) (timer - 1);
        goto alive;
    }
    if (randomIntBelow(4) == 0) {
        func_8005D444(emitter, emitter + 0x24, 2.0f, 2, 0x16, 0xFB);
    }
    (((ParticleEmitter*)emitter)->field_60) |= 1;
    return;

    alive:;
ownerPosAddr = (char *)((char *)((*(void **)((char *)(owner) + 0x3C))) + 0x20);

        ownerY = (*(f32 *)(ownerPosAddr));
        if ((((ParticleEmitter*)emitter)->field_28) < ownerY) {
            (((ParticleEmitter*)emitter)->field_28) = ownerY;
            (((ParticleState*)state)->field_4) = (f32) ((((ParticleState*)state)->field_4) * (randomFloatScaled(0.9f) - 0.45f));
            (((ParticleState*)state)->field_8) = (f32) ((f64) (((ParticleState*)state)->field_8) * D_800D4150);
            (*(f32 *)((char *)(state) + 0xC)) = (f32) ((((ParticleState*)state)->field_C) * (randomFloatScaled(0.9f) - 0.45f));
            (((ParticleEmitter*)emitter)->field_54) = (f32) ((f64) (((ParticleEmitter*)emitter)->field_54) * D_800D4158);
        }
        (((ParticleEmitter*)emitter)->field_24) += ((((ParticleState*)state)->field_4) * 0.033333335f);
        (((ParticleEmitter*)emitter)->field_28) += ((((ParticleState*)state)->field_8) * 0.033333335f);
        pos = emitter + 0x3C;
        (((ParticleEmitter*)emitter)->field_2C) += ((((ParticleState*)state)->field_C) * 0.033333335f);
        (((ParticleState*)state)->field_8) = (f32) ((f64) (((ParticleState*)state)->field_8) - D_800D4160);
        vec3Add(state + 0x10, pos, pos);
        if ((((ParticleEmitter*)emitter)->field_28) < (*(f32 *)((char *)((*(void **)((char *)(owner) + 0x20))) + 0x5C))) {
            effectPos = emitter + 0x24;
            spawnConfiguredEffect((((ParticleEmitter*)emitter)->field_20), effectPos, pos, 0, 0.1f, 1.01f, 0x19, 0xFB, 0x17, 0x80, 0x80808002);
            spawnConfiguredEffect((((ParticleEmitter*)emitter)->field_20), effectPos, NULL, 0, 0.25f, randomFloatScaled(0.05f) + 1.05f, 0x1C, 0x1B, 0x2C, 0x40008080, 0x80808008);
            (((ParticleEmitter*)emitter)->field_60) |= 1;
        }
    
}
