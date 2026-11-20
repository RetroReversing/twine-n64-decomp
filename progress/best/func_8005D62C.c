/* machine draft (m2c) for gcc-2.7.2-kmc -G0 -mips3 -mgp32 -mfp32 -O2, tried by autopilot */

s32 func_800452AC();
s32 func_80045CF8();
f32 func_80045D2C(f32);
s32 func_8005D444(void *, void *, f32, s32, s32, s32);
void *func_800617D8(void *, void*, void*, void *, f32, f32, s32, s32, s32, u32, u32);
extern f64 D_800D4150;
extern f64 D_800D4158;
extern f64 D_800D4160;

typedef struct { unsigned char pad_0[4]; float field_4; float field_8; float field_C; unsigned char pad_10[12]; short field_1C; } __repair_record_temp_s0;
typedef struct { unsigned char pad_0[32]; void * field_20; float field_24; float field_28; float field_2C; unsigned char pad_30[36]; float field_54; unsigned char pad_58[8]; int field_60; unsigned char pad_64[8]; void * field_6C; unsigned char pad_70[16]; unsigned char field_80; unsigned char field_81; } __repair_record_arg0;
void func_8005D62C(void *arg0) {
    void *temp_s2;
    s16 temp_v0;
    void *temp_s0_2;
    register void *temp_s3;
    unsigned temp_a0;
    f32 temp_fv1;
    void *temp_s0;

    temp_s0 = (((__repair_record_arg0*)arg0)->field_6C);
    temp_a0 = (((__repair_record_arg0*)arg0)->field_81) - 1;
    (*(u8 *)((char *)(arg0) + (unsigned short)0x7F)) += 1;
    (((__repair_record_arg0*)arg0)->field_80) += 1;
    (((__repair_record_arg0*)arg0)->field_81) = temp_a0;
    temp_v0 = (((__repair_record_temp_s0*)temp_s0)->field_1C);
    temp_s3 = (((__repair_record_arg0*)arg0)->field_20);
    if (temp_v0 > 0) {
        (((__repair_record_temp_s0*)temp_s0)->field_1C) = (s16) (temp_v0 - 1);
        goto alive;
    }
    if (func_80045CF8(4) == 0) {
        func_8005D444(arg0, arg0 + 0x24, 2.0f, 2, 0x16, 0xFB);
    }
    (((__repair_record_arg0*)arg0)->field_60) |= 1;
    return;
    alive:
        temp_fv1 = (*(f32 *)((char *)((*(void **)((char *)(temp_s3) + 0x3C))) + 0x20));
        if ((((__repair_record_arg0*)arg0)->field_28) < temp_fv1) {
            (((__repair_record_temp_s0*)temp_s0)->field_4) = (f32) ((((__repair_record_temp_s0*)temp_s0)->field_4) * (func_80045D2C(0.9f) - 0.45f));
            (((__repair_record_temp_s0*)temp_s0)->field_8) = (f32) ((f64) (((__repair_record_temp_s0*)temp_s0)->field_8) * D_800D4150);
            (*(f32 *)((char *)(temp_s0) + 0xC)) = (f32) ((((__repair_record_temp_s0*)temp_s0)->field_C) * (func_80045D2C(0.9f) - 0.45f));
            (((__repair_record_arg0*)arg0)->field_28) = ((*(f32 *)((char *)((*(void **)((char *)(temp_s3) + 0x3C))) + 0x20)));
            (((__repair_record_arg0*)arg0)->field_54) = (f32) ((f64) (((__repair_record_arg0*)arg0)->field_54) * D_800D4158);
        }
        (((__repair_record_arg0*)arg0)->field_24) += ((((__repair_record_temp_s0*)temp_s0)->field_4) * 0.033333335f);
        (((__repair_record_arg0*)arg0)->field_28) += ((((__repair_record_temp_s0*)temp_s0)->field_8) * 0.033333335f);
        temp_s2 = arg0 + 0x3C;
        (((__repair_record_arg0*)arg0)->field_2C) += ((((__repair_record_temp_s0*)temp_s0)->field_C) * 0.033333335f);
        (((__repair_record_temp_s0*)temp_s0)->field_8) = (f32) ((f64) (((__repair_record_temp_s0*)temp_s0)->field_8) - D_800D4160);
        func_800452AC(temp_s0 + 0x10, temp_s2, temp_s2);
        if ((((__repair_record_arg0*)arg0)->field_28) < (*(f32 *)((char *)((*(void **)((char *)(temp_s3) + 0x20))) + 0x5C))) {
            temp_s0_2 = arg0 + 0x24;
            func_800617D8((((__repair_record_arg0*)arg0)->field_20), temp_s0_2, temp_s2, 0, 0.1f, 1.01f, 0x19, 0xFB, 0x17, 0x80, 0x80808002);
            func_800617D8((((__repair_record_arg0*)arg0)->field_20), temp_s0_2, NULL, 0, 0.25f, func_80045D2C(0.05f) + 1.05f, 0x1C, 0x1B, 0x2C, 0x40008080, 0x80808008);
            (((__repair_record_arg0*)arg0)->field_60) |= 1;
        }
    
}
