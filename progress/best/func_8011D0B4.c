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

s32 func_80022DBC();
s32 func_80073AF8();
s32 func_80087100();
s32 sprintf();
extern char D_801001A4[];
extern s32 D_8010969C;
extern char D_8011F010[];

void func_8011D0B4(s32 arg0) {
    char sp30[0x20];
    void *temp_s0;

    temp_s0 = ((func_80022DBC(arg0 & 0xFFFF) & 0xFFFF) * 0x18) + D_801001A4;
    sprintf(sp30, D_8011F010, temp_s0, func_80087100(0x28B));
    func_80073AF8(0, D_8010969C, sp30, -1, -1, 1, 0, 0, 6, 0, 0x3C);
}
