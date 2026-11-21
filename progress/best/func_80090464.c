/* machine draft (m2c) for gcc-2.7.2-kmc -G0 -mips3 -mgp32 -mfp32 -O2, tried by autopilot */

s32 reset_timed_sequence();
s32 func_80095A80();
extern u8 D_800EDA87;
extern void *gSeqPlayer;

s32 func_80090464(void) {
int __repair_literal;

    
    int temp_v1_2;
    s32 var_s2;
    s32 var_s4;
    s32 var_s5;
    long var_s6;
    s32 var_s1;
    u16 temp_a1;
    u16 temp_a2_2;
    union { u32 * pointer; s32 value; } __repair_phase_storage;
    u32 temp_a2_3;
    u8 temp_a1_3;
    u8 temp_a3_2;
    u8 temp_v0_3;
    u8 temp_v0_5;
    u8 temp_v1_4;
    void *temp_a0_2;
    
    
    void *temp_a1_2;
    
    void *temp_a2;
    void *temp_a3;
    void *temp_t0;
    void *temp_v0;
    void *temp_v0_2;
    void *temp_v0_4;
    void *temp_v0_6;
    void *temp_v0_7;
    void *temp_v1_3;
    void *temp_v1_5;
    void *var_a0;

    var_s4 = 1;
    var_s6 = 0;
    var_s1 = 0;
    var_s2 = 0;
    var_s5 = 0;
    do {
        temp_t0 = gSeqPlayer;
        temp_v0 = temp_t0 + var_s2;
        __repair_phase_storage.pointer = (*(u32 **)((char *)(temp_v0) + 0x12C));
        if (__repair_phase_storage.pointer != NULL) {
            var_s6 = 1;
            if ((u32) ((*(s32 *)((char *)(temp_v0) + 0x134)) + (*(s32 *)((char *)(temp_t0) + 0x120))) >= (u32) *__repair_phase_storage.pointer) {
                var_a0 = temp_t0 + var_s2;
                for (;;) {
                    temp_a3 = (*(void **)((char *)(var_a0) + 0x12C));
                                    temp_a1 = (*(u16 *)((char *)(temp_a3) + 8));
                                    if (temp_a1 != 0xFFFE) {
                                        if (temp_a1 == 0xFFFF) {
                                            (*(void **)((char *)(var_a0) + 0x12C)) = NULL;
                                        } else {
                                            temp_a0_2 = (*(void **)((char *)(temp_t0) + 0x10C));
                                            temp_a1_2 = temp_t0 + var_s5;
                                            (*(s32 *)((char *)(temp_a1_2) + 0x56C)) = 0;
                                            (*(s32 *)((char *)(temp_a1_2) + 0x568)) = 0;
                    temp_v1_2 = 4;

                                            temp_a2 = *(s32 *)((temp_a1 * temp_v1_2) + ((*(s32 *)((char *)(temp_a0_2) + 4)) + temp_a0_2)) + temp_a0_2;
                                            (*(s32 *)((char *)(temp_a1_2) + 0x570)) = 0;
                                            (*(void **)((char *)(temp_a1_2) + 0x574)) = (void *) (temp_a2 + 0xC);
                                            __repair_phase_storage.value = (*(s32 *)((char *)(temp_a2) + 4));
                                            if (__repair_phase_storage.value != 0) {
                                                (*(void **)((char *)(temp_a1_2) + 0x578)) = (void *) (__repair_phase_storage.value + (*(void **)((char *)(temp_t0) + 0x10C)));
                                            } else {
                                                (*(void **)((char *)(temp_a1_2) + 0x578)) = NULL;
                                            }
                                            temp_a0_2 = gSeqPlayer + var_s5;
                                            (*(s32 *)((char *)(temp_a0_2) + 0x584)) = 0;
                                            (*(s16 *)((char *)(temp_a0_2) + 0x580)) = 0x2000;
                                            temp_v1_2 = (*(s32 *)((char *)(temp_a2) + 8));
                                            if (temp_v1_2) {
                                                (*(s32 *)((char *)(temp_a0_2) + 0x57C)) = (s32) (temp_v1_2 + (*(void **)((char *)(gSeqPlayer) + 0x10C)));
                                            } else {
                                                (*(s32 *)((char *)(temp_a0_2) + 0x57C)) = 0;
                                            }
                                            temp_a0_2 = gSeqPlayer + var_s5;
                                            (*(s32 *)((char *)(temp_a0_2) + 0x588)) = 0;
                                            (*(s16 *)((char *)(temp_a0_2) + 0x582)) = 0;
                                            temp_v1_3 = (*(void **)((char *)(gSeqPlayer) + 0x10C));
                                            (*(u8 *)((char *)(temp_a0_2) + 0x58C)) = (u8) *(u8 *)((*(s32 *)((char *)(temp_v1_3) + 8)) + temp_v1_3 + var_s1);
                                            (*(u8 *)((char *)((gSeqPlayer + var_s5)) + 0x58D)) = (u8) (*(u8 *)((char *)(temp_a3) + 0xB));
                                            (*(u8 *)((char *)((gSeqPlayer + var_s5)) + 0x58E)) = (u8) (*(u8 *)((char *)(temp_a3) + 0xA));
                                            (*(s8 *)((char *)((gSeqPlayer + var_s5)) + 0x58F)) = var_s1;
                                            temp_v1_4 = (*(u8 *)((char *)(temp_a3) + 4));
                                            if (temp_v1_4 != 0xFF) {
                                                temp_a1_3 = (*(u8 *)((char *)((gSeqPlayer + var_s5)) + 0x58C));
                                                temp_v0_2 = gSeqPlayer + temp_v1_4;
                                                if (temp_a1_3 != 9) {
                                                    temp_v0_3 = (*(u8 *)((char *)(temp_v0_2) + 8));
                                                    if (temp_v0_3 != 0xFF) {
                                                        temp_v0_4 = (temp_v0_3 * 8) + (*(s32 *)((char *)(gSeqPlayer) + 4));
                                                        (*(s32 *)((char *)(((temp_a1_3 * 4) + gSeqPlayer)) + 0xF80)) = (s32) (((*(u16 *)((char *)(temp_v0_4) + 0)) << 0x10) | ((*(u8 *)((char *)(temp_v0_4) + 2)) << 8) | (*(u8 *)((char *)(temp_v0_4) + 3)));
                                                    }
                                                } else {
                                                    temp_v0_5 = (*(u8 *)((char *)(temp_v0_2) + 0x8C));
                                                    if (temp_v0_5 != 0xFF) {
                                                        temp_v0_6 = (temp_v0_5 * 8) + (*(s32 *)((char *)(gSeqPlayer) + 0x88));
                                                        (*(s32 *)((char *)(gSeqPlayer) + 0xFA4)) = (s32) (((*(u16 *)((char *)(temp_v0_6) + 0)) << 0x10) | ((*(u8 *)((char *)(temp_v0_6) + 2)) << 8) | (*(u8 *)((char *)(temp_v0_6) + 3)));
                                                    }
                                                }
                                            }
                                            temp_a3_2 = (*(u8 *)((char *)(temp_a3) + 5));
                                            if (temp_a3_2 != 0xFF) {
                                                func_80095A80(7, (*(u8 *)((char *)((gSeqPlayer + var_s5)) + 0x58C)), D_800EDA87, temp_a3_2);
                                            }
                                            temp_v1_5 = gSeqPlayer + var_s2;
                                            (*(s32 *)((char *)(temp_v1_5) + 0x12C)) += 0xC;
                                            goto block_29;
                                        }
                                    } else if ((*(u8 *)((char *)(temp_t0) + 0xFC5)) != 0) {
                                        (*(void **)((char *)(var_a0) + 0x12C)) = NULL;
                                    } else {
                                        temp_v1_2 = (u16)((u16) (*(u8 *)((char *)(temp_a3) + 0xA)));
                                        (*(void **)((char *)(var_a0) + 0x12C)) = (void *) ((*(s32 *)((char *)(var_a0) + 0x128)) + (temp_v1_2 * 0xC));
                                        (*(s32 *)((char *)(var_a0) + 0x130)) = 0;
                                        (*(s32 *)((char *)(var_a0) + 0x134)) = (s32) (*(s32 *)((char *)((*(void **)((char *)(temp_t0) + 0x10C))) + 0x14));
                                        if (var_s4 & 0xFF) {
                                            var_s4 = 0;
                                            reset_timed_sequence((*(s32 *)((char *)((*(void **)((char *)(temp_t0) + 0x10C))) + 0x14)), temp_a1, temp_v1_2);
                                            (*(u16 *)((char *)(gSeqPlayer) + 0xFC6)) += 1;
                                        }
block_29:
                                        temp_v0_7 = gSeqPlayer + (var_s1 * 0x10);
                                        var_a0 = gSeqPlayer + var_s2;
                                        if ((u32) ((*(s32 *)((char *)(temp_v0_7) + 0x134)) + (*(s32 *)((char *)(gSeqPlayer) + 0x120))) < (u32) *(*(u32 **)((char *)(temp_v0_7) + 0x12C))) {
                                            goto block_30;
                                        }
                                        continue;
                                    }
                    break;
                }
            } else {
block_30:
                temp_a0_2 = gSeqPlayer + var_s2;
                temp_a2_3 = (*(s32 *)((char *)(temp_a0_2) + 0x130)) + (*(s32 *)((char *)(gSeqPlayer) + 0x118));
                (*(s32 *)((char *)(temp_a0_2) + 0x130)) = (s32) (temp_a2_3 & 0xFFFF);
                (*(s32 *)((char *)(temp_a0_2) + 0x134)) += ((temp_a2_3 >> 0x10) + (*(s32 *)((char *)(gSeqPlayer) + 0x11C)));
            }
        }
        var_s2 += 0x10;
        ++var_s1;
        var_s5 += 0x28;
    } while (var_s1 < 0x40);
    return var_s6;
}
