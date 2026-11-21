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

M2C_UNK vec3Add(M2C_UNK *, M2C_UNK *, M2C_UNK *); /* extern */
M2C_UNK func_800452E0(M2C_UNK *, void *, M2C_UNK *); /* extern */
f32 func_80045764(M2C_UNK *, M2C_UNK *);            /* extern */
M2C_UNK func_80047B14(M2C_UNK *, f32, M2C_UNK *);   /* extern */
extern f64 D_800D51E8;

/* Per-frame actor velocity update: scales the motion vector by 0.95, and when flags 0x22 are set adds a capped push from the surface normal */
void updateActorVelocityDamping(void *actor) {
    char sp10[0x10];
    M2C_UNK *motion;
    M2C_UNK *velocity;
    f32 var_ft0;

    motion = M2C_FIELD(actor, M2C_UNK **, 0x6C);
    velocity = actor + 0x24;
    vec3Add(motion, velocity, velocity);
    func_80047B14(motion, 0.95f, motion);
    if (M2C_FIELD(actor, s32 *, 0x60) & 0x22) {
        func_800452E0(velocity, (s8 *) motion + 0x50, sp10);
        func_80045764(sp10, sp10);
        func_80047B14(sp10, 0.075f, sp10);
        vec3Add(sp10, motion, motion);
        var_ft0 = func_80045764(motion, motion);
        if (D_800D51E8 < (f64) var_ft0) {
            var_ft0 = 0.075f;
        }
        func_80047B14(motion, var_ft0, motion);
    }
}
