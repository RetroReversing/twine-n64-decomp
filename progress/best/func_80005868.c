/* machine draft (m2c) for gcc-2.7.2-kmc -G0 -mips3 -mgp32 -mfp32 -O2 -fno-schedule-insns, tried by autopilot */
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

M2C_UNK func_80083560(void *, void *);              /* extern */
M2C_UNK func_800839F0(void *, f32 *, void *);       /* extern */
extern M2C_UNK (*D_800D9420)(s16 *, void *);

void func_80005868(s16 *arg0, void *arg1, void *arg2, s32 arg3) {
    f32 sp10;
    f32 sp14;
    f32 sp18;
    s16 sp20;
    s16 sp22;
    s16 sp24;
    u8 sp28[0x930];
    f32 var_ft0;
    f32 var_fv0;
    f32 var_fv1;
    s16 *var_s2;
    s32 var_s6;
    u32 temp_v1;
    void *temp_s0;
    void *temp_s1;
    void *var_s3;
    void *var_s5;

    var_s6 = 0;
    if (*arg0 >= 0) {
        var_s2 = arg0;
        var_s3 = arg2;
        var_s5 = arg1;
        do {
            temp_v1 = M2C_FIELD(var_s5, u32 *, 0x14);
            temp_s1 = sp28 + (M2C_FIELD(var_s2, s16 *, 0) * 0x30);
            sp20 = (temp_v1 >> 0x16) * 4;
            sp22 = (temp_v1 >> 0xA) & 0xFFE;
            sp24 = (temp_v1 * 2) & 0xFFE;
            D_800D9420(&sp20, temp_s1);
            if (var_s6 == 0) {
                var_fv1 = M2C_FIELD(arg1, f32 *, 8);
                var_ft0 = M2C_FIELD(arg1, f32 *, 0xC);
                var_fv0 = M2C_FIELD(arg1, f32 *, 0x10);
                if (arg3 == 0) {
                    var_fv0 = 0.0f;
                    var_ft0 = 0.0f;
                    var_fv1 = 0.0f;
                }
                M2C_FIELD(temp_s1, f32 *, 0x24) = var_fv1;
                M2C_FIELD(temp_s1, f32 *, 0x28) = var_ft0;
                M2C_FIELD(temp_s1, f32 *, 0x2C) = var_fv0;
            } else {
                temp_s0 = sp28 + (M2C_FIELD(var_s2, s16 *, 2) * 0x30);
                sp10 = M2C_FIELD(var_s2, f32 *, 4);
                sp14 = M2C_FIELD(var_s2, f32 *, 8);
                sp18 = M2C_FIELD(var_s2, f32 *, 0xC);
                func_800839F0(temp_s0, &sp10, temp_s1 + 0x24);
                M2C_FIELD(temp_s1, f32 *, 0x24) = (f32) (M2C_FIELD(temp_s1, f32 *, 0x24) + M2C_FIELD(temp_s0, f32 *, 0x24));
                M2C_FIELD(temp_s1, f32 *, 0x28) = (f32) (M2C_FIELD(temp_s1, f32 *, 0x28) + M2C_FIELD(temp_s0, f32 *, 0x28));
                M2C_FIELD(temp_s1, f32 *, 0x2C) = (f32) (M2C_FIELD(temp_s1, f32 *, 0x2C) + M2C_FIELD(temp_s0, f32 *, 0x2C));
                func_80083560(temp_s0, temp_s1);
            }
            var_s2 += 0x20;
            M2C_FIELD(var_s3, f32 *, 0) = (f32) M2C_FIELD(temp_s1, f32 *, 0x24);
            M2C_FIELD(var_s3, f32 *, 4) = (f32) M2C_FIELD(temp_s1, f32 *, 0x28);
            var_s5 += 4;
            var_s6 += 1;
            M2C_FIELD(var_s3, f32 *, 8) = (f32) M2C_FIELD(temp_s1, f32 *, 0x2C);
            var_s3 += 0xC;
        } while (*var_s2 >= 0);
    }
}
