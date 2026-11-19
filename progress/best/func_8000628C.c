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

f32 func_80046140();
f32 func_80082A70();
extern u8 D_800CA338;

s16 func_8000628C(void *arg0, void *arg1, s32 arg2, s32 arg3) {
    f32 temp_fs0;
    f32 temp_fs1;
    f32 temp_fs2;
    f32 var_ft1;
    s16 temp_a0;
    s16 temp_a0_2;
    s16 temp_v1_3;
    
    s16 var_v0_5;
    
    s32 var_a0_2;
    s32 var_a1;
    
    s32 var_v0;
    s32 var_v0_2;
    s32 var_v0_4;
    s32 var_v1;
    u16 temp_v0_2;
    u16 temp_v0_3;
    void *temp_a2;
    void *temp_s1;
    union { void * pointer; s32 value; } __repair_phase_storage;
    
    void *temp_v1_2;
    void *temp_v1_4;
    void *temp_v1_5;
    void *temp_v1_6;

    temp_a2 = M2C_FIELD(arg0, void **, 0x68);
    temp_s1 = temp_a2 + 0x14;
    if (arg1 != NULL) {
        var_ft1 = 0.2f;
        M2C_FIELD(temp_a2, s32 *, 0x14) |= 0x180000;
        if (D_800CA338 != 0) {
            var_ft1 = 0.0f;
        }
        __repair_phase_storage.pointer = M2C_FIELD(M2C_FIELD(arg0, void **, 0x68), void **, 0);
        temp_fs1 = M2C_FIELD(arg1, f32 *, 0) - M2C_FIELD(__repair_phase_storage.pointer, f32 *, 0);
        temp_fs0 = M2C_FIELD(arg1, f32 *, 8) - M2C_FIELD(__repair_phase_storage.pointer, f32 *, 8);
        temp_fs2 = (M2C_FIELD(arg1, f32 *, 4) - M2C_FIELD(__repair_phase_storage.pointer, f32 *, 0xAC)) + var_ft1;
        var_a0_2 = (s32) ((f32) (s32) (func_80082A70(-temp_fs1, temp_fs0, D_800CA338) * 651.8986f) + M2C_FIELD(arg0, f32 *, 0x40)) & 0xFFF;
        if (var_a0_2 >= 0x800) {
            var_a0_2 -= 0x1000;
        }
        var_a1 = (s32) (func_80082A70(temp_fs2, func_80046140(temp_fs1)) * 651.8986f);
        var_v1 = arg2 * 2;
    } else {
        var_a0_2 = 0;
        var_a1 = 0;
        var_v1 = arg2 * 2;
    }
    temp_a2 = var_v1 + temp_s1;
    __repair_phase_storage.value = (s32) ((var_a0_2 - M2C_FIELD(temp_a2, s16 *, 0x94)) * arg3) >> 7;
    if (__repair_phase_storage.value < -0x40) {
        __repair_phase_storage.value = -0x40;
    } else if (__repair_phase_storage.value >= 0x41) {
        __repair_phase_storage.value = 0x40;
    }
    temp_v1_2 = (arg2 * 2) + temp_s1;
    temp_v0_2 = M2C_FIELD(temp_v1_2, u16 *, 0x94) + __repair_phase_storage.value;
    M2C_FIELD(temp_v1_2, u16 *, 0x94) = temp_v0_2;
    if (__repair_phase_storage.value >= 0) {
        var_v0_2 = var_a0_2 < (s16) temp_v0_2;
    } else {
        var_v0_2 = (s16) temp_v0_2 < var_a0_2;
    }
    if (var_v0_2 != 0) {
        M2C_FIELD(temp_v1_2, u16 *, 0x94) = (u16) var_a0_2;
    }
    if (arg2 == 0) {
        temp_v1_3 = M2C_FIELD(temp_s1, s16 *, 0x94);
        if (temp_v1_3 < -0x384) {
            M2C_FIELD(temp_s1, s16 *, 0x94) = -0x384;
        } else if (temp_v1_3 >= 0x385) {
            M2C_FIELD(temp_s1, s16 *, 0x94) = 0x384;
        }
    } else {
        temp_v1_4 = (arg2 * 2) + temp_s1;
        temp_a0 = M2C_FIELD(temp_v1_4, s16 *, 0x94);
        temp_v1_3 = -0x1C2;
        if ((temp_a0 < -0x1C2) || (temp_v1_3 = 0x1C2, ((temp_a0 < 0x1C3) == 0))) {
            M2C_FIELD(temp_v1_4, s16 *, 0x94) = temp_v1_3;
        }
    }
    var_a0_2 = (s32) ((var_a1 - M2C_FIELD(temp_a2, s16 *, 0x98)) * arg3) >> 7;
    if (var_a0_2 < -0x40) {
        var_a0_2 = -0x40;
    } else if (var_a0_2 >= 0x41) {
        var_a0_2 = 0x40;
    }
    temp_v1_5 = temp_s1 + (arg2 * 2);
    temp_v0_3 = M2C_FIELD(temp_v1_5, u16 *, 0x98) + var_a0_2;
    M2C_FIELD(temp_v1_5, u16 *, 0x98) = temp_v0_3;
    if (var_a0_2 >= 0) {
        var_v0_4 = var_a1 < (s16) temp_v0_3;
    } else {
        var_v0_4 = (s16) temp_v0_3 < var_a1;
    }
    if (var_v0_4 != 0) {
        M2C_FIELD(temp_v1_5, u16 *, 0x98) = (u16) var_a1;
    }
    temp_v1_6 = temp_s1 + (arg2 * 2);
    temp_a0_2 = M2C_FIELD(temp_v1_6, s16 *, 0x98);
    var_v0_5 = -0x258;
    if (temp_a0_2 >= -0x258) {
        var_v0 = arg2 * 2;
        if (temp_a0_2 >= 0x259) {
            var_v0_5 = 0x258;
            goto block_36;
        }
    } else {
block_36:
        M2C_FIELD(temp_v1_6, s16 *, 0x98) = var_v0_5;
        var_v0 = arg2 * 2;
    }
    return M2C_FIELD((var_v0 + temp_s1), s16 *, 0x94);
}
