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
/* machine draft (m2c) for gcc-2.7.2-kmc -G0 -mips3 -mgp32 -mfp32 -O2, tried by autopilot */

extern float D_800D461C;
extern float D_800D4620;
extern float D_800D4624;
s32 func_80045290();
s32 func_800480A0();
s32 func_80048124();
s32 func_80048164();
s32 func_800481E8();
s32 func_80048224();
s32 func_80064370();
s32 func_800643C8();
s32 func_80082FE4();
s32 func_80083A6C();
extern f32 D_800C9D4C;
extern f64 D_800D4628;
extern f64 D_800D4630;
extern u8 D_800E1A16;
extern char D_80109688[];

void func_8006CD34(void *arg0) {
    f32 sp18;
    f32 sp1C;
    f32 sp20;
    unsigned long sp28;
    s16 sp58;
    f32 var_fv1;
    s16 sp5C;
    f32 temp_ft0;
    f32 temp_ft0_2;
    f32 var_fv0;
    f32 var_fv0_2;
    s16 sp5A;
f32 __repair_var_fv1_1;
    long temp_s4;
    s32 var_condition_bit;
    s8 temp_s3;
    void **temp_s0;
    void **temp_s0_2;
    void **temp_s0_3;
    void **temp_s0_4;
    void **temp_v1_2;
    void **temp_v1_3;
    void *temp_s2;
    void *temp_s2_2;
    void *temp_v0;
    void *temp_v0_2;
    void *temp_v0_3;
    void *temp_v0_4;
    void *temp_v1;
    void *var_v0;

    temp_s2 = (*(void **)((char *)(arg0) + 0x6C));
    temp_s4 = (*(s32 *)((char *)(arg0) + 0x20));
    temp_s3 = (*(s8 *)((char *)(temp_s2) + 0x182));
    if ((*(u8 *)((char *)(temp_s2) + 0x184)) == 0) {
        func_80064370(arg0, arg0);
        if ((*(s16 *)((char *)(arg0) + 0x7C)) == 5) {
            temp_s0 = (temp_s3 * 4) + D_80109688;
            (*(f32 *)((char *)(*temp_s0) + 0x4C)) = (f32) (*(f32 *)((char *)(temp_s2) + 0x3C));
            do { func_800480A0(arg0, *temp_s0); } while (0);
            temp_v1 = *temp_s0;
            temp_v0 = (*(void **)((char *)(temp_s2) + 0xBC));
            (*(f32 *)((char *)(temp_v1) + 0x10)) = (f32) (*(f32 *)((char *)(temp_v0) + 0x24));
            (*(f32 *)((char *)(temp_v1) + 0x14)) = (f32) (*(f32 *)((char *)(temp_v0) + 0x28));
            var_v0 = *temp_s0;
            (*(f32 *)((char *)(temp_v1) + 0x18)) = (f32) (*(f32 *)((char *)(temp_v0) + 0x2C));
            var_fv0 = (f32) ((f64) (*(f32 *)((char *)(var_v0) + 0x14)) + D_800D4628);
        } else {
            var_fv0_2 = 0.55f;
            if (!D_800E1A16) {
                var_fv0_2 = 0.0f;
            }
            temp_ft0 = (*(f32 *)((char *)(temp_s2) + 0x98));
            temp_s0_2 = (((*(s8 *)((char *)(temp_s2) + 0x182))) * 4) + D_80109688;
            (*(f32 *)((char *)(temp_s2) + 0x98)) = (f32) (((var_fv0_2 - temp_ft0) * 0.1f) + temp_ft0);
            (*(f32 *)((char *)(*temp_s0_2) + 0x4C)) = (f32) (*(f32 *)((char *)(temp_s2) + 0x3C));
            func_800480A0(arg0, *temp_s0_2);
            if ((*(s16 *)((char *)(arg0) + 0x7C)) == 6) {
                temp_v0_2 = *temp_s0_2;
                (*(f32 *)((char *)(temp_v0_2) + 0x130)) += 0.040000003f;
                var_fv1 = 0.4f;
                var_condition_bit = (*(f32 *)((char *)(*temp_s0_2) + 0x130)) > 0.4f;
            } else {
                temp_v0_3 = *temp_s0_2;
                (*(f32 *)((char *)(temp_v0_3) + 0x130)) -= 0.040000003f;
                __repair_var_fv1_1 = 0.0f;
                var_condition_bit = (*(f32 *)((char *)(*temp_s0_2) + 0x130)) < 0.0f;
            }
            if (var_condition_bit) {
                (*(f32 *)((char *)(*temp_s0_2) + 0x130)) = __repair_var_fv1_1;
            }
            if ((u32) ((*(u16 *)((char *)(arg0) + 0x7A)) - 2) < 2U) {
                (*(s32 *)((char *)(*(s32 *)(D_80109688 + (((*(s8 *)((char *)(temp_s2) + 0x182))) * 4))) + 0x130)) = 0;
            }
            temp_v1_2 = (((*(s8 *)((char *)(temp_s2) + 0x182))) * 4) + D_80109688;
            temp_v0_4 = *temp_v1_2;
            (*(f32 *)((char *)(temp_v0_4) + 0x14)) -= (*(f32 *)((char *)(temp_v0_4) + 0x130));
            var_v0 = *temp_v1_2;
            temp_ft0_2 = (*(f32 *)((char *)(var_v0) + 0x2C));
            var_fv0 = (((*(f32 *)((char *)(var_v0) + 0x14)) - temp_ft0_2) * 0.5f) + temp_ft0_2;
        }
        (*(f32 *)((char *)(var_v0) + 0x14)) = var_fv0;
    }
    if ((*(u8 *)((char *)(temp_s2) + 0x184)) == 1) {
        func_800643C8(arg0);
        temp_s0_3 = (((*(s8 *)((char *)(temp_s2) + 0x182))) * 4) + D_80109688;
        do { func_80048224(arg0 + 0x24, arg0 + 0x3C, *temp_s0_3, 0x3F800000, 10.0f); } while (0);
        func_800481E8(arg0,  *temp_s0_3);
        func_80048124(arg0, *temp_s0_3);
        func_80048164(arg0, *temp_s0_3, 0x3F800000);
        (*(f32 *)((char *)(*temp_s0_3) + 0x4C)) = 1.0f;
        (*(s32 *)((char *)(*temp_s0_3) + 0xF4)) = temp_s4;
    }
    if ((*(u8 *)((char *)(temp_s2) + 0x184)) == 2) {
        do { func_800643C8(arg0); } while (0);
        temp_v1_3 = (((*(s8 *)((char *)(temp_s2) + 0x182))) * 4) + D_80109688;
        (*(f32 *)((char *)(*temp_v1_3) + 0x10)) = (f32) (*(f32 *)((char *)(arg0) + 0x24));
        (*(f32 *)((char *)(*temp_v1_3) + 0x18)) = (f32) (*(f32 *)((char *)(arg0) + 0x2C));
        (*(f32 *)((char *)(*temp_v1_3) + 0x14)) = (f32) ((f64) (*(f32 *)((char *)(arg0) + 0x28)) + D_800D4630 + (f64) D_800C9D4C);
        (*(s32 *)((char *)(*temp_v1_3) + 0x38)) = 0;
        (*(f32 *)((char *)(*temp_v1_3) + 0x34)) = -1.5707964f;
        (*(s32 *)((char *)(*temp_v1_3) + 0x3C)) = 0;
        (*(f32 *)((char *)(*temp_v1_3) + 0x4C)) = 1.0f;
        (*(s32 *)((char *)(*temp_v1_3) + 0xF4)) = temp_s4;
    }
    if ((*(u8 *)((char *)(temp_s2) + 0x184)) == 3) {
        temp_s2_2 = (*(void **)((char *)(temp_s2) + 0xBC));
        if (temp_s2_2 != NULL) {
            register sp18 = D_800D461C;
            sp1C = D_800D4620;
            sp20 = D_800D4624;
            func_800643C8(arg0, &D_800D461C);
            sp58 = (s16) (s32) (*(f32 *)((char *)(temp_s2_2) + 0x3C));
            sp5A = (s16) (s32) (*(f32 *)((char *)(temp_s2_2) + 0x40));
            sp5C = (s16) (s32) (*(f32 *)((char *)(temp_s2_2) + 0x44));
            func_80082FE4(&sp58, &sp28);
            func_80083A6C(&sp28, &sp18);
            sp18 += (*(f32 *)((char *)(temp_s2_2) + 0x24));
            sp1C += (*(f32 *)((char *)(temp_s2_2) + 0x28));
            temp_s0_4 = (temp_s3 * 4) + D_80109688;
            sp20 += (*(f32 *)((char *)(temp_s2_2) + 0x2C));
            func_80045290(&sp18, *temp_s0_4 + 0x10);
            (*(f32 *)((char *)(*temp_s0_4) + 0x34)) = (f32) ((*(f32 *)((char *)(temp_s2_2) + 0x3C)) * 0.0015339808f);
            (*(f32 *)((char *)(*temp_s0_4) + 0x38)) = (f32) (((*(f32 *)((char *)(temp_s2_2) + 0x40)) * 0.0015339808f) + 3.1415927f);
            (*(f32 *)((char *)(*temp_s0_4) + 0x3C)) = (f32) (((*(f32 *)((char *)(temp_s2_2) + 0x44)) * 0.0015339808f) + 3.1415927f);
            (*(f32 *)((char *)(*temp_s0_4) + 0x4C)) = 1.0f;
            (*(s32 *)((char *)(*temp_s0_4) + 0xF4)) = (s32) (*(s32 *)((char *)(temp_s2_2) + 0x20));
        }
    }
}
