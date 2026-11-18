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

s32 func_800165E0();

void func_80016624(void *arg0, s32 *arg1, s32 arg2) {
    s32 *temp_v0;
    s32 *temp_v0_2;
    s32 *var_v0;
    s32 *var_v1;

    var_v0 = M2C_FIELD(arg1, s32 **, 4);
    var_v1 = var_v0;
    if (var_v0 != NULL) {
loop_1:
        if (var_v0 != arg0) {
            var_v1 = var_v0;
            var_v0 = M2C_FIELD(var_v0, s32 **, 4);
            if (var_v0 != NULL) {
                goto loop_1;
            }
        } else if (var_v1 != arg0) {
            M2C_FIELD(var_v1, s32 **, 4) = (s32 *) M2C_FIELD(arg0, s32 **, 4);
            temp_v0 = M2C_FIELD(arg0, s32 **, 4);
            if (temp_v0 != NULL) {
                *temp_v0 = var_v1;
            }
        } else {
            M2C_FIELD(arg1, s32 **, 4) = (s32 *) M2C_FIELD(arg0, s32 **, 4);
            temp_v0_2 = M2C_FIELD(arg0, s32 **, 4);
            if (temp_v0_2 != NULL) {
                *temp_v0_2 = arg1;
            }
        }
    }
    func_800165E0(arg0, arg2);
}
