/* machine draft (m2c) for gcc-2.7.2-kmc -G0 -mips3 -mgp32 -mfp32 -O2, tried by autopilot */

s32 applyEnemyKindMode(void *);                 /* extern */
s32 clearProbeState(void *, u16);               /* extern */
f32 cosTableLookup(f32);                            /* extern */
s32 func_80001660(void *, s8);                  /* extern */
s32 func_80001678(void *, s8);                  /* extern */
s32 func_80002EB8(void *);                      /* extern */
s32 func_80002EF0(void *, f32);                 /* extern */
void *func_8005F664(void *, s32, s8);           /* extern */
s32 func_800648FC(void *, s32);                 /* extern */
s32 func_80065BC4(void *);                      /* extern */
s32 func_80065C70(void *);           /* extern */
s32 func_80067390(void *);                      /* extern */
s32 func_8006832C(void *, void *);              /* extern */
s32 func_80070870(void *);           /* extern */
s32 func_8008194C(s8, s32);                     /* extern */
s32 func_80081D20(s8, s32);                 /* extern */
s32 listUnlinkFree(s32, s8);                    /* extern */
s32 requestSound(s32);           /* extern */
f32 sinTableLookup(f32);                            /* extern */
extern s32 D_800C46FC;
extern s32 gBorderSkipActive;
extern s32 sEnemyDefTable;
extern s32 sTrackMarkerTable;

void func_800673EC(void *arg0, void *arg1) {
    s32 *__base_sEnemyDefTable;
    f32 sp10[3];
    f32 temp_fs0;
    f32 temp_fs1;
    f32 temp_fs2;
    f32 temp_ft1;
    f32 temp_ft2;
    f32 temp_fv0;
    f32 temp_fv1;
    s32 temp_v1;
    
    s16 var_v1;
    s32 temp_a0_3;
    unsigned int temp_s5;
    unsigned long var_v0;
    s8 temp_s0;
    
    s8 temp_v1_6;
    s8 temp_v1_7;
    u16 temp_a1;
    u16 temp_a1_2;
    u16 temp_a1_3;
    void **temp_s0_2;
    void *temp_a0;
    
    void *temp_a0_4;
    void *temp_a0_5;
    void *temp_a0_6;
    void *temp_s1;
    void *temp_s1_2;
    register void *temp_s2;
    void *temp_v0;
    void *temp_v0_2;
    void *temp_v0_3;
    void *temp_v0_4;
    void *temp_v0_5;
    void *temp_v0_6;
    void *temp_v1_3;
    void *temp_v1_4;
    void *temp_v1_5;
    void *var_s4;

    temp_a0 = (*(void **)((char *)(arg0) + 0x68));
    temp_s2 = (*(void **)((char *)(arg0) + 0x6C));
    temp_s0 = (*(s8 *)((char *)(temp_s2) + 0x182));
    __base_sEnemyDefTable = &sEnemyDefTable;
    temp_s1 = (void *)(((*(s8 *)((char *)(temp_a0) + 0xE)) * 0xE8)); temp_s1 = (void *)((char *)temp_s1 + (s32)(__base_sEnemyDefTable));
    temp_v1 = (*(s16 *)((char *)((*(void **)((char *)(temp_s2) + 0xA8))) + 0x7A));
    var_s4 = (void *)(((*(s8 *)((char *)(temp_a0) + 0x10)) * 0xE8)); var_s4 = (void *)((char *)var_s4 + (s32)(__base_sEnemyDefTable));
    temp_s5 = (unsigned)gBorderSkipActive != 0;
    switch ((u32)temp_v1) {
    case 0:
    default:
        var_s4 = temp_s1;
        if ((*(s32 *)((char *)((*(void **)((char *)((*(void **)((char *)(temp_s2) + 0xA8))) + 0x68))) + 0x14)) & 0x10) {
            temp_a0 = (*(void **)((char *)(arg0) + 0x68));
            temp_s0 = (*(s8 *)((char *)(temp_a0) + 0xE));
            if ((*(s8 *)((char *)(temp_a0) + 0xF)) != temp_s0) {
                (*(s8 *)((char *)(temp_a0) + 0x10)) = temp_s0;
                temp_v1_3 = (*(void **)((char *)(arg0) + 0x68));
                (*(s8 *)((char *)(temp_v1_3) + 0xE)) = (s8) (u8) (*(s8 *)((char *)(temp_v1_3) + 0xF));
                temp_a0_3 = (*(s32 *)((char *)(temp_s2) + 8));
                if (temp_a0_3 != -1) {
                    listUnlinkFree(temp_a0_3, temp_s0);
                    (*(s32 *)((char *)(temp_s2) + 8)) = -1;
                }
                func_80067390(arg0);
                var_s4 = temp_s1;
            }
        }
        var_v0 = temp_s5 * 2;
        break;
    case 9:
        func_80065C70(arg0);
        var_s4 = temp_s1;
        if ((*(s16 *)((char *)((*(void **)((char *)((*(void **)((char *)(temp_s2) + 0xA8))) + 0x68))) + 0x94)) == 0x21) {
            func_8006832C(arg0, var_s4);
        }
        if ((*(s32 *)((char *)((*(void **)((char *)((*(void **)((char *)(temp_s2) + 0xA8))) + 0x68))) + 0x14)) & 0x10) {
            if ((func_800648FC(arg0, 1) << 0x18) != 0) {
                temp_v1 = 3;
            } else {
                (*(s16 *)((char *)((*(void **)((char *)(temp_s2) + 0xA8))) + 0x7A)) = 0;
                applyEnemyKindMode(arg0);
                temp_v1 = 3;
            }
block_48:
            (*(s16 *)((char *)((*(void **)((char *)(temp_s2) + 0xA8))) + 0x7A)) = temp_v1;
        }
        var_v0 = temp_s5 * 2;
        break;
    case 6:
    case 7:
        temp_v1_4 = (*(void **)((char *)(temp_s2) + 0xA8));
        var_s4 = temp_s1;
        if ((*(s32 *)((char *)((*(void **)((char *)(temp_v1_4) + 0x68))) + 0x14)) & 0x10) {
            (*(s16 *)((char *)(temp_v1_4) + 0x7A)) = 0;
        }
        var_v0 = temp_s5 * 2;
        break;
    case 5:
        var_s4 = temp_s1;
        if (((*(s32 *)((char *)((*(void **)((char *)((*(void **)((char *)(temp_s2) + 0xA8))) + 0x68))) + 0x14)) & 0x10) && (func_800648FC(arg0, 0), (*(s16 *)((char *)((*(void **)((char *)(temp_s2) + 0xA8))) + 0x7A)) = 0, (func_8008194C(temp_s0, 0xE) != 0))) {
            func_80081D20(temp_s0, 0xE);
            var_v0 = temp_s5 * 2;
        } else {
            var_v0 = temp_s5 * 2;
            break;
        }
        break;
    case 1:
    case 10:
        func_80065C70(arg0);
        /*__repair_pointer_balance*/if ((unsigned long)__base_sEnemyDefTable & 0x10000) {
if ((unsigned long)__base_sEnemyDefTable & 0x100) {
clearProbeState((*(void **)((char *)(temp_s2) + 0xA8)), (*(u16 *)((char *)(var_s4) + 0x9A)));
} else {
clearProbeState((*(void **)((char *)(temp_s2) + 0xA8)), (*(u16 *)((char *)(var_s4) + 0x9A)));
}
} else {
if ((unsigned long)__base_sEnemyDefTable & 0x100) {
clearProbeState((*(void **)((char *)(temp_s2) + 0xA8)), (*(u16 *)((char *)(var_s4) + 0x9A)));
} else {
clearProbeState((*(void **)((char *)(temp_s2) + 0xA8)), (*(u16 *)((char *)(var_s4) + 0x9A)));
}
}
        func_80001660(arg0, (*(s8 *)((char *)((*(void **)((char *)(arg0) + 0x68))) + 0x10)));
        temp_a0_4 = (*(void **)((char *)(temp_s2) + 0xA8));
        var_v1 = (*(s16 *)((char *)(temp_a0_4) + 0x7A));
        if ((int)var_v1 == 0xA) {
            (*(s16 *)((char *)(temp_a0_4) + 0x7A)) = 0xB;
            temp_v1 = (*(s16 *)((char *)((*(void **)((char *)(temp_s2) + 0xA8))) + 0x7A));
        }
        var_v0 = temp_s5 * 2;
        if ((unsigned)temp_v1 == 1) {
            (*(s16 *)((char *)((*(void **)((char *)(temp_s2) + 0xA8))) + 0x7A)) = 2;
            var_v0 = temp_s5 * 2;
            break;
        }
        break;
    case 2:
    case 11:
        temp_v1_5 = (*(void **)((char *)(temp_s2) + 0xA8));
        if ((*(s32 *)((char *)((*(void **)((char *)(temp_v1_5) + 0x68))) + 0x14)) & 0x10) {
            if ((*(s16 *)((char *)(temp_v1_5) + 0x7A)) == 0xB) {
                if (gBorderSkipActive == 0) {
                    temp_v0 = func_8005F664(arg0, 0, (*(s8 *)((char *)((*(void **)((char *)(arg0) + 0x68))) + 0x10)));
                    if (temp_v0 != NULL) {
                        temp_s0_2 = ((s32)temp_s0 * 4) + &sTrackMarkerTable;
                        temp_s1_2 = (*(void **)((char *)(temp_v0) + 0x6C));
                        temp_fs1 = sinTableLookup((*(f32 *)((char *)(*temp_s0_2) + 0x38)));
                        temp_fs2 = cosTableLookup((*(f32 *)((char *)(*temp_s0_2) + 0x38)));
                        temp_fs0 = sinTableLookup((*(f32 *)((char *)(*temp_s0_2) + 0x34)));
                        (*(f32 *)((char *)(temp_s1_2) + 0xC)) = (f32) (cosTableLookup((*(f32 *)((char *)(*temp_s0_2) + 0x34))) * temp_fs1);
                        temp_fv0 = cosTableLookup((*(f32 *)((char *)(*temp_s0_2) + 0x34))) * temp_fs2;
                        (*(s32 *)((char *)(temp_s1_2) + 0x18)) = 0x96;
                        (*(s8 *)((char *)(temp_s1_2) + 0x2D)) = 0;
                        (*(s8 *)((char *)(temp_s1_2) + 0x2F)) = 0;
                        (*(s16 *)((char *)(temp_s1_2) + 0x30)) = 0x384;
                        (*(f32 *)((char *)(temp_s1_2) + 0x10)) = (f32) -temp_fs0;
                        (*(f32 *)((char *)(temp_s1_2) + 0x14)) = temp_fv0;
                    }
                    (*(s8 *)((char *)((temp_s2 + ((*(s8 *)((char *)((*(void **)((char *)(arg0) + 0x68))) + 0x10)) * 8))) + 0x1FC)) = 0;
                } else if ((*(s8 *)((char *)((*(void **)((char *)(arg0) + 0x68))) + 0x10)) == 0x1B) {
                    (*(s8 *)((char *)(temp_s2) + 0x2D4)) = 0;
                }
            }
            (*(s16 *)((char *)((*(void **)((char *)(temp_s2) + 0xA8))) + 0x7A)) = 3;
        }
        temp_a0_5 = (*(void **)((char *)(arg0) + 0x68));
        temp_v1_6 = (*(s8 *)((char *)(temp_a0_5) + 0xF));
        if (temp_v1_6 != (*(s8 *)((char *)(temp_a0_5) + 0xE))) {
            (*(s8 *)((char *)(temp_a0_5) + 0xE)) = temp_v1_6;
        }
        var_v0 = temp_s5 * 2;
        break;
    case 3:
        func_80070870(arg0);
        var_s4 = temp_s1;
        func_80001678(arg0, (*(s8 *)((char *)((*(void **)((char *)(arg0) + 0x68))) + 0xE)));
        temp_a1 = (*(u16 *)((char *)(var_s4) + 0x98));
        if ((s32)temp_a1 != 0) {
            clearProbeState((*(void **)((char *)(temp_s2) + 0xA8)), temp_a1);
            temp_v1 = 4;
            goto block_48;
        }
        temp_a1_2 = (*(u16 *)((char *)(var_s4) + 0x92));
        if (temp_a1_2) {
            clearProbeState((*(void **)((char *)(temp_s2) + 0xA8)), temp_a1_2);
            temp_v1 = 4;
            goto block_48;
        }
        (*(s16 *)((char *)((*(void **)((char *)(temp_s2) + 0xA8))) + 0x7A)) = 0;
        var_v0 = temp_s5 * 2;
        break;
    case 8:
        var_s4 = temp_s1;
        func_80001678(arg0, (*(s8 *)((char *)((*(void **)((char *)(arg0) + 0x68))) + 0x10)));
        if ((*(u16 *)((char *)(var_s4) + 0x98)) != 0) {
            func_80002EB8((*(void **)((char *)(temp_s2) + 0xA8)));
            temp_v1 = 2;
            goto block_48;
        }
        temp_a1_3 = (*(u16 *)((char *)(var_s4) + 0x92));
        if (temp_a1_3 != 0) {
            clearProbeState((*(void **)((char *)(temp_s2) + 0xA8)), temp_a1_3);
            temp_v1 = 2;
            goto block_48;
        }
        (*(s16 *)((char *)((*(void **)((char *)(temp_s2) + 0xA8))) + 0x7A)) = 0;
        var_v0 = temp_s5 * 2;
        break;
        var_v0 = temp_s5 * 2;
        break;
    case 4:
        var_s4 = temp_s1;
        if ((*(s32 *)((char *)((*(void **)((char *)((*(void **)((char *)(temp_s2) + 0xA8))) + 0x68))) + 0x14)) & 0x10) {
            if (*((s32 *)((s8 *)&D_800C46FC + ((*(s8 *)((char *)((*(void **)((char *)(arg0) + 0x68))) + 0xE)) * 0xE8))) & 4) {
                requestSound(0x1DF);
            }
            (*(s16 *)((char *)(temp_s2) + 0x178)) = 0;
            (*(s16 *)((char *)((*(void **)((char *)(temp_s2) + 0xA8))) + 0x7A)) = 0;
            func_80065BC4(arg0);
        }
        temp_a0_6 = (*(void **)((char *)(arg0) + 0x68));
        temp_v1_7 = (*(s8 *)((char *)(temp_a0_6) + 0xE));
        if ((*(s8 *)((char *)(temp_a0_6) + 0xF)) != temp_v1_7) {
            (*(s8 *)((char *)(temp_a0_6) + 0x10)) = temp_v1_7;
            temp_v1 = 8;
            goto block_48;
        }
        var_v0 = temp_s5 * 2;
        break;
    }
    temp_v0_2 = (void *) ((((var_v0 + temp_s5) * 4)) + (s32) var_s4);
    sp10[0] = (*(f32 *)((char *)(temp_v0_2) + 0xA0));
    sp10[1] = (*(f32 *)((char *)(temp_v0_2) + 0xA4));
    sp10[2] = (*(f32 *)((char *)(temp_v0_2) + 0xA8));
    if (!temp_s5) {
        temp_fv1 = (*(f32 *)((char *)(*((s32 *)((s8 *)&sTrackMarkerTable + ((*(s8 *)((char *)(temp_s2) + 0x182)) * 4)))) + 0x130));
        if (temp_fv1 > 0.0f) {
            temp_ft2 = temp_fv1 * 2.5f;
            temp_ft1 = 1.0f - temp_ft2;
            sp10[0] = (sp10[0] * temp_ft1) + ((*(f32 *)((char *)(var_s4) + 0xAC)) * temp_ft2);
            sp10[1] = (sp10[1] * temp_ft1) + ((*(f32 *)((char *)(var_s4) + 0xB0)) * temp_ft2);
            sp10[2] = (sp10[2] * temp_ft1) + ((*(f32 *)((char *)(var_s4) + 0xB4)) * temp_ft2);
        }
    }
    temp_v0_3 = (*(void **)((char *)(temp_s2) + 0xA8));
    (*(f32 *)((char *)(temp_v0_3) + 0x24)) = sp10[0];
    (*(f32 *)((char *)(temp_v0_3) + 0x28)) = sp10[1];
    (*(f32 *)((char *)(temp_v0_3) + 0x2C)) = sp10[2];
    temp_v0_4 = (*(void **)((char *)(temp_s2) + 0xA8));
    (*(f32 *)((char *)(temp_v0_4) + 0x24)) = (f32) ((*(f32 *)((char *)(temp_v0_4) + 0x24)) + (*(f32 *)((char *)(arg1) + 0)));
    temp_v0_5 = (*(void **)((char *)(temp_s2) + 0xA8));
    (*(f32 *)((char *)(temp_v0_5) + 0x28)) = (f32) ((*(f32 *)((char *)(temp_v0_5) + 0x28)) + (*(f32 *)((char *)(arg1) + 4)));
    temp_v0_6 = (*(void **)((char *)(temp_s2) + 0xA8));
    (*(f32 *)((char *)(temp_v0_6) + 0x2C)) = (f32) ((*(f32 *)((char *)(temp_v0_6) + 0x2C)) + (*(f32 *)((char *)(arg1) + 8)));
    func_80002EF0((*(void **)((char *)(temp_s2) + 0xA8)), sp10[2]);
}
