/* machine draft (m2c) for gcc-2.7.2-kmc -G0 -mips3 -mgp32 -mfp32 -O1, tried by autopilot */
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

s32 func_800422F4();
s32 func_800426B8();
extern void *D_80109688;

void func_80044D28(s16 *arg0) {
    char *var_s0;
    s16 temp_a1;

    var_s0 = arg0;
    if (*arg0 >= 0) {
        do {
            func_800422F4(*(s16 *)var_s0);
            temp_a1 = *(s16 *)var_s0;
            var_s0 += 2;
            func_800426B8(M2C_FIELD(D_80109688, s32 *, 8), temp_a1, 1);
        } while (*(s16 *)var_s0 >= 0);
    }
}
