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

s32 __osMotorAccess();
extern char D_800E0790[];
extern char D_8010A3A0[];

void func_800105F8(u16 arg0) {
    char *__base_D_800E0790;
    s32 temp_s1;
    s32 var_s0;
    u16 *temp_v0;
    void *var_a0;

    var_s0 = 0;
    temp_s1 = arg0 * 0x68;
    __base_D_800E0790 = D_800E0790;
    do {
        __osMotorAccess((void *) ((temp_s1) + (s32) __base_D_800E0790), 0);
        var_s0 += 1;
    } while (var_s0 < 3);
    {
        s32 index = arg0;
        char *base = D_8010A3A0;
        temp_v0 = (u16 *)(base + index * 2);
    }
    *temp_v0 &= 0xFFFE;
}
