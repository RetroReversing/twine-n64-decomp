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

M2C_UNK func_80002BD0(void *, s32);
s32 func_8002BBA8(u8);
f32 func_800461D4(void *, void *);
M2C_UNK func_80077E00(void *);
M2C_UNK func_8007AABC(void *, s32, f32);
f32 func_800828D0(f32);
f32 func_800829A0(f32);
f32 func_800829C8(f32);
f32 func_80082A70(f32, f32);

f32 func_8007B3B8(void *arg0, void *arg1, f32 *arg2, u32 arg3) {
    f32 temp_fs0;
    f32 temp_fv0;
    f32 temp_fv1;
    f32 var_fs1;
    f32 var_fv0;
    s16 temp_v1;
    s32 var_s1;
    
    s32 var_v1;
    union { void * pointer; s32 value; } __repair_phase_storage;
    f32 temp_fa0;
    f32 temp_fa1;

    __repair_phase_storage.pointer = M2C_FIELD(arg0, void **, 0x6C);
    temp_fs0 = (f32) (func_8002BBA8(M2C_FIELD(M2C_FIELD(arg0, void **, 0x68), u8 *, 0xB1)) & 0xFF) * 0.01f;
    temp_fv0 = func_800461D4(arg0 + 0x24, arg1);
    if (temp_fv0 < *arg2) {
        *arg2 = temp_fv0;
    }
    temp_v1 = M2C_FIELD(arg0, s16 *, 0x7C);
    if (temp_v1 < 0) goto invalid;
    if (temp_v1 < 2) goto valid;
    if (temp_v1 == 3) goto valid;
invalid:
    func_80077E00(arg0);
    return 0.0f;
valid:
    switch (arg3) {
    case 0:
    case 3:
    default:
        var_fv0 = 0.12061068f;
        var_s1 = 7;
        break;
    case 1:
        var_fv0 = 0.12061068f;
        var_s1 = 0x165;
        break;
    case 4:
        var_fv0 = 0.15752044f;
        var_s1 = 0x16B;
        break;
    case 5:
        var_fv0 = 0.15752044f;
        var_s1 = 0x1FD;
        break;
    case 6:
        var_fv0 = 0.047853343f;
        var_s1 = 2;
        break;
    }
    do { func_80002BD0(arg0, var_s1 & 0xFFFF); } while (0);
    var_fs1 = temp_fs0 * var_fv0;
    M2C_FIELD(arg0, s16 *, 0x7C) = 3;
    M2C_FIELD(__repair_phase_storage.pointer, s8 *, 0x7F) = 3;
    temp_fv1 = *arg2 - var_fs1;
    temp_fa0 = M2C_FIELD(arg1, f32 *, 0) - M2C_FIELD(arg0, f32 *, 0x24);
    temp_fa1 = M2C_FIELD(arg1, f32 *, 8) - M2C_FIELD(arg0, f32 *, 0x2C);
    *arg2 = temp_fv1;
    if ((temp_fv1 * 4.0f) < var_fs1) {
        *arg2 = 0.0f;
    } else {
        __repair_phase_storage.value = 1;
        if (temp_fa0 != 0.0f) {
            __repair_phase_storage.value = 0;
        }
        var_v1 = 1;
        if (temp_fa1 != 0.0f) {
            var_v1 = 0;
        }
        func_8007AABC(arg0, (s32) (__repair_phase_storage.value & var_v1) ? (f32) (M2C_FIELD(arg0, f32 *, 0x40)) : (f32) (func_80082A70(temp_fa0, temp_fa1) * 651.8986f), 0.2f);
    }
    M2C_FIELD(arg0, f32 *, 0x24) = (f32) (M2C_FIELD(arg0, f32 *, 0x24) + (var_fs1 * func_800829A0(M2C_FIELD(arg0, f32 *, 0x40))));
    M2C_FIELD(arg0, f32 *, 0x2C) = (f32) (M2C_FIELD(arg0, f32 *, 0x2C) + (var_fs1 * func_800829C8(M2C_FIELD(arg0, f32 *, 0x40))));
    M2C_FIELD(M2C_FIELD(arg0, void **, 0x68), f32 *, 0x34) = var_fs1;
    return func_800828D0(var_fs1);
}
