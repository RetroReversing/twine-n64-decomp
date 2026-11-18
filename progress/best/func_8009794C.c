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

M2C_UNK func_8008C0D4(s32);                         /* extern */
M2C_UNK func_8008C11C();                            /* extern */
extern M2C_UNK D_800F38E4;
extern s32 D_800F38EC;
extern M2C_UNK D_800F38F0;

s32 func_8009794C(s32 arg0) {
    s32 temp_v0;
    s32 var_a2;
    s32 var_s0;
    s32 var_v0;
    s32 var_v1;
    void *var_a3;
    void *var_t0;

    var_s0 = 0;
    if (D_800F38EC > 0) {
        var_v1 = 0;
loop_2:
        if (*(&D_800F38F0 + var_v1) != arg0) {
            var_s0 += 1;
            var_v1 += 0xC;
            if (var_s0 < D_800F38EC) {
                goto loop_2;
            }
        }
    }
    var_v0 = 0;
    if (var_s0 != D_800F38EC) {
        func_8008C0D4(D_800F38EC);
        var_a2 = var_s0 + 1;
        if (var_a2 < D_800F38EC) {
            temp_v0 = var_a2 * 0xC;
            var_t0 = temp_v0 + &D_800F38E4;
            var_a3 = temp_v0 + (&D_800F38E4 + 0xC);
            __repair_rows: {
                M2C_FIELD(var_t0, s32 *, 0) = (s32) M2C_FIELD(var_a3, s32 *, 0);
                M2C_FIELD(var_t0, s32 *, 4) = (s32) M2C_FIELD(var_a3, s32 *, 4);
                M2C_FIELD(var_t0, s32 *, 8) = (s32) M2C_FIELD(var_a3, s32 *, 8);
                var_t0 += 0xC;
                var_a2 += 1;
                var_a3 += 0xC;
            }
if (var_a2 < D_800F38EC) goto __repair_rows;
        }
        D_800F38EC -= 1;
        func_8008C11C();
        var_v0 = 1;
    }
    return var_v0;
}
