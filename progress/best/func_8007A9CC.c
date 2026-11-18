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

s32 func_80000A30();
s32 func_8007A974();
f32 func_800828D0();

s32 func_8007A9CC(void *arg0, s32 arg1, s32 *arg2, f32 arg3) {
    s32 var_v0;

    func_8007A974(arg0, arg1, arg2);
    var_v0 = 1;
    if (!(func_800828D0((f32) func_80000A30(*arg2, M2C_FIELD(M2C_FIELD(arg0, void **, 0x68), s16 *, 0x8C))) < arg3)) {
        var_v0 = 0;
    }
    return var_v0;
}
