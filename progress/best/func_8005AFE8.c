/* machine draft (m2c) for gcc-2.7.2-kmc -G0 -mips3 -mgp32 -mfp32 -O2, tried by autopilot */

void *func_80016410();
s32 func_8003E6EC();
s32 func_80044670();
s32 func_80076340();
extern u8 D_800B1FE0[];
extern char D_800B2230[];
extern s32 *D_800CA31C;

void *func_8005AFE8(void *arg0, void *arg1, s16 arg2) {
    void *temp_v0;
    register void *temp_s0;
    void *temp_v0_2;
    register void *temp_v0_3;

    temp_v0 = func_80016410(0x34, 0, 0);
    if (temp_v0 != NULL) {
        register temp_s0 = (*(void **)((char *)(temp_v0) + 0x6C));
        (*(s8 *)((char *)(temp_s0) + 0x30)) = (s8) (*(u16 *)((char *)(arg0) + 0x2C));
        (*(s8 *)((char *)(temp_s0) + 0x31)) = (s8) (*(u16 *)((char *)(arg0) + 0x38));
        if ((*(u16 *)((char *)(arg0) + 4)) == 0) {
            (*(u16 *)((char *)(arg0) + 4)) = 0xF0U;
        }
        (*(s16 *)((char *)(temp_s0) + 0x28)) = arg2;
        (*(f32 *)((char *)(temp_s0) + 0x24)) = 0.01f;
        (*(f32 *)((char *)(temp_s0) + 0x2C)) = (f32) (1.0f / (f32) (*(u16 *)((char *)(arg0) + 4)));
        (*(s32 *)((char *)(temp_s0) + 0x20)) = 0;
        (*(void **)((char *)(temp_s0) + 0x1C)) = arg1;
        (*(s16 *)((char *)(temp_s0) + 0x2A)) = 0;
        (*(s8 *)((char *)(temp_s0) + 0x32)) = (s8) (*(u16 *)((char *)(arg0) + 0x2E));
        (*(u8 *)((char *)(temp_s0) + 0x19)) = 0xFF;
        (*(s8 *)((char *)(temp_s0) + 0x18)) = 0;
        (*(s8 *)((char *)(temp_s0) + 0x33)) = (s8) (*(u16 *)((char *)(arg0) + 0x32));
        (*(s8 *)((char *)(temp_s0) + 0x1A)) = 1;
        (*(s8 *)((char *)(temp_s0) + 0x16)) = 0;
        (*(s8 *)((char *)(temp_s0) + 0x17)) = 0;
        (*(u16 *)((char *)(temp_s0) + 0x14)) = (u16) (*(u16 *)((char *)(arg0) + 0x30));
        (*(f32 *)((char *)(temp_s0) + 0xC)) = (f32) *(D_800B1FE0 + (*(u16 *)((char *)(arg0) + 0x30)));
        (*(f32 *)((char *)(temp_s0) + 8)) = 1000.0f;
        (*(s32 *)((char *)(temp_s0) + 0)) = -1;
        (*(f32 *)((char *)(temp_s0) + 4)) = 1000.0f;
        (*(f32 *)((char *)(temp_s0) + 0x10)) = (f32) *(D_800B2230 + (*(u16 *)((char *)(arg0) + 0x30)));
        func_80076340(temp_s0 + 0x1C);
        (*(s16 *)((char *)(temp_v0) + 0x78)) = 0x3F;
        (*(s16 *)((char *)(temp_v0) + 0x7A)) = 0;
        (*(s16 *)((char *)(temp_v0) + 0x7C)) = 0;
        func_80044670(temp_v0, (*(u16 *)((char *)(arg0) + 0)), *(*(s16 **)((char *)(arg0) + 0x28)));
        temp_v0_2 = (*(void **)((char *)(temp_s0) + 0x1C));
        (*(s32 *)((char *)(temp_v0) + 0x30)) = (s32) (*(s32 *)((char *)(temp_v0_2) + 0));
        (*(s32 *)((char *)(temp_v0) + 0x38)) = (s32) (*(s32 *)((char *)(temp_v0_2) + 8));
        (*(s32 *)((char *)(temp_v0) + 0x28)) = (s32) (*(s32 *)((char *)(temp_v0) + 0x34));
        (*(s32 *)((char *)(temp_v0) + 0x24)) = (s32) (*(s32 *)((char *)(temp_v0) + 0x30));
        (*(s32 *)((char *)(temp_v0) + 0x34)) = (s32) (*(s32 *)((char *)(temp_v0_2) + 4));
        temp_v0_3 = (*(void **)((char *)(temp_s0) + 0x1C));
        (*(s32 *)((char *)(temp_v0) + 0x2C)) = (s32) (*(s32 *)((char *)(temp_v0) + 0x38));
        (*(s32 *)((char *)(temp_v0) + 0x4C)) = (s32) (*(s32 *)((char *)(temp_v0_3) + 0x10));
        (*(s32 *)((char *)(temp_v0) + 0x48)) = (s32) (*(s32 *)((char *)(temp_v0_3) + 0xC));
        (*(s32 *)((char *)(temp_v0) + 0x50)) = (s32) (*(s32 *)((char *)(temp_v0_3) + 0x14));
        (*(s32 *)((char *)(temp_v0) + 0x3C)) = (s32) (*(s32 *)((char *)(temp_v0) + 0x48));
        (*(s32 *)((char *)(temp_v0) + 0x44)) = (s32) (*(s32 *)((char *)(temp_v0) + 0x50));
        (*(s32 *)((char *)(temp_v0) + 0x40)) = (s32) (*(s32 *)((char *)(temp_v0) + 0x4C));
        (*(s32 *)((char *)(temp_v0) + 0x5C)) |= 0x600;
        (*(s32 *)((char *)(temp_v0) + 0x58)) |= 0x20000;
        func_8003E6EC(*D_800CA31C, temp_v0, 0);
    }
    return temp_v0;
}
