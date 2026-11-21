/* machine draft (m2c) for gcc-2.7.2-kmc -G0 -mips3 -mgp32 -mfp32 -O2, tried by autopilot */

extern unsigned short D_800BD55C;
extern unsigned short D_800BD55E;
s32 func_8001F064();
s32 func_8001F08C();
s32 func_80024D78();
void func_8002778C();
s32 func_800277E4();
s32 func_800278AC();
s32 func_8002AD60();
s32 func_8002AEC8();
s32 func_8002AF30();
s32 func_8002CBF4();
s32 func_8002CC14();
s16 func_8002CC54();
s16 func_8002D218();
s32 func_80030644();
s16 strlen();
extern char D_800B91D0[];
extern char D_800B93B0[];
extern char D_800B97C0[];
extern char D_800B99F0[];
extern char D_800B9C20[];
extern char D_800B9DB0[];
extern char D_800B9F40[];
extern char D_800B9FB8[];
extern char D_800BA3F0[];
extern char D_800BA5D0[];
extern char D_800BA7B0[];
extern char D_800BA990[];
extern char D_800BAB98[];
extern char D_800BAD78[];
extern char D_800BAFF8[];
extern char D_800BB1D8[];
extern char D_800BB458[];
extern char D_800BB6D8[];
extern char D_800BB908[];
extern char D_800BBB88[];
extern char D_800BBEA8[];
extern char D_800BC1C8[];
extern char D_800BCD80[];
extern char D_800BCF60[];
extern char D_800BD140[];
extern char D_800BD320[];
extern s16 D_800BD560;
extern u16 D_800BD68C;
extern s8 D_800BD690;
extern s16 gSaveStatus;
extern s16 D_800BFC34;
extern u8 gSaveKeyRelaxed;
extern u16 D_80100910;
extern s32 D_80102EBC;
extern s8 D_80102EDC;
extern s8 D_80102F04;
extern void *D_80109BB0;
extern s16 D_80109DD0;
extern char D_8010A950[];

typedef struct { void * field_0; unsigned char pad_4[16]; unsigned short field_14; unsigned char pad_16[10]; int field_20; } __repair_record_D_80109BB0;
s32 func_8002502C(s16 *arg0, s32 arg1) {
    char *var_a1_2;
    long var_a2_3;
    s32 var_a0;
    s32 var_a2;
    s32 var_a2_2;
    char *var_a1_3;
    s32 var_a3;
    s16 var_a1;
    s32 var_a1_5;
    s32 temp_v0;
    unsigned long temp_v0_2;
    s32 var_a1_4;
    s32 temp_a0;
    u32 var_a1_6;
    s32 var_s0;
    s32 var_v0;
    s32 temp_s0;
    void *temp_s0_2;
    s32 temp_v1_2;
    s32 temp_v1_3;
    u16 var_v0_2;
    s32 temp_v1;

    switch ((s32)D_800BD55C) {
    case 0:
            D_800BD690 = 0;
            D_800BD55E = 0U;
            D_800BD55C = 2U;
            D_800BD560 = arg1;
            if (arg0 != NULL) {
                do {*arg0 = 0;}while(0);
            }
            func_8002778C(arg1);
            switch ((s16)arg1) {
            case 0:
                        D_800BD55C = 0U;
                        func_800277E4(-(((u16) D_800BD68C >= 0xAU) & (D_800BD68C != 0x13)) & 0xFF);
                        var_v0 = 0xFF;
                        if ((((__repair_record_D_80109BB0*)D_80109BB0)->field_14) == 0x19) {
                            func_800277E4(0xFF);
                            return 0xFF;
                        }
                        /* Duplicate return node #185. Try simplifying control flow for better match */
                        return var_v0;
            case 1:
                        func_800277E4(0xFF);
                        var_a1_2 = D_800BA7B0;
                        var_a2 = 0xC;
                        var_a3 = 1;
                        {
                func_8002AD60(D_8010A950, var_a1_2, var_a2, var_a3);return 2;}
            case 3:
                        func_800277E4(0xFF);
                        var_a1_2 = D_800BA5D0;
                        var_a2 = 0xC;
                        var_a3 = 1;
                        {
                func_8002AD60(D_8010A950, var_a1_2, var_a2, var_a3);return 2;}
            case 4:
                        func_800277E4(0xFF);
                        var_a1_2 = D_800BAB98;
                        var_a2 = 0xC;
                        var_a3 = 1;
                        {
                func_8002AD60(D_8010A950, var_a1_2, var_a2, var_a3);return 2;}
            case 34:
                        var_a1_2 = D_800BAFF8;
                        var_a2 = 0xC;
                        var_a3 = 1;
                        {
                func_8002AD60(D_8010A950, var_a1_2, var_a2, var_a3);return 2;}
            case 15:
                        var_a1_2 = D_800B93B0;
                        var_a2 = 0xE;
                        func_8002AD60(D_8010A950, var_a1_2, var_a2, 0);
                        return 2;
            case 99:
                        var_a1_2 = D_800BB6D8;
                        var_a2 = 0xE;
                        var_a3 = 0;
                        {
                func_8002AD60(D_8010A950, var_a1_2, var_a2, var_a3);return 2;}
            case 98:
                        D_800BD55E = 3U;
                        var_a1_2 = D_800BB458;
                        var_a2 = 0x10;
                        func_8002AD60(D_8010A950, var_a1_2, var_a2, 0);
                        return 2;
            case 16:
                        var_a2_2 = 0xE;
                        if ((((u16) D_800BD68C < 0xAU) | (D_800BD68C == 0x13)) != 0) {
                            D_800BD560 = 0xF;
                            var_a1_3 = D_800B93B0;
                        
                        func_8002AD60(D_8010A950, var_a1_3, var_a2_2, 0);} else {
                            var_a1_3 = D_800B91D0;
                            var_a2_2 = 0xC;
                        
                        func_8002AD60(D_8010A950, var_a1_3, var_a2_2, 0);}
                        D_800BD55E = 3U;
                        return 2;
            case 64:
                var_a1_2 = D_800B9C20;
                var_a2 = 0xA;
                var_a3 = 1;
                return (func_8002AD60(D_8010A950, var_a1_2, var_a2, var_a3), 2);
            case 65:
                        var_a1_2 = D_800B9DB0;
                        var_a2 = 0xA;
                        var_a3 = 1;
                        {
                func_8002AD60(D_8010A950, var_a1_2, var_a2, var_a3);return 2;}
            case 48:
                        var_a1_2 = D_800B9FB8;
                        var_a2 = 0xE;
                        func_8002AD60(D_8010A950, var_a1_2, var_a2, 0);
                        return 2;
            case 148:
                        D_800BD55C = 0U;
                        if ((D_800BD68C < 0xAU) | (D_800BD68C == 0x13)) {
                            func_800278AC(0x19, D_80102EBC, 0x13);
                        } else {
                            func_800278AC(0x1B, D_80102EBC, 0xA);
                        }
                        return 0x80;
            case 96:
                        func_80030644((((__repair_record_D_80109BB0*)D_80109BB0)->field_20), 0x80, 0xA, 1);
                        var_a1_2 = D_800B9F40;
                        var_a2 = 3;
                        func_8002AD60(D_8010A950, var_a1_2, var_a2, 0);
                        return 2;
            case 18:
                        var_a1_2 = D_800BA3F0;
                        var_a2 = 0xC;
                        func_8002AD60(D_8010A950, var_a1_2, var_a2, 0);
                        return 2;
            case 33:
                        var_a1_2 = D_800BB1D8;
                        var_a2 = 0x10;
                        func_8002AD60(D_8010A950, var_a1_2, var_a2, 0);
                        return 2;
            case 37:
                        var_a1_2 = D_800BB908;
                        var_a2 = 0x10;
                        func_8002AD60(D_8010A950, var_a1_2, var_a2, 0);
                        return 2;
            case 32:
                        D_800BD55E = 3U;
                        var_a1_2 = D_800BAD78;
                        var_a2 = 0x10;
                        func_8002AD60(D_8010A950, var_a1_2, var_a2, 0);
                        return 2;
            case 36:
                func_8002AD60(D_8010A950, D_800BA990, 0xD, 1);
                return 2;
            case 264:
                        D_800BD690 = 1;
                        var_a1_2 = D_800BBB88;
                        var_a2 = 0x14;
                        var_a3 = 1;
                        {
                func_8002AD60(D_8010A950, var_a1_2, var_a2, var_a3);return 2;}
            case 265:
                        D_800BD690 = 1;
                        var_a1_2 = D_800BBEA8;
                        var_a2 = 0x14;
                        var_a3 = 1;
                        {
                func_8002AD60(D_8010A950, var_a1_2, var_a2, var_a3);return 2;}
            case 266:
                        D_800BD690 = 1;
                        func_800277E4(0xFF);
                        var_a1_2 = D_800BC1C8;
                        var_a2 = 0x4B;
                        var_a3 = 1;
                        return (func_8002AD60(D_8010A950, var_a1_2, var_a2, var_a3), 2);
            case 267:
                        D_800BD690 = 1;
                        var_a1_2 = D_800BCD80;
                        var_a2 = 0xC;
                        var_a3 = 1;
                        return (func_8002AD60(D_8010A950, var_a1_2, var_a2, var_a3), 2);
            case 268:
                        D_800BD690 = 1;
                        var_a2 = 0xC;
                        if (gSaveKeyRelaxed == 1) {
                            func_8002AD60(D_8010A950, D_800BCF60, 0xC, 1);
                        } else {
                            func_8002AD60(D_8010A950, D_800BD140, 0xC, 1);
                        }
                        return 2;
            case 269:
                        func_800277E4(0xFF);
                        var_a1_2 = D_800B99F0;
                        var_a2 = 0xE;
                        func_8002AD60(D_8010A950, var_a1_2, var_a2, 0);
                        return 2;
            case 270:
                        func_800277E4(0xFF);
                        var_a1_2 = D_800B97C0;
                        var_a2 = 0xE;
                        func_8002AD60(D_8010A950, var_a1_2, var_a2, 0);
                        return 2;
            case 273:
                        D_800BD690 = 1;
                        var_a1_2 = D_800BD320;
                        var_a2 = 0xE;
                        func_8002AD60(D_8010A950, var_a1_2, var_a2, 0);
                        return 2;

            default:
                            func_800277E4(0xFF);
                            D_800BD55C = 0U;
                            if (arg0 != NULL) {
                                *arg0 = 0;
                                goto block_184;
                            }
                            return 0xFF;
            }
            case 0x2:                               /* switch 1 */
                D_80102EDC = 0;
                if ((func_8002AEC8(D_8010A950) & 0xFF) == 1) {
                    return 2;
                }
                if (arg0 != NULL) {
                    *arg0 = func_8002AF30(D_8010A950) & 0xFF;
                }
                D_800BD690 = 1;
                D_800BD55C = 1U;
                return 1;
    case 1:
        var_v0_2 = 0xFF;
        if (D_800BD55E != 0) {
            D_800BD55E--;
            var_v0_2 = 1;
        }
        D_800BD55C = var_v0_2;
        return 1;
            case 0xFF:                              /* switch 1 */
                func_800277E4(-(((u16) D_800BD68C >= 0xAU) & (D_800BD68C != (unsigned short)0x13)) & 0xFF);
                temp_s0 = (u16) D_800BD560;
                D_800BD55C = 0U;
                switch (temp_s0) {
                case 0x12:
                case 0x22:
                            var_s0 = func_8002CBF4();
                            if (D_80109DD0 != 0) {
                                temp_v0 = var_s0 & 0xFFFF;
                                if ((((s32)temp_v0 == 0) | (temp_v0 == 0x30)) != 0) {
                                    var_s0 = 0x94;
                                }
                            }
                            func_80024D78();
                            func_800277E4(-(((u16) D_800BD68C >= 0xAU) & (D_800BD68C != 0x13)) & (s32)0xFF);
                            var_a1_5 = var_s0 << 0x10;
                            {var_a1 = (s16) (var_a1_5 >> 0x10);
                        return func_8002502C(arg0, (s32) var_a1) & 0xFFFF;}
                        case 0x30:                  /* switch 5 */
                            if (D_80100910 == 1) {
                                func_8002778C();
                                func_8002CC14();
                                if (((func_8002D218() << 0x10) == 0) || (var_v0 = 0x80, (func_8002D218() == temp_s0))) {
                                    if ((D_800BD68C < 0xAU) | (D_800BD68C == 0x13)) {
                            func_800278AC(0x19, D_80102EBC, 0x13);
                        } else {
                            func_800278AC(0x1B, D_80102EBC, 0xA);
                        }
                        return 0x80;
                                }
                                /* Duplicate return node #185. Try simplifying control flow for better match */
                                return var_v0;
                            }
                            var_v0 = 0xFF;
                            if (D_800BFC34 != 0) {
                                func_8002778C();
                                temp_v1_2 = (((__repair_record_D_80109BB0*)D_80109BB0)->field_14);
                                gSaveStatus = 0;
                                if (temp_v1_2 == 0x19) goto sound_zero_1;
                            if (temp_v1_2 == 0x1A) goto sound_ten_1;
                            func_800278AC(1, D_80102EBC, 0xA);
                            return 0x80;
sound_zero_1:
                            func_800278AC(0, 0, 0x12);
                            return 0x80;
sound_ten_1:
                            func_800278AC(0x10, D_80102EBC, 0xA);
                            return 0x80;
                            }
                            /* Duplicate return node #185. Try simplifying control flow for better match */
                            return var_v0;
                        case 0x60:                  /* switch 5 */
                            func_8002778C();
                            func_8002CBF4();
                            return 0xFF;
                                case 15:            /* switch 4 */
                                    if (D_80100910 != 2) {
                                        temp_s0_2 = (((__repair_record_D_80109BB0*)D_80109BB0)->field_0);
                                        temp_a0 = (*(s32 *)((char *)(temp_s0_2) + 0x18));
                                        D_800BD68C = 2;
                                        if (temp_a0 != 0) {
                                            (*(s16 *)((char *)(temp_s0_2) + 0x1C)) = strlen((s32)temp_a0);
block_184:
                                        }
                                        var_v0 = 0xFF;
                                        /* Duplicate return node #185. Try simplifying control flow for better match */
                                        return var_v0;
                                    }
                                    goto block_159;
                case 0x20:
                case 0x21:
                case 0x25:
                case 0x62:
                case 0x63:
                    switch (D_80100910) {           /* switch 6; irregular */
                    case 1:                         /* switch 6 */
                        var_a1 = func_8002CC54();
                        return func_8002502C(arg0, (s32) var_a1) & 0xFFFF;
                    case 2:                         /* switch 6 */
block_159:
                        var_a1_6 = func_8002CBF4();
                        if (D_80109DD0 != 0) {
                            temp_v0_2 = var_a1_6 & 0xFFFF;
                            if (((temp_v0_2 == 0) | (temp_v0_2 == 0x30)) != 0) {
                                var_a1_6 = 0x94;
                            }
                        }
                        var_a1_5 = var_a1_6 << 0x10;
block_163:
                        var_a1 = (s16) (var_a1_5 >> 0x10);
                        return func_8002502C(arg0, (s32) var_a1) & 0xFFFF;
                    default:                        /* switch 6 */
                        var_v0 = 0xFF;
                        if (D_800BFC34 != 0) {
                            func_8002778C();
                            temp_v1_3 = (((__repair_record_D_80109BB0*)D_80109BB0)->field_14);
                            gSaveStatus = 0;
                            if (temp_v1_3 == 0x19) goto sound_zero_2;
                            if (temp_v1_3 == 0x1A) goto sound_ten_2;
                            func_800278AC(1, D_80102EBC, 0xA);
                            return 0x80;
sound_zero_2:
                            func_800278AC(0, 0, 0x12);
                            return 0x80;
sound_ten_2:
                            func_800278AC(0x10, D_80102EBC, 0xA);
                            return 0x80;
                        }
                        return var_v0;
                    }
                                case 16:            /* switch 4 */
                                    var_v0 = 0xFF;
                                    if (D_800BFC34 != 0) {
                                        func_8002778C();
                                        temp_v1 = (((__repair_record_D_80109BB0*)D_80109BB0)->field_14);
                                        gSaveStatus = 0;
                                        if (temp_v1 == 0x19) goto sound_zero_3;
                            if (temp_v1 == 0x1A) goto sound_ten_3;
                            func_800278AC(1, D_80102EBC, 0xA);
                            return 0x80;
sound_zero_3:
                            func_800278AC(0, 0, 0x12);
                            return 0x80;
sound_ten_3:
                            func_800278AC(0x10, D_80102EBC, 0xA);
                            return 0x80;
                                    }
                                    /* Duplicate return node #185. Try simplifying control flow for better match */
                                    return var_v0;
                case 0x108:
                                var_v0 = 0xFF;
                                if (D_80100910 == 1) {
                                    func_8002778C();
                                    func_8001F064();
                                    return 0xFF;
                                }
                                /* Duplicate return node #185. Try simplifying control flow for better match */
                                return var_v0;
                case 0x109:
                        var_v0 = 0xFF;
                        if (D_80100910 == 1) {
                            func_8002778C();
                            func_8001F08C();
                            return 0xFF;
                        }
                        /* Duplicate return node #185. Try simplifying control flow for better match */
                        return var_v0;
                case 0x111:
                            var_v0 = 0xFF;
                            if (D_80100910 == 1) {
                                func_8002778C();
                                var_a1_4 = D_80102EBC;
                                var_a0 = 1;
                                var_a2_3 = 0xA;
                                D_80102F04 = 0;
                                func_800278AC(var_a0, var_a1_4, var_a2_3);
                                return 0x80;
                            }
                            /* Duplicate return node #185. Try simplifying control flow for better match */
                            return var_v0;
                default:
                    return 0xFF;
                }
    default:
        return 0xFF;
    }
}
