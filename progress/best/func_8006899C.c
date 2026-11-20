/* machine draft (m2c) for gcc-2.7.2-kmc -G0 -mips3 -mgp32 -mfp32 -O2, tried by autopilot */

s32 func_8000A270();
s32 func_8000A894();
s32 markObjectsNearPos();
f32 func_80045590();
f32 approxDistance();
s32 func_800643EC();
s32 func_80064860();
s32 func_800648FC();
s32 func_80067294();
s32 func_80067A24();
s32 func_80067A7C();
s32 func_8006832C();
s32 func_8007A9CC();
s32 func_800818AC();
s32 func_8008194C();
s32 func_80081AA4();
s32 func_80082834();
s32 func_80084338();
extern char D_800C469C[];
extern u8 D_800E1A16;
extern s32 D_800E1A28;
extern s32 D_800E1A2C;
extern char gTrackMarkerTable[];

typedef struct { unsigned char pad_0[32]; void * field_20; unsigned char pad_24[68]; void * field_68; void * field_6C; unsigned char pad_70[8]; unsigned short field_78; } __repair_record_arg0;
void func_8006899C(void *arg0, u8 arg1) {
    s32 sp28;
    s32 sp2C;
    u8 sp37;
    s16 temp_v0_10;
    s16 temp_v0_3;
    s16 temp_v0_4;
    s16 temp_v0_8;
    s16 temp_v0_9;
    s16 temp_v1_4;
    s32 temp_a0_2;
    unsigned temp_a0;
    s32 temp_a0_3;
    s32 temp_a0_4;
    s32 temp_v0_6;
    s32 temp_v0_7;
    s32 var_a0;
    s32 var_s6;
    s32 temp_fp;
    u16 temp_a0_5;
    u16 temp_v0_11;
    u16 temp_v1;
    u16 var_a0_2;
    u8 temp_a1_2;
    u8 temp_a1_3;
    u8 temp_v0_2;
    u8 temp_v0_5;
    void **temp_v0;
    
    void *temp_a1;
    void *temp_s0;
    void *temp_s0_2;
    void *temp_s2;
    void *temp_s4;
    void *temp_s7;
    void *temp_v1_2;
    void *temp_v1_3;
    void *var_s1;
    void *var_s5;

    temp_s2 = ((__repair_record_arg0*)arg0)->field_6C;
    temp_fp = (*(s8 *)((char *)(temp_s2) + 0x182));
    temp_v0 = (void **) gTrackMarkerTable;
    temp_v0 = (void **)((char *)temp_v0 + (temp_fp * 4));
    var_s6 = 1;
    sp37 = arg1;
    temp_s4 = ((*(s8 *)((char *)(((__repair_record_arg0*)arg0)->field_68) + 0xE)) * 0xE8) + D_800C469C;
    if (func_80081AA4(arg0, temp_fp, 0x12, (*(f32 *)((char *)(*temp_v0) + 0x34)), (*(f32 *)((char *)(*temp_v0) + 0x38)), 0) != 0) {
        temp_v0 = ((__repair_record_arg0*)arg0)->field_20;
        var_s5 = (*(void **)((char *)((*(void **)((char *)(temp_v0) + 0x20))) + 0x58));
        if (temp_v0 != NULL) {
            temp_s7 = arg0 + 0x24;
            do {
                var_s1 = *temp_v0;
                if (var_s1 != NULL) {
                    do {
                        temp_v1 = (*(u16 *)((char *)(var_s1) + 0x78));
                        if ((s32) temp_v1 < 0x13) {
                            if ((s32) temp_v1 < 0x10) {
                                if (temp_v1 != 0xB) {

                                } else {
                                    temp_a1 = (*(void **)((char *)(var_s1) + 0x6C));
                                    temp_v0_2 = (*(u8 *)((char *)(temp_a1) + 0x4A));
                                    var_a0 = 1;
                                    switch (temp_v0_2) {
                                    case 4:
                                        var_a0 = 1 & -((*(u16 *)((char *)(temp_a1) + 0x34)) == 0);
                                        break;
                                    case 5:
                                        var_a0 = 1 & -((*(u16 *)((char *)(temp_a1) + 0x34)) == 0);
                                        break;
                                    case 16:
                                        var_a0 = 1 & -((*(u16 *)((char *)(temp_a1) + 0x34)) == 0);
                                        break;
                                    case 17:
                                        var_a0 = 1 & -((*(u16 *)((char *)(temp_a1) + 0x34)) == 0);
                                        break;
                                    case 18:
                                    case 19:
                                    case 20:
                                    default:
                                        var_a0 = 0;
                                        break;
                                    }
                                    if ((var_a0 << 0x18) != 0) {
                                        temp_s0 = var_s1 + 0x24;
                                        if (((func_8007A9CC(arg0, temp_s0, &sp28) << 0x18) != 0) && (approxDistance(temp_s0, temp_s7) < 3.0f) && (func_80045590(temp_s0, temp_s7) < 2.0f)) {
                                            temp_v0_3 = (*(s16 *)((char *)(var_s1) + 0x7A));
                                            if (((temp_v0_3 == 0) | (temp_v0_3 == 4)) != 0) {
                                                if (((__repair_record_arg0*)arg0)->field_20 == (*(s32 *)((char *)(var_s1) + 0x20))) {
                                                    (*(s32 *)((char *)(var_s1) + 0x60)) = (*(s32 *)((char *)(var_s1) + 0x60)) | 8;
                                                } else {
                                                    (*(s32 *)((char *)(var_s1) + 0x60)) = (*(s32 *)((char *)(var_s1) + 0x60)) & ~8;
                                                }
                                                markObjectsNearPos((*(s32 *)((char *)(var_s1) + 0x20)), 2, 0x20000, var_s1 + 0x24, 0, 1);
                                                goto block_28;
                                            }
                                        }
                                    }
                                }
                            } else {
                                goto block_10;
                            }
                        } else if (((s32) temp_v1 < 0x61) && ((s32) temp_v1 >= 0x5E)) {
block_10:
                            if (((*(s32 *)((char *)(var_s1) + 0x20)) == ((__repair_record_arg0*)arg0)->field_20) && ((*(s32 *)((char *)((*(void **)((char *)(var_s1) + 0x6C))) + 0x2C)) & 0x800)) {
                                temp_s0_2 = var_s1 + 0x24;
                                if (((func_8007A9CC(arg0, temp_s0_2, &sp28, 0x44800000) << 0x18) != 0) && (approxDistance(temp_s0_2, arg0 + 0x24) < 1.5f)) {
block_28:
                                    var_s6 = 0;
                                    (*(s32 *)((char *)(var_s1) + 0x60)) |= 0x800;
                                }
                            }
                        }
                        var_s1 = (*(void **)((char *)(var_s1) + 0));
                    } while (var_s1 != NULL);
                }
                temp_v0 = NULL;
                if (var_s5 != NULL) {
                    temp_v0 = (*(void ***)((char *)(var_s5) + 8));
                    var_s5 = (*(void **)((char *)(var_s5) + 0));
                }
            } while (temp_v0 != NULL);
        }
    }
    temp_v0_4 = (*(s16 *)((char *)(temp_s2) + 0x176));
    if (temp_v0_4 >= 0) {
        (*(s16 *)((char *)(temp_s2) + 0x176)) = (s16) (temp_v0_4 - 1);
        return;
    }
    if (var_s6 != 0) {
        if ((func_80081AA4(temp_fp, 0x12) != 0) && ((*(s16 *)((char *)((*(void **)((char *)(temp_s2) + 0xA8))) + 0x7A)) == 0)) {
            if ((func_800648FC(arg0, 1) << 0x18) != 0) {
                temp_a0 = (*(s32 *)((char *)(temp_s2) + 8));
                (*(s16 *)((char *)(temp_s2) + 0x176)) = (s16) (*(u8 *)((char *)(temp_s4) + 0x36));
                if (temp_a0 != -1) {
                    func_8000A270(temp_a0);
                    (*(s32 *)((char *)(temp_s2) + 8)) = -1;
                }
                temp_v1_2 = (*(void **)((char *)(temp_s2) + 0xA8));
                (*(u16 *)((char *)(temp_s2) + 0x17A)) = (u16) (*(u16 *)((char *)((((*(u8 *)((char *)((temp_s2 + ((*(s8 *)((char *)(((__repair_record_arg0*)arg0)->field_68) + 0xE)) * 8))) + 0x1FD)) * 2) + temp_s4)) + 0x24));
                if (temp_v1_2 != NULL) {
                    (*(s16 *)((char *)(temp_v1_2) + 0x7A)) = 5;
                    func_80067A24((*(void **)((char *)(temp_s2) + 0xA8)), (*(u16 *)((char *)(temp_s4) + 0x94)));
                } else if (((__repair_record_arg0*)arg0)->field_78 == 3) {
                    func_80084338((*(u16 *)((char *)(temp_s4) + 0x54)), arg0 + 0x24);
                } else {
                    func_8000A894((*(u16 *)((char *)(temp_s4) + 0x54)));
                }
            }
        }
    }
    if (func_8008194C(temp_fp, 0xE) == 0) {
        (*(u16 *)((char *)(temp_s2) + 0x17A)) = 0U;
        goto block_61;
    }
    if ((func_80064860(arg0, (*(u8 *)((char *)(temp_s4) + 0x81)), 0U) << 0x18) == 0) {
        if (((*(s8 *)((char *)(((__repair_record_arg0*)arg0)->field_68) + 0xE)) != 0x1C) || (func_800818AC(temp_fp, 0x18) == 0)) {
            temp_v0_5 = (*(u8 *)((char *)(temp_s2) + 0x19A)) - 1;
            (*(u8 *)((char *)(temp_s2) + 0x19A)) = temp_v0_5;
            if (temp_v0_5 & 0x80) {
                (*(u8 *)((char *)(temp_s2) + 0x19A)) = 0xFU;
                if (((__repair_record_arg0*)arg0)->field_78 == 3) {
                    func_80084338((*(u16 *)((char *)(temp_s4) + 0x56)), arg0 + 0x24);
                } else {
                    func_8000A894((*(u16 *)((char *)(temp_s4) + 0x56)));
                }
            }
        }
        goto block_62;
    }
    temp_v0_6 = (*(s32 *)((char *)(temp_s2) + 0x10));
    temp_v0_7 = temp_v0_6 - 1;
    if (temp_v0_6 > 0) {
        (*(s32 *)((char *)(temp_s2) + 0x10)) = temp_v0_7;
        if (temp_v0_7 == 0) {
            if ((*(s16 *)((char *)(temp_s4) + 0x34)) > 0) {
                if ((*(s16 *)((char *)((*(void **)((char *)(temp_s2) + 0xA8))) + 0x7A)) != 0) {
                    return;
                }
                goto block_76;
            }
            goto block_62;
        }
    }
block_61:
block_62:
    if ((func_8008194C(temp_fp, 0xE) == 0) && ((func_80064860(arg0, (*(u8 *)((char *)(temp_s4) + 0x81)), 0U) << 0x18) == 0)) {
        if (((*(s16 *)((char *)((*(void **)((char *)(temp_s2) + 0xA8))) + 0x7A)) == 0) && (((*(s8 *)((char *)(((__repair_record_arg0*)arg0)->field_68) + 0xE)) != 0x1C) || (func_800818AC(temp_fp, 0x18) == 0))) {
            temp_a0_2 = (*(s32 *)((char *)(temp_s2) + 8));
            if (temp_a0_2 != -1) {
                func_8000A270(temp_a0_2);
                (*(s32 *)((char *)(temp_s2) + 8)) = -1;
            }
            if ((func_800648FC(arg0, 1) << 0x18) != 0) {
                (*(s16 *)((char *)(temp_s2) + 0x176)) = (s16) (*(u8 *)((char *)(temp_s4) + 0x36));
                (*(s16 *)((char *)(temp_s2) + 0x176)) = (s16) (*(u8 *)((char *)(temp_s4) + 0x36));
                temp_v1_3 = (*(void **)((char *)(temp_s2) + 0xA8));
                (*(u16 *)((char *)(temp_s2) + 0x17A)) = (u16) (*(u16 *)((char *)((((*(u8 *)((char *)((temp_s2 + ((*(s8 *)((char *)(((__repair_record_arg0*)arg0)->field_68) + 0xE)) * 8))) + 0x1FD)) * 2) + temp_s4)) + 0x24));
                (*(s16 *)((char *)(temp_s2) + 0x178)) = 0;
                if (temp_v1_3 != NULL) {
                    (*(s16 *)((char *)(temp_v1_3) + 0x7A)) = 5;
                    func_80067A24((*(void **)((char *)(temp_s2) + 0xA8)), (*(u16 *)((char *)(temp_s4) + 0x94)));
                    return;
                }
                var_a0_2 = (*(u16 *)((char *)(temp_s4) + 0x54));
                {
                                func_80084338(var_a0_2, arg0 + 0x24);return;}
            }
            func_80067294(arg0);
        }
    } else {
        if ((func_80081AA4(temp_fp, 0xE) != 0) || ((s8) sp37 == 1)) {
block_76:
            if (((*(s16 *)((char *)(temp_s2) + 0x176)) == -1) && ((s32) (*(s16 *)((char *)(temp_s2) + 0x178)) == 0)) {
                temp_v0_8 = (*(s16 *)((char *)(temp_s4) + 0x34));
                if (temp_v0_8 > 0) {
                    (*(s32 *)((char *)(temp_s2) + 0x10)) = (s32) temp_v0_8;
                }
                temp_v0_9 = (*(s16 *)((char *)((*(void **)((char *)(temp_s2) + 0xA8))) + 0x7A));
                if (((temp_v0_9 == 0) | (temp_v0_9 == 7)) != 0) {
                    temp_a1_2 = (*(u8 *)((char *)(temp_s4) + 0x81));
                    if ((func_80064860(arg0, temp_a1_2, temp_a1_2) << 0x18) != 0) {
                        (*(u16 *)((char *)(temp_s2) + 0x17A)) = (u16) (*(u16 *)((char *)((((*(u8 *)((char *)((temp_s2 + ((*(s8 *)((char *)(((__repair_record_arg0*)arg0)->field_68) + 0xE)) * 8))) + 0x1FD)) * 2) + temp_s4)) + 0x24));
                        (*(s16 *)((char *)(temp_s2) + 0x178)) = (s16) (*(s32 *)((char *)(temp_s4) + 0x30));
                        goto block_100;
                    }
                }
                goto block_83;
            }
            goto block_83;
        }
block_83:
        temp_v0_10 = (*(s16 *)((char *)(temp_s2) + 0x178));
        if (temp_v0_10 > 0) {
            (*(s16 *)((char *)(temp_s2) + 0x178)) = (s16) (temp_v0_10 - 1);
            temp_v1_4 = (*(s16 *)((char *)((*(void **)((char *)(temp_s2) + 0xA8))) + 0x7A));
            if (temp_v1_4 != 7) {
                if (temp_v1_4 >= 8) {
                    if (temp_v1_4 == 9) {
                        goto block_91;
                    }
                } else {
                    if (temp_v1_4 != 0) {
                        return;
                    }
                    goto block_91;
                }
            } else {
block_91:
                if ((*(s16 *)((char *)(temp_s2) + 0x178)) == 0) {
                    temp_v0_11 = (*(u16 *)((char *)(temp_s2) + 0x17A)) - 1;
                    (*(u16 *)((char *)(temp_s2) + 0x17A)) = temp_v0_11;
                    if ((temp_v0_11 << 0x10) <= 0) {
                        temp_a0_3 = (*(s32 *)((char *)(temp_s2) + 8));
                        if (temp_a0_3 == -1) {
                            (*(s16 *)((char *)(temp_s2) + 0x178)) = 0;
                            return;
                        }
                        func_8000A270(temp_a0_3);
                        (*(s32 *)((char *)(temp_s2) + 8)) = -1;
                        (*(s16 *)((char *)(temp_s2) + 0x178)) = 0;
                        return;
                    }
                    temp_a1_3 = (*(u8 *)((char *)(temp_s4) + 0x81));
                    if ((func_80064860(arg0, temp_a1_3, temp_a1_3) << 0x18) == 0) {
                        temp_a0_4 = (*(s32 *)((char *)(temp_s2) + 8));
                        (*(u16 *)((char *)(temp_s2) + 0x17A)) += 1;
                        (*(s16 *)((char *)(temp_s2) + 0x178)) = (s16) (*(s32 *)((char *)(temp_s4) + 0x30));
                        if (temp_a0_4 != -1) {
                            func_8000A270(temp_a0_4);
                            (*(s32 *)((char *)(temp_s2) + 8)) = -1;
                        }
                    } else {
block_100:
                        if ((D_800E1A16 == 0) && !((*(s32 *)((char *)(temp_s4) + 0x60)) & 0x80)) {
                            if (((__repair_record_arg0*)arg0)->field_78 == 3) {
                                var_a0_2 = (*(u16 *)((char *)(temp_s4) + 0x56));
block_104:
                                func_80084338(var_a0_2, arg0 + 0x24);
                                return;
                            }
                            func_8000A894((*(u16 *)((char *)(temp_s4) + 0x56)));
                            return;
                        }
                        D_800E1A28 |= 0x10000;
                        D_800E1A2C = (s32) (*(u8 *)((char *)(temp_s4) + 0x5E));
                        temp_a0_5 = (*(u16 *)((char *)((((*(u8 *)((char *)((temp_s2 + ((*(s8 *)((char *)(((__repair_record_arg0*)arg0)->field_68) + 0xE)) * 8))) + 0x1FD)) * 2) + temp_s4)) + 0x4E));
                        if ((temp_a0_5 != 0) && ((*(s32 *)((char *)(temp_s2) + 8)) == -1)) {
                            if (((__repair_record_arg0*)arg0)->field_78 == 3) {
                                (*(s32 *)((char *)(temp_s2) + 8)) = func_80084338((*(u16 *)((char *)(temp_s4) + 0x58)), arg0 + 0x24);
                            } else {
                                (*(s32 *)((char *)(temp_s2) + 8)) = func_8000A894(temp_a0_5);
                            }
                        }
                        if (((__repair_record_arg0*)arg0)->field_78 == 2) {
                            func_80082834(temp_fp, 5, (*(u8 *)((char *)(temp_s4) + 0x84)));
                        }
                        (*(s16 *)((char *)(temp_s2) + 0x178)) = (s16) (*(s32 *)((char *)(temp_s4) + 0x30));
                        func_80067A7C(temp_s2, (*(void **)((char *)(temp_s2) + 0xA8)), (*(u16 *)((char *)(temp_s4) + 0x96)));
                        if ((*(s32 *)((char *)(temp_s4) + 0x60)) & 0x4000) {
                            (*(s16 *)((char *)((*(void **)((char *)(temp_s2) + 0xA8))) + 0x7A)) = 9;
                            return;
                        }
                        func_8006832C(arg0, temp_s4);
                    }
                }
            }
        } else if ((*(s16 *)((char *)(temp_s2) + 0x176)) <= 0) {
            func_800643EC(arg0);
        }
    }
}
