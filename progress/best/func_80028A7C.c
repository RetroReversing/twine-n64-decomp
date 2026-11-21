/* machine draft (m2c) for gcc-2.7.2-kmc -G0 -mips3 -mgp32 -mfp32 -O2, tried by autopilot */

s32 func_800269B4(void *, s32, s32);    /* extern */
s32 func_8002778C();                            /* extern */
s32 func_800278AC(s32, s32, s32);       /* extern */
s32 func_80027C60(s32);                         /* extern */
s32 func_8002FBD4(s32, s32);                /* extern */
s32 func_80030644(s32, s32);                /* extern */
extern s32 D_800BD8C4;
extern s32 gMenuSoundParams;
extern void *gSaveMenuState;
extern void *sActiveMenu;
extern s32 sSaveMenuColorIdle;
extern s32 sSaveMenuFlagsB;

void func_80028A7C(void) {
    s32 var_a0_2;
    s16 temp_v0_2;
    s16 temp_v0_4;
    s16 temp_v0_5;
    s16 temp_v1_2;
    s16 var_v0;
    s32 temp_v1_4;
    s32 var_a0;
    s32 var_a1;
    s32 var_a2;
    u16 temp_v0_3;
    u16 temp_v0_6;
    void *temp_v0;
    void *temp_v0_7;
    void *temp_v1;
    void *temp_v1_3;

    if (func_80027C60(0x24) & 0xFF) {
        func_80030644((*(s32 *)((char *)(gSaveMenuState) + 0x20)), 0xFF);
        (*(s32 **)((char *)(gSaveMenuState) + 0xC)) = &D_800BD8C4;
        func_800278AC(1, gMenuSoundParams, 0xA);
        func_8002FBD4((*(s32 *)((char *)(gSaveMenuState) + 0x20)), 4);
        func_800269B4(gSaveMenuState + 0x1C, 3, 0x2A);
        temp_v0 = (*(void **)((char *)(gSaveMenuState) + 0x1C));
        if (temp_v0 != NULL) {
            (*(s16 *)((char *)(temp_v0) + 0x26)) = 0;
            return;
        }
        return;
    }
    temp_v1 = (*(void **)((char *)(gSaveMenuState) + 0x1C));
    if (temp_v1 != NULL) {
        (*(s32 *)((char *)(temp_v1) + 0x10)) = (s32) (sSaveMenuFlagsB | 0xFF);
        (*(u16 *)((char *)((*(void **)((char *)(gSaveMenuState) + 0x1C))) + 0x22)) = (u16) (*(u16 *)((char *)(gSaveMenuState) + 0x32));
        (*(s16 *)((char *)((*(void **)((char *)(gSaveMenuState) + 0x1C))) + 0x20)) = 0;
        (*(s16 *)((char *)((*(void **)((char *)(gSaveMenuState) + 0x1C))) + 0x26)) = 0x140;
        (*(s8 *)((char *)((*(void **)((char *)(gSaveMenuState) + 0x1C))) + 0x29)) = 0x16;
        (*(s16 *)((char *)((*(void **)((char *)(gSaveMenuState) + 0x1C))) + 0x1E)) = 0x102;
    }
    temp_v1_2 = (*(s16 *)((char *)(sActiveMenu) + 0x7C));
    if (temp_v1_2 == 0) {
        var_a2 = 0;
        if ((u32) temp_v1_2 < (u8) (*(u8 *)((char *)((*(s32 **)((char *)(gSaveMenuState) + 0x10))) + 5))) {
            do {
                temp_v1_3 = ((var_a2 & 0xFFFF) * 0x28) + (*(s32 *)((char *)((*(s32 **)((char *)(gSaveMenuState) + 0x10))) + 0));
                if ((*(s32 *)((char *)(temp_v1_3) + 8)) != 0) {
                    temp_v0_2 = (*(u16 *)((char *)(gSaveMenuState) + 0x32)) - (*(u16 *)((char *)(temp_v1_3) + 0x1A));
                    var_a1 = 0;
                    if (temp_v0_2 <= 0) {
                        temp_v1_4 = temp_v0_2 * -0xE;
                        if (temp_v1_4 >= 0) {
                            var_a0 = 0xFF;
                            if (temp_v1_4 < 0x100) {
                                var_a0 = temp_v1_4;
                            }
                        } else {
                            var_a0 = 0;
                        }
                        var_a1 = var_a0;
                    }
                    (*(s32 *)((char *)((*(void **)((char *)((((var_a2 & 0xFFFF) * 0x28) + *(*(s32 **)((char *)(gSaveMenuState) + 0x10)))) + 8))) + 0x10)) = (s32) ((sSaveMenuColorIdle & ~0xFF) | (var_a1 & 0xFFFF));
                }
                var_a2 += 1;
            } while ((u32) (var_a2 & 0xFFFF) < (u8) (*(u8 *)((char *)((*(s32 **)((char *)(gSaveMenuState) + 0x10))) + 5)));
        }
        temp_v0_3 = (*(u16 *)((char *)(gSaveMenuState) + 0x32)) + 6;
        (*(u16 *)((char *)(gSaveMenuState) + 0x32)) = temp_v0_3;
        if ((u32) (temp_v0_3 & 0xFFFF) >= 0xF6U) {
            var_v0 = 1;
            if ((*(u16 *)((char *)(gSaveMenuState) + 0x14)) == 0x10) {
                var_v0 = 0x4B;
            }
            (*(s16 *)((char *)(sActiveMenu) + 0x7C)) = var_v0;
            goto block_24;
        }
    } else {
block_24:
        if ((u16) (*(u16 *)((char *)(gSaveMenuState) + 0x32)) >= 0xF6U) {
            temp_v0_4 = (*(s16 *)((char *)(sActiveMenu) + 0x7C));
            if (temp_v0_4 > 0) {
                temp_v0_5 = temp_v0_4 - 1;
                (*(s16 *)((char *)(sActiveMenu) + 0x7C)) = temp_v0_5;
                if ((temp_v0_5 << 0x10) == 0) {
                    temp_v0_6 = (*(u16 *)((char *)(gSaveMenuState) + 0x14));
                    switch (temp_v0_6) {
                    case 1:
                        var_a0_2 = 2;
block_44:
                        func_800278AC(var_a0_2, gMenuSoundParams & ~0xFF, 0x16);
                        break;
                    case 2:
                        var_a0_2 = 3;
                        {
                        func_800278AC(var_a0_2, gMenuSoundParams & ~0xFF, 0x16);break;}
                    case 3:
                        var_a0_2 = 4;
                        {
                        func_800278AC(var_a0_2, gMenuSoundParams & ~0xFF, 0x16);break;}
                    case 4:
                        var_a0_2 = 5;
                        {
                        func_800278AC(var_a0_2, gMenuSoundParams & ~0xFF, 0x16);break;}
                    case 5:
                        var_a0_2 = 6;
                        {
                        func_800278AC(var_a0_2, gMenuSoundParams & ~0xFF, 0x16);break;}
                    case 6:
                        var_a0_2 = 7;
                        {
                        func_800278AC(var_a0_2, gMenuSoundParams & ~0xFF, 0x16);break;}
                    case 7:
                        var_a0_2 = 8;
                        {
                        func_800278AC(var_a0_2, gMenuSoundParams & ~0xFF, 0x16);break;}
                    case 8:
                        var_a0_2 = 9;
                        {
                        func_800278AC(var_a0_2, gMenuSoundParams & ~0xFF, 0x16);break;}
                    case 9:
                        var_a0_2 = 0xA;
                        {
                        func_800278AC(var_a0_2, gMenuSoundParams & ~0xFF, 0x16);break;}
                    case 10:
                        var_a0_2 = 0xB;
                        goto block_44;
                    case 11:
                        var_a0_2 = 0xC;
                        goto block_44;
                    case 12:
                        var_a0_2 = 0xD;
                        goto block_44;
                    case 13:
                        var_a0_2 = 0xE;
                        goto block_44;
                    case 14:
                        var_a0_2 = 0xF;
                        goto block_44;
                    case 15:
                        var_a0_2 = 0x10;
                        goto block_44;
                    case 16:
                        func_80030644((*(s32 *)((char *)(gSaveMenuState) + 0x20)), 0xFF);
                        (*(s32 **)((char *)(gSaveMenuState) + 0xC)) = &D_800BD8C4;
                        func_800278AC(1, gMenuSoundParams, 0xA);
                        func_8002FBD4((*(s32 *)((char *)(gSaveMenuState) + 0x20)), 4);
                        func_800269B4(gSaveMenuState + 0x1C, 3, 0x2A);
                        temp_v0_7 = (*(void **)((char *)(gSaveMenuState) + 0x1C));
                        if (temp_v0_7 != NULL) {
                            (*(s16 *)((char *)(temp_v0_7) + 0x26)) = 0;
                        }
                        break;
                    }
                    (*(u16 *)((char *)(gSaveMenuState) + 0x32)) = 0U;
                    func_8002778C();
                }
            }
        }
    }
}
