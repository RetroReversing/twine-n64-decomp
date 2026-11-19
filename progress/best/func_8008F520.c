/* machine draft (m2c) for gcc-2.7.2-kmc -G0 -mips3 -mgp32 -mfp32 -O2, tried by autopilot */

s32 func_8008CDC0();
s32 func_8008EB80();
s32 func_8008F2A4();
s32 func_80095A80();
s32 func_80095EC4();
extern char D_800E5AC4[];
extern char D_800E6A85[];
extern s32 D_800EDA90;
extern char D_80102FDC[];

s32 func_8008F520(void *arg0, void *arg1, void *arg2, void *arg3, void *arg4) {
    char *var_a1_3;
    s32 temp_a0;
    
    s32 temp_a1_2;
    s32 temp_a1_3;
    s32 temp_s0;
    s32 temp_s4;
    s32 temp_v0_2;
    s32 temp_v0_4;
    s32 var_a0;
    s32 var_a0_2;
    unsigned long var_a0_4;
    s32 var_a0_7;
    s32 var_a3;
    s32 var_s1;
    s32 var_s1_2;
    s32 var_s1_3;
    s32 var_s1_4;
    s32 var_s1_5;
    s32 var_s1_6;
    s32 var_s1_7;
    s32 var_v0;
    s32 var_v0_2;
    s32 var_v1;
    s32 var_v1_4;
    s8 var_a0_3;
    s8 var_a0_5;
    u32 var_a2_4;
    u32 var_s5;
    char *var_a2_3;
    u8 *var_v1_3;
    u8 temp_a0_3;
    u8 temp_a0_4;
    u8 temp_a3_3;
    u8 temp_v0_6;
    register u8 temp_v1_2;
    u8 temp_v1_4;
    u8 var_a1;
    u8 var_a1_2;
    void *temp_a1;
    union { void * pointer; s32 value; } __repair_phase_storage;
    void *temp_a3_2;
    void *temp_s2;
    void *temp_t0;
    void *temp_v0;
    void *temp_v0_3;
    void *temp_v0_5;
    void *temp_v1;
    void *temp_v1_3;
    void *temp_v1_5;
    void *var_a0_6;
    void *var_a2;
    void *var_a2_2;
    void *var_s3;
    void *var_t1;
    void *var_v0_3;
    void *var_v1_2;

    var_s3 = arg2;
    var_s5 = 0;
    var_v1 = 0;
loop_1:
    if (*(D_800E6A85 + var_v1) == 0) {
        var_s5 += 1;
        var_v1 += 0xFF8;
        if (var_s5 >= 8U) {

        } else {
            goto loop_1;
        }
    }
    if (var_s5 != 8) {
        temp_s2 = (var_s5 * 0xFF8) + D_800E5AC4;
        __repair_phase_storage.pointer = temp_s2 + 8;
        (*(void **)((char *)(temp_s2) + 4)) = arg0;
        var_a2 = (*(void **)((char *)(temp_s2) + 4));
        var_a0_2 = 0;
        (*(s8 *)((char *)(temp_s2) + 0xFF4)) = 0;
        (*(void **)((char *)(temp_s2) + 0x88)) = arg1;
        (*(void **)((char *)(temp_s2) + 0x10C)) = arg3;
        var_v0 = 0 & 0xFF;
        do {
            *(s32 *)(__repair_phase_storage.pointer + var_v0) = 0xFF;
            var_a0_2 += 1;
            var_v0 = var_a0_2 & 0xFF;
        } while ((u32) (var_a0_2 & 0xFF) < 0x80U);
        var_a1 = (*(u8 *)((char *)(var_a2) + 5));
        var_a0_3 = 0;
        if ((var_a1 & 0xFF) != 0xFF) {
            do {
                var_a2 += 8;
                *(s8 *)(var_a1 + __repair_phase_storage.pointer) = var_a0_3;
                var_a1 = (*(u8 *)((char *)(var_a2) + 5));
                var_a0_3 += 1;
            } while (var_a1 != 0xFF);
        }
        temp_a3_2 = temp_s2 + 0x8C;
        var_a2_2 = (*(void **)((char *)(temp_s2) + 0x88));
        var_a0_4 = 0;
        var_v0_2 = 0 & 0xFF;
        do {
            *(s32 *)(temp_a3_2 + var_v0_2) = 0xFF;
            var_a0_4 += 1;
            var_v0_2 = var_a0_4 & 0xFF;
        } while ((u32) (var_a0_4 & 0xFF) < 0x80U);
        var_a1_2 = (*(u8 *)((char *)(var_a2_2) + 5));
        var_a0_5 = 0;
        if ((var_a1_2 & 0xFF) != 0xFF) {
            do {
                var_a2_2 += 8;
                *(s8 *)(var_a1_2 + temp_a3_2) = var_a0_5;
                var_a1_2 = (*(u8 *)((char *)(var_a2_2) + 5));
                var_a0_5 += 1;
            } while (var_a1_2 != 0xFF);
        }
        (*(u8 *)((char *)(temp_s2) + 0xFC4)) = (u8) (var_s5 + 0x17);
        var_s1 = 0;
        do {
            temp_v0 = temp_s2 + var_s1;
            var_s1 += 1;
            (*(u8 *)((char *)(temp_v0) + 0x528)) = (u8) (*(u8 *)((char *)(temp_s2) + 0xFC4));
        } while (var_s1 < 0x40);
        if (arg4 == NULL) {
            (*(s32 *)((char *)(temp_s2) + 0x110)) = -1;
            (*(s32 *)((char *)(temp_s2) + 0x114)) = -1;
            (*(u16 *)((char *)(temp_s2) + 0xFC2)) = 0x100U;
        } else {
            if ((*(s32 *)((char *)(arg4) + 0)) & 1) {
                (*(s32 *)((char *)(temp_s2) + 0x110)) = (s32) (*(s32 *)((char *)(arg4) + 4));
                (*(s32 *)((char *)(temp_s2) + 0x114)) = (s32) (*(s32 *)((char *)(arg4) + 8));
            } else {
                (*(s32 *)((char *)(temp_s2) + 0x110)) = -1;
                (*(s32 *)((char *)(temp_s2) + 0x114)) = -1;
            }
            if ((*(s32 *)((char *)(arg4) + 0)) & 2) {
                (*(u16 *)((char *)(temp_s2) + 0xFC2)) = (u16) (*(u16 *)((char *)(arg4) + 0xC));
            } else {
                (*(u16 *)((char *)(temp_s2) + 0xFC2)) = 0x100U;
            }
            if ((*(s32 *)((char *)(arg4) + 0)) & 8) {
                var_s1_2 = 0;
                if ((s32) (*(u8 *)((char *)(arg4) + 0x12)) > 0) {
                    do {
                        temp_a0 = var_s1_2 * 2;
                        temp_v1 = temp_a0 + (*(s32 *)((char *)(arg4) + 0x14));
                        (*(u8 *)((char *)((temp_s2 + (*(u8 *)((char *)(temp_v1) + 0)))) + 0x528)) = (u8) (*(u8 *)((char *)(temp_v1) + 1));
                        func_8008F2A4((*(u8 *)((char *)((temp_a0 + (*(s32 *)((char *)(arg4) + 0x14)))) + 1)), 0);
                        var_s1_2 += 1;
                    } while (var_s1_2 < (s32) (*(u8 *)((char *)(arg4) + 0x12)));
                }
            }
            if ((*(s32 *)((char *)(arg4) + 0)) & 4) {
                func_8008EB80((*(u8 *)((char *)(arg4) + 0x10)), (*(u16 *)((char *)(arg4) + 0xE)), (*(u8 *)((char *)(temp_s2) + 0xFC4)), 0, 0);
                var_s1_3 = 0;
                if ((s32) (*(u8 *)((char *)(arg4) + 0x18)) > 0) {
                    do {
                        func_8008EB80((*(u8 *)((char *)(arg4) + 0x10)), (*(u16 *)((char *)(arg4) + 0xE)), *(s32 *)((*(s32 *)((char *)(arg4) + 0x1C)) + var_s1_3), 0, 0);
                        var_s1_3 += 1;
                    } while (var_s1_3 < (s32) (*(u8 *)((char *)(arg4) + 0x18)));
                }
            }
        }
        __repair_phase_storage.value = (*(s32 *)((char *)(arg3) + 0x10));
        (*(s32 *)((char *)(temp_s2) + 0x124)) = __repair_phase_storage.value;
        func_8008CDC0(__repair_phase_storage.value, var_s5 & 0xFF);
        temp_v0_2 = (*(s32 *)((char *)(arg3) + 0xC));
        temp_v0_3 = temp_v0_2 + arg3;
        if (temp_v0_2 != 0) {
            (*(void **)((char *)(temp_s2) + 0xF68)) = temp_v0_3;
            (*(void **)((char *)(temp_s2) + 0xF6C)) = temp_v0_3;
            (*(s32 *)((char *)(temp_s2) + 0xF70)) = 0;
            (*(s32 *)((char *)(temp_s2) + 0xF74)) = 0;
        } else {
            (*(void **)((char *)(temp_s2) + 0xF68)) = NULL;
        }
        var_s1_4 = 0;
        (*(s8 *)((char *)(temp_s2) + 0xFC5)) = 0;
        var_a0_6 = temp_s2;
        var_v1_2 = temp_s2;
        var_a1_3 = (*(s32 *)((char *)(arg3) + 0)) + arg3;
        do {
            *(D_80102FDC + var_s1_4) = 0x7F;
            (*(s32 *)((char *)(var_v1_2) + 0x130)) = 0;
            (*(s32 *)((char *)(var_v1_2) + 0x134)) = 0;
            (*(s32 *)((char *)(var_a0_6) + 0x574)) = 0;
            (*(s32 *)((char *)(var_a0_6) + 0x578)) = 0;
            (*(s32 *)((char *)(var_a0_6) + 0x57C)) = 0;
            temp_v0_4 = *(s32 *)var_a1_3;
            temp_v0_5 = temp_v0_4 + arg3;
            if (temp_v0_4 != 0) {
                (*(void **)((char *)(var_v1_2) + 0x128)) = temp_v0_5;
                (*(void **)((char *)(var_v1_2) + 0x12C)) = temp_v0_5;
            } else {
                (*(void **)((char *)(var_v1_2) + 0x128)) = NULL;
                (*(void **)((char *)(var_v1_2) + 0x12C)) = NULL;
            }
            var_a1_3 += 4;
            var_a0_6 += 0x28;
            var_s1_4 += 1;
            var_v1_2 += 0x10;
        } while (var_s1_4 < 0x40);
        var_s1_5 = 0;
        (*(s32 *)((char *)(temp_s2) + 0xF78)) = 0;
        (*(s32 *)((char *)(temp_s2) + 0xF7C)) = 0;
        var_a0_7 = 0 & 0xFF;
        do {
            func_80095EC4(var_a0_7, var_s5 & 0xFF);
            var_s1_5 += 1;
            var_a0_7 = var_s1_5 & 0xFF;
        } while (var_s1_5 < 0x10);
        var_s1_6 = 0xF;
        var_v0_3 = temp_s2 + 0x3C;
        do {
            (*(s32 *)((char *)(var_v0_3) + 0xF80)) = -1;
            var_s1_6 -= 1;
            var_v0_3 -= 4;
        } while (0 <= var_s1_6);
        var_t1 = (*(void **)((char *)(temp_s2) + 4));
        var_v1_3 = temp_s2 + 8;
        var_a3 = 0;
        do {
            var_a2_3 = var_v1_3;
            temp_t0 = var_a2_3 + 0x80;
loop_45:
            temp_v0_6 = *(u8 *)var_a2_3;
            if (temp_v0_6 != 0xFF) {
                temp_a1 = (temp_v0_6 * 8) + var_t1;
                temp_a0_3 = (*(u8 *)((char *)(temp_a1) + 4));
                if (temp_a0_3 != 0xFF) {
                    (*(s32 *)((char *)(((temp_a0_3 * 4) + temp_s2)) + 0xF80)) = (s32) (((*(u16 *)((char *)(temp_a1) + 0)) << 0x10) | ((*(u8 *)((char *)(temp_a1) + 2)) << 8) | (*(u8 *)((char *)(temp_a1) + 3)));
                }
            }
            var_a2_3 += 1;
            if ((s32) var_a2_3 < (s32) temp_t0) {
                goto loop_45;
            }
            var_t1 = (*(void **)((char *)(temp_s2) + 0x88));
            var_a3 += 1;
            var_v1_3 = temp_s2 + 0x8C;
        } while (var_a3 < 2);
        if (var_s3 != NULL) {
            var_s1_7 = 0;
            temp_s4 = var_s5 & 0xFF;
            do {
                temp_a0_4 = (*(u8 *)((char *)(var_s3) + 4));
                temp_a1_2 = var_s1_7 & 0xFF;
                if (temp_a1_2 != 9) {
                    temp_v1_2 = (*(u8 *)((char *)((temp_a0_4 + temp_s2)) + 8));
                    if (temp_v1_2 != 0xFF) {
                        temp_v1_3 = (temp_v1_2 * 8) + (*(void **)((char *)(temp_s2) + 4));
                        (*(s32 *)((char *)(((temp_a1_2 * 4) + temp_s2)) + 0xF80)) = (s32) (((*(u16 *)((char *)(temp_v1_3) + 0)) << 0x10) | ((*(u8 *)((char *)(temp_v1_3) + 2)) << 8) | (*(u8 *)((char *)(temp_v1_3) + 3)));
                    }
                } else {
                    temp_v1_4 = (*(u8 *)((char *)((temp_a0_4 + temp_s2)) + 0x8C));
                    if (temp_v1_4 != 0xFF) {
                        temp_v1_5 = (temp_v1_4 * 8) + (*(void **)((char *)(temp_s2) + 0x88));
                        (*(s32 *)((char *)(temp_s2) + 0xFA4)) = (s32) (((*(u16 *)((char *)(temp_v1_5) + 0)) << 0x10) | ((*(u8 *)((char *)(temp_v1_5) + 2)) << 8) | (*(u8 *)((char *)(temp_v1_5) + 3)));
                    }
                }
                temp_s0 = var_s1_7 & 0xFF;
                temp_a1_3 = temp_s0;/*__repair_loop_weight*/do {do {do {
                var_s1_7 += 1;} while (0);} while (0);} while (0);
                func_80095A80(7, temp_a1_3, temp_s4, (*(u8 *)((char *)(var_s3) + 5)));
                func_80095A80(0xA, temp_s0, temp_s4, (*(u8 *)((char *)(var_s3) + 6)));
                func_80095A80(0x5B, temp_s0, temp_s4, (*(u8 *)((char *)(var_s3) + 7)));
                temp_a3_3 = (*(u8 *)((char *)(var_s3) + 8));
                func_80095A80(0x5D, temp_s0, temp_s4, temp_a3_3);
                var_s3 += 8;
            } while (var_s1_7 < 0x10);
        }
        (*(s16 *)((char *)(temp_s2) + 0xFC6)) = 0;
        if ((arg4 == NULL) || !((*(s32 *)((char *)(arg4) + 0)) & 0x10)) {
            (*(s8 *)((char *)(temp_s2) + 0xFC0)) = 1;
        }
        do {
            var_a2_4 = 0;
            var_v1_4 = 0;
            var_a0 = D_800EDA90;
            D_800EDA90 = (var_a0 + 1) & 0x7FFFFFFF;
loop_63:
            if (*(D_800E6A85 + var_v1_4) != 0) {
                var_a2_4 += 1;
                goto block_70;
            }
            if (*(s32 *)(D_800E5AC4 + var_v1_4) == var_a0) {
                var_a0 = -1;
            } else {
                var_a2_4 += 1;
block_70:
                var_v1_4 += 0xFF8;
                if (var_a2_4 < 8U) {
                    goto loop_63;
                }
            }
        } while (var_a0 == -1);
        *(s32 *)(D_800E5AC4 + (var_s5 * 0xFF8)) = var_a0;
        (*(s8 *)((char *)(temp_s2) + 0xFC1)) = 0;
        return var_a0;
    }
    return -1;
}
