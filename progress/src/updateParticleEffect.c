void vec3Add(void *, void *, void *);
void func_800617D8(void *, void *, int, int, f32, f32, int, int, int, int, int);
extern f64 D_800D4138;
extern f64 D_800D4140;

/* Advances one particle effect: ages it, drifts it with its velocity, applies gravity and damping, and kills it on ground contact or expiry */ void updateParticleEffect(void *effect) {
    void *particle;
    void *parent;
    f32 parentGroundY;
    f32 effectGroundY;

    particle = *(void **)((char *)effect + 0x6C);
    parent = *(void **)((char *)effect + 0x20);
    *(unsigned short *)((char *)particle + 0x1C) = *(unsigned short *)((char *)particle + 0x1C) - 1;
    *(f32 *)((char *)effect + 0x54) = (f32)(*(f32 *)((char *)effect + 0x54) + D_800D4138);
    if (parent == 0) {
        *(int *)((char *)effect + 0x60) = *(int *)((char *)effect + 0x60) | 1;
        return;
    }
    effectGroundY = *(f32 *)((char *)effect + 0x28);
    parentGroundY = *(f32 *)((char *)*(void **)((char *)parent + 0x20) + 0x5C);
    if (parentGroundY < effectGroundY) {
        *(f32 *)((char *)effect + 0x28) = parentGroundY;
        func_800617D8(*(void **)((char *)effect + 0x20), (char *)effect + 0x24, 0, 0, 0.25f, 1.05f, 0x1C, 0x1B, 0x2C, 0x40008080, 0x80808008);
        *(int *)((char *)effect + 0x60) = *(int *)((char *)effect + 0x60) | 1;
        return;
    }
    if (((short)*(unsigned short *)((char *)particle + 0x1C) <= 0) || (*(f32 *)((char *)*(void **)((char *)parent + 0x3C) + 0x24) < effectGroundY)) {
        *(int *)((char *)effect + 0x60) = *(int *)((char *)effect + 0x60) | 1;
        return;
    }
    vec3Add((char *)particle + 4, (char *)effect + 0x24, (char *)effect + 0x24);
    {
        f32 t4;
        f32 t0;
        f32 t12;
        f32 t8;
        t4 = (f32)(*(f32 *)((char *)particle + 4) * D_800D4140);
        *(f32 *)((char *)particle + 4) = t4;
        t0 = *(f32 *)((char *)effect + 0x54) * 0.001f + 0.0012760417f;
        t12 = (f32)(*(f32 *)((char *)particle + 0xC) * D_800D4140);
        t8 = *(f32 *)((char *)particle + 8) + t0;
        *(f32 *)((char *)particle + 0xC) = t12;
        *(f32 *)((char *)particle + 8) = t8;
    }
    *(int *)((char *)effect + 0x58) = *(int *)((char *)effect + 0x58) | 1;
}
