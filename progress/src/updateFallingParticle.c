typedef struct ParticleMotion {
    u8 pad0[4];
    f32 velX, velY, velZ;
    f32 accel[3];
    s16 lifetime;
} ParticleMotion;

typedef struct ParticleOwner {
    u8 pad0[0x3C];
    u8 *groundInfo;
} ParticleOwner;

typedef struct Particle {
    u8 pad0[0x20];
    ParticleOwner *owner;
    f32 posX, posY, posZ;
    u8 pad30[0xC];
    f32 target[3];
    u8 pad48[0x18];
    u32 flags;
    u8 pad64[8];
    ParticleMotion *motion;
} Particle;

extern s32 vec3Add(void *, void *, void *);

/* Advances a falling particle one tick under gravity; sets flag 1 when it expires or drops below the ground. */
void updateFallingParticle(Particle *p) {
    ParticleMotion *m;
    ParticleOwner *owner;
    void *target;

    m = p->motion;
    owner = p->owner;
    if ((m->lifetime <= 0) || (m->lifetime = m->lifetime - 1, target = p->target, (p->posY < *(f32 *)(owner->groundInfo + 0x20)))) {
        p->flags |= 1;
        return;
    }
    p->posX = p->posX + (m->velX * 0.033333335f);
    p->posY = p->posY + (m->velY * 0.033333335f);
    p->posZ = p->posZ + (m->velZ * 0.033333335f);
    m->velY = m->velY - 0.32666668f;
    vec3Add(m->accel, target, target);
}
