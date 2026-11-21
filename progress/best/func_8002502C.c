/* machine draft (m2c) for gcc-2.7.2-kmc -G0 -mips3 -mgp32 -mfp32 -O2, tried by autopilot */

extern unsigned short D_800BD55C;
extern unsigned short D_800BD55E;
s32 func_8001F064();
s32 func_8001F08C();
s32 refreshSlotMenuLabels();
s32 func_8002778C();
s32 func_800277E4();
s32 func_800278AC();
s32 voiceGroupInit();
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
extern s32 gMenuSoundParams;
extern s8 D_80102EDC;
extern s8 D_80102F04;
extern void *gMenuState;
extern s16 D_80109DD0;
extern char D_8010A950[];

s32 func_8002502C(s16 *arg0, s32 arg1) {
    s32 *var_a1_2;
    long var_a2_3;
    s32 var_a0;
    s32 var_a2;
    s32 var_a2_2;
    s32 *var_a1_3;
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
    u16 temp_v1_2;
    s32 temp_v1_3;
    u16 var_v0_2;
    u16 temp_v1;

    if (D_800BD55C != 1) {
        if ((s32) D_800BD55C < 2) {
            if (D_800BD55C) {
                return 0xFF;
            }
            D_800BD690 = 0;
            D_800BD55E = 0U;
            D_800BD55C = 2U;
            D_800BD560 = arg1;
            if (arg0 != NULL) {
                *arg0 = 0;
            }
            func_8002778C(arg1);
            if (arg1 != 0x40) {
                if (arg1 < 0x41) {
                    switch (arg1) {                 /* switch 2; irregular */
                    default:                        /* switch 2 */
                        var_a2 = 0xD;
                        if ((u32)arg1 != 0x24) {
                            func_800277E4(0xFF);
                            D_800BD55C = 0U;
                            if (arg0 != NULL) {
                                *arg0 = 0;
                                goto block_184;
                            }
                            return 0xFF;
                        }
                        var_a1_2 = D_800BA990;
                        var_a3 = 1;
                        {
                voiceGroupInit(D_8010A950);return 2;}
                    case 0:                         /* switch 2 */
                        D_800BD55C = 0U;
                        func_800277E4(-(((u16) D_800BD68C >= 0xAU) & (D_800BD68C != 0x13)) & 0xFF);
                        var_v0 = 0xFF;
                        if ((*(u16 *)((char *)(gMenuState) + 0x14)) == 0x19) {
                            func_800277E4(0xFF);
                            return 0xFF;
                        }
                        /* Duplicate return node #185. Try simplifying control flow for better match */
                        return var_v0;
                    case 1:                         /* switch 2 */
                        func_800277E4(0xFF);
                        var_a1_2 = D_800BA7B0;
                        var_a2 = 0xC;
                        var_a3 = 1;
                        {
                voiceGroupInit(D_8010A950, var_a1_2, var_a2, var_a3);return 2;}
                    case 3:                         /* switch 2 */
                        func_800277E4(0xFF);
                        var_a1_2 = D_800BA5D0;
                        var_a2 = 0xC;
                        var_a3 = 1;
                        {
                voiceGroupInit(D_8010A950, var_a1_2, var_a2, var_a3);return 2;}
                    case 4:                         /* switch 2 */
                        func_800277E4(0xFF);
                        var_a1_2 = D_800BAB98;
                        var_a2 = 0xC;
                        var_a3 = 1;
                        {
                voiceGroupInit(D_8010A950, var_a1_2, var_a2, var_a3);return 2;}
                    case 34:                        /* switch 2 */
                        var_a1_2 = D_800BAFF8;
                        var_a2 = 0xC;
                        var_a3 = 1;
                        {
                voiceGroupInit(D_8010A950, var_a1_2, var_a2, var_a3);return 2;}
                    case 15:                        /* switch 2 */
                        var_a1_2 = D_800B93B0;
                        var_a2 = 0xE;
                        goto block_95;
                    case 16:                        /* switch 2 */
                        var_a2_2 = 0xE;
                        if ((((u16) D_800BD68C < 0xAU) | (D_800BD68C == 0x13)) != 0) {
                            D_800BD560 = 0xF;
                            var_a1_3 = D_800B93B0;
                        
                        voiceGroupInit(D_8010A950, var_a1_3, var_a2_2, 0);} else {
                            var_a1_3 = D_800B91D0;
                            var_a2_2 = 0xC;
                        
                        voiceGroupInit(D_8010A950, var_a1_3, var_a2_2, 0);}
                        D_800BD55E = 3U;
                        return 2;
                    case 48:                        /* switch 2 */
                        var_a1_2 = D_800B9FB8;
                        var_a2 = 0xE;
                        goto block_95;
                    case 18:                        /* switch 2 */
                        var_a1_2 = D_800BA3F0;
                        var_a2 = 0xC;
                        goto block_95;
                    case 33:                        /* switch 2 */
                        var_a1_2 = D_800BB1D8;
                        var_a2 = 0x10;
                        goto block_95;
                    case 37:                        /* switch 2 */
                        var_a1_2 = D_800BB908;
                        var_a2 = 0x10;
                        goto block_95;
                    case 32:                        /* switch 2 */
                        D_800BD55E = 3U;
                        var_a1_2 = D_800BAD78;
                        var_a2 = 0x10;
                        goto block_95;
                    }
                } else {
                    switch (arg1) {                 /* switch 3; irregular */
                    case 0x63:                      /* switch 3 */
                        var_a1_2 = D_800BB6D8;
                        var_a2 = 0xE;
block_95:
                        var_a3 = 0;
                        goto block_96;
                    case 0x62:                      /* switch 3 */
                        D_800BD55E = 3U;
                        var_a1_2 = D_800BB458;
                        var_a2 = 0x10;
                        goto block_95;
                    case 0x41:                      /* switch 3 */
                        var_a1_2 = D_800B9DB0;
                        var_a2 = 0xA;
                        var_a3 = 1;
                        goto block_96;
                    case 0x94:                      /* switch 3 */
                        D_800BD55C = 0U;
                        var_a0 = 0x19;
                        if ((((u16) D_800BD68C < 0xAU) | (D_800BD68C == 0x13)) != 0) {
                            var_a1_4 = gMenuSoundParams;
                            var_a2_3 = 0x13;
                        } else {
                            var_a1_4 = gMenuSoundParams;
                            var_a0 = 0x1B;
                            var_a2_3 = 0xA;
                        }
                        goto block_183;
                    case 0x60:                      /* switch 3 */
                        func_80030644((*(s32 *)((char *)(gMenuState) + 0x20)), 0x80);
                        var_a1_2 = D_800B9F40;
                        var_a2 = 3;
                        goto block_95;
                    case 0x108:                     /* switch 3 */
                        D_800BD690 = 1;
                        var_a1_2 = D_800BBB88;
                        var_a2 = 0x14;
                        var_a3 = 1;
                        goto block_96;
                    case 0x109:                     /* switch 3 */
                        D_800BD690 = 1;
                        var_a1_2 = D_800BBEA8;
                        var_a2 = 0x14;
                        var_a3 = 1;
                        goto block_96;
                    case 0x10A:                     /* switch 3 */
                        D_800BD690 = 1;
                        func_800277E4(0xFF);
                        var_a1_2 = "@!\0\0\x80\x01\x8e8\0\0\0\0\f\xa1\0\0\0\0\0\0\0\0\0\x01\0\xc7\0<\x01\0\0\0\0\0\0\0\0\0\0\0\x01\x17\0\0\x80\x01\x8e8\0\0\0\0\f\xa0\0\0\0\0\0\0\0\0\0A\0\x97\0J\0\0\0\0\0\0\0\0\t\x02?\n\x01\x18\0\0\x80\x01\x8e8\0\0\0\0\f\xa0\0\0\0\0\0\0\0\0\0B\0\xa3\0J\0\0\0\0\0\0\0\0\x01\x03?\v\x01\x19\0\0\x80\x01\x8e8\0\0\0\0\f\xa0\0\0\0\0\0\0\0\0\0C\0\xaf\0J\0\0\0\0\0\0\0\0\x02\x04?\f\x01\x1a\0\0\x80\x01\x8e8\0\0\0\0\f\xa0\0\0\0\0\0\0\0\0\0D\0\xbb\0J\0\0\0\0\0\0\0\0\x03\x05@\r\x01\x1b\0\0\x80\x01\x8e8\0\0\0\0\f\xa0\0\0\0\0\0\0\0\0\0E\0\xc7\0J\0\0\0\0\0\0\0\0\x04\x06@\x0e\x01\x1c\0\0\x80\x01\x8e8\0\0\0\0\f\xa0\0\0\0\0\0\0\0\0\0F\0\xd3\0J\0\0\0\0\0\0\0\0\x05\x07@\x0f\x01\x1d\0\0\x80\x01\x8e8\0\0\0\0\f\xa0\0\0\0\0\0\0\0\0\0G\0\xdf\0J\0\0\0\0\0\0\0\0\x06\bA\x10\x01\x1e\0\0\x80\x01\x8e8\0\0\0\0\f\xa0\0\0\0\0\0\0\0\0\0H\0\xeb\0J\0\0\0\0\0\0\0\0\x07\tA\x11\x01\x1f\0\0\x80\x01\x8e8\0\0\0\0\f\xa0\0\0\0\0\0\0\0\0\0I\0\xf7\0J\0\0\0\0\0\0\0\0\b\x01A\x12\x01 \0\0\x80\x01\x8e8\0\0\0\0\f\xa0\0\0\0\0\0\0\0\0\0J\0\x97\0X\0\0\0\0\0\0\0\0\x12\v\x01\x13\x01!\0\0\x80\x01\x8e8\0\0\0\0\f\xa0\0\0\0\0\0\0\0\0\0K\0\xa3\0X\0\0\0\0\0\0\0\0\n\f\x02\x14\x01\"\0\0\x80\x01\x8e8\0\0\0\0\f\xa0\0\0\0\0\0\0\0\0\0L\0\xaf\0X\0\0\0\0\0\0\0\0\v\r\x03\x15\x01#\0\0\x80\x01\x8e8\0\0\0\0\f\xa0\0\0\0\0\0\0\0\0\0M\0\xbb\0X\0\0\0\0\0\0\0\0\f\x0e\x04\x16\x01$\0\0\x80\x01\x8e8\0\0\0\0\f\xa0\0\0\0\0\0\0\0\0\0N\0\xc7\0X\0\0\0\0\0\0\0\0\r\x0f\x05\x17\x01%\0\0\x80\x01\x8e8\0\0\0\0\f\xa0\0\0\0\0\0\0\0\0\0O\0\xd3\0X\0\0\0\0\0\0\0\0\x0e\x10\x06\x18\x01&\0\0\x80\x01\x8e8\0\0\0\0\f\xa0\0\0\0\0\0\0\0\0\0P\0\xdf\0X\0\0\0\0\0\0\0\0\x0f\x11\x07\x19\x01'\0\0\x80\x01\x8e8\0\0\0\0\f\xa0\0\0\0\0\0\0\0\0\0Q\0\xeb\0X\0\0\0\0\0\0\0\0\x10\x12\b\x1a\x01(\0\0\x80\x01\x8e8\0\0\0\0\f\xa0\0\0\0\0\0\0\0\0\0R\0\xf7\0X\0\0\0\0\0\0\0\0\x11\n\t\x1b\x01)\0\0\x80\x01\x8e8\0\0\0\0\f\xa0\0\0\0\0\0\0\0\0\0S\0\x97\0f\0\0\0\0\0\0\0\0\x1b\x14\n\x1c\x01*\0\0\x80\x01\x8e8\0\0\0\0\f\xa0\0\0\0\0\0\0\0\0\0T\0\xa3\0f\0\0\0\0\0\0\0\0\x13\x15\v\x1d\x01+\0\0\x80\x01\x8e8\0\0\0\0\f\xa0\0\0\0\0\0\0\0\0\0U\0\xaf\0f\0\0\0\0\0\0\0\0\x14\x16\f\x1e\x01,\0\0\x80\x01\x8e8\0\0\0\0\f\xa0\0\0\0\0\0\0\0\0\0V\0\xbb\0f\0\0\0\0\0\0\0\0\x15\x17\r\x1f\x01-\0\0\x80\x01\x8e8\0\0\0\0\f\xa0\0\0\0\0\0\0\0\0\0W\0\xc7\0f\0\0\0\0\0\0\0\0\x16\x18\x0e \x01.\0\0\x80\x01\x8e8\0\0\0\0\f\xa0\0\0\0\0\0\0\0\0\0X\0\xd3\0f\0\0\0\0\0\0\0\0\x17\x19\x0f!\x01/\0\0\x80\x01\x8e8\0\0\0\0\f\xa0\0\0\0\0\0\0\0\0\0Y\0\xdf\0f\0\0\0\0\0\0\0\0\x18\x1a\x10\"\x010\0\0\x80\x01\x8e8\0\0\0\0\f\xa0\0\0\0\0\0\0\0\0\0Z\0\xeb\0f\0\0\0\0\0\0\0\0\x19\x1b\x11#\x011\0\0\x80\x01\x8e8\0\0\0\0\f\xa0\0\0\0\0\0\0\0\0\0a\0\xf7\0f\0\0\0\0\0\0\0\0\x1a\x13\x12$\x012\0\0\x80\x01\x8e8\0\0\0\0\f\xa0\0\0\0\0\0\0\0\0\0b\0\x97\0t\0\0\0\0\0\0\0\0$\x1d\x13%\x013\0\0\x80\x01\x8e8\0\0\0\0\f\xa0\0\0\0\0\0\0\0\0\0c\0\xa3\0t\0\0\0\0\0\0\0\0\x1c\x1e\x14&\x014\0\0\x80\x01\x8e8\0\0\0\0\f\xa0\0\0\0\0\0\0\0\0\0d\0\xaf\0t\0\0\0\0\0\0\0\0\x1d\x1f\x15'\x015\0\0\x80\x01\x8e8\0\0\0\0\f\xa0\0\0\0\0\0\0\0\0\0e\0\xbb\0t\0\0\0\0\0\0\0\0\x1e \x16(\x016\0\0\x80\x01\x8e8\0\0\0\0\f\xa0\0\0\0\0\0\0\0\0\0f\0\xc7\0t\0\0\0\0\0\0\0\0\x1f!\x17)\x017\0\0\x80\x01\x8e8\0\0\0\0\f\xa0\0\0\0\0\0\0\0\0\0g\0\xd3\0t\0\0\0\0\0\0\0\0 \"\x18*\x018\0\0\x80\x01\x8e8\0\0\0\0\f\xa0\0\0\0\0\0\0\0\0\0h\0\xdf\0t\0\0\0\0\0\0\0\0!#\x19+\x019\0\0\x80\x01\x8e8\0\0\0\0\f\xa0\0\0\0\0\0\0\0\0\0i\0\xeb\0t\0\0\0\0\0\0\0\0\"$\x1a,\x01:\0\0\x80\x01\x8e8\0\0\0\0\f\xa0\0\0\0\0\0\0\0\0\0j\0\xf7\0t\0\0\0\0\0\0\0\0#\x1c\x1b-\x01;\0\0\x80\x01\x8e8\0\0\0\0\f\xa0\0\0\0\0\0\0\0\0\0k\0\x97\0\x82\0\0\0\0\0\0\0\0-&\x1c.\x01<\0\0\x80\x01\x8e8\0\0\0\0\f\xa0\0\0\0\0\0\0\0\0\0l\0\xa3\0\x82\0\0\0\0\0\0\0\0%'\x1d/\x01=\0\0\x80\x01\x8e8\0\0\0\0\f\xa0\0\0\0\0\0\0\0\0\0m\0\xaf\0\x82\0\0\0\0\0\0\0\0&(\x1e0\x01>\0\0\x80\x01\x8e8\0\0\0\0\f\xa0\0\0\0\0\0\0\0\0\0n\0\xbb\0\x82\0\0\0\0\0\0\0\0')\x1f1\x01?\0\0\x80\x01\x8e8\0\0\0\0\f\xa0\0\0\0\0\0\0\0\0\0o\0\xc7\0\x82\0\0\0\0\0\0\0\0(* 2\x01@\0\0\x80\x01\x8e8\0\0\0\0\f\xa0\0\0\0\0\0\0\0\0\0p\0\xd3\0\x82\0\0\0\0\0\0\0\0)+!3\x01A\0\0\x80\x01\x8e8\0\0\0\0\f\xa0\0\0\0\0\0\0\0\0\0q\0\xdf\0\x82\0\0\0\0\0\0\0\0*,\"4\x01B\0\0\x80\x01\x8e8\0\0\0\0\f\xa0\0\0\0\0\0\0\0\0\0r\0\xeb\0\x82\0\0\0\0\0\0\0\0+-#5\x01C\0\0\x80\x01\x8e8\0\0\0\0\f\xa0\0\0\0\0\0\0\0\0\0s\0\xf7\0\x82\0\0\0\0\0\0\0\0,%$6\x01D\0\0\x80\x01\x8e8\0\0\0\0\f\xa0\0\0\0\0\0\0\0\0\0t\0\x97\0\x90\0\0\0\0\0\0\0\06/%7\x01E\0\0\x80\x01\x8e8\0\0\0\0\f\xa0\0\0\0\0\0\0\0\0\0u\0\xa3\0\x90\0\0\0\0\0\0\0\0.0&8\x01F\0\0\x80\x01\x8e8\0\0\0\0\f\xa0\0\0\0\0\0\0\0\0\0v\0\xaf\0\x90\0\0\0\0\0\0\0\0/1'9\x01G\0\0\x80\x01\x8e8\0\0\0\0\f\xa0\0\0\0\0\0\0\0\0\0w\0\xbb\0\x90\0\0\0\0\0\0\0\002(:\x01H\0\0\x80\x01\x8e8\0\0\0\0\f\xa0\0\0\0\0\0\0\0\0\0x\0\xc7\0\x90\0\0\0\0\0\0\0\013);\x01I\0\0\x80\x01\x8e8\0\0\0\0\f\xa0\0\0\0\0\0\0\0\0\0y\0\xd3\0\x90\0\0\0\0\0\0\0\024*<\x01J\0\0\x80\x01\x8e8\0\0\0\0\f\xa0\0\0\0\0\0\0\0\0\0z\0\xdf\0\x90\0\0\0\0\0\0\0\035+=\x01K\0\0\x80\x01\x8e8\0\0\0\0\f\xa0\0\0\0\0\0\0\0\0\00\0\xeb\0\x90\0\0\0\0\0\0\0\046,>\x01L\0\0\x80\x01\x8e8\0\0\0\0\f\xa0\0\0\0\0\0\0\0\0\01\0\xf7\0\x90\0\0\0\0\0\0\0\05.->\x01M\0\0\x80\x01\x8e8\0\0\0\0\f\xa0\0\0\0\0\0\0\0\0\02\0\x97\0\x9e\0\0\0\0\0\0\0\0>8.?\x01N\0\0\x80\x01\x8e8\0\0\0\0\f\xa0\0\0\0\0\0\0\0\0\03\0\xa3\0\x9e\0\0\0\0\0\0\0\079/?\x01O\0\0\x80\x01\x8e8\0\0\0\0\f\xa0\0\0\0\0\0\0\0\0\04\0\xaf\0\x9e\0\0\0\0\0\0\0\08:0@\x01P\0\0\x80\x01\x8e8\0\0\0\0\f\xa0\0\0\0\0\0\0\0\0\05\0\xbb\0\x9e\0\0\0\0\0\0\0\09;1@\x01Q\0\0\x80\x01\x8e8\0\0\0\0\f\xa0\0\0\0\0\0\0\0\0\06\0\xc7\0\x9e\0\0\0\0\0\0\0\0:<2@\x01R\0\0\x80\x01\x8e8\0\0\0\0\f\xa0\0\0\0\0\0\0\0\0\07\0\xd3\0\x9e\0\0\0\0\0\0\0\0;=3A\x01S\0\0\x80\x01\x8e8\0\0\0\0\f\xa0\0\0\0\0\0\0\0\0\08\0\xdf\0\x9e\0\0\0\0\0\0\0\0<>4A\x01T\0\0\x80\x01\x8e8\0\0\0\0\f\xa0\0\0\0\0\0\0\0\0\09\0\xeb\0\x9e\0\0\0\0\0\0\0\0=75A\x01W\0\0\x80\x01\x8e8\0\0\0\0\f\xa0\0\0\0\0\0\0\0\0\0 \0\xa3\0\xac\0\0\0\0\0\0\0\0A@7\x01\x01U\0\0\x80\x01\x8e8\0\0\0\0\f\xa0\0\0\0\0\0\0\0\0\x03\xe8\0\xbb\0\xac\0\0\0\0\0\0\0\0?A9\x04\x01V\0\0\x80\x01\x8e8\0\0\0\0\f\xa0\0\0\0\0\0\0\0\0\x07\xd0\0\xd3\0\xac\0\0\0\0\0\0\0\0@?<\x07\0\x03\0\0\0\0\0\0\0\0\0\0@\0\0\0\0\0\0\0\0\0\0\0\0\x88\06\x80\0\0\0\0,\0$\xff\xff\xff\xff\0\x03\0\0\0\0\0\0\0\0\0\0@\0\0\0\0\0\0\0\0\0\0\0\0\x88\0\xac\xc0\0\0\0\0,\0$\xff\xff\xff\xff\0\x03\0\0\0\0\0\0\0\0\0\0@\0\0\0\0\0\0\0\0\0\0\0\0\xf8\06\xa0\0\0\0\0,\0$\xff\xff\xff\xff\0\x03\0\0\0\0\0\0\0\0\0\0@\0\0\0\0\0\0\0\0\0\0\0\0\xf8\0\xac\xe0\0\0\0\0,\0$\xff\xff\xff\xff\0\x03\0\0\0\0\0\0\0\0\0\0\x80\0\0\0\0\0\0\0\0h\0\x02\0\x94\06\x80\0\0\0\0\x03\0*\xff\xff\xff\xff\0\x03\0\0\0\0\0\0\0\0\0\0\x80\0\0\0\0\0\0\0\0h\0\x02\0\x94\0\xba\x80\0\0\0\0\x03\0*\xff\xff\xff\xff\0\x03\0\0\0\0\0\0\0\0\0\0\x80\0\0\0\0\0\0\0\0\x02\0n\0\x88\0B\x80\0\0\0\0\x03\0*\xff\xff\xff\xff\0\x03\0\0\0\0\0\0\0\0\0\0\x80\0\0\0\0\0\0\0\0\x02\0n\x01\x06\0B\x80\0\0\0\0\x03\0*\xff\xff\xff\xff\0\x03\0\0\0\0\0\0\0\0\0\0\xa0\t\0\0\0\0\0\0\0~\0\x82\0\x89\08\x80\0\0\0\0\x0e\0*\xff\xff\xff\xff" /* not null-terminated */;
                        var_a2 = 0x4B;
                        var_a3 = 1;
                        goto block_96;
                    case 0x10B:                     /* switch 3 */
                        D_800BD690 = 1;
                        var_a1_2 = D_800BCD80;
                        var_a2 = 0xC;
                        var_a3 = 1;
                        goto block_96;
                    case 0x10C:                     /* switch 3 */
                        D_800BD690 = 1;
                        var_a2 = 0xC;
                        if (gSaveKeyRelaxed == 1) {
                            var_a1_2 = D_800BCF60;
                        } else {
                            var_a1_2 = D_800BD140;
                        }
                        var_a3 = 1;
                        goto block_96;
                    case 0x10D:                     /* switch 3 */
                        func_800277E4(0xFF);
                        var_a1_2 = D_800B99F0;
                        var_a2 = 0xE;
                        goto block_95;
                    case 0x10E:                     /* switch 3 */
                        func_800277E4(0xFF);
                        var_a1_2 = D_800B97C0;
                        var_a2 = 0xE;
                        goto block_95;
                    case 0x111:                     /* switch 3 */
                        D_800BD690 = 1;
                        var_a1_2 = D_800BD320;
                        var_a2 = 0xE;
                        goto block_95;
                    }
                }
            } else {
                var_a1_2 = D_800B9C20;
                var_a2 = 0xA;
                var_a3 = 1;
block_96:
                voiceGroupInit(D_8010A950, var_a1_2, var_a2, var_a3);
                return 2;
            }
        } else {
            switch (D_800BD55C) { /* switch 1; irregular */
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
            case 0xFF:                              /* switch 1 */
                temp_s0 = (u16) D_800BD560;
                func_800277E4(-(((u16) D_800BD68C >= 0xAU) & (D_800BD68C != (unsigned short)0x13)) & 0xFF);
                D_800BD55C = 0U;
                if (temp_s0 != 0x25) {
                    if ((s32) temp_s0 < 0x26) {
                        if (temp_s0 != 0x12) {
                            if ((s32) temp_s0 < 0x13) {
                                switch (temp_s0) {  /* switch 4; irregular */
                                case 15:            /* switch 4 */
                                    if (D_80100910 != 2) {
                                        temp_s0_2 = (*(void **)((char *)(gMenuState) + 0));
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
                                case 16:            /* switch 4 */
                                    var_v0 = 0xFF;
                                    if (D_800BFC34 != 0) {
                                        temp_v1 = (*(u16 *)((char *)(gMenuState) + 0x14));
                                        func_8002778C();
                                        gSaveStatus = 0;
                                        if (temp_v1 != 0x19) {
                                            var_a0 = 1;
                                            if (temp_v1 != 0x1A) {
                                                var_a1_4 = gMenuSoundParams;
                                                var_a2_3 = 0xA;
                                            } else {
                                                var_a1_4 = gMenuSoundParams;
                                                var_a0 = 0x10;
                                                var_a2_3 = 0xA;
                                            }
                                        } else {
                                            var_a0 = 0;
                                            var_a1_4 = 0;
                                            var_a2_3 = 0x12;
                                        }
                                        goto block_183;
                                    }
                                    /* Duplicate return node #185. Try simplifying control flow for better match */
                                    return var_v0;
                                default:            /* switch 4 */
                                    return 0xFF;
                                }
                            } else {
                                var_v0 = 0xFF;
                                if (temp_s0 >= 0x20) {
                                    if ((s32) temp_s0 >= 0x22) {
                                        if (temp_s0 != 0x22) {
                                            return 0xFF;
                                        }
                                        goto block_134;
                                    }
                                    goto block_154;
                                }
                                /* Duplicate return node #185. Try simplifying control flow for better match */
                                return var_v0;
                            }
                        } else {
block_134:
                            var_s0 = func_8002CBF4();
                            if (D_80109DD0 != 0) {
                                temp_v0 = var_s0 & 0xFFFF;
                                if ((((s32)temp_v0 == 0) | (temp_v0 == 0x30)) != 0) {
                                    var_s0 = 0x94;
                                }
                            }
                            refreshSlotMenuLabels();
                            func_800277E4(-(((u16) D_800BD68C >= 0xAU) & (D_800BD68C != 0x13)) & (s32)0xFF);
                            var_a1_5 = var_s0 << 0x10;
                            {var_a1 = (s16) (var_a1_5 >> 0x10);
                        return func_8002502C(arg0, (s32) var_a1) & 0xFFFF;}
                        }
                    } else if ((s32) temp_s0 < 0x64) {
                        switch (temp_s0) {    /* switch 5; irregular */
                        case 0x30:                  /* switch 5 */
                            if (D_80100910 == 1) {
                                func_8002778C();
                                func_8002CC14();
                                if (((func_8002D218() << 0x10) == 0) || (var_v0 = 0x80, (func_8002D218() == temp_s0))) {
                                    var_a0 = 0x19;
                                    if ((((u16) D_800BD68C < 0xAU) | (D_800BD68C == 0x13)) != 0) {
                                        var_a1_4 = gMenuSoundParams;
                                        var_a2_3 = 0x13;
                                    } else {
                                        var_a1_4 = gMenuSoundParams;
                                        var_a0 = 0x1B;
                                        var_a2_3 = 0xA;
                                    }
                                    goto block_183;
                                }
                                /* Duplicate return node #185. Try simplifying control flow for better match */
                                return var_v0;
                            }
                            var_v0 = 0xFF;
                            if (D_800BFC34 != 0) {
                                func_8002778C();
                                temp_v1_2 = (*(u16 *)((char *)(gMenuState) + 0x14));
                                gSaveStatus = 0;
                                if (temp_v1_2 != 0x19) {
                                    var_a0 = 1;
                                    if (temp_v1_2 != 0x1A) {
                                        var_a1_4 = gMenuSoundParams;
                                        var_a2_3 = 0xA;
                                    } else {
                                        var_a1_4 = gMenuSoundParams;
                                        var_a0 = 0x10;
                                        var_a2_3 = 0xA;
                                    }
                                } else {
                                    var_a0 = 0;
                                    var_a1_4 = 0;
                                    var_a2_3 = 0x12;
                                }
                                goto block_183;
                            }
                            /* Duplicate return node #185. Try simplifying control flow for better match */
                            return var_v0;
                        case 0x60:                  /* switch 5 */
                            func_8002778C();
                            func_8002CBF4();
                            return 0xFF;
                        default:                    /* switch 5 */
                            return 0xFF;
                        }
                    } else {
                        if (temp_s0 != 0x109) {
                            if ((s32) temp_s0 < 0x10A) {
                                if (temp_s0 != 0x108) {
                                    return 0xFF;
                                }
                                var_v0 = 0xFF;
                                if (D_80100910 == 1) {
                                    func_8002778C();
                                    func_8001F064();
                                    return 0xFF;
                                }
                                /* Duplicate return node #185. Try simplifying control flow for better match */
                                return var_v0;
                            }
                            if (temp_s0 != 0x111) {
                                return 0xFF;
                            }
                            var_v0 = 0xFF;
                            if (D_80100910 == 1) {
                                func_8002778C();
                                var_a1_4 = gMenuSoundParams;
                                var_a0 = 1;
                                var_a2_3 = 0xA;
                                D_80102F04 = 0;
                                goto block_183;
                            }
                            /* Duplicate return node #185. Try simplifying control flow for better match */
                            return var_v0;
                        }
                        var_v0 = 0xFF;
                        if (D_80100910 == 1) {
                            func_8002778C();
                            func_8001F08C();
                            return 0xFF;
                        }
                        /* Duplicate return node #185. Try simplifying control flow for better match */
                        return var_v0;
                    }
                } else {
block_154:
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
                            temp_v1_3 = (*(u16 *)((char *)(gMenuState) + 0x14));
                            gSaveStatus = 0;
                            if (temp_v1_3 != 0x19) {
                                var_a0 = 1;
                                if (temp_v1_3 != 0x1A) {
                                    var_a1_4 = gMenuSoundParams;
                                    var_a2_3 = 0xA;
                                } else {
                                    var_a1_4 = gMenuSoundParams;
                                    var_a0 = 0x10;
                                    var_a2_3 = 0xA;
                                }
                            } else {
                                var_a0 = 0;
                                var_a1_4 = 0;
                                var_a2_3 = 0x12;
                            }
block_183:
                            func_800278AC(var_a0, var_a1_4, var_a2_3);
                            return 0x80;
                        }
                        return var_v0;
                    }
                }
                break;
            default:                                /* switch 1 */
                return 0xFF;
            }
        }
    } else {
        if (D_800BD55E == 0) {
            var_v0_2 = 0xFF;
        } else {
            D_800BD55E = (u16) (D_800BD55E - 1);
            var_v0_2 = 1;
        }
        D_800BD55C = var_v0_2;
        return 1;
    }
}
