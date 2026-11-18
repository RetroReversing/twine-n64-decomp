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

extern short D_800E1112;
s32 func_8001187C();
s32 sprintf();
extern char D_800E10D0[];

void func_8002CA90(s32 arg0) {
    sprintf(D_800E10D0, "%s\0\0TWINE", arg0);
    D_800E1112 = 0xF;
    M2C_FIELD(&D_800E1112, s16 *, -2) = 0;
    func_8001187C(D_800E10D0, &D_800E1112 - 2, 0x200);
}
