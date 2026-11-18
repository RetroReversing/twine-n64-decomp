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

void *func_80016410(M2C_UNK, void *, M2C_UNK);      /* extern */
M2C_UNK func_8002B000(M2C_UNK *, M2C_UNK);          /* extern */
M2C_UNK func_8003E6EC(s32, void *, M2C_UNK);        /* extern */
M2C_UNK func_80044670(void *, M2C_UNK, M2C_UNK);    /* extern */
M2C_UNK func_80119E60(s32, M2C_UNK, void *);        /* extern */
extern s32 *D_800CA31C;
extern u8 D_801002A0;
extern M2C_UNK D_8011F118;
extern M2C_UNK D_8011F11C;
extern M2C_UNK D_8011F120;
extern M2C_UNK D_8011F140;
extern M2C_UNK D_8011F150;

void *func_8011A098(void *arg0, M2C_UNK arg1, s32 arg2) {
    M2C_UNK var_a1;
    s16 temp_s3;
    s32 temp_s0;
    s32 temp_v0_3;
    s32 temp_v1;
    void *temp_v0;
    void *temp_v0_2;

    if (D_801002A0 == 6) {
        func_8002B000(&D_8011F140, 0x1E);
        func_8002B000(&D_8011F140 + 8, 0x1E);
        temp_v0 = func_80016410(0, arg0, arg1);
        temp_s3 = arg2 - 1;
        if (temp_v0 != NULL) {
            temp_v1 = temp_s3 & 0xFFFF;
            *(&D_8011F150 + (temp_v1 * 4)) = temp_v0;
            if (temp_v1 != 0) {
                if (temp_v1 != 1) {
                    var_a1 = 5;
                } else {
                    var_a1 = 4;
                }
            } else {
                var_a1 = 3;
            }
            func_80044670(temp_v0, var_a1, 0xF4);
            M2C_FIELD(temp_v0, s16 *, 0x78) = 0x41;
            M2C_FIELD(temp_v0, s16 *, 0x7A) = temp_s3;
            M2C_FIELD(temp_v0, s16 *, 0x7C) = 2;
            M2C_FIELD(temp_v0, f32 *, 0x54) = 1.0f;
            M2C_FIELD(temp_v0, s32 *, 0x5C) = (s32) (M2C_FIELD(temp_v0, s32 *, 0x5C) & ~0x200);
            func_8003E6EC(*D_800CA31C, temp_v0, 1);
            temp_v0_2 = func_80016410(0, arg0, arg1);
            if (temp_v0_2 != NULL) {
                func_80044670(temp_v0_2, 2, 0xF4);
                temp_s0 = temp_s3 & 0xFFFF;
                M2C_FIELD(temp_v0_2, s16 *, 0x7A) = temp_s3;
                M2C_FIELD(temp_v0_2, s16 *, 0x7C) = 2;
                M2C_FIELD(temp_v0_2, s32 *, 0x5C) = (s32) (M2C_FIELD(temp_v0_2, s32 *, 0x5C) & ~0x200);
                func_80119E60(temp_s0, 2, temp_v0);
                temp_v0_3 = temp_s0 * 0xC;
                *(&D_8011F118 + temp_v0_3) = M2C_FIELD(arg0, s32 *, 0);
                *(&D_8011F11C + temp_v0_3) = M2C_FIELD(arg0, s32 *, 4);
                *(&D_8011F120 + temp_v0_3) = M2C_FIELD(arg0, s32 *, 8);
                M2C_FIELD(temp_v0, void **, 0x6C) = temp_v0_2;
                M2C_FIELD(temp_v0_2, s16 *, 0x78) = 0x1F;
                M2C_FIELD(temp_v0_2, f32 *, 0x54) = 1.0f;
                func_8003E6EC(*D_800CA31C, temp_v0_2, 1);
            }
            return temp_v0;
        }
    }
    return NULL;
}
