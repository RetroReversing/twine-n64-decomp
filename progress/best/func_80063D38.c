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

s32 func_80063CFC();
extern u8 D_800C471C[];

s32 func_80063D38(s32 arg0, s16 arg1) {
    s32 temp_s0;
    s32 var_v0;

    temp_s0 = arg1 * 0xE8;
    var_v0 = 1;
    if (M2C_FIELD((arg0 + (*(D_800C471C + temp_s0) * 2)), s16 *, 0x1BC) == 0) {
        var_v0 = 1;
        if ((func_80063CFC(arg0, arg1) << 0x10) == 0) {
            var_v0 = *(D_800C471C + temp_s0) == 0;
        }
    }
    return var_v0;
}
