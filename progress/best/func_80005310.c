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

s32 func_80005C70();
s32 func_8000600C();
extern f32 D_800D9414;

void func_80005310(void *arg0) {
    char *var_v0;
    char *var_v0_2;
    f32 temp_fv0;
    f32 temp_fv0_2;
    f32 temp_fv0_3;
    f32 var_fs0;
    f32 var_ft0;
    f32 var_fv1;
    s32 temp_a1;
    s32 temp_t1;
    s32 var_a2;
    s32 var_a3;
    void *temp_t0;
    void *temp_v0;
    void *temp_v0_2;
    void *temp_v1;
    void *temp_v1_2;

    temp_v0 = M2C_FIELD(arg0, void **, 0x68);
    temp_v1 = M2C_FIELD(temp_v0, void **, 0x60);
    var_fs0 = M2C_FIELD(temp_v0, f32 *, 0x30);
    temp_fv0 = M2C_FIELD(temp_v1, f32 *, 0);
    temp_t0 = temp_v0 + 0x14;
    if (temp_fv0 <= var_fs0) {
        do {
            var_fs0 -= temp_fv0;
        } while (temp_fv0 <= var_fs0);
    }
    if (var_fs0 < 0.0f) {
        do {
            var_fs0 += M2C_FIELD(temp_v1, f32 *, 0);
        } while (var_fs0 < 0.0f);
    }
    temp_a1 = M2C_FIELD(temp_v1, s32 *, 4);
    temp_v1_2 = temp_v1 + 0xC;
    var_a2 = (s32) ((var_fs0 * (f32) temp_a1) / M2C_FIELD(temp_v1, f32 *, 0));
    var_v0 = (var_a2 * 4) + temp_v1_2;
    if (!(var_fs0 < *(f32 *)var_v0)) {
        var_a2 += 1;
        var_v0_2 = (var_a2 * 4) + temp_v1_2;
        var_a3 = var_a2 + 1;
        if (*(f32 *)var_v0_2 <= var_fs0) {
            do {
                var_v0_2 += 4;
                var_a2 += 1;
            } while (*(f32 *)var_v0_2 <= var_fs0);
            var_a3 = var_a2 + 1;
        }
    } else {
loop_8:
        var_a3 = var_a2 + 1;
        if (var_a2 != 0) {
            var_v0 -= 4;
            if (var_fs0 < M2C_FIELD(var_v0, f32 *, -4)) {
                var_a2 -= 1;
                goto loop_8;
            }
        }
    }
    temp_t1 = var_a3 & -(var_a3 < temp_a1);
    temp_v0_2 = (var_a2 * 4) + temp_v1_2;
    var_fv1 = M2C_FIELD(temp_v0_2, f32 *, 0);
    var_ft0 = var_fs0;
    if (var_a2 > 0) {
        temp_fv0_2 = M2C_FIELD(temp_v0_2, f32 *, -4);
        var_ft0 = var_fs0 - temp_fv0_2;
        var_fv1 -= temp_fv0_2;
    }
    temp_fv0_3 = var_ft0 / var_fv1;
    if (!(M2C_FIELD(temp_v0, s32 *, 0x14) & 0x40000)) {
        D_800D9414 = temp_fv0_3;
        func_8000600C(arg0, M2C_FIELD(temp_t0, s16 *, 0x7E), var_a2, temp_t1);
        M2C_FIELD(temp_v0, f32 *, 0x30) = var_fs0;
        return;
    }
    func_80005C70(M2C_FIELD(temp_t0, s32 *, 0x44), M2C_FIELD(temp_t0, s16 *, 0x7E), var_a2, temp_t1, temp_fv0_3, M2C_FIELD(temp_v0, s32 *, 0x14) & 1);
    M2C_FIELD(temp_v0, f32 *, 0x30) = var_fs0;
}
