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

s32 func_80087100();
s16 strlen();

void func_80074FD4(void *arg0) {
    
    s16 temp_a0;
    s32 temp_a1;
s32 __repair_phase_temp_a1;
    s32 temp_v0;
    s32 temp_v0_2;
    s32 var_a1;
    s32 var_s1;
    u8 temp_v1;
    void *temp_s0;

    temp_s0 = M2C_FIELD(M2C_FIELD(arg0, void **, 0x6C), void **, 4);
    temp_a1 = (u8)(M2C_FIELD(temp_s0, u8 *, 0x13));
    temp_a0 = M2C_FIELD(arg0, s16 *, 0x7A);
    if (temp_a0 != 0) {
        temp_v0 = temp_a1 - 8;
        if (temp_a0 != 1) {
            var_a1 = temp_a1 << 0x10;
        } else {
            var_s1 = temp_v0;
            if (temp_v0 < 0) {
                M2C_FIELD(arg0, s16 *, 0x7A) = 0;
                var_s1 = 0;
                temp_v0 = 0xF8;
                if (M2C_FIELD(temp_s0, s32 *, 0x18) == func_80087100(0xF8, arg0)) {
                    temp_v0 = 0x2AB;
                }
                M2C_FIELD(temp_s0, s32 *, 0x18) = func_80087100(temp_v0);
                M2C_FIELD(temp_s0, s16 *, 0x1C) = strlen(M2C_FIELD(temp_s0, s32 *, 0x18));
            }
            goto block_9;
        }
    } else {
        temp_v0_2 = temp_a1 + 8;
        var_s1 = temp_v0_2;
        if (temp_v0_2 >= 0x100) {
            M2C_FIELD(arg0, s16 *, 0x7A) = 1;
            var_s1 = 0xFF;
        }
block_9:
        var_a1 = var_s1 << 0x10;
    }
    var_a1 = var_a1 >> 0x10;
    M2C_FIELD(temp_s0, s32 *, 0x10) = (s32) ((var_a1 << 0x10) | ((var_a1 << 8) | 0xFF000000) | var_a1);
}
