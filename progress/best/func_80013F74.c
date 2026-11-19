/* machine draft (m2c) for gcc-2.7.2-kmc -G0 -mips3 -mgp32 -mfp32 -O2, tried by autopilot */

void func_80013F74(void *arg0) {
    
    s32 temp_v1;
s32 __repair_phase_temp_v1;
    s32 temp_v1_2;
    s32 var_a2;
    s32 var_a2_10;
    s32 var_a2_11;
    s32 var_a2_12;
    s32 var_a2_2;
    s32 var_a2_3;
    s32 var_a2_4;
    s32 var_a2_5;
    s32 var_a2_6;
    s32 var_a2_7;
    s32 var_a2_8;
    s32 var_a2_9;
    s32 var_a3;
    s32 var_a3_3;
    s32 var_a3_4;
    s32 var_a3_6;
    s32 var_t2;
    s32 var_t2_2;
    s32 var_t2_3;
    s32 var_t2_4;
    s32 var_t2_5;
    s32 var_t2_6;
    s32 var_t2_7;
    s32 var_t2_8;
    s32 var_v1;
    s32 var_v1_10;
    s32 var_v1_11;
    s32 var_v1_12;
    s32 var_v1_13;
    s32 var_v1_14;
    s32 var_v1_15;
    s32 var_v1_16;
    s32 var_v1_17;
    s32 var_v1_18;
    s32 var_v1_19;
    s32 var_v1_20;
    s32 var_v1_21;
    s32 var_v1_22;
    s32 var_v1_3;
    s32 var_v1_4;
    s32 var_v1_5;
    long var_v1_7;
    s32 var_v1_8;
    s32 var_v1_9;
    char *var_t0;
    u32 temp_a1;
    u32 temp_a1_10;
    u32 temp_a1_11;
    u32 temp_a1_12;
    u32 temp_a1_13;
    u32 temp_a1_14;
    u32 temp_a1_15;
    u32 temp_a1_16;
    u32 temp_a1_17;
    u32 temp_a1_18;
    u32 temp_a1_19;
    u32 temp_a1_20;
    u32 temp_a1_21;
    u32 temp_a1_22;
    u32 temp_a1_23;
    u32 temp_a1_24;
    u32 temp_a1_25;
    u32 temp_a1_26;
    u32 temp_a1_27;
    u32 temp_a1_28;
    u32 temp_a1_2;
    u32 temp_a1_3;
    u32 temp_a1_4;
    u32 temp_a1_5;
    u32 temp_a1_6;
    u32 temp_a1_7;
    u32 temp_a1_8;
    u32 temp_a1_9;
    u32 var_a1;
u32 __repair_result_var_a1;
    u32 var_a1_10;
    u32 var_a1_11;
    u32 var_a1_12;
    u32 var_a1_13;
    u32 var_a1_2;
    u32 var_a1_3;
    u32 var_a1_4;
    u32 var_a1_5;
    u32 var_a1_6;
    u32 var_a1_7;
    u32 var_a1_8;
    u32 var_a1_9;
    u32 var_t1;
u32 __repair_result_var_t1;
    char *var_a0;
    char *var_a3_2;
    char *var_a3_5;
    u8 temp_v0_3;
    u8 temp_v0_4;
    u8 var_v1_2;
    u8 var_v1_6;
    union { void * pointer; s32 value; } __repair_phase_storage;

    __repair_phase_storage.pointer = (*(void **)((char *)(arg0) + 4));
    var_a2 = 0x20;
    var_a0 = (*(u8 **)((char *)(arg0) + 0));
    __repair_result_var_a1 = (*(u32 *)((char *)(__repair_phase_storage.pointer) + 0xC));
    __repair_result_var_t1 = (*(u32 *)((char *)(__repair_phase_storage.pointer) + 0x10));
    var_t0 = __repair_phase_storage.pointer + 0x14;
loop_1:
    var_a2_2 = var_a2 - 1;
loop_2:
    var_v1 = __repair_result_var_a1 & 1;
    if (var_a2_2 < 0) {
        temp_a1 = __repair_result_var_t1;
        var_t1 = *(u32 *)var_t0;
        var_t0 += 4;
        var_v1 = (__repair_result_var_a1 + (temp_a1 << (var_a2_2 + 1))) & 1;
        var_a1_2 = temp_a1 >> -var_a2_2;
        var_a2_2 += 0x20;
    } else {
        var_a1_2 = __repair_result_var_a1 >> 1;
    }
    if (var_v1 == 0) {
        var_a2 = var_a2_2 - 8;
        var_v1_2 = var_a1_2 & 0xFF;
        if (var_a2 < 0) {
            temp_a1_2 = var_t1;/*__repair_loop_weight*/do {do {do {
            var_t1 = *(u32 *)var_t0;} while (0);} while (0);} while (0);
            var_t0 += 4;
            var_v1_2 = (var_a1_2 + (temp_a1_2 << (var_a2 + 8))) & 0xFF;
            var_a1 = temp_a1_2 >> -var_a2;
            var_a2 += 0x20;
        } else {
            var_a1 = var_a1_2 >> 8;
        }
        *(u8 *)var_a0 = var_v1_2;
        var_a0 += 1;
        goto loop_1;
    }
    var_a2_3 = var_a2_2 - 1;
    __repair_phase_storage.value = var_a1_2 & 1;
    if (var_a2_3 < 0) {
        temp_a1_3 = var_t1;
        var_t1 = *(u32 *)var_t0;
        var_t0 += 4;
        var_v1_3 = (var_a1_2 + (temp_a1_3 << (var_a2_3 + 1))) & 1;
        var_a1_3 = temp_a1_3 >> -var_a2_3;
        var_a2_3 += 0x20;
    } else {
        var_a1_3 = var_a1_2 >> 1;
    }
    var_a2_4 = var_a2_3 - 1;
    if (__repair_phase_storage.value == 0) {
        temp_v1 = var_a1_3 & 1;
        if (var_a2_4 < 0) {
            temp_a1_4 = var_t1;
            var_t1 = *(u32 *)var_t0;
            var_t0 += 4;
            var_t2 = (var_a1_3 + (temp_a1_4 << (var_a2_4 + 1))) & 1;
            var_a1_4 = temp_a1_4 >> -var_a2_4;
            var_a2_4 += 0x20;
        } else {
            var_a1_4 = var_a1_3 >> 1;
        }
        var_a2_5 = var_a2_4 - 1;
        var_t2_2 = temp_v1 + 4;
        if (var_a2_5 < 0) {
            temp_a1_5 = var_t1;
            var_t1 = *(u32 *)var_t0;
            var_t0 += 4;
            var_v1_4 = (var_a1_4 + (temp_a1_5 << (var_a2_5 + 1))) & 1;
            var_a1_5 = temp_a1_5 >> -var_a2_5;
            var_a2_5 += 0x20;
        } else {
            var_v1_4 = var_a1_4 & 1;
            var_a1_5 = var_a1_4 >> 1;
        }
        if (var_v1_4 != 0) {
            var_a2_5 -= 1;
            var_v1_5 = var_a1_5 & 1;
            if (0 > var_a2_5) {
                temp_a1_6 = var_t1;
                var_t1 = *(u32 *)var_t0;
                var_t0 += 4;
                var_v1_5 = (var_a1_5 + (temp_a1_6 << (var_a2_5 + 1))) & 1;
                var_a1_5 = temp_a1_6 >> -var_a2_5;
                var_a2_5 += 0x20;
            } else {
                var_a1_5 = var_a1_5 >> 1;
            }
            var_t2_2 = ((var_t2_2 - 1) * 2) + var_v1_5;
        }
        if (var_t2_2 == 9) {
            var_a2 = var_a2_5 - 4;
            var_t2_3 = var_a1_5 & 0xF;
            if (var_a2 < 0) {
                temp_a1_7 = var_t1;
                var_t1 = *(u32 *)var_t0;
                var_t2_3 = (var_a1_5 + (temp_a1_7 << (var_a2 + 4))) & 0xF;
                var_t0 += 4;
                var_a1 = temp_a1_7 >> -var_a2;
                var_a2 += 0x20;
            } else {
                var_a1 = var_a1_5 >> 4;
            }
            __repair_phase_storage.value = var_t2_3 * 4;
            var_t2_4 = __repair_phase_storage.value + 0xB;
            if ((__repair_phase_storage.value + 0xC) != 0) {
                do {
                    var_a2 -= 8;
                    var_v1_6 = var_a1 & 0xFF;
                    if (var_a2 < 0) {
                        temp_a1_8 = var_t1;
                        var_t1 = *(u32 *)var_t0;
                        var_t0 += 4;
                        var_v1_6 = (var_a1 + (temp_a1_8 << (var_a2 + 8))) & 0xFF;
                        var_a1 = temp_a1_8 >> -var_a2;
                        var_a2 += 0x20;
                    } else {
                        var_a1 = var_a1 >> 8;
                    }
                    *(u8 *)var_a0 = var_v1_6;
                    var_a0 += 1;
                    var_t2_4 -= 1;
                } while (var_t2_4);
                var_a2_2 = var_a2 - 1;
            } else {
                goto loop_1;
            }
        } else {
            var_a2_6 = var_a2_5 - 1;
            var_a3 = 0;
            if (var_a2_6 < 0) {
                temp_a1_9 = var_t1;
                var_t1 = *(u32 *)var_t0;
                var_t0 += 4;
                var_v1_7 = (var_a1_5 + (temp_a1_9 << (var_a2_6 + 1))) & 1;
                var_a1_6 = temp_a1_9 >> -var_a2_6;
                var_a2_6 += 0x20;
            } else {
                var_v1_7 = var_a1_5 & 1;
                var_a1_6 = var_a1_5 >> 1;
            }
            if (var_v1_7 != 0) {
                var_a2_7 = var_a2_6 - 1;
                var_a3 = var_a1_6 & 1;
                if (var_a2_7 < 0) {
                    temp_a1_10 = var_t1;
                    var_t1 = *(u32 *)var_t0;
                    var_t0 += 4;
                    var_a3 = (var_a1_6 + (temp_a1_10 << (var_a2_7 + 1))) & 1;
                    var_a1_7 = temp_a1_10 >> -var_a2_7;
                    var_a2_7 += 0x20;
                } else {
                    var_a1_7 = var_a1_6 >> 1;
                }
                var_a2_6 = var_a2_7 - 1;
                var_v1_8 = var_a1_7 & 1;
                if (var_a2_6 < 0) {
                    temp_a1_11 = var_t1;
                    var_t1 = *(u32 *)var_t0;
                    var_t0 += 4;
                    var_v1_8 = (var_a1_7 + (temp_a1_11 << (var_a2_6 + 1))) & 1;
                    var_a1_6 = temp_a1_11 >> -var_a2_6;
                    var_a2_6 += 0x20;
                } else {
                    var_a1_6 = var_a1_7 >> 1;
                }
                if (var_v1_8 != 0) {
                    var_a2_8 = var_a2_6 - 1;
                    var_v1_9 = var_a1_6 & 1;
                    if (var_a2_8 < 0) {
                        temp_a1_12 = var_t1;
                        var_t1 = *(u32 *)var_t0;
                        var_t0 += 4;
                        var_v1_9 = (var_a1_6 + (temp_a1_12 << (var_a2_8 + 1))) & 1;
                        var_a1_8 = temp_a1_12 >> -var_a2_8;
                        var_a2_8 += 0x20;
                    } else {
                        var_a1_8 = var_a1_6 >> 1;
                    }
                    var_a2_6 = var_a2_8 - 1;
                    var_a3 = (var_a3 * 2) + var_v1_9 + 4;
                    if (var_a2_6 < 0) {
                        temp_a1_13 = var_t1;
                        var_t1 = *(u32 *)var_t0;
                        var_t0 += 4;
                        var_v1_10 = (var_a1_8 + (temp_a1_13 << (var_a2_6 + 1))) & 1;
                        var_a1_6 = temp_a1_13 >> -var_a2_6;
                        var_a2_6 += 0x20;
                    } else {
                        var_v1_10 = var_a1_8 & 1;
                        var_a1_6 = var_a1_8 >> 1;
                    }
                    if (var_v1_10 == 0) {
                        var_a2_6 -= 1;
                        var_v1_11 = var_a1_6 & 1;
                        if (var_a2_6 < 0) {
                            temp_a1_14 = var_t1;
                            var_t1 = *(u32 *)var_t0;
                            var_t0 += 4;
                            var_v1_11 = (var_a1_6 + (temp_a1_14 << (var_a2_6 + 1))) & 1;
                            var_a1_6 = temp_a1_14 >> -var_a2_6;
                            var_a2_6 += 0x20;
                        } else {
                            var_a1_6 = var_a1_6 >> 1;
                        }
                        var_a3 = (var_a3 * 2) + var_v1_11;
                    }
                } else if (var_a3 == 0) {
                    var_a2_6 -= 1;
                    var_v1_12 = var_a1_6 & 1;
                    if (var_a2_6 < 0) {
                        temp_a1_15 = var_t1;
                        var_t1 = *(u32 *)var_t0;
                        var_t0 += 4;
                        var_v1_12 = (var_a1_6 + (temp_a1_15 << (var_a2_6 + 1))) & 1;
                        var_a1_6 = temp_a1_15 >> -var_a2_6;
                        var_a2_6 += 0x20;
                    } else {
                        var_a1_6 = var_a1_6 >> 1;
                    }
                    var_a3 = var_v1_12 + 2;
                }
            }
            var_a2 = var_a2_6 - 8;
            var_v1_13 = var_a1_6 & 0xFF;
            if (var_a2 < 0) {
                temp_a1_16 = var_t1;
                var_t1 = *(u32 *)var_t0;
                var_t0 += 4;
                var_v1_13 = (var_a1_6 + (temp_a1_16 << (var_a2 + 8))) & 0xFF;
                var_a1 = temp_a1_16 >> -var_a2;
                var_a2 += 0x20;
            } else {
                var_a1 = var_a1_6 >> 8;
            }
            var_a3_2 = var_a0 - ((var_a3 << 8) + var_v1_13 + 1);
            var_t2_5 = var_t2_2 - 1;
            if (var_t2_2 != 0) {
                do {
                    var_a2_10 = (u8)(*(u8 *)var_a3_2);
                    __repair_phase_temp_v1 = var_t2_5;
                    var_a3_2 += 1;
                    var_t2_5 -= 1;
                    *(u8 *)var_a0 = var_a2_10;
                    var_a0 += 1;
                } while (__repair_phase_temp_v1 != 0);
                var_a2_2 = var_a2 - 1;
            } else {
                goto loop_1;
            }
        }
        goto loop_2;
    }
    var_v1_14 = var_a1_3 & 1;
    if (var_a2_4 < 0) {
        temp_a1_17 = var_t1;
        var_t1 = *(u32 *)var_t0;
        var_t0 += 4;
        var_v1_14 = (var_a1_3 + (temp_a1_17 << (var_a2_4 + 1))) & 1;
        var_a1_9 = temp_a1_17 >> -var_a2_4;
        var_a2_4 += 0x20;
    } else {
        var_a1_9 = var_a1_3 >> 1;
    }
    if (var_v1_14 == 0) {
        var_a2 = var_a2_4 - 8;
        var_t2_6 = 2;
        if (var_a2 < 0) {
            temp_a1_18 = var_t1;
            var_t1 = *(u32 *)var_t0;
            var_t0 += 4;
            var_a3_3 = (var_a1_9 + (temp_a1_18 << (var_a2 + 8))) & 0xFF;
            var_a1 = temp_a1_18 >> -var_a2;
            var_a2 += 0x20;
        } else {
            var_a3_3 = var_a1_9 & 0xFF;
            var_a1 = var_a1_9 >> 8;
        }
        var_a3_4 = var_a3_3 + 1;
block_68:
        var_a3_5 = var_a0 - var_a3_4;
        var_t2_7 = var_t2_6 - 1;
        if (var_t2_6 != 0) {
            do {
                temp_v0_4 = *(u8 *)var_a3_5;
                var_a3_5 += 1;
                temp_v1_2 = var_t2_7;
                var_t2_7--;
                *(u8 *)var_a0 = temp_v0_4;
                var_a0 += 1;
            } while (temp_v1_2 != 0);
            var_a2_2 = var_a2 - 1;
        } else {
            goto loop_1;
        }
        goto loop_2;
    }
    var_a2_9 = var_a2_4 - 1;
    var_v1_15 = var_a1_9 & 1;
    if (var_a2_9 < 0) {
        temp_a1_19 = var_t1;
        var_t1 = *(u32 *)var_t0;
        var_t0 += 4;
        var_v1_15 = (var_a1_9 + (temp_a1_19 << (var_a2_9 + 1))) & 1;
        var_a1_10 = temp_a1_19 >> -var_a2_9;
        var_a2_9 += 0x20;
    } else {
        var_a1_10 = var_a1_9 >> 1;
    }
    if (var_v1_15 == 0) {
        var_t2_6 = 3;
block_37:
        var_a2_10 = var_a2_9 - 1;
        var_a3_6 = 0;
        if (var_a2_10 < 0) {
            temp_a1_20 = var_t1;
            var_t1 = *(u32 *)var_t0;
            var_t0 += 4;
            var_v1_16 = (var_a1_10 + (temp_a1_20 << (var_a2_10 + 1))) & 1;
            var_a1_11 = temp_a1_20 >> -var_a2_10;
            var_a2_10 += 0x20;
        } else {
            var_v1_16 = var_a1_10 & 1;
            var_a1_11 = var_a1_10 >> 1;
        }
        if (var_v1_16 != 0) {
            var_a2_11 = var_a2_10 - 1;
            var_a3_6 = var_a1_11 & 1;
            if (var_a2_11 < 0) {
                temp_a1_21 = var_t1;
                var_t1 = *(u32 *)var_t0;
                var_t0 += 4;
                var_a3_6 = (var_a1_11 + (temp_a1_21 << (var_a2_11 + 1))) & 1;
                var_a1_12 = temp_a1_21 >> -var_a2_11;
                var_a2_11 += 0x20;
            } else {
                var_a1_12 = var_a1_11 >> 1;
            }
            var_a2_10 = var_a2_11 - 1;
            var_v1_17 = var_a1_12 & 1;
            if (var_a2_10 < 0) {
                temp_a1_22 = var_t1;
                var_t1 = *(u32 *)var_t0;
                var_t0 += 4;
                var_v1_17 = (var_a1_12 + (temp_a1_22 << (var_a2_10 + 1))) & 1;
                var_a1_11 = temp_a1_22 >> -var_a2_10;
                var_a2_10 += 0x20;
            } else {
                var_a1_11 = var_a1_12 >> 1;
            }
            if ((s32)var_v1_17 != 0) {
                var_a2_12 = var_a2_10 - 1;
                var_v1_18 = var_a1_11 & 1;
                if (var_a2_12 < 0) {
                    temp_a1_23 = var_t1;
                    var_t1 = *(u32 *)var_t0;
                    var_t0 += 4;
                    var_v1_18 = (var_a1_11 + (temp_a1_23 << (var_a2_12 + 1))) & 1;
                    var_a1_13 = temp_a1_23 >> -var_a2_12;
                    var_a2_12 += 0x20;
                } else {
                    var_a1_13 = var_a1_11 >> 1;
                }
                var_a2_10 = var_a2_12 - 1;
                var_a3_6 = (var_a3_6 * 2) + var_v1_18 + 4;
                if (var_a2_10 < 0) {
                    temp_a1_24 = var_t1;
                    var_t1 = *(u32 *)var_t0;
                    var_t0 += 4;
                    var_v1_19 = (var_a1_13 + (temp_a1_24 << (var_a2_10 + 1))) & 1;
                    var_a1_11 = temp_a1_24 >> -var_a2_10;
                    var_a2_10 += 0x20;
                } else {
                    var_v1_19 = var_a1_13 & 1;
                    var_a1_11 = var_a1_13 >> 1;
                }
                if (var_v1_19 == 0) {
                    var_a2_10 -= 1;
                    var_v1_20 = var_a1_11 & 1;
                    if (var_a2_10 < 0) {
                        temp_a1_25 = var_t1;
                        var_t1 = *(u32 *)var_t0;
                        var_t0 += 4;
                        var_v1_20 = (var_a1_11 + (temp_a1_25 << (var_a2_10 + 1))) & 1;
                        var_a1_11 = temp_a1_25 >> -var_a2_10;
                        var_a2_10 += 0x20;
                    } else {
                        var_a1_11 = var_a1_11 >> 1;
                    }
                    var_a3_6 = (var_a3_6 * 2) + var_v1_20;
                }
            } else if (var_a3_6 == 0) {
                var_a2_10 -= 1;
                var_v1_21 = var_a1_11 & 1;
                if (0 > var_a2_10) {
                    temp_a1_26 = var_t1;
                    var_t1 = *(u32 *)var_t0;
                    var_t0 += 4;
                    var_v1_21 = (var_a1_11 + (temp_a1_26 << (var_a2_10 + 1))) & 1;
                    var_a1_11 = temp_a1_26 >> -var_a2_10;
                    var_a2_10 += 0x20;
                } else {
                    var_a1_11 = var_a1_11 >> 1;
                }
                var_a3_6 = var_v1_21 + 2;
            }
        }
        var_a2 = var_a2_10 - 8;
        var_v1_22 = var_a1_11 & 0xFF;
        if (var_a2 < 0) {
            temp_a1_27 = var_t1;
            var_t1 = *(u32 *)var_t0;
            var_t0 += 4;
            var_v1_22 = (var_a1_11 + (temp_a1_27 << (var_a2 + 8))) & 0xFF;
            var_a1 = temp_a1_27 >> -var_a2;
            var_a2 += (u32)0x20;
        } else {
            var_a1 = var_a1_11 >> 8;
        }
        var_a3_4 = (var_a3_6 << 8) + var_v1_22 + 1;
        goto block_68;
    }
    var_a2_9 -= 8;
    var_t2_8 = var_a1_10 & 0xFF;
    if (var_a2_9 < 0) {
        temp_a1_28 = var_t1;
        var_t1 = *(u32 *)var_t0;
        var_t0 += 4;
        var_t2_8 = (var_a1_10 + (temp_a1_28 << (var_a2_9 + 8))) & 0xFF;
        var_a1_10 = temp_a1_28 >> -var_a2_9;
        var_a2_9 += 0x20;
    } else {
        var_a1_10 = var_a1_10 >> 8;
    }
    var_t2_6 = var_t2_8 + 8;
    if (var_t2_8) {
        goto block_37;
    }
}
