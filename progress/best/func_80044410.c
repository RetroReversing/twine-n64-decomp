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

M2C_UNK func_80084048(s32, M2C_UNK);                /* extern */
extern M2C_UNK D_800C0784;
extern M2C_UNK D_800C0788;
extern M2C_UNK D_800C078C;
extern u32 D_80100914;
extern u8 D_80109A35;

void func_80044410(s8 arg0) {
    s32 var_s2;
    u32 temp_v0_2;
    u32 var_s1;
    u32 var_s3;
    u8 temp_v0;
    u8 temp_v1;
    void *var_s0;

    if (D_80109A35 != 0) {
        var_s3 = 0;
        if (D_80100914 != 0) {
            var_s2 = 0;
            __repair_rows: {
                if (*(&D_800C0784 + var_s2) != 0) {
                    var_s1 = 0;
                    if (*(&D_800C078C + var_s2) != 0) {
                        var_s0 = *(&D_800C0788 + var_s2);
                        do {
                            temp_v1 = M2C_FIELD(var_s0, u8 *, 0x46);
                            if (!(temp_v1 & 0x80)) {
                                temp_v0 = temp_v1 - 1;
                                if (temp_v1 != 0) {
                                    M2C_FIELD(var_s0, u8 *, 0x46) = temp_v0;
                                    temp_v0_2 = temp_v0 & 0xFF;
                                    if (temp_v0_2 == 0) {
                                        func_80084048(M2C_FIELD(var_s0, s32 *, 0), 0x2E);
                                        M2C_FIELD(var_s0, s32 *, 0) = 0;
                                    } else if ((arg0 != 0) && (temp_v0_2 >= 5U)) {
                                        M2C_FIELD(var_s0, u8 *, 0x46) = 0U;
                                    }
                                }
                            }
                            var_s1 += 1;
                            var_s0 += 0x4C;
                        } while (var_s1 < (u32) *(&D_800C078C + var_s2));
                    }
                }
                var_s3 += 1;
                var_s2 += 0x10;
            }
if (var_s3 < (u32) D_80100914) goto __repair_rows;
        }
    }
}
