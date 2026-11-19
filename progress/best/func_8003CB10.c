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

f32 func_800828D0();
f32 func_80082908();

void func_8003CB10(void *arg0, f32 *arg1, void *arg2, s32 arg3) {
char *__repair_addr;

    f32 *temp_s0;
    f32 *temp_v0;
    char *var_a1;
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
    s32 var_a3;
    u16 temp_v1;
    void *temp_v1_2;

    var_a1 = arg1;
    var_a3 = arg3;
    temp_s0 = var_a1;
    if ((arg0 != NULL) && (temp_s0 != NULL)) {
        temp_v0 = M2C_FIELD(arg0, f32 **, 0x34);
        temp_v1 = M2C_FIELD(arg0, u16 *, 0x42);
        var_fs0 = M2C_FIELD(temp_v0, f32 *, 0);
        var_fs3 = M2C_FIELD(temp_v0, f32 *, 4);
        var_fs4 = M2C_FIELD(temp_v0, f32 *, 8);
        var_fa0 = var_fs0;
        var_fs1 = var_fs3;
        var_fs5 = var_fs4;
        if (temp_v1 != 0) {
            var_a3 = 0;
            var_a1 = temp_v0;
            temp_v1_2 = (temp_v1 * 0xC) + var_a1;
            do {
                temp_fv0 = *(f32 *)var_a1;
                if (temp_fv0 < var_fa0) {
                    var_fa0 = temp_fv0;
                } else if (var_fs0 < temp_fv0) {
                    var_fs0 = temp_fv0;
                }
__repair_addr = (char *)((var_a3 + M2C_FIELD(arg0, f32 **, 0x34)));

                temp_fv0_2 = M2C_FIELD(__repair_addr, f32 *, 4);
                if (temp_fv0_2 < var_fs1) {
                    var_fs1 = temp_fv0_2;
                } else if (var_fs3 < temp_fv0_2) {
                    var_fs3 = temp_fv0_2;
                }
                temp_fv0_3 = M2C_FIELD((var_a3 + M2C_FIELD(arg0, f32 **, 0x34)), f32 *, 8);
                if (temp_fv0_3 < var_fs5) {
                    var_fs5 = temp_fv0_3;
                } else if (var_fs4 < temp_fv0_3) {
                    var_fs4 = temp_fv0_3;
                }
                var_a1 += 0xC;
                var_a3 += 0xC;
            } while ((s32) var_a1 < (s32) temp_v1_2);
        }
        M2C_FIELD(arg2, f32 *, 4) = var_fs0;
        M2C_FIELD(arg2, f32 *, 0xC) = var_fs3;
        M2C_FIELD(arg2, f32 *, 0x14) = var_fs4;
        M2C_FIELD(arg2, f32 *, 0) = var_fa0;
        M2C_FIELD(arg2, f32 *, 8) = var_fs1;
        M2C_FIELD(arg2, f32 *, 0x10) = var_fs5;
        var_fs2 = func_800828D0(arg0);
        if (var_fs2 < func_800828D0(var_fs0)) {
            var_fs2 = var_fs0;
        }
        var_fs1_2 = func_800828D0(var_fs1);
        if (var_fs1_2 < func_800828D0(var_fs3)) {
            var_fs1_2 = var_fs3;
        }
        var_fs0_2 = func_800828D0(var_fs5);
        if (var_fs0_2 < func_800828D0(var_fs4)) {
            var_fs0_2 = var_fs4;
        }
        M2C_FIELD(temp_s0, f32 *, 0xC) = func_80082908((var_fs2 * var_fs2) + (var_fs1_2 * var_fs1_2) + (var_fs0_2 * var_fs0_2));
        M2C_FIELD(temp_s0, f32 *, 0) = 0.0f;
        M2C_FIELD(temp_s0, s32 *, 4) = 0;
        M2C_FIELD(temp_s0, s32 *, 8) = 0;
    }
}
