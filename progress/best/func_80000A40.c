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

extern int D_800D1D60;
extern int D_800D1D64;
extern float D_800D1D68;
s16 *func_80001928();
s32 func_8000628C();
s32 *func_8000DA08();
s32 func_80043FA0();
f32 func_80046140();
s32 func_800468E4();
f32 func_80082A70();
s32 func_80083410();
s32 func_800834B8();
s32 func_80083560();
s32 func_800839F0();
s32 func_80083A6C();
s32 func_800A37C0();
extern u32 D_800B1D84;
extern u8 D_800C2B40;
extern char D_800C392A[];
extern s32 (*D_800D9420)(s16 *, s32 *);
extern void *D_801002FC;
extern s32 D_80102ED8;
extern u32 D_80107EA0;
extern void *D_8010A4B4;
extern void *D_80115328;
extern void *D_80117728;

void func_80000A40(void *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, u8 arg5) {
    f32 sp10;
    f32 sp14;
    f32 sp18;
    f32 sp20;
    f32 sp24;
    f32 sp28;
    f32 sp30;
    f32 sp34;
    s32 sp38;
    s32 sp40;
    s32 sp44;
    f32 sp48;
    f32 sp50;
    f32 sp54;
    f32 sp58;
    s32 sp5C;
    f32 sp60;
    f32 sp64;
    f32 sp68;
    s32 sp6C;
    f32 sp70;
    f32 sp74;
    f32 sp78;
    s32 sp7C;
    f32 sp80;
    f32 sp84;
    f32 sp88;
    f32 sp8C;
    s32 sp90;
    s32 spC0;
    s32 sp120;
    s16 spA50;
    s16 spA52;
    s16 spA54;
    s16 spA58;
    s16 spA5A;
    u16 spA5C;
    u8 spA67;
    void *spA6C;
    s32 *spA74;
    s32 spA7C;
    s32 spA84;
    s32 spA8C;
    s32 spA94;
    s32 *spA9C;
    void *spAAC;
    s32 *temp_s0;
    s32 *temp_s1;
    s32 *var_a0_2;
    char *var_a1;
    char *var_v1;
    f32 temp_fv1_2;
    f32 var_fv0;
    s16 *temp_v0_2;
    char *var_s5;
    s16 temp_v0_3;
    s16 temp_v0_4;
    s16 var_v0;
    s32 temp_ft0;
    s32 temp_fv1;
    s32 temp_s1_2;
    s32 temp_v0;
    s32 temp_v1;
    s32 var_s4;
    s32 var_s6;
    s32 var_v0_3;
    s32 var_v1_2;
    s8 temp_v1_2;
    u16 temp_v1_3;
    u16 var_v0_2;
    u32 temp_v0_5;
    u32 temp_v1_4;
    u32 var_a0;
    u32 var_a2;
    void *temp_a0;
    void *temp_s0_2;
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
    sp44 = D_800D1D64;
    sp48 = D_800D1D68;
    temp_a0 = M2C_FIELD(arg0, void **, 0x68);
    temp_s3 = temp_a0 + 0x14;
    if (M2C_FIELD(temp_a0, s16 *, 0x92) >= 0) {
        temp_v1 = M2C_FIELD(temp_a0, s32 *, 0x14) & 3;
        spA7C = 0;
        switch (temp_v1) {                          /* irregular */
        default:
        case 0:
            spA8C = 5;
            spA94 = 0;
            break;
        case 1:
            spA8C = 5;
            spA94 = M2C_FIELD(temp_a0, s8 *, 0xB3) + 5;
            break;
        case 2:
            spA94 = 0;
            spA7C = 1;
            spA8C = (M2C_FIELD(temp_a0, s8 *, 0xB3) * 3) + 2;
            break;
        case 3:
            temp_v1_2 = M2C_FIELD(temp_a0, s8 *, 0xB3);
            spA7C = 1;
            temp_v0 = (temp_v1_2 * 3) + 2;
            spA8C = temp_v0;
            spA94 = temp_v0 + temp_v1_2;
            break;
        }
        temp_v1_3 = M2C_FIELD(arg0, u16 *, 0x78);
        spA84 = *(D_800C392A + (M2C_FIELD(temp_s3, u8 *, 0x9E) * 8)) == 0;
        var_fp = NULL;
        if (temp_v1_3 == 2) {
            var_fp = M2C_FIELD(arg0, void **, 0x6C);
        }
        if (temp_v1_3 == 3) {
            var_fp = M2C_FIELD(arg0, void **, 0x6C);
        }
        spA6C = M2C_FIELD(temp_s3, void **, 0x48);
        spA50 = (s16) (s32) M2C_FIELD(arg0, f32 *, 0x3C);
        spA52 = (s16) (s32) M2C_FIELD(arg0, f32 *, 0x40);
        spA54 = (s16) (s32) M2C_FIELD(arg0, f32 *, 0x44);
        D_800D9420(&spA50, &spC0);
        if (M2C_FIELD(arg0, f32 *, 0x54) != 1.0f) {
            var_a2 = 0;
            var_a1 = &sp10;
            do {
                var_a0 = 0;
                var_v1 = var_a1 + 0xB0;
loop_16:
                var_a0 += 1;
                *(f32 *)var_v1 *= M2C_FIELD(arg0, f32 *, 0x54);
                var_v1 += 4;
                if (var_a0 < 3U) {
                    goto loop_16;
                }
                var_a2 += 1;
                var_a1 += 0xC;
            } while (var_a2 < 3U);
        }
        spA74 = &spC0;
        if (spA67 == 0) {
            sp5C = 0;
            sp6C = 0;
            sp7C = 0;
            sp8C = 1.0f;
            var_s4 = 0;
            temp_v0_2 = func_80001928(M2C_FIELD(temp_s3, u8 *, 0x9E));
            if (*temp_v0_2 >= 0) {
                var_s5 = temp_v0_2;
                var_s6 = 0;
                spA9C = &sp120;
                spAAC = spA6C;
                do {
                    temp_s1 = spA9C + (M2C_FIELD(var_s5, s16 *, 0) * 0x30);
                    if (spA94 == 0) {
                        temp_v1_4 = *(u32 *)(((spA8C + var_s4) * 4) + spA6C);
                        spA58 = (temp_v1_4 >> 0x16) * 4;
                        spA5A = (temp_v1_4 >> 0xA) & 0xFFE;
                        spA5C = (temp_v1_4 * 2) & 0xFFE;
                        D_800D9420(&spA58, temp_s1);
                    } else {
                        func_800468E4(spA6C + ((spA94 + (var_s4 * 4)) * 4), temp_s1);
                    }
                    if (M2C_FIELD(temp_a0, s32 *, 0x14) & 0x80000) {
                        if (var_s4 == 0xE) {
                            spA58 = M2C_FIELD(temp_s3, u16 *, 0x94) - M2C_FIELD(temp_s3, u16 *, 0x96);
                            spA5C = M2C_FIELD(temp_s3, u16 *, 0x98) - M2C_FIELD(temp_s3, u16 *, 0x9A);
                            func_80083410(&spA58, &sp90);
                            goto block_30;
                        }
                        if (var_s4 == 7) {
                            spA5A = -(s16) M2C_FIELD(temp_s3, u16 *, 0x96);
                            spA5C = M2C_FIELD(temp_s3, u16 *, 0x9A);
                            func_800834B8(&spA58, &sp90);
block_30:
                            func_80083560(&sp90, temp_s1);
                        }
                    }
                    if ((var_fp != NULL) && (D_80102ED8 != 0)) {
                        if (var_s4 == 7) {
                            temp_ft0 = (s32) (M2C_FIELD(var_fp, f32 *, 0x11C) * 4096.0f);
                            spA5A = (s16) temp_ft0;
                            temp_fv1 = (s32) (M2C_FIELD(var_fp, f32 *, 0x124) * 4096.0f);
                            spA5C = (u16) temp_fv1;
                            if (((s16) temp_ft0 != 0) || ((temp_fv1 << 0x10) != 0)) {
                                var_v0 = -0xDC;
                                if (((s16) temp_ft0 < -0xDC) || (var_v0 = 0xDC, (((s16) temp_ft0 < 0xDD) == 0))) {
                                    spA5A = var_v0;
                                }
                                var_v0_2 = -0xDCU;
                                if ((s16) spA5C >= -0xDC) {
                                    if ((s16) spA5C >= 0xDD) {
                                        var_v0_2 = 0xDC;
                                        goto block_42;
                                    }
                                } else {
block_42:
                                    spA5C = var_v0_2;
                                }
                                goto block_49;
                            }
                        } else if (((var_s4 == 0xB) | (var_s4 == 8)) != 0) {
                            temp_v0_3 = M2C_FIELD(var_fp, s16 *, 0x17C);
                            if (temp_v0_3 != 0) {
                                temp_v0_4 = temp_v0_3 - 4;
                                M2C_FIELD(var_fp, s16 *, 0x17C) = temp_v0_4;
                                if (temp_v0_4 & 0x8000) {
                                    M2C_FIELD(var_fp, s16 *, 0x17C) = 0;
                                }
                                spA5A = 0;
                                spA5C = (u16) M2C_FIELD(var_fp, s16 *, 0x17C);
block_49:
                                func_800834B8(&spA58, &sp90);
                                func_80083560(&sp90, temp_s1);
                            }
                        }
                    }
                    if (spA7C == 0) {
                        sp20 = M2C_FIELD(var_s5, f32 *, 4);
                        sp24 = M2C_FIELD(var_s5, f32 *, 8);
                        var_fv0 = M2C_FIELD(var_s5, f32 *, 0xC);
                    } else {
                        sp20 = M2C_FIELD(spAAC, f32 *, 8);
                        sp24 = M2C_FIELD(spAAC, f32 *, 0xC);
                        var_fv0 = M2C_FIELD(spAAC, f32 *, 0x10);
                    }
                    sp28 = var_fv0;
                    if (var_s4 == 0) {
                        M2C_FIELD(temp_s1, f32 *, 0x24) = sp20;
                        M2C_FIELD(temp_s1, f32 *, 0x28) = sp24;
                        M2C_FIELD(temp_s1, f32 *, 0x2C) = sp28;
                        if (M2C_FIELD(arg0, s32 *, 0x58) & 0x40000) {
                            var_a0_2 = func_8000DA08(arg0);
                        } else {
                            var_a0_2 = spA74;
                        }
                        func_80083560(var_a0_2, temp_s1);
                    } else {
                        temp_s0 = spA9C + (M2C_FIELD(var_s5, s16 *, 2) * 0x30);
                        func_800839F0(temp_s0, &sp20, temp_s1 + 0x24);
                        M2C_FIELD(temp_s1, f32 *, 0x24) += M2C_FIELD(temp_s0, f32 *, 0x24);
                        M2C_FIELD(temp_s1, f32 *, 0x28) += M2C_FIELD(temp_s0, f32 *, 0x28);
                        M2C_FIELD(temp_s1, f32 *, 0x2C) += M2C_FIELD(temp_s0, f32 *, 0x2C);
                        func_80083560(temp_s0, temp_s1);
                        if ((spA84 != 0) && (var_s4 == 0xE)) {
                            sp30 = 0.0f;
                            sp38 = 0;
                            sp34 = 1.0f;
                            func_800839F0(temp_s1, &sp30, &sp40);
                            M2C_FIELD(temp_s3, s16 *, 0x78) = (s16) (s32) (func_80082A70(sp40, sp48) * 651.8986f);
                            M2C_FIELD(temp_s3, s16 *, 0x7A) = (s16) (s32) (func_80082A70(sp40, func_80046140(sp40, sp48)) * 651.8986f);
                        }
                    }
                    sp10 = M2C_FIELD(temp_s1, f32 *, 0x24) + M2C_FIELD(arg0, f32 *, 0x24);
                    sp18 = M2C_FIELD(temp_s1, f32 *, 0x2C) + M2C_FIELD(arg0, f32 *, 0x2C);
                    if (spA67 != 0) {
                        temp_fv1_2 = M2C_FIELD(M2C_FIELD(M2C_FIELD(arg0, void **, 0x20), void **, 0x3C), f32 *, 0x20);
                        sp14 = (M2C_FIELD(temp_s1, f32 *, 0x28) - M2C_FIELD(arg0, f32 *, 0x28)) + temp_fv1_2 + temp_fv1_2;
                    } else {
                        sp14 = M2C_FIELD(temp_s1, f32 *, 0x28) + M2C_FIELD(arg0, f32 *, 0x28);
                        sp20 = M2C_FIELD(var_s5, f32 *, 0x10);
                        sp24 = M2C_FIELD(var_s5, f32 *, 0x14);
                        sp28 = M2C_FIELD(var_s5, f32 *, 0x18);
                        func_80083A6C(temp_s1, &sp20);
                        *(f32 *)(var_s6 + M2C_FIELD(M2C_FIELD(arg0, void **, 0x68), s32 *, 0)) = sp10;
                        M2C_FIELD((var_s6 + M2C_FIELD(M2C_FIELD(arg0, void **, 0x68), s32 *, 0)), f32 *, 4) = sp14;
                        M2C_FIELD((var_s6 + M2C_FIELD(M2C_FIELD(arg0, void **, 0x68), s32 *, 0)), f32 *, 8) = sp18;
                        *(s32 *)(var_s6 + M2C_FIELD(M2C_FIELD(arg0, void **, 0x68), s32 *, 4)) = sp10 + sp20;
                        M2C_FIELD((var_s6 + M2C_FIELD(M2C_FIELD(arg0, void **, 0x68), s32 *, 4)), f32 *, 4) = (f32) (sp14 + sp24);
                        M2C_FIELD((var_s6 + M2C_FIELD(M2C_FIELD(arg0, void **, 0x68), s32 *, 4)), f32 *, 8) = (f32) (sp18 + sp28);
                    }
                    if (!(M2C_FIELD(arg0, s32 *, 0x58) & 8) && ((u32) D_80107EA0 < (u32) D_800B1D84)) {
                        sp50 = M2C_FIELD(temp_s1, f32 *, 0) * 0.015625f;
                        sp60 = M2C_FIELD(temp_s1, f32 *, 4) * 0.015625f;
                        sp70 = M2C_FIELD(temp_s1, f32 *, 8) * 0.015625f;
                        sp54 = M2C_FIELD(temp_s1, f32 *, 0xC) * 0.015625f;
                        sp64 = M2C_FIELD(temp_s1, f32 *, 0x10) * 0.015625f;
                        sp74 = M2C_FIELD(temp_s1, f32 *, 0x14) * 0.015625f;
                        sp58 = M2C_FIELD(temp_s1, f32 *, 0x18) * 0.015625f;
                        sp68 = M2C_FIELD(temp_s1, f32 *, 0x1C) * 0.015625f;
                        temp_v0_5 = D_80107EA0 + 1;
                        D_80107EA0 = temp_v0_5;
                        temp_s1_2 = M2C_FIELD(D_80117728, s32 *, 0x74C) + (temp_v0_5 << 6);
                        sp80 = sp10 * 64.0f;
                        sp84 = sp14 * 64.0f;
                        sp88 = sp18 * 64.0f;
                        sp78 = M2C_FIELD(temp_s1, f32 *, 0x20) * 0.015625f;
                        func_800A37C0(&sp50, temp_s1_2);
                        M2C_FIELD(D_80115328, s32 *, 0) = 0xDA380003;
                        M2C_FIELD(D_80115328, s32 *, 4) = (s32) (temp_s1_2 - 0x80000000);
                        temp_v0_6 = *(s32 *)((var_s4 * 4) + M2C_FIELD(temp_s3, s32 *, 0x58));
                        D_80115328 += 8;
                        if (temp_v0_6 != NULL) {
                            if ((M2C_FIELD(temp_v0_6, s32 *, 0) != 0) || (func_80043FA0(temp_v0_6), (M2C_FIELD(temp_v0_6, s32 *, 0) != 0))) {
                                if (!(M2C_FIELD(temp_v0_6, u8 *, 0x46) & 0x80)) {
                                    M2C_FIELD(temp_v0_6, u8 *, 0x46) = (u8) D_800C2B40;
                                }
                                temp_v0_7 = D_80115328;
                                M2C_FIELD(temp_v0_7, s32 *, 0) = 0xDE000000;
                                D_80115328 = temp_v0_7 + 8;
                                M2C_FIELD(temp_v0_7, s32 *, 4) = (s32) M2C_FIELD(temp_v0_6, s32 *, 0);
                            }
                            if ((var_s4 == 0xA) && (spA84 != 0)) {
                                temp_s0_2 = M2C_FIELD(temp_s3, void **, 0x5C);
                                if ((temp_s0_2 != NULL) && ((M2C_FIELD(temp_s0_2, s32 *, 0) != 0) || (func_80043FA0(temp_s0_2), (M2C_FIELD(temp_s0_2, s32 *, 0) != 0)))) {
                                    if (!(M2C_FIELD(temp_s0_2, u8 *, 0x46) & 0x80)) {
                                        M2C_FIELD(temp_s0_2, u8 *, 0x46) = (u8) D_800C2B40;
                                    }
                                    temp_v0_8 = D_80115328;
                                    M2C_FIELD(temp_v0_8, s32 *, 0) = 0xDE000000;
                                    D_80115328 = temp_v0_8 + 8;
                                    M2C_FIELD(temp_v0_8, s32 *, 4) = (s32) M2C_FIELD(temp_s0_2, s32 *, 0);
                                }
                                temp_s0_3 = M2C_FIELD(temp_s3, void **, 0x60);
                                if (temp_s0_3 != NULL) {
                                    M2C_FIELD(D_8010A4B4, s32 *, 0) = 0xDA380003;
                                    M2C_FIELD(D_8010A4B4, s32 *, 4) = (s32) (temp_s1_2 - 0x80000000);
                                    D_8010A4B4 += 8;
                                    if ((M2C_FIELD(temp_s0_3, s32 *, 0) != 0) || (func_80043FA0(temp_s0_3), (M2C_FIELD(temp_s0_3, s32 *, 0) != 0))) {
                                        if (!(M2C_FIELD(temp_s0_3, u8 *, 0x46) & 0x80)) {
                                            M2C_FIELD(temp_s0_3, u8 *, 0x46) = (u8) D_800C2B40;
                                        }
                                        temp_v0_9 = D_8010A4B4;
                                        M2C_FIELD(temp_v0_9, s32 *, 0) = 0xDE000000;
                                        D_8010A4B4 = temp_v0_9 + 8;
                                        M2C_FIELD(temp_v0_9, s32 *, 4) = (s32) M2C_FIELD(temp_s0_3, s32 *, 0);
                                    }
                                    M2C_FIELD(temp_s3, void **, 0x60) = NULL;
                                }
                            }
                        }
                        if (var_s4 == 0x25) {
                            temp_s0_4 = M2C_FIELD(temp_s3, void **, 0x64);
                            if ((temp_s0_4 != NULL) && ((M2C_FIELD(temp_s3, void **, 0x64) = NULL, M2C_FIELD(D_801002FC, s32 *, 0) = 0xDA380003, M2C_FIELD(D_801002FC, s32 *, 4) = (s32) (temp_s1_2 - 0x80000000), D_801002FC += 8, (M2C_FIELD(temp_s0_4, s32 *, 0) != 0)) || (func_80043FA0(temp_s0_4), (M2C_FIELD(temp_s0_4, s32 *, 0) != 0)))) {
                                if (!(M2C_FIELD(temp_s0_4, u8 *, 0x46) & 0x80)) {
                                    M2C_FIELD(temp_s0_4, u8 *, 0x46) = (u8) D_800C2B40;
                                }
                                temp_v0_10 = D_801002FC;
                                M2C_FIELD(temp_v0_10, s32 *, 0) = 0xDE000000;
                                D_801002FC = temp_v0_10 + 8;
                                M2C_FIELD(temp_v0_10, s32 *, 4) = (s32) M2C_FIELD(temp_s0_4, s32 *, 0);
                            }
                        }
                    }
                    var_s5 += 0x20;
                    var_s6 += 0xC;
                    var_s4 += 1;
                    spAAC += 0xC;
                } while (*(s16 *)var_s5 >= 0);
            }
            var_v1_2 = M2C_FIELD(temp_a0, s32 *, 0x14);
            if (var_v1_2 & 0x80000) {
                if (!(var_v1_2 & 0x100000)) {
                    func_8000628C(arg0, 0, 1, 0x15);
                    func_8000628C(arg0, 0, 0, 0x53);
                    if (((s16) M2C_FIELD(temp_s3, u16 *, 0x94) == 0) && ((s16) M2C_FIELD(temp_s3, u16 *, 0x98) == 0) && ((s16) M2C_FIELD(temp_s3, u16 *, 0x96) == 0) && ((s16) M2C_FIELD(temp_s3, u16 *, 0x9A) == 0)) {
                        var_v0_3 = M2C_FIELD(temp_a0, s32 *, 0x14);
                        var_v1_2 = 0xFFF7FFFF;
                        goto block_103;
                    }
                } else {
                    var_v0_3 = 0xFFEFFFFF;
block_103:
                    M2C_FIELD(temp_a0, s32 *, 0x14) = (s32) (var_v1_2 & var_v0_3);
                }
            }
        }
    }
}
