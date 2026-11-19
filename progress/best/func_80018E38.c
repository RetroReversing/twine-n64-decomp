/* machine draft (m2c) for gcc-2.7.2-kmc -G0 -mips3 -mgp32 -mfp32 -O2, tried by autopilot */

s32 func_8000A894();
s32 func_80026004();
s32 func_8002638C();
s32 func_80027A7C();
s32 func_80027C60();
s32 func_80027CE0();
s32 func_80029000();
s32 func_80029AC8();
void *func_80087100();
s32 func_800AB880();
s32 func_800AB950();
s32 func_800AB9B0();
s32 sprintf();
u16 strlen();
extern u16 D_800B60A4;
extern void *D_800BF5A0;
extern u8 D_801002AD;
extern void *D_80109BB0;
extern s32 func_8011AA9C;

extern char D_8011AB08[];
extern char D_800D285C[];
extern char D_800D2864[];
void func_80018E38(void) {
    u8 sp10[0x10];
    s32 temp_v1;
    unsigned long temp_v0;
    u8 *temp_v1_3;
    s32 var_a2;
    s8 *temp_s0;
    s8 *temp_s1;
    char *var_a1;
    s8 *var_s0;
    u16 var_v0;
    u8 sp20;
    u8 temp_v0_2;
    u8 temp_v1_2;
    
    void *temp_a1;
    void *temp_a3;
    
    void *var_a2_2;
    void *var_a3;

    if (D_800BF5A0 != NULL) {
        temp_a1 = (*(void **)((char *)(D_800BF5A0) + 0));
        temp_a3 = (*(void **)((char *)(D_800BF5A0) + 4));
        temp_s1 = (*(s8 **)((char *)((*(void **)((char *)(temp_a1) + 8))) + 0x18));
        temp_s0 = (D_801002AD * 0x18) + (&D_801002AD - 0x109);
        if (temp_a3 == temp_a1) {
            (*(void **)((char *)(D_800BF5A0) + 4)) = (void *) (temp_a3 + 0x28);
            sprintf(temp_s1, temp_s0, D_800BF5A0);
            D_800B60A4 = strlen(temp_s1);
        }
        func_80029AC8(D_80109BB0 + 0x2A, D_80109BB0 + 0x28, D_80109BB0 + 0x29);
        func_80029000((*(s32 *)((char *)(D_800BF5A0) + 8)));
        if (func_80027C60(0x24) & 0xFF) {
            sprintf(temp_s1, temp_s0);
            (*(s8 *)((char *)(D_800BF5A0) + 0xD)) = 0;
            goto block_40;
        }
        if (func_80027C60(0x2A) & 0xFF) {
            func_8000A894(0xE8);
            temp_v1 = (*(s32 *)((char *)((*(void **)((char *)(D_800BF5A0) + 4))) + 0x14));
            if (temp_v1 == 0x7D0) {
                sprintf(temp_s0, temp_s1);
block_40:
                temp_v0 = func_8002638C((*(s32 *)((char *)(D_80109BB0) + 0x10)), 0x65);
                if (temp_v0) {
                    func_80026004(temp_v0);
                }
                (*(s8 *)((char *)(D_800BF5A0) + 0xF)) = 1;
                func_8000A894(0xE8);
            } else {
                if (temp_v1 == 0x3E8) {
                    var_v0 = D_800B60A4 - 1;
                    if (D_800B60A4 == 0) {
                        func_8000A894(0xEA);
                    } else {
                        goto block_12;
                    }
                } else {
                    temp_s1[D_800B60A4] = (s8) temp_v1;
                    var_v0 = D_800B60A4 + 1;
block_12:
                    D_800B60A4 = var_v0;
                }
                if (D_800B60A4 == 9) {
                    func_8000A894(0xEA);
                    D_800B60A4 -= 1;
                }
                temp_s1[D_800B60A4] = 0;
                goto block_16;
            }
        } else {
block_16:
            if ((func_80027CE0(0x20) & 0xFF) && ((*(u8 *)((char *)(D_80109BB0) + 0x29)) != 0)) {
                func_8000A894(0xED);
                (*(void **)((char *)(D_800BF5A0) + 4)) = (void *) ((*(void **)((char *)(D_800BF5A0) + 0)) + ((*(s8 *)((char *)((*(void **)((char *)(D_800BF5A0) + 4))) + 0x24)) * 0x28));
            }
            if ((func_80027CE0(0x21) & 0xFF) && ((*(u8 *)((char *)(D_80109BB0) + 0x29)) != 0)) {
                func_8000A894(0xED);
                (*(void **)((char *)(D_800BF5A0) + 4)) = (void *) ((*(void **)((char *)(D_800BF5A0) + 0)) + ((*(s8 *)((char *)((*(void **)((char *)(D_800BF5A0) + 4))) + 0x25)) * 0x28));
            }
            if ((func_80027CE0(0x1E) & 0xFF) && ((*(u8 *)((char *)(D_80109BB0) + 0x29)) != 0)) {
                func_8000A894(0xED);
                (*(void **)((char *)(D_800BF5A0) + 4)) = (void *) ((*(void **)((char *)(D_800BF5A0) + 0)) + ((*(s8 *)((char *)((*(void **)((char *)(D_800BF5A0) + 4))) + 0x26)) * 0x28));
            }
            if ((func_80027CE0(0x1F) & 0xFF) && ((*(u8 *)((char *)(D_80109BB0) + 0x29)) != 0)) {
                func_8000A894(0xED);
                (*(void **)((char *)(D_800BF5A0) + 4)) = (void *) ((*(void **)((char *)(D_800BF5A0) + 0)) + ((*(s8 *)((char *)((*(void **)((char *)(D_800BF5A0) + 4))) + 0x27)) * 0x28));
            }
            var_s0 = (void *)(&func_8011AA9C); var_s0 = (void *)((char *)var_s0 + (s32)(0x6C));
            func_80027A7C((*(s32 *)((char *)(D_800BF5A0) + 8)), (*(void **)((char *)(D_800BF5A0) + 4)), 0);
            func_800AB880(sp10, temp_s1);
            func_800AB9B0(sp10);
            temp_v0_2 = (u8) (*(s8 *)((char *)(&func_8011AA9C) + 0x6C));
            var_a2 = 0;
            if ((*(s8 *)((char *)(&func_8011AA9C) + 0x6C)) != 0) {
                for (;;) {
                    sp20 = temp_v0_2;
                    if (temp_v0_2 != 0) {
                        var_a1 = var_s0;
                        __repair_rows: {
                            temp_v1_3 = &(&sp20)[var_a2];
                            temp_v0_2 = *temp_v1_3;
                            var_a1 += 1;/*__repair_loop_weight*/do {
                            ++var_a2;} while (0);
                            *temp_v1_3 = temp_v0_2 - 1;
                            temp_v1_2 = *(s8 *)var_a1;
                            (&sp20)[var_a2] = temp_v1_2;
                        }
if (temp_v1_2 != 0) goto __repair_rows;
                    }
                    if (func_800AB950(sp10, &sp20, var_a2) != 0) {
                        if ((u8) D_801002AD < 4U) {
                            var_a2_2 = func_80087100(0xAD);
                            var_a3 = D_801002AD + 1;

                        sprintf(temp_s1, D_800D285C, var_a2_2, var_a3);} else {
                            var_a2_2 = func_80087100(0x158);
                            var_a3 = D_801002AD - 3;

                        sprintf(temp_s1, D_800D2864, var_a2_2, var_a3);}
                        D_800B60A4 = strlen(temp_s1);
                    } else {
                        var_s0 = &(*(s8 *)((char *)(&var_s0[strlen(var_s0)]) + 1));
                        temp_v0_2 = (u8) *var_s0;
                        var_a2 = 0;
                        if (*var_s0 != 0) {
                            continue;
                        }
                    }
                    break;
                }
            }
            temp_a1 = (*(void **)((char *)((*(void **)((char *)(D_800BF5A0) + 0))) + 8));
            (*(u16 *)((char *)(temp_a1) + 0x1C)) = strlen(temp_s1);
        }
    }
}
