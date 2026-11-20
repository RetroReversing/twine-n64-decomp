/* machine draft (m2c) for gcc-2.7.2-kmc -G0 -mips3 -mgp32 -mfp32 -O2, tried by autopilot */
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

s32 func_80018700();
s32 func_80018744();
s32 func_8001880C();
s32 func_80084338();
extern u16 D_800C79AA;
extern f64 D_800D27E0;
extern char gActorDoneFlags[];

void func_80018A18(void *arg0) {
    f32 temp_fv1;
    f32 temp_fv1_2;
    s16 temp_v1;
    u16 temp_v0;
    u16 temp_v0_2;
    u8 temp_a0;
    void *temp_s1;

    temp_v1 = M2C_FIELD(arg0, s16 *, 0x7A);
    temp_s1 = M2C_FIELD(arg0, void **, 0x6C);
    switch (temp_v1) {
    case 0:
        temp_fv1 = M2C_FIELD(arg0, f32 *, 0x3C);
        M2C_FIELD(arg0, f32 *, 0x3C) = (f32) ((f64) temp_fv1 + ((f64) (M2C_FIELD(temp_s1, f32 *, 0xC) - temp_fv1) * D_800D27E0));
        temp_fv1_2 = M2C_FIELD(arg0, f32 *, 0x40);
        M2C_FIELD(arg0, f32 *, 0x40) = (f32) ((f64) temp_fv1_2 + ((f64) (M2C_FIELD(temp_s1, f32 *, 0x10) - temp_fv1_2) * D_800D27E0));
        return;
    case 1:
        temp_v0 = M2C_FIELD(arg0, u16 *, 0x7C) - 1;
        M2C_FIELD(arg0, u16 *, 0x7C) = temp_v0;
        if ((temp_v0 << 0x10) <= 0) {
            M2C_FIELD(arg0, s16 *, 0x7A) = 2;
            M2C_FIELD(arg0, u16 *, 0x7C) = 0xFU;
        }
        /* fallthrough */
    case 2:
        func_8001880C(arg0);
        return;
    case 3:
        func_8001880C(arg0);
        M2C_FIELD(temp_s1, s32 *, 0x18) = func_80084338(D_800C79AA, arg0 + 0x24);
        M2C_FIELD(arg0, s16 *, 0x7A) = 4;
        return;
    case 4:
        func_8001880C(arg0);
        func_80018744(arg0);
        temp_v0_2 = M2C_FIELD(arg0, u16 *, 0x7C) - 1;
        M2C_FIELD(arg0, u16 *, 0x7C) = temp_v0_2;
        if ((temp_v0_2 << 0x10) <= 0) {
            func_80018700(temp_s1);
            M2C_FIELD(arg0, s16 *, 0x7A) = 1;
            M2C_FIELD(arg0, u16 *, 0x7C) = 0x1EU;
            return;
        }
    default:
        return;
    case 6:
        func_8001880C(arg0);
        M2C_FIELD(temp_s1, s32 *, 0x18) = func_80084338(D_800C79AA, arg0 + 0x24);
        M2C_FIELD(arg0, s16 *, 0x7A) = 7;
        return;
    case 7:
        func_8001880C(arg0);
        func_80018744(arg0);
        temp_a0 = M2C_FIELD(temp_s1, u8 *, 0x1C);
        if (temp_a0 != 0) {
            *(gActorDoneFlags + temp_a0) = 1;
            return;
        }
        break;
    case 8:
        func_80018700(temp_s1);
        M2C_FIELD(arg0, s16 *, 0x7A) = 2;
        return;
    case 5:
        func_80018700(temp_s1);
        M2C_FIELD(arg0, u16 *, 0x7C) = 0x1EU;
        M2C_FIELD(arg0, s16 *, 0x7A) = 0;
        break;
    }
}
