extern s32 D_800BD644;
extern s32 D_800BD660;
extern u8 D_800C469C[];
extern s32 D_801001A0[];
extern u8 D_801001A2[];
extern u8 D_801002A0;
extern s32 D_801002B4;
extern s32 D_801002C0;
extern void *D_8010A500[];
extern u8 D_8011508D[];
extern char D_8011F01C[];
extern char D_8011F020[];
extern char D_8011F02C[];
extern char D_8011F034[];
extern f64 D_8011F038;
extern s16 D_8011F15C[];
extern char D_8011F378[];
extern void *D_8011F3D0[];
extern s16 D_8011F3E0[];
extern void *D_8011F3E8[];
extern void *D_8011F2F8[];

s32 strlen(char *);
s32 sprintf(char *, char *, ...);
s32 func_80063C7C(s32, void *, void **);
char func_80087100(u16);
s32 func_8011E95C(void *, void *, s32, s32);
s32 func_800448A4(void *, s32, s32);

void func_8011DC18(void) {
    s32 i;
    s32 s0;
    s32 s2;
    s32 s5;
    s32 v0;
    s32 v1;
    s8 s1;
    u8 s0b;
    unsigned a3;
    s32 a1;
    void *obj;
    void *ent;
    void *p;
    void *q;
    void *temp_s3;
    void **temp_a2;
    void **temp_s4;
    void **temp_s0_5;
    void *temp_s1;
    void *temp_s1_2;
    void *temp_s2_2;
    void *temp_v0;
    void *temp_v0_3;
    void *temp_v1;
    void *temp_a0;
    void *temp_a0_2;
    void *temp_a0_3;
    void *temp_a0_4;
    void *temp_a0_5;
    void *temp_s0_2;
    void *temp_s0_3;
    void *temp_s0_4;
    s16 *temp_a1_2;
    void *temp_v1_2;
    s16 temp_v0_2;
    s32 var_v0_3;
    s32 var_s2;
    s32 var_v1;
    f32 temp_ft0;
    f32 temp_fv1;
    f32 temp_fv1_2;
    f32 temp_fv1_3;
    s32 temp_s6;
    s32 temp_a3;
    s32 temp_v1_6;

    s5 = 0;
    if (D_801002C0 > 0) {
        i = 0;
        do {
            temp_v0 = D_8010A500[i];
            if (temp_v0 != NULL) {
                temp_s3 = *(void **)((u8 *)temp_v0 + 0x6C);
                if (temp_s3 != NULL) {
                    temp_a0 = *(void **)((u8 *)temp_s3 + 0xB4);
                    if (*((u8 *)temp_a0 + 0x12) == 2) {
                        do { sprintf(D_8011F378 + i * 0xC, D_8011F01C, *(u16 *)((u8 *)temp_a0 + 0xC) - *(u16 *)((u8 *)temp_a0 + 0xE), i); } while (0);
                        s0 = s5 & 0xFFFF;
                    } else {
                        temp_v1 = *(void **)((u8 *)temp_s3 + 0xB4);
                        do { sprintf(D_8011F378 + i * 0xC, D_8011F020, *(u16 *)((u8 *)temp_v1 + 0xC) - *(u16 *)((u8 *)temp_v1 + 0xE), 5, 0, D_8011F15C[*((u8 *)temp_s3 + 0x12) * 2], 0xC, 5); } while (0);
                        s0 = s5 & 0xFFFF;
                    }
                    s2 = s0 * 4;
                    temp_s1 = D_8011F3D0[s0];
                    if (temp_s1 != NULL) {
                        *(s16 *)((u8 *)temp_s1 + 0x1C) = strlen(D_8011F378 + s0 * 0xC);
                    }
                    temp_a2 = &D_8011F3E8[s0];
                    if (*temp_a2 != NULL && (temp_v0_2 = D_8011F3E0[s0], temp_v0_2 > 0)) {
                        D_8011F3E0[s0] = temp_v0_2 - 1;
                        if (*(f32 *)((u8 *)D_8010A500[s0] + 0x74) <= 0.0f) {
                            D_8011F3E0[s0] = 0;
                        }
                        if (D_8011F3E0[s0] < 0x20) {
                            temp_v1_2 = *temp_a2;
                            *(s32 *)((u8 *)temp_v1_2 + 0x10) = *(s32 *)((u8 *)temp_v1_2 + 0x10) & ~0xFF;
                            *(s32 *)((u8 *)*temp_a2 + 0x10) = *(s32 *)((u8 *)*temp_a2 + 0x10) | (D_8011F3E0[s0] * 8);
                        }
                        v0 = s5 & 0xFFFF;
                        if (D_8011F3E0[s0] == 0) {
                            *(s32 *)((u8 *)*temp_a2 + 0x28) = (*(s32 *)((u8 *)*temp_a2 + 0x28) & ~0xFC) | 0x1C;
                            v0 = s5 & 0xFFFF;
                        }
                    } else {
                        v0 = s5 & 0xFFFF;
                    }
                    temp_v0_3 = *(void **)((u8 *)D_8010A500[v0] + 0x68);
                    s1 = 0;
                    if (temp_v0_3 != NULL) {
                        s1 = *((u8 *)temp_v0_3 + 0xE);
                    }
                    temp_s2_2 = D_800C469C + (s32)(s16)s1 * 0xE8;
                    var_s2 = (u8)(*((u8 *)temp_s2_2 + 0x80));
                    if (D_8011508D[*((s8 *)temp_s3 + 0x182) * 0xA0] != 0) {
                        *(s32 *)((u8 *)*(void **)((u8 *)temp_s3 + 0x418) + 0x10) = *(s32 *)((u8 *)*(void **)((u8 *)temp_s3 + 0x418) + 0x10) | 0xFF;
                        *(s32 *)((u8 *)*(void **)((u8 *)temp_s3 + 0x420) + 0x10) = *(s32 *)((u8 *)*(void **)((u8 *)temp_s3 + 0x420) + 0x10) | 0xFF;
                    } else {
                        *(s32 *)((u8 *)*(void **)((u8 *)temp_s3 + 0x418) + 0x10) = *(s32 *)((u8 *)*(void **)((u8 *)temp_s3 + 0x418) + 0x10) & ~0xFF;
                        *(s32 *)((u8 *)*(void **)((u8 *)temp_s3 + 0x420) + 0x10) = *(s32 *)((u8 *)*(void **)((u8 *)temp_s3 + 0x420) + 0x10) & ~0xFF;
                    }
                    temp_v1_6 = s5 & 0xFFFF;
                    temp_fv1 = (f32)(D_8011F038 / (2.0 * (f64)D_801001A0[temp_v1_6 * 6])) * *(f32 *)((u8 *)D_8010A500[temp_v1_6] + 0x74);
                    temp_a0_2 = *(void **)((u8 *)temp_s3 + 0x478);
                    if (temp_fv1 >= 2.1474836e9f) {
                        *(u16 *)((u8 *)temp_a0_2 + 0x26) = (u16)((s32)(temp_fv1 - 2.1474836e9f) | 0x80000000);
                    } else {
                        *(u16 *)((u8 *)temp_a0_2 + 0x26) = (u16)(s32)temp_fv1;
                    }
                    temp_fv1_2 = *(f32 *)((u8 *)temp_s3 + 0x60) * 0.24f;
                    temp_a0_3 = *(void **)((u8 *)temp_s3 + 0x47C);
                    if (temp_fv1_2 >= 2.1474836e9f) {
                        *(s16 *)((u8 *)temp_a0_3 + 0x26) = (s16)((s32)(temp_fv1_2 - 2.1474836e9f) | 0x80000000);
                    } else {
                        *(s16 *)((u8 *)temp_a0_3 + 0x26) = (s16)(s32)temp_fv1_2;
                    }
                    q = *(void **)((u8 *)temp_s3 + 0x478);
                    var_v0_3 = s1 << 0x10;
                    if (*(u16 *)((u8 *)q + 0x26) == 0) {
                        if (*(f32 *)((u8 *)D_8010A500[s5 & 0xFFFF] + 0x74) > 0.0f) {
                            *(u16 *)((u8 *)q + 0x26) = 1;
                        }
                        var_v0_3 = s1 << 0x10;
                    }
                    temp_a0_4 = (void *)(var_v0_3 >> 0x10);
                    if (temp_a0_4 != NULL) {
                        sprintf(*(s8 **)((u8 *)*(void **)((u8 *)temp_s3 + 0x418) + 0x18), D_8011F02C, *((s8 *)temp_s3 + ((s32)(func_80063C7C((s32)temp_a0_4, D_800C469C, (void **)temp_a2) << 0x10) >> 0xD) + 0x1FF), *(s16 *)((u8 *)temp_s3 + var_s2 * 2 + 0x1BC));
                    } else {
                        **(s8 **)((u8 *)*(void **)((u8 *)temp_s3 + 0x418) + 0x18) = 0;
                    }
                    temp_s0_2 = *(void **)((u8 *)temp_s3 + 0x418);
                    *(s16 *)((u8 *)temp_s0_2 + 0x1C) = strlen(*(s8 **)((u8 *)temp_s0_2 + 0x18));
                    if (*(void **)((u8 *)temp_s3 + 0x41C) != NULL) {
                        sprintf(*(s8 **)((u8 *)*(void **)((u8 *)temp_s3 + 0x41C) + 0x18), D_8011F034, func_80087100((s32)(s1 & 0xFFFF) | 0xA000));
                        temp_s0_3 = *(void **)((u8 *)temp_s3 + 0x41C);
                        *(s16 *)((u8 *)temp_s0_3 + 0x1C) = strlen(*(s8 **)((u8 *)temp_s0_3 + 0x18));
                    }
                    sprintf(*(s8 **)((u8 *)*(void **)((u8 *)temp_s3 + 0x420) + 0x18), D_8011F034, func_80087100(*(u16 *)((u8 *)temp_s2_2 + *((u8 *)temp_s3 + ((s32)(s1 << 0x10) >> 0xD) + 0x1FD) * 2 + 0x2C)));
                    temp_s0_4 = *(void **)((u8 *)temp_s3 + 0x420);
                    temp_a3 = s5 & 0xFFFF;
                    *(s16 *)((u8 *)temp_s0_4 + 0x1C) = strlen(*(s8 **)((u8 *)temp_s0_4 + 0x18));
                    if (D_801001A2[temp_a3 * 0x18] != 0) {
                        var_s2 = 0;
                        if (D_801002B4 > 0) {
                            temp_s6 = temp_a3 * 4;
                            var_v1 = 0;
                            temp_s4 = (void **)((u8 *)D_8010A500 + temp_s6);
                            do {
                                temp_a0_5 = D_8010A500[var_v1];
                                if (temp_a0_5 != NULL) {
                                    if (temp_a3 != var_v1) {
                                        temp_s1_2 = *(void **)((u8 *)D_8011F2F8 + temp_s6 + var_v1 * 0x10);
                                        if (temp_s1_2 != NULL) {
                                            if ((u32)(*(u16 *)((u8 *)temp_a0_5 + 0x78) - 2) < 2U) {
                                                *(s32 *)((u8 *)temp_s1_2 + 0x28) = (*(s32 *)((u8 *)temp_s1_2 + 0x28) & ~0xFC) | 0xC;
                                            } else {
                                                *(s32 *)((u8 *)temp_s1_2 + 0x28) = (*(s32 *)((u8 *)temp_s1_2 + 0x28) & ~0xFC) | 0x1C;
                                            }
                                            temp_s0_5 = (void **)((u8 *)D_8010A500 + (var_s2 & 0xFFFF) * 4);
                                            func_8011E95C(temp_s1_2, *temp_s4, (u8 *)*temp_s0_5 + 0x24, temp_a3);
                                            temp_ft0 = *(f32 *)((u8 *)*temp_s0_5 + 0x28);
                                            temp_fv1_3 = *(f32 *)((u8 *)*temp_s4 + 0x28);
                                            if (temp_fv1_3 < (temp_ft0 - 1.0f)) {
                                                a1 = 0x17;
                                            } else {
                                                a1 = 0x1A;
                                                if (!((temp_ft0 + 1.0f) < temp_fv1_3)) {
                                                    a1 = 0x1B;
                                                }
                                            }
                                            func_800448A4(temp_s1_2, a1, 0x1B);
                                            if (D_801002A0 == 8) {
                                                if (*(u8 *)((u8 *)*(void **)((u8 *)D_8010A500[var_s2 & 0xFFFF] + 0x6C) + 0xB4 + 0x10) != 0) {
                                                    *(s32 *)((u8 *)temp_s1_2 + 0x10) = D_800BD660;
                                                } else {
                                                    *(s32 *)((u8 *)temp_s1_2 + 0x10) = D_800BD644;
                                                }
                                            }
                                        }
                                    }
                                }
                                var_s2 += 1;
                                var_v1 = var_s2 & 0xFFFF;
                            } while ((var_s2 & 0xFFFF) < D_801002B4);
                        }
                    }
                }
            }
            s5 += 1;
            i = s5 & 0xFFFF;
        } while ((s5 & 0xFFFF) < D_801002C0);
    }
}
