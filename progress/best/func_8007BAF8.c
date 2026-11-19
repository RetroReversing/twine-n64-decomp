/* machine draft (m2c) for gcc-2.7.2-kmc -G0 -mips3 -mgp32 -mfp32 -O2, tried by autopilot */

s32 func_80002BD0();
s32 func_8003D6FC();
f32 func_80045764();
f32 func_800461D4();
s32 func_80047E4C();
s32 func_8004E6E4();
s32 func_8004F430();
s32 func_80077960();
s32 func_80077E00();
s32 func_80083B64();
extern void *D_80108F84;
extern s32 func_8004DBD8;

s32 func_8007BAF8(void *arg0, f32 *arg1, s32 arg2, s32 arg3) {
    unsigned int __repair_store_1;
    s32 __repair_store_0;
    s32 __repair_store_2;
    f32 sp28[3];
    f32 sp38[3];
    long sp48;
    s32 sp70;
    f32 sp98[24];
    
    int sp104;
    f32 *temp_s4;
    char *var_s0;
    char *var_s0_2;
    f32 temp_fs0;
    f32 temp_fs0_2;
    f32 temp_fv0;
    f32 temp_fv0_10;
    f32 temp_fv0_11;
    f32 temp_fv0_12;
    f32 temp_fv0_2;
    f32 temp_fv0_3;
    f32 temp_fv0_4;
    f32 temp_fv0_5;
    f32 temp_fv0_6;
    f32 temp_fv0_7;
    f32 temp_fv0_8;
    f32 temp_fv0_9;
    f32 var_fs1;
    f32 var_fs2;
    s32 temp_a1;
    unsigned temp_a1_2;
    s32 temp_a2;
    s32 temp_a2_2;
    s32 temp_s5;
    s32 var_a1;
    s32 var_s1;
    register s32 var_s1_2;
    s32 var_s6;
    s32 var_s7;
    register s32 var_v0;
    void *temp_a2_3;
    void *temp_fp;
    void *temp_v0;
    void *temp_v0_2;

    __repair_store_2 = arg2;
    sp104 = arg3;
    temp_fp = (*(void **)((char *)(arg0) + 0x6C));
    temp_s5 = (*(s32 *)((char *)(arg0) + 0x20));
    sp28[0] = (*(f32 *)((char *)(arg1) + 0)) - (*(f32 *)((char *)(arg0) + 0x24));
    sp28[1] = (*(f32 *)((char *)(arg1) + 4)) - (*(f32 *)((char *)(arg0) + 0x28));
    sp28[2] = (*(f32 *)((char *)(arg1) + 8)) - (*(f32 *)((char *)(arg0) + 0x2C));
    temp_fv0 = func_80045764(sp28, arg1, sp28);
    var_v0 = 0;
    if (!(temp_fv0 < 0.01f)) {
        if ((func_8004F430(temp_s5, arg0 + 0x24, sp28, (int)temp_fv0) << 0x18) != 0) {
            temp_fv0_2 = (*(f32 *)((char *)((*(void **)((char *)(D_80108F84) + 0x3C))) + 0x18)) - 0.55f;
            sp98[21] = temp_fv0_2;
            sp98[12] = temp_fv0_2;
            sp98[9] = temp_fv0_2;
            sp98[0] = temp_fv0_2;
            temp_fv0_3 = (*(f32 *)((char *)((*(void **)((char *)(D_80108F84) + 0x3C))) + 0x1C)) + 0.55f;
            sp98[18] = temp_fv0_3;
            sp98[15] = temp_fv0_3;
            sp98[6] = temp_fv0_3;
            sp98[3] = temp_fv0_3;
            temp_fv0_4 = (*(f32 *)((char *)((*(void **)((char *)(D_80108F84) + 0x3C))) + 0x20)) - 0.55f;
            sp98[16] = temp_fv0_4;
            sp98[13] = temp_fv0_4;
            sp98[4] = temp_fv0_4;
            sp98[1] = temp_fv0_4;
            temp_fv0_5 = (*(f32 *)((char *)((*(void **)((char *)(D_80108F84) + 0x3C))) + 0x24)) + 0.55f;
            sp98[22] = temp_fv0_5;
            sp98[19] = temp_fv0_5;
            sp98[10] = temp_fv0_5;
            sp98[7] = temp_fv0_5;
            temp_fv0_6 = (*(f32 *)((char *)((*(void **)((char *)(D_80108F84) + 0x3C))) + 0x28)) - 0.55f;
            sp98[11] = temp_fv0_6;
            sp98[8] = temp_fv0_6;
            sp98[5] = temp_fv0_6;
            sp98[2] = temp_fv0_6;
            temp_fv0_7 = (*(f32 *)((char *)((*(void **)((char *)(D_80108F84) + 0x3C))) + 0x2C)) + 0.55f;
            sp98[23] = temp_fv0_7;
            sp98[20] = temp_fv0_7;
            sp98[17] = temp_fv0_7;
            sp98[14] = temp_fv0_7;
            func_80047E4C(D_80108F84, &sp48, &sp70);
            sp38[0] = (*(f32 *)((char *)(arg1) + 0));
            sp38[1] = (*(f32 *)((char *)(arg1) + 4));
            sp38[2] = (*(f32 *)((char *)(arg1) + 8));
            sp38[0] -= (*(f32 *)((char *)(D_80108F84) + 0x24));
            sp38[1] -= (*(f32 *)((char *)(D_80108F84) + 0x28));
            var_fs1 = 65536.0f;
            sp38[2] -= (*(f32 *)((char *)(D_80108F84) + 0x2C));
            func_80083B64(&sp70, sp38);
            var_s1 = 0;
            var_fs2 = 65536.0f;
            if (((func_8003D6FC(sp38, D_80108F84) << 0x18) == 0) || (arg3 == 0)) {
                var_s0 = sp98;
                do {
                    func_80083B64(&sp48, var_s0);
                    (*(f32 *)((char *)(var_s0) + 0)) += (*(f32 *)((char *)(D_80108F84) + 0x24));
                    (*(f32 *)((char *)(var_s0) + 4)) = (f32) (*(f32 *)((char *)(arg0) + 0x28));
                    var_s1 += 1;
                    (*(f32 *)((char *)(var_s0) + 8)) += (*(f32 *)((char *)(D_80108F84) + 0x2C));
                    var_s0 += 0xC;
                } while (var_s1 < 8);
                var_s6 = -1;
                var_s7 = -1;
                var_s1_2 = 0;
                temp_s4 = arg0 + 0x24;
                var_s0_2 = sp98;
                __repair_rows: {
                    sp28[0] = (*(f32 *)((char *)(var_s0_2) + 0)) - (*(f32 *)((char *)(arg0) + 0x24));
                    sp28[1] = (*(f32 *)((char *)(var_s0_2) + 4)) - (*(f32 *)((char *)(arg0) + 0x28));
                    sp28[2] = (*(f32 *)((char *)(var_s0_2) + 8)) - (*(f32 *)((char *)(arg0) + 0x2C));
                    temp_fv0_8 = func_80045764(sp28, sp28);
                    if (((func_8004F430(temp_s5, temp_s4, sp28, temp_fv0_8) << 0x18) == 0) && ((func_8004E6E4(&func_8004DBD8, temp_s5, temp_s4, sp28, 0, temp_fv0_8, 0, 1, 0) << 0x18) == 0)) {
                        sp28[0] = (*(f32 *)((char *)(arg1) + 0)) - (*(f32 *)((char *)(var_s0_2) + 0));
                        sp28[1] = (*(f32 *)((char *)(arg1) + 4)) - (*(f32 *)((char *)(var_s0_2) + 4));
                        sp28[2] = (*(f32 *)((char *)(arg1) + 8)) - (*(f32 *)((char *)(var_s0_2) + 8));
                        temp_fv0_9 = func_80045764(sp28, sp28);
                        if (((func_8004F430(temp_s5, var_s0_2, sp28, (int)temp_fv0_9) << 0x18) == 0) && ((func_8004E6E4(&func_8004DBD8, temp_s5, var_s0_2, sp28, 0, temp_fv0_9, 0, 1, 0) << 0x18) == 0)) {
                            temp_fs0 = func_800461D4(temp_s4, var_s0_2);
                            temp_fs0_2 = temp_fs0 + func_800461D4(arg1, var_s0_2);
                            if (temp_fs0_2 < var_fs2) {
                                var_s6 = var_s1_2;
                                var_fs2 = temp_fs0_2;
                            }
                        } else {
                            temp_fv0_10 = func_800461D4(arg1, var_s0_2);
                            if (temp_fv0_10 < var_fs1) {
                                var_s7 = var_s1_2;
                                var_fs1 = temp_fv0_10;
                            }
                        }
                    }
                    var_s1_2 += 1;
                    var_s0_2 += 0xC;
                }
if (var_s1_2 < 8) goto __repair_rows;
                if (var_s6 != -1) {
                    temp_a1 = var_s6 * 0xC;
                    temp_v0 = temp_a1 + sp28;
                    temp_a2 = (*(s32 *)((char *)(temp_v0) + 0x78));
                    (*(s32 *)((char *)(temp_fp) + 0x18)) = (s32) (*(s32 *)((char *)(temp_v0) + 0x70));
                    (*(s32 *)((char *)(temp_fp) + 0x1C)) = (s32) (*(s32 *)((char *)(temp_v0) + 0x74));
                    (*(s32 *)((char *)(temp_fp) + 0x20)) = temp_a2;
                    temp_fv0_11 = func_800461D4(arg0 + 0x24, sp98 + temp_a1, temp_a2);
                    var_a1 = arg2;
                    (*(f32 *)((char *)(temp_fp) + 0x38)) = temp_fv0_11;
                    (*(f32 *)((char *)(temp_fp) + 0x34)) = temp_fv0_11;
                    goto block_25;
                }
                if (var_s7 != var_s6) {
                    temp_a1_2 = var_s7 * 0xC;
                    temp_v0_2 = temp_a1_2 + sp28;
                    temp_a2_2 = (*(s32 *)((char *)(temp_v0_2) + 0x78));
                    (*(s32 *)((char *)(temp_fp) + 0x18)) = (s32) (*(s32 *)((char *)(temp_v0_2) + 0x70));
                    (*(s32 *)((char *)(temp_fp) + 0x1C)) = (s32) (*(s32 *)((char *)(temp_v0_2) + 0x74));
                    (*(s32 *)((char *)(temp_fp) + 0x20)) = temp_a2_2;
                    temp_fv0_12 = func_800461D4(arg0 + 0x24, sp98 + temp_a1_2, temp_a2_2);
                    var_a1 = __repair_store_2;
                    (*(f32 *)((char *)(temp_fp) + 0x38)) = temp_fv0_12;
                    (*(f32 *)((char *)(temp_fp) + 0x34)) = temp_fv0_12;
                    goto block_25;
                }
                var_v0 = 0;
                if (arg3) {
                    temp_a2_3 = (*(void **)((char *)(temp_fp) + 0x40));
                    var_v0 = 1;
                    if (temp_a2_3 != NULL) {
                        temp_s5 = (s32) (*(s32 *)((char *)(temp_a2_3) + 0x24));
                        __repair_store_1 = (s32) (*(s32 *)((char *)(temp_a2_3) + 0x28));
                        __repair_store_2 = (s32) (*(s32 *)((char *)(temp_a2_3) + 0x2C));
                        (*(s32 *)((char *)(temp_fp) + 0x18)) = temp_s5;
                        (*(s32 *)((char *)(temp_fp) + 0x1C)) = __repair_store_1;
                        (*(s32 *)((char *)(temp_fp) + 0x20)) = __repair_store_2;
                        if ((func_80077E00(arg0, var_s7 * 2, temp_a2_3) << 0x18) != 0) {
                            func_80002BD0(arg0, 0x14D);
                            goto block_24;
                        }
                        goto block_26;
                    }
                }
                /* Duplicate return node #28. Try simplifying control flow for better match */
                return var_v0;
            }
block_24:
            var_a1 = arg3;
block_25:
            func_80077960(arg0, var_a1);
block_26:
            return 1;
        }
        var_v0 = 0;
        /* Duplicate return node #28. Try simplifying control flow for better match */
        return var_v0;
    }
    return var_v0;
}
