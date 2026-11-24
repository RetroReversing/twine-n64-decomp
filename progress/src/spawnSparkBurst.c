/* machine draft (m2c) for gcc-2.7.2-kmc -G0 -mips3 -mgp32 -mfp32 -O2, tried by autopilot */

s32 effectSetAnimFrame(void *, s32, s32);   /* extern */
f32 vec3NormalizeLength(s32, void *);                 /* extern */
s32 directionToPitchYaw(void *, f32, f32, f32);       /* extern */
s32 vec3Scale(void *, f32, void *);     /* extern */
s32 objectListInsert(void *, s32);              /* extern */
s32 randomIntBelow(s32);                        /* extern */
void *spawnEffectObject(s32, s32, s32); /* extern */

/* Spawns count short-lived spark effects at random offsets around center, each with a random velocity direction and animation frame. */ void spawnSparkBurst(void *owner, s32 effectType, void *center, f32 spread, u32 count) {
    volatile s32 padding[2];
    f32 halfSpread;
    int spawned;
    void *spark;
    void *sparkState;
    register void *temp_s0;

    spawned = 0;
    halfSpread = spread * 0.5f;
    if (count != 0) {
        do {
            spark = spawnEffectObject(0x20, effectType, 0);
            if (!spark) { spawned += 1; continue; }
            {
                sparkState = (*(void **)((char *)(spark) + 0x6C));
                (*(s16 *)((char *)(spark) + 0x7A)) = 0;
                (*(s16 *)((char *)(spark) + 0x78)) = 8;
                (*(s16 *)((char *)(sparkState) + 0x1C)) = (s16) (randomIntBelow(4) + 4);
                (*(u8 *)((char *)(spark) + 0x82)) = 0xFF;
                (*(s8 *)((char *)(sparkState) + 0x1E)) = (s8) (0xFF / (s16) (*(s16 *)((char *)(sparkState) + 0x1C)));
                (*(f32 *)((char *)(spark) + 0x54)) = (f32) (randomFloatScaled(0.5f) + 0.5f);
                (*(f32 *)((char *)(sparkState) + 4)) = (f32) (((*(f32 *)((char *)(center) + 0)) + randomFloatScaled(spread)) - halfSpread);
                (*(f32 *)((char *)(sparkState) + 8)) = (f32) (((*(f32 *)((char *)(center) + 4)) + randomFloatScaled(spread)) - halfSpread);
                temp_s0 = sparkState + 4;
                (*(f32 *)((char *)(sparkState) + 0xC)) = (f32) (((*(f32 *)((char *)(center) + 8)) + randomFloatScaled(spread)) - halfSpread);
                vec3Scale(temp_s0, 6.0f, temp_s0);
                (*(f32 *)((char *)(sparkState) + 0)) = vec3NormalizeLength(0, temp_s0);
                (*(u8 *)((char *)(spark) + 0x7F)) = 0xFF;
                (*(u8 *)((char *)(spark) + 0x80)) = 0xFF;
                (*(s8 *)((char *)(spark) + 0x81)) = 0;
                (*(s32 *)((char *)(spark) + 0x58)) = (s32) ((*(s32 *)((char *)(spark) + 0x58)) | 0x10000);
                effectSetAnimFrame(spark, randomIntBelow(3) + 0xF, 0x1B);
                directionToPitchYaw(spark + 0x3C, (*(f32 *)((char *)(sparkState) + 4)), (*(f32 *)((char *)(sparkState) + 8)), (*(f32 *)((char *)(sparkState) + 0xC)));
                (*(f32 *)((char *)(spark) + 0x3C)) = (f32) -(*(f32 *)((char *)(spark) + 0x3C));
                objectListInsert(spark, (*(s32 *)((char *)(owner) + 0x20)));
            }
            do { spawned += 1; } while (0);
        } while (count > spawned);
    }
}

