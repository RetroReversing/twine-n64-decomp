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

f32 absFloat(f32);
f32 func_80082908(f32);

void func_8003CD18(s32 arg0, void *arg1, void *arg2, void *arg3) {
    f32 temp_fv0;
    f32 temp_fv0_2;
    f32 temp_fv0_3;
    f32 var_fa0;
    f32 var_fs0;
    f32 var_fs0_2;
    f32 var_fs1;
    f32 var_fs1_2;
    f32 var_fs2;
    f32 var_fs3;
    f32 var_fs4;
    f32 var_fs5;
    void *temp_v1;
    void *var_a1;

    var_a1 = arg1;
    if (arg2 != NULL) {
        var_fs0 = M2C_FIELD(var_a1, f32 *, 0);
        var_fs2 = M2C_FIELD(var_a1, f32 *, 4);
        var_fs4 = M2C_FIELD(var_a1, f32 *, 8);
        var_fa0 = var_fs0;
        var_fs1 = var_fs2;
        var_fs5 = var_fs4;
        if (arg0 != 0) {
            temp_v1 = (void *) (((arg0 * 0xC)) + (s32) var_a1);
            do {
                temp_fv0 = M2C_FIELD(var_a1, f32 *, 0);
                if (temp_fv0 < var_fa0) {
                    var_fa0 = temp_fv0;
                } else if (var_fs0 < temp_fv0) {
                    var_fs0 = temp_fv0;
                }
                temp_fv0_2 = M2C_FIELD(var_a1, f32 *, 4);
                if (temp_fv0_2 < var_fs1) {
                    var_fs1 = temp_fv0_2;
                } else if (var_fs2 < temp_fv0_2) {
                    var_fs2 = temp_fv0_2;
                }
                temp_fv0_3 = M2C_FIELD(var_a1, f32 *, 8);
                if (temp_fv0_3 < var_fs5) {
                    var_fs5 = temp_fv0_3;
                } else if (var_fs4 < temp_fv0_3) {
                    var_fs4 = temp_fv0_3;
                }
                var_a1 += 0xC;
            } while ((u32) var_a1 < (u32) temp_v1);
        }
        M2C_FIELD(arg3, f32 *, 4) = var_fs0;
        M2C_FIELD(arg3, f32 *, 0xC) = var_fs2;
        M2C_FIELD(arg3, f32 *, 0x14) = var_fs4;
        M2C_FIELD(arg3, f32 *, 0) = var_fa0;
        M2C_FIELD(arg3, f32 *, 8) = var_fs1;
        M2C_FIELD(arg3, f32 *, 0x10) = var_fs5;
        var_fs3 = absFloat(var_fa0);
        if (var_fs3 < absFloat(var_fs0)) {
            var_fs3 = var_fs0;
        }
        var_fs1_2 = absFloat(var_fs1);
        if (var_fs1_2 < absFloat(var_fs2)) {
            var_fs1_2 = var_fs2;
        }
        var_fs0_2 = absFloat(var_fs5);
        if (var_fs0_2 < absFloat(var_fs4)) {
            var_fs0_2 = var_fs4;
        }
        M2C_FIELD(arg2, f32 *, 0xC) = func_80082908((var_fs3 * var_fs3) + (var_fs1_2 * var_fs1_2) + (var_fs0_2 * var_fs0_2));
        M2C_FIELD(arg2, s32 *, 0) = 0;
        M2C_FIELD(arg2, s32 *, 4) = 0;
        M2C_FIELD(arg2, s32 *, 8) = 0;
    }
}
