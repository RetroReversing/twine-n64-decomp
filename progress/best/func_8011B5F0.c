s32 func_8000A270();
s32 func_8000A894();
s32 func_80016624();
s32 func_80016718();
s32 func_80016990();
s16 func_8002B278();
f32 approxDistance();
s32 func_80064370();
s32 func_800643C8();
s32 func_80073AF8();
s32 func_80087100();
s32 sprintf(char *, const char *, ...);
extern u8 gSceneType;
extern char D_80102EFC[];
extern s32 gTrackMarkerTable[];
extern s32 D_8010969C;
extern void *D_8010A500[];
extern s16 D_8011ED10[];
extern char D_8011EFE0[], D_8011EFEC[];
extern char D_8011F168[], D_8011F170[];
extern void *D_8011F270[];
extern s32 D_8011F278[];
extern void *D_8011F280[], *D_8011F288[], *D_8011F290[];
extern s32 D_8011F298[];
extern s32 D_8011F29C[], D_8011F2A0[];
extern s32 D_8011F2B0[];
void func_8011B5F0(void *arg0) {
    s32 *sp34;
    void **sp3C;
    s32 var_a2;
    s32 var_a2_2;
    int var_a2_3;
    s32 *temp_s0_5;
    s32 *temp_s0_7;
    unsigned long temp_a1_2;
    s32 temp_a0_3;
    s32 temp_a1;
    s32 temp_a0;
    u32 temp_a1_3;
    
    s32 temp_s0;
    s32 temp_s0_3;
    s32 temp_s0_4;
    s32 temp_s0_6;
    s32 temp_s0_8;
    s32 temp_s0_9;
    s32 temp_s1;
    s32 temp_s1_2;
    s32 temp_s1_3;
    s32 temp_s3_2;
    unsigned temp_s3_3;
    s32 temp_s3_4;
    s32 temp_s5;
    s32 temp_s6_2;
    s32 temp_v0_5;
    s32 temp_v0_7;
    
    s32 temp_v1;
    register s32 var_a0;
    unsigned var_a0_2;
    s32 var_a0_3;
    s32 var_a0_4;
    long var_s5;
    s32 var_v0;
    
    u16 temp_v0_4;
    register u8 temp_s6;
    void **temp_s0_2;
    void **temp_s3;
    void **temp_s7;
    void *temp_a0_2;
    void *temp_a0_4;
    void *temp_a0_5;
    void *temp_s4;
    void *temp_v0;
    void *temp_v0_2;
    void *temp_v0_3;
    void *temp_v0_6;

    temp_v1 = (u8)((*(u8 *)((char *)(arg0) + 0x7B)));
    temp_s0 = temp_v1 & 0xFF;
    (*(s32 *)((char *)(arg0) + 0x58)) |= 1;
    temp_a0 = temp_s0 * 4;
    temp_s3 = temp_a0 + D_8011F280;
    temp_v0 = *temp_s3;
    var_s5 = 0;
    if (temp_v0 != NULL) {
        if ((*(f32 *)((char *)(temp_v0) + 0x74)) > 0.0f) {
            temp_v0_2 = (*(void **)((char *)((*(void **)((char *)(temp_v0) + 0x68))) + 4));
            (*(s32 *)((char *)(arg0) + 0x24)) = (s32) (*(s32 *)((char *)(temp_v0_2) + 0x9C));
            (*(s32 *)((char *)(arg0) + 0x28)) = (s32) (*(s32 *)((char *)(temp_v0_2) + 0xA0));
            (*(s32 *)((char *)(arg0) + 0x2C)) = (s32) (*(s32 *)((char *)(temp_v0_2) + 0xA4));
            temp_v0_3 = *temp_s3;
            temp_a1 = (*(s32 *)((char *)(temp_v0_3) + 0x44));
            (*(s32 *)((char *)(arg0) + 0x3C)) = (s32) (*(s32 *)((char *)(temp_v0_3) + 0x3C));
            (*(f32 *)((char *)(arg0) + 0x40)) = (f32) (*(f32 *)((char *)(temp_v0_3) + 0x40));
            (*(s32 *)((char *)(arg0) + 0x44)) = temp_a1;
            if (gSceneType != 3) {
                (*(f32 *)((char *)(arg0) + 0x40)) += 1024.0f;
            }
            func_80016718(arg0);
            func_80016990(arg0, (*(s32 *)((char *)(*temp_s3) + 0x20)));
        }
    } else {
        sp34 = temp_a0 + D_8011F290;
        sp3C = temp_s3;
        temp_s7 = temp_a0 + D_8011F288;
        var_v0 = 0 & 0xFFFF;
loop_6:
        temp_s0_2 = (var_v0 * 4) + D_8010A500;
        temp_a0_2 = *temp_s0_2;
        if (temp_a0_2 == NULL) {
            var_s5 += 1;
            goto block_34;
        }
        temp_v0_4 = (*(u16 *)((char *)(temp_a0_2) + 0x78));
        if (((temp_v0_4 == 0x4D) | (temp_v0_4 == 0x61)) != 0) {
            var_s5 += 1;
            goto block_34;
        }
        if (!(approxDistance(temp_a0_2 + 0x24, arg0 + 0x24) < 2.0f)) {
            ++var_s5;
            goto block_34;
        }
        temp_s4 = (*(void **)((char *)(*temp_s0_2) + 0x6C));
        temp_a0_3 = temp_s0 == 0;
        if (temp_s4 != NULL) {
            var_a0 = -temp_a0_3;
            if ((*(u8 *)((char *)((*(void **)((char *)(temp_s4) + 0xB4))) + 0x12)) == temp_s0) {
                if (*(D_8011F168 + temp_s0) != 0) {
                    var_s5 += 1;
block_34:
                    var_v0 = var_s5 & 0xFFFF;
                    if ((u32) (var_s5 & 0xFFFF) >= 4U) {
                        temp_s3_2 = temp_v1 & 0xFF;
                        temp_s0_3 = temp_s3_2 * 4;
                        if ((*(D_8011F280 + temp_s0_3) == 0) && (*(D_8011F168 + temp_s3_2) == 0) && ((u32) (func_8002B278(D_80102EFC) - *(D_8011F278 + temp_s0_3)) >= 0xAU)) {
                            if (*(D_8011F168 + temp_s3_2) == 0) {
                                temp_s5 = func_80087100((-(temp_s3_2 != 0) & 0x6F) | 0x6E);
                                var_a0_2 = 0x290;
                                if (gSceneType == 2) {
                                    var_a0_2 = 0x28F;
                                }
                                temp_s0_4 = func_80087100(var_a0_2);
                                temp_v0_5 = func_80087100(0x291);
                                var_a2 = 5;
                                if (temp_s3_2 == 0) {
                                    var_a2 = 0xC;
                                }
                                { sprintf(D_8011F170, D_8011EFE0, var_a2, temp_s5, temp_s0_4, temp_v0_5); }
                                func_80073AF8(0, D_8010969C, D_8011F170, -1, -1, 1, 0, 0, 6, 0, 0x3C);
                            }
                            temp_s1 = temp_v1 & 0xFF;
                            temp_v0_6 = (temp_s1 * 0xC) + D_8011F298;
                            (*(s32 *)((char *)(arg0) + 0x24)) = (s32) (*(s32 *)((char *)(temp_v0_6) + 0));
                            (*(s32 *)((char *)(arg0) + 0x28)) = (s32) (*(s32 *)((char *)(temp_v0_6) + 4));
                            (*(s32 *)((char *)(arg0) + 0x2C)) = (s32) (*(s32 *)((char *)(temp_v0_6) + 8));
                            temp_a1_2 = (*(s32 *)((char *)(temp_v0_6) + 8));
                            (*(s32 *)((char *)(arg0) + 0x30)) = (s32) (*(s32 *)((char *)(temp_v0_6) + 0));
                            (*(s32 *)((char *)(arg0) + 0x34)) = (s32) (*(s32 *)((char *)(temp_v0_6) + 4));
                            (*(s32 *)((char *)(arg0) + 0x38)) = temp_a1_2;
                            *(D_8011F168 + temp_s1) = 1;
                            temp_s1_2 = temp_s1 * 4;
                            temp_s0_5 = temp_s1_2 + D_8011F290;
                            *(D_8011F280 + temp_s1_2) = 0;
                            func_8000A270(*temp_s0_5, temp_a1_2);
                            *temp_s0_5 = 0;
                            func_80016718(arg0);
                            func_80016990(arg0, (*(s32 *)((char *)(*(D_8011F270 + temp_s1_2)) + 0x20)));
                            func_800643C8(*(D_8011F2B0 + temp_s1_2));
                        }
                        return;
                    }
                    goto loop_6;
                }
                temp_s3_3 = func_80087100((-(temp_s0 != 0) & 0x6F) | 0x6E);
                temp_v0_5 = func_80087100(0x28E);
                var_a0_3 = 0x290;
                if (gSceneType == 2) {
                    var_a0_3 = 0x28F;
                }
                temp_v0_7 = func_80087100(var_a0_3);
                var_a2_2 = 5;
                if (temp_s0 == 0) {
                    var_a2_2 = 0xC;
                }
                sprintf(D_8011F170, D_8011EFE0, var_a2_2, temp_s3_3, temp_v0_5, temp_v0_7);
                func_8000A894(0x219);
                func_80073AF8(0, D_8010969C, D_8011F170, -1, -1, 1, 0, 0, 6, 0, 0x3C);
                temp_v0_7 = temp_s0 * 0xC;
                *(D_8011F168 + temp_s0) = 1;
                (*(s32 *)((char *)(arg0) + 0x30)) = (s32) *(D_8011F298 + temp_v0_7);
                temp_a1_3 = *(D_8011F2A0 + temp_v0_7);
                (*(s32 *)((char *)(arg0) + 0x34)) = (s32) *(D_8011F29C + temp_v0_7);
                (*(s32 *)((char *)(arg0) + 0x38)) = temp_a1_3;
                (*(s32 *)((char *)(arg0) + 0x24)) = (s32) (*(s32 *)((char *)(arg0) + 0x30));
                (*(s32 *)((char *)(arg0) + 0x28)) = (s32) (*(s32 *)((char *)(arg0) + 0x34));
                (*(s32 *)((char *)(arg0) + 0x2C)) = (s32) (*(s32 *)((char *)(arg0) + 0x38));
                temp_s1_3 = temp_s0 * 4;
                temp_s0_7 = temp_s1_3 + D_8011F290;
                func_8000A270(*temp_s0_7, temp_a1_3);
                *temp_s0_7 = 0;
                func_80016718(arg0);
                func_80016990(arg0, (*(s32 *)((char *)(*(D_8011F270 + temp_s1_3)) + 0x20)));
                (*(s32 *)((char *)(arg0) + 0x3C)) = 0;
                (*(f32 *)((char *)(arg0) + 0x40)) = 0.0f;
                (*(s32 *)((char *)(arg0) + 0x44)) = 0;
                func_800643C8(*(D_8011F2B0 + temp_s1_3));
                temp_a0_4 = *(temp_s1_3 + D_8011F288);
                (*(s32 *)((char *)(temp_a0_4) + 0x28)) = (s32) (((*(s32 *)((char *)(temp_a0_4) + 0x28)) & ~0xFC) | 0x1C);
                return;
            }
            goto block_26;
        }
        var_a0 = -temp_a0_3;
block_26:
        temp_s0_8 = func_80087100(0x28C);
        temp_s6_2 = func_80087100((var_a0 & 0x6F) | 0x6E);
        var_a0_4 = 0x290;
        temp_s3_4 = func_80087100((-(temp_s0 != 0) & 0x6F) | 0x6E);
        if (gSceneType == 2) {
            var_a0_4 = 0x28F;
        }
        var_a2_3 = 0xC;
        temp_v1 = func_80087100(var_a0_4);
        if (temp_s0 == 0) {
            var_a2_3 = 5;
        }
        if (temp_s0 == 0) {
            var_a0_4 = 0xC;
        } else {
            var_a0_4 = 5;
        }
        sprintf(D_8011F170, D_8011EFEC, var_a2_3, temp_s6_2, var_a0_4, temp_s3_4, temp_v1);
        func_80073AF8(0, D_8010969C, D_8011F170, -1, -1, 1, 0, 0, 6, 0, 0x3C);
        temp_v1 = var_s5 & 0xFFFF;
        *sp34 = func_8000A894(0x21E);
        *(D_8011F168 + temp_s0) = 0;
        *sp3C = *((temp_v1 * 4) + D_8010A500);
        func_80064370(arg0, temp_v1);
        temp_a0_5 = *temp_s7;
        temp_s0_9 = temp_s0 * 0x24;
        (*(s32 *)((char *)(temp_a0_5) + 0x28)) = (s32) (((*(s32 *)((char *)(temp_a0_5) + 0x28)) & ~0xFC) | 0x10);
        func_80016624(*temp_s7, *((*(D_8011ED10 + temp_s0_9) * 4) + gTrackMarkerTable), *(((*(s8 *)((char *)(temp_s4) + 0x182)) * 4) + gTrackMarkerTable));
        *(D_8011ED10 + temp_s0_9) = (s16) (s8) (u8) (*(s8 *)((char *)(temp_s4) + 0x182));
    }
}
