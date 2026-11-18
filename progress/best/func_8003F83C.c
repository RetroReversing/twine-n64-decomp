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

s32 func_8003EC70(s32);                /* extern */
extern void *D_800E1770;
extern M2C_UNK D_800E1778;
extern M2C_UNK D_800E177C;
extern M2C_UNK D_800E1780;

s32 func_8003F83C(void *arg0, void *arg1, s32 arg2) {
    f32 temp_fv0;
    f32 temp_fv0_2;
    s32 temp_v0;
    s32 var_a3;
    s32 var_a3_2;
    s32 var_v1;
    void *var_a0;
    void *var_a1;
    void *var_v1_2;

    var_a1 = arg1;
    var_a3 = 0;
    if (arg2 > 0) {
        var_v1 = 0;
        do { {
            *((M2C_UNK *)((s8 *)&D_800E1778 + var_v1)) = M2C_FIELD(var_a1, f32 *, 0);
            *((M2C_UNK *)((s8 *)&D_800E177C + var_v1)) = M2C_FIELD(var_a1, f32 *, 4);
            temp_fv0 = 1.0f / M2C_FIELD(var_a1, f32 *, 8);
            var_a3 += 1;
            var_a1 += 0x24;
            *((M2C_UNK *)((s8 *)&D_800E1780 + var_v1)) = temp_fv0;
            var_v1 += 0x24;
        }
} while (var_a3 < arg2);
    }
    temp_v0 = func_8003EC70(arg2);
    var_a3_2 = 0;
    if (temp_v0 > 0) {
        var_a0 = arg0;
        var_v1_2 = D_800E1770;
        __repair_rows: {
            M2C_FIELD(var_a0, f32 *, 0) = (f32) M2C_FIELD(var_v1_2, f32 *, 0);
            M2C_FIELD(var_a0, f32 *, 4) = (f32) M2C_FIELD(var_v1_2, f32 *, 4);
            temp_fv0_2 = 1.0f / M2C_FIELD(var_v1_2, f32 *, 8);
            var_a3_2 += 1;
            var_v1_2 += 0x24;
            M2C_FIELD(var_a0, f32 *, 8) = temp_fv0_2;
            var_a0 += 0x24;
        }
if (var_a3_2 < temp_v0) goto __repair_rows;
    }
    return temp_v0;
}
