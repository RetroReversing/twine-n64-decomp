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

s32 func_8003D64C(f32 *, void *);
s32 func_8004886C(void *, void *, f32);
s32 func_8004E6E4(M2C_UNK *, void *, f32 *, s32 *, M2C_UNK *, f32, s32, s32, s32);
M2C_UNK func_80082FE4(s16 *, M2C_UNK *);
M2C_UNK func_80083A6C(M2C_UNK *, f32 *);
extern M2C_UNK D_800D2FC8;
extern M2C_UNK D_800D2FD4;
extern M2C_UNK func_8004DBD8;

s32 func_8003E6EC(void *arg0, void *arg1, u8 arg2) {
    s16 sp28[3];
    M2C_UNK sp30[12];
    f32 sp60[3];
    s32 sp70[3];
    s32 sp80[3];
    f32 sp90[3];
    u8 spA7;
    s32 *spAC;
    f32 temp_fv0;
    f32 var_fs0;
    f32 var_fs1;
    f32 var_fv0;
    f32 var_fv1;
    void *temp_v0;
    void *temp_v0_2;
    void *temp_v0_3;
    void *temp_v0_4;
    void *temp_v0_5;
    void *var_s1;
    void *var_s3;
    void *var_s4;

    var_fs0 = 65536.0f;
    var_s3 = NULL;
    temp_v0 = M2C_FIELD(arg1, void **, 0x70);
    var_s4 = NULL;
    var_s1 = arg0;
    spA7 = arg2;
    var_fs1 = 65536.0f;
    if (temp_v0 != NULL) {
        sp60[0] = (M2C_FIELD(temp_v0, f32 *, 0x18) + M2C_FIELD(temp_v0, f32 *, 0x1C)) * 0.5f;
        temp_v0_2 = M2C_FIELD(arg1, void **, 0x70);
        sp60[1] = (M2C_FIELD(temp_v0_2, f32 *, 0x20) + M2C_FIELD(temp_v0_2, f32 *, 0x24)) * 0.5f;
        temp_v0_3 = M2C_FIELD(arg1, void **, 0x70);
        sp60[2] = (M2C_FIELD(temp_v0_3, f32 *, 0x28) + M2C_FIELD(temp_v0_3, f32 *, 0x2C)) * 0.5f;
        sp28[0] = (s16) (s32) M2C_FIELD(arg1, f32 *, 0x3C);
        sp28[1] = (s16) (s32) M2C_FIELD(arg1, f32 *, 0x40);
        sp28[2] = (s16) (s32) M2C_FIELD(arg1, f32 *, 0x44);
        func_80082FE4(sp28, sp30);
        func_80083A6C(sp30, sp60);
        sp60[0] += M2C_FIELD(arg1, f32 *, 0x24);
        sp60[1] += M2C_FIELD(arg1, f32 *, 0x28);
        sp60[2] += M2C_FIELD(arg1, f32 *, 0x2C);
    } else {
        sp60[0] = M2C_FIELD(arg1, f32 *, 0x24);
        sp60[1] = M2C_FIELD(arg1, f32 *, 0x28);
        sp60[2] = M2C_FIELD(arg1, f32 *, 0x2C);
    }
    if (var_s1 != NULL) {
        f32 *point = sp60;
        spAC = sp70;
        do {
            if ((M2C_FIELD(var_s1, u16 *, 0x58) == 0x46) && ((func_8004886C(var_s1 + 0x40, point, M2C_FIELD(arg1, f32 *, 0x64)) << 0x18) != 0) && ((func_8003D64C(point, var_s1) << 0x18) != 0)) {
                __builtin_memcpy(sp70, &D_800D2FC8, 12);
                __builtin_memcpy(sp80, &D_800D2FD4, 12);
                temp_fv0 = M2C_FIELD(var_s1, f32 *, 0x4C);
                if (temp_fv0 < var_fs1) {
                    var_s4 = var_s1;
                    var_fs1 = temp_fv0;
                }
                if ((func_8004E6E4(&func_8004DBD8, var_s1, point, spAC, &sp90, 256.0f, 0, 1, 0) << 0x18) != 0) {
                    var_fv1 = sp90[1] - sp60[1];
                    if (var_fv1 < var_fs0) {
                        var_s3 = var_s1;
                        var_fs0 = var_fv1;
                    }
                } else {
                    if ((func_8004E6E4(&func_8004DBD8, var_s1, point, sp80, &sp90, 256.0f, 0, 1, 0) << 0x18) != 0) {
                        var_fv1 = sp60[1] - sp90[1];
                        if (var_fv1 < var_fs0) {
                            var_s3 = var_s1;
                            var_fs0 = var_fv1;
                        }
                    }
                }
            }
            var_s1 = M2C_FIELD(var_s1, void **, 0x10);
        } while (var_s1 != NULL);
    }
    if (var_s3 != NULL) {
        temp_v0_4 = M2C_FIELD(var_s3, void **, 0);
        if (temp_v0_4 != NULL) {
            M2C_FIELD(temp_v0_4, void **, 4) = arg1;
        }
        M2C_FIELD(arg1, void **, 0) = M2C_FIELD(var_s3, void **, 0);
        M2C_FIELD(arg1, void **, 4) = var_s3;
        M2C_FIELD(var_s3, void **, 0) = arg1;
        M2C_FIELD(var_s3, s32 *, 4) = 0;
        M2C_FIELD(arg1, void **, 0x20) = var_s3;
        return 1;
    }
    if (var_s4 != NULL) {
        temp_v0_5 = M2C_FIELD(var_s4, void **, 0);
        if (temp_v0_5 != NULL) {
            M2C_FIELD(temp_v0_5, void **, 4) = arg1;
        }
        M2C_FIELD(arg1, void **, 0) = M2C_FIELD(var_s4, void **, 0);
        M2C_FIELD(arg1, void **, 4) = var_s4;
        M2C_FIELD(var_s4, void **, 0) = arg1;
        M2C_FIELD(var_s4, s32 *, 4) = 0;
        M2C_FIELD(arg1, void **, 0x20) = var_s4;
        return 1;
    }
    if ((spA7 << 0x18) != 0) {
        M2C_FIELD(arg1, s32 *, 0x60) = (s32) (M2C_FIELD(arg1, s32 *, 0x60) | 1);
    }
    return 0;
}
