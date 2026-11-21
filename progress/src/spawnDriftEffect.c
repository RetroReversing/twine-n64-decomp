typedef struct { f32 x, y, z; } V61578;
typedef struct { V61578 pos; s32 c; u8 pad[0xC]; unsigned hi:12; unsigned mid:16; unsigned lo:4; } P61578;
typedef struct { u8 pad0[0x20]; s32 v20; u8 pad24[0x20]; f32 f44; u8 pad48[0xC]; f32 f54; u8 pad58[0x14]; P61578 *p; u8 pad70[8]; s16 t78; u8 pad7A[5]; u8 c7F, c80, c81, c82; } O61578;
void *spawnEffectObject(s32, s32, s32);
void objectListInsert(O61578 *, s32);
void effectSetAnimFrame(O61578 *, s32, s32);
u32 randomIntBelow(s32);
f32 randomFloatScaled(f32);

/* Spawns a drift effect object seeded from the source effect's position, with a jittered
 * velocity, random spin and a short lifetime, then links it into the object list. */
void spawnDriftEffect(O61578 *srcEffect, s32 arg1) {
    O61578 *o = spawnEffectObject(0x2C, arg1, 0);
    P61578 *p;
    P61578 *src;

    if (o != NULL) {
        p = o->p;
        src = srcEffect->p;
        o->t78 = 0x14;
        p->pos = src->pos;
        p->pos.x = p->pos.x * 0.06f + randomFloatScaled(0.02f) - 0.01f;
        p->pos.y = p->pos.y * 0.06f + randomFloatScaled(0.02f) - 0.01f;
        p->pos.z = p->pos.z * 0.06f + randomFloatScaled(0.02f) - 0.01f;
        o->f44 = randomIntBelow(0x1000);
        o->f54 = 0.2f;
        p->c = 0x20;
        o->c82 = 0xFF;
        o->c7F = srcEffect->c7F;
        o->c80 = srcEffect->c80;
        o->c81 = srcEffect->c81;
        effectSetAnimFrame(o, src->mid, src->hi);
        objectListInsert(o, srcEffect->v20);
    }
}
