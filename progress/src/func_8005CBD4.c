/* machine draft (m2c) for gcc-2.7.2-kmc -G0 -mips3 -mgp32 -mfp32 -O2, tried by autopilot */

s32 effectSetAnimFrame(void *, s32, s32);   /* extern */
f32 func_80045764(s32, void *);                 /* extern */
s32 func_80046424(void *, f32, f32, f32);       /* extern */
s32 func_80047B14(void *, f32, void *);     /* extern */
s32 objectListInsert(void *, s32);              /* extern */
s32 randomIntBelow(s32);                        /* extern */
void *spawnEffectObject(s32, s32, s32); /* extern */

void func_8005CBD4(void *arg0, s32 arg1, void *arg2, f32 arg3, u32 arg4) {
    volatile s32 padding[2];
    f32 temp_fs1;
    int var_s3;
    void *temp_v0;
    void *temp_s1;
    register void *temp_s0;

    var_s3 = 0;
    temp_fs1 = arg3 * 0.5f;
    if (arg4 != 0) {
        do {
            temp_v0 = spawnEffectObject(0x20, arg1, 0);
            if (!temp_v0) { var_s3 += 1; continue; }
            {
                temp_s1 = (*(void **)((char *)(temp_v0) + 0x6C));
                (*(s16 *)((char *)(temp_v0) + 0x7A)) = 0;
                (*(s16 *)((char *)(temp_v0) + 0x78)) = 8;
                (*(s16 *)((char *)(temp_s1) + 0x1C)) = (s16) (randomIntBelow(4) + 4);
                (*(u8 *)((char *)(temp_v0) + 0x82)) = 0xFF;
                (*(s8 *)((char *)(temp_s1) + 0x1E)) = (s8) (0xFF / (s16) (*(s16 *)((char *)(temp_s1) + 0x1C)));
                (*(f32 *)((char *)(temp_v0) + 0x54)) = (f32) (randomFloatScaled(0.5f) + 0.5f);
                (*(f32 *)((char *)(temp_s1) + 4)) = (f32) (((*(f32 *)((char *)(arg2) + 0)) + randomFloatScaled(arg3)) - temp_fs1);
                (*(f32 *)((char *)(temp_s1) + 8)) = (f32) (((*(f32 *)((char *)(arg2) + 4)) + randomFloatScaled(arg3)) - temp_fs1);
                temp_s0 = temp_s1 + 4;
                (*(f32 *)((char *)(temp_s1) + 0xC)) = (f32) (((*(f32 *)((char *)(arg2) + 8)) + randomFloatScaled(arg3)) - temp_fs1);
                func_80047B14(temp_s0, 6.0f, temp_s0);
                (*(f32 *)((char *)(temp_s1) + 0)) = func_80045764(0, temp_s0);
                (*(u8 *)((char *)(temp_v0) + 0x7F)) = 0xFF;
                (*(u8 *)((char *)(temp_v0) + 0x80)) = 0xFF;
                (*(s8 *)((char *)(temp_v0) + 0x81)) = 0;
                (*(s32 *)((char *)(temp_v0) + 0x58)) = (s32) ((*(s32 *)((char *)(temp_v0) + 0x58)) | 0x10000);
                effectSetAnimFrame(temp_v0, randomIntBelow(3) + 0xF, 0x1B);
                func_80046424(temp_v0 + 0x3C, (*(f32 *)((char *)(temp_s1) + 4)), (*(f32 *)((char *)(temp_s1) + 8)), (*(f32 *)((char *)(temp_s1) + 0xC)));
                (*(f32 *)((char *)(temp_v0) + 0x3C)) = (f32) -(*(f32 *)((char *)(temp_v0) + 0x3C));
                objectListInsert(temp_v0, (*(s32 *)((char *)(arg0) + 0x20)));
            }
            do { var_s3 += 1; } while (0);
        } while (arg4 > var_s3);
    }
}

