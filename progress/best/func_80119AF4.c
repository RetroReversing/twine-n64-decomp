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

s32 func_80022DBC(s32);                             /* extern */
s32 func_80063D38(void *, u8);                      /* extern */
M2C_UNK func_8007089C(void *, M2C_UNK, s32);        /* extern */
extern M2C_UNK D_800BF68A;
extern M2C_UNK D_800C469E;
extern M2C_UNK D_8010019C;
extern M2C_UNK D_8011ECC0;

void func_80119AF4(void *arg0) {
    u32 temp_s5;
    u8 *var_s1;
    u8 temp_s0;
    u8 var_s2;
    void *temp_s3;

    temp_s3 = M2C_FIELD(arg0, void **, 0x6C);
    var_s1 = *(&D_8011ECC0 + (*(&D_800BF68A + (*(&D_8010019C + ((func_80022DBC((s8) M2C_FIELD(temp_s3, u8 *, 0x182) & 0xFFFF) & 0xFFFF) * 0x18)) * 0xC)) * 4));
    var_s2 = -1U;
    temp_s5 = var_s1 + 0x3B;
loop_1:
    temp_s0 = *var_s1;
    if ((M2C_FIELD((temp_s3 + (*(&D_800C469E + (temp_s0 * 0xE8)) * 8)), u8 *, 0x1FC) != 0) && ((func_80063D38(temp_s3, temp_s0) << 0x18) != 0)) {
        var_s2 = temp_s0;
    } else {
        var_s1 += 1;
        if ((u32) var_s1 < temp_s5) {
            goto loop_1;
        }
    }
    if ((var_s2 != -1U) && (M2C_FIELD(M2C_FIELD(arg0, void **, 0x68), s8 *, 0xE) != var_s2)) {
        func_8007089C(arg0, 0, var_s2 & 0xFFFF);
    }
}
