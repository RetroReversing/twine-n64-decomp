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

extern u8 D_800C471C[];

s32 func_8005EF30(void *arg0, s32 arg1) {
    s32 var_a0;
    u32 var_a2;
    void *var_v1;

    var_a2 = 4;
    var_a0 = 0x3A0;
    var_v1 = M2C_FIELD(arg0, s32 *, 0x6C) + 0x20;
loop_1:
    if (M2C_FIELD(var_v1, u8 *, 0x1FC) == 0) {
        var_a0 += 0xE8;
        goto block_8;
    }
    if (*(D_800C471C + var_a0) != arg1) {
        var_a0 += 0xE8;
block_8:
        var_a2 += 1;
        var_v1 += 8;
        if (var_a2 >= 0x21U) {
            return 0;
        }
        goto loop_1;
    }
    return 1;
}
