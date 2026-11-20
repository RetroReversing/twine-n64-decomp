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

extern u16 *D_80109A50;

void func_8000B478(s32 arg0) {
    u16 *var_a1;
    u16 *var_t0;
    u16 var_a2;
    void *temp_v1;

    if ((arg0 != 0) && (var_a1 = D_80109A50, var_a2 = *var_a1, var_t0 = NULL, ((var_a2 & 8) == 0))) {
loop_3:
        temp_v1 = (char *)var_a1 + M2C_FIELD(var_a1, s32 *, 4);
        if ((var_a2 & 2) && ((arg0 - 0x10) == var_a1)) {
            M2C_FIELD(var_a1, u16 *, 0) = 1;
            if (M2C_FIELD(temp_v1, u16 *, 0x10) & 1) {
                M2C_FIELD(var_a1, s32 *, 4) += 0x10 + M2C_FIELD(temp_v1, s32 *, 0x14);
            }
            if ((var_t0 != NULL) && (M2C_FIELD(var_t0, u16 *, 0) & 1)) {
                M2C_FIELD(var_t0, s32 *, 4) += 0x10 + M2C_FIELD(var_a1, s32 *, 4);
            }
        } else {
            var_t0 = var_a1;
            var_a1 = temp_v1 + 0x10;
            var_a2 = M2C_FIELD(temp_v1, u16 *, 0x10);
            if (var_a2 & 8) {

            } else {
                goto loop_3;
            }
        }
    }
}
