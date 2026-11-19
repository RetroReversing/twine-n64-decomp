/* machine draft (m2c) for gcc-2.7.2-kmc -G0 -mips3 -mgp32 -mfp32 -O2, tried by autopilot */

f32 func_80045E34(void *, void *);                  /* extern */
s32 func_80078114(void *, void *, void **, f32 *);  /* extern */
extern u16 D_800B35B0;
extern u16 D_80108F72;
extern void *D_8010A500;
extern f32 D_80117408;

void *func_8007847C(void *arg0) {
    void *sp10;
    f32 sp14;
    s32 temp_s6;
    s32 var_s3;
    s32 var_v0_2;
    s32 var_v0_3;
    s32 var_v1_3;
    u16 temp_t0;
    u8 temp_v1;
    void *temp_a0;
    void *temp_a0_2;
    void *temp_a0_3;
    void *temp_a1;
    void *temp_s0;
    void *temp_s5;
    void *temp_v1_2;
    void *temp_v1_3;
    void *var_s0;
    void *var_s2;
    void *var_s4;
    void *var_v0;
    void *var_v1;
    void *var_v1_2;

    temp_s5 = (*(void **)((char *)(arg0) + 0x6C));
    sp10 = NULL;
    temp_v1 = (*(u8 *)((char *)(temp_s5) + 0x82));
    temp_s6 = (*(s32 *)((char *)(arg0) + 0x60));
    if (temp_v1 == 0x1E) {
        if ((D_80117408 <= (f32) (*(s16 *)((char *)(temp_s5) + 0x74))) && (var_v1 = (*(void **)((char *)((*(void **)((char *)(arg0) + 0x20))) + 0)), (var_v1 != NULL))) {
loop_4:
            if (((*(u16 *)((char *)(var_v1) + 0x78)) != 1) || (var_v0 = var_v1, (((*(s32 *)((char *)((*(void **)((char *)(var_v1) + 0x6C))) + 0x88)) & 0x01E00000) != 0x600000))) {
                var_v1 = (*(void **)((char *)(var_v1) + 0));
                if (var_v1 != NULL) {
                    goto loop_4;
                }
                goto block_49;
            }
        } else {
            goto block_49;
        }
        /* Duplicate return node #50. Try simplifying control flow for better match */
        return var_v0;
    }
    if (temp_v1 == 0x1F) {
        var_v1_2 = (*(void **)((char *)((*(void **)((char *)(arg0) + 0x20))) + 0));
        if (var_v1_2 != NULL) {
loop_11:
            if (((*(u16 *)((char *)(var_v1_2) + 0x78)) != 1) || (var_v0 = var_v1_2, (((*(s32 *)((char *)((*(void **)((char *)(var_v1_2) + 0x6C))) + 0x88)) & 0x01E00000) != 0x800000))) {
                var_v1_2 = (*(void **)((char *)(var_v1_2) + 0));
                if (var_v1_2 == NULL) {
                    return NULL;
                }
                goto loop_11;
            }
            /* Duplicate return node #50. Try simplifying control flow for better match */
            return var_v0;
        }
        goto block_48;
    }
    if (((*(s32 *)((char *)((unsigned short)temp_s5) + 0x88)) & 0x01E00000) == 0x200000) {
        sp14 = func_80045E34(arg0 + 0x24, D_8010A500 + 0x24);
        sp10 = D_8010A500;
    } else {
        sp10 = NULL;
        sp14 = 65536.0f;
    }
    temp_t0 = D_800B35B0 + 1;
    D_800B35B0 = temp_t0;
    var_s3 = 0;
    if (D_80108F72 != 0) {
        temp_s0 = (*(void **)((char *)(arg0) + 0x20));
        (*(s32 *)((char *)(arg0) + 0x60)) = (s32) ((*(s32 *)((char *)(arg0) + 0x60)) & 0xFFFE8FFF);
        (*(u16 *)((char *)((*(void **)((char *)(temp_s0) + 0x20))) + 0x60)) = temp_t0;
        if ((func_80078114(temp_s0, arg0, &sp10, &sp14) << 0x18) != 0) {
            var_s3 = 1;
            (*(s32 *)((char *)(arg0) + 0x60)) = (s32) ((*(s32 *)((char *)(arg0) + 0x60)) | 0x1000);
        }
        var_s4 = (*(void **)((char *)((*(void **)((char *)(temp_s0) + 0x20))) + 0x58));
        var_v1_3 = var_s3 ^ 1;
loop_41:
        if ((var_s4 != NULL) & var_v1_3) {
            if ((*(u16 *)((char *)(var_s4) + 0x26)) & 0x2000) {
                temp_a0 = (*(void **)((char *)(var_s4) + 8));
                temp_v1_2 = (*(void **)((char *)(temp_a0) + 0x20));
                var_s2 = (*(void **)((char *)(temp_v1_2) + 0x58));
                if ((*(u16 *)((char *)(temp_v1_2) + 0x60)) != D_800B35B0) {
                    (*(u16 *)((char *)(temp_v1_2) + 0x60)) = (u16) D_800B35B0;
                    var_v0_2 = var_s2 != NULL;
                    if ((func_80078114(temp_a0, arg0, &sp10, &sp14) << 0x18) != 0) {
                        var_s3 = 1;
                        (*(s32 *)((char *)(arg0) + 0x60)) = (s32) ((*(s32 *)((char *)(arg0) + 0x60)) | 0x2000);
                        var_v0_2 = var_s2 != NULL;
                    }
                    if (var_v0_2 & (var_s3 ^ 1)) {
                        do { {
                            if ((*(u16 *)((char *)(var_s2) + 0x26)) & 0x2000) {
                                temp_a0_2 = (*(void **)((char *)(var_s2) + 8));
                                temp_v1_3 = (*(void **)((char *)(temp_a0_2) + 0x20));
                                var_s0 = (*(void **)((char *)(temp_v1_3) + 0x58));
                                if ((*(u16 *)((char *)(temp_v1_3) + 0x60)) != D_800B35B0) {
                                    (*(u16 *)((char *)(temp_v1_3) + 0x60)) = (u16) D_800B35B0;
                                    var_v0_3 = var_s0 != NULL;
                                    if ((func_80078114(temp_a0_2, arg0, &sp10, &sp14) << 0x18) != 0) {
                                        var_s3 = 1;
                                        (*(s32 *)((char *)(arg0) + 0x60)) = (s32) ((*(s32 *)((char *)(arg0) + 0x60)) | 0x4000);
                                        var_v0_3 = var_s0 != NULL;
                                    }
                                    if (var_v0_3 & (var_s3 ^ 1)) {
                                        do {
                                            if ((*(u16 *)((char *)(var_s0) + 0x26)) & 0x2000) {
                                                temp_a0_3 = (*(void **)((char *)(var_s0) + 8));
                                                temp_a1 = (*(void **)((char *)(temp_a0_3) + 0x20));
                                                if ((*(u16 *)((char *)(temp_a1) + 0x60)) != D_800B35B0) {
                                                    (*(u16 *)((char *)(temp_a1) + 0x60)) = (u16) D_800B35B0;
                                                    if ((func_80078114(temp_a0_3, arg0, &sp10, &sp14) << 0x18) != 0) {
                                                        var_s3 = 1;
                                                        (*(s32 *)((char *)(arg0) + 0x60)) = (s32) ((*(s32 *)((char *)(arg0) + 0x60)) | 0x8000);
                                                    }
                                                }
                                            }
                                            var_s0 = (*(void **)((char *)(var_s0) + 0));
                                        } while ((var_s0 != NULL) & (var_s3 ^ 1));
                                    }
                                }
                            }
                            var_s2 = (*(void **)((char *)(var_s2) + 0));
                        }
} while ((var_s2 != NULL) & (var_s3 ^ 1));
                    }
                }
            }
            var_s4 = (*(void **)((char *)(var_s4) + 0));
            var_v1_3 = var_s3 ^ 1;
            goto loop_41;
        }
        if (sp10 != NULL) {
            if (sp10 != D_8010A500) {
                (*(s32 *)((char *)(temp_s5) + 0x88)) = (s32) ((*(s32 *)((char *)(temp_s5) + 0x88)) | 0x40000000);
            } else {
                (*(s32 *)((char *)(arg0) + 0x60)) = temp_s6;
            }
            return sp10;
        }
        goto block_47;
    }
block_47:
    if (((*(s32 *)((char *)(temp_s5) + 0x88)) & 0x01E00000) == 0x400000) {
block_48:
        return NULL;
    }
block_49:
    var_v0 = D_8010A500;
    return var_v0;
}
