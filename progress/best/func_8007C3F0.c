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

s32 func_80045CF8(M2C_UNK);                         /* extern */
f32 func_800461D4(void *, void *);                  /* extern */
M2C_UNK func_80077960(void *, M2C_UNK);             /* extern */
M2C_UNK func_800779C4(void *);                      /* extern */
M2C_UNK func_80077E94(void *);                      /* extern */
s32 updateTrackMarkerTargets(void *);                          /* extern */
M2C_UNK func_8007B030(void *);                      /* extern */
s32 func_8007BAF8(void *, void *, M2C_UNK, M2C_UNK); /* extern */
s32 func_8007C214(void *, void *);                  /* extern */
extern f64 D_800D5120;
extern u8 D_80109B1E;

s32 func_8007C3F0(void *arg0, s32 arg1) {
    f32 sp14[2];
    f32 reserve[2];
    M2C_UNK var_a1;
    f32 temp_ft0;
    f32 temp_ft0_2;
    f32 temp_ft0_3;
    f32 temp_fv0;
    f32 temp_fv1;
    f32 var_fv1;
    f64 var_ft0;
    s16 temp_v1_2;
    s32 temp_v0;
    s32 var_v0;
    s32 temp_v1;
    void *temp_s1;
    void *temp_s2;

    temp_s1 = M2C_FIELD(arg0, void **, 0x6C);
    var_v0 = 0;
    if (M2C_FIELD(M2C_FIELD(arg0, void **, 0x68), s8 *, 0xE) != 0) {
        if (M2C_FIELD(temp_s1, void **, 0x40) != NULL) {
            if (((arg1 << 0x18) != 0) || (var_v0 = 0, (func_80045CF8(0xF) == 0))) {
                var_v0 = 0;
                if (((func_8007C214(arg0, M2C_FIELD(temp_s1, void **, 0x40)) << 0x18) != 0) && ((func_800779C4(arg0), (D_80109B1E == 0)) || (var_v0 = 1, ((updateTrackMarkerTargets(arg0) << 0x18) == 0)))) {
                    temp_ft0 = M2C_FIELD(M2C_FIELD(temp_s1, void **, 0x40), f32 *, 0x24);
                    M2C_FIELD(temp_s1, f32 *, 0x18) = (f32) (temp_ft0 + ((temp_ft0 - M2C_FIELD(arg0, f32 *, 0x24)) * 0.5f) + func_80045D8C(2.0f, 1.0f));
                    temp_fv1 = M2C_FIELD(M2C_FIELD(temp_s1, void **, 0x40), f32 *, 0x28);
                    M2C_FIELD(temp_s1, f32 *, 0x1C) = (f32) (temp_fv1 + ((temp_fv1 - M2C_FIELD(arg0, f32 *, 0x28)) * 0.5f));
                    temp_ft0_2 = M2C_FIELD(M2C_FIELD(temp_s1, void **, 0x40), f32 *, 0x2C);
                    M2C_FIELD(temp_s1, f32 *, 0x20) = (f32) (temp_ft0_2 + ((temp_ft0_2 - M2C_FIELD(arg0, f32 *, 0x2C)) * 0.5f) + func_80045D8C(2.0f, 1.0f));
                    temp_fv0 = func_800461D4(arg0 + 0x24, temp_s1 + 0x18);
                    M2C_FIELD(temp_s1, f32 *, 0x38) = temp_fv0;
                    if (temp_fv0 > 5.0f) {
                        var_fv1 = func_80045D2C(temp_fv0 * 3.0f);
                    } else {
                        var_fv1 = 0.0f;
                    }
                    temp_v1 = M2C_FIELD(temp_s1, u8 *, 0x82);
                    if (((s32) temp_v1 >= 9) && (((s32) temp_v1 < 0xC) || (temp_v1 == 0x1E))) {
                        var_fv1 = 0.0f;
                    }
                    if ((var_fv1 < 8.0f) && (M2C_FIELD(M2C_FIELD(arg0, void **, 0x68), u16 *, 0xC) & 8)) {
                        func_8007B030(arg0);
                        var_a1 = 0x21;
                        {
                        func_80077960(arg0, var_a1);return 1;}
                    }
                    temp_v1_2 = M2C_FIELD(arg0, s16 *, 0x7C);
                    if ((temp_v1_2 >= 0) && ((temp_v1_2 < 2) || (temp_v1_2 == 3))) {
                        temp_v0 = func_80045CF8(0);
                        var_ft0 = (f64) temp_v0;
                        if (temp_v0 < 0) {
                            var_ft0 += D_800D5120;
                        }
                        sp14[0] = M2C_FIELD(M2C_FIELD(temp_s1, void **, 0x40), f32 *, 0x28) - M2C_FIELD(arg0, f32 *, 0x28);
                        temp_ft0_3 = (f32) var_ft0 + 0.25f;
                        sp14[1] = M2C_FIELD(M2C_FIELD(temp_s1, void **, 0x40), f32 *, 0x2C) - M2C_FIELD(arg0, f32 *, 0x2C);
                        M2C_FIELD(temp_s1, f32 *, 0x18) = (f32) (M2C_FIELD(arg0, f32 *, 0x24) + ((M2C_FIELD(M2C_FIELD(temp_s1, void **, 0x40), f32 *, 0x24) - M2C_FIELD(arg0, f32 *, 0x24)) * temp_ft0_3));
                        M2C_FIELD(temp_s1, f32 *, 0x1C) = (f32) (M2C_FIELD(arg0, f32 *, 0x28) + (sp14[0] * temp_ft0_3));
                        M2C_FIELD(temp_s1, f32 *, 0x20) = (f32) (M2C_FIELD(arg0, f32 *, 0x2C) + (sp14[1] * temp_ft0_3));
                        if (M2C_FIELD(M2C_FIELD(temp_s1, void **, 0x40), s32 *, 0x20) == M2C_FIELD(arg0, s32 *, 0x20)) {
                            temp_s2 = temp_s1 + 0x18;
                            var_v0 = 1;
                            if ((func_8007BAF8(arg0, temp_s2, 6, 0xB) << 0x18) == 0) {
                                M2C_FIELD(temp_s1, f32 *, 0x38) = func_800461D4(arg0 + 0x24, temp_s2);
                                var_a1 = 0x1E;
                                {
                        func_80077960(arg0, var_a1);return 1;}
                            }
                            /* Duplicate return node #29. Try simplifying control flow for better match */
                            return var_v0;
                        }
                        var_a1 = 0x11;
block_26:
                        func_80077960(arg0, var_a1);
                        return 1;
                    }
                    func_80077E94(arg0);
                    goto block_28;
                }
            }
            /* Duplicate return node #29. Try simplifying control flow for better match */
            return var_v0;
        }
block_28:
        var_v0 = 0;
        /* Duplicate return node #29. Try simplifying control flow for better match */
        return var_v0;
    }
    return var_v0;
}
