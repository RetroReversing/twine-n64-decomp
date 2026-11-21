/* machine draft (m2c) for gcc-2.7.2-kmc -G0 -mips3 -mgp32 -mfp32 -O2, tried by autopilot */

void *spawnEffectObject();
s32 objectSetAnimFrame();
extern u8 D_800B20D2;
extern u8 D_800B2322;
extern s16 D_800C2942;

void *func_8006201C(s32 arg0, void *arg1, s32 arg2, s16 arg3) {
    register void *temp_a3;
    void *temp_v0;
        u16 ticks;
        u16 color;
    u16 inputColor;
        u16 mode;
        s32 kind;
        f32 inverse;

    temp_v0 = spawnEffectObject(0x30, arg0, 0);
    if (temp_v0 != NULL) {
        (*(s16 *)((char *)(temp_v0) + 0x78)) = 0x5B;
        (*(s16 *)((char *)(temp_v0) + 0x7A)) = 0;
        (*(u8 *)((char *)(temp_v0) + 0x7F)) = 0xFF;
        (*(s8 *)((char *)(temp_v0) + 0x80)) = 0;
        (*(s8 *)((char *)(temp_v0) + 0x81)) = 0;
        (*(u8 *)((char *)(temp_v0) + 0x82)) = 0xFF;
        (*(f32 *)((char *)(temp_v0) + 0x54)) = 0.5f;
        ticks = *(u16 *)((char *)arg1 + 4);
        temp_a3 = (*(void **)((char *)(temp_v0) + 0x6C));
        if (ticks == 0) {
            *(u16 *)((char *)arg1 + 4) = 0x1E;
        }
        (*(s8 *)((char *)(temp_a3) + 0x2E)) = (s8) (*(u16 *)((char *)(arg1) + 0x2C));
        inputColor = *(u16 *)((char *)arg1 + 0x2E);
        (*(s32 *)((char *)(temp_a3) + 0)) = (unsigned)arg2;
        (*(s16 *)((char *)(temp_a3) + 0xC)) = arg3;
        (*(s16 *)((char *)(temp_a3) + 0xE)) = 0;
        (*(s32 *)((char *)(temp_a3) + 4)) = 0;
        *(s8 *)((char *)temp_a3 + 0x2F) = inputColor;
        inverse = 1.0f / (f32)*(u16 *)((char *)arg1 + 4);
        (*(u16 *)((char *)(temp_a3) + 0x2C)) = 0U;
        mode = *(volatile u16 *)((char *)temp_a3 + 0x2C);
        (*(s8 *)((char *)(temp_a3) + 0x28)) = 0;
        (*(s8 *)((char *)(temp_a3) + 0x26)) = 0;
        (*(s8 *)((char *)(temp_a3) + 0x27)) = 0;
        (*(volatile u8 *)((char *)(temp_a3) + 0x29)) = 0xFF;
        (*(s16 *)((char *)(temp_a3) + 0x24)) = 0xF2;
        (*(s8 *)((char *)(temp_a3) + 0x2A)) = 1;
        *(f32 *)((char *)temp_a3 + 8) = inverse;
        color = D_800B20D2;
        kind = D_800C2942;
        *(f32 *)((char *)temp_a3 + 0x1C) = color;
        color = D_800B2322;
        (*(s32 *)((char *)(temp_a3) + 0x10)) = -1;
        (*(f32 *)((char *)(temp_a3) + 0x14)) = 1000.0f;
        (*(f32 *)((char *)(temp_a3) + 0x18)) = 1000.0f;
        *(f32 *)((char *)temp_a3 + 0x20) = color;
        objectSetAnimFrame(temp_v0, mode, kind, temp_a3);
    }
    return temp_v0;
}

