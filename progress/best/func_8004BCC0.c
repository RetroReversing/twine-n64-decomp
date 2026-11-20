/* machine draft (m2c) for gcc-2.7.2-kmc -G0 -mips3 -mgp32 -mfp32 -O2, tried by autopilot */

extern float D_800D3E24;
extern float D_800D3E28;
extern float D_800D3E2C;
s32 func_80047E4C();
s32 func_800487F0();
s32 Sphere_OverlapsPoint(s32);
s32 func_800488D4();
s32 rayHitsTriangleXZ();
s32 func_8004D910();
s32 func_8004E418();
s32 func_80082D24();
s32 rotateVec3ByMat3();
s32 func_80083B64();
extern void *gPlayerActor;
extern void **D_80108F84;

typedef struct { float field_0; float field_4; float field_8; } __repair_record_arg1;
s32 func_8004BCC0(void **arg0, void *arg1, void *arg2, f32 arg3) { float __repair_float_constant; 
    f32 sp48[3];
    f32 sp28[3];
    f32 sp38[3];
    u8 sp58[0x48];
    s16 sp88[3];
    f32 sp90[3];
    register f32 spA0;
    f32 spA4;
    char spA8[0x28];
    u8 stack_pad[0x18];
    f32 spD0[3];
    f32 spE0[3];
    f32 spF0;
    void *spFC;
    f32 *sp124;
    f32 *sp11C;
    f32 *sp114;
    f32 *sp10C;
    s32 *sp104;
    register f32 *sp12C;
    s16 *sp134;
    
    
    f32 temp_fs2;
    f32 var_fs0;
    s32 temp_s0;
    
    s32 temp_s3_2;
    s32 temp_s4;
    s32 temp_s6;
    s32 temp_s7;
    register s32 temp_v0;
    register s32 temp_v0_2;
    int temp_v1_11;
    register s32 temp_v1_13;
    s32 temp_v1_3;
    unsigned int temp_v1_5;
    s32 temp_v1_7;
    register long temp_v1_9;
    s32 var_s0;
    s32 var_s0_2;
    s32 var_s2;
    s32 var_s2_2;
    register s32 var_s2_3;
    s32 var_s2_4;
    register char *var_s4;
    
    u16 temp_v1_10;
    u16 temp_v1_12;
    u16 temp_v1_2;
    u16 temp_v1_4;
    u16 temp_v1_6;
    u16 temp_v1_8;
    register u32 temp_s3;
    u32 temp_v1;
u32 __repair_phase_temp_v1;
    u32 var_s0_3;
    u32 var_s0_4;
    u32 var_s0_5;
    u32 var_s0_6;
    void **var_s5;
    void *temp_a0;
    
    
    
    void *temp_s1;
    void *temp_s2;
    void *var_s1;
    void *var_s3;
    register void *var_s3_2;

    var_fs0 = arg3;
    __repair_float_constant = 0.0f; var_s5 = arg0; spFC = arg2; temp_fs2 = var_fs0;
    if (var_s5 != NULL) {
        sp28[0] = (((__repair_record_arg1*)arg1)->field_0);
        var_s1 = *var_s5;
        sp28[1] = (((__repair_record_arg1*)arg1)->field_4) + var_fs0;
        gPlayerActor = NULL;
        D_80108F84 = NULL;
        sp28[2] = (((__repair_record_arg1*)arg1)->field_8);
        if (var_s1 != NULL) {
            sp104 = sp58;
            sp10C = sp38;
            sp114 = sp48;
            sp11C = sp90;
            sp124 = &spA0;
            sp12C = &spA4;
            do {
                if ((*(void **)((char *)(var_s1) + 0x70)) != NULL) {
                    temp_s3 = (*(s32 *)((char *)(var_s1) + 0x58)) & 0x400;
                    if ((temp_s3 == 0) && ((*(s32 *)((char *)(var_s1) + 0x5C)) & 0x200) && ((func_800487F0(var_s1) << 0x18) != 0)) {
                        temp_s2 = (*(void **)((char *)(var_s1) + 0x70));
                        sp88[0] = (s16) (s32) -(*(f32 *)((char *)(var_s1) + 0x3C));
                        sp88[1] = (s16) (s32) -(*(f32 *)((char *)(var_s1) + 0x40));
                        sp88[2] = (s16) (s32) -(*(f32 *)((char *)(var_s1) + 0x44));
                        func_80082D24(sp88);
                        sp38[0] = (((__repair_record_arg1*)arg1)->field_0) - (*(f32 *)((char *)(var_s1) + 0x24));
                        sp38[1] = (((__repair_record_arg1*)arg1)->field_4) - (*(f32 *)((char *)(var_s1) + 0x28));
                        sp38[2] = (((__repair_record_arg1*)arg1)->field_8) - (*(f32 *)((char *)(var_s1) + 0x2C));
                        sp48[0] = sp28[0] - (*(f32 *)((char *)(var_s1) + 0x24));
                        sp48[1] = sp28[1] - (*(f32 *)((char *)(var_s1) + 0x28));
                        sp48[2] = sp28[2] - (*(f32 *)((char *)(var_s1) + 0x2C));
                        rotateVec3ByMat3(sp104, sp10C);
                        temp_s0 = temp_s2 + 0x18;
                        rotateVec3ByMat3(sp104, sp114);
                        if ((func_800488D4(temp_s0, sp10C, sp114) << 0x18) != 0) {
                            *(__repair_record_arg1 *)sp90 = *(__repair_record_arg1 *)&D_800D3E24;
                            temp_v0 = func_8004E418(temp_s0, sp10C, sp114) & 0xFFFF;
                            temp_s7 = temp_v0 & 0xFF;
                            temp_s6 = temp_v0 & 0xFF00;
                            rotateVec3ByMat3(sp104, sp11C);
                            temp_v1 = (*(u8 *)((char *)(temp_s2) + 0x48)) & 4;
                            if (temp_v1) {
                                var_s4 = (*(u16 **)((char *)(temp_s2) + 0x3C));
                                if (temp_s3 < (u16) (*(u16 *)((char *)(temp_s2) + 0x40))) {
                                    var_s0 = 0;
                                    var_s3 = var_s4 + 4;
                                    do {
                                        temp_v1 = var_s0 & 0xFFFF;
    temp_v1_2 = *(u16 *)(((temp_v1) * 2) + (*(s32 *)((char *)(temp_s2) + 0x38)));
                                        if ((temp_s7 & temp_v1_2) && (temp_s6 & temp_v1_2)) {
                                            temp_v1_3 = (*(s32 *)((char *)(temp_s2) + 0x34));
                                            if ((rayHitsTriangleXZ(sp38, sp90, temp_v1_3 + (*(u16 *)var_s4 * 0xC), temp_v1_3 + ((*(u16 *)((char *)(var_s3) + -2)) * 0xC), temp_v1_3 + ((*(u16 *)((char *)(var_s3) + 0)) * 0xC), sp124) & 0xFF) && (spA0 >= __repair_float_constant) && (spA0 < var_fs0)) {
                                                var_fs0 = spA0;
                                                gPlayerActor = var_s1;
                                                D_80108F84 = NULL;
                                            }
                                        }
                                        var_s3 += 6;
                                        var_s4 += 6;
                                        var_s0 += 1;
                                    } while ((u32) (var_s0 & 0xFFFF) < (u16) (*(u16 *)((char *)(temp_s2) + 0x40)));
                                }
                            } else {
                                var_s0_2 = 0;
                                var_s4 = (*(u16 **)((char *)(temp_s2) + 0x3C));
                                if (temp_v1 < (u16) (*(u16 *)((char *)(temp_s2) + 0x40))) {
                                    var_s3_2 = var_s4 + 2;
                                    do {
                                        temp_v1_4 = *(u16 *)(((var_s0_2 & 0xFFFF) * 2) + (*(s32 *)((char *)(temp_s2) + 0x38)));
                                        if ((temp_s7 & temp_v1_4) && (temp_s6 & temp_v1_4)) {
                                            temp_v1_5 = (*(s32 *)((char *)(temp_s2) + 0x34));
                                            if ((rayHitsTriangleXZ(sp38, sp90, temp_v1_5 + (*(u16 *)var_s4 * 0xC), temp_v1_5 + ((*(u8 *)((char *)(var_s3_2) + -1)) * 0xC), temp_v1_5 + ((*(u8 *)((char *)(var_s3_2) + 0)) * 0xC), sp12C) & 0xFF) && (spA4 >= __repair_float_constant) && (var_fs0 > spA4)) {
                                                var_fs0 = spA4;
                                                gPlayerActor = var_s1;
                                                D_80108F84 = NULL;
                                            }
                                        }
                                        var_s3_2 += 3;
                                        ++var_s0_2;
                                        var_s4 += 3;
                                    } while ((u32) (var_s0_2 & 0xFFFF) < (u16) (*(u16 *)((char *)(temp_s2) + 0x40)));
                                }
                            }
                        }
                    }
                }
                var_s1 = (*(void **)((char *)(var_s1) + 0));
            } while (var_s1 != NULL);
        }
        if (var_s5 != NULL) {
            sp134 = sp88;
            sp10C = spD0;
            sp114 = spE0;
            do {
                if (((*(s32 *)((char *)(var_s5) + 0x50)) & 0x200) && ((Sphere_OverlapsPoint((s8 *) var_s5 + 0x40) << 0x18) != 0)) {
                    temp_s1 = (*(void **)((char *)(var_s5) + 0x3C));
                    *(__repair_record_arg1 *)sp88 = *(__repair_record_arg1 *)arg1;
                    *(__repair_record_arg1 *)spD0 = *(__repair_record_arg1 *)sp28;
                    if (((u32) (*(u32 *)((char *)(var_s5) + 0x5C)) >> 0x17) & 1) {
                        ((f32 *)sp88)[0] -= (*(f32 *)((char *)(var_s5) + 0x24));
                        ((f32 *)sp88)[1] -= (*(f32 *)((char *)(var_s5) + 0x28));
                        spD0[0] -= (*(f32 *)((char *)(var_s5) + 0x24));
                        spD0[1] -= (*(f32 *)((char *)(var_s5) + 0x28));
                        ((f32 *)sp88)[2] -= (*(f32 *)((char *)(var_s5) + 0x2C));
                        spD0[2] -= (*(f32 *)((char *)(var_s5) + 0x2C));
                    }
                    if (((u32) (*(u32 *)((char *)(var_s5) + 0x5C)) >> 0x17) & 2) {
                        func_80047E4C(var_s5, 0, spA8);
                        func_80083B64(spA8, sp134);
                        func_80083B64(spA8, (s16 *) sp10C);
                    }
                    temp_s0 = temp_s1 + 0x18;
                    if ((func_800488D4(temp_s0, (f32 *) sp134, sp10C) << 0x18) != 0) {
                        *(__repair_record_arg1 *)spE0 = *(__repair_record_arg1 *)&D_800D3E24;
                        temp_v0_2 = func_8004E418(temp_s0, (f32 *) sp134, sp10C);
                        temp_s4 = temp_v0_2 & 0xFF;
                        temp_s3_2 = temp_v0_2 & 0xFF00;
                        if (!(((u32) (*(u32 *)((char *)(var_s5) + 0x5C)) >> 0x17) & 2) || (func_80083B64(spA8, (s16 *) sp114), ((((u32) (*(u32 *)((char *)(var_s5) + 0x5C)) >> 0x17) & 2) == 0))) {
                            if ((*(u8 *)((char *)(temp_s1) + 0x48)) & 4) {
                                if ((*(u16 *)((char *)(temp_s1) + 0x40)) != 0) {
                                    var_s0_3 = 0;
                                    var_s2 = 0;
                                    do {
                                        temp_a0 = (*(s32 *)((char *)(temp_s1) + 0x3C)) + var_s2;
                                        temp_v1_6 = *(u16 *)((var_s0_3 * 2) + (*(s32 *)((char *)(temp_s1) + 0x38)));
                                        if ((temp_s4 & temp_v1_6) && (temp_s3_2 & temp_v1_6)) {
                                            temp_v1_7 = (*(s32 *)((char *)(temp_s1) + 0x34));
                                            if ((func_8004D910(sp88, spE0, temp_v1_7 + ((*(u16 *)((char *)(temp_a0) + 0)) * 0xC), temp_v1_7 + ((*(u16 *)((char *)(temp_a0) + 2)) * 0xC), temp_v1_7 + ((*(u16 *)((char *)(temp_a0) + 4)) * 0xC), &spF0) & 0xFF) && (spF0 >= __repair_float_constant) && (spF0 < var_fs0)) {
                                                var_fs0 = spF0;
                                                gPlayerActor = NULL;
                                                D_80108F84 = var_s5;
                                            }
                                        }
                                        var_s0_3 += 1;
                                        var_s2 += 6;
                                    } while (var_s0_3 < (u16) (*(u16 *)((char *)(temp_s1) + 0x40)));
                                }
                            } else {
                                var_s0_4 = 0;
                                if ((*(u16 *)((char *)(temp_s1) + 0x40)) != 0) {
                                    var_s2_2 = 0;
                                    do {
                                        temp_a0 = (*(s32 *)((char *)(temp_s1) + 0x3C)) + var_s2_2;
                                        temp_v1_8 = *(u16 *)((var_s0_4 * 2) + (*(s32 *)((char *)(temp_s1) + 0x38)));
                                        if ((temp_s4 & temp_v1_8) && (temp_s3_2 & temp_v1_8)) {
                                            temp_v1_9 = (*(s32 *)((char *)(temp_s1) + 0x34));
                                            if ((func_8004D910(sp88, spE0, temp_v1_9 + ((*(u8 *)((char *)(temp_a0) + 0)) * 0xC), temp_v1_9 + ((*(u8 *)((char *)(temp_a0) + 1)) * 0xC), temp_v1_9 + ((*(u8 *)((char *)(temp_a0) + 2)) * 0xC), &spF0) & 0xFF) && (__repair_float_constant <= spF0) && (var_fs0 > spF0)) {
                                                var_fs0 = spF0;
                                                gPlayerActor = NULL;
                                                D_80108F84 = var_s5;
                                            }
                                        }
                                        var_s0_4 += 1;
                                        var_s2_2 += 3;
                                    } while (var_s0_4 < (u16) (*(u16 *)((char *)(temp_s1) + 0x40)));
                                }
                            }
                        } else if ((*(u8 *)((char *)(temp_s1) + 0x48)) & 4) {
                            var_s0_5 = 0;
                            if ((*(u16 *)((char *)(temp_s1) + 0x40)) != 0) {
                                var_s2_3 = 0;
                                do {
                                    temp_a0 = (*(s32 *)((char *)(temp_s1) + 0x3C)) + var_s2_3;
                                    temp_v1_10 = *(u16 *)((var_s0_5 * 2) + (*(s32 *)((char *)(temp_s1) + 0x38)));
                                    if ((temp_s4 & temp_v1_10) && (temp_s3_2 & temp_v1_10)) {
                                        temp_v1_11 = (*(s32 *)((char *)(temp_s1) + 0x34));
                                        if ((func_8004D910(sp88, spE0, temp_v1_11 + ((*(u16 *)((char *)(temp_a0) + 0)) * 0xC), temp_v1_11 + ((*(u16 *)((char *)(temp_a0) + 2)) * 0xC), temp_v1_11 + ((*(u16 *)((char *)(temp_a0) + 4)) * 0xC), &spF0) & 0xFF) && (__repair_float_constant <= spF0) && (spF0 < var_fs0)) {
                                            var_fs0 = spF0;
                                            gPlayerActor = NULL;
                                            D_80108F84 = var_s5;
                                        }
                                    }
                                    ++var_s0_5;
                                    var_s2_3 += 6;
                                } while (var_s0_5 < (u16) (*(u16 *)((char *)(temp_s1) + 0x40)));
                            }
                        } else {
                            var_s0_6 = 0;
                            if ((*(u16 *)((char *)(temp_s1) + 0x40)) != 0) {
                                var_s2_4 = 0;
                                do {
                                    temp_v1_12 = *(u16 *)(((u32)var_s0_6 * 2) + (*(s32 *)((char *)(temp_s1) + 0x38)));
                                    temp_a0 = (*(s32 *)((char *)(temp_s1) + 0x3C)) + var_s2_4;
                                    if ((temp_s4 & temp_v1_12) && (temp_s3_2 & temp_v1_12)) {
                                        temp_v1_13 = (*(s32 *)((char *)(temp_s1) + 0x34));
                                        if ((func_8004D910(sp88, spE0, temp_v1_13 + ((*(u8 *)((char *)(temp_a0) + 0)) * 0xC), temp_v1_13 + ((*(u8 *)((char *)(temp_a0) + 1)) * 0xC), temp_v1_13 + ((*(u8 *)((char *)(temp_a0) + 2)) * 0xC), &spF0) & 0xFF) && (spF0 >= __repair_float_constant) && (spF0 < var_fs0)) {
                                            var_fs0 = spF0;
                                            gPlayerActor = NULL;
                                            D_80108F84 = var_s5;
                                        }
                                    }
                                    var_s0_6 += 1;
                                    var_s2_4 += 3;
                                } while (var_s0_6 < (u16) (*(u16 *)((char *)(temp_s1) + 0x40)));
                            }
                        }
                    }
                }
                var_s5 = (*(void ***)((char *)(var_s5) + 0x14));
            } while (var_s5 != NULL);
        }
        if (var_fs0 == temp_fs2) {
            goto block_83;
        }
        (*(f32 *)((char *)(spFC) + 0)) = (f32) (((__repair_record_arg1*)arg1)->field_0);
        (*(f32 *)((char *)(spFC) + 4)) = (f32) ((((__repair_record_arg1*)arg1)->field_4) + var_fs0);
        (*(f32 *)((char *)(spFC) + 8)) = (f32) (((__repair_record_arg1*)arg1)->field_8);
        return 1;
    }
block_83:
    return 0;
}
