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

extern u32 D_800E1550;
extern s8 D_800E1554;
extern s8 D_800E1556;

s32 func_8002E848(void *arg0, s32 arg1, u32 arg2) {
    s32 temp_v1;
    s32 var_t0;
    s8 temp_a1;
    s32 temp_v0_2;
    u32 temp_v0;
    u8 *temp_a3;

    D_800E1550 = 0;
    var_t0 = 0;
    if (arg2 != 0) {
        do {
            temp_a3 = M2C_FIELD(arg0, u8 **, 0);
            temp_v0_2 = 1 << M2C_FIELD(arg0, s32 *, 4);
            temp_a1 = 1 << D_800E1550;
            D_800E1554 = temp_v0_2;
            D_800E1556 = temp_a1;
            if (*temp_a3 & temp_v0_2) {
                var_t0 |= temp_a1 & 0xFF;
            }
            temp_v1 = M2C_FIELD(arg0, s32 *, 4);
            if ((temp_v1 & 7) == 7) {
                M2C_FIELD(arg0, u8 **, 0) = (u8 *) (temp_a3 + 1);
                M2C_FIELD(arg0, s32 *, 4) = 0;
            } else {
                M2C_FIELD(arg0, s32 *, 4) = (s32) (temp_v1 + 1);
            }
            temp_v0 = D_800E1550 + 1;
            D_800E1550 = temp_v0;
        } while (temp_v0 < arg2);
    }
    return var_t0;
}
