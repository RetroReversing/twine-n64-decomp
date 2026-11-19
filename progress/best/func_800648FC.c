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

s32 func_80063C7C();
extern char D_800C469C[];

s32 func_800648FC(void *arg0, s32 arg1) {
    s16 temp_a1;
    s32 var_v1;
    s32 temp_s2;
    s32 temp_v0;
    s8 temp_a0;
    short temp_a0_2;
    u8 temp_s0;
    void *temp_a2;
    void *temp_s1;
    void *temp_t0;

    temp_a0 = M2C_FIELD(M2C_FIELD(arg0, void **, 0x68), s8 *, 0xE);
    temp_s2 = M2C_FIELD(arg0, s32 *, 0x6C);
    temp_s1 = (temp_a0 * 0xE8) + D_800C469C;
    temp_s0 = M2C_FIELD(temp_s1, u8 *, 0x80);
    temp_v0 = func_80063C7C(temp_a0);
    temp_t0 = (char *)(temp_s2); temp_t0 += (s32)((temp_s0 * 2));
    temp_a1 = M2C_FIELD(temp_t0, s16 *, 0x1BC);
    if (temp_a1 > 0) {
        temp_a0_2 = M2C_FIELD(temp_s1, u8 *, 0x83);
        var_v1 = M2C_FIELD(temp_s1, u8 *, 0x82) - M2C_FIELD((temp_a2 = temp_s2 + ((s32) (temp_v0 << 0x10) >> 0xD)), s8 *, 0x1FF);
        if ((s32) temp_a0_2 < var_v1) {
            var_v1 = (s16) temp_a0_2;
        }
        if (temp_a1 < var_v1) {
            var_v1 = temp_a1;
        }
        if (temp_a1 != 0) {
            if ((arg1 << 0x18) != 0) {
                return 1;
            }
            M2C_FIELD(temp_t0, s16 *, 0x1BC) = (s16) (temp_a1 - temp_a1);
            M2C_FIELD(temp_a2, s8 *, 0x1FF) = (s8) ((u8) M2C_FIELD(temp_a2, s8 *, 0x1FF) + temp_a1);
            return 1;
        }
        goto block_10;
    }
block_10:
    return 0;
}
