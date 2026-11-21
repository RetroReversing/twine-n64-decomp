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

f32 approxDistance();
s32 func_8000A894();
s32 func_80016624();
s32 func_80016718();
s16 func_8002B278();
s32 func_80064370();
s32 func_800643C8();
s32 func_80073AF8();
s32 func_80087100();
s32 listUnlinkFree();
s32 objectListInsert();
s32 sprintf();
extern char D_80102EFC[];
extern s32 D_8010969C;
extern char D_8010A500[];
extern char D_8011ED10[];
extern char D_8011EFE0[];
extern char D_8011EFEC[];
extern char D_8011F170[];
extern char D_8011F278[];
extern char D_8011F288[];
extern char D_8011F29C[];
extern char D_8011F2A0[];
extern char D_8011F2B0[];
extern u8 gSceneType;
extern s32 gTrackMarkerTable;
extern s32 sProbeActive;
extern s32 sProbeFlags;
extern s32 sProbeHandles;
extern s32 sProbeObjects;
extern s32 sProbePositions;

void func_8011B5F0(void *arg0) {
    s32 *sp34;
    void **sp3C;
    s32 var_a2;
    s32 var_a2_2;
    s32 var_a2_3;
    s32 *temp_s0_5;
    s32 *temp_s0_7;
    s32 temp_a0;
    s32 temp_a0_3;
    s32 temp_a1;
    s32 temp_a1_2;
    s32 temp_a1_3;
    s32 temp_a1_4;
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
    s32 temp_s3_3;
    s32 temp_s3_4;
    s32 temp_s5;
    s32 temp_s6_2;
    s32 temp_v0_5;
    s32 temp_v0_7;
    s32 temp_v0_8;
    s32 temp_v1;
    s32 var_a0;
    s32 var_a0_2;
    s32 var_a0_3;
    s32 var_a0_4;
    s32 var_s5;
    s32 var_v0;
    s32 var_v0_2;
    u16 temp_v0_4;
    u8 temp_s6;
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

    temp_s6 = M2C_FIELD(arg0, u8 *, 0x7B);
    temp_s0 = temp_s6 & 0xFF;
    M2C_FIELD(arg0, s32 *, 0x58) |= 1;
    temp_a0 = temp_s0 * 4;
    temp_s3 = temp_a0 + &sProbeFlags;
    temp_v0 = *temp_s3;
    var_s5 = 0;
    if (temp_v0 != NULL) {
        if (M2C_FIELD(temp_v0, f32 *, 0x74) > 0.0f) {
            temp_v0_2 = M2C_FIELD(M2C_FIELD(temp_v0, void **, 0x68), void **, 4);
            M2C_FIELD(arg0, s32 *, 0x24) = (s32) M2C_FIELD(temp_v0_2, s32 *, 0x9C);
            M2C_FIELD(arg0, s32 *, 0x28) = (s32) M2C_FIELD(temp_v0_2, s32 *, 0xA0);
            M2C_FIELD(arg0, s32 *, 0x2C) = (s32) M2C_FIELD(temp_v0_2, s32 *, 0xA4);
            temp_v0_3 = *temp_s3;
            temp_a1 = M2C_FIELD(temp_v0_3, s32 *, 0x44);
            M2C_FIELD(arg0, s32 *, 0x3C) = (s32) M2C_FIELD(temp_v0_3, s32 *, 0x3C);
            M2C_FIELD(arg0, f32 *, 0x40) = (f32) M2C_FIELD(temp_v0_3, f32 *, 0x40);
            M2C_FIELD(arg0, s32 *, 0x44) = temp_a1;
            if (gSceneType != 3) {
                M2C_FIELD(arg0, f32 *, 0x40) += 1024.0f;
            }
            func_80016718(arg0, temp_a1);
            objectListInsert(arg0, M2C_FIELD(*temp_s3, s32 *, 0x20));
        }
    } else {
        sp34 = temp_a0 + &sProbeHandles;
        temp_s7 = temp_a0 + &sProbeHandles;
        sp3C = temp_s3;
        var_v0 = 0 & 0xFFFF;
loop_6:
        temp_s0_2 = (var_v0 * 4) + D_8010A500;
        temp_a0_2 = *temp_s0_2;
        if (temp_a0_2 == NULL) {
            var_s5 += 1;
            goto block_34;
        }
        temp_v0_4 = M2C_FIELD(temp_a0_2, u16 *, 0x78);
        if (((temp_v0_4 == 0x4D) | (temp_v0_4 == 0x61)) != 0) {
            var_s5 += 1;
            goto block_34;
        }
        if (!(approxDistance(temp_a0_2 + 0x24, arg0 + 0x24) < 2.0f)) {
            var_s5 += 1;
            goto block_34;
        }
        temp_s4 = M2C_FIELD(*temp_s0_2, void **, 0x6C);
        temp_a0_3 = temp_s0 == 0;
        if (temp_s4 != NULL) {
            var_a0 = -temp_a0_3;
            if (M2C_FIELD(M2C_FIELD(temp_s4, void **, 0xB4), u8 *, 0x12) == temp_s0) {
                if (*(&sProbeActive + temp_s0) != 0) {
                    var_s5 += 1;
block_34:
                    var_v0 = var_s5 & 0xFFFF;
                    if ((u32) (var_s5 & 0xFFFF) >= 4U) {
                        temp_s3_2 = temp_s6 & 0xFF;
                        temp_s0_3 = temp_s3_2 * 4;
                        if ((*(&sProbeFlags + temp_s0_3) == 0) && (*(&sProbeActive + temp_s3_2) == 0) && ((u32) (func_8002B278(D_80102EFC) - *(D_8011F278 + temp_s0_3)) >= 0xAU)) {
                            if (*(&sProbeActive + temp_s3_2) == 0) {
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
                                sprintf(D_8011F170, D_8011EFE0, var_a2, temp_s5, temp_s0_4, temp_v0_5);
                                func_80073AF8(0, D_8010969C, D_8011F170, -1, -1, 1, 0, 0, 6, 0, 0x3C);
                            }
                            temp_s1 = temp_s6 & 0xFF;
                            temp_v0_6 = (temp_s1 * 0xC) + &sProbePositions;
                            M2C_FIELD(arg0, s32 *, 0x24) = (s32) M2C_FIELD(temp_v0_6, s32 *, 0);
                            M2C_FIELD(arg0, s32 *, 0x28) = (s32) M2C_FIELD(temp_v0_6, s32 *, 4);
                            M2C_FIELD(arg0, s32 *, 0x2C) = (s32) M2C_FIELD(temp_v0_6, s32 *, 8);
                            temp_a1_2 = M2C_FIELD(temp_v0_6, s32 *, 8);
                            M2C_FIELD(arg0, s32 *, 0x30) = (s32) M2C_FIELD(temp_v0_6, s32 *, 0);
                            M2C_FIELD(arg0, s32 *, 0x34) = (s32) M2C_FIELD(temp_v0_6, s32 *, 4);
                            M2C_FIELD(arg0, s32 *, 0x38) = temp_a1_2;
                            *(&sProbeActive + temp_s1) = 1;
                            temp_s1_2 = temp_s1 * 4;
                            temp_s0_5 = temp_s1_2 + &sProbeHandles;
                            *(&sProbeFlags + temp_s1_2) = 0;
                            listUnlinkFree(*temp_s0_5, temp_a1_2);
                            *temp_s0_5 = 0;
                            func_80016718(arg0);
                            objectListInsert(arg0, M2C_FIELD(*(&sProbeObjects + temp_s1_2), s32 *, 0x20));
                            func_800643C8(*(D_8011F2B0 + temp_s1_2));
                        }
                        return;
                    }
                    goto loop_6;
                }
                temp_s3_3 = func_80087100((-(temp_s0 != 0) & 0x6F) | 0x6E);
                var_a0_3 = 0x290;
                temp_s0_6 = func_80087100(0x28E);
                if (gSceneType == 2) {
                    var_a0_3 = 0x28F;
                }
                temp_v0_7 = func_80087100(var_a0_3);
                var_a2_2 = 5;
                if (temp_s0 == 0) {
                    var_a2_2 = 0xC;
                }
                sprintf(D_8011F170, D_8011EFE0, var_a2_2, temp_s3_3, temp_s0_6, temp_v0_7);
                func_8000A894(0x219);
                func_80073AF8(0, D_8010969C, D_8011F170, -1, -1, 1, 0, 0, 6, 0, 0x3C);
                temp_v0_8 = temp_s0 * 0xC;
                *(&sProbeActive + temp_s0) = 1;
                temp_a1_3 = *(D_8011F2A0 + temp_v0_8);
                M2C_FIELD(arg0, s32 *, 0x30) = (s32) *(&sProbePositions + temp_v0_8);
                M2C_FIELD(arg0, s32 *, 0x34) = (s32) *(D_8011F29C + temp_v0_8);
                M2C_FIELD(arg0, s32 *, 0x38) = temp_a1_3;
                M2C_FIELD(arg0, s32 *, 0x24) = (s32) M2C_FIELD(arg0, s32 *, 0x30);
                M2C_FIELD(arg0, s32 *, 0x28) = (s32) M2C_FIELD(arg0, s32 *, 0x34);
                M2C_FIELD(arg0, s32 *, 0x2C) = (s32) M2C_FIELD(arg0, s32 *, 0x38);
                temp_s1_3 = temp_s0 * 4;
                temp_s0_7 = temp_s1_3 + &sProbeHandles;
                listUnlinkFree(*temp_s0_7, temp_a1_3);
                *temp_s0_7 = 0;
                func_80016718(arg0);
                objectListInsert(arg0, M2C_FIELD(*(&sProbeObjects + temp_s1_3), s32 *, 0x20));
                M2C_FIELD(arg0, s32 *, 0x3C) = 0;
                M2C_FIELD(arg0, f32 *, 0x40) = 0.0f;
                M2C_FIELD(arg0, s32 *, 0x44) = 0;
                func_800643C8(*(D_8011F2B0 + temp_s1_3));
                temp_a0_4 = *(temp_s1_3 + D_8011F288);
                M2C_FIELD(temp_a0_4, s32 *, 0x28) = (s32) ((M2C_FIELD(temp_a0_4, s32 *, 0x28) & ~0xFC) | 0x1C);
                return;
            }
            goto block_26;
        }
        var_a0 = -temp_a0_3;
block_26:
        temp_s6_2 = func_80087100((var_a0 & 0x6F) | 0x6E);
        temp_s0_8 = func_80087100(0x28C);
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
            var_v0_2 = 0xC;
        } else {
            var_v0_2 = 5;
        }
        sprintf(D_8011F170, D_8011EFEC, var_a2_3, temp_s6_2, var_v0_2, temp_s3_4, temp_v1);
        func_80073AF8(0, D_8010969C, D_8011F170, -1, -1, 1, 0, 0, 6, 0, 0x3C);
        temp_a1_4 = var_s5 & 0xFFFF;
        *sp34 = func_8000A894(0x21E);
        *(&sProbeActive + temp_s0) = 0;
        *sp3C = *((temp_a1_4 * 4) + D_8010A500);
        func_80064370(arg0, temp_a1_4);
        temp_a0_5 = *temp_s7;
        temp_s0_9 = temp_s0 * 0x24;
        M2C_FIELD(temp_a0_5, s32 *, 0x28) = (s32) ((M2C_FIELD(temp_a0_5, s32 *, 0x28) & ~0xFC) | 0x10);
        func_80016624(*temp_s7, *((*(D_8011ED10 + temp_s0_9) * 4) + &gTrackMarkerTable), *((M2C_FIELD(temp_s4, s8 *, 0x182) * 4) + &gTrackMarkerTable));
        *(D_8011ED10 + temp_s0_9) = (s16) (s8) (u8) M2C_FIELD(temp_s4, s8 *, 0x182);
    }
}
