static __inline__ s16 __repair_inline(s16 a) { return a; }
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

s16 func_80096E7C();
extern char D_80112E9E[];

s32 func_8009AE24(s32 arg0, void *arg1, s32 arg2) {
    s16 var_a0;
    s16 var_s0;
    s32 temp_a2;
    s32 temp_v0;
    s32 temp_v0_2;
    s32 var_s2;
    u32 temp_v1;
    u32 temp_v1_2;
    u32 temp_v1_3;
    
    u32 temp_v1_5;

    temp_v1 = M2C_FIELD(arg1, u32 *, 0);
    temp_v1_5 = temp_v1 >> 0x10;
    if ((temp_v1 >> 8) & 0xFF) {
        var_s0 = func_80096E7C(arg0, temp_v1_5 & 0xFF);
    } else {
        temp_v1_3 = temp_v1_5 & 0x1F;
        temp_v0 = temp_v1_3 * 2;
        if (temp_v1_3 < 0x10U) {
            var_s0 = M2C_FIELD((temp_v0 + arg0), s16 *, 0x180);
        } else {
            var_s0 = __repair_inline(*(u16 *)(D_80112E9E + temp_v0));
        }
    }
    temp_v1_3 = M2C_FIELD(arg1, u32 *, 4);
    if ((u8) M2C_FIELD(arg1, u32 *, 0) != 0) {
        var_a0 = func_80096E7C(arg0, temp_v1_3 & 0xFF);
    } else {
        temp_v1_5 = temp_v1_3 & 0x1F;
        temp_v0_2 = temp_v1_5 * 2;
        if (temp_v1_5 < 0x10U) {
            var_a0 = M2C_FIELD((temp_v0_2 + arg0), s16 *, 0x180);
        } else {
            var_a0 = *(u16 *)(D_80112E9E + temp_v0_2);
        }
    }
    temp_a2 = arg2 & 0xFF;
    switch (temp_a2) {                              /* irregular */
    case 0:
        var_s2 = ((var_s0 ^ var_a0) << 0x10) == 0;
        break;
    case 1:
        var_s2 = var_s0 < var_a0;
        break;
    }
    if (M2C_FIELD(arg1, u8 *, 6) != 0) {
        temp_a2 = var_s2 & 0xFF;
    var_s2 = (temp_a2) == 0;
    }
    if (var_s2 & 0xFF) {
        M2C_FIELD(arg0, s32 *, 4) = (s32) (M2C_FIELD(arg0, s32 *, 0) + (((u32) M2C_FIELD(arg1, u32 *, 4) >> 0x10) * 8));
    }
    return 0;
}
