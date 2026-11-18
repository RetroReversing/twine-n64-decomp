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

s32 func_80082164();
extern char D_8011508B[];
extern char D_80115091[];
extern char D_80115092[];
extern char D_80115094[];
extern char D_80115095[];

void func_80081BC4(s32 arg0, u16 arg1, s32 arg2) {
    s32 temp_v1;
    s32 var_a2;
    s32 var_v1;

    var_a2 = arg2;
    temp_v1 = arg0 * 0xA0;
    if (*(D_80115092 + temp_v1) != arg1) {
        *(D_80115092 + temp_v1) = arg1;
        switch (arg1) {
        default:
            *(D_8011508B + (arg0 * 0xA0)) = 0;
            var_a2 = 0;
            break;
        case 0:
        case 1:
        case 4:
        case 5:
            *(D_8011508B + (arg0 * 0xA0)) = 1;
            var_a2 = 0;
            break;
        }
        var_v1 = arg0 * 0xA0;
        do {
            var_a2 += 1;
            *(D_80115095 + var_v1) = 0;
            *(D_80115094 + var_v1) = *(D_80115094 + var_v1) & 0x1D;
            var_v1 += 2;
        } while (var_a2 < 0x3A);
    }
    *(D_80115091 + (arg0 * 0xA0)) = (s8) arg1;
    func_80082164(arg0, arg1, var_a2);
}
