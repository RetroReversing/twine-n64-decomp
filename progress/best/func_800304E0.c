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

s32 func_8002FBD4();
s32 func_8002FFAC();
s32 func_80030108();

void func_800304E0(s32 arg0, void *arg1) {
    s32 var_a1;
    s16 temp_v1;

    temp_v1 = M2C_FIELD(arg1, s16 *, 0x7A);
    switch (temp_v1) {
    case 3:
        M2C_FIELD(arg1, s16 *, 0x7A) = 1;
        return;
    case 1:
        if (func_80030108() & 0xFF) {
            var_a1 = 2;
block_7:
            func_8002FBD4(arg1, var_a1);
        }
    default:
    case 2:
    case 4:
        return;
    case 0:
        if (func_8002FFAC() & 0xFF) {
            var_a1 = 4;
            goto block_7;
        }
        break;
    }
}
