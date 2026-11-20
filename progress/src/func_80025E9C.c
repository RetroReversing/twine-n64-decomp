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

s32 func_80025F78();
s32 formatTextEntry();
s32 func_80087100();

extern char D_800D2AF0[];
void func_80025E9C(void *arg0, s32 arg1, void *arg2, void *arg3, u16 arg4, u16 arg5) {

    func_80025F78(arg0, arg5);
    func_80025F78(arg1, arg5);
    if (arg1 != 0) {
        formatTextEntry(arg1, D_800D2AF0, func_80087100(0x13));
    }
    if (((arg0 != NULL) & (arg2 != NULL)) && (arg3 != NULL)) {
        if (arg4 != 0) {
            M2C_FIELD(arg2, u8 *, 0x27) = (u8) M2C_FIELD(arg0, u8 *, 0x27);
            M2C_FIELD(arg3, u8 *, 0x26) = (u8) M2C_FIELD(arg0, u8 *, 0x26);
            return;
        }
        M2C_FIELD(arg2, u8 *, 0x25) = (u8) M2C_FIELD(arg0, u8 *, 0x25);
        M2C_FIELD(arg3, u8 *, 0x24) = (u8) M2C_FIELD(arg0, u8 *, 0x24);
    }
}
