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

s32 func_800055CC();
s32 func_80005D04(s32, void *, void *, f32);

void func_80005C70(s32 arg0, s32 arg1, s32 arg2, s32 arg3, f32 arg4, s32 arg5) {
    u8 sp10[0x628];
    u8 sp638[0x628];

    func_800055CC(sp10, arg1, arg2, arg5);
    __repair_rows: { func_800055CC(sp638, arg1, arg3, arg5); }
if (0) goto __repair_rows;
    func_80005D04(arg0, sp10, sp638, arg4);
}
