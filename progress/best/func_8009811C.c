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

M2C_UNK func_8008C0D4();                            /* extern */
M2C_UNK func_8008C11C();                            /* extern */
extern s32 D_800F8D5C;
extern M2C_UNK D_800F8D60;
extern M2C_UNK D_800F8D62;
extern M2C_UNK D_800F9560;
extern M2C_UNK D_800F9564;
extern M2C_UNK D_800F9566;

s32 func_8009811C(s32 arg0) {
    M2C_UNK *var_a1;
    s16 temp_v0_2;
    s32 temp_a1;
    s32 temp_v0;
    s32 temp_v0_3;
    s32 temp_v0_4;
    s32 temp_v1_2;
    s32 var_a0;
    s32 var_a2;
    s32 var_a2_2;
    s32 var_v0_2;
    u16 temp_t1;
    u16 temp_v1;
    u16 temp_v1_3;
    u16 var_v0;
    u32 temp_s0;
    u32 temp_t2;
    void *var_a3;
    void *var_t0;

    func_8008C0D4();
    temp_s0 = arg0 & 0xFFFF;
    temp_t2 = temp_s0 >> 6;
    temp_v0 = temp_t2 * 4;
    temp_v1 = *(&D_800F8D60 + temp_v0);
    if (temp_v1 != 0) {
        temp_t1 = *(&D_800F8D62 + temp_v0);
        var_a2 = 0;
        if (temp_v1 != 0) {
            var_v0 = temp_t1;
loop_3:
            var_v0_2 = temp_t2 * 4;
            if (*(&D_800F9564 + (var_v0 * 8)) != temp_s0) {
                var_a2 += 1;
                var_v0 = temp_t1 + var_a2;
                if (var_a2 >= (s32) temp_v1) {
                    var_v0_2 = temp_t2 * 4;
                } else {
                    goto loop_3;
                }
            }
            temp_a1 = temp_t1 + var_a2;
            if (var_a2 < (s32) *(&D_800F8D60 + var_v0_2)) {
                temp_v1_2 = temp_a1 * 8;
                temp_v0_2 = *(&D_800F9566 + temp_v1_2) - 1;
                *(&D_800F9566 + temp_v1_2) = temp_v0_2;
                var_a2_2 = temp_a1 + 1;
                if (!(temp_v0_2 & 0xFFFF)) {
                    if (var_a2_2 < D_800F8D5C) {
                        temp_v0_3 = var_a2_2 * 8;
                        var_t0 = temp_v0_3 + (&D_800F9560 - 8);
                        var_a3 = temp_v0_3 + &D_800F9560;
                        do {
                            M2C_FIELD(var_t0, s32 *, 0) = (s32) M2C_FIELD(var_a3, s32 *, 0);
                            M2C_FIELD(var_t0, s32 *, 4) = (s32) M2C_FIELD(var_a3, s32 *, 4);
                            var_t0 += 8;
                            var_a2_2 += 1;
                            var_a3 += 8;
                        } while (var_a2_2 < D_800F8D5C);
                    }
                    var_a1 = &D_800F8D60;
                    var_a0 = 0;
                    __repair_rows: {
                        temp_v1_3 = *(&D_800F8D62 + var_a0);
                        if ((s32) temp_t1 < (s32) temp_v1_3) {
                            M2C_FIELD(var_a1, s16 *, 2) = (s16) (temp_v1_3 - 1);
                        }
                        var_a0 += 4;
                        var_a1 += 4;
                    }
if (var_a0 < 0x800) goto __repair_rows;
                    temp_v0_4 = temp_t2 * 4;
                    *(&D_800F8D60 + temp_v0_4) = *(&D_800F8D60 + temp_v0_4) - 1;
                    D_800F8D5C -= 1;
                }
            }
        }
    }
    func_8008C11C();
    return 0;
}
