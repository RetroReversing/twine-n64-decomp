/* machine draft (m2c) for gcc-2.7.2-kmc -G0 -mips3 -mgp32 -mfp32 -O2, tried by autopilot */

void *func_80016410();
s32 func_80016990();
s32 func_80044670();
s32 func_80045CF8();
f32 func_80045D2C(f32);
extern f64 D_800D4250;

void func_80061578(void *arg0) {
    f32 temp_a0;
    register f64 var_ft0;
    void *temp_s3;
    void *temp_s0;
    register int temp_v0_2;
    void *temp_v0;
    register u32 temp_a2;

    temp_v0 = func_80016410(0x2C, 0);
    if (temp_v0 != NULL) {
        temp_s0 = (*(void **)((char *)(temp_v0) + 0x6C));
        (*(f32 *)((char *)(temp_s0) + 0)) = (f32) (*(f32 *)((char *)(temp_s3) + 0));
        temp_s3 = (*(void **)((char *)(arg0) + 0x6C));
        (*(f32 *)((char *)(temp_s0) + 4)) = (f32) (*(f32 *)((char *)(temp_s3) + 4));
        (*(s16 *)((char *)(temp_v0) + 0x78)) = 0x14;
        (*(f32 *)((char *)(temp_s0) + 8)) = temp_a0;
        temp_a0 = (*(f32 *)((char *)(temp_s3) + 8));
        (*(f32 *)((char *)(temp_s0) + 0)) = (f32) ((((*(f32 *)((char *)(temp_s0) + 0)) * 0.06f) + func_80045D2C(0.02f)) - 0.01f);
        (*(f32 *)((char *)(temp_s0) + 4)) = (f32) ((((*(f32 *)((char *)(temp_s0) + 4)) * 0.06f) + func_80045D2C(0.02f)) - 0.01f);
        (*(f32 *)((char *)(temp_s0) + 8)) = (f32) ((((*(f32 *)((char *)(temp_s0) + 8)) * 0.06f) + func_80045D2C(0.02f)) - 0.01f);
        temp_v0_2 = func_80045CF8(0x1000);
        var_ft0 = (f64) temp_v0_2;
        if (0 > temp_v0_2) {
            var_ft0 += D_800D4250;
        }
        (*(f32 *)((char *)(temp_v0) + 0x44)) = (f32) var_ft0;
        (*(f32 *)((char *)(temp_v0) + 0x54)) = 0.2f;
        (*(s32 *)((char *)(temp_s0) + 0xC)) = 0x20;
        (*(u8 *)((char *)(temp_v0) + 0x82)) = 0xFF;
        (*(u8 *)((char *)(temp_v0) + 0x7F)) = (u8) (*(u8 *)((char *)(arg0) + 0x7F));
        (*(u8 *)((char *)(temp_v0) + 0x80)) = (u8) (*(u8 *)((char *)(arg0) + 0x80));
        (*(u8 *)((char *)(temp_v0) + 0x81)) = (u8) (*(u8 *)((char *)(arg0) + 0x81));
        temp_a2 = (*(u32 *)((char *)(temp_s3) + 0x1C));
        func_80044670(temp_v0, (temp_a2 >> 4) & 0xFFFF, temp_a2 >> 0x14);
        func_80016990(temp_v0, (*(s32 *)((char *)(arg0) + 0x20)));
    }
}
