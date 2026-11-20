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

extern char D_800F37E0[];
extern char D_800F3860[];

void func_8009692C(s32 arg0, s32 arg1, s8 arg2) {
    char *__base_D_800F37E0;
    s32 temp_v1;

    temp_v1 = arg1 & 0xFF;
    if (temp_v1 != 0xFF) {
        __base_D_800F37E0 = D_800F37E0;
        __base_D_800F37E0 += temp_v1 * 0x10;
        __base_D_800F37E0[arg0 & 0xFF] = arg2;
        return;
    }
    *(D_800F3860 + (arg0 & 0xFF)) = arg2;
}
