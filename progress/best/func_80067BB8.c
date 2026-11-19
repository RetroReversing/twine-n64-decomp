/* machine draft (m2c) for gcc-2.7.2-kmc -G0 -mips3 -mgp32 -mfp32 -O2, tried by autopilot */

extern f64 D_800D4480;
extern f64 D_800D4488;
extern f64 D_800D4490;
extern char D_80109688[];

void func_80067BB8(void *arg0) {
    f32 sp0;
    s32 sp8;
    f32 sp4;
    register void *temp_a0;
    void **temp_v1;
    register void *temp_v0;

    temp_v1 = ((*(s8 *)((char *)(temp_a0) + 0x182)) * 4) + D_80109688;
    sp0 = (*(f32 *)((char *)(*temp_v1) + 0x34));
    (*(f32 *)((char *)((*(void **)((char *)(temp_a0) + 0xA8))) + 0x3C)) = (f32) ((f64) ((*(f32 *)((char *)(temp_a0) + 0x74)) * 651.8986f) + ((((f64) (*(f32 *)((char *)(temp_a0) + 0x28)) * D_800D4480) / (f64) (*(f32 *)((char *)(*temp_v1) + 0x4C))) * D_800D4488));
    temp_a0 = (*(void **)((char *)(arg0) + 0x6C));
    sp8 = 0;
    sp4 = (*(f32 *)((char *)(*temp_v1) + 0x38));
    temp_v0 = *temp_v1;
    (*(f32 *)((char *)((*(void **)((char *)(temp_a0) + 0xA8))) + 0x40)) = (f32) (D_800D4490 - ((f64) (*(f32 *)((char *)(temp_v0) + 0x80)) * D_800D4488 * (((f64) (*(f32 *)((char *)(temp_a0) + 0x24)) * D_800D4480) / (f64) (*(f32 *)((char *)(temp_v0) + 0x4C)))));
    (*(f32 *)((char *)((*(void **)((char *)(temp_a0) + 0xA8))) + 0x44)) = -2048.0f;
}
