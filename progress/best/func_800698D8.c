/* machine draft (m2c) for gcc-2.7.2-kmc -G0 -mips3 -mgp32 -mfp32 -O2 -fno-schedule-insns, tried by autopilot */
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

f32 func_800828D0();
extern char D_8011508F[];

void func_800698D8(void *arg0, s32 arg1, s32 arg2) {
    f32 temp_fv0;
    s8 var_v1;
    void *temp_s0;

    temp_s0 = M2C_FIELD(arg0, void **, 0x6C);
    M2C_FIELD(temp_s0, s32 *, 0x38) = arg2;
    temp_fv0 = func_800828D0(arg0, arg1);
    var_v1 = 0;
    if (temp_fv0 <= 0.2f) {
        var_v1 = 1;
    } else if (temp_fv0 >= 0.8f) {
        var_v1 = 2;
    }
    if ((var_v1 != 0) && (var_v1 != M2C_FIELD(temp_s0, s8 *, 0x17F))) {
        M2C_FIELD(temp_s0, s8 *, 0x17F) = var_v1;
        if (*(D_8011508F + (M2C_FIELD(temp_s0, s8 *, 0x182) * 0xA0)) != 0) {
            M2C_FIELD(temp_s0, s8 *, 0x17E) = 2;
        }
    }
}
