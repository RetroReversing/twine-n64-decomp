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

s32 func_8008C0D4();
s32 func_8008C11C();
s32 func_8008F520();
extern u8 D_800CF540;
extern s16 D_800EDAA0;
extern char D_800EDAA4[];

s32 func_80092F9C(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    s32 temp_a3;
    s32 var_a2;
    s32 var_s0;
    s32 var_v1;
    char *var_s0_2;
    u16 var_a0;
    void *temp_a1;
    void *temp_s1;
    void *temp_s2;

    arg0 &= 0xFFFF;
    if (D_800CF540 != 0) {
        var_v1 = 0;
        if (D_800EDAA0 > 0) {
            temp_a3 = arg1 & 0xFFFF;
            var_a2 = 0;
loop_3:
            temp_a1 = *(D_800EDAA4 + var_a2);
            if (M2C_FIELD(temp_a1, u16 *, 4) != arg0) {
                var_v1 += 1;
                var_a2 += 4;
                if (var_v1 >= D_800EDAA0) {
                    goto block_18;
                }
                goto loop_3;
            }
            if (M2C_FIELD(temp_a1, u16 *, 6) == 0) {
                var_s0_2 = temp_a1 + (M2C_FIELD(temp_a1, s32 *, 0x24) + 8);
                var_a0 = *(u16 *)var_s0_2;
                temp_s2 = temp_a1 + (M2C_FIELD(temp_a1, s32 *, 0x20) + 8);
                temp_s1 = temp_a1 + (M2C_FIELD(temp_a1, s32 *, 0x1C) + 8);
                if ((var_a0 & 0xFFFF) != 0xFFFF) {
loop_8:
                    if (var_a0 != temp_a3) {
                        var_s0_2 += 0x84;
                        var_a0 = *(u16 *)var_s0_2;
                        if (var_a0 == 0xFFFF) {
                            return -1;
                        }
                        goto loop_8;
                    }
                    if (arg4 & 0xFF) {
                        var_s0 = func_8008F520(temp_s1, temp_s2, var_s0_2, arg2, arg3);
                    } else {
                        func_8008C0D4(temp_s1, temp_a1, var_a2, temp_a3);
                        var_s0 = func_8008F520(temp_s1, temp_s2, var_s0_2, arg2, arg3);
                        func_8008C11C();
                    }
                    return var_s0;
                }
                goto block_18;
            }
            /* Duplicate return node #19. Try simplifying control flow for better match */
            return -1;
        }
    }
block_18:
    return -1;
}
