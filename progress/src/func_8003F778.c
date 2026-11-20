/* machine draft (m2c) for gcc-2.7.2-kmc -G0 -mips3 -mgp32 -mfp32 -O2 -fno-strength-reduce -fno-schedule-insns, tried by autopilot */
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

s32 clip_verts_z_planes();
extern void *clip_result_verts;
extern char clip_buffer_a[];
extern char D_800E177C[];
extern char D_800E1780[];

s32 func_8003F778(void *arg0, void *arg1, s32 arg2) {
    f32 temp_fv0;
    f32 temp_fv0_2;
    s32 temp_v0;
    s32 var_a3;
    
    s32 var_v1;
    void *var_a0;
    void *var_a1;
    void *var_v1_2;
/* Inferred frame reservation; original purpose unknown. */
char __repair_stack_padding[16];

    var_a1 = arg1;
    var_a3 = 0;
    if (arg2 > 0) {
        var_v1 = 0;
        do {
            *(f32 *)(clip_buffer_a + var_v1) = M2C_FIELD(var_a1, f32 *, 0);
            var_a3 += 1;
            *(f32 *)(D_800E177C + var_v1) = M2C_FIELD(var_a1, f32 *, 4);
            temp_fv0 = M2C_FIELD(var_a1, f32 *, 8);
            var_a1 += 0x24;
            *(f32 *)(D_800E1780 + var_v1) = temp_fv0;
            var_v1 += 0x24;
        } while (var_a3 < arg2);
    }
    temp_v0 = clip_verts_z_planes(arg2, var_a1);
    var_a3 = 0;
    if (temp_v0 > 0) {
        var_a0 = arg0;
        var_v1_2 = clip_result_verts;
        do {
            M2C_FIELD(var_a0, f32 *, 0) = (f32) M2C_FIELD(var_v1_2, f32 *, 0);
            var_a3 += 1;
            M2C_FIELD(var_a0, f32 *, 4) = (f32) M2C_FIELD(var_v1_2, f32 *, 4);
            temp_fv0_2 = M2C_FIELD(var_v1_2, f32 *, 8);
            var_v1_2 += 0x24;
            M2C_FIELD(var_a0, f32 *, 8) = temp_fv0_2;
            var_a0 += 0x24;
        } while (var_a3 < temp_v0);
    }
    return temp_v0;
}
