/* machine draft (m2c) for gcc-2.7.2-kmc -G0 -mips3 -mgp32 -mfp32 -O2, tried by autopilot */

s32 func_800452AC();
s32 func_80045CF8();
f32 func_80045D2C(f32);
s32 func_8005D444(s32, s32, f32, s32, s32, s32);
s32 func_800617D8(s32, void*, void*, s32, f32, f32, s32, s32, s32, s32, s32);
extern f64 D_800D4150;
extern f64 D_800D4158;
extern f64 D_800D4160;

typedef struct { unsigned char pad_0[4]; float field_4; float field_8; float field_C; unsigned char pad_10[12]; short field_1C; } __repair_record_temp_s0;
void func_8005D62C(void *arg0) {
    void *temp_s2;
    s16 temp_v0;
    void *temp_s0_2;
    register void *temp_s3;
    unsigned temp_a0;
    f32 temp_fv1;
    void *temp_s0;

    temp_s0 = (*(void **)((char *)(arg0) + 0x6C));
    temp_a0 = (*(u8 *)((char *)(arg0) + 0x81)) - 1;
    (*(u8 *)((char *)(arg0) + (unsigned short)0x7F)) += 1;
    (*(u8 *)((char *)(arg0) + 0x80)) += 1;
    (*(u8 *)((char *)(arg0) + 0x81)) = temp_a0;
    temp_v0 = (((__repair_record_temp_s0*)temp_s0)->field_1C);
    temp_s3 = (*(void **)((char *)(arg0) + 0x20));
    if (0 >= temp_v0) {
        if (func_80045CF8(4) == 0) {
            func_8005D444(arg0, arg0 + 0x24, 2.0f, 2, 0x16, 0xFB);
        }
        (*(s32 *)((char *)(arg0) + 0x60)) |= 1;
    } else {
        (((__repair_record_temp_s0*)temp_s0)->field_1C) = (s16) (temp_v0 - 1);
        temp_fv1 = (*(f32 *)((char *)((*(void **)((char *)(temp_s3) + 0x3C))) + 0x20));
        if ((*(f32 *)((char *)(arg0) + 0x28)) < temp_fv1) {
            (((__repair_record_temp_s0*)temp_s0)->field_4) = (f32) ((((__repair_record_temp_s0*)temp_s0)->field_4) * (func_80045D2C(0.9f) - 0.45f));
            (((__repair_record_temp_s0*)temp_s0)->field_8) = (f32) ((f64) (((__repair_record_temp_s0*)temp_s0)->field_8) * D_800D4150);
            (*(f32 *)((char *)(temp_s0) + 0xC)) = (f32) ((((__repair_record_temp_s0*)temp_s0)->field_C) * (func_80045D2C(0.9f) - 0.45f));
            (*(f32 *)((char *)(arg0) + 0x28)) = temp_fv1;
            (*(f32 *)((char *)(arg0) + 0x54)) = (f32) ((f64) (*(f32 *)((char *)(arg0) + 0x54)) * D_800D4158);
        }
        (*(f32 *)((char *)(arg0) + 0x24)) += ((((__repair_record_temp_s0*)temp_s0)->field_4) * 0.033333335f);
        (*(f32 *)((char *)(arg0) + 0x28)) += ((((__repair_record_temp_s0*)temp_s0)->field_8) * 0.033333335f);
        temp_s2 = arg0 + 0x3C;
        (*(f32 *)((char *)(arg0) + 0x2C)) += ((((__repair_record_temp_s0*)temp_s0)->field_C) * 0.033333335f);
        (((__repair_record_temp_s0*)temp_s0)->field_8) = (f32) ((f64) (((__repair_record_temp_s0*)temp_s0)->field_8) - D_800D4160);
        func_800452AC(temp_s0 + 0x10, temp_s2, temp_s2);
        if ((*(f32 *)((char *)(arg0) + 0x28)) < (*(f32 *)((char *)((*(void **)((char *)(temp_s3) + 0x20))) + 0x5C))) {
            temp_s0_2 = arg0 + 0x24;
            func_800617D8((*(void **)((char *)(arg0) + 0x20)), temp_s0_2, temp_s2, 0, 0.1f, 1.01f, 0x19, 0xFB, 0x17, 0x80, 0x80808002);
            func_800617D8((*(void **)((char *)(arg0) + 0x20)), temp_s0_2, NULL, 0, 0.25f, func_80045D2C(0.05f) + 1.05f, 0x1C, 0x1B, 0x2C, 0x40008080, 0x80808008);
            (*(s32 *)((char *)(arg0) + 0x60)) |= 1;
        }
    }
}
