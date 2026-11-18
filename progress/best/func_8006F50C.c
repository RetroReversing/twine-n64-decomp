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

s32 func_8004FF30();

void func_8006F50C(s32 arg0, void *arg1, s32 arg2, s32 arg3) {
    f32 sp20;
    f32 sp24;
    f32 sp28;
    s32 sp30;
    f32 sp40;
    f32 sp44;
    f32 sp48;
    f32 sp50;
    f32 sp54;
    f32 sp58;
    f32 sp60;
    f32 sp64;
    f32 sp68;
    f32 temp_fv0;
    f32 temp_fv0_2;
    f32 temp_fv0_3;

    sp40 = M2C_FIELD(arg1, f32 *, 0x24);
    sp44 = M2C_FIELD(arg1, f32 *, 0x28);
    sp48 = M2C_FIELD(arg1, f32 *, 0x2C);
    sp20 = 0.0f;
    sp24 = 0.0f;
    sp28 = 0.0f;
    sp44 += 1.0f;
    temp_fv0 = M2C_FIELD(arg1, f32 *, 0x24);
    sp60 = temp_fv0;
    sp50 = temp_fv0;
    temp_fv0_2 = M2C_FIELD(arg1, f32 *, 0x28);
    sp64 = temp_fv0_2;
    sp54 = temp_fv0_2;
    temp_fv0_3 = M2C_FIELD(arg1, f32 *, 0x2C);
    sp68 = temp_fv0_3;
    sp58 = temp_fv0_3;
    if ((func_8004FF30(&sp50, &sp30, 0x3F400000, 0x10, arg2, arg3, 0) << 0x18) != 0) {
        sp20 += sp50 - sp60;
        sp24 += sp54 - sp64;
        sp28 += sp58 - sp68;
    }
    M2C_FIELD(arg1, f32 *, 0x24) += sp20;
    M2C_FIELD(arg1, f32 *, 0x28) += sp24;
    M2C_FIELD(arg1, f32 *, 0x2C) += sp28;
}
