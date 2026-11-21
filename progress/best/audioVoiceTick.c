/* machine draft (m2c) for gcc-2.7.2-kmc -G0 -mips3 -mgp32 -mfp32 -O2, tried by autopilot */

extern unsigned int D_800FDBA0;
extern unsigned short D_800FDBA2;
extern signed char D_800FDBA3;
s32 audioVoiceIsActive();
s32 func_8008C380();
s32 func_8008C3D8();
s32 func_8008C590();
s32 func_8008C7E0();
s32 func_8008CE38();
s32 randomU16Next();
s32 func_800957A8();
s32 func_800957B8();
s32 func_800968A4();
u8 func_800968E8();
s32 func_8009692C();
s32 func_800969B4();
u32 func_80096D9C();
s8 func_80096E1C();
s32 func_80096F44();
s32 func_800982B4();
void *func_8009846C();
s32 voiceListRemove();
s32 func_80098B14();
s32 func_800992B4();
void *audioUpdateClipSelection();
void *audioVoiceStepTimer();
void *audioCmdNoteOn();
void *func_8009A0E4();
void *audioVoiceApplyEnvelope();
void *audioApplyVoiceConfig();
void *func_8009A4E4();
void *func_8009A70C();
void *func_8009A804();
void *func_8009A990();
void *func_8009ABD4();
void *func_8009AE24();
extern u32 D_800FDB9C;
extern u8 D_800FDB9D;
extern u8 D_800FDB9E;
extern char D_801007D9[];
extern u8 D_80100868;
extern char D_80100C7C[];
extern s32 D_80109680;
extern char D_8010D748[];
extern char D_8010D784[];
extern char D_80112E9E[];
extern char D_80112EBE[];
extern u8 sVoiceCount;

void audioVoiceTick(void *arg0, u8 arg1, s32 arg2) {
    s16 sp10[4];
    s32 var_a2_4;
    s32 var_a2_5;
    s16 temp_v0_20;
    s16 var_a1_4;
    s32 temp_a0;
    s32 temp_a0_11;
    s32 temp_a0_13;
    s32 temp_a0_15;
    s32 temp_a0_17;
    s32 temp_a0_19;
    s32 temp_a0_21;
    s32 temp_a0_23;
    s32 temp_a0_2;
    s32 temp_a0_5;
    s32 temp_a0_7;
    s32 temp_a0_9;
    s32 temp_v0_14;
    s32 temp_v0_15;
    s32 temp_v0_19;
    s32 temp_v0_21;
    s32 temp_v0_3;
    s32 temp_v0_4;
    s32 temp_v0_5;
    s32 temp_v0_6;
    s32 temp_v0_7;
    s32 temp_v0_8;
    s32 temp_v1;
    s32 temp_v1_11;
    s32 temp_v1_2;
    s32 temp_v1_3;
    s32 temp_v1_4;
    s32 temp_v1_6;
    s32 temp_v1_7;
    s32 temp_v1_9;
    s32 var_a2;
    unsigned var_a2_2;
    s32 var_a2_3;
    s32 var_v0;
    s32 var_v0_2;
    s32 var_v0_4;
s32 __repair_result_var_v0_4;
    s32 var_v0_5;
    s32 var_v1;
    u16 temp_s0;
    u16 temp_v0_10;
    u16 temp_v0_11;
    u16 temp_v0_12;
    u16 temp_v0_13;
    u16 temp_v1_10;
    u16 var_v1_3;
    u32 temp_s0_10;
    u32 temp_s0_11;
    u32 temp_s0_2;
    u32 temp_s0_3;
    u32 temp_s0_4;
    u32 temp_s0_5;
    u32 temp_s0_6;
    u32 temp_s0_7;
    u32 temp_s0_8;
    u32 temp_s0_9;
    u32 temp_v0_17;
    u32 temp_v0_18;
    u32 temp_v1_12;
    u32 temp_v1_23;
    u32 temp_v1_24;
    s32 temp_v1_25;
    u32 temp_v1_5;
    u32 temp_v1_8;
    u32 var_a1_2;
    u32 var_v0_6;
    u8 temp_a0_3;
    u8 temp_a0_4;
    u8 temp_a1;
    u8 temp_a1_2;
    u8 temp_a2;
    u8 temp_s2;
    u8 temp_s2_2;
    u8 temp_s2_3;
    u8 temp_s2_4;
    u8 temp_s2_5;
    u8 temp_s2_6;
    u8 temp_s2_7;
    u8 temp_s2_8;
    u8 temp_s2_9;
    u8 temp_v0;
    u8 temp_v0_16;
    u8 temp_v0_22;
    u8 temp_v0_2;
    u8 temp_v1_13;
    u8 temp_v1_14;
    u8 temp_v1_15;
    u8 temp_v1_16;
    u8 temp_v1_17;
    u8 temp_v1_18;
    u8 temp_v1_19;
    u8 temp_v1_20;
    u8 temp_v1_21;
    u8 var_a1;
    u8 var_a1_3;
    u8 var_v0_3;
    u8 var_v1_2;
    void *temp_a0_10;
    
    void *temp_a0_14;
    void *temp_a0_16;
    void *temp_a0_18;
    void *temp_a0_20;
    void *temp_a0_22;
    void *temp_a0_6;
    void *temp_a0_8;
    void *temp_v0_9;
    void *temp_v1_22;
    void *var_a0;

    var_a1 = arg1;
    var_a2 = arg2;
    temp_v1 = (*(s32 *)((char *)(arg0) + 0x24));
    if (temp_v1 & 3) {
        if (temp_v1 & 1) {
            (*(s32 *)((char *)(arg0) + 0x24)) = (s32) (temp_v1 & ~1);
            func_8008C590((*(u8 *)((char *)(arg0) + 0x63)));
        }
        if ((*(s32 *)((char *)(arg0) + 0x24)) & 0x40) {
            (*(s32 *)((char *)(arg0) + 0x24)) = 0;
            func_800992B4(arg0);
            return;
        }
        func_800969B4(arg0);
        temp_a2 = (*(u8 *)((char *)(arg0) + 0x56));
        (*(u8 *)((char *)(arg0) + 0x4A)) = (u8) (*(u8 *)((char *)(arg0) + 0x54));
        (*(u8 *)((char *)(arg0) + 0x4B)) = (u8) (*(u8 *)((char *)(arg0) + 0x55));
        temp_v1_2 = (*(u8 *)((char *)(arg0) + 0x52)) << 0x10;
        (*(s32 *)((char *)(arg0) + 0x30)) = temp_v1_2;
        (*(s32 *)((char *)(arg0) + 0x34)) = temp_v1_2;
        (*(u8 *)((char *)(arg0) + 0x2F)) = temp_a2;
        (*(s32 *)((char *)(arg0) + 0x38)) = (s32) ((*(u8 *)((char *)(arg0) + 0x53)) << 0x10);
        temp_v0 = func_800968E8((*(u8 *)((char *)(arg0) + 0x4A)), (*(u8 *)((char *)(arg0) + 0x4B)));
        if ((temp_v0 & 0xFF) != 0xFF) {
            (*(u8 *)((char *)(arg0) + 0xC1)) = temp_v0;
        } else {
            (*(u8 *)((char *)(arg0) + 0xC1)) = (u8) (*(u16 *)((char *)(arg0) + 0x4E));
        }
        temp_v1_3 = (*(s32 *)((char *)(arg0) + 0x60));
        func_800968A4((*(u8 *)((char *)(arg0) + 0x4A)), (*(u8 *)((char *)(arg0) + 0x4B)), (*(u8 *)((char *)(arg0) + 0x4F)));
        if ((temp_v1_3 != -1) && (temp_a1 = (*(u8 *)((char *)(arg0) + 0x4A)), (temp_a1 != 0xFF))) {
            temp_v0_2 = (*(u8 *)((char *)(arg0) + 0x4B));
            if (temp_v0_2 == 0xFF) {
                *(D_80100C7C + (temp_v1_3 & 0xFF)) = (s8) temp_v1_3;
            } else {
                *((temp_v0_2 * 0x10) + D_801007D9 + temp_a1) = (s8) temp_v1_3;
            }
        }
        var_a1 = (*(u8 *)((char *)(arg0) + 0xBF));
        var_a2 = 0;
        (*(u32 *)((char *)(arg0) + 0x90)) = 0x64U;
        (*(s8 *)((char *)(arg0) + 0x6A)) = 2;
        (*(s8 *)((char *)(arg0) + 0x6B)) = 2;
        (*(u8 *)((char *)(arg0) + 0x99)) = 0x80;
        (*(s32 *)((char *)(arg0) + 0x8C)) = 0;
        (*(s8 *)((char *)(arg0) + 0x98)) = 0;
        (*(s8 *)((char *)(arg0) + 0x9A)) = 0;
        (*(s16 *)((char *)(arg0) + 0x68)) = 0;
        (*(s8 *)((char *)(arg0) + 0x48)) = 0;
        (*(s8 *)((char *)(arg0) + 0x49)) = 0;
        (*(s32 *)((char *)(arg0) + 0x40)) = 0;
        (*(s32 *)((char *)(arg0) + 0x44)) = 0;
        (*(s32 *)((char *)(arg0) + 0x16C)) = 0;
        (*(s16 *)((char *)(arg0) + 0x170)) = 0;
        (*(s32 *)((char *)(arg0) + 0x178)) = 0;
        (*(s16 *)((char *)(arg0) + 0x17C)) = 0;
        (*(s32 *)((char *)(arg0) + 0x1C)) = 0;
        (*(void **)((char *)(arg0) + 0x20)) = NULL;
        (*(s32 *)((char *)(arg0) + 0x5C)) = 0x4000AC44;
        (*(s16 *)((char *)(arg0) + 0xB8)) = 0x2000;
        (*(s16 *)((char *)(arg0) + 0xC2)) = 0;
        (*(u8 *)((char *)(arg0) + 0xBE)) = var_a1;
        (*(s32 *)((char *)(arg0) + 0x24)) &= 8;
        {
            u8 __repair_i;
            for (__repair_i = 0; __repair_i < 0x10; __repair_i++) {
                (*(s16 *)((char *)(((__repair_i * 2) + arg0)) + 0x180)) = 0;
            }
        }
        (*(u32 *)((char *)(arg0) + 0xA0)) = 0U;
        (*(u32 *)((char *)(arg0) + 0xA4)) = 0U;
        goto block_19;
    }
block_19:
    var_a0 = (*(void **)((char *)(arg0) + 0x20));
    if (var_a0 != NULL) {
        temp_v1_4 = (*(s32 *)((char *)(arg0) + 0x24));
        if (!(temp_v1_4 & 0x40000000) && (temp_v1_4 & 8)) {
            temp_v0_3 = (*(s32 *)((char *)(arg0) + 0x1C));
            (*(void **)((char *)(arg0) + 4)) = var_a0;
            (*(u32 *)((char *)(arg0) + 0x9C)) = 0U;
            (*(void **)((char *)(arg0) + 0x20)) = NULL;
            (*(s32 *)((char *)(arg0) + 0)) = temp_v0_3;
            (*(s32 *)((char *)(arg0) + 0x1C)) = 0;
        }
    }
    if ((*(u32 *)((char *)(arg0) + 0x9C)) == 0) {
        D_80100868 = 1;
loop_25:
        D_800FDB9C = (*(u32 *)((char *)((*(void **)((char *)(arg0) + 4))) + 0));
        D_800FDBA0 = (u32) (*(u32 *)((char *)((*(void **)((char *)(arg0) + 4))) + 4));
        (*(void **)((char *)(arg0) + 4)) = (void *) ((*(void **)((char *)(arg0) + 4)) + 8);
        temp_v1_5 = D_800FDB9C & 0x7F;
        switch (temp_v1_5) {
        case 0x1:
            if ((D_800FDB9E != 0) && (temp_v1_6 = (*(s32 *)((char *)(arg0) + 8)), var_a0 = NULL, (temp_v1_6 != 0))) {
                (*(s32 *)((char *)(arg0) + 0)) = temp_v1_6;
                (*(void **)((char *)(arg0) + 4)) = (void *) (*(void **)((char *)(arg0) + 0xC));
            } else {
            case 0x0:
block_40:
                voiceListRemove(arg0);
                func_800992B4(arg0);
                var_a0 = (void *)1;
            }
            break;
        case 0x2:
            if ((u16) (*(u16 *)((char *)(arg0) + 0x50)) >= (u8) D_800FDB9E) {
                temp_v0_4 = func_800982B4((u32) D_800FDB9C >> 0x10);
                var_a0 = NULL;
                if (temp_v0_4 != 0) {
                    (*(s32 *)((char *)(arg0) + 0)) = temp_v0_4;
                    (*(void **)((char *)(arg0) + 4)) = (void *) (temp_v0_4 + (D_800FDBA2 * 8));
                }
            } else {
            default:
block_205:
                var_a0 = NULL;
            }
            break;
        case 0x3:
            if ((u16) (*(s32 *)((char *)(arg0) + 0x30)) >= (u8) D_800FDB9E) {
                temp_v0_5 = func_800982B4((u32) D_800FDB9C >> 0x10);
                var_a0 = NULL;
                if (temp_v0_5 != 0) {
                    (*(s32 *)((char *)(arg0) + 0)) = temp_v0_5;
                    (*(void **)((char *)(arg0) + 4)) = (void *) (temp_v0_5 + (D_800FDBA2 * 8));
                }
            } else {
                goto block_205;
            }
            break;
        case 0x4:
block_120:
            var_a0 = audioUpdateClipSelection(arg0, &D_800FDB9C);
            break;
        case 0x5:
            var_a0 = audioVoiceStepTimer(arg0, &D_800FDB9C);
            break;
        case 0x6:
            temp_v0_6 = func_800982B4((u32) (u16) D_800FDB9C);
            var_a0 = NULL;
            if (temp_v0_6 != 0) {
                temp_v0_7 = (*(s32 *)((char *)(arg0) + 0));
                (*(s32 *)((char *)(arg0) + 0)) = temp_v0_6;
                (*(s32 *)((char *)(arg0) + 8)) = temp_v0_7;
                (*(void **)((char *)(arg0) + 0xC)) = (void *) (*(void **)((char *)(arg0) + 4));
                (*(void **)((char *)(arg0) + 4)) = (void *) (temp_v0_6 + (D_800FDBA2 * 8));
            } else {
                goto block_40;
            }
            break;
        case 0x7:
            D_800FDBA2 = 1;
            goto block_120;
        case 0x8:
            var_a0 = audioCmdNoteOn(arg0, &D_800FDB9C);
            break;
        case 0x9:
            var_a1_2 = 0;
            if (sVoiceCount != 0) {
                var_a2_2 = 0;
                do {
                    temp_a0 = *(s32 *)(D_8010D784 + var_a2_2);
                    if ((temp_a0 == ((((*(u16 *)((char *)(arg0) + 0x4E)) + D_800FDB9E) << 8) | ((u16) D_800FDB9C << 0x10) | var_a1_2)) && (temp_a0 != -1)) {
                        temp_v1_7 = (temp_a0 & 0xFF) * 0x1A0;
                        if (*(s32 *)(D_8010D784 + temp_v1_7) == temp_a0) {
                            *(s32 *)(D_8010D748 + temp_v1_7) = *(s32 *)(D_8010D748 + temp_v1_7) | 8;
                        }
                    }
                    var_a1_2 += 1;
                    var_a2_2 += 0x1A0;
                } while (var_a1_2 < (u8) sVoiceCount);
                var_a0 = NULL;
            } else {
block_60:
                var_a0 = NULL;
            }
            break;
        case 0xA:
            var_a0 = NULL;
            if ((*(u8 *)((char *)(arg0) + 0x4A)) != 0xFF) {
                if ((u32) ((func_80096D9C(arg0) >> 7) & 0xFF) >= (u8) D_800FDB9E) {
                    temp_v0_8 = func_800982B4((u32) D_800FDB9C >> 0x10);
                    var_a0 = NULL;
                    if (temp_v0_8 != 0) {
                        (*(s32 *)((char *)(arg0) + 0)) = temp_v0_8;
                        (*(void **)((char *)(arg0) + 4)) = (void *) (temp_v0_8 + (D_800FDBA2 * 8));
                    }
                } else {
                    goto block_205;
                }
            }
            break;
        case 0xB:
            temp_a0_2 = ((s32) ((((*(u16 *)((char *)(arg0) + 0x50)) - D_800FDB9D) << 0x10) * ((s32) (D_800FDB9C << 0x10) >> 0x18)) >> 7) + (((u32) D_800FDB9C >> 0x18) << 0x10);
            if (temp_a0_2 >= 0) {
                var_v1 = 0x7F0000;
                if (temp_a0_2 <= 0x7F0000) {
                    var_v1 = temp_a0_2;
                }
            } else {
                var_v1 = 0;
            }
            (*(s32 *)((char *)(arg0) + 0x38)) = var_v1;
            goto block_60;
        case 0xC:
            temp_v0_9 = func_8009846C(((u32) D_800FDB9C >> 8) & 0xFFFF);
            if (temp_v0_9 != NULL) {
                temp_v0_10 = (*(u16 *)((char *)(temp_v0_9) + 0));
                sp10[0] = (temp_v0_10 >> 8) | (temp_v0_10 << 8);
                temp_v0_11 = (*(u16 *)((char *)(temp_v0_9) + 2));
                sp10[1] = (temp_v0_11 >> 8) | (temp_v0_11 << 8);
                temp_v0_12 = (*(u16 *)((char *)(temp_v0_9) + 4));
                sp10[2] = (temp_v0_12 >> 8) | (temp_v0_12 << 8);
                temp_v0_13 = (*(u16 *)((char *)(temp_v0_9) + 6));
                sp10[3] = (temp_v0_13 >> 8) | (temp_v0_13 << 8);
                func_8008C3D8((*(u8 *)((char *)(arg0) + 0x63)), sp10);
                (*(s32 *)((char *)(arg0) + 0x24)) |= 0x200;
                goto block_60;
            }
            goto block_205;
        case 0xD:
            var_a0 = func_8009A70C(arg0, &D_800FDB9C);
            break;
        case 0xE:
            (*(s32 *)((char *)(arg0) + 0x24)) |= 0x10000;
            temp_s0 = (u16) D_800FDB9C;
            (*(s32 *)((char *)(arg0) + 0xA8)) = (s32) temp_s0;
            func_800957A8(arg0 + 0xA8);
            temp_v0_14 = D_800FDB9E << 0x10;
            temp_v1_8 = D_800FDBA3 << 0x10;
            (*(s32 *)((char *)(arg0) + 0x38)) = temp_v0_14;
            (*(s32 *)((char *)(arg0) + 0xAC)) = (s32) (temp_v1_8 + temp_v0_14);
            if ((*(s32 *)((char *)(arg0) + 0xA8)) != 0) {
                (*(u32 *)((char *)(arg0) + 0x3C)) = (u32) (temp_v1_8 / temp_s0);
            } else {
                (*(u32 *)((char *)(arg0) + 0x3C)) = temp_v1_8;
            }
            goto block_60;
        case 0xF:
            var_a2_3 = (*(s32 *)((char *)(arg0) + 0x30));
block_75:
            var_a0 = func_8009A804(arg0, &D_800FDB9C, var_a2_3);
            break;
        case 0x10:
            var_a0 = audioVoiceApplyEnvelope(arg0, &D_800FDB9C);
            break;
        case 0x11:
            func_8008C380((*(u8 *)((char *)(arg0) + 0x63)), 1);
            var_a0 = NULL;
            break;
        case 0x12:
            var_a0 = NULL;
            (*(s32 *)((char *)(arg0) + 0x24)) |= 0x80;
            break;
        case 0x13:
            if ((u32) (randomU16Next(var_a0) & 0xFF) >= (u8) D_800FDB9E) {
                temp_v0_15 = func_800982B4((u32) D_800FDB9C >> 0x10);
                var_a0 = NULL;
                if (temp_v0_15 != 0) {
                    (*(s32 *)((char *)(arg0) + 0)) = temp_v0_15;
                    (*(void **)((char *)(arg0) + 4)) = (void *) (temp_v0_15 + (D_800FDBA2 * 8));
                }
            } else {
                goto block_205;
            }
            break;
        case 0x14:
            var_a2_3 = 0;
            goto block_75;
        case 0x17:
            var_a0 = func_8009A990(arg0, &D_800FDB9C);
            break;
        case 0x18:
            var_a0 = func_8009A0E4(arg0, &D_800FDB9C);
            break;
        case 0x19:
            temp_v1_9 = (*(s32 *)((char *)(arg0) + 0x60));
            (*(u16 *)((char *)(arg0) + 0x50)) = (u16) (D_800FDB9E & 0x7F);
            (*(s8 *)((char *)(arg0) + 0xC0)) = (s8) (u16) D_800FDB9C;
            if (temp_v1_9 != -1) {
                temp_a1_2 = (*(u8 *)((char *)(arg0) + 0x4A));
                var_v0_2 = 0;
                if (temp_a1_2 != 0xFF) {
                    temp_v0_16 = (*(u8 *)((char *)(arg0) + 0x4B));
                    if (temp_v0_16 == 0xFF) {
                        var_v1_2 = temp_v1_9 & 0xFF;
                        var_v0_3 = *(D_80100C7C + var_v1_2);
                    } else {
                        var_v1_2 = *((temp_v0_16 * 0x10) + D_801007D9 + temp_a1_2);
                        var_v0_3 = temp_v1_9 & 0xFF;
                    }
                    var_v0_2 = 0;
                    if (var_v1_2 == var_v0_3) {
                        var_v0_2 = 1;
                    }
                }
            } else {
                var_v0_2 = 0;
            }
            if (var_v0_2 & 0xFF) {
                func_800968A4((*(u8 *)((char *)(arg0) + 0x4A)), (*(u8 *)((char *)(arg0) + 0x4B)), (*(u8 *)((char *)(arg0) + 0x51)));
            }
            D_800FDB9C = 4;
            goto block_120;
        case 0x1A:
            temp_v1_10 = (*(u8 *)((char *)(arg0) + 0xC1)) + ((s32) (D_800FDB9C << 0x10) >> 0x18);
            (*(u16 *)((char *)(arg0) + 0x50)) = temp_v1_10;
            if (!(temp_v1_10 & 0x8000)) {
                if ((u32) (temp_v1_10 & 0xFFFF) >= 0x80U) {
                    var_v1_3 = 0x7F;
                    goto block_95;
                }
                (*(u16 *)((char *)(arg0) + 0x50)) = temp_v1_10;
            } else {
                var_v1_3 = 0;
block_95:
                (*(u16 *)((char *)(arg0) + 0x50)) = var_v1_3;
            }
            temp_a0_3 = (*(u8 *)((char *)(arg0) + 0x4A));
            (*(s8 *)((char *)(arg0) + 0xC0)) = (s8) (u16) D_800FDB9C;
            if (temp_a0_3 != 0xFF) {
                func_800968A4(temp_a0_3, (*(u8 *)((char *)(arg0) + 0x4B)), (*(u8 *)((char *)(arg0) + 0x51)));
            }
            D_800FDB9C = 4;
            goto block_120;
        case 0x1B:
            (*(s8 *)((char *)(arg0) + 0x98)) = (s8) (u16) D_800FDB9C;
            sp10[0] = (u32) D_800FDBA0 >> 0x10;
            if (((u32) D_800FDBA0 >> 8) & 1) {
                func_800957A8(sp10);
            } else {
                func_800957B8(sp10, arg0);
            }
            (*(u32 *)((char *)(arg0) + 0x90)) = sp10[0];
            if (D_800FDB9E != 0) {
                var_a0 = NULL;
                if (D_800FDB9E != 1) {

                } else {
                    if (!((*(s32 *)((char *)(arg0) + 0x24)) & 0x800)) {
                        func_8008CE38(arg0);
                    }
                    (*(s32 *)((char *)(arg0) + 0x24)) |= 0x1800;
                    goto block_60;
                }
            } else {
                temp_a0_4 = (*(u8 *)((char *)(arg0) + 0x4A));
                (*(s32 *)((char *)(arg0) + 0x24)) = (s32) (((*(s32 *)((char *)(arg0) + 0x24)) & ~0x800) | 0x1000);
                if (temp_a0_4 != 0xFF) {
                    func_8009692C(temp_a0_4, (*(u8 *)((char *)(arg0) + 0x4B)), 0);
                    var_a0 = NULL;
                } else {
                    goto block_205;
                }
            }
            break;
        case 0x1C:
            var_a0 = audioApplyVoiceConfig(arg0, &D_800FDB9C);
            break;
        case 0x1D:
            (*(s32 *)((char *)(arg0) + 0x40)) = 0;
            temp_v0_17 = (u32) D_800FDB9C >> 8;
            (*(s8 *)((char *)(arg0) + 0x48)) = (s8) temp_v0_17;
            (*(s8 *)((char *)(arg0) + 0xB0)) = (s8) temp_v0_17;
            if ((s16) D_800FDB9C >= 0) {
                __repair_result_var_v0_4 = func_8008C7E0((s16) D_800FDB9C);
            } else {
                var_v0_4 = -func_8008C7E0(-(s16) D_800FDB9C);
            }
            (*(s32 *)((char *)(arg0) + 0x7C)) = (s32) (var_v0_4 << 0x10);
block_119:
            D_800FDB9C = 0;
            goto block_120;
        case 0x1E:
            (*(s32 *)((char *)(arg0) + 0x44)) = 0;
            temp_v0_18 = (u32) D_800FDB9C >> 8;
            (*(s8 *)((char *)(arg0) + 0x49)) = (s8) temp_v0_18;
            (*(s8 *)((char *)(arg0) + 0xB1)) = (s8) temp_v0_18;
            if ((s16) D_800FDB9C >= 0) {
                var_v0_5 = func_8008C7E0((s16) D_800FDB9C);
            } else {
                var_v0_5 = -func_8008C7E0(-(s16) D_800FDB9C);
            }
            (*(s32 *)((char *)(arg0) + 0x80)) = (s32) (var_v0_5 << 0x10);
            goto block_119;
        case 0x1F:
            var_a0 = func_8009A4E4(arg0, &D_800FDB9C);
            break;
        case 0x28:
            temp_v0_19 = func_800982B4((u32) (u16) D_800FDB9C);
            var_a0 = NULL;
            if (temp_v0_19 != 0) {
                (*(s32 *)((char *)(arg0) + 0x1C)) = temp_v0_19;
                (*(void **)((char *)(arg0) + 0x20)) = (void *) (temp_v0_19 + (D_800FDBA2 * 8));
            }
            break;
        case 0x29:
            var_a0 = NULL;
            (*(void **)((char *)(arg0) + 0x20)) = NULL;
            (*(s32 *)((char *)(arg0) + 0x1C)) = 0;
            break;
        case 0x30:
            temp_v1_11 = ((u32) (*(u32 *)((char *)(arg0) + 0x28)) >> 0xF) + (s16) D_800FDB9C;
            if (temp_v1_11 < 0) {
                (*(u32 *)((char *)(arg0) + 0x28)) = 0U;
            } else {
                if (temp_v1_11 > 0xFFFF) {
                    var_v0_6 = 0x7FFF8000;
                } else {
                    var_v0_6 = temp_v1_11 << 0xF;
                }
block_151:
                (*(u32 *)((char *)(arg0) + 0x28)) = var_v0_6;
            }
            goto block_60;
        case 0x31:
            var_a0 = NULL;
            (*(u32 *)((char *)(arg0) + 0x28)) = (u32) ((u16) D_800FDB9C << 0xF);
            break;
        case 0x32:
            *(s16 *)(D_80112EBE + (D_800FDB9E * 2)) = (s16) D_800FDB9D;
            var_a0 = NULL;
            break;
        case 0x33:
            (*(s8 *)((char *)(arg0) + 0x6A)) = (s8) (u16) D_800FDB9C;
            var_a0 = NULL;
            (*(s8 *)((char *)(arg0) + 0x6B)) = (s8) ((u32) D_800FDB9C >> 8);
            break;
        case 0x34:
            (*(s8 *)((char *)(arg0) + 0x99)) = (s8) ((u32) D_800FDB9C >> 8);
            var_a0 = NULL;
            (*(s8 *)((char *)(arg0) + 0x9A)) = (s8) (u16) D_800FDB9C;
            break;
        case 0x35:
            var_a0 = NULL;
            (*(s32 *)((char *)(arg0) + 0x24)) |= 0x40000;
            break;
        case 0x36:
            var_a1_3 = D_800FDB9E;
block_144:
            func_80098B14(arg0, var_a1_3);
            var_a0 = NULL;
            break;
        case 0x37:
            temp_v0_20 = (*(u8 *)((char *)(arg0) + 0x2E)) + (u16) D_800FDB9C;
            var_a1_4 = temp_v0_20;
            if (temp_v0_20 >= 0) {
                if (temp_v0_20 >= 0x100) {
                    var_a1_4 = 0xFF;
                }
            } else {
                var_a1_4 = 0;
            }
            var_a1_3 = var_a1_4 & 0xFF;
            goto block_144;
        case 0x38:
            if (D_800FDBA0 == 0) {
                (*(s16 *)((char *)(arg0) + 0x2C)) = 0;
            } else {
                (*(s16 *)((char *)(arg0) + 0x2C)) = (s16) ((u32) ((u32) (*(u32 *)((char *)(arg0) + 0x28)) >> 8) / (u32) D_800FDBA0);
            }
            goto block_60;
        case 0x39:
            temp_v1_12 = (u16) D_800FDB9C + ((u32) ((u16) (*(s32 *)((char *)(arg0) + 0x30)) * D_800FDBA2) >> 7);
            var_v0_6 = 0x75300000;
            if (temp_v1_12 <= 0xEA60U) {
                var_v0_6 = temp_v1_12 << 0xF;
            }
            goto block_151;
        case 0x40:
            temp_a0_5 = (*(s32 *)((char *)(arg0) + 0x24));
            temp_s2 = (u8) D_800FDBA3;
            if ((!(temp_a0_5 & 0x200000) | (temp_s2 == 0)) != 0) {
                (*(s32 *)((char *)(arg0) + 0x24)) = (s32) (temp_a0_5 | 0x200000);
                (*(u8 *)((char *)(arg0) + 0xD4)) = 0U;
            }
            temp_v1_13 = (*(u8 *)((char *)(arg0) + 0xD4));
            temp_s0_2 = temp_v1_13 & 0xFF;
            if (temp_s0_2 < 4U) {
                (*(u8 *)((char *)(arg0) + 0xD4)) = (u8) (temp_v1_13 + 1);
                temp_a0_6 = arg0 + 0xC4 + (temp_s0_2 * 4);
                (*(s8 *)((char *)(temp_a0_6) + 0)) = func_80096E1C(D_800FDB9E, 0x200000);
                (*(u8 *)((char *)(temp_a0_6) + 1)) = temp_s2;
                (*(s16 *)((char *)(temp_a0_6) + 2)) = (s16) (((s16) D_800FDB9C << 8) / 100);
            }
            goto block_60;
        case 0x41:
            temp_a0_7 = (*(s32 *)((char *)(arg0) + 0x24));
            temp_s2_2 = (u8) D_800FDBA3;
            if ((!(temp_a0_7 & 0x400000) | (temp_s2_2 == 0)) != 0) {
                (*(s32 *)((char *)(arg0) + 0x24)) = (s32) (temp_a0_7 | 0x400000);
                (*(u8 *)((char *)(arg0) + 0xE6)) = 0U;
            }
            temp_v1_14 = (*(u8 *)((char *)(arg0) + 0xE6));
            temp_s0_3 = temp_v1_14 & 0xFF;
            if (temp_s0_3 < 4U) {
                (*(u8 *)((char *)(arg0) + 0xE6)) = (u8) (temp_v1_14 + 1);
                temp_a0_8 = arg0 + 0xD6 + (temp_s0_3 * 4);
                (*(s8 *)((char *)(temp_a0_8) + 0)) = func_80096E1C(D_800FDB9E, 0x400000);
                (*(u8 *)((char *)(temp_a0_8) + 1)) = temp_s2_2;
                (*(s16 *)((char *)(temp_a0_8) + 2)) = (s16) (((s16) D_800FDB9C << 8) / 100);
            }
            goto block_60;
        case 0x42:
            temp_a0_9 = (*(s32 *)((char *)(arg0) + 0x24));
            temp_s2_3 = (u8) D_800FDBA3;
            if ((!(temp_a0_9 & 0x800000) | (temp_s2_3 == 0)) != 0) {
                (*(s32 *)((char *)(arg0) + 0x24)) = (s32) (temp_a0_9 | 0x800000);
                (*(u8 *)((char *)(arg0) + 0x10A)) = 0U;
            }
            temp_v1_15 = (*(u8 *)((char *)(arg0) + 0x10A));
            temp_s0_4 = temp_v1_15 & 0xFF;
            if (temp_s0_4 < 4U) {
                (*(u8 *)((char *)(arg0) + 0x10A)) = (u8) (temp_v1_15 + 1);
                temp_a0_10 = arg0 + 0xFA + (temp_s0_4 * 4);
                (*(s8 *)((char *)(temp_a0_10) + 0)) = func_80096E1C(D_800FDB9E, 0x800000);
                (*(u8 *)((char *)(temp_a0_10) + 1)) = temp_s2_3;
                (*(s16 *)((char *)(temp_a0_10) + 2)) = (s16) (((s16) D_800FDB9C << 8) / 100);
            }
            goto block_60;
        case 0x43:
            temp_a0_11 = (*(s32 *)((char *)(arg0) + 0x24));
            temp_s2_4 = (u8) D_800FDBA3;
            if ((!(temp_a0_11 & 0x01000000) | (temp_s2_4 == 0)) != 0) {
                (*(s32 *)((char *)(arg0) + 0x24)) = (s32) (temp_a0_11 | 0x01000000);
                (*(u8 *)((char *)(arg0) + 0x12E)) = 0U;
            }
            temp_v1_16 = (*(u8 *)((char *)(arg0) + 0x12E));
            temp_s0_5 = temp_v1_16 & 0xFF;
            if (temp_s0_5 < 4U) {
                (*(u8 *)((char *)(arg0) + 0x12E)) = (u8) (temp_v1_16 + 1);
                temp_a0_10 = arg0 + 0x11E + (temp_s0_5 * 4);
                (*(s8 *)((char *)(temp_a0_10) + 0)) = func_80096E1C(D_800FDB9E, 0x01000000);
                (*(u8 *)((char *)(temp_a0_10) + 1)) = temp_s2_4;
                (*(s16 *)((char *)(temp_a0_10) + 2)) = (s16) (((s16) D_800FDB9C << 8) / 100);
            }
            goto block_60;
        case 0x44:
            temp_a0_13 = (*(s32 *)((char *)(arg0) + 0x24));
            temp_s2_5 = (u8) D_800FDBA3;
            if ((!(temp_a0_13 & 0x08000000) | (temp_s2_5 == 0)) != 0) {
                (*(s32 *)((char *)(arg0) + 0x24)) = (s32) (temp_a0_13 | 0x08000000);
                (*(u8 *)((char *)(arg0) + 0x140)) = 0U;
            }
            temp_v1_17 = (*(u8 *)((char *)(arg0) + 0x140));
            temp_s0_6 = temp_v1_17 & 0xFF;
            if (temp_s0_6 < 4U) {
                (*(u8 *)((char *)(arg0) + 0x140)) = (u8) (temp_v1_17 + 1);
                temp_a0_14 = arg0 + 0x130 + (temp_s0_6 * 4);
                (*(s8 *)((char *)(temp_a0_14) + 0)) = func_80096E1C(D_800FDB9E, 0x08000000);
                (*(u8 *)((char *)(temp_a0_14) + 1)) = temp_s2_5;
                (*(s16 *)((char *)(temp_a0_14) + 2)) = (s16) (((s16) D_800FDB9C << 8) / 100);
            }
            goto block_60;
        case 0x45:
            temp_a0_15 = (*(s32 *)((char *)(arg0) + 0x24));
            temp_s2_6 = (u8) D_800FDBA3;
            if ((!(temp_a0_15 & 0x04000000) | (temp_s2_6 == 0)) != 0) {
                (*(s32 *)((char *)(arg0) + 0x24)) = (s32) (temp_a0_15 | 0x04000000);
                (*(u8 *)((char *)(arg0) + 0x152)) = 0U;
            }
            temp_v1_18 = (*(u8 *)((char *)(arg0) + 0x152));
            temp_s0_7 = temp_v1_18 & 0xFF;
            if (temp_s0_7 < 4U) {
                (*(u8 *)((char *)(arg0) + 0x152)) = (u8) (temp_v1_18 + 1);
                temp_a0_16 = arg0 + 0x142 + (temp_s0_7 * 4);
                (*(s8 *)((char *)(temp_a0_16) + 0)) = func_80096E1C(D_800FDB9E, 0x04000000);
                (*(u8 *)((char *)(temp_a0_16) + 1)) = temp_s2_6;
                (*(s16 *)((char *)(temp_a0_16) + 2)) = (s16) (((s16) D_800FDB9C << 8) / 100);
            }
            goto block_60;
        case 0x46:
            temp_a0_17 = (*(s32 *)((char *)(arg0) + 0x24));
            temp_s2_7 = (u8) D_800FDBA3;
            if ((!(temp_a0_17 & 0x02000000) | (temp_s2_7 == 0)) != 0) {
                (*(s32 *)((char *)(arg0) + 0x24)) = (s32) (temp_a0_17 | 0x02000000);
                (*(u8 *)((char *)(arg0) + 0x164)) = 0U;
            }
            temp_v1_19 = (*(u8 *)((char *)(arg0) + 0x164));
            temp_s0_8 = temp_v1_19 & 0xFF;
            if (temp_s0_8 < 4U) {
                (*(u8 *)((char *)(arg0) + 0x164)) = (u8) (temp_v1_19 + 1);
                temp_a0_18 = arg0 + 0x154 + (temp_s0_8 * 4);
                (*(s8 *)((char *)(temp_a0_18) + 0)) = func_80096E1C(D_800FDB9E, 0x02000000);
                (*(u8 *)((char *)(temp_a0_18) + 1)) = temp_s2_7;
                (*(s16 *)((char *)(temp_a0_18) + 2)) = (s16) (((s16) D_800FDB9C << 8) / 100);
            }
            goto block_60;
        case 0x47:
            temp_a0_19 = (*(s32 *)((char *)(arg0) + 0x24));
            temp_s2_8 = (u8) D_800FDBA3;
            if ((!(temp_a0_19 & 0x10000000) | (temp_s2_8 == 0)) != 0) {
                (*(s32 *)((char *)(arg0) + 0x24)) = (s32) (temp_a0_19 | 0x10000000);
                (*(u8 *)((char *)(arg0) + 0xF8)) = 0U;
            }
            temp_v1_20 = (*(u8 *)((char *)(arg0) + 0xF8));
            temp_s0_9 = temp_v1_20 & 0xFF;
            if (temp_s0_9 < 4U) {
                (*(u8 *)((char *)(arg0) + 0xF8)) = (u8) (temp_v1_20 + 1);
                temp_a0_20 = arg0 + 0xE8 + (temp_s0_9 * 4);
                (*(s8 *)((char *)(temp_a0_20) + 0)) = func_80096E1C(D_800FDB9E, 0x10000000);
                (*(u8 *)((char *)(temp_a0_20) + 1)) = temp_s2_8;
                (*(s16 *)((char *)(temp_a0_20) + 2)) = (s16) (((s16) D_800FDB9C << 8) / 100);
            }
            goto block_60;
        case 0x48:
            temp_a0_21 = (*(s32 *)((char *)(arg0) + 0x24));
            temp_s2_9 = (u8) D_800FDBA3;
            if ((!(temp_a0_21 & 0x20000000) | (temp_s2_9 == 0)) != 0) {
                (*(s32 *)((char *)(arg0) + 0x24)) = (s32) (temp_a0_21 | 0x20000000);
                (*(u8 *)((char *)(arg0) + 0x11C)) = 0U;
            }
            temp_v1_21 = (*(u8 *)((char *)(arg0) + 0x11C));
            temp_s0_10 = temp_v1_21 & 0xFF;
            if (temp_s0_10 < 4U) {
                (*(u8 *)((char *)(arg0) + 0x11C)) = (u8) (temp_v1_21 + 1);
                temp_a0_22 = arg0 + 0x10C + (temp_s0_10 * 4);
                (*(s8 *)((char *)(temp_a0_22) + 0)) = func_80096E1C(D_800FDB9E, 0x20000000);
                (*(u8 *)((char *)(temp_a0_22) + 1)) = temp_s2_9;
                (*(s16 *)((char *)(temp_a0_22) + 2)) = (s16) (((s16) D_800FDB9C << 8) / 100);
            }
            goto block_60;
        case 0x50:
            temp_s0_11 = (u32) D_800FDB9C >> 8;
            sp10[0] = (u32) D_800FDB9C >> 0x10;
            func_800957A8(sp10);
            temp_v1_22 = arg0 + ((temp_s0_11 & 0xFF) * 0xC);
            if ((*(u32 *)((char *)(temp_v1_22) + 0x16C)) != 0) {
                (*(s32 *)((char *)(temp_v1_22) + 0x168)) = 0;
            }
            var_a0 = NULL;
            (*(u32 *)((char *)(temp_v1_22) + 0x16C)) = sp10[0];
            break;
        case 0x60:
            var_a2_4 = 0;
block_196:
            var_a0 = func_8009ABD4(arg0, &D_800FDB9C, var_a2_4);
            break;
        case 0x61:
            var_a2_4 = 1;
            goto block_196;
        case 0x62:
            var_a2_4 = 2;
            goto block_196;
        case 0x63:
            var_a2_4 = 3;
            goto block_196;
        case 0x64:
            var_a2_4 = 4;
            goto block_196;
        case 0x65:
            temp_v1_23 = (u32) D_800FDB9C >> 0x10;
            if (((u32) D_800FDB9C >> 8) & 0xFF) {
                func_80096F44(arg0, temp_v1_23 & 0xFF, (s16) D_800FDBA0);
                var_a0 = NULL;
            } else {
                temp_v1_24 = temp_v1_23 & 0x1F;
                temp_v0_21 = temp_v1_24 * 2;
                if (temp_v1_24 < 0x10U) {
                    (*(s16 *)((char *)((temp_v0_21 + arg0)) + 0x180)) = (s16) D_800FDBA0;
                    goto block_60;
                }
                *(s16 *)(D_80112E9E + temp_v0_21) = (s16) D_800FDBA0;
                var_a0 = NULL;
            }
            break;
        case 0x70:
            var_a2_5 = 0;
block_204:
            var_a0 = func_8009AE24(arg0, &D_800FDB9C, var_a2_5);
            break;
        case 0x71:
            var_a2_5 = 1;
            goto block_204;
        }
        if (!((s32) var_a0 & 0xFF)) {
            temp_v0_22 = D_80100868 + 1;
            D_80100868 = temp_v0_22;
            if ((u32) (temp_v0_22 & 0xFF) < 0x21U) {
                goto loop_25;
            }
        }
        (*(u32 *)((char *)(arg0) + 0xA4)) += D_80109680;
        return;
    }
    temp_a0_23 = (*(s32 *)((char *)(arg0) + 0x24));
    (*(u32 *)((char *)(arg0) + 0xA4)) += D_80109680;
    if ((temp_a0_23 & 4) && !(temp_a0_23 & 0x40000000) && (temp_a0_23 & 8)) {
        (*(s32 *)((char *)(arg0) + 0x24)) = (s32) (temp_a0_23 & ~4);
        (*(u32 *)((char *)(arg0) + 0x9C)) = 0U;
        (*(u32 *)((char *)(arg0) + 0xA0)) = (u32) (*(u32 *)((char *)(arg0) + 0xA4));
    }
    if (((*(s32 *)((char *)(arg0) + 0x24)) & 0x100000) && !(audioVoiceIsActive((*(u8 *)((char *)(arg0) + 0x63))) & 0xFF)) {
        (*(u32 *)((char *)(arg0) + 0x9C)) = 0U;
        (*(s32 *)((char *)(arg0) + 0x24)) &= 0xFFEFFFFF;
        (*(u32 *)((char *)(arg0) + 0xA0)) = (u32) (*(u32 *)((char *)(arg0) + 0xA4));
    }
    temp_v1_25 = (*(u32 *)((char *)(arg0) + 0x9C));
    if ((temp_v1_25 != -1U) && ((u32) (*(u32 *)((char *)(arg0) + 0xA4)) >= temp_v1_25)) {
        (*(u32 *)((char *)(arg0) + 0xA0)) = temp_v1_25;
        (*(u32 *)((char *)(arg0) + 0x9C)) = 0U;
    }
}
