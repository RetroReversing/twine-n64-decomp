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

s32 func_800109CC();
s32 func_80011800();
extern char D_800E0790[];
extern char D_80109DC8[];

void func_80013374(void) {
    s16 *temp_s1;
    s32 var_a2;
    s32 var_s0;

    var_s0 = 0;
    var_a2 = 0 & 0xFFFF;
    do {
        temp_s1 = (var_a2 * 2) + D_80109DC8;
        *temp_s1 = 0;
        func_80011800(0xC, (var_a2 * 0x68) + D_800E0790, var_a2, 0, 0, 0, 0, 0);
        if (func_800109CC() == 0) {
            *temp_s1 = 1;
        }
        var_s0 += 1;
        var_a2 = var_s0 & 0xFFFF;
    } while ((u32) (var_s0 & 0xFFFF) < 4U);
}
