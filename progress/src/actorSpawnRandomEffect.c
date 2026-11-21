void *spawnEffectObject();
s32 objectListInsert();
s32 objectSetAnimFrame();
s32 randomIntBelow();
f32 randomFloatScaled(f32);
f32 randomFloatMinusOffset(f32, f32);

/* Occasionally spawns a small effect object near an actor that is in a flagged state, then clears the actor's effect trigger flags. */
void actorSpawnRandomEffect(void *actor) {
    struct Vec3 {
        f32 x, y, z;
    } pos;
    void *effectParams;
    void *effect;
    void *effectState;

    effectParams = *(void **)((char *)actor + 0x6C);
    if ((*(s32 *)((char *)actor + 0x58) & 4 || *(s32 *)((char *)actor + 0x60) & 0x3000) && randomIntBelow(*(s16 *)((char *)actor + 0x7C)) == 0) {
        pos = *(struct Vec3 *)((char *)actor + 0x24);
        pos.x += randomFloatMinusOffset(2.0f, 1.0f) * *(f32 *)effectParams;
        pos.z += randomFloatMinusOffset(2.0f, 1.0f) * *(f32 *)effectParams;
        effect = spawnEffectObject(0xC, &pos, 0);
        if (effect != 0) {
            effectState = *(void **)((char *)effect + 0x6C);
            objectSetAnimFrame(effect, 2, 0x1B);
            *(f32 *)((char *)effectState + 4) = *(f32 *)((char *)effectParams + 4);
            *(f32 *)((char *)effectState + 8) = -randomFloatScaled(0.32666668f);
            *(s16 *)((char *)effect + 0x78) = 0x65;
            *(s8 *)((char *)effect + 0x7F) = 0;
            *(s8 *)((char *)effect + 0x80) = 0;
            *(s8 *)((char *)effect + 0x81) = 0;
            *(s8 *)((char *)effect + 0x82) = 0x40;
            objectListInsert(effect, *(s32 *)((char *)actor + 0x20));
        }
    }
    *(s32 *)((char *)actor + 0x60) = 0;
}
