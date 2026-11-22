/* machine draft (m2c) for gcc-2.7.2-kmc -G0 -mips3 -mgp32 -mfp32 -O2, tried by autopilot */
#ifndef M2C_DEFINES
#define M2C_DEFINES
typedef s32 M2C_UNK;
typedef s8 M2C_UNK8;
typedef s16 M2C_UNK16;
typedef s32 M2C_UNK32;
#define M2C_FIELD(expr, type_ptr, offset) (((struct { __typeof__(*(type_ptr)0) v; } *)((s8 *)(expr) + (offset)))->v)
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define M2C_CARRY 0
#define M2C_OVERFLOW(a) (0)
#endif

typedef struct { f32 v[3]; } RenderVec3;
extern RenderVec3 D_800D1D60;
s16 *findOrLoadStreamSlot();
s32 func_8000628C();
s32 *func_8000DA08();
s32 func_80043FA0();
f32 approximate_hypot2(f32, f32);
s32 func_800468E4();
f32 approximateAtan2(f32, f32);
s32 func_80083410();
s32 build_yz_rotation_matrix();
s32 MatMul3x3InPlace();
s32 func_800839F0();
s32 rotateVec3ByMat3();
s32 guMtxF2L();
extern u32 sMatrixPoolLimit;
extern u8 D_800C2B40;
extern char D_800C392A[];
extern s32 (*D_800D9420)(s16 *, s32 *);
extern void *D_801002FC;
extern s32 gBorderSkipActive;
extern u32 sMatrixPoolUsed;
extern void *D_8010A4B4;
extern void *D_80115328;
extern void *sRenderState;

typedef struct { int value; } __repair_field_0;
typedef struct { unsigned char pad[100]; void * value; } __repair_field_64;
void func_80000A40(void *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, u8 arg5) {
    f32 sp10[3];
    f32 sp20[3];
    f32 sp30[3];
    RenderVec3 sp40;
    f32 sp50[16];
    char sp90[0x30];
    s32 spC0[24];
    s32 sp120[0x24c];
    s16 spA50[3];
    s16 spA58[3];
u16 __repair_result_spA5C;
    u8 spA67;
    void *spA6C;
    s32 *spA74;
    s32 spA7C;
    s32 spA84;
    s32 spA8C;
    s32 spA94;
    s32 *spA9C;
    void *spAAC;
    
    s32 *temp_s1;
    
    char *var_a1;
    char *var_v1;
    f32 temp_fv1_2;
    f32 var_fv0;
    s16 *temp_v0_2;
    
    s16 temp_v0_3;
    s16 temp_v0_4;
    s16 var_v0;
    s32 temp_ft0;
    s32 temp_fv1;
    s32 temp_s1_2;
    s32 __repair_field_base;
    s32 temp_v0;
    s32 temp_v1;
    s32 var_s4;
s32 __repair_phase_var_s4;
    s32 var_s6;
    s32 var_s6_b1;
    s32 var_v0_3;
    s32 var_v1_2;
    s8 temp_v1_2;
    
    s32 var_v0_2;
    u32 temp_v0_5;
    u32 temp_v1_4;
    u32 var_a0;
    u32 var_a2;
    void *temp_a0;
    void *temp_s0_2;
    void *temp_s0_5;
    void *temp_s0_3;
    void *temp_s0_4;
    void *temp_s3;
    void *temp_v0_10;
    void *temp_v0_6;
    void *temp_v0_7;
    void *temp_v0_8;
    void *temp_v0_9;
    void *var_fp;

    spA67 = arg5;
    sp40 = D_800D1D60;
    temp_a0 = M2C_FIELD(arg0, void **, 0x68);
    temp_s3 = temp_a0 + 0x14;
    if (M2C_FIELD(temp_a0, s16 *, 0x92) >= 0) {
        temp_v1 = M2C_FIELD(temp_s3, s32 *, 0) & 3;
        spA7C = 0;
        switch ((u32)temp_v1) {                          /* irregular */
        default:
        case 0:
            spA8C = 5;
            spA94 = 0;
            break;
        case 1:
            spA8C = 5;
            spA94 = M2C_FIELD(temp_s3, s8 *, 0x9F) + 5;
            break;
        case 2:
            spA94 = 0;
            spA7C = 1;
            spA8C = (M2C_FIELD(temp_s3, s8 *, 0x9F) * 3) + 2;
            break;
        case 3:
            var_s4 = (s8)(M2C_FIELD(temp_s3, s8 *, 0x9F));
            spA7C = 1;
            var_s6 = (var_s4 * 3) + 2;
            spA8C = var_s6;
            spA94 = var_s6 + var_s4;
            break;
        }
        __repair_result_spA5C = M2C_FIELD(arg0, u16 *, 0x78);
        spA84 = *(s16 *)(D_800C392A + (M2C_FIELD(temp_s3, u8 *, 0x9E) * 8)) == 0;
        var_fp = NULL;
        if (__repair_result_spA5C == 2) {
            var_fp = M2C_FIELD(arg0, void **, 0x6C);
        }
        if (__repair_result_spA5C == 3) {
            var_fp = M2C_FIELD(arg0, void **, 0x6C);
        }
        spA6C = M2C_FIELD(temp_s3, void **, 0x48);
        spA50[0] = (s16) (s32) M2C_FIELD(arg0, f32 *, 0x3C);
        spA50[1] = (s16) (s32) M2C_FIELD(arg0, f32 *, 0x40);
        spA50[2] = (s16) (s32) M2C_FIELD(arg0, f32 *, 0x44);
        D_800D9420(spA50, spC0);
        if (M2C_FIELD(arg0, f32 *, 0x54) != 1.0f) {
            char *scale_row;
            var_a2 = 0;
            scale_row = sp10;
            do {
u32 __block_var_a0;

                __block_var_a0 = 0;
                var_v1 = scale_row + 0xB0;
do {
                __block_var_a0 += 1;
                *(f32 *)var_v1 *= M2C_FIELD(arg0, f32 *, 0x54);
                var_v1 += 4;
                } while (__block_var_a0 < 3U);
                var_a2 += 1;
                scale_row += 0xC;
            } while (var_a2 < 3U);
        }
        spA74 = &spC0;
        if (spA67 == 0) {
            sp50[3] = 0;
            sp50[7] = 0;
            sp50[11] = 0;
            sp50[15] = 1.0f;
            __repair_phase_var_s4 = 0;
            temp_v0_2 = findOrLoadStreamSlot(M2C_FIELD(temp_s3, u8 *, 0x9E));
            if (*temp_v0_2 >= 0) {
                spA9C = &sp120;
                do {
                    temp_s1 = (s32 *)((char *)spA9C + M2C_FIELD(((char *)temp_v0_2 + __repair_phase_var_s4 * 0x20), s16 *, 0) * 0x30);
                    if (spA94 == 0) {
                        temp_v1_4 = *(u32 *)(((spA8C + __repair_phase_var_s4) * 4) + spA6C);
                        spA58[0] = (temp_v1_4 >> 0x16) * 4;
                        spA58[1] = (temp_v1_4 >> 0xA) & 0xFFE;
                        spA58[2] = (temp_v1_4 * 2) & 0xFFE;
                        D_800D9420(spA58, temp_s1);
                    } else {
                        func_800468E4(spA6C + ((spA94 + (__repair_phase_var_s4 * 4)) * 4), temp_s1);
                    }
                    if (M2C_FIELD(temp_s3, s32 *, 0) & 0x80000) {
                        if (__repair_phase_var_s4 == 0xE) {
                            spA58[0] = M2C_FIELD(temp_s3, u16 *, 0x94) - M2C_FIELD(temp_s3, u16 *, 0x96);
                            spA58[2] = M2C_FIELD(temp_s3, u16 *, 0x98) - M2C_FIELD(temp_s3, u16 *, 0x9A);
                            func_80083410(spA58, sp90);
                            MatMul3x3InPlace(sp90, temp_s1);
                        } else {
                            if (__repair_phase_var_s4 == 7) {
                                spA58[1] = -(s16) M2C_FIELD(temp_s3, u16 *, 0x96);
                                spA58[2] = M2C_FIELD(temp_s3, u16 *, 0x9A);
                                build_yz_rotation_matrix(spA58, sp90);
                                MatMul3x3InPlace(sp90, temp_s1);
                            }
                        }
                    }
                    if ((var_fp != NULL) && (gBorderSkipActive != 0)) {
                        if (__repair_phase_var_s4 == 7) {
                            temp_ft0 = (s32) (M2C_FIELD(var_fp, f32 *, 0x11C) * 4096.0f);
                            spA58[1] = (s16) temp_ft0;
                            temp_fv1 = (s32) (M2C_FIELD(var_fp, f32 *, 0x124) * 4096.0f);
                            spA58[2] = (u16) temp_fv1;
                            if (((s16) temp_ft0 != 0) || ((temp_fv1 << 0x10) != 0)) {
                                if ((s16) temp_ft0 < -0xDC) {
                                    spA58[1] = -0xDC;
                                } else if (!((s16) temp_ft0 < 0xDD)) {
                                    spA58[1] = 0xDC;
                                }
                                if ((s16) spA58[2] < -0xDC) {
                                    spA58[2] = -0xDC;
                                } else if ((s16) spA58[2] >= 0xDD) {
                                    spA58[2] = 0xDC;
                                }
                                build_yz_rotation_matrix(spA58, sp90);
                                MatMul3x3InPlace(sp90, temp_s1);
                            }
                        } else if (((__repair_phase_var_s4 == 0xB) | (__repair_phase_var_s4 == 8)) != 0) {
                            temp_v0_3 = M2C_FIELD(var_fp, s16 *, 0x17C);
                            if (temp_v0_3 != 0) {
                                temp_v0_4 = temp_v0_3 - 4;
                                M2C_FIELD(var_fp, s16 *, 0x17C) = temp_v0_4;
                                if (temp_v0_4 < 0) {
                                    M2C_FIELD(var_fp, s16 *, 0x17C) = 0;
                                }
                                spA58[2] = (u16) M2C_FIELD(var_fp, s16 *, 0x17C);
                                spA58[1] = 0;
                                build_yz_rotation_matrix(spA58, sp90);
                                MatMul3x3InPlace(sp90, temp_s1);
                            }
                        }
                    }
                    if (spA7C == 0) {
                        sp20[0] = M2C_FIELD(((char *)temp_v0_2 + __repair_phase_var_s4 * 0x20), f32 *, 4);
                        sp20[1] = M2C_FIELD(((char *)temp_v0_2 + __repair_phase_var_s4 * 0x20), f32 *, 8);
                        var_fv0 = M2C_FIELD(((char *)temp_v0_2 + __repair_phase_var_s4 * 0x20), f32 *, 0xC);
                    } else {
                        sp20[0] = M2C_FIELD(((char *)spA6C + __repair_phase_var_s4 * 0xC), f32 *, 8);
                        sp20[1] = M2C_FIELD(((char *)spA6C + __repair_phase_var_s4 * 0xC), f32 *, 0xC);
                        var_fv0 = M2C_FIELD(((char *)spA6C + __repair_phase_var_s4 * 0xC), f32 *, 0x10);
                    }
                    sp20[2] = var_fv0;
                    if (__repair_phase_var_s4 == 0) {
                        M2C_FIELD(temp_s1, f32 *, 0x24) = sp20[0];
                        M2C_FIELD(temp_s1, f32 *, 0x28) = sp20[1];
                        M2C_FIELD(temp_s1, f32 *, 0x2C) = sp20[2];
                        if (M2C_FIELD(arg0, s32 *, 0x58) & 0x40000) {
s32 *temp_s0;

                            temp_s0 = func_8000DA08(arg0);
                        
                        MatMul3x3InPlace(temp_s0, temp_s1);} else {
s32 *temp_s0;

                            temp_s0 = spA74;
                        
                        MatMul3x3InPlace(temp_s0, temp_s1);}
                    } else {
s32 *temp_s0;

                        temp_s0 = (s32 *)((char *)spA9C + M2C_FIELD(((char *)temp_v0_2 + __repair_phase_var_s4 * 0x20), s16 *, 2) * 0x30);
                        func_800839F0(temp_s0, sp20, (char *)temp_s1 + 0x24);
                        M2C_FIELD(temp_s1, f32 *, 0x24) += M2C_FIELD(temp_s0, f32 *, 0x24);
                        M2C_FIELD(temp_s1, f32 *, 0x28) += M2C_FIELD(temp_s0, f32 *, 0x28);
                        M2C_FIELD(temp_s1, f32 *, 0x2C) += M2C_FIELD(temp_s0, f32 *, 0x2C);
                        MatMul3x3InPlace(temp_s0, temp_s1);
                        if ((spA84 != 0)) {
                            if ((__repair_phase_var_s4 == 0xE)) {
                                sp30[0] = 0.0f;
                                sp30[2] = 0;
                                sp30[1] = 1.0f;
                                func_800839F0(temp_s1, sp30, sp40.v);
                                M2C_FIELD(temp_s3, s16 *, 0x78) = (s16) (s32) (approximateAtan2(sp40.v[0], sp40.v[2]) * 651.8986f);
                                M2C_FIELD(temp_s3, s16 *, 0x7A) = (s16) (s32) (approximateAtan2(sp40.v[0], approximate_hypot2(sp40.v[0], sp40.v[2])) * 651.8986f);
                            }
                        }
                    }
                    sp10[0] = M2C_FIELD(temp_s1, f32 *, 0x24) + M2C_FIELD(arg0, f32 *, 0x24);
                    sp10[2] = M2C_FIELD(temp_s1, f32 *, 0x2C) + M2C_FIELD(arg0, f32 *, 0x2C);
                    if (spA67 != 0) {
                        temp_fv1_2 = M2C_FIELD(M2C_FIELD(M2C_FIELD(arg0, void **, 0x20), void **, 0x3C), f32 *, 0x20);
                        sp10[1] = (M2C_FIELD(temp_s1, f32 *, 0x28) - M2C_FIELD(arg0, f32 *, 0x28)) + temp_fv1_2 + temp_fv1_2;
                    } else {
                        sp10[1] = M2C_FIELD(temp_s1, f32 *, 0x28) + M2C_FIELD(arg0, f32 *, 0x28);
                        sp20[0] = M2C_FIELD(((char *)temp_v0_2 + __repair_phase_var_s4 * 0x20), f32 *, 0x10);
                        sp20[1] = M2C_FIELD(((char *)temp_v0_2 + __repair_phase_var_s4 * 0x20), f32 *, 0x14);
                        sp20[2] = M2C_FIELD(((char *)temp_v0_2 + __repair_phase_var_s4 * 0x20), f32 *, 0x18);
                        rotateVec3ByMat3(temp_s1, sp20);
                        *(f32 *)((__repair_phase_var_s4 * 0xC) + M2C_FIELD(M2C_FIELD(arg0, void **, 0x68), s32 *, 0)) = sp10[0];
                        M2C_FIELD(((__repair_phase_var_s4 * 0xC) + M2C_FIELD(M2C_FIELD(arg0, void **, 0x68), s32 *, 0)), f32 *, 4) = sp10[1];
                        M2C_FIELD(((__repair_phase_var_s4 * 0xC) + M2C_FIELD(M2C_FIELD(arg0, void **, 0x68), s32 *, 0)), f32 *, 8) = sp10[2];
                        *(f32 *)((__repair_phase_var_s4 * 0xC) + M2C_FIELD(M2C_FIELD(arg0, void **, 0x68), s32 *, 4)) = sp10[0] + sp20[0];
                        M2C_FIELD(((__repair_phase_var_s4 * 0xC) + M2C_FIELD(M2C_FIELD(arg0, void **, 0x68), s32 *, 4)), f32 *, 4) = (f32) (sp10[1] + sp20[1]);
                        M2C_FIELD(((__repair_phase_var_s4 * 0xC) + M2C_FIELD(M2C_FIELD(arg0, void **, 0x68), s32 *, 4)), f32 *, 8) = (f32) (sp10[2] + sp20[2]);
                    }
                    if (!(M2C_FIELD(arg0, s32 *, 0x58) & 8) && ((u32) sMatrixPoolUsed < (u32) sMatrixPoolLimit)) {
                        __repair_field_base = M2C_FIELD(sRenderState, s32 *, 0x74C);
                        sp50[0] = M2C_FIELD(temp_s1, f32 *, 0) * 0.015625f;
                        sp50[4] = M2C_FIELD(temp_s1, f32 *, 4) * 0.015625f;
                        sp50[8] = M2C_FIELD(temp_s1, f32 *, 8) * 0.015625f;
                        sp50[1] = M2C_FIELD(temp_s1, f32 *, 0xC) * 0.015625f;
                        sp50[5] = M2C_FIELD(temp_s1, f32 *, 0x10) * 0.015625f;
                        sp50[9] = M2C_FIELD(temp_s1, f32 *, 0x14) * 0.015625f;
                        sp50[2] = M2C_FIELD(temp_s1, f32 *, 0x18) * 0.015625f;
                        sp50[6] = M2C_FIELD(temp_s1, f32 *, 0x1C) * 0.015625f;
                        var_a0 = sMatrixPoolUsed + 1;
                        sMatrixPoolUsed = var_a0;
                        temp_s1_2 = __repair_field_base + (var_a0 << 6);
                        sp50[10] = M2C_FIELD(temp_s1, f32 *, 0x20) * 0.015625f;
                        sp50[12] = sp10[0] * 64.0f;
                        sp50[13] = sp10[1] * 64.0f;
                        sp50[14] = sp10[2] * 64.0f;
                        guMtxF2L(sp50, temp_s1_2);
                        ((__repair_field_0 *)D_80115328)->value = 0xDA380003;
                        M2C_FIELD(D_80115328, s32 *, 4) = (s32) (temp_s1_2 - 0x80000000);
                        temp_v0_6 = *(s32 *)((__repair_phase_var_s4 * 4) + M2C_FIELD(temp_s3, s32 *, 0x58));
                        D_80115328 += 8;
                        if (temp_v0_6 != NULL) {
                            temp_s0_5 = temp_v0_6;
                            temp_v0_6 = NULL;

                            if ((((__repair_field_0 *)temp_s0_5)->value != 0) || (func_80043FA0(temp_s0_5), (((__repair_field_0 *)temp_s0_5)->value != 0))) {
                                if (!(M2C_FIELD(temp_s0_5, u8 *, 0x46) & 0x80)) {
                                    M2C_FIELD(temp_s0_5, u8 *, 0x46) = (u8) D_800C2B40;
                                }
                                temp_v0_7 = D_80115328;
                                ((__repair_field_0 *)temp_v0_7)->value = 0xDE000000;
                                D_80115328 = temp_v0_7 + 8;
                                M2C_FIELD(temp_v0_7, s32 *, 4) = (s32) ((__repair_field_0 *)temp_s0_5)->value;
                            }
                            if ((__repair_phase_var_s4 == 0xA)) {
                                if ((spA84 != 0)) {
                                    temp_s0_2 = M2C_FIELD(temp_s3, void **, 0x5C);
                                    if ((temp_s0_2 != NULL) && ((((__repair_field_0 *)temp_s0_2)->value != 0) || (func_80043FA0(temp_s0_2), (((__repair_field_0 *)temp_s0_2)->value != 0)))) {
                                        if (!(M2C_FIELD(temp_s0_2, u8 *, 0x46) & 0x80)) {
                                            M2C_FIELD(temp_s0_2, u8 *, 0x46) = (u8) D_800C2B40;
                                        }
                                        temp_v0_8 = D_80115328;
                                        ((__repair_field_0 *)temp_v0_8)->value = 0xDE000000;
                                        D_80115328 = temp_v0_8 + 8;
                                        M2C_FIELD(temp_v0_8, s32 *, 4) = (s32) ((__repair_field_0 *)temp_s0_2)->value;
                                    }
                                    temp_s0_3 = M2C_FIELD(temp_s3, void **, 0x60);
                                    if (temp_s0_3 != NULL) {
                                        ((__repair_field_0 *)D_8010A4B4)->value = 0xDA380003;
                                        M2C_FIELD(D_8010A4B4, s32 *, 4) = (s32) (temp_s1_2 - 0x80000000);
                                        D_8010A4B4 += 8;
                                        if ((((__repair_field_0 *)temp_s0_3)->value != 0) || (func_80043FA0(temp_s0_3), (((__repair_field_0 *)temp_s0_3)->value != 0))) {
                                            if (!(M2C_FIELD(temp_s0_3, u8 *, 0x46) & 0x80)) {
                                                M2C_FIELD(temp_s0_3, u8 *, 0x46) = (u8) D_800C2B40;
                                            }
                                            temp_v0_9 = D_8010A4B4;
                                            ((__repair_field_0 *)temp_v0_9)->value = 0xDE000000;
                                            D_8010A4B4 = temp_v0_9 + 8;
                                            M2C_FIELD(temp_v0_9, s32 *, 4) = (s32) ((__repair_field_0 *)temp_s0_3)->value;
                                        }
                                        M2C_FIELD(temp_s3, void **, 0x60) = NULL;
                                    }
                                }
                            }
                        }
                        if (__repair_phase_var_s4 == 0x25) {
                            temp_s0_4 = ((__repair_field_64 *)temp_s3)->value;
                            if ((temp_s0_4 != NULL) && ((((__repair_field_64 *)temp_s3)->value = NULL, ((__repair_field_0 *)D_801002FC)->value = 0xDA380003, M2C_FIELD(D_801002FC, s32 *, 4) = (s32) (temp_s1_2 - 0x80000000), D_801002FC += 8, (((__repair_field_0 *)temp_s0_4)->value != 0)) || (func_80043FA0(temp_s0_4), (((__repair_field_0 *)temp_s0_4)->value != 0)))) {
                                if (!(M2C_FIELD(temp_s0_4, u8 *, 0x46) & 0x80)) {
                                    M2C_FIELD(temp_s0_4, u8 *, 0x46) = (u8) D_800C2B40;
                                }
                                temp_v0_10 = D_801002FC;
                                ((__repair_field_0 *)temp_v0_10)->value = 0xDE000000;
                                D_801002FC = temp_v0_10 + 8;
                                M2C_FIELD(temp_v0_10, s32 *, 4) = (s32) ((__repair_field_0 *)temp_s0_4)->value;
                            }
                        }
                    }
                    __repair_phase_var_s4 += 1;
                } while (*(s16 *)((char *)temp_v0_2 + __repair_phase_var_s4 * 0x20) >= 0);
            }
            var_v1_2 = M2C_FIELD(temp_s3, s32 *, 0);
            if (var_v1_2 & 0x80000) {
                if (!(var_v1_2 & 0x100000)) {
                    func_8000628C(arg0, 0, 1, 0x15);
                    func_8000628C(arg0, 0, 0, 0x53);
                    if (((s16) M2C_FIELD(temp_s3, u16 *, 0x94) == 0) && ((s16) M2C_FIELD(temp_s3, u16 *, 0x98) == 0) && ((s16) M2C_FIELD(temp_s3, u16 *, 0x96) == 0) && ((s16) M2C_FIELD(temp_s3, u16 *, 0x9A) == 0)) {
                        var_v0_3 = M2C_FIELD(temp_s3, s32 *, 0);
                        var_v1_2 = 0xFFF7FFFF;
                        M2C_FIELD(temp_s3, s32 *, 0) = (s32) (var_v1_2 & var_v0_3);
                    }
                } else {
                    var_v0_3 = 0xFFEFFFFF;
                    M2C_FIELD(temp_s3, s32 *, 0) = (s32) (var_v1_2 & var_v0_3);
                }
            }
        }
    }
}

